#define pin_pl1 8
#define pin_pl2 9
#define pin_pl3 10
#define pin_pl4 11
#define pin_pba 2
#define pin_pbb 3
bool n = 0;
bool nn = 0;
int m = 0;

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

 
  if (pba == HIGH) {
    if (n == 0) {
      if (m < 15) { 
        m++;
      }
      n = 1;
    }
  } else {
    n = 0;
  }

 
  if (pbb == HIGH) {
    if (nn == 0) {
      if (m > 0) {  
        m--;
      }
      nn = 1;
    }
  } else {
    nn = 0;
  }

  digitalWrite(pin_pl1, (m & 0x01) ? HIGH : LOW); 
  digitalWrite(pin_pl2, (m & 0x02) ? HIGH : LOW);  
  digitalWrite(pin_pl3, (m & 0x04) ? HIGH : LOW);
  digitalWrite(pin_pl4, (m & 0x08) ? HIGH : LOW);

  Serial.println(m);
}
