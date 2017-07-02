
/* Don't forget to call wiringPiSetup() in main function
 * Compile with -lwiringPi -wiringPiDev flags
 */


#ifndef temp_humidity_DHT11
#define temp_humidity_DHT11

#include <wiringPi.h>

#define MAXTIMINGS  85
#define DHTPIN  7



void read_dht11_data(int dht11_data[]);
    


#endif

