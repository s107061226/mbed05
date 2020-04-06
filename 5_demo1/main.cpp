#include "mbed.h"

DigitalOut blueLED(LED3);   // blue LED output
Ticker time_up;             // set a ticker to count

void Blink()
{
    blueLED = !blueLED;       // switch the led
}

int main()
{
    blueLED = 1;                     // initial the LED
    time_up.attach(&Blink, 0.5);    // blink LED
}