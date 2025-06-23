#define pin_l1  2
#define int pin_l2  3
#define int pin_l3  4
#define int pin_l4  5

unsigned long tempoAntes = 0;
int atualestado = 0;

void setup() {
  pinMode(pin_l1, OUTPUT);
  pinMode(pin_l2, OUTPUT);
  pinMode(pin_l3, OUTPUT);
  pinMode(pin_l4, OUTPUT);

  digitalWrite(pin_l1, LOW);
  digitalWrite(pin_l2, LOW);
  digitalWrite(pin_l3, LOW);
  digitalWrite(pin_l4, LOW);
}

void loop() {
  unsigned long atualestado = millis();

  if (atualestado == 0) {
    digitalWrite(pin_l1, HIGH);
    tempoAntes = tempoDepois;
    atualestado = 1;
  }

  if (atualestado == 1) {
    if (tempoDepois - tempoAntes >= 125) {
      digitalWrite(pin_l2, HIGH);
      tempoAntes = tempoDepois;
      atualestado = 2;
    }
  }

  if (atualestado == 2) {  
    if (tempoDepois - tempoAntes >= 250) {
      digitalWrite(pin_l3, HIGH);
      tempoAntes = tempoDepois;
      atualestado = 3;
    }
  }
  if (atualestado == 3) { 
    if (tempoDepois - tempoAntes >= 500) {
      digitalWrite(pin_l4, HIGH);
      tempoAntes = tempoDepois;
      atualestado = 4;
    }
  }
  if (atualestado == 4) {  
    if (tempoDepois - tempoAntes >= 500) {
      digitalWrite(pin_l1, LOW);
      digitalWrite(pin_l2, LOW);
      digitalWrite(pin_l3, LOW);
      digitalWrite(pin_l4, LOW);
      tempoAntes = tempoDepois;
      atualestado = 0;  
    }
  }
}