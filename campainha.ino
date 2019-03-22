#define campainha 3 //pino para campainha exterior
#define sensing 2   //pino para leitura dos fios do video porteiro
long tempo = 500;   //duração do toque da campainha exterior em milisegundos

byte on = 0;

void setup() {
  pinMode(sensing, INPUT);
  pinMode(campainha, OUTPUT);
  digitalWrite(campainha, 0);
}

void loop() {
  if (digitalRead(sensing) == 0 && on == 0) {
    delay(500);
    if (digitalRead(sensing) == 0) {
      on = 1;
      digitalWrite(campainha, 1);
      delay(tempo);
      digitalWrite(campainha, 0);
      delay(tempo*4);
      digitalWrite(campainha, 1);
      delay(tempo);
      digitalWrite(campainha, 0);
    }
  }
  if (digitalRead(sensing) == 1) {
    on = 0;
  }
  delay(10);
}
