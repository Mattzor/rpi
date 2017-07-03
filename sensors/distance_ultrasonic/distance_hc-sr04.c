#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <wiringPi.h>
#include <time.h>

#define trigg_pin 1
#define echo_pin  5


struct timespec tstart={0,0}, tend={0,0};

double distance()
{
    digitalWrite(trigg_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigg_pin, LOW);
    clock_gettime(CLOCK_MONOTONIC, &tstart);

    while(digitalRead(echo_pin) == LOW){
        clock_gettime(CLOCK_MONOTONIC, &tstart);
    }
    while(digitalRead(echo_pin) == HIGH){
        clock_gettime(CLOCK_MONOTONIC, &tend);
    }

    double timeElapsed = (double) (tend.tv_nsec - tstart.tv_nsec) / 1000000000;

    return (double) (timeElapsed * 34300 ) / 2;
    
}


int main ()
{
    wiringPiSetup();
    pinMode(trigg_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
    printf("before while\n");
    while(1){
       printf("Distance: %f\n",distance());
       delay(1000); 
    }
}
