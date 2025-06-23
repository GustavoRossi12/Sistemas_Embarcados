#define pin_lib 8
#define pin_lot 9
#define pin_ver 10
#define pin_sev 2
#define pin_ssv 3
#define pin_bot 4

bool n = 0;
bool nn = 0;
int m = 10;
bool travado = false;

void setup() {
  pinMode(pin_lib, OUTPUT);
  pinMode(pin_lot, OUTPUT);
  pinMode(pin_ver, OUTPUT);
  pinMode(pin_sev, INPUT);
  pinMode(pin_ssv, INPUT);
  pinMode(pin_bot, INPUT);
  Serial.begin(9600);  
}

void loop() {
  bool bot = digitalRead(pin_bot);

  if (travado) {
    if (bot == HIGH) {
      travado = false;
      m = 10; 
      digitalWrite(pin_ver, LOW);
    }
    return; 
  }

  bool sev = digitalRead(pin_sev);
  bool ssv = digitalRead(pin_ssv);

 
  if (ssv == HIGH) {
    if (!n) {
      m++;
      n = true;
    }
  } else {
    n = false;
  }


  if (sev == HIGH) {
    if (!nn) {
      m--;
      nn = true;
    }
  } else {
    nn = false;
  }

  
  if (m > 11) m = 10;
  if (m < 0) m = 0;

  Serial.println(m);

  if (m > 0 && m <= 10) {
    digitalWrite(pin_lib, HIGH);
  } else {
    digitalWrite(pin_lib, LOW);
  }


  digitalWrite(pin_lot, (m == 0) ? HIGH : LOW);


  if (m == 0) {
    digitalWrite(pin_ver, HIGH);
    travado = true;
  }
}
