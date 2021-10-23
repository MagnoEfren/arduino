#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //  (0x3f,16,2) || (0x38,16,2)  ||(0x20,16,2)

byte a[8] = {
B00000,      
B00000,     
B01000,     
B00100,     
B00010,     
B00001,     
B00000,     
B00000      
     
 


};

byte b[8] = {
B10000,      
B11000,     
B10100,     
B10010,     
B10001,     
B10010,     
B10100,     
B11000      
     

};

byte c[8] = {
B00001,        
B00010,       
B00100,       
B01000,       
B00000,       
B00000,       
B00000,       
B00000      
    


};


byte d[8] = {
B10100,        
B10010,       
B10001,       
B10010,       
B10100,       
B11000,       
B10000,       
B00000       
     


};

//Linea

byte e[8] = {

B00000,      
B00010,     
B00010,     
B00110,     
B00110,     
B01110,     
B01110,     
B11110      
     

};





void setup() {

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.createChar(0, a);
  lcd.createChar(1, b);
  lcd.createChar(2, c);
  lcd.createChar(3, d);
 lcd.createChar(4, e);
 
 lcd.begin(16, 2);

}

void loop() {




  lcd.setCursor(0, 0);
  lcd.write(byte(0));

  lcd.setCursor(1, 0);
  lcd.write(byte(1));

  lcd.setCursor(0, 1);
  lcd.write(byte(2));


  lcd.setCursor(1, 1);
  lcd.write(byte(3));



  //linea


  lcd.setCursor(3, 0);
  lcd.write(byte(4));
  
  lcd.setCursor(2, 0);
  lcd.write(byte(4));
  


}
