unsigned long previousMillis = 0;  // will store last time LED was updated
const long interval = 1000;        // interval at which to blink (milliseconds)
void readNeopixel() {
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    int analogRaw = analogRead(A0);
    int blue_mapped = constrain(map(analogRaw, blue_min, blue_max, 0, 255), 0, 255);
    Serial.print("raw: ");
    Serial.print(analogRaw);
    Serial.print(" blue_mapped: ");
    Serial.print(blue_mapped);
    // Serial.print(" Blue: "); Serial.print(analogRead(bluePin));
    Serial.println();
  }
}