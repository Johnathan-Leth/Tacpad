#include <stdio.h>
#include "pico/stdlib.h"
#include "bsp/board.h"
#include "tusb.h"

// GPIO matrix
const uint8_t gpio_pins[3][3] = {
    {28, 2, 5}, // Top row
    {27, 11, 7}, // Middle row
    {19, 17, 14} // Bottom row
};

// Keyboard matrix
const uint8_t keycodes[3][3] = {
    {HID_USAGE_KEY_1, HID_KEY_2, HID_KEY_3},
    {HID_KEY_4, HID_KEY_5, HID_KEY_6},
    {HID_KEY_7, HID_KEY_8, HID_KEY_9}
};


int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
