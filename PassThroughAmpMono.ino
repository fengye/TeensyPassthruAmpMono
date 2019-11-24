/*
 * A simple hardware test which receives audio on the A2 analog pin
 * and sends it to the PWM (pin 3) output and DAC (A14 pin) output.
 *
 * This example code is in the public domain.
 */
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputAnalog         adc1;           //xy=352,488
AudioOutputAnalog        dac1;           //xy=923,519
AudioConnection          patchCord1(adc1, dac1);
// GUItool: end automatically generated code



#define PROP_AMP_ENABLE    5
#define LOUD_SPEAKER
#define LED                13

static uint8_t led_status = LOW;

void setup() {
  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(12);
  delay(1000);
#ifdef LOUD_SPEAKER
  dac1.analogReference(EXTERNAL); // louder!!!
#else
  dac1.analogReference(INTERNAL);
#endif

  pinMode(PROP_AMP_ENABLE, OUTPUT);
  digitalWrite(PROP_AMP_ENABLE, HIGH);    // Enable Amplifier

  pinMode(LED, OUTPUT);
  
}

void loop() {

  led_status = !led_status;
  digitalWrite(LED, led_status);
  delay(1000);


  // Do nothing here.  The Audio flows automatically
  
  // When AudioInputAnalog is running, analogRead() must NOT be used.
}
