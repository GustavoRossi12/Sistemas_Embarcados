#define pin_led1 8  
#define pin_led2 9    
#define pin_led3 10   
#define pin_led4 11  


void setup() {
  Serial.begin(9600);          //define a velocidade da comunicação
  pinMode (pin_led1, OUTPUT);  //definindo led1 saida
  pinMode (pin_led2, OUTPUT);  //definindo led2 saida
  pinMode (pin_led3, OUTPUT);  //definindo led3 saida
  pinMode (pin_led4, OUTPUT);  //definindo led4 saida

}

void loop() {
  if (Serial.avaible() == 1){
    char i = Serial.read();
    serial.println(i);
  }
 /*
 Serial.println("liga LED");    //manda mensagem pro serial monitor sempre que acontece isso
 digitalWrite (pin_led1, HIGH);  //definindo led1 alto
 digitalWrite (pin_led2, HIGH);  //definindo led2 alto
 digitalWrite (pin_led3, HIGH);  //definindo led3 alto
 digitalWrite (pin_led4, HIGH);  //definindo led4 alto
 delay (500);                    // espera 500 milissegundos
 Serial.println("desliga LED");  //manda mensagem pro serial monitor sempre que acontece isso
 digitalWrite (pin_led1, LOW);   //definindo led1 baixo
 digitalWrite (pin_led2, LOW);   //definindo led2 baixo
 digitalWrite (pin_led3, LOW);   //definindo led3 baixo
 digitalWrite (pin_led4, LOW);   //definindo led4 baixo
 delay (500);                    // espera 500 milissegundos
*/
}
