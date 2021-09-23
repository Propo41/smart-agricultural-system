#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);


void setup() {
  lcd.begin(16,2);
  pinMode(A2,INPUT);
}

void loop() {
  float val = analogRead(A2);
  val = val/1023;
  val = val*14;
  lcd.setCursor(0,0);
  lcd.print(val);
  delay(2000);
  lcd.clear();
  
}
