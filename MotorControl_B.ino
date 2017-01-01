/****************************************************************
* Ar2D2 : An Android remote controlled Arduino Car
* By Oliver H and Brook H
* Our CS 362 Project
*
* Description:
* -----------
* The following arduino code controls the direction and the speed
* of the motors based on the signal that from another arduino.
* It controls the robot in 5 basic ways; moving forward , backward,
* turning left, right and stopping. It has four functions to
* to accomplish that and will be constantly checking for incoming signals.
* for more explanation how the code works please refer to the project report.
*
* Code written by Brook H
*/
/****************************************************************/

/****************************************************************/
// GENERAL MOTOR CONTROLS
/****************************************************************/

// Motor Channels (Direction) A and B (right and left morots)
int DA = 12;  // reverse or forward direction for motor A
int DB = 13; //  reverse or forward direction for motor B

// Motor Break control
int BA = 9;
int BB = 8; //Latest version use pin 4 instead of pin 8

// Motor speed control for the right and Left Motor
int MA = 3;   // spins the right motor
int MB = 11;  // spins the left motoslowing left or right motor and increasing the speed of the otehr motorr

//****************************************************************/

/****************************************************************/
// GENERAL CAR CONTROLS
/****************************************************************/

// Motor Channels (Direction) A and B (right and left morots)
int moveForwardAr2D2 = 4;  // input singnal to move car forward
int moveBackwardAr2D2 = 5;// input singnalto move car backwards
int turnRightAr2D2 = 6;   // input signal to move car right
int turnLeftAr2D2 = 7;  // input signal to move car left
int stopAr2D2 = 10; //  input singal to stop car

//****************************************************************/

/****************************************************************/
// MOVING MOTOR A
/****************************************************************/
void MotorA(int pwm, boolean forward)
{
 // check the direction
  if(forward)
 {
  digitalWrite(DA,HIGH);
 }
else
{
  digitalWrite(DA,LOW);
 }

 analogWrite(MA,pwm); //set pwm control, 0 for stop, and 255 for maximum speed

}

/****************************************************************/
// MOVING MOTOR B
/****************************************************************/

void MotorB(int pwm, boolean forward)
{
 if(forward)
 {
  digitalWrite(DB,HIGH);
 }
else
{
  digitalWrite(DB,LOW);
 }
  analogWrite(MB,pwm);
}

void turnRight ()
{
  MotorA(255,false);
  MotorB(255,true);

}
void turnLeft()
{
  MotorA(255,true);
  MotorB(255,false);
}
// move the motor forward
void moveForward(int pwm)
{
  MotorA(pwm,true);
  MotorB(pwm,true);
}

// move the motor backwards
void moveBackward(int pwm)
{
  MotorA(pwm,false);
  MotorB(pwm,false);
}

void setup()
{

   //Setup Channel A
  pinMode(DA, OUTPUT); //Initiates Motor Channel A pin
  pinMode(BA, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(DB, OUTPUT); //Initiates Motor Channel A pin
  pinMode(BB, OUTPUT);  //Initiates Brake Channel A pin

  // Setup Car controls (Initiate as an input pin)
  pinMode(moveForwardAr2D2, INPUT);
  pinMode(moveBackwardAr2D2, INPUT);
  pinMode(turnRightAr2D2, INPUT);
  pinMode(turnLeftAr2D2, INPUT);
  pinMode(stopAr2D2, INPUT);

  Serial.begin(9600);
}


void loop()
{


    if(digitalRead(moveForwardAr2D2)==HIGH)
              moveForward(200);
    else if(digitalRead(moveBackwardAr2D2)== HIGH)
              moveBackward(200);
    else if(digitalRead(turnRightAr2D2)== HIGH)
              turnRight();
    else if(digitalRead(turnLeftAr2D2)== HIGH)
              turnLeft();
    else if(digitalRead(stopAr2D2)== HIGH)
     {
        MotorA(0,false);
        MotorB(0,false);
     }
    else{
      ;
    }

}
