#include <SoftwareSerial.h>
#include <Ultrasonic.h>


int MOTOR2_PIN1 = 3;
int MOTOR2_PIN2 = 5;
int MOTOR1_PIN1 = 6;
int MOTOR1_PIN2 = 9;

Ultrasonic ultrasonic(7, 8);
int distanceFront = ultrasonic.distanceRead();

int methanePin = A0;
int carbonPin = A1;

char data;

void setup() {
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
   while(Serial.available()>0)
  {
    data=Serial.read();
    Serial.write(data);
    if(data == 'W' || data == 'w') 
    { 
        go(150,150);
    }
    if (data == 'D' || data == 'd')
    {
        go(-150,150);
    }
  
    if(data == 'A' || data == 'a')
    {
        go(150,-150);
    
    }
    if(data == 'S' || data == 's')
    {
        go(-150,-150);
    }
    if(data == 'X' || data == 'x')
     {
        go(0, 0);      
     }
    while(data == 'Q' || data == 'q')
    {
      while(distanceFront > 50 || distanceFront == 0)
      {
          go(150, 150);
          delay(1000);
          distanceFront = ultrasonic.distanceRead();
          Serial.print(distanceFront);
      }
      Serial.print(distanceFront);
      go(0, 0);
      delay(1000);
      go(-150,150);
      delay(1000);
      go(0, 0);
      delay(1000);
      go(150, 150);
      delay(1000);
      go(150, -150);
      delay(1000);
      go(0, 0);
      distanceFront = ultrasonic.distanceRead();
    }
    if(data == 'M' || data == 'm')
     {
       Serial.print("Metan:");
       Serial.print(analogRead(methanePin));
       Serial.println(" mg/L");
     }
    if(data == 'C' || data == 'c')
     {
       Serial.print("Monoxid de carbon:");
       Serial.print(analogRead(carbonPin));
       Serial.println(" mg/L");
     }
  }
 
}

void go(int speedLeft, int speedRight)
{
  if (speedLeft > 0) 
  {
    analogWrite(MOTOR1_PIN1, speedLeft);
    analogWrite(MOTOR1_PIN2, 0);
  } 
  else 
  {
    analogWrite(MOTOR1_PIN1, 0);
    analogWrite(MOTOR1_PIN2, -speedLeft);
  }
 
  if (speedRight > 0) 
  {
    analogWrite(MOTOR2_PIN1, speedRight);
    analogWrite(MOTOR2_PIN2, 0);
  }
  else 
  {
    analogWrite(MOTOR2_PIN1, 0);
    analogWrite(MOTOR2_PIN2, -speedRight);
  }
}

