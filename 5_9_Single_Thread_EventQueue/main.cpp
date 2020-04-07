#include "mbed.h"

DigitalOut led1(LED1);                      // red led output
DigitalOut led2(LED2);                      // green led output
InterruptIn sw2(SW2);                       // SW2 interrupt signal
InterruptIn sw3(SW3);                       // SW3 interrupt signal
EventQueue queue(32 * EVENTS_EVENT_SIZE);   // set a queue to store 32 events
Thread t;                                   // set a thread

/* *****************************************
 * print out sw2 triggered                 *
 * interrupt ISR cannot use print          *
 * it need to print out by calling queue   *
 *******************************************/
void led1_info() 
{
    printf("led1 is triggered! \r\n");
}

/* ISR of sw2 */
void Trig_led1()  
{
    // Execute the time critical part first
    led1 = !led1;
    // interrupt cannot use printf, call queue to print
    queue.call(led1_info);
}

/*********************************************
 * ISR of sw3                                *
 * it is in the queue, so it can use printf  *
 *********************************************/
void Trig_led2()  
{
    led2 = !led2;
    printf("led2 is triggered! \r\n");
}

int main() 
{
    // t is a thread to process tasks in an EventQueue
    // t call queue.dispatch_forever() to start the scheduler of the EventQueue
    t.start(callback(&queue, &EventQueue::dispatch_forever));
    // 'Trig_led1' will execute in IRQ context
    sw2.rise(Trig_led1);
    // 'Trig_led2' will execute in context of thread 't'
    // 'Trig_led2' is directly put into the queue
    sw3.rise(queue.event(Trig_led2));
}
