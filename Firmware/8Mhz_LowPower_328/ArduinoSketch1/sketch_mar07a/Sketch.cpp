


#include <Arduino.h>
#include "epd.h"
#include <LowPower.h>
#include <SoftwareSerial.h>

#define eink_EN 4

unsigned long rxTimeout = 0;
//SoftwareSerial loraSerial(2,3);
String message;

const int wake_up = 2;
const int reset = 3;

void setup()
{
  //pinMode(4, OUTPUT);
  //digitalWrite(4, HIGH);
  //delay(1000);
  //loraSerial.begin(9600);
  //Serial.begin(9600);
  //Serial.println("init");
 
  pinMode(eink_EN, OUTPUT);
  
  delay(2000);
  digitalWrite(eink_EN, HIGH);
  delay(4000);
  
		Serial.begin(57600);
      //epd_init(wake_up, reset);
		delay(1000);
      epd_wakeup(wake_up);
	  delay(1000);
      epd_set_memory(MEM_NAND);
      delay(1000);
      //epd_clear();
      delay(2000);
  
	//   char buff[] = {'G', 'B', 'K', '3', '2', ':', ' ', 0xc4, 0xe3, 0xba, 0xc3, 0xca, 0xc0, 0xbd, 0xe7, 0x00};
	epd_set_color(BLACK, WHITE);
	delay(1000);
	//   epd_set_ch_font(GBK32);
	//   epd_set_en_font(ASCII32);
	//   epd_disp_string(buff, 0, 50);
	//   epd_disp_string("ASCII32: Hello, World", 0, 300);

	//   epd_set_ch_font(GBK48);
	//   epd_set_en_font(ASCII48);
	//   buff[3] = '4';
	//   buff[4] = '8';
	//   epd_disp_string(buff, 0, 100);
	//   epd_disp_string("ASCII48: Hello, World", 0, 350);

	epd_set_ch_font(GBK64);
	delay(1000);
	epd_set_en_font(ASCII64);
	delay(1000);
	//   buff[3] = '6';
	//   buff[4] = '4';
	//   epd_disp_string(buff, 0, 160);
	epd_disp_string("JANICE IS BIG DUMB", 190, 200);
	delay(1000);
	epd_udpate();
	delay(3000);
	epd_clear();
	delay(3000);
	epd_disp_string("JK SHE AIIGHT", 250, 200);
	epd_udpate();

	delay(3000);
  
  
  delay(1000);
  digitalWrite(eink_EN, LOW);

}

void loop()
{
	//Serial.println("Going to sleep now");
	//delay(500);
	//LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); 
}
