#include "motor.cpp"

class Car
{

private:
    Motor motor1 = Motor(27, 26, 14, 0);
    Motor motor2 = Motor(25, 33, 13, 2);
    Motor motor3 = Motor(19, 18, 5, 4);
    Motor motor4 = Motor(16, 17, 4, 6);

public:
    void initalize()
    {
        this->motor1.initialize();
        this->motor2.initialize();
        this->motor3.initialize();
        this->motor4.initialize();
    }

    void moveForward()
    {
        motor1.moveForward();
        motor2.moveForward();
        motor3.moveForward();
        motor4.moveForward();
    }

    void moveBackward()
    {
        motor1.moveBackward();
        motor2.moveBackward();
        motor3.moveBackward();
        motor4.moveBackward();
    }

    void increaseSpeed(int delta)
    {
        motor1.increaseSpeed(delta);
        motor2.increaseSpeed(delta);
        motor3.increaseSpeed(delta);
        motor4.increaseSpeed(delta);
    }

    void setToMinSpeed()
    {
        motor1.setToMinSpeed();
        motor2.setToMinSpeed();
        motor3.setToMinSpeed();
        motor4.setToMinSpeed();
    }

    void setToMaxSpeed()
    {
        motor1.setToMaxSpeed();
        motor2.setToMaxSpeed();
        motor3.setToMaxSpeed();
        motor4.setToMaxSpeed();
    }

    void stop()
    {
        motor1.stop();
        motor2.stop();
        motor3.stop();
        motor4.stop();
    }

    void turnLeft()
    {
        motor1.moveBackward();
        motor3.moveBackward();
        motor2.moveForward();
        motor4.moveForward();
    }

    void turnRight()
    {
        motor1.moveForward();
        motor3.moveForward();
        motor2.moveBackward();
        motor4.moveBackward();
    }

    int currentSpeed()
    {
        return motor1.currentSpeed();
    }
};
