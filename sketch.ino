#include <Adafruit_NeoPixel.h>

#define PIN            2 // Neopixel Data Input
#define NUMPIXELS      1 // The bin gives only one neopixel
#define LDR_PIN        26 // ADC0 (GP26)
#define SLIDER_PIN     27 // ADC1 (GP27)

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();

  analogReadResolution(12); // 12-bit ADC resolution

  Serial1.begin(115200);
  Serial1.println("Hello, Raspberry Pi Pico W!");
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);
  int sliderValue = analogRead(SLIDER_PIN);
  
  int colorValue = map(ldrValue, 0, 4095, 0, 255);

  int brightness = map(sliderValue, 0, 4095, 0, 255);

  int red = colorValue;
  int green = 0;
  int blue = 255 - colorValue;

  red = (red * brightness) / 255;
  green = (green * brightness) / 255;
  blue = (blue * brightness) / 255;

  pixels.setPixelColor(0, pixels.Color(red, green, blue));
  pixels.show();

  Serial1.print("LDR Value: ");
  Serial1.print(ldrValue);
  Serial1.print(" | Color Value: ");
  Serial1.print(colorValue);
  Serial1.print(" | Slider Value: ");
  Serial1.print(sliderValue);
  Serial1.print(" | Brightness: ");
  Serial1.print(brightness);
  Serial1.print(" | Red: ");
  Serial1.print(red);
  Serial1.print(" | Green: ");
  Serial1.print(green);
  Serial1.print(" | Blue: ");
  Serial1.println(blue);
  
  delay(100);
}
