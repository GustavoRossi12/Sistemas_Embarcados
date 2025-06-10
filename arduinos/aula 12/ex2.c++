#define pin_led1 8

void setup() {
  pinMode(pin_led1, OUTPUT);
}

void loop() {

  for (int i = 0; i < 3; i++) {
    digitalWrite(pin_led1, HIGH);
    delay(200);
    digitalWrite(pin_led1, LOW);
    delay(200);
  }

 
  for (int i = 0; i < 3; i++) {
    digitalWrite(pin_led1, HIGH);
    delay(600);
    digitalWrite(pin_led1, LOW);
    delay(200);
  }

  
  for (int i = 0; i < 3; i++) {
    digitalWrite(pin_led1, HIGH);
    delay(200);
    digitalWrite(pin_led1, LOW);
    delay(200);
  }

  delay(2000);
}

