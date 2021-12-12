/*
   T3chFlicks - Motion Sensing Under Bed Lighting
   Free to use and distribute.
   Find the tutorial and parts list at https://t3chflicks.com/shop/kit/motion-sensing-under-bed-lights/
*/

#include <FastLED.h>

#define LED_DATA_PIN 7
#define NUM_LEDS 200
CRGB leds[NUM_LEDS];

int calibrationTime = 30; 
int onTime = 30*1000; // 30 seconds
int motion_sensor_downstairs = 9;
int motion_sensor_upstairs = 10;
int fadeTimeDiff = 50;

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.setBrightness(200);
  FastLED.show();
  pinMode(motion_sensor_downstairs, INPUT);
  pinMode(motion_sensor_upstairs, INPUT);
  digitalWrite(motion_sensor_downstairs, LOW);
  digitalWrite(motion_sensor_upstairs, LOW);
  pinMode(LED_BUILTIN, OUTPUT);
  calibrateSensors();
}

void loop() {
  if (digitalRead(motion_sensor_downstairs) == HIGH || digitalRead(motion_sensor_upstairs) == HIGH) {
    Serial.print("Motion Detected: ");
    Serial.println(motion_sensor_downstairs);
    Serial.println(motion_sensor_upstairs);
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(200);                       // wait for a second
    fadeIn();
    delay(onTime);
    fadeOut();
  }
}

void fadeIn() {
  Serial.println("Switching on for 30 seconds");
  for (int led = 0; led < NUM_LEDS; led++) {
    leds[led] = CRGB( 255, 75, 0);
  }
  for (int b = 0; b < 255; b += 2) {
    FastLED.setBrightness(b);
    FastLED.show();
    delay(fadeTimeDiff);
  }
}

void fadeOut() {
  Serial.println("Fading out and switching off until motion detected");
  for (int led = 0; led < NUM_LEDS; led++) {
    leds[led] = CRGB( 255, 75, 0);
  }
  for (int b = 255; b > 0; b -= 2) {
    FastLED.setBrightness(b);
    FastLED.show();
    delay(fadeTimeDiff);
  }
  for (int led = 0; led < NUM_LEDS; led++) {
    leds[led] = CRGB::Black;
  }
  FastLED.show();
}

void calibrateSensors() {
    Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){ 
      Serial.print("."); delay(1000); 
    } 
    Serial.println(" done"); 
    Serial.println("SENSOR ACTIVE"); 
    delay(50);
}
