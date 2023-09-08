#include<SoftwareSerial.h>

const int inputPin1  = 22;    
const int inputPin2  = 24;    
const int enable1    = 26;
const int enable2    = 28;
const int inputPin3  = 30;   
const int inputPin4  = 32; 
const int led1 =49;
const int led2 =47;
const int led3 =45;
const int led4 =43;
String data;
int btVal;
SoftwareSerial mySerial(51,53); // RX, TX

void setup() 
{
    Serial.begin(9600);
    mySerial.begin(9600);
    pinMode(enable1,OUTPUT);
    pinMode(inputPin1, OUTPUT);
    pinMode(inputPin2, OUTPUT);
    pinMode(enable2,OUTPUT);
    pinMode(inputPin3, OUTPUT);
    pinMode(inputPin4, OUTPUT);
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(led3,OUTPUT);
    pinMode(led4,OUTPUT);
}


void loop()
{
 while (mySerial.available())
 {  
  {  
      data = mySerial.readStringUntil('\n');
      Serial.print(data);             
  } 
    
    btVal = (data.toInt());
    Serial.print("BlueTooth Value ");
    Serial.println(btVal);    



  switch (btVal) 
   {
      case 1:                                
        Serial.println("Forward");
        forward();
        break;

      case 2:                 
       Serial.println("Reverse");
        reverse();
        break;

      case 3:         
        Serial.println("Left");
        left();
        delay(1000);
        stopcar();
        break;
        
      case 4:                     
        Serial.println("Right");
        right();
        delay(1000);
        stopcar();
        break;
        
      case 5:                                            
        Serial.println("Stop");
        stopcar();
        break;
  }

 } 
 
                                                              
   if (mySerial.available() < 0)                              
    {
     Serial.println("No Bluetooth Data ");          
    }
  
}


void reverse()
{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    digitalWrite(enable1,HIGH);
    digitalWrite(inputPin1,HIGH);
    digitalWrite(inputPin2,LOW);
    digitalWrite(enable2,HIGH);
    digitalWrite(inputPin3,LOW);
    digitalWrite(inputPin4,HIGH);
}

void forward()
{
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(enable1,HIGH);
    digitalWrite(inputPin1,LOW);
    digitalWrite(inputPin2,HIGH);
    digitalWrite(enable2,HIGH);
    digitalWrite(inputPin3,HIGH);
    digitalWrite(inputPin4,LOW);
}

void left()
{
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
    digitalWrite(enable1,HIGH);
    digitalWrite(inputPin1,LOW);
    digitalWrite(inputPin2,HIGH);
    digitalWrite(enable2,HIGH);
    digitalWrite(inputPin3,LOW);
    digitalWrite(inputPin4,HIGH);
}

void right()
{  
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
    digitalWrite(enable1,HIGH);
    digitalWrite(inputPin1,HIGH);
    digitalWrite(inputPin2,LOW);
    digitalWrite(enable2,HIGH);
    digitalWrite(inputPin3,HIGH);
    digitalWrite(inputPin4,LOW);
}

void stopcar()
{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(enable1,LOW);
    digitalWrite(inputPin1,LOW);
    digitalWrite(inputPin2,LOW);
    digitalWrite(enable2,LOW);
    digitalWrite(inputPin3,LOW);
    digitalWrite(inputPin4,LOW);
}
