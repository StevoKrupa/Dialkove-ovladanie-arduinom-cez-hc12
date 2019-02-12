#include <SoftwareSerial.h>


int motory[6];
byte a;

SoftwareSerial mySerial(13, 12);// RX, TX

void setup() 
{
  Serial.begin(9600); 
  mySerial.begin(9600);
}
int A;
void loop() 
{
  serialresive();
  
  for(int i=0;i<6;i++)
    {
    Serial.print(motory[i]);
    Serial.print(' ');
    }
  Serial.println();
  ////////////////////////////////////////////////////
  A=motory[0];
  if(A>150)
  {
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH); 
  }
  if(A<50)
  {
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW); 
  }
  if((A>50)&&(A<150))
  {
  digitalWrite(2,LOW);
  digitalWrite(3,LOW); 
  }
  
}
int serialresive()
{
  int i=0;
  while(mySerial.read()!='A')
  {
  i++;
  if(i>4000)
  {
    Serial.println("conection lost!!!!!");
    return(0);      
  }
  delay(1);
  }
  //Serial.println(mySerial.read());
   motory[0]=mySerial.parseInt();
   delay(1);
    motory[1]=mySerial.parseInt();
    delay(1);
     motory[2]=mySerial.parseInt();
     delay(1);
      motory[3]=mySerial.parseInt();
      delay(1);
       motory[4]=mySerial.parseInt();
       delay(1);
        motory[5]=mySerial.parseInt();
           
 mySerial.flush();
}
