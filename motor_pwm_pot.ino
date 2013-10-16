/*
Control a motor speed using a potentiometer
*/

int enablePin = 9;
int ledPin = 8; //LED 
int potPin = 0; //potentiometer speed control

int speed_;

void setup() {
  Serial.begin (9600);
  pinMode(enablePin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT); 
  blink(ledPin, 10, 200);  //indicate start/restart
}
 
void loop() {
  motor();
}
 
void motor() {  
  speed_ = analogRead(potPin)/4;
  if ( speed_ < 50 ) speed_ = 50;
  analogWrite(enablePin, speed_); 
  Serial.println(speed_);
}

void blink(int whatPin, int howManyTimes, int milliSecs) {
  for ( int i = 0; i < howManyTimes; i++) {
  digitalWrite(whatPin, LOW);
  delay(milliSecs/2);
  digitalWrite(whatPin, HIGH);
  delay(milliSecs/2);
  }
}
