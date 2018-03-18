#include<SoftwareSerial.h>

int sensorPin = A0; // select the input pin for the LDR

int sensorValue = 0;
int motor=3;// variable to store the value coming from the sensor
const int ledPin = 3;   //pin 3 has PWM funtion
const int flexPin = A1; //pin A0 to read analog input

//Variables:
int value; //save analog value

 int motor1=4;
 int motor2=5;

void setup() {
pinMode(motor, OUTPUT);
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);

  pinMode(ledPin, OUTPUT);  //Set pin 3 as 'output'
  Serial.begin(9600);       //Begin serial communication

}

void loop()

{

sensorValue = analogRead(sensorPin);

//Serial.println(sensorValue);

if(sensorValue<=1022 && sensorValue>1010)
  {
    Serial.println("Flame Detected Close by");
     analogWrite(motor, sensorValue);
    
  }

else if(sensorValue<1010 && sensorValue>950)
  { 
    Serial.println("Flame Detected Very Near");
  }

 
else if(sensorValue<950)
  { 
    Serial.println("Too late");
    //analogWrite(motor, HIGH);
    
  }
delay(10);

//FLEXPART
  value = analogRead(flexPin);         //Read and save analog value from potentiometer
                //Print value
  //value = map(value, 700, 900, 0, 255);
  //Serial.println(value); 
  if(value<800){
  digitalWrite(motor1,HIGH);digitalWrite(motor2,LOW);}
  else
  {digitalWrite(motor1,LOW);digitalWrite(motor2,HIGH);}
  //Map value 0-1023 to 0-255 (PWM)
  //analogWrite(ledPin, value);          //Send PWM value to led
  delay(10);                          //Small delay
  

}

