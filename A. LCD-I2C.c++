#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
String msg = " Araucaria/CAPAO RASO ";
String final_msg = "";

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
}

void loop(){
  for (int i = 0; i < msg.length() ; i++){
    final_msg = final_msg + msg[i];
    lcd.print(final_msg);
  }
}