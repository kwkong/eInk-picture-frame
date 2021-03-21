


#include <Arduino.h>
#include "epd.h"
#include <LowPower.h>
#include <SoftwareSerial.h>

#define F_CPU 8000000
#define eink_EN 4

unsigned long rxTimeout = 0;
//SoftwareSerial loraSerial(2,3);
String message;

void setup()
{
  //pinMode(4, OUTPUT);
  //digitalWrite(4, HIGH);
  //delay(1000);
  //loraSerial.begin(9600);
  Serial.begin(9600);
  Serial.println("init");
 
  pinMode(eink_EN, OUTPUT);
  
  delay(1000);
  digitalWrite(eink_EN, HIGH);
  delay(1000);
  
  
    epd_clear();
    epd_disp_bitmap("PIC4.BMP", 0, 0);
    epd_udpate();
    delay(5000);

    epd_clear();
    epd_disp_bitmap("PIC2.BMP", 0, 100);
    epd_disp_bitmap("PIC3.BMP", 400, 100);
    epd_udpate();
    delay(5000);

    epd_clear();
    epd_disp_bitmap("PIC7.BMP", 0, 0);
    epd_udpate();
  
  
  delay(1000);
  digitalWrite(eink_EN, LOW);

}

void loop()
{
	Serial.println("Going to sleep now");
	delay(500);
	//LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); 
}
