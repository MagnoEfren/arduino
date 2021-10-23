#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //  (0x3f,16,2) || (0x38,16,2)  ||(0x20,16,2)

byte a[8] = {
B11111,      
B10000,     
B10000,     
B10000,     
B10001,     
B10011,     
B10011,     
B10011      
 


};

byte b[8] = {
B11111,      
B00000,     
B00000,     
B11100,     
B11110,     
B11111,     
B11111,     
B11111      


};

byte c[8] = {
B11111,      
B00000,     
B00000,     
B01110,     
B11111,     
B11111,     
B11111,     
B11111      


};


byte d[8] = {
B11111,      
B00001,     
B00001,     
B00001,     
B10001,     
B11001,     
B11001,     
B11001      

/////////////
};


byte e[8] = {
B10001,      
B10000,     
B10000,     
B10000,     
B10000,     
B10000,     
B10000,     
B11111      



};

byte f[8] = {
B11111,        
B11111,       
B01111,       
B00111,       
B00011,       
B00001,       
B00000,       
B11111,       


};

byte g[8] = {
B11111,        
B11110,       
B11100,       
B11000,       
B10000,       
B00000,       
B00000,       
B11111,       



};


byte h[8] = {
B00001,        
B00001,       
B00001,       
B00001,       
B00001,       
B00001,       
B00001,       
B11111,       
      



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
  lcd.createChar(5, f);
  lcd.createChar(6, g);
 lcd.createChar(7, h);
 lcd.begin(16, 2);

}

void loop() {

for  (int a=0;a>10;a++){
  lcd.scrollDisplayLeft();
  delay(250);
}
  for(int a=0;a<10;a++){
  lcd.scrollDisplayRight();
  delay(250);
}


  lcd.setCursor(0, 0);
  lcd.write(byte(0));

  lcd.setCursor(1, 0);
  lcd.write(byte(1));

  lcd.setCursor(2, 0);
  lcd.write(byte(2));


  lcd.setCursor(3, 0);
  lcd.write(byte(3));

///
  lcd.setCursor(0, 1);
  lcd.write(byte(4));

  lcd.setCursor(1, 1);
  lcd.write(byte(5));

  lcd.setCursor(2, 1);
  lcd.write(byte(6));


  lcd.setCursor(3, 1);
  lcd.write(byte(7));

lcd.print("Electronics");

  /// ........................


}
