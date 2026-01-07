// Project to display text and scrolling messages on a 16x2 LCD (HD44780).

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

// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
}

void loop() {

  lcd.clear(); // Clear the LCD screen

  // Set cursor to column 3, row 0
  lcd.setCursor(3, 0);
  lcd.print("Absolute IoT");

  // Set cursor to column 3, row 1
  lcd.setCursor(3, 1);
  lcd.print("With LCD 16x2");

  delay(4000);

  // Scroll the display to the left
  for (int position = 0; position < 3; position++) {
    lcd.scrollDisplayLeft();
    delay(300);
  }

  // Scroll the display to the right
  for (int position = 0; position < 6; position++) {
    lcd.scrollDisplayRight();
    delay(300);
  }
}