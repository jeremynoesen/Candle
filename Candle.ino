/**
 * set the brightness of the LED on pin 13 for a millisecond
 * 
 * @param brightness LED brightness 0 to 1000
 */
void setBrightness(int brightness) {
  int clampedBrightness = (brightness < 0) ? 0 : ((brightness > 1000) ? 1000 : brightness);
  digitalWrite(LED_BUILTIN, HIGH);
  delayMicroseconds(clampedBrightness);
  digitalWrite(LED_BUILTIN, LOW);
  delayMicroseconds(1000 - clampedBrightness);
}

/**
 * set pin 13 as an output
 */
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

/**
 * play candle effect
 */
void loop() {
  int randSpeed = random(1, 4); // random speed
  int randMaxBrightness = random(500, 1001); // random max brightness
  int randMinBrightness = random(1, 500); // random min brightness

  // fade up
  for (int i = randMinBrightness; i < randMaxBrightness; i += randSpeed) {
    setBrightness(i);
  }

  randSpeed = random(1, 3); // new random speed

  // fade dowm
  for (int i = randMaxBrightness; i > randMinBrightness; i -= randSpeed) {
    setBrightness(i);
  }
}
