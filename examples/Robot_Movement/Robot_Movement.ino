#include <Cytron_PikaBot.h>

//Base takes in the following: Left Motor Pin 1, Left Motor Pin 2, Right Motor Pin 1, Right Motor Pin 2
//By Default:
//Left Motor Pin 1: 9
//Left Motor Pin 2: 3
//Right Motor Pin 1: 11
//Right Motor Pin 3: 10
Base base(9,3,11,10);


void setup() {
  //put your setup code here, to run once
}

void loop() {
  // put your main code here, to run

  //note, all motor speeds are from -255 to 255!

  //powerBase(leftSpeed, rightSpeed).
  //Sets PikaBot Speed
  base.powerBase(200,200);
  delay(10000);
  
  //moveForward(speed)
  //move PikaBot Forward by given speed
  base.moveForward(100);
  delay(10000);

  //moveBackward(speed)
  //move PikaBot Backward by given speed
  base.moveBackward(100);
  delay(10000);

  //turnLeft(speed)
  //turns PikaBot to the Left by given speed
  base.turnLeft(250);
  delay(10);

  //turnRight(speed)
  //turns PikaBot to the Right by given speed
  base.turnRight(250);
  delay(10000);

  //stop()
  //stops PikaBot
  base.stop();
  delay(10000);
}