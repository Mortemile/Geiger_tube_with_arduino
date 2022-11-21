/*
 * Calibration tube depends of the radioactive element (for J305ß):
 * Co-60: 123 counts per minute = 1 μSv/h, conversion factor  = 1/123 = 0.0081
 * Cs-137: 111 counts per minute = 1 μSv/h, conversion factor  = 1/111 = 0.009
 */

#include <LiquidCrystal_I2C.h>
#include <Wire.h>


volatile unsigned int counts = 0;  // num of events
unsigned long cpm  = 0;  // counts per minute
int intTime = 15000; // integration time
float conversion_factor_Co_60 = 0.0081;
float conversion_factor_Cs_137 = 0.009;
double numOfMeas = 0;
double avgCPM = 0;
double avgDose = 0;
double totalCPM = 0;
double totalDose = 0;
double Dose = 0;
const int inputPin = 2;  // output from P3 on scheme

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 

void impulse(){
  counts++;
}

void setup() {
  Serial.begin(9600);

  lcd.init(); // initialize the lcd
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Please wait...");

  pinMode(inputPin, INPUT); 

  attachInterrupt(digitalPinToInterrupt(inputPin), impulse, FALLING);  // FALLING - HIGH to LOW
}

 void loop(){
  Serial.print("Start measure");
  Serial.print("\n");
  
  
  delay(intTime);  

  lcd.clear();
  
  Serial.print("Calculating...");
  Serial.print("\n");
  
  cpm = counts * (60000 / intTime);
  Dose = cpm * conversion_factor_Co_60;

  Serial.print("The number of events for 15 sec ");
  Serial.print(counts);
  Serial.print("\n");
  Serial.print("cpm:");
  Serial.print(cpm);
  Serial.print("\n");
  Serial.print("Dose:");
  Serial.print(Dose);
  Serial.print(" uSv/h");
  Serial.print("\n");
  lcd.print("Dose = ");
  lcd.print(Dose);

//  average meanings

  numOfMeas++;
  totalCPM +=cpm;
  totalDose +=Dose;

  avgCPM = totalCPM / numOfMeas;
  avgDose = totalDose / numOfMeas;

  Serial.print("Average cpm:");
  Serial.print(avgCPM);
  Serial.print("\n");
  Serial.print("Average dose:");
  Serial.print(avgDose);
  Serial.print(" uSv/h");
  Serial.print("\n");
  Serial.print("\n");

  lcd.setCursor(0, 1);
  lcd.print("AvDose = ");
  lcd.print(avgDose);

  counts = 0;
   
 }
