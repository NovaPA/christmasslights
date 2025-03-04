#define LED_PIN_0 0
#define LED_PIN_1 1
#define LED_PIN_4 4
#define NUM_LEDS 3


float sinValues[NUM_LEDS][256];

void setup() {
  pinMode(LED_PIN_0, OUTPUT);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);


  // Заполняем массив предварительно вычисленными значениями sin
  for (int i = 0; i < 256; i++) {
    sinValues[0][i] = sin(i * 2 * PI / 256.0);
    sinValues[1][i] = sin((i + 85) * 2 * PI / 256.0);
    sinValues[2][i] = sin((i + 170) * 2 * PI / 256.0);
  }
}

void loop() {
  // Режим 1: Все светодиоды включены
  allOn();
  delay(1000);

  // Режим 2: Мигание светодиодов
  blink();
  delay(1000);

  // Режим 3: Плавное мерцание светодиодов
  fade();
  delay(1000);

  // Режим 4: Бегущий огонь
  runningLights();
  delay(1000);

  // Режим 5: Все светодиоды выключены
  allOff();
  delay(1000);
}

void allOn() {
  digitalWrite(LED_PIN_0, HIGH);
  digitalWrite(LED_PIN_1, HIGH);
  digitalWrite(LED_PIN_4, HIGH);
}

void allOff() {
  digitalWrite(LED_PIN_0, LOW);
  digitalWrite(LED_PIN_1, LOW);
  digitalWrite(LED_PIN_4, LOW);
}

void blink() {
  digitalWrite(LED_PIN_0, HIGH);
  digitalWrite(LED_PIN_1, HIGH);
  digitalWrite(LED_PIN_4, HIGH);
  delay(500);
  allOff();
  delay(500);
}

void fade() {
  for (int phase = 0; phase < 256; phase += 5) {
    for (int i = 0; i < 256; i += 32) {
      analogWrite(LED_PIN_0, map(sinValues[0][(i + phase) % 256], -1, 1, 0, 255));
      analogWrite(LED_PIN_1, map(sinValues[1][(i + phase + 85) % 256], -1, 1, 0, 255));
      analogWrite(LED_PIN_4, map(sinValues[2][(i + phase + 170) % 256], -1, 1, 0, 255));
      delay(20);
    }
  }
  allOff();
}

void runningLights() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(LED_PIN_0, HIGH);
    delay(100);
    allOff();
    digitalWrite(LED_PIN_1, HIGH);
    delay(100);
    allOff();
    digitalWrite(LED_PIN_4, HIGH);
    delay(100);
    allOff();
  }
}
