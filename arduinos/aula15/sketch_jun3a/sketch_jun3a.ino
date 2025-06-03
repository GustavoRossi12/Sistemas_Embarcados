#define pin_pl1 8
#define pin_pl2 9
#define pin_pl3 10
#define pin_pl4 11
#define pin_pba 2
#define pin_pbb 3

void setup() {
 pinMode(pin_pl1, OUTPUT);
 pinMode(pin_pl2, OUTPUT);
pinMode(pin_pl3, OUTPUT);
pinMode(pin_pl4, OUTPUT);
pinMode(pin_pba, INPUT);
pinMode(pin_pbb, INPUT);
Serial.begin(9600);
}

void loop() {
  bool pba = digitalRead(pin_pba);
  bool pbb = digitalRead(pin_pbb);
  if (pba == 1 ) {
    Serial.println("botão A apertado");
  }

  if (pbb == 1 ) {
    Serial.println("botão B apertado");
  }



  if ((pba == 1 ) || (pbb == 1)) {
    digitalWrite(pin_pl2, 1);
  } else {
    digitalWrite(pin_pl2, 0);
  }
  if ((pba == 1 ) && (pbb == 1)) {
    digitalWrite(pin_pl1, 1);
  } else {
    digitalWrite(pin_pl1, 0);
  }
  if ((pba == 1 ) ^ (pbb == 1)) {
    digitalWrite(pin_pl3, 1);
  } else {
    digitalWrite(pin_pl3, 0);
  }




}
