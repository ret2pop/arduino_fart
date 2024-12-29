#include <Arduino.h>

#define MODULUS 2147483648 // 2^31
#define MULTIPLIER 1103515245
#define INCREMENT 12345

long randInt;
unsigned long seed = 13054324;

void setup() {
  pinMode(A5, OUTPUT);
}

unsigned long nextRandom() {
    seed = (MULTIPLIER * seed + INCREMENT) % MODULUS;
    return seed;
}

void loop() {
  randInt = (nextRandom() % 600000) + 600000;
  digitalWrite(A5, HIGH);
  delay(4000);
  digitalWrite(A5, LOW);
  delay(1000 + randInt);
}
