#define pin_led1 8  

void setup() {
  pinMode(pin_led1, OUTPUT);
}

void loop() {
  digitalWrite(pin_led1, HIGH); 
  delay(1000);                  
  digitalWrite(pin_led1, LOW);  
  delay(1000);                  
}
