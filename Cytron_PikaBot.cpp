#include "Cytron_PikaBot.h"

Base::Base(uint8_t left1, uint8_t left2, uint8_t right1, uint8_t right2)
{
  this->left.pin1 = left1;
  this->left.pin2 = left2;
  this->right.pin1 = right1;
  this->right.pin2 = right2;
  
  pinMode(this->left.pin1, OUTPUT);
  pinMode(this->left.pin2, OUTPUT);
  pinMode(this->right.pin1, OUTPUT);
  pinMode(this->right.pin2, OUTPUT);
  digitalWrite(this->left.pin1, LOW);
  digitalWrite(this->left.pin2, LOW);
  digitalWrite(this->right.pin1, LOW);
  digitalWrite(this->right.pin2, LOW);
}

void Base::move(Motor motor, int speed)
{
  if (speed > 255) speed = 255;
  else if (speed < -255) speed = -255;
  
  if (speed >= 0) {
    analogWrite(motor.pin1, speed);
    analogWrite(motor.pin2, 0);
  } else {
    analogWrite(motor.pin1, 0);
    analogWrite(motor.pin2, -speed);
  } 
};

void Base::powerBase(int leftSpeed, int rightSpeed)
{
  move(this->left, leftSpeed);
  move(this->right, rightSpeed);
};

void Base::moveForward(int speed)
{
  this->powerBase(speed, speed);
};

void Base::moveBackward(int speed)
{
  this->powerBase(-speed, -speed);
};

void Base::turnLeft(int speed)
{
  this->powerBase(-speed, speed);
};

void Base::turnRight(int speed)
{
  this->powerBase(speed, -speed);
};

void Base::stop()
{
  this->powerBase(0, 0);
};

Ultrasonic::Ultrasonic(uint8_t echoPin, uint8_t triggerPin)
{
  this->echoPin = echoPin;
  this->triggerPin = triggerPin;
  pinMode(this->echoPin, INPUT);
  pinMode(this->triggerPin, OUTPUT);
}

double Ultrasonic::getDistance()
{
  digitalWrite(this->triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(this->triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(this->triggerPin, LOW);
  noInterrupts();
  double d = pulseIn(this->echoPin,HIGH,23529.4);
  interrupts();
  return d/58.8235;
};

IRLine::IRLine(uint8_t pin)
{
  this->pin = pin;
  pinMode(this->pin, INPUT);
}

bool IRLine::onLine()
{
  return digitalRead(this->pin) == HIGH;
};

Button::Button(uint8_t pin)
{
  this->pin = pin;
  pinMode(this->pin, INPUT_PULLUP);
}

bool Button::isPressed()
{
  return digitalRead(this->pin) == LOW;
};


