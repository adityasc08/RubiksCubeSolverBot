#include <Servo.h>  
Servo Rightservo;Servo Leftservo;Servo Frontservo;Servo Backservo;Servo FBservo;Servo RLservo;
int pos = 0;
String input;
char input1[100];
char b,c;
int i,a,d,e,f=0;

int FBRL_scan=50; 

int F_zero=45;int F_ninety=130;

int B_zero=45;int B_ninety=130;

int R_zero=45;int R_ninety=130;

int L_zero=45;int L_ninety=130;

int RL_zero=0;int RL_ninety=90;

int FB_zero=0;int FB_ninety=90;

void setup() {

Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
FBservo.attach(3);
RLservo.attach(5);
Frontservo.attach(6);
Backservo.attach(10);
Rightservo.attach(9);
Leftservo.attach(11);



 pinMode(13, OUTPUT);
 


RLservo.write(RL_zero);
FBservo.write(FB_zero);

 
}

void loop() {
restart:
while(Serial.available()) {
input= Serial.readString();// read the incoming data as string
 
}//serial ends
input.toCharArray(input1,7);
if(strcmp(input1,"Start.")==0||strcmp(input1,"\nStart.")==0)
{Serial.println("Ready.\n");
goto right;
}
else if(strcmp(input1,"Grab.")==0||strcmp(input1,"\nGrab.")==0)
{Rightservo.write(R_zero);
Leftservo.write(L_zero);
Frontservo.write(F_zero);
Backservo.write(B_zero);
RLservo.write(RL_zero);
FBservo.write(FB_zero);

delay(500);
RLservo.write(RL_ninety);
delay(5000);
FBservo.write(FB_ninety);



goto restart;
}
else if(strcmp(input1,"Ungrab.")==0||strcmp(input1,"\nUngrab.")==0)
{
Rightservo.write(R_zero);
Leftservo.write(L_zero);
Frontservo.write(F_zero);
Backservo.write(B_zero);
RLservo.write(RL_zero);
FBservo.write(FB_zero);


goto restart;
}
else{ goto restart;
}
right:
while(Serial.available()) {
input= Serial.readString();// read the incoming data as string
 
}//serial ends
input.toCharArray(input1,7);
if(strcmp(input1,"Right.")==0||strcmp(input1,"\nRight.")==0)
{FU();
wholeFAC();
pullback();
//*****************************************************************************************************************************8
Serial.println("Right.\n");
goto front;
}
else goto right;
front:
while(Serial.available()) {
input= Serial.readString();// read the incoming data as string
 
}//serial ends
input.toCharArray(input1,7);
if(strcmp(input1,"Front.")==0||strcmp(input1,"\nFront.")==0)
{wholeFC();
pullback();
//*****************************************************************************************************************************8
Serial.println("Front.\n");
goto down;
}
else goto front;
down:
while(Serial.available()) {
input= Serial.readString();// read the incoming data as string
 
}//serial ends
input.toCharArray(input1,6);
if(strcmp(input1,"Down.")==0||strcmp(input1,"\nDown.")==0)
{FU();
pullback();
//*****************************************************************************************************************************8
Serial.println("Down.\n");
goto left;
}
else goto down;
left:
while(Serial.available()) {
input= Serial.readString();// read the incoming data as string
 
}//serial ends
input.toCharArray(input1,6);
if(strcmp(input1,"Left.")==0||strcmp(input1,"\nLeft.")==0)
{FD();
wholeFC();
pullback();
//*****************************************************************************************************************************8
Serial.println("Left.\n");
goto back;
}
else goto left;
back:
while(Serial.available()) {
input= Serial.readString();// read the incoming data as string
 
}//serial ends
input.toCharArray(input1,6);
if(strcmp(input1,"Back.")==0||strcmp(input1,"\nBack.")==0)
{wholeFC();
pullback();
//*****************************************************************************************************************************8
Serial.println("Back.\n");

goto soln;
}
else goto back;
soln:
wholeFC();
wholeFC();
FD();
input="";
soln2:
while(Serial.available()) {
input= Serial.readString();// read the incoming data as string
 
}
if(input.length()>1)
goto solve;
else goto soln2;
solve:
for(i=0;i<input.length();i++)//for loop 1
{
b=input[i];
c=input[i+1];
///////////////////////////////////////
if(b=='R')
{
  if (c=='\'')
    {RAC();}
  else if(c=='2')
    {RC();RC();}
  else
    {RC();}

}
///////////////////////////////////////
if(b=='L')
{
  if (c=='\'')
    {LAC();}
  else if(c=='2')
    {LC();LC();}
  else
    {LC();}
  
}
///////////////////////////////////////
if(b=='F')
{
  if (c=='\'')
    {FAC();}
  else if(c=='2')
    {FC();FC();}
  else
    {FC();}
  
}
///////////////////////////////////////
if(b=='B')
{
  if (c=='\'')
    {BAC();}
  else if(c=='2')
    {BC();BC();}
  else
    {BC();}
  
}
///////////////////////////////////////
if(b=='U')
{
  if(c=='\'')
    {FD();FAC();FU();}
  else if(c=='2')
    {FD();FC();FC();FU();}
  else 
    {FD();FC();FU();}
}
///////////////////////////////////////
if(b=='D')
{
  if(c=='\'')
    {FD();BAC();FU();}
  else if(c=='2')
    {FD();BC();BC();FU();}
  else 
    {FD();BC();FU();}
}

///////////////////////////////////////
}//for loop 1
Serial.println("Done.\n");
input="";



}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RC()
{Rightservo.write(R_ninety); 
delay(500);
RLservo.write(RL_zero);
delay(500);
Rightservo.write(R_zero);
delay(500);
RLservo.write(RL_ninety);
delay(500);

}

////////////////////////////////////////////////////////////////////////////////

void RAC()
{RLservo.write(RL_zero);
delay(500);
  Rightservo.write(R_ninety); 
delay(500);
RLservo.write(RL_ninety);
delay(500);
Rightservo.write(R_zero);
delay(500);


}
////////////////////////////////////////////////////////////////////////////////

void LC()
{Leftservo.write(L_ninety); 
delay(500);
RLservo.write(RL_zero);
delay(500);
Leftservo.write(L_zero);
delay(500);
RLservo.write(RL_ninety);
delay(500);

}
////////////////////////////////////////////////////////////////////////////////
void LAC()
{RLservo.write(RL_zero);
delay(500);
  Leftservo.write(L_ninety); 
delay(500);
RLservo.write(RL_ninety);
delay(500);
Leftservo.write(L_zero);
delay(500);


}
////////////////////////////////////////////////////////////////////////////////

void FC()
{Frontservo.write(F_ninety); 
delay(500);
FBservo.write(FB_zero);
delay(500);
Frontservo.write(F_zero);
delay(500);
FBservo.write(FB_ninety);
delay(500);

}
////////////////////////////////////////////////////////////////////////////////
void FAC()
{FBservo.write(FB_zero);
delay(500);
  Frontservo.write(F_ninety); 
delay(500);
FBservo.write(FB_ninety);
delay(500);
Frontservo.write(F_zero);
delay(500);


}
////////////////////////////////////////////////////////////////////////////////

void BC()
{Backservo.write(B_ninety); 
delay(500);
FBservo.write(FB_zero);
delay(500);
Backservo.write(B_zero);
delay(500);
FBservo.write(FB_ninety);
delay(500);

}
////////////////////////////////////////////////////////////////////////////////
void BAC()
{FBservo.write(FB_zero);
delay(500);
  Backservo.write(B_ninety); 
delay(500);
FBservo.write(FB_ninety);
delay(500);
Backservo.write(B_zero);
delay(500);


}
////////////////////////////////////////////////////////////////////////////////
void FD()
{
  //rac
  RLservo.write(RL_zero);
delay(500);
  Rightservo.write(R_ninety); 
delay(500);
RLservo.write(RL_ninety);
delay(500);

FBservo.write(FB_zero);
delay(500);

Rightservo.write(R_zero);
Leftservo.write(L_ninety); 
delay(500);

FBservo.write(FB_ninety);
delay(500);

RLservo.write(RL_zero);
delay(500);
Leftservo.write(L_zero);
delay(500);
RLservo.write(RL_ninety);
delay(500);
   
  /*FBservo.write(FB_zero);
delay(500);
Rightservo.write(R_zero);
Leftservo.write(L_ninety);
delay(500);
FBservo.write(FB_ninety);
delay(500);
RLservo.write(FB_zero);
delay(500);
Rightservo.write(R_ninety);
Leftservo.write(L_zero);
delay(500);
RLservo.write(FB_ninety);
delay(500);
*/
}
////////////////////////////////////////////////////////////////////////////////
void FU()
{
//lac
RLservo.write(RL_zero);
delay(500);
  Leftservo.write(L_ninety); 
delay(500);
RLservo.write(RL_ninety);
delay(500);

FBservo.write(FB_zero);
delay(500);

Leftservo.write(L_zero);
//rc
Rightservo.write(R_ninety); 
delay(500);

FBservo.write(FB_ninety);
delay(500);

RLservo.write(RL_zero);
delay(500);
Rightservo.write(R_zero);
delay(500);
RLservo.write(RL_ninety);
delay(500);  
  /*FBservo.write(FB_zero);
delay(500);
Rightservo.write(R_ninety);
Leftservo.write(L_zero);
delay(500);
FBservo.write(FB_ninety);
delay(500);
RLservo.write(FB_zero);
delay(500);
Rightservo.write(R_zero);
Leftservo.write(L_ninety);
delay(500);
RLservo.write(FB_ninety);
*/
}
void wholeFAC()
{  FBservo.write(FB_zero);
delay(500);
  Frontservo.write(F_ninety); 
delay(500);
FBservo.write(FB_ninety);
delay(500);

RLservo.write(RL_zero);
delay(500);

Frontservo.write(F_zero);
  Backservo.write(B_ninety); 
delay(500);

RLservo.write(RL_ninety);
delay(500);

FBservo.write(FB_zero);
delay(500);
Backservo.write(B_zero);
delay(500);
FBservo.write(FB_ninety);
delay(500);

 
}
void wholeFC()
{//bac//fc
FBservo.write(FB_zero);
delay(500);
  Backservo.write(B_ninety); 
delay(500);
FBservo.write(FB_ninety);
delay(500);

RLservo.write(RL_zero);
delay(500);

Backservo.write(B_zero);
 Frontservo.write(F_ninety); 
delay(500);

RLservo.write(RL_ninety);
delay(500);

FBservo.write(FB_zero);
delay(500);
Frontservo.write(F_zero);
delay(500);
FBservo.write(FB_ninety);
delay(500); 
}

void pullback()
{
RLservo.write(FBRL_scan);
FBservo.write(FBRL_scan);
delay(500);

}
