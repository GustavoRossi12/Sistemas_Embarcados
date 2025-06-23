///Definir os terminais com os nomes
#define led_LIB 8
#define led_LOT 9
#define led_VER 10
#define pin_b1 2
#define pin_b2 3
#define pin_b3 4


int t1 = 0;
int t2 = 0;


void setup() {
  pinMode(led_LIB, OUTPUT);
  pinMode(led_LOT, OUTPUT);
  pinMode(led_VER, OUTPUT);
  pinMode(pin_b1, INPUT);
  pinMode(pin_b2, INPUT);
  pinMode(pin_b3, INPUT);
  
  Serial.begin(9600);
}

void loop() {

  bool SEV = digitalRead(pin_b1);
  bool SSV = digitalRead(pin_b2); 
  bool BOT = digitalRead(pin_b3); 

  Serial.println(c);

 if (SEV == 1 && t1 == 0 && c<10) {
   
    c += 1;
    t1 += 1;
  }
 
  if (SEV == 0) {
    t1 = 0;
  }

  if (SSV == 1 && t2 == 0 && c>0) {
  
    c -= 1;
    t2 += 1;
  }

  
  if (SSV == 0) {
    t2 = 0;
  }

if (c == 10){
  digitalWrite(led_LOT, 1);
  digitalWrite(led_LIB, 0);
}else{ 
  digitalWrite(led_LOT, 0);
}

if (c < 10){
  digitalWrite(led_LIB, 1);
  digitalWrite(led_LOT, 0);
}else{ 
  digitalWrite(led_LIB, 0);
}

if (c == 0){
  digitalWrite(led_VER, 1);
  digitalWrite(led_LOT, 0);
}else{
  digitalWrite(led_VER, 0);
}

if (BOT == 1) {
  c = 0;
}
}
