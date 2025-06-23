#define pin_l1 8
#define bA 2


bool stateled = false;
bool botaoApertado = false;
unsigned long tempoAntes = 0;
const long intervalo = 500;

void setup() {
  pinMode(pin_l1, OUTPUT);
  pinMode(bA, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(bA) == LOW && !botaoapertado) {
    botaoapertado = true;
    stateled = !stateled;
  } else if (digitalRead(bA) == HIGH) {
    botaoapertado = false;
  }

  if (stateled) {
    unsigned long tempoDepois = millis();
    if (tempoDepois - tempoAntes >= intervalo) {
      tempoAntes = tempoDepois;
      digitalWrite(pin_l1, !digitalRead(pin_l1));
    }
  } else {
    digitalWrite(pin_l1, LOW);
  }
}
