// AccelStepper to control stepper motors
#include <AccelStepper.h>

#include <Wire.h>

////////////////////// For stepper motors /////////////////////////
AccelStepper stepper0(AccelStepper::DRIVER, 2, 5); // pin 2 for step, pin 5 for direction
AccelStepper stepper1(AccelStepper::DRIVER, 3, 6);
AccelStepper stepper2(AccelStepper::DRIVER, 4, 7);

int speed0 = 0;
int speed1 = 0;
int speed2 = 0;


////////////////////// For serial communication ///////////////////
int twobytes1int(byte high, byte low)
{
  int number;

  number = low | (high << 8);
  return number;
}


////////////////// Setup and Loop ///////////////////////////

void setup()
{  
  Serial.begin(9600);
  Wire.begin(97);  
  Wire.onReceive(receiveEvent);

  // for stepper motor control
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
   
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
   
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);

  stepper0.setMaxSpeed(2000);
  stepper1.setMaxSpeed(2000);
  stepper2.setMaxSpeed(2000);

  stepper0.setSpeed(0);
  stepper1.setSpeed(0);
  stepper2.setSpeed(0);

}

void loop()
{
	stepper0.runSpeed();
	stepper1.runSpeed();
	stepper2.runSpeed();
}

void receiveEvent(int numBytes) {
  byte buf[9];
  int i = 0;

  int speed0 = 0, speed1 = 0, speed2 = 0;

  while (0 < Wire.available()) 
  {
    buf[i] = Wire.read();
    i++;
  }

  speed0 = twobytes1int(buf[0], buf[1])*(buf[2]-2);
  speed1 = twobytes1int(buf[3], buf[4])*(buf[5]-2);
  speed2 = twobytes1int(buf[6], buf[7])*(buf[8]-2);

  stepper0.setSpeed(speed0);
  stepper1.setSpeed(speed1);
  stepper2.setSpeed(speed2);

   Serial.println("Speed0, Speed1, Speed2: ");
   Serial.print(speed0);
   Serial.print(", ");
   Serial.print(speed1);
   Serial.print(", ");
   Serial.println(speed2);
   Serial.println();
}
