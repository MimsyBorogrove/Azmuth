// //Concepts to be implemented into the watch at some time in the future.


// //Flashlight; glow as bright as possible for 5 seconds
// void flashlight() {
//   ring.clear();
//   ring.fill(Adafruit_NeoPixel::Color(255, 255, 255));
//   ring.show();
//   delay(5000);
//   ring.clear();
//   ring.show();
// }

// //Anti-anxiety breathing pacer;
// void antiAnxiety() {
//   int timer = 0;
//   for (int i = 0; i < sizeof(leds); i++) { //fill the ring with indigo light over 4 seconds (breathe in during this)
//     ring.setPixelColor(leds[i], 75, 0, 130);
//     ring.show();
//     delay(50);//4000/(sizeof(leds)*1000)); //quick maffs
//   }
//   //  for(float i=0; i< 8; i+=0.1){        //hold your breath as the light shifts from purple to green
//   //    ring.fill();
//   //  }
//   ring.clear();
//   ring.show();

// }


// int scroller() {
//   //----State Detection------
//   int bUState = digitalRead(RIGHT_BUTTON_PIN);
//   int bDState = digitalRead(LEFT_BUTTON_PIN);
//   int bUStateL; // "L" for "Last"
//   int bDStateL;
  

//   int counter = 0;
//   int timeLeft = millis() + 2000;
//   while (millis() <= timeLeft) {                  //Once the scroll function is run, wait 2 seconds after the button is pressed to invoke the indexed function
//     bUState = digitalRead(RIGHT_BUTTON_PIN);
//     bDState = digitalRead(LEFT_BUTTON_PIN);
//     if (bUState != bUStateL) {
//       counter++;
//       ring.setPixelColor((counter - 1), 0, 128, 0); //set indexed pixel to green
//       ring.show();
//       timeLeft = millis() + 2000; //if the button is pressed again, reset the 2-second counter and start again
//       bUState = digitalRead(RIGHT_BUTTON_PIN);
//       //      break;
//     }
//     else if (bDState != bDStateL) { //same logic as above
//       counter--;
//       ring.setPixelColor((counter - 1), 0, 0, 0); //turn indexed pixel off
//       ring.show();
//       timeLeft = millis() + 2000;
//       bDState = digitalRead(LEFT_BUTTON_PIN);
//       //      break;
//     }
//     //more state detection
//     bUStateL = bUState;
//     bDStateL = bDState;
//   }
//   ring.clear();
//   ring.show();
//   return counter;
// }


// //while(millis() <= millis()+5000)
