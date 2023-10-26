#include <Ultrasonic.h>


Ultrasonic ultrasonic(7, 6);
const int led1Pin = 12;    
const int led2Pin = 13;    
const int buzzerPin = 10;  


void setup() {
  Serial.begin(9600);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  delay(5000); 
}


void loop() {
  int distancia = ultrasonic.distanceRead(CM);
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
 
  if (distancia > 0 && distancia < 10 ) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    tone(buzzerPin, 261);
    delay(200);
    noTone(buzzerPin);
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    delay(200);
  } else {
    noTone(buzzerPin);
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
  }
}