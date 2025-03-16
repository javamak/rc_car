#include <Arduino.h>

class Motor
{

private:
    int pin1;
    int pin2;
    int enablePin;
    int speed;
    int pwmChannel;

    const int MIN_SPEED = 200;
    const int MAX_SPEED = 255;

public:
    Motor(int pin1, int pin2, int enablePin, int pwmChannel)
    {
        this->pin1 = pin1;
        this->pin2 = pin2;
        this->enablePin = enablePin;
        this->pwmChannel = pwmChannel;
        this->speed = MIN_SPEED;
    }

    void initialize()
    {
        pinMode(pin1, OUTPUT);
        pinMode(pin2, OUTPUT);
        pinMode(enablePin, OUTPUT);

        ledcSetup(pwmChannel, 30000, 8);
        // attach the channel to the GPIO to be controlled
        ledcAttachPin(enablePin, pwmChannel);
        ledcWrite(pwmChannel, MIN_SPEED);
    }

    void moveForward()
    {
        Serial.println("Moving Forward");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
    }

    void moveBackward()
    {
        Serial.println("Moving Backwards");
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
    }

    void stop()
    {
        Serial.println("Motor stopped");
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
    }

    void increaseSpeed(int delta)
    {
        int speed = this->speed + delta;
        if (speed >= MAX_SPEED)
        {
            speed = MAX_SPEED;
        }
        ledcWrite(pwmChannel, speed);
        this->speed = speed;
    }

    void setToMinSpeed()
    {
        ledcWrite(pwmChannel, MIN_SPEED);
        this->speed = MIN_SPEED;
    }

    void setToMaxSpeed()
    {
        ledcWrite(pwmChannel, MAX_SPEED);
        this->speed = MAX_SPEED;
    }

    int currentSpeed()
    {
        return this->speed;
    }
};