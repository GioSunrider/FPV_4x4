#include <Servo.h>


//Servo
Servo DirectionL;
Servo DirectionR;
const int SERVO_OUTL = 3;
const int SERVO_OUTR = 5;

const int L_SERVO = 90;
const int R_SERVO = 89;

//FS PIN Ports PWM
const int RC_CHANNEL2 = 10;//Ahead and back pin
const int RC_CHANNEL1 = 9;//Left and Right pin
const int SWA = 11;//Disable pin

void setup() {
  pinMode(RC_CHANNEL2, INPUT);
  pinMode(RC_CHANNEL1, INPUT);
  pinMode(SWA, INPUT);
  DirectionL.attach(SERVO_OUTL);
  DirectionR.attach(SERVO_OUTR);
  Serial.begin(9600);
}

void loop() {
  
  int pwmR = 0;
  int pwmL = 0;
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
      DirectionR.write(R_SERVO);
      DirectionL.write(L_SERVO);
    }
    else if(rc2 > 1500) 
    {
      pwmR = map(rc2, 1500, 1988, R_SERVO, R_SERVO);
      pwmL = map(rc2, 1500, 1988, L_SERVO, L_SERVO);
      DirectionR.write(90-pwmR);
      DirectionL.write(90+pwmL);
      Serial.print(" ahead stick speed: ");
      Serial.println(pwmL);
    }
    else if(rc2 < 1450)
    {
      pwmR = map(rc2, 1480, 1000, R_SERVO, R_SERVO);
      pwmL = map(rc2, 1480, 1000, L_SERVO, L_SERVO);
      DirectionR.write(90+pwmR);
      DirectionL.write(90-pwmL);
      Serial.print(" back stick speed: ");
      Serial.println(pwmR);
    }
    else if(rc1 > 1500) //right stick
    {
      pwmR = map(rc1, 1500, 1988, R_SERVO, R_SERVO);
      pwmL = map(rc1, 1500, 1988, L_SERVO, L_SERVO);
      DirectionR.write(90+pwmR);
      DirectionL.write(90+pwmL);
      Serial.print(" right stick speed: ");
      Serial.println(pwmR);
    }
    else if(rc1 < 1450)
    {
      pwmR = map(rc1, 1480, 1000, R_SERVO, R_SERVO);
      pwmL = map(rc1, 1480, 1000, L_SERVO, L_SERVO);
      DirectionR.write(90-pwmR);
      DirectionL.write(90-pwmL);
      Serial.print(" left stick speed: ");
      Serial.println(pwmL);
    }
    else
    {
      Serial.println(" stick centered");
      DirectionR.write(R_SERVO);
      DirectionL.write(L_SERVO);
    }      
  }
  else
  {
      Serial.println("Interruptor desactivado.");
      DirectionR.write(R_SERVO);
      DirectionL.write(L_SERVO);
  }
  
}
