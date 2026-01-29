// ESP32 Sinusoidal PWM + Serial Oscilloscope Loopback Test

#include <Arduino.h>


const int pwmPin1 = 32;  // pwm output pin for mosfet 1
const int pwmPin2= 25;  // pwm output pin for mosfet 2
const int pwmPin3= 27;  // pwm output pin for mosfet 3
const int pwmPin4= 12;  // pwm output pin for mosfet 4
const int pwmPin5= 13;  // pwm output pin for mosfet 5
const int pwmPin6= 4;  // pwm output pin for mosfet 6

float m = 1.0; // modulation index



const int samples = 100;
const float sineFreq = 50;                // 50 Hz sine wave
const float samplingRate = sineFreq * samples; // 50 * 100 = 5000 samples/sec
const unsigned long periodMicros = 1000000/samplingRate;

float sinTable1[samples];
float sinTable2[samples];
float sinTable3[samples];
float sinTable4[samples];
float sinTable5[samples];
float sinTable6[samples];
unsigned long lastMicros = 0;

const int pwmChannel = 0;      
const int pwmFreq = 1000;     // 1 kHz carrier
const int pwmResolution = 8;   // 8-bit resolution (0–255)

void setup() {
  Serial.begin(9600);
  delay(1000);

  ledcAttach(pwmPin1, pwmFreq, pwmResolution);
  ledcAttach(pwmPin2, pwmFreq, pwmResolution);
  ledcAttach(pwmPin3, pwmFreq, pwmResolution);
  ledcAttach(pwmPin4, pwmFreq, pwmResolution);
  ledcAttach(pwmPin5, pwmFreq, pwmResolution);
  ledcAttach(pwmPin6, pwmFreq, pwmResolution);
  

  for (int i = 0; i < samples; i++) {
    sinTable1[i] =  245.5f* sinf(2 * PI * i / samples);  //mosfet 1
    sinTable2[i] =  127.5f* sinf((2 * PI * i / samples)  + 0.3333*PI );       
    sinTable3[i] =  127.5f* sinf((2 * PI * i / samples)+ 0.6667*PI); //mosfet 3
    sinTable4[i] =  127.5f* sinf((2 * PI * i / samples) + PI);
    sinTable5[i] =  127.5f* sinf((2 * PI * i / samples ) + 1.3333*PI); //mosfet 5
    sinTable6[i] =  127.5f* sinf((2 * PI * i / samples) + 1.6667*PI);
 

  }
}

void loop() {
  static int index = 0;
  unsigned long now = micros();

  if (now - lastMicros >= periodMicros) {
    lastMicros = now;

    int duty1 = (int)sinTable1[index]; // 2 duty cyles generated
    int duty2 = (int)sinTable2[index]; 
    int duty3 = (int)sinTable3[index]; 
    int duty4 = (int)sinTable4[index]; // complementry signal
    int duty5 = (int)sinTable5[index]; 
    int duty6 = (int)sinTable6[index]; 


    ledcWrite(pwmPin1, duty1); 
    ledcWrite(pwmPin2, duty2);
    
    ledcWrite(pwmPin3, duty3); 
    ledcWrite(pwmPin4, duty4);


    ledcWrite(pwmPin5, duty5); 
    ledcWrite(pwmPin6, duty6);




    index++;
    if (index >= samples)index = 0;


    //int value = analogRead(analogPin);
    //Serial.println(value);
  }
}