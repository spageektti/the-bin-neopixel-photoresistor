#include <Adafruit_NeoPixel.h>

#define PIN            0 // Neopixel Data Input
#define NUMPIXELS      1 // The bin gives only one neopixel
#define LDR_PIN        26 // ADC0 (GP26)
#define SLIDER_PIN     27 // ADC1 (GP27)

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();

  analogReadResolution(12); // 12-bit ADC resolution
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);
  int sliderValue = analogRead(SLIDER_PIN);
  
  int hue = map(ldrValue, 0, 4095, 0, 255);

  int brightness = map(sliderValue, 0, 4095, 0, 255);

  pixels.setPixelColor(0, pixels.ColorHSV(hue * 65536L, 255, brightness));
  pixels.show();
  
  delay(100);
}
