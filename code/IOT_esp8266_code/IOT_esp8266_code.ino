#include "arduino_secrets.h"
/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/dfe9c21c-ecd9-4b09-a85f-9b807deea304 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  bool right;
  bool down;
  bool up;
  bool left;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial n(12,15);//d6,d8,rx,tx
bool flag=true;

//Servo myservo;


void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(115200);
  n.begin(9600);
  pinMode(16,OUTPUT);//d0
  pinMode(5,OUTPUT);//d1
  pinMode(4,OUTPUT);//d2
  pinMode(0,OUTPUT);//d3
  //myservo.attach(2,550,2500);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1200); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  n.write(-1);
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  
  
}

void onUpChange() {
  // Do something
  if(up)
  {

   // myservo.write(0); 
    n.write(1);
    Serial.println("up");
    digitalWrite(16,HIGH);
    digitalWrite(5,HIGH);
   
    
   
  }
 
  else{
      
     digitalWrite(16,LOW);
     digitalWrite(5,LOW);
     digitalWrite(4,LOW);
     digitalWrite(0,LOW);
    
  }
}


void onDownChange() {
  // Do something
   if(down)
  {
  
    
    //myservo.write(0);
     n.write(1);
    Serial.println("down");
    digitalWrite(4,HIGH);
    digitalWrite(0,HIGH);
     
  }
else
  {
     
     digitalWrite(16,LOW);
     digitalWrite(5,LOW);
     digitalWrite(4,LOW);
     digitalWrite(0,LOW);
   
  }
}


void onLeftChange() {
  // Do something
   if(left)
  {
  
     
    //myservo.write(100); 
    n.write(0);    
    Serial.println("left");
    digitalWrite(16,HIGH);
    digitalWrite(4,HIGH);
    
  }
  else
  {
     
     digitalWrite(16,LOW);
     digitalWrite(5,LOW);
     digitalWrite(4,LOW);
     digitalWrite(0,LOW);
     
  }
}


void onRightChange() {
  // Do something
   if(right)
  {
    
     //myservo.write(100); 
     n.write(0); 
    Serial.println("right");
    digitalWrite(0,HIGH);
    digitalWrite(5,HIGH);
    
  }
else
  {
  
     digitalWrite(16,LOW);
     digitalWrite(5,LOW);
     digitalWrite(4,LOW);
     digitalWrite(0,LOW);
     
  }
}
void onNumChange() {
  // Do something

  if(!flag)
  {
     Serial.println(num);
     n.write(num);
            
  }
  flag=false;
  

}
