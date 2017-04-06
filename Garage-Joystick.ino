#include <IRremote.h>
#include <Servo.h>

Servo myservo;
int RECV_PIN = 7;
boolean lampe = false;
int position_init = 0;
int position_final = 1023;
int posit=0;
int JoysX = 0;
int JoyVal;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(JoysX, INPUT);
  pinMode(4, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
    myservo.attach(9);
}

void loop() {
  JoyVal = analogRead(JoysX);
  if (JoyVal = 1023) {
    Serial.println(JoyVal);
    if(JoyVal == 1023 ){
      if(lampe)
        posit = position_init;
      else posit = position_final;
      myservo.write(map(posit, 0, 1023,180, 90));
      lampe =!lampe;
       digitalWrite(4, lampe);
    }
     
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}


int getValue(long value){
  Serial.println(value);
  int val =-1;
  switch(value){
    case 16582903 : val=1;break;
    case 16615543 : val=2;break;
    case 16599223 : val=3;break;
    case 16591063 : val=4;break;
    case 16623703 : val=5;break;
    case 16607383 : val=6;break;
    case 16586983 : val=7;break;
    case 16619623 : val=8;break;
    case 16603303 : val=9;break;
    case 16593103 : val=0;break;
    case 16580863 : val=10;break;
    default : val=-1;
    
  }
  return val;
}
