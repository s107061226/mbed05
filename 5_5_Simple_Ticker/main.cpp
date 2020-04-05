#include "mbed.h"

Ticker time_up;             // set a ticker object
DigitalOut redLED(LED1);    // set redLED digital output

/* change the state of the led */
void blink()
{
    redLED = !redLED;
}

int main()
{
    redLED = 1;
    time_up.attach(&blink, 0.2);
    while(1);
}
