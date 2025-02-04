#include <stdint.h>
#include "eecs388_lib.h"

int main()
{
    // Define LED pins
    int leds[] = {RED_LED, GREEN_LED, BLUE_LED};
    int num_leds = 3;

    // Set LEDs as output
    for (int i = 0; i < num_leds; i++) {
        gpio_mode(leds[i], OUTPUT);
    }

    while (1)
    {
        for (int i = 0; i < num_leds; i++) {
            gpio_write(leds[i], ON);  // Turn LED on
            delay(500);               // Wait 500ms
            gpio_write(leds[i], OFF); // Turn LED off
            delay(300);               // Wait 300ms
        }
    }

    return 0;
}
