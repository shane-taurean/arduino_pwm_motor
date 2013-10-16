/*
Adafruit Arduino - Lesson 15. Bi-directional Motor
*/
 
int enablePin = 9;
int speed_ = 256;
int ledPin = 8; //LED 

void setup()
{
  Serial.begin (9600);
  pinMode(enablePin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  blink(ledPin, 10, 200);
}
 
void loop()
{
  motor();
}
 
void motor()
{  
  for ( int speed_ = 64; speed_ < 256; speed_++ ) {
    Serial.println(speed_);
    analogWrite(enablePin, speed_); 
    delay(200);    
  }
  for ( int speed_ = 255; speed_ > 64; speed_-- ) {
    Serial.println(speed_);
    analogWrite(enablePin, speed_); 
    delay(200);    
  }
}

void blink(int whatPin, int howManyTimes, int milliSecs) {
  int i = 0;
  for ( i = 0; i < howManyTimes; i++) {
  digitalWrite(whatPin, LOW);
  delay(milliSecs/2);
  digitalWrite(whatPin, HIGH);
  delay(milliSecs/2);
  }
}
