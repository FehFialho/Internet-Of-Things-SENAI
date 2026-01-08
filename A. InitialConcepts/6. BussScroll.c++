// ========= COMPONENTS =========
// - Arduino UNO
// - 16x2 LCD Display (HD44780 compatible)
// - 10k Potentiometer (contrast adjustment)
// - Jumper Wires

// ========= LCD CONNECTIONS (4-BIT MODE) =========
// - Pin 1  (VSS) -> GND
// - Pin 2  (VDD) -> 5V
// - Pin 3  (V0)  -> Potentiometer middle pin
// - Pin 4  (RS)  -> Digital Pin 12
// - Pin 5  (RW)  -> GND
// - Pin 6  (E)   -> Digital Pin 11
// - Pin 7  (D0)  -> Not connected
// - Pin 8  (D1)  -> Not connected
// - Pin 9  (D2)  -> Not connected
// - Pin 10 (D3)  -> Not connected
// - Pin 11 (D4)  -> Digital Pin 5
// - Pin 12 (D5)  -> Digital Pin 4
// - Pin 13 (D6)  -> Digital Pin 3
// - Pin 14 (D7)  -> Digital Pin 2
// - Pin 15 (A)   -> 5V (Backlight)
// - Pin 16 (K)   -> GND (Backlight)

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String texto = "H01 - Araucaria/Capao Raso ";
int tamanhoLCD = 16;
int offset = 0;

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);

  // escreve exatamente 16 caracteres
  for (int i = 0; i < tamanhoLCD; i++) {
    int indice = (i - offset + texto.length()) % texto.length();
    lcd.print(texto[indice]);
  }

  lcd.setCursor(0, 1);
  lcd.print(" 6:21 6:28 6:34 6:42");

  offset++;

  if (offset >= texto.length()) {
    offset = 0;
  }

  delay(250);
}
