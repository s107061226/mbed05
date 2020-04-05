#include "mbed.h"

Timer debounce;             // set a timer called debounce
InterruptIn button(SW2);    // set SW2 be interrupt signal
DigitalOut redLED(LED1);    // redLED digital output

void toggle()
{
    if (debounce.read_ms() > 1000) {
        redLED = !redLED;
        debounce.reset();
    }
}

int main()
{
    debounce.start();
    button.rise(&toggle);
    while(1);
}