#include <Servo.h>
int trigPin=12;
int echoPin=11;
long duration;
long distance;
Servo MyServo;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  MyServo.attach(9);
}

void loop(){
    for(int i=0;i<180;i=i+1){            
        MyServo.write(i);
        delay(30);
        distance = cal_Dist();
        Serial.print(i);                      
        Serial.print(",");                   
        Serial.print(distance);              
        Serial.print(".");                   
     }
    for(int i=180;i>0;i=i-1){  
        MyServo.write(i);
        delay(30);
        distance = cal_Dist();
        Serial.print(i);
        Serial.print(",");
        Serial.print(distance);
        Serial.print(".");
    }
}

    int cal_Dist(){
       digitalWrite(trigPin, LOW);
       delayMicroseconds(2);
       digitalWrite(trigPin, HIGH);
       delayMicroseconds(10);
       digitalWrite(trigPin, LOW);                                                     
       duration = pulseIn(echoPin, HIGH);                            
       distance= duration*0.034/2;                  
       return distance;
}
