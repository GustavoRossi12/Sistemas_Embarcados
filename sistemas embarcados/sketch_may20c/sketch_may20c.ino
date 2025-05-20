#define pl1 8
#define pl2 9
#define pl3 10
#define pl4 11
#define pb 2
#define pb2 3

void setup() {
  pinMode(pl1, OUTPUT);
  pinMode(pl2, OUTPUT);
  pinMode(pl3, OUTPUT);
  pinMode(pl4, OUTPUT);
  pinMode(pb, INPUT);

}

void loop() {
  bool estado = digitalRead(pb);
  if (estado == 1) {
    digitalWrite(pl1, HIGH);
    digitalWrite(pl3, HIGH);
    digitalWrite(pl2, LOW);
    digitalWrite(pl4, LOW);

  } else {
    digitalWrite(pl1, LOW);
    digitalWrite(pl3, LOW);
    digitalWrite(pl2, HIGH);
    digitalWrite(pl4, HIGH);

  }


}
