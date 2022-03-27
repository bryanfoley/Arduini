#include <FastLED.h>

#define POT_PIN     A0      // The Analog input pin that the brightness control potentiometer is attached to.
#define COLOUR_PIN  A1      // The Analog input pin that the colour control potentiometer is attached to.
#define LED_PIN     7       // which pin are LEDS connected to?
#define NUM_LEDS    20
#define MIN_BRIGHTNESS 25
#define MAX_BRIGHTNESS 255

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  int MAPPED_COLOUR = map(analogRead(COLOUR_PIN), 0, 1023, 0, 255);
  int MAPPED_BRIGHTNESS = map(analogRead(POT_PIN), 0, 1023, 0, 255);
  FastLED.setBrightness(MAPPED_BRIGHTNESS);

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
  int MAPPED_BRIGHTNESS = map(analogRead(POT_PIN), 0, 1023, 0, 255);
  int MAPPED_COLOUR = map(analogRead(COLOUR_PIN), 0, 1023, 0, 255);
  //Serial.print("Brightness POT Value = ");   // Print text
  //Serial.println(MAPPED_BRIGHTNESS);       // Print value on Serial Monitor
  Serial.print("Colour POT Value = ");   // Print text
  Serial.println(MAPPED_COLOUR);       // Print value on Serial Monitor
  for (int i = 0; i < NUM_LEDS; i++) {
    //leds[i] = CRGB(255, 75, MAPPED_COLOUR);
    leds[i].setRGB(255, 75, MAPPED_COLOUR<=15 ? 0: MAPPED_COLOUR);
  }
  FastLED.setBrightness(constrain(MAPPED_BRIGHTNESS, MIN_BRIGHTNESS, MAX_BRIGHTNESS));
  FastLED.show();
  delay(100);
}
