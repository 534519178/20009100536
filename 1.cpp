// C++ code
//
#include<MsTimer2.h>
void onTimer()
{
  int tick=0;
  Serial.print("timer ");
  tick++;
  if(tick>9)
  {
	tick=0;
  }
  if(tick%2)
  {
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
  }
  else
  {
	digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
  }
  
  Serial.println(tick);
  digitalWrite(8,((tick)&0x1));
  digitalWrite(9,((tick>>1)&0x1));
  digitalWrite(10,((tick>>2)&0x1));
  digitalWrite(11,((tick>>3)&0x1));
           
}

void setup()
{
  Serial.begin(9600);
  int i=8;
  for(i=8;i<=13;i++)
  {
    pinMode(i,OUTPUT);
  }
  
  MsTimer2::set(500, onTimer);
  MsTimer2::start();
}

