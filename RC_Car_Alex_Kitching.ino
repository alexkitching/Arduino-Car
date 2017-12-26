// Motor Driver
// Motor One (Left)
const int c_iM1P = 10; // Motor Power Input
const int c_iM1F = 9; // Motor Forward Input
const int c_iM1R = 8; // Motor Reverse Input
// Motor Two
const int c_iM2P = 5; // Motor Power Input
const int c_iM2F = 7; // Motor Forward Input
const int c_iM2R = 6; // Motor Reverse Input
//Timer
unsigned long ulPreviousMillis = 0;
const long c_lInterval = 100;
//LED
const int c_iActiveLEDPin = 12;
int iActiveLEDState = LOW;
//Buzzer
const int c_iBuzPin = 13;
int iBuzState = LOW;
// Bluetooth Input
const int c_iBInput= 0; //Set Bluetooth Input Pin
int iBState; //Create Current State Variable

void setup() // Pre Setup
{
  // Set all the motor  pins to outputs
  pinMode(c_iM1P, OUTPUT);
  pinMode(c_iM2P, OUTPUT);
  pinMode(c_iM1F, OUTPUT);
  pinMode(c_iM1R, OUTPUT);
  pinMode(c_iM2F, OUTPUT);
  pinMode(c_iM2R, OUTPUT);
  pinMode(c_iActiveLEDPin, OUTPUT);
  pinMode(c_iBuzPin, OUTPUT);
  pinMode(c_iBInput, INPUT);
  //Setup Serial for Bluetooth
  Serial.begin(9600);
}

void loop() // Main Program
{
  if(digitalRead(c_iBInput)==LOW) 
  {
    iBState='S'; 
  }
  if(Serial.available() > 0)
  {
    iBState = Serial.read();
  }
    //Forward
    if (iBState == 'F' )
    {
      //Motor 1 (Left) - Forward
      digitalWrite(c_iM1F, HIGH);
      digitalWrite(c_iM1R, LOW);
      analogWrite(c_iM1P, 190);
      //Motor 2 (Right) - Forward
      digitalWrite(c_iM2F, HIGH);
      digitalWrite(c_iM2R, LOW);
      analogWrite(c_iM2P, 190);
      //LED
      if (millis() - ulPreviousMillis > c_lInterval) //Timer which bleeps LED
      {
         ulPreviousMillis = millis();
         if (iActiveLEDState == LOW)
         {
           iActiveLEDState = HIGH; 
           digitalWrite(c_iActiveLEDPin, iActiveLEDState);
         }
         else if (iActiveLEDState == HIGH)
         {
           iActiveLEDState = LOW; 
           digitalWrite(c_iActiveLEDPin, iActiveLEDState);
         }
      }
    }
    //Reverse
    else if (iBState == 'B')
    {
      //Motor 1 (Left) - Reverse
      digitalWrite(c_iM1F, LOW);
      digitalWrite(c_iM1R, HIGH);
      analogWrite(c_iM1P, 190);
      //Motor 2 (Right) - Reverse
      digitalWrite(c_iM2F, LOW);
      digitalWrite(c_iM2R, HIGH);
      analogWrite(c_iM2P, 190); 
      //LED - Blink
      if (millis() - ulPreviousMillis > c_lInterval) //Timer which bleeps LED
      {
         ulPreviousMillis = millis();
         if (iActiveLEDState == LOW)
         {
           iActiveLEDState = HIGH; 
           digitalWrite(c_iActiveLEDPin, iActiveLEDState);
         }
         else if (iActiveLEDState == HIGH)
         {
           iActiveLEDState = LOW; 
           digitalWrite(c_iActiveLEDPin, iActiveLEDState);
         }
      }
    }
    //Left
    else if (iBState == 'L')
    {
      //Motor 1 (Left) - Reverse
      digitalWrite(c_iM1F, LOW);
      digitalWrite(c_iM1R, HIGH);
      analogWrite(c_iM1P, 140);
      //Motor 2 (Right) - Forward
      digitalWrite(c_iM2F, HIGH);
      digitalWrite(c_iM2R, LOW);
      analogWrite(c_iM2P, 140);
      //LED - Blink
      if (millis() - ulPreviousMillis > c_lInterval) //Timer which bleeps LED
      {
         ulPreviousMillis = millis();
         if (iActiveLEDState == LOW)
         {
           iActiveLEDState = HIGH; 
           digitalWrite(c_iActiveLEDPin, iActiveLEDState);
         }
         else if (iActiveLEDState == HIGH)
         {
           iActiveLEDState = LOW; 
           digitalWrite(c_iActiveLEDPin, iActiveLEDState);
         }
      }
    }
    //Right
    else if (iBState == 'R')
    {
      //Motor 1 (Left) - Forward
      digitalWrite(c_iM1F, HIGH);
      digitalWrite(c_iM1R, LOW);
      analogWrite(c_iM1P, 140);
      //Motor 2 (Right) - Reverse
      digitalWrite(c_iM2F, LOW);
      digitalWrite(c_iM2R, HIGH);
      analogWrite(c_iM2P, 140);  
      //LED - Blink
      if (millis() - ulPreviousMillis > c_lInterval) //Timer which bleeps LED
      {
         ulPreviousMillis = millis();
         if (iActiveLEDState == LOW)
         {
           iActiveLEDState = HIGH; 
           digitalWrite(c_iActiveLEDPin, iActiveLEDState);
         }
         else if (iActiveLEDState == HIGH)
         {
           iActiveLEDState = LOW; 
           digitalWrite(c_iActiveLEDPin, iActiveLEDState);
         }
      }
    }
    else if (iBState == 'v')
    {
      noTone(c_iBuzPin); //Stop Current Sound
    }
    else if (iBState == 'V')
    {
      tone(c_iBuzPin, 1000); //Emit Sound
    }
    else if (iBState == 'S') //If Car is not Moving
    {
      //Motor 1 (Left) - Stop
      digitalWrite(c_iM1F, LOW);
      digitalWrite(c_iM1R, LOW);
      analogWrite(c_iM1P, 0);
      //Motor 2 (Right) - Stop
      digitalWrite(c_iM2F, LOW);
      digitalWrite(c_iM2R, LOW);
      analogWrite(c_iM2P, 0);
      //LED - Off
      digitalWrite(c_iActiveLEDPin, LOW);
    }
}

