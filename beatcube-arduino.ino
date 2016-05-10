#include "cubeplex.h"

String inputString = "";        
boolean stringComplete = false;

const int cubeSides = 4;
int color = random(red, white);

void setup() {
  Serial.begin(9600);
  inputString.reserve(200);
  initCube();
}

void loop() { 
  if (stringComplete) {
    Serial.println(inputString);
    drawBeat(inputString);
    resetBuffer();
    inputString = "";
    stringComplete = false;
  }
}

void drawBeat(String inputString) {
  int height = inputString[0] - '0';

  if (height == cubeSides) {
     color = random(red, white);
  }

  for (int xpos = 0; xpos < cubeSides; xpos++) {
    for (int ypos = 0; ypos < cubeSides; ypos++) {
      for (int zpos = 0; zpos < height; zpos++) {
          drawLed(color, xpos, ypos, zpos);
      }
    }
  }
}

void resetBuffer() {
  flushBuffer();
  clearBuffer();
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

