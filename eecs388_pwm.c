#include <stdio.h>
#include <stdint.h>
#include "eecs388_lib.h"

#define SERVO_PULSE_MAX 2400 /* 2400 us */
#define SERVO_PULSE_MIN 544 /* 544 us */
#define SERVO_PERIOD 20000 /* 20000 us (20ms) */

void servo(int gpio, int pos)
{
// Ensure angle is within valid range
if (pos < 0) pos = 0;
if (pos > 180) pos = 180;

// Map the position to the corresponding pulse width
int pulse_width = SERVO_PULSE_MIN + ((pos * (SERVO_PULSE_MAX - SERVO_PULSE_MIN)) / 180);

// Generate PWM signal
gpio_write(gpio, ON);
delay_usec(pulse_width);
gpio_write(gpio, OFF);
delay_usec(SERVO_PERIOD - pulse_width);
}

int main()
{
int gpio = PIN_19;
gpio_mode(gpio, OUTPUT);

while (1) {
// Move from 0 to 180 in increments of 30
for (int pos = 0; pos <= 180; pos += 30) {
printf("pos: %d (degree)\n", pos);
for (int i = 0; i < 50; i++) // Maintain position for a short duration
servo(gpio, pos);
}
// Quickly return to 0 in one motion
printf("Returning to 0 degrees\n");
for (int i = 0; i < 50; i++) // Adjust the iteration count to control speed
servo(gpio, 0);
}
}
