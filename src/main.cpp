#include <Arduino.h>
#include <SoftwareSerial.h>

#define blink_led 10

String data;
//RX, TX
SoftwareSerial BTserial(2, 3);


void setup()
{
  //Starts software serial at 9600 Baudrate.
  BTserial.begin(9600); 
  Serial.begin(9600);
  pinMode(blink_led, OUTPUT);
}

void loop()
{
  //Resets the variable every time loop starts.
  data = "";
  
  while(BTserial.available()>0)
  {
    data +=BTserial.readString();
    Serial.println(data);
    if( data == "close" || data == "Close"){
      //Turns off the led.
      digitalWrite(blink_led, LOW);   
    }else if( data == "open" || data == "Open"){
      //Turns on the led.
      digitalWrite(blink_led, HIGH);  
    }else{
      //The led blinks.
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