#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>

// οθόνη
LiquidCrystal_I2C lcd(0x27 , 20, 4);

// LM35
const int LM35_Pin = A0;


// DHT11
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// BMP280
Adafruit_BMP280 bmp;

// LDR
const int LDR_Pin = A1;

// MQ135
const int MQ135_Pin = A3;
int mq135_bash =0;


// κουμπί
const int Button_Pin =3;
int page = 0;
bool Button_State;
bool Prev_Button_State = HIGH;
int prev_page = -1;

// υψόμετρο Καλαμαριάς
float localAltitude = 40.0;

// διορθωμένη πίεση αναφοράς για BMP280
float seaLevelPressure = 1013.25;



// Συνάρτηση κουμπιού
void CheckButton()
{
  Button_State = digitalRead(Button_Pin);

    // Έλεγχος αλλαγής HIGH σε LOW
    if (Prev_Button_State == HIGH && Button_State == LOW) {
      page++;

      if(page > 3) {
        page = 0;
      }
    }

  Prev_Button_State = Button_State;
}


void setup() {
  
  analogReference(DEFAULT); 

  lcd.init();
  lcd.backlight();

  dht.begin();

  bmp.begin(0x76);

  // Calibration πίεση αναφοράς με βάση το τοπικό υψόμετρο
  seaLevelPressure = bmp.seaLevelForAltitude(localAltitude, bmp.readPressure()/100.0);

  pinMode(Button_Pin, INPUT_PULLUP);

  // MQ135 calibration
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Calibrating");
  lcd.setCursor(0,1);
  lcd.print("Air...");


  for(int i=0; i<100; i++) {
    mq135_bash += analogRead(MQ135_Pin);
    delay(50);
  }

  mq135_bash /=100;

  lcd.clear();

}


void loop() {

  CheckButton();

  if (page != prev_page) {
    lcd.clear();
    prev_page = page;
  }


  if(page == 0) {
  
    // LM35 θερμοκρασία
    float temp_lm35 = (analogRead(LM35_Pin)*5.0*100.0/1024.0);
 
    float temp_lm35_corrected =0.049* temp_lm35 + 23.471;

    // οθόνη σελίδα 1

    lcd.setCursor(0,0);
    lcd.print("T_A: ");
    lcd.print(temp_lm35_corrected);
    lcd.print((char)223);
    lcd.print("C");

    // DHT11 θερμοκρασία

    float temp_dht = dht.readTemperature();

    float temp_dht_corrected = 0.642 * temp_dht + 6.557;

    // οθόνη σελίδα 1

    lcd.setCursor(0,1);
    lcd.print("T_D: ");
    lcd.print(temp_dht_corrected);
    lcd.print((char)223);
    lcd.print("C");

  }


  else if (page==1) {
  
    // DHT11 υγρασία
    float humidity = dht.readHumidity();

    // οθόνη σελίδα 2
    lcd.setCursor(0,0);
    lcd.print("Humidity:");
    lcd.print(humidity);
    lcd.print("%");

    // LDR
    int light = analogRead(LDR_Pin);

    String LDR_state;

    if(light > 850) {
      LDR_state = "Day";
    }
    else if(light > 400) {
      LDR_state ="Cloudy";
    }
    else {
      LDR_state ="Night";
    }

    // οθόνη σελίδα 2
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print(LDR_state);

  }


  else if (page==2) {
    
    //BMP280
    float pressure = bmp.seaLevelForAltitude(localAltitude, bmp.readPressure()/100.0);

    String pressure_state;

    if (pressure <1000) {
      pressure_state = "Low";
    }
    else if(pressure<1018) {
      pressure_state="Normal";
    }
    else {
      pressure_state = "High";
    }

    // οθόνη σελίδα 3
    lcd.setCursor(0,0);
    lcd.print("                    ");
    lcd.setCursor(0,0);
    lcd.print("P: ");
    lcd.print(pressure);
    lcd.print(" hPa");
  
    lcd.setCursor(0,1);
    lcd.print("               ");
    lcd.setCursor(0,1);
    lcd.print(pressure_state);

  }


  else if (page==3) {
  
    float altitude = bmp.readAltitude(seaLevelPressure);

    // οθόνη σελίδα 4

    lcd.setCursor(0,0);
    lcd.print("Alt:");
    lcd.print(altitude);
    lcd.print(" m");

    //MQ135
  
    String airQuality;

    int value= analogRead(MQ135_Pin);

    int delta = value - mq135_bash;

    if (delta < 20) {
      airQuality = "Good";
    }
    else if (delta < 60) {
      airQuality = "Moderate";
    }
    else {
      airQuality = "Poor";
    }

    // οθόνη σελίδα 4
    lcd.setCursor(0,1);
    lcd.print("                    ");
    lcd.setCursor(0,1);
    lcd.print("Air:");
    lcd.print(airQuality);

  }

  delay(500);

}