#include <Arduino.h>
#include "EEPROM.h"
#include "LowPower.h"
#include "epd.h"

#define imageMaximum 17
#define imageCounterAddress 1
#define eink_EN 4
#define eink_DIN 2
#define eink_DOUT 3

unsigned long dayCounter = 0;
unsigned long holdTimer = 0;

void displayImage();
void restartCounter();

void setup()
{
	//restartCounter();
	pinMode(eink_DIN, INPUT_PULLUP);
	if(!digitalRead(eink_DIN))
	{
		holdTimer = millis();
		while(!digitalRead(eink_DIN));
		
		if((millis() - holdTimer) > 3000)
		{
			int imageCounter = 0;
			EEPROM.put(imageCounterAddress,imageCounter);
		}
	}
	displayImage();
}

void loop()
{
	if(dayCounter > 300000)
	{
		displayImage();
		dayCounter = 0;
	}

	dayCounter++;
	LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
}

void displayImage()
{
    pinMode(eink_EN, OUTPUT);
    digitalWrite(eink_EN, HIGH);
    delay(5000);

    Serial.begin(115200);
    epd_set_memory(MEM_TF);
	
	int imageCounter = 0;
	String imageName = "o";

	
	EEPROM.get(imageCounterAddress, imageCounter);
	imageCounter++;

	if(imageCounter > imageMaximum)
	{
		imageCounter = 0;
	}

	EEPROM.put(imageCounterAddress,imageCounter);

	imageName += String(imageCounter);
	imageName += ".bmp";
	
	
	epd_clear();
	epd_disp_bitmap(imageName.c_str(), 0, 0);
	epd_udpate();
	delay(15000);
	digitalWrite(eink_EN, LOW);
}

void restartCounter()
{
	for (int i = 0 ; i < EEPROM.length() ; i++) 
	{
		EEPROM.write(i, 0);
	}
	
	int imageCounter = 0;
	EEPROM.put(imageCounterAddress, imageCounter);
	//Serial.println("Comment this function out and restart device");
	while(1);
}