/****************************************************************
* Ar2D2 : An Android remote controlled Arduino Car
* By Oliver H and Brook H
* Our CS 362 Project
*
* Description:
* -----------
* This small script waits for input from the Anrdoid device through
* Bluetooth. The Anrdoid app sends the integer 1 - 5 which in this
* script lights up one of 5 LEDs. However this is also used to
* control the direction of the car. Forward, Reverse, Left, Right, Stop.
*
* Code written by Oliver H
*
*/
/****************************************************************/

#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);
// creates a "virtual" serial port/UART
// connect BT module TX to D10
// connect BT module RX to D11
// connect BT Vcc to 5V, GND to GND

int yellow = 2;
int blue = 3;
int red = 4;
int green = 5;
int other = 6;

boolean yLight = false;
boolean bLight = false;
boolean rLight = false;
boolean gLight = false;

void setup()
{
  // set digital pin to control as an output
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(other, OUTPUT);

  // set the data rate for the SoftwareSerial port
  Serial.begin(9600);
  BT.begin(9600);
  // Send test message to other device
  BT.println("Hello from Arduino");

}
char a; // stores incoming character from other device
void loop()
{
  if (BT.available())
    // if text arrived in from BT serial...
  {

    a = (BT.read());
    Serial.write(a);
    switch (a) {

        digitalWrite(yellow, HIGH);
        digitalWrite(blue, LOW);
        digitalWrite(red, LOW);
        digitalWrite(green, LOW);
        digitalWrite(other, LOW);
        break;

      case '2':

        digitalWrite(blue, HIGH);
        digitalWrite(yellow, LOW);
        digitalWrite(red, LOW);
        digitalWrite(green, LOW);
        digitalWrite(other, LOW);
        break;

      case '3':

        digitalWrite(red, HIGH);
        digitalWrite(blue, LOW);
        digitalWrite(yellow, LOW);
        digitalWrite(green, LOW);
        digitalWrite(other, LOW);
        break;

      case '4':

        digitalWrite(green, HIGH);
        digitalWrite(blue, LOW);
        digitalWrite(red, LOW);
        digitalWrite(yellow, LOW);
        digitalWrite(other, LOW);
        break;

     case '5':

        digitalWrite(other, HIGH);
        digitalWrite(green, LOW);
        digitalWrite(blue, LOW);
        digitalWrite(red, LOW);
        digitalWrite(yellow, LOW);
        break;

      default:
        // if nothing else matches, do the default
        // default is optional
        break;
    }

    // you can add more "if" statements with other characters to add more commands
  }
}
