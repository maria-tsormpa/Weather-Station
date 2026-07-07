#include <LiquidCrystal.h>

// οθόνη LCD
LiquidCrystal lcd(2,3,4,5,6,7);

// LM35 αναλογικός αισθητήρας θερμοκρασίας
const int LM35_Pin = A0;

void setup() {
  // τάση αναφοράς 1.1 V
  analogReference(INTERNAL);

  lcd.begin(16,2);

}

void loop() {
  // υπολογισμός της θερμοκρασίας
  float temperature;

  float value = analogRead(LM35_Pin);

  temperature = (value*0.85*100.0/1024.0); // βαθμινόμηση (0.85 αντι για 1.1)
  
  // εμφάνιση στην οθόνη
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("T: ");
  lcd.print(temperature);
  lcd.print((char)223);
  lcd.print("C");

  delay(1000);

}
