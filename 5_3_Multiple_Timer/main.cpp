#include "mbed.h"

Timer timer_fast, timer_slow;       // set 2 timers
DigitalOut redLED(LED1);            // set LED1 output
DigitalOut greenLED(LED2);          // set LED2 output

int main()
{
    // initialize 2 LEDs
    redLED = 1;
    greenLED = 1;
    
    // start the timers
    timer_fast.start();
    timer_slow.start();

    while (1) {
        // change redLED each 0.2 sec
        if(timer_fast.read() > 0.2) {
            redLED = !redLED;
            timer_fast.reset();
        }
        // change greenLED each 2 sec
        if(timer_slow.read() > 2) {
            greenLED = !greenLED;
            timer_slow.reset();
        }
    }
}
