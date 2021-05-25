// Version 0.0.1
// @author Ainsel

#include <Arduino.h>

#include "Wire.h"
#include "RTClib.h"
#include "Adafruit_NeoPixel.h"
#include "JC_Button.h"

#include "Azmuth.h"
#include "Modes.h"

int scroller();

//========Pin Definitions=========
const byte RING_PIN = 6;
const byte LED_COUNT = 12;
const byte MAIN_BUTTON_PIN = 12;
const byte LEFT_BUTTON_PIN = 11;
const byte RIGHT_BUTTON_PIN = 10;
const byte MODE_COUNT = 3;

Adafruit_NeoPixel ring(LED_COUNT, RING_PIN);

Button buttonMain(MAIN_BUTTON_PIN, 25, true, false); //Defining a Button object for the main "activation" button. Params: Pin to read from, debounce time = 25ms, deactivate internal pullup resistor, and consider a HIGH state as active.
Button buttonRight(RIGHT_BUTTON_PIN, 25, false, false);
Button buttonLeft(LEFT_BUTTON_PIN, 25, false, false);

void (*Modes[MODE_COUNT])() = {showTime, flashlight, antiAnxiety}; //Each mode for the watch is defined in a function; this array contains pointers to each of them, allowing them to be called by index like this: Modes[i]()


/*This function handles the control buttons.*/
int scroller() {
  int counter = 0;
  unsigned long time;
  unsigned long timeLeft = millis() + 2000;
  time = millis();
  while (time < timeLeft){
    // buttonMain.read();
    buttonLeft.read();
    buttonRight.read();
      if (buttonLeft.wasPressed()) { //Checking if either of the side buttons were pressed
        counter++;
        ring.setPixelColor((counter % LED_COUNT) -1 , 0, 128, 0);
        ring.show();
        timeLeft = millis()+2000;
      }
/*Note for future me: Buttons are wired properly and function in basic loop(); problem isolated to within the scroller() function*/
      else if (buttonRight.wasPressed()) {
        ring.setPixelColor((counter % LED_COUNT)-1, 0, 0, 0);
        counter--;
        Serial.print("[Scroller] counter = ");
        Serial.println(counter);
        Serial.println("[Scroller] counter mod = ");
        Serial.println(counter % MODE_COUNT);
        ring.show();
        timeLeft = millis()+2000;
      }
      else  {
        time = millis();
      }
  }
  ring.clear();
  ring.show();
  return counter % MODE_COUNT;
}

void setup() {
  pinMode(RING_PIN, OUTPUT);

  buttonMain.begin();
  buttonRight.begin();
  buttonLeft.begin();
  Serial.begin(9600);
  rtc.begin();
  ring.begin();
  ring.show();

}


void loop() {
  //Incrementing the buttons states
  buttonMain.read();
  buttonRight.read();
  buttonLeft.read();
  if(buttonMain.wasPressed()){
    ring.setPixelColor(0, 0, 128, 0); //debugging; set top pixel to green
    ring.show();
    int counter = scroller();
    Modes[counter](); //Using the int returned from scroller() as the index for the array of modes to choose which one to activate
    ring.clear();
    ring.show();
  }
}

//made with caffeine and stubbornness
