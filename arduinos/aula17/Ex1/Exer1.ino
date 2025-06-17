///Definir os terminais com os nomes
#define pin_led1 8          
#define pin_led2 9         
#define pin_led3 10        
#define pin_led4 11         
#define pin_botaoA 2
#define pin_botaoB 3
#define pin_botaoC 4

//começo a programação informando o tipo de pino INPUT(envia dados) ou OUTPUT(recebe dados)
void setup() {
  pinMode(pin_led1, OUTPUT);        
  pinMode(pin_led2, OUTPUT);        
  pinMode(pin_led3, OUTPUT);        
  pinMode(pin_led4, OUTPUT);        
  pinMode(pin_botaoA, INPUT);
  pinMode(pin_botaoB, INPUT);
  pinMode(pin_botaoC, INPUT);

}
void loop() {
  //aqui informo o nome da variavel e o tipo dela que sera boleana, sendo 1 ou 0 como resultado
  bool estadoA = digitalRead(pin_botaoA); //pin_botaoA esta com o nome de "estadoA"
  bool estadoB = digitalRead(pin_botaoB); //pin_botaoB esta com o nome de "estadoB"
  bool estadoC = digitalRead(pin_botaoC); //pin_botaoC esta com o nome de "estadoC"

  //se o estadoA (pin_botãoA) for precionado ele acendera o led1 caso ele solte o led1 sera apagado
  if (estadoA == 1) {
    digitalWrite(pin_led1, 1);    
  } else {
    digitalWrite(pin_led1, 0);
  }

  //se o estadoB (pin_botãoB) for precionado ele acendera o led2 caso ele solte o led2 sera apagado
  if (estadoB == 1) {
    digitalWrite(pin_led2, 1);    
  } else {
    digitalWrite(pin_led2, 0);
  }

  //se o estadoC (pin_botãoC) for precionado ele acendera o led3 caso ele solte o led3 sera apagado
  if (estadoC == 1) {
    digitalWrite(pin_led3, 1);    
  } else {
    digitalWrite(pin_led3, 0);
  }
}
