#include <Arduino.h>

int pinA = 11;int pinB = 7;int pinC = 4;int pinD = 2;
int pinE = 13;int pinF = 10;int pinG = 5;
int pinDP = 3;int D1 = 9;int D2 = 8;int D3 = 12; int D4 = 6;
int AxaX = A5; 
int AxaY = A2;

void setup() {
pinMode(pinA, OUTPUT);
pinMode(pinB, OUTPUT);
pinMode(pinC, OUTPUT);
pinMode(pinD, OUTPUT);
pinMode(pinE, OUTPUT);
pinMode(pinF, OUTPUT);
pinMode(pinG, OUTPUT);
pinMode(pinDP, OUTPUT);
pinMode(D1, OUTPUT);
pinMode(D2, OUTPUT);
pinMode(D3, OUTPUT);
pinMode(D4, OUTPUT);
pinMode(AxaX, INPUT_PULLUP);
pinMode(AxaY, INPUT_PULLUP);
LED_1_3();
Serial.begin(9600);

}

int X=1;
int Y=3;
int digit=1;
int direction=2;
int oneright=0;

void loop(){
  int XX=analogRead(AxaX);
  int YY=analogRead(AxaY);
  
  Serial.print(XX);
  Serial.print(" ");
  Serial.println(YY);
  if (oneright==0){
    right();
  }
  oneright=oneright+1; 

  if (XX>1000){
     up();
  }    
    if (XX<100){
     down();
  }
    if (YY<100){
     left();
  } 
    if (YY>1000){
     right();
  } 
}

void up(){
  if (X==5 && direction==1){
    LED_4_1();
  } else if (X==5 && direction==2){
    LED_4_2();
  } else if (X==3 && direction==1){
    LED_2_1();
  } else if (X==3 && direction==2){
    LED_2_2();
  } else if (X==4 && Y==1){
    LED_2_1();
  } else if (X==4 && Y==2){
    LED_2_2();
  } 
  direction=3;
  delay(200);
}

void down(){
  if (X==1 && direction ==1)
  {
    LED_2_1();
  } else if (X==1 && direction==2){
    LED_2_2();
  } else if (X==3 && direction==1){
    LED_4_1();
  } else if (X==3 && direction==2){
    LED_4_2();
  } else if (X==2 && Y==1){
    LED_4_1();
  } else if (X==2 && Y==2){
    LED_4_2();
  } 
  direction=4;
  delay(200);
}

void left(){
  if (Y==1){ 
    leftDigit();
    leftLED(); 
  } else if (Y==2) {
    leftLED();
  } else if (Y==3) {
    leftDigit();
  }
  direction=1;
  delay(200);
}

void right(){
  if (Y==2){
    rightDigit();  
    rightLED();
  } else if (Y==1) {
    rightLED();
  } else if (Y==3){
    rightDigit();
  }
  direction=2;
  delay(200);
}

void rightDigit(){
  digit=digit+1;
  if (digit==1){
    DIGIT_1();
  } else if (digit==2){
    DIGIT_2();
  } else if (digit==3){
    DIGIT_3();
  } else if (digit==4){
    DIGIT_4();
  } else if (digit==5){
    digit=4;
  } 
}

void leftDigit(){
  digit=digit-1;
  if (digit==4){
    DIGIT_4();
  } else if (digit==3){
    DIGIT_3();
  } else if (digit==2){
    DIGIT_2();
  } else if (digit==1){
    DIGIT_1();
  } else if (digit==0){
    digit=1;
  } 
}

void rightLED(){
  if (X==2 && Y==1 && direction==3)
  {
    LED_1_3();
  } else if (X==2 && Y==1 && direction==4)
  {
    LED_3_3();
  } else if (X==4 && Y==1 && direction==3)
  {
    LED_3_3();
  } else if (X==4 && Y==1 && direction==4)
  {
    LED_5_3();
  } else if (X==4 && Y==2 && direction==4)
  {
    LED_5_3();
  } else if (X==4 && Y==2 && direction==3)
  {
    LED_3_3();
  } else if (X==2 && Y==2 && direction==4)
  {
    LED_3_3();
  } else if (X==2 && Y==2 && direction==3)
  {
    LED_1_3();
  } 
}

void leftLED(){
  if (X==2 && Y==2 && direction==3)
  {
    LED_1_3();
  } else if (X==2 && Y==2 && direction==4)
  {
    LED_3_3();
  } else if (X==4 && Y==2 && direction==3)
  {
    LED_3_3();
  } else if (X==4 && Y==2 && direction==4)
  {
    LED_5_3();
  } else if (X==2 && Y==1 && direction==4)
  {
    LED_3_3();
  } else if (X==2 && Y==1 && direction==3)
  {
    LED_1_3();
  } else if (X==4 && Y==1 && direction==4)
  {
    LED_5_3();
  } else if (X==4 && Y==1 && direction==3)
  {
    LED_3_3();
  }
  
  
}

void LED_1_3 (){
digitalWrite(pinA, HIGH);
digitalWrite(pinB, LOW);
digitalWrite(pinC, LOW);
digitalWrite(pinD, LOW);
digitalWrite(pinE, LOW);
digitalWrite(pinF, LOW);
digitalWrite(pinG, LOW);
X=1;
Y=3;
}

void LED_2_1 (){
digitalWrite(pinA, LOW);
digitalWrite(pinB, LOW);
digitalWrite(pinC, LOW);
digitalWrite(pinD, LOW);
digitalWrite(pinE, LOW);
digitalWrite(pinF, HIGH);
digitalWrite(pinG, LOW);
X=2;
Y=1;
}

void LED_2_2 (){
digitalWrite(pinA, LOW);
digitalWrite(pinB, HIGH);
digitalWrite(pinC, LOW);
digitalWrite(pinD, LOW);
digitalWrite(pinE, LOW);
digitalWrite(pinF, LOW);
digitalWrite(pinG, LOW);
X=2;
Y=2;
}

void LED_3_3 (){
digitalWrite(pinA, LOW);
digitalWrite(pinB, LOW);
digitalWrite(pinC, LOW);
digitalWrite(pinD, LOW);
digitalWrite(pinE, LOW);
digitalWrite(pinF, LOW);
digitalWrite(pinG, HIGH);
X=3;
Y=3;
}

void LED_4_1 (){
digitalWrite(pinA, LOW);
digitalWrite(pinB, LOW);
digitalWrite(pinC, LOW);
digitalWrite(pinD, LOW);
digitalWrite(pinE, HIGH);
digitalWrite(pinF, LOW);
digitalWrite(pinG, LOW);
X=4;
Y=1;
}

void LED_4_2 (){
digitalWrite(pinA, LOW);
digitalWrite(pinB, LOW);
digitalWrite(pinC, HIGH);
digitalWrite(pinD, LOW);
digitalWrite(pinE, LOW);
digitalWrite(pinF, LOW);
digitalWrite(pinG, LOW);
X=4;
Y=2;
}

void LED_5_3 (){
digitalWrite(pinA, LOW);
digitalWrite(pinB, LOW);
digitalWrite(pinC, LOW);
digitalWrite(pinD, HIGH);
digitalWrite(pinE, LOW);
digitalWrite(pinF, LOW);
digitalWrite(pinG, LOW);
X=5;
Y=3;
}

void DIGIT_1()
{
  digitalWrite(D1,LOW);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,HIGH);
  digitalWrite(D4,HIGH);
}
void DIGIT_2()
{
  digitalWrite(D1,HIGH);
  digitalWrite(D2,LOW);
  digitalWrite(D3,HIGH);
  digitalWrite(D4,HIGH);
}
void DIGIT_3()
{
  digitalWrite(D1,HIGH);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,LOW);
  digitalWrite(D4,HIGH);
}
void DIGIT_4()
{
  digitalWrite(D1,HIGH);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,HIGH);
  digitalWrite(D4,LOW);
}
