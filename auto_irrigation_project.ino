#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x3F  // Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN     3
#define BACKLIGHT_POL POSITIVE
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int soilHumiditySensorA0 = 0;
int relayD2 = 2;
int n = 1;

LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin, BACKLIGHT_PIN, BACKLIGHT_POL);


void setup() {
  Serial.begin(9600);
  
  //relay setup
  pinMode(relayD2,OUTPUT);

  //lcd setup
  lcd.begin (16,2);
  lcd.home ();                   // go home

  lcd.print("Moisture measur.");  
  lcd.setCursor ( 0, 1 );        // go to the 2nd line
  lcd.print("READY");

}

void loop() {
  // put your main code here, to run repeatedly:

}
