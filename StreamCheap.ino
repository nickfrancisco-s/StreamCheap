/*
 *  Project     'Stream Cheap' Mini Macro Keyboard
 *  @author     David Madison
 * 	@modified by Nick Francisco
 *  @link       partsnotincluded.com/electronics/diy-stream-deck-mini-macro-keyboard
 *  @license    MIT - Copyright (c) 2018 David Madison
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

// ---------------------------------
// Key definitions
#define BUTTON_KEY1 KEY_F13
#define BUTTON_KEY2 KEY_F14
#define BUTTON_KEY3 KEY_F15
#define BUTTON_KEY4 KEY_F16
#define BUTTON_KEY5 KEY_F17
#define BUTTON_KEY6 KEY_F18
#define BUTTON_KEY7 KEY_F19
#define BUTTON_KEY8 KEY_F20

// Pin definitions
#define BUTTON_PIN1 2
#define BUTTON_PIN2 3
#define BUTTON_PIN3 4
#define BUTTON_PIN4 5
#define BUTTON_PIN5 6
#define BUTTON_PIN6 7
#define BUTTON_PIN7 8
#define BUTTON_PIN8 9
#define LED_PIN 10
#define LED_PIN2 16
// ---------------------------------

#include "Keyboard.h"

int mode = 0;


//EDIT THESE TO MOD your shortcuts
//mODE 0
#define MODE0_BUTTON1 "/giphy facepalm"
#define MODE0_BUTTON2 "/giphy nod"
#define MODE0_BUTTON3 "/giphy bear"
#define MODE0_BUTTON4 "/giphy ainsley spicy"
#define MODE0_BUTTON5 "Ranks!"
#define MODE0_BUTTON6 "Shabba!"
#define MODE0_BUTTON7 "/giphy title of your sex tape"


//mode 1
#define MODE1_BUTTON1 "docker "
#define MODE1_BUTTON2 "ssh "
#define MODE1_BUTTON3 "agent-coleman"
#define MODE1_BUTTON4 "agent-o"
#define MODE1_BUTTON5 "agent-makepeace"
#define MODE1_BUTTON6 "password1"
#define MODE1_BUTTON7 "password2"


//Mode2
#define MODE2_BUTTON1 "docker "
#define MODE2_BUTTON2 "ssh "
#define MODE2_BUTTON3 "agent-coleman"
#define MODE2_BUTTON4 "agent-o"
#define MODE2_BUTTON5 "agent-makepeace"
#define MODE2_BUTTON6 "password1"
#define MODE2_BUTTON7 "password2"

//end of shortcut mod section

//Mode 3 shortcuts are for function keys. 
#define MODE3_BUTTON1 KEY_F13
#define MODE3_BUTTON2 KEY_F14
#define MODE3_BUTTON3 KEY_F15
#define MODE3_BUTTON4 KEY_F16
#define MODE3_BUTTON5 KEY_F17
#define MODE3_BUTTON6 KEY_F18
#define MODE3_BUTTON7 KEY_F19


char *ButtonDef1[] =  {MODE0_BUTTON1, MODE0_BUTTON2, MODE0_BUTTON3,MODE0_BUTTON4, MODE0_BUTTON5, MODE0_BUTTON6, MODE0_BUTTON7};
char *ButtonDef2[] =  {MODE1_BUTTON1, MODE1_BUTTON2, MODE1_BUTTON3,MODE1_BUTTON4, MODE1_BUTTON5, MODE1_BUTTON6, MODE1_BUTTON7};
char *ButtonDef3[] =  {MODE2_BUTTON1, MODE2_BUTTON2, MODE2_BUTTON3,MODE2_BUTTON4, MODE2_BUTTON5, MODE2_BUTTON6, MODE2_BUTTON7};
char *ButtonDef4[] =  {MODE3_BUTTON1, MODE3_BUTTON2, MODE3_BUTTON3,MODE3_BUTTON4, MODE3_BUTTON5, MODE3_BUTTON6, MODE3_BUTTON7};

const uint8_t SigLedPin1 = LED_PIN;
const uint8_t SigLedPin2 = LED_PIN2;
const uint8_t LED_DUTY_CYCLE = 15;
const uint8_t LED_DUTY_CYCLE2 = 130;

void toggleMode()
  { 
    mode++;

    if(mode ==4)
    {
      mode = 0;
    }
     
    //decide on mode light combii  
    if(mode==0)
    {
    //digitalWrite(SigLedPin1, LOW);
    //digitalWrite(SigLedPin2, LOW);
		analogWrite(SigLedPin1, 0);
		analogWrite(SigLedPin2, 0);
    }
    else if(mode == 1)
    {
      //digitalWrite(SigLedPin1, HIGH);
      //digitalWrite(SigLedPin2, LOW);	  
	  analogWrite(SigLedPin1, LED_DUTY_CYCLE);
	  analogWrite(SigLedPin2, 0);
    }
    else if(mode == 2)
    {
      //digitalWrite(SigLedPin1, LOW);
      //digitalWrite(SigLedPin2, HIGH);	 
		analogWrite(SigLedPin1, 0);
		analogWrite(SigLedPin2, LED_DUTY_CYCLE2);	  
    }    
    else if(mode == 3)
    {
      //digitalWrite(SigLedPin1, HIGH);
      //digitalWrite(SigLedPin2, HIGH);	
		analogWrite(SigLedPin1, LED_DUTY_CYCLE);
		analogWrite(SigLedPin2, LED_DUTY_CYCLE2);	  
    }   
  }

// Button helper class for handling press/release and debouncing
class button {
  public:
  const char key;
  const uint8_t pin;
  
  button(uint8_t k, uint8_t p) : key(k), pin(p){}

  void Act(int PinNumber,boolean State)
  {
    int BtnIndex = PinNumber - 2;
       if(State)
          {            
             if(mode==0)
             { 
				Keyboard.print(ButtonDef1[BtnIndex]);				
             }
             else if(mode ==1)
             {              
                Keyboard.print(ButtonDef2[BtnIndex]);
				
             }
             else if(mode ==2)
             {
                 Keyboard.print(ButtonDef3[BtnIndex]);
             }
             else if(mode ==3)
             {
                //FunctionS              
                if(State)
                {
                    Keyboard.press(ButtonDef4[BtnIndex]);
                }
                else
                {
                    Keyboard.release(ButtonDef4[BtnIndex]);
                }                           
             }  
			 
             delay(250);    
          }         
  }

  void press(boolean state){
    if(state == pressed || (millis() - lastPressed  <= debounceTime)){
      return; // Nothing to see here, folks
    }

    lastPressed = millis();

    if(pin==9){

         if(state)
          {
            toggleMode();       
          } 
          delay(250);                     
      }
      else {        
              Act(pin,state);  
      }    
      
      pressed = state;
  }
  
  void update(){
      press(!digitalRead(pin));    
  }

  private:
  const long debounceTime = 30;
  unsigned long lastPressed;
  boolean pressed = 0;
} ;

// Button objects, organized in array
button buttons[] = {
  {BUTTON_KEY1, BUTTON_PIN1},
  {BUTTON_KEY2, BUTTON_PIN2},
  {BUTTON_KEY3, BUTTON_PIN3},
  {BUTTON_KEY4, BUTTON_PIN4},
  {BUTTON_KEY5, BUTTON_PIN5},
  {BUTTON_KEY6, BUTTON_PIN6},
  {BUTTON_KEY7, BUTTON_PIN7},
  {BUTTON_KEY8, BUTTON_PIN8},
};


const uint8_t NumButtons = sizeof(buttons) / sizeof(button);
const uint8_t ledPin = 17;



void setup() { 
  // Safety check. Ground pin #1 (RX) to cancel keyboard inputs.
  pinMode(1, INPUT_PULLUP);
  if(!digitalRead(1)){
    failsafe();
  }

  // Set LEDs Off. Active low.
  pinMode(ledPin, OUTPUT);
  pinMode(SigLedPin1, OUTPUT);
  pinMode(SigLedPin2, OUTPUT);

  digitalWrite(ledPin, HIGH);
  digitalWrite(SigLedPin1, LOW); 
  digitalWrite(SigLedPin2, LOW); 
  
  TXLED0;

  for(int i = 0; i < NumButtons; i++){
    pinMode(buttons[i].pin, INPUT_PULLUP);
  }
}

void loop() {
  for(int i = 0; i < NumButtons; i++){
    buttons[i].update();
  }
}

void failsafe(){
  for(;;){} // Just going to hang out here for awhile :D
}
