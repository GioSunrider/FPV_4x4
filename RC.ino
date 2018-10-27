#include <Servo.h>

//Servo which controls the right-left direction
Servo Direction;
const int TRIM = 0;

//Set the digital PIN of the Arduino
const byte  YAW_IN_PIN = 5;
const byte YAW_OUT_PIN = 10; //Pin DIRECTION
unsigned long YAW_DURATION;

const byte THROTTLE_IN_PIN = 6;
const byte THROTTLE_OUT_PIN = 9; //THROTTLE
unsigned long THROTTLE_DURATION;

const byte START_STOP_IN_PIN = 3; //SWITCH
const byte START_STOP_OUT_PIN = 4; //STBY DRIVER
unsigned long STOP_DURATION;

//Driver Pin
const int pinAIN2 = 7;
const int pinAIN1 = 8;

//Speed of the DC motor which is control by the throttle
const int speed = 250;

enum moveDirection {
   forward,
   backward
};

const int pinMotor[3] = { THROTTLE_OUT_PIN, pinAIN2, pinAIN1 };

void setup()
{
  //Set the Pin of the FS Receiver
  //Direction
  pinMode(YAW_IN_PIN, INPUT);
  pinMode(YAW_OUT_PIN, OUTPUT);
  //Throtle
  pinMode(THROTTLE_IN_PIN, INPUT);
  pinMode(THROTTLE_OUT_PIN, OUTPUT);
  pinMode(pinAIN2, OUTPUT);
  pinMode(pinAIN1, OUTPUT);
  //Star-Stop
  pinMode(START_STOP_IN_PIN, INPUT);
  pinMode(START_STOP_OUT_PIN, OUTPUT);
  
  // Attach the servo to digital pin PWM
  Direction.attach(YAW_OUT_PIN);  


  //Set the Baudrate
  Serial.begin(9600); 
}

void loop()
{
  //STAR-STOP
  STOP_DURATION = pulseIn(START_STOP_IN_PIN, HIGH);
  STOP_DURATION = map(STOP_DURATION, 1000, 1500, 0, 1);
  digitalWrite( START_STOP_OUT_PIN, HIGH);
  delayMicroseconds(STOP_DURATION);
  digitalWrite( START_STOP_OUT_PIN, LOW);
  
  //LEFT
  YAW_DURATION = pulseIn(YAW_IN_PIN, HIGH);
  YAW_DURATION = map(YAW_DURATION, 1450, 1000, 980, 2020);
  digitalWrite(YAW_OUT_PIN, HIGH);
  Direction.write(30);
  delayMicroseconds(YAW_DURATION);
  digitalWrite(YAW_OUT_PIN, LOW); 

  //RIGHT
  YAW_DURATION = pulseIn(YAW_IN_PIN, HIGH);
  YAW_DURATION = map(YAW_DURATION, 1550, 2000, 980, 2020);
  digitalWrite(YAW_OUT_PIN, HIGH);
  Direction.write(-30);
  delayMicroseconds(YAW_DURATION);
  digitalWrite(YAW_OUT_PIN, LOW);

  //FORWARD
  THROTTLE_DURATION = pulseIn(THROTTLE_IN_PIN, HIGH);
  THROTTLE_DURATION = map(THROTTLE_DURATION, 1550, 2000, 980, 2020);
  digitalWrite(THROTTLE_OUT_PIN, HIGH);
  move(forward, speed);
  delayMicroseconds(THROTTLE_DURATION);
  digitalWrite(THROTTLE_OUT_PIN, LOW); 

  //BACKWARD
  THROTTLE_DURATION = pulseIn(THROTTLE_IN_PIN, HIGH);
  THROTTLE_DURATION = map(THROTTLE_DURATION, 1450, 1000, 980, 2020);
  digitalWrite(THROTTLE_OUT_PIN, HIGH);
  move(backward, speed);
  delayMicroseconds(THROTTLE_DURATION);
  digitalWrite(THROTTLE_OUT_PIN, LOW); 
}


//Control of the Throttle
void move(int direction, int speed)
{
   if (direction == forward)
   {
      moveMotorForward(pinMotor, speed);
   }
   else
   {
      moveMotorBackward(pinMotor, speed);
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
