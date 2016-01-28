/* IRON MAN SUIT
 *
 *
 */
#include <Adafruit_NeoPixel.h>

// Variable Inits
// LED Ring
byte ringPin = 1;
int spinningLights[6];
int light1;
int light2;
int light3;
int light4;
int light5;
int light6;
byte flipTheFace = 0;

//// Left Glove
//byte leftGloveLEDPin = 0;
//byte leftGloveFlexPin = 0;
//int leftFlexValue;
//int leftLightLevel;

// Right Glove
byte rightGloveLEDPin = 3;
byte rightGloveFlexPin = 11;
int rightFlexValue;
int rightLightLevel;

Adafruit_NeoPixel theRing = Adafruit_NeoPixel(25, ringPin, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel leftGloveLight = Adafruit_NeoPixel(3, leftGloveLEDPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel rightGloveLight = Adafruit_NeoPixel(1, rightGloveLEDPin, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  theRing.begin();
  //  leftGloveLight.begin();
  rightGloveLight.begin();
  startUpSpin();
  rightGloveLight.setPixelColor(0, 150, 0, 0);
  rightGloveLight.show();
  delay(1000);
  //  gloveStartUp();
  theRing.setPixelColor(24, 15, 100, 254);
}

void loop() {
  updateTheReactor(flipTheFace);

  // ******* SECTION 2 ******* \\
  // ******* The Glove ******* \\

  //  // Left Glove
  //  leftFlexValue = analogRead(leftGloveFlexPin);
  //  if (leftFlexValue >= 0) {
  //    leftLightLevel = map(leftFlexValue, 0, 1024, 0, 254); // These values need to be calibrated
  //    flipTheFace = 0;
  //  } else {
  //    flipTheFace = 1;
  //  }

  // Right Glove
  rightFlexValue = analogRead(rightGloveFlexPin);

  Serial.println(rightFlexValue);
  rightLightLevel = map(rightFlexValue, 525, 775, 0, 254);
  rightGloveLight.setPixelColor(0,rightLightLevel,rightLightLevel,rightLightLevel);
  rightGloveLight.show();
//  delay(10);

}

// *********************************************************************************************** \\

void startUpSpin() {
  for (int spin = 0; spin < 5; spin++) {
    for (int pix = 0; pix < 24; pix++) {
      light1 = pix;
      light2 = pix + 1;
      light3 = pix + 2;
      light4 = pix + 3;
      light5 = pix + 4;
      light6 = pix + 5;

      for (int light = 0; light < 6; light++) {
        spinningLights[light] = pix + light;
        if (spinningLights[light] > 23) {
          spinningLights[light] = spinningLights[light] - 24;
        }
      }

      theRing.setPixelColor(spinningLights[0], 0, 0, 0);
      theRing.setPixelColor(spinningLights[1], 10, 10, 10);
      theRing.setPixelColor(spinningLights[2], 45, 45, 45);
      theRing.setPixelColor(spinningLights[3], 90, 90, 90);
      theRing.setPixelColor(spinningLights[4], 120, 120, 120);
      theRing.setPixelColor(spinningLights[5], 254, 254, 254);
      theRing.show();
      delay(50);
    }
  }

  for (int pix = 5; pix < 23; pix++) {
    if (pix >= 23) {
      pix = pix - 23;
    }
    theRing.setPixelColor(pix, 240, 240, 240);
    theRing.show();
    delay(20);
  }
}

// *********************************************************************************************** \\

void updateTheReactor(int flipTheFace) {
  // ******* SECTION 1 ******* \\
  //     The Reactor Ring

  for (int p = 0; p < 24; p++) {
    if (flipTheFace == 0) {
      theRing.setPixelColor(p, random(10), random(50) + 25, random(154) + 100); // different shades of blue?
      //                                                       Maybe try (200,200,250); (150,150,200); etc.
    } else if (flipTheFace == 1) {
      theRing.setPixelColor(p, random(154) + 100, random(50) + 25, random(10));
    }
    theRing.show(); // updates pixels one at a time around the ring.
//    delay(50);
  }

}

// *********************************************************************************************** \\

//void gloveStartUp() {
//  // LEFT GLOVE
//  for (int pix = 0; pix < 3; pix++) {
//    leftGloveLight.setPixelColor(pix, 0, 150, 0);
//    leftGloveLight.show();
//    delay(100);
//    leftGloveLight.setPixelColor(pix, 150, 0, 0);
//    leftGloveLight.show();
//    delay(100);
//  }
//
//  leftGloveLight.setPixelColor(0, 0, 0, 0);
//  leftGloveLight.setPixelColor(1, 0, 0, 0);
//  leftGloveLight.setPixelColor(2, 0, 0, 0);
//  leftGloveLight.show();
//
//  for (int colorVal = 0; colorVal < 255; colorVal++) {
//    for (int pix = 0; pix < 3; pix++) {
//      leftGloveLight.setPixelColor(pix, colorVal, colorVal, colorVal);
//      leftGloveLight.show();
//    }
//  }
//
//  delay(1000);
//
//  for (int colorVal = 254; colorVal >= 0; colorVal--) {
//    for (int pix = 0; pix < 3; pix++) {
//      leftGloveLight.setPixelColor(pix, colorVal, colorVal, colorVal);
//      leftGloveLight.show();
//    }
//  }
//
//  // RIGHT GLOVE
//  for (int pix = 0; pix < 3; pix++) {
//    rightGloveLight.setPixelColor(pix, 0, 150, 0);
//    rightGloveLight.show();
//    delay(100);
//    rightGloveLight.setPixelColor(pix, 150, 0, 0);
//    rightGloveLight.show();
//    delay(100);
//  }
//
//  rightGloveLight.setPixelColor(0, 0, 0, 0);
//  rightGloveLight.setPixelColor(1, 0, 0, 0);
//  rightGloveLight.setPixelColor(2, 0, 0, 0);
//  rightGloveLight.show();
//
//  for (int colorVal = 0; colorVal < 255; colorVal++) {
//    for (int pix = 0; pix < 3; pix++) {
//      rightGloveLight.setPixelColor(pix, colorVal, colorVal, colorVal);
//      rightGloveLight.show();
//    }
//  }
//
//  delay(1000);
//
//  for (int colorVal = 254; colorVal >= 0; colorVal--) {
//    for (int pix = 0; pix < 3; pix++) {
//      rightGloveLight.setPixelColor(pix, colorVal, colorVal, colorVal);
//      rightGloveLight.show();
//    }
//  }
//}

// *********************************************************************************************** \\





