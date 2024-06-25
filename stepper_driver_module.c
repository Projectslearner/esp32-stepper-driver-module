/*
   Project name: ESP32 Stepper Motor Control
   Modified Date: 25-06-2024
   Code by: Projectslearner
   Website: https://projectslearner.com/learn/esp32-stepper-motor-control
*/

// Define pin connections for the stepper motor driver module
const int stepPin = 12; // GPIO pin for STEP signal
const int dirPin = 14;  // GPIO pin for DIR signal

// Define variables for motor control
int stepsPerRevolution = 200; // Number of steps per full revolution of your motor

void setup() {
  // Set the GPIO pins as outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  
  // Initialize Serial communication
  Serial.begin(9600);
}

void loop() {
  // Rotate motor clockwise for one revolution
  rotateClockwise(stepsPerRevolution);
  delay(1000); // Delay for 1 second
  
  // Rotate motor counterclockwise for one revolution
  rotateCounterclockwise(stepsPerRevolution);
  delay(1000); // Delay for 1 second
}

// Function to rotate motor clockwise
void rotateClockwise(long steps) {
  digitalWrite(dirPin, HIGH); // Set the direction to clockwise
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000); // Adjust speed of rotation here
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000); // Adjust speed of rotation here
  }
}

// Function to rotate motor counterclockwise
void rotateCounterclockwise(long steps) {
  digitalWrite(dirPin, LOW); // Set the direction to counterclockwise
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000); // Adjust speed of rotation here
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000); // Adjust speed of rotation here
  }
}
