const int Red_Cars_Pin = 4;
const int Blue_Cars_Pin = 7;
const int Green_Cars_Pin = 9;
const int Red_Ped_Pin = 11;
const int Green_Ped_Pin = 12;
const unsigned long Blue_Delay=2000;
const unsigned long wait_to_ph2 =4000;
volatile unsigned long Green_Delay;
volatile unsigned long Red_Delay;
unsigned long start_time;
unsigned long elapsed_time=0;

void setup()
{
pinMode(Red_Cars_Pin,OUTPUT);
pinMode(Blue_Cars_Pin,OUTPUT);
pinMode(Green_Cars_Pin,OUTPUT);
pinMode(Red_Ped_Pin,OUTPUT);
pinMode(Green_Ped_Pin,OUTPUT);
attachInterrupt(0, buttonpush, RISING);
}

void loop()
{
 Green_Delay=10000;
 Red_Delay=5000;
 digitalWrite(Red_Ped_Pin,HIGH);
 digitalWrite(Green_Cars_Pin,HIGH);
 elapsed_time=0;
 start_time=millis();
 while(elapsed_time <= Green_Delay)
 {
  elapsed_time = millis() - start_time;
 }
 digitalWrite(Green_Cars_Pin,LOW);
 digitalWrite(Blue_Cars_Pin, HIGH);
 start_time = millis();
 while(millis()-start_time <= Blue_Delay)
 {

 }
 digitalWrite(Blue_Cars_Pin,LOW);
 digitalWrite(Red_Cars_Pin,HIGH);
 digitalWrite(Red_Ped_Pin,LOW);
 digitalWrite(Green_Ped_Pin,HIGH);
 start_time=millis();
 while (millis()-start_time <= Red_Delay)
 {

 }
 digitalWrite(Green_Ped_Pin,LOW);
 digitalWrite(Red_Cars_Pin,LOW);
}

void buttonpush()
{
  if(Green_Delay - elapsed_time > wait_to_ph2)
  {
    Green_Delay = elapsed_time + wait_to_ph2;
  }
  Red_Delay = 7000;
}

