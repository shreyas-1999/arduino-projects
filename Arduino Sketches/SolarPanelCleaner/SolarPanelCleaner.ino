
  int relay1 = 40;
  int relay2 = 42;
  int relay3 = 44;
  int relay4 = 46;
  
 const int trigR1 = 7;
 const int echoR1 = 6;
 const int trigR2 = 2;
 const int echoR2 = 3;
 const int trigL1 = 14;
 const int echoL1 = 15;
 const int trigL2 = 16;
 const int echoL2 = 17;
  long durationR1, distanceR1;
  long durationR2, distanceR2;
  long durationL1, distanceL1;
  long durationL2, distanceL2;
  
void setup() 
{
  delay(5000);   // delay for 2 seconds
  Serial.begin(9600);
  
  pinMode(trigR1, OUTPUT);         // set trig pin as output
  pinMode(echoR1, INPUT);          //set echo pin as input to capture reflected waves
  pinMode(trigR2, OUTPUT);
  pinMode(echoR2, INPUT);
  pinMode(trigL1, OUTPUT);
  pinMode(echoL1, INPUT);
  pinMode(trigL2, OUTPUT);
  pinMode(echoL2, INPUT);
   
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(relay3,OUTPUT);
  pinMode(relay4,OUTPUT);    

  
}

void loop() 
{

 reverseCheck();
 
}

void forward()
{
  digitalWrite (relay1, HIGH);  //motor begins rotating
  digitalWrite (relay2, HIGH);  //motor begins rotating
  digitalWrite (relay3, LOW);
  digitalWrite (relay4, LOW);
}

void reverse()
{
  digitalWrite (relay3, HIGH);  //motor begins rotating
  digitalWrite (relay4, HIGH);  //motor begins rotating
  digitalWrite (relay1, LOW);
  digitalWrite (relay2, LOW);
}

void forwardCheck()
{
  
  digitalWrite(trigR1, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigR1, HIGH);         // send waves for 10 us
  delayMicroseconds(10);
  digitalWrite(trigR1, LOW);
  durationR1 = pulseIn(echoR1, HIGH); // receive reflected waves
  distanceR1 = durationR1 / 58.2;     // convert to distance
  delay(10);

  digitalWrite(trigR2, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigR2, HIGH);         // send waves for 10 us
  delayMicroseconds(10);
  digitalWrite(trigR2, LOW);
  durationR2 = pulseIn(echoR2, HIGH); // receive reflected waves
  distanceR2 = durationR2 / 58.2;     // convert to distance
  delay(10);

  if( distanceR1 < 10 && distanceR2 < 10)
  {
    forward();
  }

  if( distanceR1 > 10 && distanceR2 < 10)
  {
    forward();
  }

  if( distanceR1 < 10 && distanceR2 > 10)
  {
    forward();
  }

  if( distanceR1 > 10 && distanceR2 > 10)
  {
    Motorstop();
  }
}

void reverseCheck()
{
 
  digitalWrite(trigL1, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigL1, HIGH);         // send waves for 10 us
  delayMicroseconds(10);
  digitalWrite(trigL1, LOW);
  durationL1 = pulseIn(echoL1, HIGH); // receive reflected waves
  distanceL1 = durationL1 / 58.2;     // convert to distance
  delay(10);
  
  digitalWrite(trigL2, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigL2, HIGH);         // send waves for 10 us
  delayMicroseconds(10);
  digitalWrite(trigL2, LOW);
  durationL2 = pulseIn(echoL2, HIGH); // receive reflected waves
  distanceL2 = durationL2 / 58.2;     // convert to distance
  delay(10);
  
  if( distanceL1 < 10 && distanceL2 < 10)
  {
    reverse();
  }

  if( distanceL1 < 10 && distanceL2 > 10)
  {
    reverse();
  }

  if( distanceL1 > 10 && distanceL2 < 10)
  {
    reverse();
  }

  if( distanceL1 > 10 && distanceL2 > 10)
  {
    Motorstop();
  }

 
}

 void Motorstop()
{
  digitalWrite (relay1, LOW);
  digitalWrite (relay2, LOW);
  digitalWrite (relay3, LOW);
  digitalWrite (relay4, LOW);
}
