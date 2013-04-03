// UTFT_Demo_400x240 (C)2012 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// This program is a demo of how to use most of the functions
// of the library with a supported display modules.
//
// This demo was made for modules with a screen resolution 
// of 400x240 pixels.
//
// This program requires the UTFT library.
//

#include <UTFT.h>
#include <Adafruit_BMP085.h>
#include <Wire.h>
//
// Declare which fonts we will be using
extern uint8_t SmallFont[];

// Uncomment the next line for Arduino 2009/Uno
//UTFT myGLCD(TFT01_32,19,18,17,16);   // Remember to change the model parameter to suit your display module!

// Uncomment the next line for Arduino Mega
UTFT myGLCD(TFT01_32WD,38,39,40,41);   // Remember to change the model parameter to suit your display module!
int counter = 0;

Adafruit_BMP085 bmp;

void setup()
{
  randomSeed(analogRead(0));
  
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  
  
    myGLCD.clrScr();

  myGLCD.setColor(255, 255, 255);

  myGLCD.print("Hello World !!!", CENTER, 100);
  
  if (!bmp.begin()) {
    
      myGLCD.print("Could not find a valid BMP085 sensor2", CENTER, 150);
 
  
	 
	while (1) {}
  }
  
  
}

void loop()
{
  counter = counter + 1;
  myGLCD.setColor(255, 255, 255);
  myGLCD.printNumF(bmp.readPressure()/100, 2, CENTER, 120);
  delay(1000);

 
}

