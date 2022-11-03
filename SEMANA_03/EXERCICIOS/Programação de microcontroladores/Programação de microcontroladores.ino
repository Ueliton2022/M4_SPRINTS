int ldr = 13;
int button1 = 1;
int button2 = 2;
int led1 = 38;
int led2 = 39;
int led3 = 40;
int led4 = 41;
int buzzer = 7; 
int soundBuzzer = 700; 
int binary[4] = {0,0,0,0};

void setup() {

  Serial.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(buzzer, OUTPUT);

  }


void loop(){

  int button1Value = digitalRead(button1);
  Serial.println(button1Value);
  int button2Value = digitalRead(button2);

  if (button1Value==1){
    delay(1000);
    int ldrValue = analogRead(ldr);
    Serial.println(ldrValue); // print o valor exato do ldr
    ldrValue = ldrValue/273; // Divisão que converte dentro de um intervalo de  0 a 15.
    Serial.println(ldrValue);
    soundBuzzer = ldrValue*250; // definindo a frequencia do som multiplicado por 250 (valor aleatório)
    tone(buzzer, soundBuzzer, 1000);
    for (int i=3; ldrValue !=0; i--){
      binary[i] = (ldrValue%2);
      ldrValue = ldrValue/2; // converte valor
    }
    for(int convert:binary){ // Converte o valor para binário
      Serial.print(convert);
      Serial.print(" ");
    }
    Serial.print("\n"); // Pulando linha para organização do print no Serial Monitor
    for (int i = 0; i < 4; i++){
      Serial.print(binary[i]);
      Serial.print(" ");
    }
    if (binary[0] == 1){
      digitalWrite(led1, HIGH);
    }
    if(binary[1] == 1){
      digitalWrite(led2, HIGH);
    };
    if(binary[2] == 1){
      digitalWrite(led3, HIGH);
    };
    if(binary[3] == 1){
      digitalWrite(led4, HIGH);
    };
    delay(3000);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  int buttonkingValue = digitalRead(button2);
  if (buttonkingValue == 1){
    tone(buzzer, soundBuzzer, 1000);
    if (binary[0] == 1){
      digitalWrite(led1, HIGH);
      delay(200);
    }
    if(binary[1] == 1){
      digitalWrite(led2, HIGH);
      delay(200);
    };
    if(binary[2] == 1){
      digitalWrite(led3, HIGH);
      delay(200);
    };
    if(binary[3] == 1){
      digitalWrite(led4, HIGH);
      delay(200);
    };
    delay(500);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    soundBuzzer = 0;
    for (int i = 0; i < 4; i++){
      binary[i] = 0;
    }
  }
}
