#include "pico/stdlib.h"
#include "tusb.h"
#include "btstack.h"



int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
