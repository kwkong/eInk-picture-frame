#include <Arduino.h>
#include <EEPROM.h>
#include "LowPower.h"
#include "epd.h"

#define imageMaximum 75
#define imageCounterAddress 0

int dayCounter = 0;

void displayImage();
void restartCounter();

void setup()
{
	Serial.begin(115200);
	restartCounter();
	epd_set_memory(MEM_TF);
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
	int imageCounter = 0;
	String imageName = "i";

	EEPROM.get(imageCounterAddress, imageCounter);
	imageCounter++;

	if(imageCounter > 75)
	{
		imageCounter = 0;
	}

	EEPROM.put(imageCounterAddress,imageCounter);

	imageName += String(imageCounter);
	imageName += ".bmp";

	epd_clear();
	epd_disp_bitmap(imageName.c_str(), 0, 0);
	epd_udpate();
	delay(5000);
}

void restartCounter()
{
	int imageCounter = 0;
	EEPROM.put(imageCounterAddress, imageCounter);
	Serial.println("Comment this function out and restart device");
	while(1);
}