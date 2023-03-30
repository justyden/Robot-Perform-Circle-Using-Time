/* A program to have the car do a perfect circle.
Angle and speed can be adjusted to change how big in can be. */

#define speedPinR 9    //  RIGHT PWM pin connect MODEL-X ENA
#define RightMotorDirPin1  12    //Right Motor direction pin 1 to MODEL-X IN1 
#define RightMotorDirPin2  11    //Right Motor direction pin 2 to MODEL-X IN2
#define speedPinL 6    // Left PWM pin connect MODEL-X ENB
#define LeftMotorDirPin1  7    //Left Motor direction pin 1 to MODEL-X IN3 
#define LeftMotorDirPin2  8   //Left Motor direction pin 1 to MODEL-X IN4 


/*motor control*/
void go_Advance(void)  //Forward
{
  digitalWrite(RightMotorDirPin1, HIGH);
  digitalWrite(RightMotorDirPin2,LOW);
  digitalWrite(LeftMotorDirPin1,HIGH);
  digitalWrite(LeftMotorDirPin2,LOW);
  analogWrite(speedPinL,200);
  analogWrite(speedPinR,200);
}

void go_Circle(int t=0) //Has the correct angle and speed to do a circle.
{
  digitalWrite(RightMotorDirPin1, HIGH);
  digitalWrite(RightMotorDirPin2,LOW);
  digitalWrite(LeftMotorDirPin1,HIGH);
  digitalWrite(LeftMotorDirPin2,LOW);
  analogWrite(speedPinL,200);
  analogWrite(speedPinR,71);
}

void stop_Stop()    //Stop
{
  digitalWrite(RightMotorDirPin1, LOW);
  digitalWrite(RightMotorDirPin2,LOW);
  digitalWrite(LeftMotorDirPin1,LOW);
  digitalWrite(LeftMotorDirPin2,LOW);
}
/*set motor speed */
void set_Motorspeed(int speed_L,int speed_R)
{
  analogWrite(speedPinL,speed_L); 
  analogWrite(speedPinR,speed_R);   
}

//Pins initialize
void init_GPIO()
{
	pinMode(RightMotorDirPin1, OUTPUT); 
	pinMode(RightMotorDirPin2, OUTPUT); 
	pinMode(speedPinL, OUTPUT);  
 
	pinMode(LeftMotorDirPin1, OUTPUT);
  pinMode(LeftMotorDirPin2, OUTPUT); 
  pinMode(speedPinR, OUTPUT); 
	stop_Stop();
}

void setup()
{
	init_GPIO();

  go_Advance(); // Needs to move slightly forward to get the wheels in sync from the start.
  delay(100);

  go_Circle(); // Performs the circle.
  delay(8950);
  
  stop_Stop();//Stop

}

void loop(){
}
