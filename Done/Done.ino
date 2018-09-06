int S1 = 8;   //left far sensor
int S2 = 7;   //left near sensor
int S3 = 4;   //middle sensor
int S4 = 3;   //right near sensor
int S5 = 2;   //right far sensor
int LM1 = 11; //left motor
int LM2 = 12; //left motor
int RM1 = 9;  //right motor
int RM2 = 10; //right motor
int A;
int B;
int C;
int D;
int E;
int en1=6;    //M1
int en2=5;    //M2
int i;
const int w = 0;     // low
const int b = 1 ;    // high

void setup()
{
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
}

void loop()
{
/* A = digitalRead(S1);
 B = digitalRead(S2);
 C = digitalRead(S3);
 D = digitalRead(S4);
 E = digitalRead(S5);*/

 readsensorvalue();

   if(A == b && B== b && C== w && D== b && E == b) //straight
  {
    straight(); 
  } 
   if (A==b && B==w && C==w && D==b && E==b|| A==b && B==w && C==b && D==b && E==b ) //adjustment
  {
    leftcurve();
  }
   if(A==b && B==b && C==w && D==w && E==b ||  A==b && B==b && C==b && D==w && E==b ) //adjustment
  {
    rightcurve();
  }

  if(A==w && B==w && C==w && D==b && E==b )
  {
    straight();
    delay(100);
    left1();
  }
  if(A==w && B==w && C==w && D==w && E==w)  
  {  
    straight();
    delay(100);
    stop1();
    delay(100);

 A = digitalRead(S1);
 B = digitalRead(S2);
 C = digitalRead(S3);
 D = digitalRead(S4);
 E = digitalRead(S5);

    if(A==w && B==w && C==w && D==w && E==w )
    {
      straight();
      delay(500);
      stop1();
      for(;;);
    }
    else
    {
    left1();
    }
 A = digitalRead(S1);
 B = digitalRead(S2);
 C = digitalRead(S3);
 D = digitalRead(S4);
 E = digitalRead(S5);
  }
  if(A==b && B==b && C==w && D==w && E==w )
  {
    straight();
    delay(100);
    stop1();
    delay(100); 

 A = digitalRead(S1);
 B = digitalRead(S2);
 C = digitalRead(S3);
 D = digitalRead(S4);
 E = digitalRead(S5);

 if(A == b && B== b && C== w && D== b && E == b )
 {
  straight();
 }
 else
 {  
  right1();  
 }
 
}
if(A == b && B== b && C==b && D== b && E == b )
{
  turnaround();
  stop1();
  delay(100);
}
}

 void straight()
{
 analogWrite(en1,100);
 analogWrite(en2,100);
  
 digitalWrite(LM1,HIGH);
 digitalWrite(LM2,LOW);
 digitalWrite(RM1,HIGH);
 digitalWrite(RM2,LOW);;
}

void leftcurve()
{
 analogWrite(en1,50);
 analogWrite(en2,200);

 digitalWrite(LM1,HIGH);
 digitalWrite(LM2,LOW);
 digitalWrite(RM1,HIGH);
 digitalWrite(RM2,LOW);
}

void rightcurve()
{
 analogWrite(en1,200);
 analogWrite(en2,50);

 digitalWrite(LM1,HIGH);
 digitalWrite(LM2,LOW);
 digitalWrite(RM1,HIGH);
 digitalWrite(RM2,LOW);
}

void stop1()
{
 analogWrite(en1,0);
 analogWrite(en2,0);
    
 digitalWrite(LM1,LOW);
 digitalWrite(LM2,LOW);
 digitalWrite(RM1,LOW);
 digitalWrite(RM2,LOW);
}  

void turnaround()
{
 i=0;
 do
{ 
 analogWrite(en1,75);
 analogWrite(en2,75);
    
 digitalWrite(LM1,HIGH);
 digitalWrite(LM2,LOW);
 digitalWrite(RM1,LOW);
 digitalWrite(RM2,HIGH);
 
 for(i=0;i<=0;i++)
 {
  delay(1100);
 }
}
 while(A != b && B != b && C != w && D != b && E != b);
}

void left1()
{
 i=0;
 do
{
 analogWrite(en1,75);
 analogWrite(en2,75);
   
 digitalWrite(LM1,LOW);
 digitalWrite(LM2,HIGH);
 digitalWrite(RM1,HIGH);
 digitalWrite(RM2,LOW); 

 for(i=0;i<=0;i++)
 {
  delay(650);
 }
}
  while(A != b && B != b && C != w && D != b && E != b);
}

void right1()
{
 i=0;
 do
{
 analogWrite(en1,75);
 analogWrite(en2,75);
   
 digitalWrite(LM1,HIGH);
 digitalWrite(LM2,LOW);
 digitalWrite(RM1,LOW);
 digitalWrite(RM2,HIGH); 
 for(i=0;i<=0;i++)
 {
  delay(650);
 }
}
while(A != b && B != b && C != w && D != b && E != b);
}

void readsensorvalue()
{
 A = digitalRead(S1);
 B = digitalRead(S2);
 C = digitalRead(S3);
 D = digitalRead(S4);
 E = digitalRead(S5);

 delay(2);

 A = digitalRead(S1);
 B = digitalRead(S2);
 C = digitalRead(S3);
 D = digitalRead(S4);
 E = digitalRead(S5);

 delay(2 );
   
 A = digitalRead(S1);
 B = digitalRead(S2);
 C = digitalRead(S3);
 D = digitalRead(S4);
 E = digitalRead(S5);
}

