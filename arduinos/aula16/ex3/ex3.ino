#define pin_l1 8
#define pin_l2 9
#define pin_l3 10
#define pin_l4 11
#define pin_bA 2
#define pin_bB 3
#define pin_bC 4

void setup() {
  pinMode(pin_l1, OUTPUT);
  pinMode(pin_l2, OUTPUT);
  pinMode(pin_l3, OUTPUT);
  pinMode(pin_l4, OUTPUT);
  pinMode(pin_bA, INPUT);
  pinMode(pin_bB, INPUT);
  pinMode(pin_bC, INPUT);
  Serial.begin(9600);
}

void loop() {
  bool A = digitalRead(pin_bA);
  bool B = digitalRead(pin_bB);

  if ((A==0) && (B==0)) {
    digitalWrite(pin_l1, 1);
  } else {
    digitalWrite(pin_l1, 0);
  }


  if ((A==0) && (B==1)) {
    digitalWrite(pin_l1, 0);
  }


  if ((A==1) && (B==0)) {
    digitalWrite(pin_l1, 0);
  }


  if ((A==1) && (B==1)) {
    digitalWrite(pin_l1, 0);
  }


}
