///Definir os terminais com os nomes
#define led_LIB 8
#define led_LOT 9
#define led_VER 10
#define pin_botao1 2
#define pin_botao2 3
#define pin_botao3 4

//Aqui coloco o tipo da variavel (INT) e coloco o valor inicial dela como 0 (fora do "VOID SETUP" para que ele não resete toda vez que o codigo voltar para cima)
int cont = 0;
int tic1 = 0;
int tic2 = 0;

//começo a programação informando o tipo de pino INPUT(envia dados) ou OUTPUT(recebe dados)
void setup() {
  pinMode(led_LIB, OUTPUT);
  pinMode(led_LOT, OUTPUT);
  pinMode(led_VER, OUTPUT);
  pinMode(pin_botao1, INPUT);
  pinMode(pin_botao2, INPUT);
  pinMode(pin_botao3, INPUT);
  //codigo abaixo é a frequencia que o arduino trabalhara
  Serial.begin(9600);
}

void loop() {
  //aqui informo o nome da variavel e o tipo dela que sera boleana, sendo 1 ou 0 como resultado. (coloquei esses nomes por conta do enunciado da questão)
  bool SEV = digitalRead(pin_botao1); //pin_botaoA esta com o nome de "SEV"
  bool SSV = digitalRead(pin_botao2); //pin_botaoB esta com o nome de "SSV"
  bool BOT = digitalRead(pin_botao3); //pin_botaoC esta com o nome de "BOT"

  //aqui sera a mensagem que sera mostrada no MONITOR SERIAL
  Serial.println(cont);

  //Aqui quando o botão SEV for pressionado e o tic1 for igual a 0 ele ira ver se o contador chegou a 10, caso não ocorra ele ira continuar, mas se chegar ele para o contador
 if (SEV == 1 && tic1 == 0 && cont<10) {
    //apos a "verificação" ele ira acressentar "1" no CONT e no TIC1, para dizer que o botão só foi pressionado uma vez
    cont += 1;
    tic1 += 1;
  }
  //Quando o botão SEV for igual a 0 o TIC1 tambem sera ja que o botão não esta pressionado
  if (SEV == 0) {
    tic1 = 0;
  }

  //Aqui quando o botão SEV for pressionado e o tic2 for igual a 0 ele ira ver se o contador chegou a 0, caso não ocorra ele ira continuar, mas se chegar ele para o contador  
  if (SSV == 1 && tic2 == 0 && cont>0) {
    //apos a "verificação" ele ira diminuir "1" no CONT e acressentar no TIC1, para dizer que o botão só foi pressionado uma vez
    cont -= 1;
    tic2 += 1;
  }

  //Quando o botão SEV for igual a 0 o TIC2 tambem sera ja que o botão não esta pressionado
  if (SSV == 0) {
    tic2 = 0;
  }

//caso o contador chegar a 10 o "led_LOT" sera acesso para informar que o estacionamento esta cheio
if (cont == 10){
  digitalWrite(led_LOT, 1);
  digitalWrite(led_LIB, 0);
}else{ //caso isso nao ocorra ele continuara normal
  digitalWrite(led_LOT, 0);
}

//caso o contador for menor a 10 o "led_LIB" sera acesso para informar que à vaga no estacionamento
if (cont < 10){
  digitalWrite(led_LIB, 1);
  digitalWrite(led_LOT, 0);
}else{ //caso isso nao ocorra ele continuara normal
  digitalWrite(led_LIB, 0);
}

//caso o contador chegar a 0 o "led_VER" sera acesso para informar para o operador verificar se esta tudo certo
if (cont == 0){
  digitalWrite(led_VER, 1);
  digitalWrite(led_LOT, 0);
}else{ //caso isso nao ocorra ele continuara normal
  digitalWrite(led_VER, 0);
}

//se o botão BOT for precisonado ele resetara as informações, voltando a contagem para 0
if (BOT == 1) {
  cont = 0;
}
}