#include <Arduino.h>
#include "EEPROM.h"
#include "LowPower.h"
#include "epd.h"

#define imageMaximum 75
#define imageCounterAddress 1
#define eink_EN 4

int dayCounter = 0;

void displayImage();
void restartCounter();

void setup()
{
	Serial.begin(115200);
	//restartCounter();
	displayImage();
}

void loop()
{
	if(dayCounter > 10800)
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
	delay(3000);
	epd_set_memory(MEM_TF);
	
	int imageCounter = 0;
	String imageName = "i";

	
	EEPROM.get(imageCounterAddress, imageCounter);
	imageCounter++;

	if(imageCounter > 75)
	{
		imageCounter = 0;
	}

	EEPROM.put(imageCounterAddress,imageCounter);

	imageName = String(imageCounter);
	imageName += ".bmp";
	epd_disp_bitmap(imageName.c_str(), 0, 0);
	epd_udpate();
	
	//Serial.println(imageName);
	delay(4000);
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