#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN        12

#define NUMPIXELS 2

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB);

#define DELAYVAL 5000 // Time (in milliseconds) to pause between pixels

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear(); // Set all pixel colors to 'off'
  Serial.begin(9600);
  Serial.println("MASTER START");
}

void loop() {

//   for (int i = 0; i < NUMPIXELS; i++)
//   { // For each pixel...
//     pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    
//   }
  
//   pixels.show();   // Send the updated pixel colors to the hardware.
//   Serial.println("pixels.Color(10, 10, 10)");

//   delay(DELAYVAL); // Pause before next pass through loop

//   for (int i = 0; i < NUMPIXELS; i++)
//   { // For each pixel...
//     pixels.setPixelColor(i, pixels.Color(255, 255, 255));
//     pixels.show();   // Send the updated pixel colors to the hardware.
//   }

//  pixels.show();   // Send the updated pixel colors to the hardware.
//   Serial.println("pixels.Color(255, 255, 255));");

  

  for(int v = 0; v <= 255; v++)
  {
    for (int i = 0; i < NUMPIXELS; i++)
    { // For each pixel...
      pixels.setPixelColor(i, pixels.Color(v, v, v));
      Serial.println(v);
      pixels.show();   // Send the updated pixel colors to the hardware.
    }
    delay(100); // Pause before next pass through loop
  }

     for (int i = 0; i < NUMPIXELS; i++)
   { // For each pixel...
     pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    
   }
  
   pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
}
