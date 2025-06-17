#define pin_led1 8
#define pin_led2 9
#define pin_led3 10
#define pin_led4 11
#define pin_botaoA 2
#define pin_botaoB 3
#define pin_botaoC 4

void setup() {
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_led2, OUTPUT);
  pinMode(pin_led3, OUTPUT);
  pinMode(pin_led4, OUTPUT);
  pinMode(pin_botaoA, INPUT);
  pinMode(pin_botaoB, INPUT);
  pinMode(pin_botaoC, INPUT);
  Serial.begin(9600);
}

void loop() {
  bool A = digitalRead(pin_botaoA);
  bool B = digitalRead(pin_botaoB);

  if ((A==0) && (B==0)) {
    digitalWrite(pin_led1, 1);
  } else {
    digitalWrite(pin_led1, 0);
  }


  if ((A==0) && (B==1)) {
    digitalWrite(pin_led1, 0);
  }


  if ((A==1) && (B==0)) {
    digitalWrite(pin_led1, 0);
  }


  if ((A==1) && (B==1)) {
    digitalWrite(pin_led1, 0);
  }


}
