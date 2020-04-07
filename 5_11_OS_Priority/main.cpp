#include "mbed.h"
#include "mbed_events.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
InterruptIn btn(SW2);
EventQueue printfQueue;     // lower priority
EventQueue eventQueue;      // normal priority
Thread printfThread(osPriorityLow);
Thread eventThread(osPriorityNormal);
Ticker ledTicker;

void blink_led2() 
{
    led2 = !led2;
}


void print_toggle_led() 
{
    printf("Toggle LED!\r\n");
}

void btn_fall_irq() 
{
    led1 = !led1;
    // defer the printf call to the low priority thread
    printfQueue.call(&print_toggle_led);
}

int main() 
{
    printfThread.start(callback(&printfQueue, &EventQueue::dispatch_forever));
    eventThread.start(callback(&eventQueue, &EventQueue::dispatch_forever));
    ledTicker.attach(eventQueue.event(&blink_led2), 1.0f);
    // button fall still runs in the ISR
    btn.fall(&btn_fall_irq);
    while (1) {
        wait(1);
    }
}
