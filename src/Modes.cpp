#include "Modes.h"
#include "Azmuth.h"

/* showTime() : The actual "watch" mode for the watch.
* The LED ring's 12 segments act as an analog watch's increments.
* The LEDcorresponding to the hour turns red, and the minute's turns blue.
* (If both are in the same block,that LED turns purple.)
* */
void showTime() {
  DateTime now = rtc.now();  //Prepare a DateTime object to read the current time from the RTC

  byte minute = int(floor(now.minute() / 5));
  byte hour = int(now.hour() % 12 );

  if (minute == hour) {
    ring.setPixelColor(hour, 128, 0, 128); //If the hour and minute are in the same LED block, set that LED to purple.
  }
  else {
    ring.setPixelColor(minute, 128, 0, 0); //set 5minute LED to red
    ring.setPixelColor(hour, 0, 0 , 128); //set hour LED to blue
  }
  ring.show();

  unsigned long currentTime = millis();
  unsigned long previousTime = currentTime;
  unsigned int interval = 5000;
  while ((currentTime - previousTime >= interval) || (!buttonMain.isPressed())) { //
    currentTime = millis();
  }

  ring.clear(); //clear the display for the next functiosn.
  ring.show();
}


/* flashlight(): Makes all LEDs glow bright white for 5 seconds.
 * */
void flashlight() {
  ring.clear();
  ring.fill(Adafruit_NeoPixel::Color(255, 255, 255));
  ring.show();
  delay(5000);
  ring.clear();
  ring.show();
}


/* antiAnxiety(): A breathing pacer.
 * The display will slowly begin to brighten, stay constant for 5 seconds, and then fade back down for 8.
 * The idea is to sync your breathing to the LEDs, following the 5-7-8 method of calming a panic.
 * TODO: find a better way to activate this mode than having to search for it in the "list".
 * */
void antiAnxiety() {
  for (int i = 0; i < LED_COUNT; i++) { //fill the ring with indigo light over 4 seconds (breathe in during this)
      ring.setPixelColor(i, 75, 0, 130);
      ring.show();
      delay(4000/(LED_COUNT*1000)); //quick maffs
  }
  //  for(float i=0; i< 8; i+=0.1){        //hold your breath as the light shifts from purple to green
  //    ring.fill();
  //  }
  ring.clear();
  ring.show();

}
