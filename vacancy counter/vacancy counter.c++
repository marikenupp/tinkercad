// C++ code
#include <Adafruit_LiquidCrystal.h>
int dist = 0;
int vaga1 = 0;
int vaga2 = 0;
int vaga3 = 0;
int vaga4 = 0;
int sensor1 = 0;
int sensor2 = 0;
int sensor3 = 0;
int sensor4 = 0;

Adafruit_LiquidCrystal lcd_1(0);


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);

  lcd_1.begin(16, 2);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  sensor1 = 0.01723 * readUltrasonicDistance(A0, A0);
  sensor2 = 0.01723 * readUltrasonicDistance(A1, A1);
  sensor3 = 0.01723 * readUltrasonicDistance(A2, A2);
  sensor4 = 0.01723 * readUltrasonicDistance(A3, A3);
  // Declarar vagas
  if (sensor1 > 200) {
    vaga1 = 1;
  } else {
    vaga1 = 0;
  }
  if (sensor2 > 200) {
    vaga2 = 1;
  } else {
    vaga2 = 0;
  }
  if (sensor3 > 200) {
    vaga3 = 1;
  } else {
    vaga3 = 0;
  }
  if (sensor4 > 200) {
    vaga4 = 1;
  } else {
    vaga4 = 0;
  }
  Serial.print(vaga1);
  Serial.print(vaga2);
  Serial.print(vaga3);
  Serial.print(vaga4);
 
  Serial.println("");
  
  // Definir leds
  if (vaga1 == 1) {
    digitalWrite(2, LOW);
  } else {
    digitalWrite(2, HIGH);
  }
  if (vaga2 == 1) {
    digitalWrite(3, LOW);
  } else {
    digitalWrite(3, HIGH);
  }
  if (vaga3 == 1) {
    digitalWrite(4, LOW);
  } else {
  digitalWrite(4, HIGH);
  }
  if (vaga4 == 1) {
  digitalWrite(5, LOW);
  } else {
  digitalWrite(5, HIGH);
  }
  lcd_1.setCursor(0,0);
  lcd_1.clear();
  lcd_1.print("Vagas Comuns: ");
  lcd_1.print(vaga1 + vaga2);
  lcd_1.setCursor(0,1);
  lcd_1.print("Especiais: ");
  lcd_1.print(vaga3 + vaga4);
  delay(5000); // Wait for 5000 millisecond(s)
}