const int pingTrigPin = A4;
const int pingEchoPin = A5;
const int ledPin = 9;
const int buzzerPin = 7;
const int motorPin = 12;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode (buzzerPin, OUTPUT);
  pinMode (motorPin, OUTPUT);
  pinMode(pingTrigPin, OUTPUT);
  pinMode(pingEchoPin, INPUT);
}
void loop() {
  long distanceInCentimeters = measureDistance();
  if (distanceInCentimeters > 0 && distanceInCentimeters <= 200) { 
    controlLEDAndBuzzer (distanceInCentimeters); 
  }

  Serial.print(distanceInCentimeters);
  Serial.println("cm");
  delay(40);
}
long measureDistance() {
  digitalWrite(pingTrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingTrigPin, LOW);
  long duration = pulseIn(pingEchoPin, HIGH);
  return microsecondsToCentimeters(duration);
}
void controlLEDAndBuzzer (long distanceInCentimeters) {
  int delayTime = map(distanceInCentimeters, 1, 100, 10, 1000);
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(motorPin, HIGH);
  delay(50);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(motorPin, LOW);
  delay(delayTime);
}
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29/ 2;
}