#include <FastLED.h>

#define NUM_LEDS 144
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);

  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  Serial.println("LEDs are now set up.");

  FastLED.setBrightness(255);
}

void loop() {
  int midPoint = NUM_LEDS / 2; // Вычисляем середину
  
  for(int i = 0; i <= midPoint; i++) {
    // Загораем светодиоды с середины к краям
    leds[midPoint - i] = CRGB::HTMLColorCode(0xFFB8E0); 
    leds[midPoint + i] = CRGB::HTMLColorCode(0xFFB8E0);
    FastLED.show();
    delay(30); // Задержка для плавности
  }

  for (int i = 0; i <= midPoint; i++) {
    // Гасим светодиоды с краев к середине
    leds[midPoint - i] = CRGB::HTMLColorCode(0xBE9EFF);
    leds[midPoint + i] = CRGB::HTMLColorCode(0xBE9EFF);
    FastLED.show();
    delay(30); // Задержка для плавности
  }
}