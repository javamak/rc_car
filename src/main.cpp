#include <Arduino.h>
#include "car.cpp"
#include <DabbleESP32.h>

Car car;

void setup()
{

  // sets the pins as outputs:
  Dabble.begin("My BlE");
  car.initalize();
  car.setToMaxSpeed();
  Serial.begin(921600);
}

void loop()
{

  Dabble.processInput(); // this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.

  if (GamePad.isUpPressed())
  {
    Serial.print("Up");
    car.moveForward();
  }

  if (GamePad.isDownPressed())
  {
    Serial.print("Down");
    car.moveBackward();
  }

  if (GamePad.isLeftPressed())
  {
    Serial.print("Left");
    car.turnLeft();
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("Right");
    car.turnRight();
  }

  car.stop();
}