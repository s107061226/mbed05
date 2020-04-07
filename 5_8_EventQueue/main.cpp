#include "mbed.h"

EventQueue queue;       // set a queue

int main() {

    // events are simple callbacks
    queue.call(printf, "called immediately\r\n");
    queue.call_in(2000, printf, "called in 2 seconds\r\n");
    queue.call_every(1000, printf, "called every 1 seconds\r\n");

    // if do queue.dispatch(); this time will not execute the event below

    queue.call_every(5000, printf, "Hello every 5 sec \r\n");
    // excute the event in queue
    queue.dispatch();
}
