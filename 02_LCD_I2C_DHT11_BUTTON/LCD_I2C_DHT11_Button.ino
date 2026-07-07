#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// οθόνη
LiquidCrystal_I2C lcd(0x27 , 20 , 4);

// LM35
const int LM35_Pin = A0;

// DHT11
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN , DHTTYPE);

// κουμπί
const int Button_Pin = 3;
int page = 0 ;
bool Prev_Button_State = LOW;

void setup() {
  analogReference(INTERNAL);

  lcd.init();
  lcd.backlight();

  dht.begin();

  pinMode(Button_Pin, INPUT);
  
}

void loop() {
  // κουμπί
  bool Button_State = digitalRead(Button_Pin);
  if (Prev_Button_State == LOW && Button_State == HIGH)
  {
    page++;
    if (page>1)
    {
      page =0;
    }
    delay(250);
  }

  Prev_Button_State = Button_State;
  lcd.clear();
  
  if (page==0)
  {
    // LM35
    float temp_lm35;

    temp_lm35 = (analogRead(LM35_Pin)*0.85*100.0/1024.0);

    // οθόνη σελίδα 1
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("T_A: ");
    lcd.print(temp_lm35);
    lcd.print((char)223);
    lcd.print("C");

    // DHT11 θερμοκρασία
    float temp_dht = dht.readTemperature();

    // οθόνη σελίδα 1
    lcd.setCursor(0,1);
    lcd.setCursor(0,1);
    lcd.print("T_D: ");
    lcd.print(temp_dht);
    lcd.print((char)223);
    lcd.print("C");
  }
  else if (page==1)
  {
    // DHT11 υγρασία
    float humidity = dht.readHumidity();

    // οθόνη σελίδα 2
    lcd.setCursor(0,0);
    lcd.print("Humidity;");
    lcd.print(humidity);
    lcd.print("%");
  }

  delay(1000);
  
}
