#include <Joystick.h>
#include "Nintendo.h"

CGamecubeConsole GamecubeConsole(A5);
Gamecube_Data_t d = defaultGamecubeData;

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  14, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  true, true, false,   // Rx, Ry, no Rz
  false, true,          // No rudder, throttle
  false, false, false);  // No accelerator, no brake, no steering

enum game
{
  Melee,
  PM,
  Ultimate
};

enum device
{
	GC,
	PC
};

enum SOCD
{
  Neutral,
  TwoIP,
  TwoIPNoReactivate
};

bool isLeft = false;
bool isRight = true;
bool isUp = false;
bool isDown = true;
bool isHoldingLeft = false;
bool isHoldingRight = false;
bool isHoldingUp = false;
bool isHoldingDown = false;

game currentGame = Melee;
device currentDevice = GC;
SOCD currentSOCD = TwoIPNoReactivate;

const int L = 16;
const int LEFT = 1;
const int DOWN = 0;
const int RIGHT = 4;
const int MOD1 = 5;
const int MOD2 = 6;

const int START = 7;
const int B = A2;
const int X = A1;
const int Z = A0;
const int UP = 13;
const int R = A4;
const int Y = A3;

const int CDOWN = 12;
const int A = 15;
const int CRIGHT = 14;
const int CLEFT = 9;
const int CUP = 8;

const int EXTRA1 = 11;
const int EXTRA2 = 10;

void setup() {
  Serial.begin(115200);
  Joystick.begin();
  Joystick.setXAxisRange(0, 255);
  Joystick.setYAxisRange(0, 255);
  Joystick.setRxAxisRange(0, 255);
  Joystick.setRyAxisRange(0, 255);
  Joystick.setThrottleRange(0, 255);

  pinMode(L, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
  pinMode(MOD1, INPUT_PULLUP);
  pinMode(MOD2, INPUT_PULLUP);

  pinMode(START, INPUT_PULLUP);
  pinMode(B, INPUT_PULLUP);
  pinMode(X, INPUT_PULLUP);
  pinMode(Z, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  pinMode(R, INPUT_PULLUP);
  pinMode(Y, INPUT_PULLUP);

  pinMode(CDOWN, INPUT_PULLUP);
  pinMode(A, INPUT_PULLUP);
  pinMode(CRIGHT, INPUT_PULLUP);
  pinMode(CLEFT, INPUT_PULLUP);
  pinMode(CUP, INPUT_PULLUP);

  pinMode(EXTRA1, INPUT_PULLUP);
  pinMode(EXTRA2, INPUT_PULLUP);

  if (digitalRead(CDOWN) == LOW)
  {
	  currentDevice = PC;
  }

  if (digitalRead(B) == LOW)
  {
    currentGame = Ultimate;
    currentSOCD = TwoIP;
  }
  if (digitalRead(X) == LOW)
  {
    currentGame = PM;
    currentSOCD = TwoIPNoReactivate;
  }
}

void loop()
{
  //This resets and establishes all the values after the controller sends them to the console and helps with initial "zeroing"
  int pinA = 0;
  int pinB = 0;
  int pinX = 0;
  int pinY = 0;
  int pinZ = 0;
  int pinSTART = 0;

  int pinEXTRA1 = 0;
  int pinEXTRA2 = 0;

  int pinR = 0;
  int pinL = 0;
  int pinRLight = 0;
  int pinLLight = 0;

  int pinDLEFT = 0;
  int pinDRIGHT = 0;
  int pinDUP = 0;
  int pinDDOWN = 0;

  int mod1 = 0;
  int mod2 = 0;

  int pinCLEFT = 0;
  int pinCRIGHT = 0;
  int pinCUP = 0;
  int pinCDOWN = 0;

  int pinxAxisC = 128;
  int pinyAxisC = 128;

  int pinxAxis = 128;
  int xmod = 0;
  int pinyAxis = 128;

  int rightOne = 0;
  int leftOne = 0;
  int downOne = 0;
  int upOne = 0;

  int cUp = 0;
  int cDown = 0;
  int cLeft = 0;
  int cRight = 0;

  if (digitalRead(MOD1) == LOW && digitalRead(MOD2) == HIGH)mod1 = 1;
  if (digitalRead(MOD2) == LOW && digitalRead(MOD1) == HIGH)mod2 = 1;

  //SOCD method for left/right is 2ip without reactivation
  if (currentSOCD == TwoIPNoReactivate)
  {
    // X Axis
    if (digitalRead(LEFT) == LOW && isRight == true)
    {
  	//if left is pressed and isRight is true(if you press left while holding right):
  		pinxAxis = 128-127;
  		leftOne = 1;
  		isHoldingRight = true;
    }
    else if (digitalRead(RIGHT) == LOW && isLeft == true)
    {
  	//else, if right is pressed and isLeft is true (if you press right while holding left):
  		pinxAxis = 128+127;
  		rightOne = 1;
  		isHoldingLeft = true;
    }

    if (digitalRead(LEFT) == HIGH && digitalRead(RIGHT) == LOW){
  	//if left is not pressed and right is pressed:
  	if(isHoldingRight == false){
  		pinxAxis = 128+127;
  		rightOne = 1;
  	}
      isRight = true;
      isLeft = false;
  	isHoldingLeft = false;
    }
    if (digitalRead(LEFT) == LOW && digitalRead(RIGHT) == HIGH){
  	//if left is pressed and right is not pressed:
  	if(isHoldingLeft == false){
  		pinxAxis = 128-127;
  		leftOne = 1;
  	}
      isLeft = true;
      isRight = false;
  	isHoldingRight = false;
    }
    if (digitalRead(LEFT) == HIGH && digitalRead(RIGHT) == HIGH){
  	  //if neither button is being pressed, set all left/right booleans to false
  	  isHoldingLeft = false;
  	  isHoldingRight = false;
  	  isLeft = false;
  	  isRight = false;
    }
    /*************************************/
    // Y Axis
    if (digitalRead(DOWN) == LOW && isUp == true)
    {
  	//if down is pressed and isUp is true(if you press down while holding up):
  		pinyAxis = 128-127;
  		downOne = 1;
  		isHoldingUp = true;
    }
    else if (digitalRead(UP) == LOW && isDown == true)
    {
  	//else, if up is pressed and isDown is true (if you press up while holding down):
  		pinyAxis = 128+127;
  		upOne = 1;
  		isHoldingDown = true;
    }

    if (digitalRead(DOWN) == HIGH && digitalRead(UP) == LOW){
  	//if down is not pressed and up is pressed:
  	if(isHoldingUp == false){
  		pinyAxis = 128+127;
  		upOne = 1;
  	}
      isUp = true;
      isDown = false;
  	isHoldingDown = false;
    }
    if (digitalRead(DOWN) == LOW && digitalRead(UP) == HIGH){
  	//if down is pressed and up is not pressed:
  	if(isHoldingDown == false){
  		pinyAxis = 128-127;
  		downOne = 1;
  	}
      isDown = true;
      isUp = false;
  	isHoldingUp = false;
    }
    if (digitalRead(DOWN) == HIGH && digitalRead(UP) == HIGH){
  	  //if neither button is being pressed, set all down/up booleans to false
  	  isHoldingDown = false;
  	  isHoldingUp = false;
  	  isDown = false;
  	  isUp = false;
    }
  }

  //SOCD method for left/right is 2ip
  if (currentSOCD == TwoIP)
  {
    // X Axis
    if (digitalRead(LEFT) == LOW && isRight == true)
    {
      pinxAxis = 128-127;
      leftOne = 1;
    }
    else if (digitalRead(RIGHT) == LOW && isLeft == true)
    {
      pinxAxis = 128+127;
      rightOne = 1;
    }

    if (digitalRead(LEFT) == HIGH && digitalRead(RIGHT) == LOW){
      pinxAxis = 128+127;
      rightOne = 1;
      isRight = true;
      isLeft = false;
    }
    if (digitalRead(LEFT) == LOW && digitalRead(RIGHT) == HIGH){
      pinxAxis = 128-127;
      leftOne = 1;
      isLeft = true;
      isRight = false;
    }

    /*************************************/
    // Y Axis
    if (digitalRead(DOWN) == LOW && isUp == true)
    {
      pinyAxis = 128-127;
      downOne = 1;
    }
    else if (digitalRead(UP) == LOW && isDown == true)
    {
      pinyAxis = 128+127;
      upOne = 1;
    }

    if (digitalRead(DOWN) == HIGH && digitalRead(UP) == LOW){
      pinyAxis = 128+127;
      upOne = 1;
      isUp = true;
      isDown = false;
    }
    if (digitalRead(DOWN) == LOW && digitalRead(UP) == HIGH){
      pinyAxis = 128-127;
      downOne = 1;
      isDown = true;
      isUp = false;
    }
  }

  //SOCD method for left/right is neutral
  if (currentSOCD == Neutral)
  {
    if (digitalRead(LEFT) == HIGH && digitalRead(RIGHT) == LOW){
      pinxAxis = 128+127;
      rightOne = 1;
    }
    if (digitalRead(LEFT) == LOW && digitalRead(RIGHT) == HIGH){
      pinxAxis = 128-127;
      leftOne = 1;
    }
    if (digitalRead(DOWN) == HIGH && digitalRead(UP) == LOW){
      pinyAxis = 128+127;
      upOne = 1;
    }
    if (digitalRead(DOWN) == LOW && digitalRead(UP) == HIGH){
      pinyAxis = 128-127;
      downOne = 1;
    }
  }

    //Reads CStick pins, same logic as controlstick values.
  if (digitalRead(CLEFT) == HIGH && digitalRead(CRIGHT) == LOW){
    pinxAxisC = 255;
    cRight = 1;
  }
  if (digitalRead(CLEFT) == LOW && digitalRead(CRIGHT) == HIGH){
    pinxAxisC = 0;
    cLeft = 1;
  }
  if (digitalRead(CDOWN) == HIGH && digitalRead(CUP) == LOW){
    pinyAxisC = 255;
    cUp = 1;
  }
  if (digitalRead(CDOWN) == LOW && digitalRead(CUP) == HIGH){
    pinyAxisC = 0;
    cDown = 1;
  }

  if (digitalRead(A) == LOW)pinA = 1;
  if (digitalRead(B) == LOW)pinB = 1;
  if (digitalRead(X) == LOW)pinX = 1;
  if (digitalRead(Y) == LOW)pinY = 1;
  if (digitalRead(Z) == LOW)pinZ = 1;
  if (digitalRead(START) == LOW)pinSTART = 1;
  if (digitalRead(EXTRA1) == LOW)pinEXTRA1 = 1;
  if (digitalRead(EXTRA2) == LOW)pinEXTRA2 = 1;



  //This is for digital shield.
  //[Crane] Also does a bit of analog shield for Smash4 and Ultimate
  if (digitalRead(R) == LOW) {
    pinR = 1;
    pinRLight = 125;
  }
  if (digitalRead(L) == LOW) {
    pinL = 1;
    pinLLight = 125;
  }

  if (currentGame == Melee)
  {
    if(mod1){
    if(leftOne || rightOne){
      pinxAxis = 128 + ((rightOne - leftOne)*59);
    }
    if(upOne || downOne){
      pinyAxis = 128 + ((upOne - downOne)*52);
    }
    if((leftOne || rightOne) && (upOne || downOne)){
      pinxAxis = 128 + ((rightOne - leftOne)*59);
      pinyAxis = 128 + ((upOne - downOne)*23);
    }
    //Ambiguous DI
    if((leftOne || rightOne) && pinA){
      pinxAxis = 128 + ((rightOne - leftOne)*47);
    }
    //FireFox Angles with cButtons
    if(cUp && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*53);
      pinyAxis = 128 + ((upOne - downOne)*37);
    }
    if(cDown && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*62);
      pinyAxis = 128 + ((upOne - downOne)*30);
    }
    if(cLeft && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*63);
      pinyAxis = 128 + ((upOne - downOne)*37);
    }
    if(cRight && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*51);
      pinyAxis = 128 + ((upOne - downOne)*42);
    }
    //Up and Down Forward Smash
    if((upOne||downOne)&&(cLeft||cRight)){
      pinxAxisC = 128 + ((cRight - cLeft)*127);
      pinyAxisC = 128 + ((upOne - downOne)*41);
    }
  }

  if(mod2){
    if(leftOne || rightOne){
      pinxAxis = 128 + ((rightOne - leftOne)*23);
    }
    if(upOne || downOne){
      pinyAxis = 128 + ((upOne - downOne)*59);
    }
    //Keeps B Reversals Fair
    if((leftOne || rightOne) && pinB){
      pinxAxis = 128 + ((rightOne - leftOne)*59);
    }
    if((leftOne || rightOne) && (upOne || downOne)){
      pinxAxis = 128 + ((rightOne - leftOne)*23);
      pinyAxis = 128 + ((upOne - downOne)*59);
    }

    //Ambiguous DI
    if((leftOne || rightOne) && pinA){
      pinxAxis = 128 + ((rightOne - leftOne)*35);
    }
    //FireFox Angles with cButtons
    if(cUp && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*44);
      pinyAxis = 128 + ((upOne - downOne)*63);
    }
    if(cDown && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*31);
      pinyAxis = 128 + ((upOne - downOne)*64);
    }
    if(cLeft && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*37);
      pinyAxis = 128 + ((upOne - downOne)*63);
    }
    if(cRight && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*47);
      pinyAxis = 128 + ((upOne - downOne)*57);
    }
  }
  }
  else if (currentGame == Ultimate)
  {
  if(mod1){
    if(leftOne || rightOne){
      pinxAxis = 128 + ((rightOne - leftOne)*53);
    }
    if(upOne || downOne){
      pinyAxis = 128 + ((upOne - downOne)*51);
    }

/******************/

    if((leftOne || rightOne) && pinB){
      pinxAxis = 128 + ((rightOne - leftOne)*41);
    }

/*******************/

    if((leftOne || rightOne) && (upOne || downOne)){
      pinxAxis = 128 + ((rightOne - leftOne)*53);
      pinyAxis = 128 + ((upOne - downOne)*40);
    }
    //Ambiguous DI
    if((leftOne || rightOne) && pinA){
      pinxAxis = 128 + ((rightOne - leftOne)*47);
    }
    //FireFox Angles with cButtons
    if(cUp && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*71);
      pinyAxis = 128 + ((upOne - downOne)*35);
      pinxAxisC = 128;
      pinyAxisC = 128;
    }
    if(cDown && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*61);
      pinyAxis = 128 + ((upOne - downOne)*49);
      pinxAxisC = 128;
      pinyAxisC = 128;
    }
    if(cLeft && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*66);
      pinyAxis = 128 + ((upOne - downOne)*42);
      pinxAxisC = 128;
      pinyAxisC = 128;
    }
    if(cRight && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*75);
      pinyAxis = 128 + ((upOne - downOne)*27);
      pinxAxisC = 128;
      pinyAxisC = 128;
    }
    //Up and Down Forward Smash
    if((upOne||downOne)&&(cLeft||cRight)){
      pinxAxisC = 128 + ((cRight - cLeft)*65);
      pinyAxisC = 128 + 40;
    }
  }

  if(mod2){
    if(leftOne || rightOne){
      pinxAxis = 128 + ((rightOne - leftOne)*26);
    }
    if(upOne || downOne){
      pinyAxis = 128 + ((upOne - downOne)*51);
    }
    //Keeps B Reversals Fair
    if((leftOne || rightOne) && pinB){
      pinxAxis = 128 + ((rightOne - leftOne)*41);
    }

    if((leftOne || rightOne) && (upOne || downOne)){
      pinxAxis = 128 + ((rightOne - leftOne)*40);
      pinyAxis = 128 + ((upOne - downOne)*68);
    }

    //Ambiguous DI
    if((leftOne || rightOne) && pinA){
      pinxAxis = 128 + ((rightOne - leftOne)*35);
    }
    //FireFox Angles with cButtons
    if(cUp && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*35);
      pinyAxis = 128 + ((upOne - downOne)*71);
      pinxAxisC = 128;
      pinyAxisC = 128;
    }
    if(cDown && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*49);
      pinyAxis = 128 + ((upOne - downOne)*61);
      pinxAxisC = 128;
      pinyAxisC = 128;
    }
    if(cLeft && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*42);
      pinyAxis = 128 + ((upOne - downOne)*66);
      pinxAxisC = 128;
      pinyAxisC = 128;
    }
    if(cRight && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*27);
      pinyAxis = 128 + ((upOne - downOne)*75);
      pinxAxisC = 128;
      pinyAxisC = 128;
    }
    //Up and Down Forward Smash
    if((upOne||downOne)&&(cLeft||cRight)){
      pinxAxisC = 128 + ((cRight - cLeft)*65);
      pinyAxisC = 128 - 40;
    }

  }
  }
  else if (currentGame == PM)
  {
  if(mod1){
    if(leftOne || rightOne){
      pinxAxis = 128 + ((rightOne - leftOne)*49);
    }
    if(upOne || downOne){
      pinyAxis = 128 + ((upOne - downOne)*65);
    }
    if((leftOne || rightOne) && (upOne || downOne)){
      pinxAxis = 128 + ((rightOne - leftOne)*68);
      pinyAxis = 128 + ((upOne - downOne)*28);
    }
    //Ambiguous DI
    if((leftOne || rightOne) && pinA){
      pinxAxis = 128 + ((rightOne - leftOne)*47);
    }
    //FireFox Angles with cButtons
    if(cUp && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*53);
      pinyAxis = 128 + ((upOne - downOne)*37);
      pinxAxisC = 128;
      pinyAxisC = 128;
    }
    if(cDown && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*62);
      pinyAxis = 128 + ((upOne - downOne)*30);
      pinxAxisC = 128;
      pinyAxisC = 128;
    }
    if(cLeft && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*63);
      pinyAxis = 128 + ((upOne - downOne)*37);
      pinxAxisC = 128;
      pinyAxisC = 128;
    }
    if(cRight && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*51);
      pinyAxis = 128 + ((upOne - downOne)*42);
      pinxAxisC = 128;
      pinyAxisC = 128;
    }
    //Up and Down Forward Smash
    if((upOne||downOne)&&(cLeft||cRight)){
      pinxAxisC = 128 + ((cRight - cLeft)*127);
      pinyAxisC = 128 + ((upOne - downOne)*41);
    }
  }

  if(mod2){
    if(leftOne || rightOne){
      pinxAxis = 128 + ((rightOne - leftOne)*33);
    }
    if(upOne || downOne){
      pinyAxis = 128 + ((upOne - downOne)*59);
    }
    //Keeps B Reversals Fair
    if((leftOne || rightOne) && pinB){
      pinxAxis = 128 + ((rightOne - leftOne)*59);
    }
    if((leftOne || rightOne) && (upOne || downOne)){
      pinxAxis = 128 + ((rightOne - leftOne)*28);
      pinyAxis = 128 + ((upOne - downOne)*68);
    }

    //Ambiguous DI
    if((leftOne || rightOne) && pinA){
      pinxAxis = 128 + ((rightOne - leftOne)*35);
    }
    //FireFox Angles with cButtons
    if(cUp && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*44);
      pinyAxis = 128 + ((upOne - downOne)*63);
      pinxAxisC = 128;
      pinyAxisC = 128;
    }
    if(cDown && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*31);
      pinyAxis = 128 + ((upOne - downOne)*64);
      pinxAxisC = 128;
      pinyAxisC = 128;
    }
    if(cLeft && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*37);
      pinyAxis = 128 + ((upOne - downOne)*63);
      pinxAxisC = 128;
      pinyAxisC = 128;
    }
    if(cRight && ((leftOne ||rightOne) && (upOne || downOne))){
      pinxAxis = 128 + ((rightOne - leftOne)*47);
      pinyAxis = 128 + ((upOne - downOne)*57);
      pinxAxisC = 128;
      pinyAxisC = 128;
    }
  }
  }


  if(pinL){

    if(rightOne||leftOne){
      pinxAxis = 128 + ((rightOne - leftOne)*127);
    }
    if (upOne||downOne){
      pinyAxis = 128 + ((upOne - downOne)*127);
    }

    if(upOne && (leftOne || rightOne)){
      pinxAxis = 128 + ((rightOne - leftOne)*52);
      pinyAxis = 128 + 52;
    }

    //Axe Method Shield Drop
    if (currentGame == Melee)
    {
      if(downOne && (leftOne || rightOne)){
        pinxAxis = 128 + ((rightOne - leftOne)*96);
        pinyAxis = 128 - 91;
      }
    }
    else
    {
      if(downOne && (leftOne || rightOne)){
        pinxAxis = 128 + ((rightOne - leftOne)*96);
        pinyAxis = 128 - 99;
      }
    }

    if(mod1){
      pinLLight = 80;
      pinL = 0;
    }
    if(mod2){
      pinLLight = 80;
      pinL = 0;
    }

    //Wavedash with L and Mod1
    if(((leftOne || rightOne) && downOne)&& mod1){
      if (currentGame == Melee)
      {
        pinxAxis = 128 + ((rightOne - leftOne)*110);
        pinyAxis = 128 - 65;
      }
      if (currentGame == Ultimate)
      {
        pinxAxis = 128 + ((rightOne - leftOne)*110);
        pinyAxis = 128 - 65;
      }
      if (currentGame == PM)
      {
        pinxAxis = 128 + ((rightOne - leftOne)*110);
        pinyAxis = 128 - 65;
      }
    }
    //Wavedash with L and Mod2
    if(((leftOne || rightOne) && downOne)&& mod2){
      pinxAxis = 128 + ((rightOne - leftOne)*65);
      pinyAxis = 128 - 110;
    }
  }

  //Manual Shield Tilt with R
  if(pinR){

    if(currentGame == Ultimate)
    {
      if(downOne || upOne){
        pinyAxis = 128 + ((upOne - downOne)*51);
      }
      if(leftOne || rightOne){
        pinxAxis = 128 + ((rightOne - leftOne)*51);
      }
      if((leftOne || rightOne) && (downOne || upOne)){
        pinxAxis = 128 + ((rightOne - leftOne)*51);
        pinyAxis = 128 + ((upOne - downOne)*51);
      }
    }
    else
    {
      if(downOne || upOne){
        pinyAxis = 128 + ((upOne - downOne)*52);
      }
      if(leftOne || rightOne){
        pinxAxis = 128 + ((rightOne - leftOne)*55);
      }
      if((leftOne || rightOne) && (downOne || upOne)){
        pinxAxis = 128 + ((rightOne - leftOne)*52);
        pinyAxis = 128 + ((upOne - downOne)*52);
      }
    }

    //Wavedash with R and Mod1
    if(((leftOne || rightOne) && downOne)&& mod1){
      if (currentGame == Melee)
      {
        pinxAxis = 128 + ((rightOne - leftOne)*110);
        pinyAxis = 128 - 65;
      }
      if (currentGame == Ultimate)
      {
        pinxAxis = 128 + ((rightOne - leftOne)*110);
        pinyAxis = 128 - 65;
      }
      if (currentGame == PM)
      {
        pinxAxis = 128 + ((rightOne - leftOne)*110);
        pinyAxis = 128 - 65;
      }
    }
    //Wavedash with R and Mod2
    if(((leftOne || rightOne) && downOne)&& mod2){
      pinxAxis = 128 + ((rightOne - leftOne)*65);
      pinyAxis = 128 - 110;
    }
  }


  if(pinZ){
    if(upOne && (leftOne || rightOne)){
      pinxAxis = 128 + ((rightOne - leftOne)*127);
      pinyAxis = 128 + 112;
    }
  }



  //D-Pad
 if(digitalRead(MOD1)==LOW && digitalRead(MOD2)==LOW){
        pinxAxisC = 128;
        pinyAxisC = 128;
      if(digitalRead(CRIGHT)==HIGH && digitalRead(CLEFT)==LOW){
          pinDLEFT=1;
      }
      else if(digitalRead(CUP)==HIGH && digitalRead(CDOWN)==LOW){
          pinDDOWN=1;
      }
      else if(digitalRead(CDOWN)==HIGH  && digitalRead(CUP)==LOW){
         pinDUP=1;
      }
      else if(digitalRead(CLEFT)==HIGH  && digitalRead(CRIGHT)==LOW){
         pinDRIGHT=1;
      }
  }

  if (currentDevice == GC)
  {
    d.report.a = pinA;
    d.report.b = pinB;
    d.report.x = pinX;
    d.report.y = pinY;
    d.report.z = pinZ;
    d.report.start = pinSTART;
    d.report.r = pinR;
    d.report.l = pinL;
    d.report.left = pinLLight;
    d.report.right = pinRLight;
    d.report.xAxis = pinxAxis;
    d.report.yAxis = pinyAxis;
    d.report.cxAxis = pinxAxisC;
    d.report.cyAxis = pinyAxisC;
    d.report.dup = pinDUP;
    d.report.dright = pinDRIGHT;
    d.report.ddown = pinDDOWN;
    d.report.dleft = pinDLEFT;
    //sends the complied data to console when console polls for the input
    GamecubeConsole.write(d);
  }
  else
  {
    Joystick.setButton(0, pinA);
    Joystick.setButton(1, pinB);
    Joystick.setButton(2, pinX);
    Joystick.setButton(3, pinY);
    Joystick.setButton(4, pinZ);
    Joystick.setButton(5, pinL);
    Joystick.setButton(6, pinR);
    Joystick.setButton(7, pinSTART);
    Joystick.setButton(8, pinDLEFT);
    Joystick.setButton(9, pinDUP);
    Joystick.setButton(10, pinDRIGHT);
    Joystick.setButton(11, pinDDOWN);
    Joystick.setButton(12, pinEXTRA1);
    Joystick.setButton(13, pinEXTRA2);

    Joystick.setXAxis(pinxAxis);
    Joystick.setYAxis(pinyAxis);
    Joystick.setRxAxis(pinxAxisC);
    Joystick.setRyAxis(pinyAxisC);
    Joystick.setThrottle(pinLLight);
  }
}
