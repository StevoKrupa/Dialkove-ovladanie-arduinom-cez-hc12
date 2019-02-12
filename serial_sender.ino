#include <SoftwareSerial.h>
int motory[6];
SoftwareSerial mySerial(13, 12);// RX, TX

int i;
int a,b,c,d,e,f;

void setup() 
{
  
  Serial.begin(9600),;
  mySerial.begin(9600);
  
}

void loop() 
{
 
 a=analogRead(A0);
 b=analogRead(A1);
 c=analogRead(A2);
 d=analogRead(A3);
 e=analogRead(A4);
 f=analogRead(A5);
 
 a=map(a,0,1023,0,200);
 b=map(b,0,1023,0,200);
 c=map(c,0,1023,0,200);
 d=map(d,0,1023,0,200);
 e=map(e,0,1023,0,200);
 f=map(f,0,1023,0,200);
 if((a>90)&&(a<110))
 {
  a=100; 
 }
 if((b>90)&&(b<110))
 {
  b=100; 
 }
 
 if((c>90)&&(c<110))
 {
  c=100; 
 }if((d>90)&&(d<110))
 {
  d=100; 
 }
 if((e>90)&&(e<110))
 {
  e=100; 
 }
 if((f>90)&&(f<110))
 {
  f=100; 
 }
 motory[0]=a;
 motory[1]=b;
 motory[2]=c;
 motory[3]=d;
 motory[4]=e;
 motory[5]=f;
 Serial.print(a);
 Serial.print(" ");
 Serial.println(b);
 serialsend();
 delay(10);
}
int serialsend()
{
    mySerial.print("A");
    mySerial.print(motory[0]);
    mySerial.print(' ');
    delay(1);
    mySerial.print(motory[1]);
    mySerial.print(' ');
    delay(1);
    mySerial.print(motory[2]);
    mySerial.print(' ');
    delay(1);
    mySerial.print(motory[3]);
    mySerial.print(' ');
    delay(1);
    mySerial.print(motory[4]);
    mySerial.print(' ');
    delay(1);
    mySerial.print(motory[5]);
    mySerial.print(' ');
    delay(1);
    mySerial.print(motory[6]);
    mySerial.print(' ');
    delay(1);
   
}
