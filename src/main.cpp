#include <Arduino.h>
#include <SoftwareSerial.h>

String data;
SoftwareSerial BTserial(2, 3);
#define blink_led 10

void setup()
{
  BTserial.begin(9600); 
  Serial.begin(9600);
  pinMode(blink_led, OUTPUT);
}

void loop()
{
  data = "";
  
  while(BTserial.available()>0)
  {
    data +=BTserial.readString();
    Serial.println(data);
    if( data == "close" || data == "Close"){
      digitalWrite(blink_led, LOW);   
    }else if( data == "open" || data == "Open"){
      digitalWrite(blink_led, HIGH);  
    }else{
      digitalWrite(blink_led, HIGH); 
      delay(200);
      digitalWrite(blink_led, LOW); 
      delay(200);
      digitalWrite(blink_led, HIGH); 
      delay(200);
      digitalWrite(blink_led, LOW); 
      delay(200);
    }
  }
}