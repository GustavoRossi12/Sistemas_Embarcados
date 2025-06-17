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
  bool sH = digitalRead(pin_botaoA);
  bool sL = digitalRead(pin_botaoB);

  if ((sL==0)&&(sH==0)) {
    digitalWrite(pin_led1, 1);
    digitalWrite(pin_led2, 1);
  }


  if ((sL==0)&&(sH==1)) {
    digitalWrite(pin_led1, 0);
    digitalWrite(pin_led2, 1);
  }


  if ((sL==1)&&(sH==0)) {
    digitalWrite(pin_led1, 1);
    digitalWrite(pin_led2, 0);
  }


  if ((sL==1)&&(sH==1)) {
    digitalWrite(pin_led1, 0);
    digitalWrite(pin_led2, 0);
  }
}
