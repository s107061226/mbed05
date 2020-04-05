#include "mbed.h"

InterruptIn button(SW2);    // set SW2 is an external interrupt
DigitalOut led(LED1);       // set LED1 is the output

/*************************************** 
 * interrupt service routine of SW2    *
 * change the state of LED1            *
 ***************************************/
void ISR1()
{
    led = !led;
}

int main()
{
    button.fall(&ISR1);     // set negative edge trigger of SW2
    while (1);
}
