#define pin_led1 8  
#define pin_led2 9    
#define pin_led3 10   
#define pin_led4 11  


void setup() {
  Serial.begin(9600);       
  pinMode (pin_led1, OUTPUT); 
  pinMode (pin_led2, OUTPUT); 
  pinMode (pin_led3, OUTPUT); 
  pinMode (pin_led4, OUTPUT);  

}

void loop() {
  if (Serial.avaible() == 1){
    char i = Serial.read();
    serial.println(i);
  }

 Serial.println("liga LED");    
 digitalWrite (pin_led1, HIGH);  
 digitalWrite (pin_led2, HIGH); 
 digitalWrite (pin_led3, HIGH);  
 digitalWrite (pin_led4, HIGH); 
 delay (500);                    
 Serial.println("desliga LED");  
 digitalWrite (pin_led1, LOW);   
 digitalWrite (pin_led2, LOW);   
 digitalWrite (pin_led3, LOW);   
 digitalWrite (pin_led4, LOW);  
 delay (500);                   

}
