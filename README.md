# Arduino Library for Cytron PikaBot

This library provides functions for Cytron Pika Bot.

## Installation

### Download from  Arduino Library Manager  (Recommended)

In Arduino IDE, go to **Tools > Manage Libraries...** and search for "**Cytron_PikaBot**". Click "**Install**" and then "**Close**" after it is done.

### Manual download

Download the ZIP file [here](https://github.com/beanbeah/CytronPikaBot/archive/refs/heads/master.zip). Unzip it and place it under **Documents\Arduino\libraries** (The folder should be named as "**CytronPikaBot**").

You are ready to go!

## Documentation

### Base 
The PikaBot Base can be initialised by decalring a new instance of the Base Object.
```
Base PikaBot(leftPin1,leftPin2,rightPin1,rightPin2)
```

After declaring a new instance of the Base Object, the following functions can be used to control the PikaBot Base.

`powerBase(leftSpeed, rightSpeed)`:
powerBase can be used to set the speed of the base. Speed can be any value from -255 to 255. 

`moveForward(speed)`:
moves the PikaBot Base Forward at defined speed. Speed can be from 0 to 255.

`moveBackward(speed)`:
moves the PikaBot Base Backwards at defined speed. Speed can be from 0 to 255.

`turnLeft(speed)`:
turns the PikaBot Base Left at defined speed. Speed can be from 0 to 255.

`turnRight(speed)`:
turns the PikaBot Base Right at defiend speed. Speed can be from 0 to 255

### Ultrasonic
The Ultrasonic Sensor can be initialised by declaring a new instance of the Ultrasonic Object.
```
Ultrasnic ultrasonic(echoPin,triggerPin)
```

`double getDistance()`:
returns the distance of an object detected by the Ultrasonic Range Sensor. Note, distance is a **double**

### IR Sensor
The IR sensor can be initialised by declaring a new instance of the IRLine Object
```
IRLine ir(analogPin)
```

`bool onLine()`:
Returns if the IR Sensor detects a Line. Return is **either True or False**.

### Misc
The pullup button can be initialised by declaring a new instance of the Button Object

```
Button redButton(pin)
```

`bool isPressed()`:
Returns if the button has been pressed. Return is **either True or False**.

