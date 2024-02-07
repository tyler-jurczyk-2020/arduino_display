#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void setup(){
    Serial.begin(9600);
    Serial.println("Hi I compiled!!");

    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }

    display.display();
    delay(2000);
    display.clearDisplay();
    display.display();
    delay(2000);
    display.drawLine(0, 0, 128, 64, SSD1306_WHITE);
    display.drawLine(128, 0, 0, 64, SSD1306_WHITE);
    display.display();
    delay(2000);
    display.clearDisplay();
    display.display();
}

void loop(){
    
}
