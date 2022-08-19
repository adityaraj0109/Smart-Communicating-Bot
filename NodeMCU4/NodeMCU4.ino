#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <SoftwareSerial.h>

WiFiClient client;

#define echoPin D5 
#define trigPin D6 

long duration; 
int distance;
int value;

long myChannelNumber = 1561903;
const char myWriteAPIKey[] = "W4M2DQOASRYV44K9";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  WiFi.begin("realme 7", "adityariya201");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration * 0.034 / 2;
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
  if(Serial.available()>0)
  {
    value=Serial.read();
    ThingSpeak.writeField(myChannelNumber, 2, value, myWriteAPIKey);
    Serial.println(value);
  }
  ThingSpeak.writeField(myChannelNumber, 1, percent, myWriteAPIKey);
//  ThingSpeak.writeField(myChannelNumber, 2, value, myWriteAPIKey);
  delay(1000);
}
