#include "mbed.h"

Timer t;                    // set a timer
Serial pc(USBTX, USBRX);    // set communication between K66F and PC

int main()
{
    t.start();
    pc.printf("Hello from the other side\n");
    wait(1);
    t.stop();
    pc.printf("The time taken was %f seconds\n", t.read());
}
