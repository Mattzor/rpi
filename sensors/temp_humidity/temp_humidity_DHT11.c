#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <wiringPi.h>
#include "temp_humidity_DHT11.h"


void read_dht11_data(int dht11_data[])
{
    uint8_t lastState = HIGH;
    uint8_t counter = 0;
    uint8_t j = 0, i;
    float f;

    dht11_data[0] = dht11_data[1] = dht11_data[2] = dht11_data[3] = dht11_data[4] = 0;
     
    pinMode(DHTPIN, OUTPUT);
    digitalWrite(DHTPIN, LOW);
    delay(18);
 
    digitalWrite(DHTPIN, HIGH);
    delayMicroseconds(40);
    
    pinMode(DHTPIN, INPUT);

    for( i = 0; i < MAXTIMINGS; i++){
        counter = 0;
        while(digitalRead(DHTPIN) == lastState){
            counter++;
            delayMicroseconds(1);
            if(counter == 255){
                break;
            }
        }
        lastState = digitalRead(DHTPIN);
        if(counter == 255){
            break;
        }
        if((i >= 4) && (i % 2 == 0)){
            dht11_data[j/8] <<= 1;
            if(counter > 16){
                dht11_data[j/8] |= 1;
            }
            j++;
        }
    }
    /* Useless right now */
    if((j >= 40) && (dht11_data[4] == ((dht11_data[0] + dht11_data[1] + dht11_data[2] + dht11_data[3]) & 0xFF))){
        f = dht11_data[2] * 9. / 5. + 32;
    }


}
