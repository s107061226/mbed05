#include "mbed.h"

Timeout tout;               // set a timeout object
DigitalIn button(SW2);      // set SW2 button be digital input
DigitalOut redLED(LED1);    // set LED be digital output

/* redLED blink once */
void blink()
{
    redLED = 0;
    wait(0.5);
    redLED = 1;
}

int main()
{
    redLED = 1;
    while (1) {
        // the button be pressed
        if (button == 0) {
            tout.attach(&blink, 2.0);
        }
        wait(0.2);
    }
}
