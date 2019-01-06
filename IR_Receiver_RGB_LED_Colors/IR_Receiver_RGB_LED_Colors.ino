
#include <IRremote.h>
int out=9;
int out2=10;
int out3=6; 
int steps=5; 
int RECV_PIN = 11;


IRrecv irrecv(RECV_PIN);

decode_results results;

void setup(){
  irrecv.enableIRIn(); // start the receiver
  pinMode(out,OUTPUT);
  pinMode(out2,OUTPUT);
  pinMode(out3,OUTPUT);
  analogWrite(out,0);
  analogWrite(out2,0);
  analogWrite(out3,0);
}

void loop() {
  if (irrecv.decode(&results)) {
    
    if (results.value==0xA5C77){
    digitalWrite(out,HIGH);
  }
  else(digitalWrite(out,LOW));
  if (results.value==0xF5D23){
    digitalWrite(out2,HIGH);
  }
  else(digitalWrite(out2,LOW));
  if (results.value==0xE4A7854){
    digitalWrite(out3,HIGH);
  }
  else(digitalWrite(out3,LOW));

  if (results.value==0xBC111){
    analogWrite(out,0);
    analogWrite(out2,255);
    analogWrite(out3,255);  
  }
  if (results.value==0xBC121){
    analogWrite(out,0);
    analogWrite(out2,102);
    analogWrite(out3,0);
  }
  if (results.value==0xBD243A){
    analogWrite(out,153);
    analogWrite(out2,0);
    analogWrite(out3,255); 
  }
  if (results.value==0x20DF8D72){
    analogWrite(out,255);
    analogWrite(out2,255);
    analogWrite(out3,0);
  }
  if (results.value==0x20DD8D27){
    analogWrite(out,255);
    analogWrite(out2,153);
    analogWrite(out3, 0);
  }
  if (results.value==0xF5D75){
    analogWrite(out,255);
    analogWrite(out2,0);
    analogWrite(out3,204);  
  }
  irrecv.resume();
}}




