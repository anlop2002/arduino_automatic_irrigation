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

  //lcd setup A4==SDA, A5==SCL
  lcd.backlight(); 
  lcd.begin (16,2);
  lcd.home ();                   // go home

  lcd.print("Moisture measur.");  
  lcd.setCursor ( 0, 1 );        // go to the 2nd line
  lcd.print("READY");

}

void loop() {
  int sensorValue = analogRead(soilHumiditySensorA0); //A0
  Serial.println(sensorValue);
  
 if (sensorValue >= 615)
 {
  Serial.println("Dry");
  digitalWrite(relayD2,HIGH);
  lcd.home();
  lcd.clear();
  lcd.print("Watering Plants");
  delay(10000);
  digitalWrite(relayD2,LOW);
  }
  else if (sensorValue >= 410 && sensorValue < 615)
 {
  Serial.println("Perfect");
  lcd.home();
  lcd.clear();
  lcd.print("Optimal");
  lcd.setCursor ( 0, 1 );
  lcd.print("Humd.:");
  lcd.print(sensorValue);
  }    
else if (sensorValue >= 0 && sensorValue < 410)
 {
  Serial.println("Recently Irrigated");
  lcd.clear();
  lcd.home();
  lcd.print("Watered");
  lcd.setCursor ( 0, 1 );
  lcd.print("Humd.:");
  lcd.print(sensorValue);
  }
  delay(1000);
}
