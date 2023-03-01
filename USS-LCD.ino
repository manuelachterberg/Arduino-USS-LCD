
/*
  IoT Beispiel für IT Basics Training

 Demonstrates the use a 16x2 LCD display in combination with a Ultrasound Sensor.

  The  LCD circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */

// include the library code:
#include <LiquidCrystal.h>
#include "SR04.h"
// setup the trigger and echo pin for USS
#define TRIG_PIN 6
#define ECHO_PIN 5
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("IT Basics!");
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  // print the number of seconds since reset:
  a=sr04.Distance();
  Serial.print(a);
  Serial.println("cm");
  lcd.setCursor(0, 1);
  lcd.print("     ");
  lcd.setCursor(0, 1);
  lcd.print(a);
  lcd.setCursor(5, 1);
  lcd.print("cm");
  delay(1000);
}

