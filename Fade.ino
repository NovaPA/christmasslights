/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/

int ct;
int a1; 
int a2;
int brightness = 0;    // how bright the LED is

int brightness1 = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  

  for (int ct = 1; ct <= 255; ct++) {
    brightness1=ct;
    delay(10);
  analogWrite(9, brightness1);
 
    
  int a1 = analogRead(A1);
    analogWrite(6, a1);
    int a2 = analogRead(A0);
  analogWrite(5, a2);
 };
 analogWrite(9, 0);

 
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
