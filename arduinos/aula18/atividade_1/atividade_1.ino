#define pin_l1 8
#define pin_l2 9
#define pin_l3 10
#define pin_ba 2
#define pin_bb 3
#define pin_bc 4



void setup() {

pinMode(pin_l1, OUTPUT);
pinMode(pin_l2, OUTPUT);
pinMode(pin_l3, OUTPUT);


pinMode(pin_ba, INPUT);
pinMode(pin_bb, INPUT);
pinMode(pin_bc, INPUT);
}

void loop() {
 bool ba = digitalRead(pin_ba);
 bool bb = digitalRead(pin_bb);
 bool bc = digitalRead(pin_bc);

if ( ba == HIGH) {
  digitalWrite(pin_l1, HIGH);
  delay(100);
  digitalWrite(pin_l1, LOW);
}


if ( bb == HIGH) {
  digitalWrite(pin_l2, HIGH);
  delay(100);
  digitalWrite(pin_l2, LOW);
}

if ( bc == HIGH) {
  digitalWrite(pin_l3, HIGH);
  delay(100);
  digitalWrite(pin_l3, LOW);
}

}
