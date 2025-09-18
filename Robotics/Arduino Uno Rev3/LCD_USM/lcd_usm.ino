//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>
#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 300 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
float distance;

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup()
{
  lcd.init();                      // initialize the lcd 
  
  // Print a message to the LCD.
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Turning ON");
  delay(1200);
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("Distance ");
  lcd.setCursor(1,1);
  lcd.print("Measurement Device ");
  delay(2000);
  lcd.clear();
  
}


void loop()
{
  lcd.setCursor(1,0);
  lcd.print("Distance in CM");
  distance = sonar.ping_cm();
  lcd.setCursor(4,1);
  lcd.print(distance);
  lcd.print("           ");
  delay(100);
}
