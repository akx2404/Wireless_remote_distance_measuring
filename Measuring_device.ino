#include <Wire.h>  
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address, if it's not working try 0x27.

int laser = 10;
int btn = 2;
int btnstate = 0;

const int trigPin =5;
const int echoPin =6;//defines variables---- trig==ouput;echo==input
long duration;
int distance;


void setup() {
  pinMode(laser, OUTPUT);
  pinMode(btn, INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  lcd.begin(16,2);
  lcd.backlight();

}

void loop() {
  btnstate = digitalRead(btn);

  if (btnstate == HIGH){
    digitalWrite(laser, HIGH);
    digitalWrite(trigPin,LOW);
    delayMicroseconds(10); 
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
  
    duration=pulseIn(echoPin,HIGH);
  
    distance=duration*0.0346*0.5;
  
    lcd.print(distance);
    lcd.print(" cm");
    delay(1000);
    lcd.clear();
  }

  else{
    digitalWrite(laser, LOW);
  }
}
