const int inputPin1  = 22;    // Pin 15 of L293D IC
const int inputPin2  = 24;    // Pin 10 of L293D IC
const int enable1    = 26;
const int enable2    = 28;
const int inputPin3  = 30;   
const int inputPin4  = 32; 
int trigPin = 52;      // trig pin 
int echoPin = 50;     // Echo pin 
int trigPinL = 37;      
int echoPinL = 39; 
int trigPinR = 33;       
int echoPinR = 35;
long duration, distance;
long durationL, distanceL;
long durationR, distanceR;


void setup() 
{
    delay(random(500,2000));   // delay for random time
    Serial.begin(9600);
    pinMode(enable1,OUTPUT);
    pinMode(inputPin1, OUTPUT);
    pinMode(inputPin2, OUTPUT);
    pinMode(enable2,OUTPUT);
    pinMode(inputPin3, OUTPUT);
    pinMode(inputPin4, OUTPUT);
    pinMode(trigPin, OUTPUT);         // set trig pin as output
    pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
    pinMode(trigPinL, OUTPUT);         // set trig pin as output
    pinMode(echoPinL, INPUT);          //set echo pin as input to capture reflected waves
    pinMode(trigPinR, OUTPUT);         // set trig pin as output
    pinMode(echoPinR, INPUT);          //set echo pin as input to capture reflected waves
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  distance = duration / 58.2;   // convert to distance
  delay(10);
  
  digitalWrite(trigPinL, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPinL, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  durationL = pulseIn(echoPinL, HIGH); // receive reflected waves
  distanceL = durationL / 58.2;   // convert to distance
  delay(10);

  digitalWrite(trigPinR, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPinR, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  durationR = pulseIn(echoPinR, HIGH); // receive reflected waves
  distanceR = durationR / 58.2;   // convert to distance
  delay(10);
  
  if (distance < 10 && distanceL < 10 && distanceR < 10)
  {
    forward();
  } 
  if(distance > 10)
  {
    stopcar();
    delay(500);
    reverse();
    delay(500);
    right();
    delay(950);
  }
  if(distanceR > 10)
  {
    stopcar();
    delay(500);
    right();
    delay(500);
  }
  if(distanceL > 10)
  {
    stopcar();
    delay(500);
    left();
    delay(500);
  }
 
}

void reverse()
{
    digitalWrite(enable1,HIGH);
    digitalWrite(inputPin1,HIGH);
    digitalWrite(inputPin2,LOW);
    digitalWrite(enable2,HIGH);
    digitalWrite(inputPin3,LOW);
    digitalWrite(inputPin4,HIGH);
}

void forward()
{
    digitalWrite(enable1,HIGH);
    digitalWrite(inputPin1,LOW);
    digitalWrite(inputPin2,HIGH);
    digitalWrite(enable2,HIGH);
    digitalWrite(inputPin3,HIGH);
    digitalWrite(inputPin4,LOW);
}

void right()
{
    digitalWrite(enable1,HIGH);
    digitalWrite(inputPin1,LOW);
    digitalWrite(inputPin2,HIGH);
    digitalWrite(enable2,HIGH);
    digitalWrite(inputPin3,LOW);
    digitalWrite(inputPin4,HIGH);
}

void left()
{
    digitalWrite(enable1,HIGH);
    digitalWrite(inputPin1,HIGH);
    digitalWrite(inputPin2,LOW);
    digitalWrite(enable2,HIGH);
    digitalWrite(inputPin3,HIGH);
    digitalWrite(inputPin4,LOW);
}

void stopcar()
{
    digitalWrite(enable1,LOW);
    digitalWrite(inputPin1,HIGH);
    digitalWrite(inputPin2,LOW);
    digitalWrite(enable2,LOW);
    digitalWrite(inputPin3,HIGH);
    digitalWrite(inputPin4,LOW);
}
