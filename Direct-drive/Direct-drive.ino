// ARDUINO MICRO

#define   inblue    A0   
#define   inRed     A1  
#define   enPin     5   // the number of the En pin
#define   stpPin    6   // the number of the Stp pin
#define   dirPin    7   // the number of the Dir pin

#define blue_min 760
#define blue_max 95
 
/**************************************************************
***  connect:
      D5---En (Select L or Hold for the En option on the screen of the closed-loop driver board)
      D6---Stp
      D7---Dir
      V+,Gnd----10~28
      gnd---gnd

*** Precautions:
      Connect the wire first, then power on, do not unplug or plug when the power is on! ! !
      When powering on, first connect 10~28V power supply,
      and then connect the Arduino control board USB power supply! ! !
      Avoid damage caused by some effects.
      When the power is off, first cut off the USB power supply of the Arduino control board,
      and then cut off the 10~28V power supply.
***************************************************************/

long i = 0, j = 0;  bool cntDir = false;

void setup() {
  // put your setup code here, to run once:


  pinMode(enPin , OUTPUT);  digitalWrite(enPin , LOW);  // initialize the En pin as an output
  pinMode(stpPin, OUTPUT);  digitalWrite(stpPin, LOW);  // initialize the Stp pin as an output
  pinMode(dirPin, OUTPUT);  digitalWrite(dirPin, LOW);  // initialize the Dir pin as an output

  //pinMode(redPin, INPUT);
  pinMode(A0, INPUT);
}

void loop() {
 //driveStepper();
 readInputPins();
}

void driveStepper()
{
 // put your main code here, to run repeatedly:

  /**********************************************************
  ***  The time interval between high and low levels, that is,
  ***  half of the pulse time (control the rotation speed of the motor)
  **********************************************************/
  delayMicroseconds(600); //600us

  /**********************************************************
  ***  Invert D6 (Stp pin)
  **********************************************************/
  digitalWrite(stpPin, !digitalRead(stpPin));

  /**********************************************************
  ***  Record the number of IO inversions (IO inversion times = 2 times the number of pulses)
  **********************************************************/
  if (cntDir)  {
    --i;
  }  else  {
    ++i;
  }

  /**********************************************************
  ***  PA6 (Stp pin) is inverted 6400 times, that is, 3200 pulses are sent
  ***  Under 16 subdivision, send 3200 pulses, the motor rotates one circle (1.8 degree motor)
  **********************************************************/
  if (i >= 6400)
  {
    digitalWrite(dirPin, HIGH);  cntDir = true;   delay(1000);  //Switch direction rotation
  }
  else if (i == 0)
  {
    digitalWrite(dirPin, LOW);  cntDir = false;   delay(1000);  //Switch direction rotation
  }
}

unsigned long duration1, duration2;
void readInputPins()
{

//  Serial.print("Red: "); Serial.print(pulseIn(redPin, HIGH));
//  Serial.print(" Blue: "); Serial.print(pulseIn(bluePin, HIGH));
//  Serial.println();
//  delay(100);

  //Serial.print("A0: "); Serial.print(analogRead(A0));
  int analogRaw = analogRead(A0);
  int blue_mapped = constrain(map(analogRaw, blue_min, blue_max, 0, 255), 0, 255);
   Serial.print("raw: "); Serial.print(analogRaw);
   Serial.print(" blue_mapped: "); Serial.print(blue_mapped);
 // Serial.print(" Blue: "); Serial.print(analogRead(bluePin));
  Serial.println();
  delay(10);
}
