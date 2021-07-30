// C++ code
//
#include<MsTimer2.h>
 int tick1=0;
 int tick2=0;
void onTimer()
{
  Serial.print("timer ");
  tick1++;
  if(tick1>9)
  {
	tick1=0;
    tick2++;
  }
  if(tick1%2)
  {
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
  }
  else
  {
	digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
  }
  
  Serial.println(tick1);
  digitalWrite(4,((tick1&0x1));
  digitalWrite(5,((tick1>>1)&0x1));
  digitalWrite(6,((tick1>>2)&0x1));
  digitalWrite(7,((tick1>>3)&0x1));
   
  Serial.println(tick2);
  digitalWrite(8,(tick2&0x1));
  digitalWrite(9,((tick2>>1)&0x1)); 
  digitalWrite(10,((tick2>>2)&0x1));
  digitalWrite(11,((tick2>>3)&0x1));
}

void setup()
{
  Serial.begin(9600);
  int i=0;
  for(i=8;i<=13;i++)
  {
    pinMode(i,OUTPUT);
  }
  pinMode(2,INPUT_PULLUP);
  MsTimer2::set(1000,onTimer);
  MsTimer2::start();
}

void keyPro(){
    if(digitalRead(2)==LOW)
    {
      delay(20);
      if(digitalRead(2)==LOW){
        tick1=0;
        tick2=0;
        while(!digitalRead(2));
      }
    }
  }
void loop()
{
  keyPro();
}


