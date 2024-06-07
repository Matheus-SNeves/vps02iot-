int sensorAberto = 4;
int sensorFechado = 2;
int botaoComando = 8;
int motorLigado = 12;
int motorDirecao = 13;
int sentidoMotor = 1;
int ledAberto = 5;
int ledFechado = 6;

void setup()
{
  pinMode(sensorAberto, INPUT);
  pinMode(sensorFechado, INPUT);
  pinMode(botaoComando, INPUT);
  pinMode(motorLigado, OUTPUT);
  pinMode(motorDirecao, OUTPUT);
  pinMode(ledAberto, OUTPUT);
  pinMode(ledFechado, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int estadoAberto = digitalRead(sensorAberto);
  int estadoFechado = digitalRead(sensorFechado);
  int comando = digitalRead(botaoComando);
  delay(400);

  if (estadoAberto == HIGH)
  {
    Serial.println("Aberto");
    digitalWrite(motorLigado, 0);
    sentidoMotor = 1;
    digitalWrite(ledFechado, LOW);
  }
  else if (estadoFechado == HIGH)
  {
    Serial.println("Fechado");
    digitalWrite(motorLigado, 0);
    sentidoMotor = 0;
    digitalWrite(ledAberto, LOW);
  }
  else
  {
    digitalWrite(motorDirecao, sentidoMotor);
    if (comando == HIGH)
    {
      sentidoMotor = !sentidoMotor;
      digitalWrite(motorLigado, 1);
      Serial.print("Portão ");
      Serial.println(sentidoMotor ? "abrindo" : "fechando");
    }
  }

  while (true) {
    piscarLed(ledAberto, ledFechado);
    piscarLed(ledFechado, ledAberto);
  }
}

void piscarLed(int led1, int led2)
{
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  delay(200);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(200);
}

