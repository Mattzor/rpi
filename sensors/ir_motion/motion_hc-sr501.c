#include "motion_hc-sr501.h"
#include <stdint.h>
#define SR_PIN 7

int main()
{
    printf("start\n");
    uint8_t state = 1;

    wiringPiSetup();
    pinMode(SR_PIN, INPUT);
    
    while(1){
        state = digitalRead(SR_PIN);
        if(state == HIGH){
            printf("Motion!!\n");
        }else{
            printf("Everything ok\n");
        }
        delay(500);
    }
}
