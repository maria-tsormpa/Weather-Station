#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>

// οθόνη
LiquidCrystal_I2C lcd(0x27 , 20, 4);

// LM35
const int LM35_Pin = A0;

//DHT11
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//BMP280
Adafruit_BMP280 bmp;

// LDR
const int LDR_Pin = A1;

//MQ135
int airValue = analogRead(A3);


//κουμπί
const int Button_Pin =3;
int page =0;
bool Button_State;
bool Prev_Button_State = HIGH;

void setup() {
  analogReference(DEFAULT);

  lcd.init();
  lcd.backlight();

  dht.begin();

  bmp.begin(0x76);

  pinMode(Button_Pin, INPUT_PULLUP);

}

void loop() {

// κουμπί
Button_State = digitalRead(Button_Pin);

if (Prev_Button_State==HIGH && Button_State==LOW)
{
  page++;

  if(page>3)
  {
     page=0;
  }

  delay(250);
}

Prev_Button_State = Button_State;

lcd.clear();

if(page==0)
{
  // LM35
  float temp_lm35;
  temp_lm35 = (analogRead(LM35_Pin)*5.0*100.0/1024.0);

  
 lcd.setCursor(0,0);
 lcd.print("T_A: ");
 lcd.print(temp_lm35);
 lcd.print(" C");

 //DHT11 θερμοκρασία
  float temp_dht = dht.readTemperature();

 lcd.setCursor(0,1);
 lcd.print("T_D: ");
 lcd.print(temp_dht);
 lcd.print(" C");
 
}
else if (page==1)
{
  // DHT11 υγρασία
  float humidity = dht.readHumidity();

  lcd.setCursor(0,0);
  lcd.print("Humidity:");
  lcd.print(humidity);
  lcd.print("%");

  //LDR
  int light = analogRead(A1);
  String LDR_state;

  if(light > 850)
  {
    LDR_state = "Day";
  }
  else if(light > 400)
  {
    LDR_state ="Cloudy";
  }
  else
  {
    LDR_state ="Night";
  }
  
  lcd.setCursor(0,1);
  lcd.print(LDR_state);
  
}
else if (page==2)
{
  //BMP280
  float pressure = bmp.readPressure()/100.0;

  String pressure_state;
  if (pressure <1000)
  {
    pressure_state = "Low";
  }
  else if(pressure<1015)
  {
    pressure_state="Normal";
  }
  else
  {
    pressure_state = "High";
  }
  
  lcd.setCursor(0,0);
  lcd.print("P: ");
  lcd.print(pressure);
  lcd.print(" hPa");
  
  lcd.setCursor(0,1);
  lcd.print(pressure_state);

}
else if (page==3)
{
  float altitude = bmp.readAltitude(1013.25);

  lcd.setCursor(0,0);
  lcd.print("Alt:");
  lcd.print(altitude);
  lcd.print(" m");

  //MQ135
  
  String airQuality;

  int air = 0;
  for(int i=0; i<10; i++)
  {
    air += analogRead(A3);
    delay(10);
  }

  air= air/10;

  if (air <= 16)
  {
    airQuality = "Good";
  }
  else if (air <= 18)
  {
    airQuality = "Moderate";
  }
  else
  {
    airQuality = "Bad";
  }

  lcd.setCursor(0,1);
  lcd.print("Air:");
  lcd.print(airQuality);

}

 delay(1000);
}

