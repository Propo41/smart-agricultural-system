#include <LiquidCrystal.h>
#include<SoftwareSerial.h>
#include "DHT.h" //version 1.3.0 by AdaFruit
#include<Servo.h>

SoftwareSerial mySerial(9,10); // RX, TX

// Defining Light sensor pin
#define LIGHTBULB_PIN 30

// Defining LDR sensor pin
#define LDR_PIN A2

// Defining Moisture sensor pin
#define MoistureSensorPin A0 

#define PH_PIN A3

// Defining Temperature & Humidity sensor pin
#define DHTPIN 7
#define DHTTYPE DHT22
DHT dht(DHTPIN,DHTTYPE);

// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(26, 27, 22, 23, 24, 25);

// creating servo object to control a servo motor
Servo shadeMotor;
//Servo fanMotor;

#define WATER_PUMP_FORWARD 34
#define WATER_PUMP_REVERSE 35

#define WATER_SPRAY_FORWARD 39
#define WATER_SPRAY_REVERSE 40

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  mySerial.begin(9600); // Baud rate for GSM module
  Serial1.begin(9600); // Baud rate for Serial monitor
  dht.begin();
  shadeMotor.attach(4); // servo for Shade on pin 4
//  fanMotor.attach(5); // servo for Fan on pin 5
  pinMode(LIGHTBULB_PIN, OUTPUT); // setting output pin for light bulbs
  pinMode(A2,INPUT);
  pinMode(PH_PIN,INPUT);

  // initializing pinMode for Water pump & sprayer
  pinMode(WATER_PUMP_FORWARD, OUTPUT);  
  pinMode(WATER_PUMP_REVERSE, OUTPUT); 
  pinMode(WATER_SPRAY_FORWARD, OUTPUT);  
  pinMode(WATER_SPRAY_REVERSE, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int moistureSensorValue = analogRead(MoistureSensorPin);
  float moistureSensorVolts = analogRead(MoistureSensorPin)*0.0048828125; 

  float humidityValue = dht.readHumidity();
  float temperatureValue = dht.readTemperature();

  int ldrValue = analogRead(LDR_PIN);

  digitalWrite(WATER_PUMP_FORWARD, LOW);
  digitalWrite(WATER_PUMP_REVERSE, HIGH);

  digitalWrite(WATER_SPRAY_FORWARD, HIGH);
  digitalWrite(WATER_SPRAY_REVERSE, LOW); 

//  Humidity and Temperature sensor
//  lcd.setCursor(0,0);
//  lcd.print("Temp: ");
//  lcd.print(temperatureValue);
//  lcd.print(" C");
//  lcd.setCursor(0,1);
//  lcd.print("Hum: ");
//  lcd.print(humidityValue);
//  lcd.print(" %");
//  delay(500);

  digitalWrite(LIGHTBULB_PIN, HIGH);

  ph_read();
  
}

void ph_read(){
  float phValue = analogRead(PH_PIN);
  phValue = phValue/1023;
  phValue = phValue*14;
  lcd.setCursor(0,0);
  lcd.print(phValue);
}
