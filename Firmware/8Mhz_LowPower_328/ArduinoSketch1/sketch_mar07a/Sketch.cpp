/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include <Arduino.h>
#include <LowPower.h>
#include <SoftwareSerial.h>
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

#define F_CPU 8000000

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
  delay(1000);
}

void loop()
{
	Serial.println("Going to sleep now");
	delay(25);
	LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); 
}
