
#include "dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to
 
dht DHT;

int red_light_pin= 8;
int green_light_pin = 7;
int blue_light_pin = 6;


void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    int temp = DHT.temperature;
    Serial.print((temp)); 
    Serial.println("C  ");
    if(temp>30){
    RGB_color(255, 0, 0);
  }
  else if(temp<=30 && temp>=26){
    RGB_color(0, 255, 0);
  }
  else if (temp<26){
    RGB_color(0, 0, 255); 
  }
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}// end loop()
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
