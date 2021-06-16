#include <LiquidCrystal.h>

#define PIR 2 //NIM = 1303180093, 93 mod 13 = 2
#define PIE 12//output data digital berupa piezo
#define LED 13//tambahan output biar beda aja

LiquidCrystal lcd(11, 10, 9, 8, 7, 6);

void setup() {
  
	pinMode(PIE, OUTPUT);
  	pinMode(PIR, INPUT);
  	pinMode(LED, OUTPUT);
  	Serial.begin(9600);
  	lcd.begin(16,2);
  
}

void loop(){
	lcd.setCursor(0,0);
  	lcd.print("Diam Nih");
  	lcd.setCursor(0,1);
  	lcd.print("Cari Pergerakan");
  	check_For_Intruder();
}
void check_For_Intruder(){
  	boolean sensorvalue = digitalRead(PIR);
  	if (sensorvalue==1){
  		digitalWrite(PIE,HIGH);
      	digitalWrite(LED,HIGH);
    	lcd.setCursor(0,0);
    	lcd.print("Ada yang lewat");
    	lcd.setCursor(0,1);
    	lcd.print("LED&PIEZO Hidup");
    	delay(3000);
    	lcd.clear();
    }else{
    	digitalWrite(PIE,LOW);
      	digitalWrite(LED,LOW);
    }
  	delay(10);
}