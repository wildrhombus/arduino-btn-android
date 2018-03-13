#include <Wire.h>
#include <Servo.h>

#include <Max3421e.h>
#include <Usb.h>
#include <AndroidAccessory.h>

AndroidAccessory acc("WildRhombus",
		     "Blinky",
		     "Blinky Arduino Board",
		     "1.0",
		     "http://www.android.com",
		     "0000000012345678");

const int sensorPin = A0;     // the number of the pushbutton pin

int sensorValue = 0;
void setup()
{
	Serial.begin(115200);
	Serial.print("\r\nStart");

	acc.powerOn();
}

void loop()
{
  byte msg[2];
  msg[0] = 0x1;
  static byte b = 0;
   
  if (acc.isConnected()) {
    sensorValue = analogRead(sensorPin);
    Serial.println(sensorValue);
    if( sensorValue < 800 ) {
      b = 0;
    } else {
      b = 1;
    }
    
    msg[1] = b;
    acc.write(msg, 2);
  } 
}
