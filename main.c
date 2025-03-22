#include <stdio.h>
#include "pico/stdlib.h"
//#include "bsp/board.h"
#include "tusb.h"

#define LED_PIN 25

// GPIO matrix
const uint8_t gpio_pins[3][3] = {
    {28, 2, 5}, // Top row
    {27, 11, 7}, // Middle row
    {19, 17, 14} // Bottom row
};

// Keyboard matrix
const uint8_t keycodes[3][3] = {
    {HID_KEY_1, HID_KEY_2, HID_KEY_3},
    {HID_KEY_4, HID_KEY_5, HID_KEY_6},
    {HID_KEY_7, HID_KEY_8, HID_KEY_9}
};

// Button monitor
void gpio_caller(uint gpio, uint32_t events) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (gpio_pins[row][col] == gpio) {
                uint8_t key = keycodes[row][col];

                // Sends button press and flashes led for testing
                if (tud_hid_ready()) {
                    uint8_t report[6] = {key, 0, 0, 0, 0, 0};
                    tud_hid_keyboard_report(0, 0, report);
                    gpio_put(LED_PIN, 1);

                    sleep_ms(100);

                    uint8_t empty_report[6] = {0};
                    tud_hid_keyboard_report(0, 0, empty_report);
                    gpio_put(LED_PIN, 1);
                }
            }
        }
    }
}

// Initialize gpio pins to monitor
void init_gpio() {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            uint8_t pin = gpio_pins[row][col];
            gpio_init(pin);
            gpio_set_dir(pin, GPIO_IN);
            gpio_pull_up(pin);
            gpio_set_irq_enabled_with_callback(pin, GPIO_IRQ_EDGE_FALL, true, &gpio_caller);
        }
    }
}

// Initialize and loop the 
int main() {
    stdio_init_all();
    tusb_init();
    init_gpio();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        tud_task();
    }
}
