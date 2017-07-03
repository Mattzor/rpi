#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <wiringPi.h>

#define laserPin 7

int main()
{
    wiringPiSetup();
    pinMode(laserPin, OUTPUT);

    uint8_t value = 0;

    while(1){
        digitalWrite(laserPin, (value = !value));
        delay(100);
    }
    

}
