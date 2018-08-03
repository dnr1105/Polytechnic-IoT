#include <Wire.h> 
#include "LiquidCrystal_I2C.h"

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  Serial.begin(115200);

  lcd.print("HELLO");

}

void loop()
{
  if(Serial.available()>0){
    char input=Serial.read();
    if(input=='a'){
      lcd.print("AAAAAAAAA");
    }
    
    if(input=='p'){
      String msg = Serial.readString();
      if(msg.length()<16){
        lcd.print(msg);
      }
      else{
        String a = msg.substring(0,16);
        String b = msg.substring(16,32);
        lcd.print(a);
        lcd.setCursor(0,1);
        lcd.print(b);
      }
    }
    else if(input=='c'){
      lcd.clear();
    }
    else if(input=='s'){
      char temp;
      while(true){
        temp=Serial.read();
        if(temp=='t'){
          break;
        }
        lcd.scrollDisplayRight();
        delay(500);
      }
    }else if(input=='S'){
      char temp;
      while(true){
        temp=Serial.read();
        if(temp=='t'){
          break;
        }
        lcd.scrollDisplayLeft();
        delay(500);
      }
    }
  }
}

