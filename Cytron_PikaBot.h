#ifndef CYTRON_PIKABOT_H
#define CYTRON_PIKABOT_H

#include <Arduino.h>
#include <stdint.h>

struct Motor
{
  uint8_t pin1;
  uint8_t pin2;
};

class Base
{
  public:
    Base(uint8_t left1, uint8_t left2, uint8_t right1, uint8_t right2);
    void powerBase(int leftSpeed, int rightSpeed);
    void moveForward(int speed);
    void moveBackward(int speed);
    void turnLeft(int speed);
    void turnRight(int speed);
    void stop();
    
  protected:
    void move(Motor motor, int speed);
    Motor left;
    Motor right;
};

class Ultrasonic
{
  public:
    Ultrasonic(uint8_t echoPin, uint8_t triggerPin);
    double getDistance();
    
  protected:
    uint8_t  echoPin;
    uint8_t  triggerPin;
};

class IRLine
{
  public:
    IRLine(uint8_t pin);
    bool onLine();
    
  protected:
    uint8_t pin;
};

class Button
{
  public:
    Button(uint8_t pin);
    bool isPressed();
    
  protected:
    uint8_t pin;
};

#endif
