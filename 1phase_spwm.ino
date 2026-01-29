// ESP32 Sinusoidal PWM + Serial Oscilloscope Loopback Test

#include <Arduino.h>

const int pwmPin1 = 25;  // pwm output pin for mosfet 1 and 3
const int pwmPin2= 12;   // PWM output pin for mosfet 2 and 4


const int samples = 100;
const float sineFreq = 50.0;                // 50 Hz sine wave
const float samplingRate = sineFreq * samples; // 50 * 100 = 5000 samples/sec
const unsigned long periodMicros = 1000000/samplingRate;

float sinTable1[samples];
float sinTable2[samples];
unsigned long lastMicros = 0;

const int pwmChannel = 0;      
const int pwmFreq = 1000;     // 20 kHz carrier
const int pwmResolution = 8;   // 8-bit resolution (0–255)

void setup() {
  Serial.begin(9600);
  delay(1000);

  ledcAttach(pwmPin1, pwmFreq, pwmResolution);
  ledcAttach(pwmPin2, pwmFreq, pwmResolution);
  

  for (int i = 0; i < samples; i++) {
    sinTable1[i] =  127.5f* sinf(2 * PI * i / samples); 
    sinTable2[i] =  127.5f* sinf((2 * PI * i / samples) +PI); // 180 degree shift
  }
}

void loop() {
  static int index = 0;
  unsigned long now = micros();

  if (now - lastMicros >= periodMicros) {
    lastMicros = now;

    int duty1 = (int)sinTable1[index]; // 2 duty cyles generated
    int duty2 = (int)sinTable2[index]; // complementry signal
    ledcWrite(pwmPin1, duty1); 
    ledcWrite(pwmPin2, duty2);


    index++;
    if (index >= samples)index = 0;


    //int value = analogRead(analogPin);
    //Serial.println(value);
  }
}