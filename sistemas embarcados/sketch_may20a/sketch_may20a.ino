#define pl1 8
#define pl2 9
#define pl3 10
#define pl4 11

void setup() {
  Serial.begin(9600);
  pinMode(pl1, OUTPUT);
  pinMode(pl2, OUTPUT);
  pinMode(pl3, OUTPUT);
  pinMode(pl4, OUTPUT);
}

void loop() {
  //liga o led 
  if Serial.available() == 1) {
   char i = serial.read();
    seral.println(i);
  } 
  Serial.println("liga led");
  digitalWrite(pl1, HIGH);
  digitalWrite(pl2, HIGH);
  digitalWrite(pl3, HIGH);
  digitalWrite(pl4, HIGH);
  //temporizador
  delay(1000);
  //desliga o led
  Serial.println("desliga led");
  digitalWrite(pl1, LOW);
  digitalWrite(pl2, LOW);
  digitalWrite(pl3, LOW);
  digitalWrite(pl4, LOW);
  //temporizador
  delay(1000);
}
