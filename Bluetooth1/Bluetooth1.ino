#include <SoftwareSerial.h>
#define tx 2
#define rx 3
#define echoPin 4
#define trigPin 5 
SoftwareSerial bt(rx,tx);
                
void setup() 
{
  Serial.begin(9600);     
  bt.begin(9600);    
  pinMode(tx, OUTPUT);    
  pinMode(rx, INPUT);  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float duration = pulseIn(echoPin, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds
  float distance = duration * 0.034 / 2;
  int percent;
  if (distance>=0 && distance<2)
    {
        percent=100;
    }
  else if (distance>=2 && distance<=3)
    {
        percent=90;
    }
  else if (distance>=4 && distance<=5)
    {
        percent=80;
    }
  else if (distance>=6 && distance<=7)
    {
        percent=70;
    }
  else if (distance>=8 && distance<=9)
    {
        percent=60;
    }
  else if (distance>=10 && distance<=11)
    {
        percent=50;
    }
  else if (distance>=12 && distance<=13)
    {
        percent=40;
    }
  else if (distance>=14 && distance<=15)
    {
        percent=30;
    }
  else if (distance>=16 && distance<=17)
    {
        percent=20;
    }
  else if (distance>=18 && distance<=19)
    {
        percent=10;
    }
  else
    {
        percent=0;
    }
  Serial.print("Level Percentage: ");
  Serial.print(percent);
  Serial.println(" %");
  bt.write(percent);                      
} 
