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
  if (pba == 1 ) {
    if (n == 0){
      m++;
      n = 1;
    }
  }else {
    n = 0;
  }
  Serial.println(m);

  if (pbb == 1 ) {
    if (nn == 0){
      m--;
      nn = -1;
    }
  }else {
    nn = 0;
  }
  Serial.println(m);

  if ( m > 50 ) {
    m = 50;
      }
   if ( m < 0 ) {
    m = 0;
      } 
  
}
