// Created by Alex James
// Created on Oct. 2023
// Template taken from Autodesk Instructables

#include <Servo.h>

Servo servo;

const int trigPin = 3;
const int echoPin = 2;
float duration, distance;

// setup
void setup() {
    Serial.begin (9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    servo.attach(4);
}

// forever loop
void loop() {
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2; 
    if (distance < 50) {
        Serial.print("distance:  ");
        Serial.println(distance);
        servo.write(90);
  
        delay(500);
    } else if (distance > 50) {
        Serial.print("distance:  ");
        Serial.println(distance);
        servo.write(0); 
    }

    delay(500);
}