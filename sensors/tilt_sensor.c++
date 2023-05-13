// C++ code
int Led = 13;
int Tilt = 3;
int Estado;

void setup ()
{
pinMode(Led, OUTPUT);
pinMode(Tilt, INPUT);
Serial.begin(9600);
}
void loop()
{
Estado = digitalRead(Tilt);
  if(Estado == LOW){
  digitalWrite(Led, HIGH);
  }
  else{
  digitalWrite(Led, LOW);
  }
  Serial.print("Estado = ");
  Serial.println(Estado);
}