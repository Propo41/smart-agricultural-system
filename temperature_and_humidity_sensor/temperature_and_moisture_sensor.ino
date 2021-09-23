#include "DHT.h"
#define DHTPIN 7
#define DHTTYPE DHT22
DHT dht(DHTPIN,DHTTYPE);
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

void setup() {
 lcd.begin(16,2);
 dht.begin();
}

void loop() {
  float h=dht.readHumidity();
  float t=dht.readTemperature();

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Hum: ");
  lcd.print(h);
  lcd.print(" %");
  delay(500);
  
  
}
