#include <Servo.h>

//Driver
const int AIN1 = 8;
const int AIN2 = 7;
const int PWMA = 9;

//Servo
Servo Direction;
const int SERVO_OUT = 10;

//FS PIN Ports PWM
const int RC_CHANNEL2 = 5;//Ahead and back pin
const int RC_CHANNEL1 = 6;//Left and Right pin
const int SWA = 3;//Disable pin

void setup() {
  pinMode(RC_CHANNEL2, INPUT);
  pinMode(RC_CHANNEL1, INPUT);
  pinMode(SWA, INPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  Direction.attach(SERVO_OUT);
  Serial.begin(9600);
}

void loop() {
  
  int pwm = 0;
  int swd = pulseIn(SWA, HIGH);
  int rc2 = pulseIn(RC_CHANNEL2, HIGH);
  int rc1 = pulseIn(RC_CHANNEL1, HIGH);
  
  if(swd>1000)//Interruptor activado
  {
    Serial.print("switch: ");
    Serial.print(swd);
    Serial.print(" RC_CHANNEL 2: ");
    Serial.print(rc2);
    Serial.print(" RC_CHANNEL 1: ");
    Serial.print(rc1);
    if(rc2==0||rc1==0)//ahead stick
    {
      Serial.println(" no signal");
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, LOW);
      analogWrite(PWMA, 0);
    }
    else if(rc2 > 1500) 
    {
      pwm = map(rc2, 1500, 1975, 0, 255);//speed 0-255 range 
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, HIGH);
      analogWrite(PWMA, pwm);
      Serial.print(" ahead stick speed: ");
      Serial.println(pwm);
    }
    else if(rc2 < 1450)
    {
      pwm = map(rc2, 1480, 989, 0, 255); //speed 0-255 range
      digitalWrite(AIN1, HIGH);
      digitalWrite(AIN2, LOW);
      analogWrite(PWMA, pwm);
      Serial.print(" back stick speed: ");
      Serial.println(pwm);
    }
     else if(rc1 > 1500) //right stick
    {
      pwm = map(rc1, 1500, 1975, 0, 255); //map our speed to 0-255 range
      Direction.write(90+pwm);
      Serial.print(" right stick speed: ");
      Serial.println(pwm);
    }
    else if(rc1 < 1450)
    {
      pwm = map(rc1, 1480, 989, 0, 255); //map our speed to 0-255 range
      Direction.write(90-pwm);
      Serial.print(" left stick speed: ");
      Serial.println(pwm);
    }
    else
    {
      Serial.println(" stick centered");
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, LOW);
      analogWrite(PWMA, 0);
    }      
  }
  else
  {
      Serial.println("Interruptor desactivado.");
  }
  
}
