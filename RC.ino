#include <Servo.h>

#define THROTTLE_SIGNAL_IN_PIN 2 
#define RIGHT_LEFT_STICK_SIGNAL_IN_PIN 3 

#define NEUTRAL_STICK 1500 // this is the duration in microseconds of neutral throttle on an electric RC Car

Servo Movement;

const int TRIM = 0;
const int PIN_Movement = 5;
const int speed = 200;

enum moveDirection {
   forward,
   backward
};

//Driver
const int pinPWMA = 6;
const int pinAIN2 = 7;
const int pinAIN1 = 8;

const int pinMotor[3] = { pinPWMA, pinAIN2, pinAIN1 };



void setup()
{

  Movement.attach(PIN_Movement);  // Attach the servo to digital pin PWM
  Serial.begin(9600); 
}

void loop()
{

}


//Control of the Throttle
void move(int direction, int speed)
{
   if (direction == forward)
   {
      moveMotorForward(pinMotorA, speed);
      moveMotorForward(pinMotorB, speed);
   }
   else
   {
      moveMotorBackward(pinMotorA, speed);
      moveMotorBackward(pinMotorB, speed);
   }
}

//Control of the motor
void moveMotorForward(const int pinMotor[3], int speed)
{
   digitalWrite(pinMotor[1], HIGH);
   digitalWrite(pinMotor[2], LOW);
 
   analogWrite(pinMotor[0], speed);
}
 
void moveMotorBackward(const int pinMotor[3], int speed)
{
   digitalWrite(pinMotor[1], LOW);
   digitalWrite(pinMotor[2], HIGH);
 
   analogWrite(pinMotor[0], speed);
}
