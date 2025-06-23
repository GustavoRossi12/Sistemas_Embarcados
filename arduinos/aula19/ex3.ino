
#define int pin_l1  2
#define int pin_l2  3
#define int pin_l3  4
#define int pin_l4  5
#define int bA  6 


unsigned long tempoantes = 0;
int atualestado = 0;
bool seqdireta = true;
bool seqativa = false;
bool botaoapertado = false;

void setup() {
  pinMode(pin_l1, OUTPUT);
  pinMode(pin_l2, OUTPUT);
  pinMode(pin_l3, OUTPUT);
  pinMode(pin_l4, OUTPUT);
  pinMode(bA, INPUT_PULLUP);
  
  digitalWrite(pin_l1, LOW);
  digitalWrite(pin_l2, LOW);
  digitalWrite(pin_l3, LOW);
  digitalWrite(pin_l4, LOW);
}

void loop() {
  unsigned long tempodepois = millis();
  

  if (digitalRead(bA) == LOW && !botaoapertado) {
    botaoapertado = true;
    seqdireta = !seqdireta;
    seqativa = true;
    atualestado = 0;
    tempoantes = tempodepois;
    
   
    digitalWrite(pin_l1, LOW);
    digitalWrite(pin_l2, LOW);
    digitalWrite(pin_l3, LOW);
    digitalWrite(pin_l4, LOW);
  }
  
  if (digitalRead(bA) == HIGH) {
    botaoapertado = false;
  }

  
  if (seqativa) {
    if (seqdireta) {
      if (atualestado == 0) {
        digitalWrite(pin_l1, HIGH);
        tempoantes = tempodepois;
        atualestado = 1;
      }
      
      if (atualestado == 1 && tempodepois - tempoantes >= 125) {
        digitalWrite(pin_l2, HIGH);
        tempoantes = tempodepois;
        atualestado = 2;
      }
      
      if (atualestado == 2 && tempodepois - tempoantes >= 250) {
        digitalWrite(pin_l3, HIGH);
        tempoantes = tempodepois;
        atualestado = 3;
      }
      
      if (atualestado == 3 && tempodepois - tempoantes >= 500) {
        digitalWrite(pin_l4, HIGH);
        tempoantes = tempodepois;
        atualestado = 4;
      }
      
      if (atualestado == 4 && tempodepois - tempoantes >= 500) {
        digitalWrite(pin_l1, LOW);
        digitalWrite(pin_l2, LOW);
        digitalWrite(pin_l3, LOW);
        digitalWrite(pin_l4, LOW);
        seqativa = false;
      }
      
    } else {
      if (atualestado == 0) {
        digitalWrite(pin_l4, HIGH);
        tempoantes = tempodepois;
        atualestado = 1;
      }
      
      if (atualestado == 1 && tempodepois - tempoantes >= 125) {
        digitalWrite(pin_l3, HIGH);
        tempoantes = tempodepois;
        atualestado = 2;
      }
      
      if (atualestado == 2 && tempodepois - tempoantes >= 250) {
        digitalWrite(pin_l2, HIGH);
        tempoantes = tempodepois;
        atualestado = 3;
      }
      
      if (atualestado == 3 && tempodepois - tempoantes >= 500) {
        digitalWrite(pin_l1, HIGH);
        tempoantes = tempodepois;
        atualestado = 4;
      }
      
      if (atualestado == 4 && tempodepois - tempoantes >= 500) {
        digitalWrite(pin_l1, LOW);
        digitalWrite(pin_l2, LOW);
        digitalWrite(pin_l3, LOW);
        digitalWrite(pin_l4, LOW);
        seqativa = false;
      }
    }
  }
}
