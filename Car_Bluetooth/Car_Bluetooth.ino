#include <AFMotor.h>

// Initialize motors on Adafruit Motor Shield
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

int command;
int speedValue = 255;

void setup() {
  Serial.begin(9600); // Match this baud rate with your Bluetooth module
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();

    Stop(); // Default state

    switch (command) {
      case 'F': forward(); break;
      case 'B': back(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      case 'I': topright(); break;
      case 'J': topleft(); break;
      case 'K': bottomright(); break;
      case 'M': bottomleft(); break;
      case 'T': Stop(); break;
    }
  }
}

void forward() {
  motor1.setSpeed(speedValue);
  motor2.setSpeed(speedValue);
  motor3.setSpeed(speedValue);
  motor4.setSpeed(speedValue);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void back() {
  motor1.setSpeed(speedValue);
  motor2.setSpeed(speedValue);
  motor3.setSpeed(speedValue);
  motor4.setSpeed(speedValue);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void left() {
  motor1.setSpeed(speedValue);
  motor2.setSpeed(speedValue);
  motor3.setSpeed(speedValue);
  motor4.setSpeed(speedValue);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void right() {
  motor1.setSpeed(speedValue);
  motor2.setSpeed(speedValue);
  motor3.setSpeed(speedValue);
  motor4.setSpeed(speedValue);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void topleft() {
  motor1.setSpeed(speedValue);
  motor2.setSpeed(speedValue);
  motor3.setSpeed(speedValue / 3);
  motor4.setSpeed(speedValue / 3);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void topright() {
  motor1.setSpeed(speedValue / 3);
  motor2.setSpeed(speedValue / 3);
  motor3.setSpeed(speedValue);
  motor4.setSpeed(speedValue);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void bottomleft() {
  motor1.setSpeed(speedValue);
  motor2.setSpeed(speedValue);
  motor3.setSpeed(speedValue / 3);
  motor4.setSpeed(speedValue / 3);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void bottomright() {
  motor1.setSpeed(speedValue / 3);
  motor2.setSpeed(speedValue / 3);
  motor3.setSpeed(speedValue);
  motor4.setSpeed(speedValue);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void Stop() {
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
