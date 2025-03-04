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

int bigcycle;
int ct;
int mark=1;


// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(1, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  
bigcycle=bigcycle+mark;

 ct=255-bigcycle;
 analogWrite(1, ct);
  delay(10); 
  analogWrite(0, bigcycle);
    analogWrite(4, bigcycle);


if (bigcycle > 255) {mark = mark*-1;};
if (bigcycle < 1) {mark = mark*-1;};
  delay(30); 
  analogWrite(1, 0);
  analogWrite(0, 0);
}
