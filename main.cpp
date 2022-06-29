#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_ADS1X15.h"
#include <SPI.h>

#define I2C_CUSTOM

#define I2C_SDA_PIN 32
#define I2C_SCL_PIN 33

Adafruit_ADS1015 ads(I2C_SDA_PIN,I2C_SCL_PIN);

void setup() {
  Serial.begin(115200);

  if (!ads.begin(0x48)) {//begin() in Adafruit_ADS1X15.h
    Serial.println("Failed to initialize ADS.");
    while (1);
  }
  ads.setGain(GAIN_TWOTHIRDS);

}

void loop() {

  int16_t adc_result[3];
  adc_result[0] = ads.readADC_SingleEnded(0);
  adc_result[1] = ads.readADC_SingleEnded(1);

  Serial.printf("adc0=%d, adc1=%d\n", adc_result[0], adc_result[1]);

}