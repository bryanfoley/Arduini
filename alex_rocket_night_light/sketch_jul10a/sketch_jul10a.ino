#include <FastLED.h>

#define POT_PIN     A0      // The Analog input pin that the brightness control potentiometer is attached to.
#define LED_PIN     7       // which pin are LEDS connected to?
#define NUM_LEDS    20
#define MIN_BRIGHTNESS 25
#define MAX_BRIGHTNESS 255

CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  int MAPPED_VALUE = map(analogRead(POT_PIN), 0, 1023, 0, 255);
  FastLED.setBrightness(MAPPED_VALUE);

  for (int i = 0; i <= NUM_LEDS/2; i++) {
    leds[10-i] = CRGB(255, 75, 0);
    leds[11+i] = CRGB(255, 75, 0);
    for(int j=1; j<=15; j+=1){
      leds[10-i].setRGB(17*j,5*j,0);
      leds[11+i].setRGB(17*j,5*j,0);
      FastLED.show();
      if(i==1){
        delay(200);
      }
      else{
        delay(1);
      }
    }
    FastLED.show();
    delay(1);
  }  
}

void loop() {
  int MAPPED_VALUE = map(analogRead(POT_PIN), 0, 1023, 0, 255);
  FastLED.setBrightness(constrain(MAPPED_VALUE, MIN_BRIGHTNESS, MAX_BRIGHTNESS));
  FastLED.show();
  delay(1);
}
