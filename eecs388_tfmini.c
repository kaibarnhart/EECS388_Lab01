/**
 * This program reads the distance data from the TFmini LiDAR sensor,
 * prints the read data and controls an LED depending on the measured distance.
 */
#include <stdint.h>
#include <stdio.h>
#include "eecs388_lib.h"

int main()
{
    // Set up GPIO pins for LED output
    gpio_mode(RED_LED, OUTPUT);
    gpio_mode(GREEN_LED, OUTPUT);
    
    // Initialize serial communication
    ser_setup();
    ser_printline("Setup completed.");

    uint8_t buf[9];
    uint16_t dist = 0;

    while (1) {
        /* 
            Task 2.1: 
            - read a data frame from the TFmini sensor
            - from Table 6, we know each LIDAR measurement sends 9 bytes
            - the function `ser_read()` can process 1 byte per function call
            - This if-statement below will read (and check) the first two bytes of a valid data frame
            - You will need to write code to read the subsequent bytes to get the distance data
            - You will need to process the data received from the sensor to get the correct distance value
        */
        if (ser_read() == 0x59 && ser_read() == 0x59) {
            buf[0] = 0x59;
            buf[1] = 0x59;
            for (int i = 2; i < 9; i++) {
                buf[i] = ser_read();
            }

            // Extract 16-bit distance value from bytes 3 and 4
            dist = (buf[3] << 8) | buf[2];
            printf("Distance: %d cm\n", dist);

            /* 
                Task 2.2: Control LED based on distance 
                - Turn on the red LED if the distance measured is less than 50 cm. 
                - Otherwise, turn on the green LED 
            */
            if (dist < 50) {
                gpio_write(RED_LED, ON);
                gpio_write(GREEN_LED, OFF);
            } else {
                gpio_write(RED_LED, OFF);
                gpio_write(GREEN_LED, ON);
            }
        }
    }
}
