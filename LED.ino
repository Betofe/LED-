/*
 Name:		LED.ino
 Created:	10/26/2022 9:30:06 AM
 Author:	Imami Joel Betofe
*/

// the number of the LED pin
const int ledPin = 12;  // 16 corresponds to GPIO16

// setting PWM properties
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

void setup() {
    // configure LED PWM functionalitites
    ledcSetup(ledChannel, freq, resolution);

    // attach the channel to the GPIO to be controlled
    ledcAttachPin(ledPin, ledChannel);
}

void loop() {
    // increase the LED brightness
    for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        ledcWrite(ledChannel, 255);
        delay(100);
    }

    // decrease the LED brightness
    for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
        // changing the LED brightness with PWM
        ledcWrite(ledChannel, 0);
        delay(100);
    }
}