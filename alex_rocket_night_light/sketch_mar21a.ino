#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    20

CRGB leds[NUM_LEDS];
int brightness = 0;
int fadeByAmount = 1;
uint8_t hue = 0;

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();

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

//  EVERY_N_SECONDS(1) {
//    hue++;
//  }
//
//  fill_solid(leds, NUM_LEDS, CHSV(hue, 155, 75));  
//  FastLED.show();
}
