#include <Cytron_PikaBot.h>

//Base takes in the following: Left Motor Pin 1, Left Motor Pin 2, Right Motor Pin 1, Right Motor Pin 2
//By Default:
//Left Motor Pin 1: 9
//Left Motor Pin 2: 3
//Right Motor Pin 1: 11
//Right Motor Pin 3: 10
Base base(9,3,11,10);

//IR Takes in the following: Analog_Pin
//By Default:
//Left IR: A0
//Right IR: A1
IRLine left(A0);
IRLine right(A1);

//Red Button on PikaBot, Default wired to Pin 2
Button redButton(2);

void setup() {
  //put your setup code here, to run once
}

void loop() {
  // put your main code here, to run
  if (redButton.isPressed()){
    while(true){
      if (!left.onLine() && !right.onLine()) {
        base.moveForward(200);
      }
      else if (left.onLine()) {
        base.turnLeft(200);
      }
      else if (right.onLine()) {
        base.turnRight(200);
      }
    }
  }
}