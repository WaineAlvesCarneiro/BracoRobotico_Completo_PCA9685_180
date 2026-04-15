#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 150
#define SERVOMAX 600
#define SERVO_FREQ 50

const int GARRA_ABERTA  = 45; //quanto maior menos abre
const int GARRA_FECHADA = 90;
const int GARRA_FECHADA_PEGAR = 82; // quanto maior mais fecha

const int VELOCIDADE = 40;
const int VELOCIDADE_BASE = 80;
const int VELOCIDADE_OMBRO = 100;
const int ESTABILIZAR = 2000;

const int CANAL_BASE = 0;
const int CANAL_OMBRO = 1; 
const int CANAL_COTOVELO = 2;
const int CANAL_PULSO = 3;
const int CANAL_GARRA = 4;

const int PIN_BOTAO = 2; 

int posBase = 90;
int posOmbro = 0;
int posCotovelo = 0;
int posPulso = 0;
int posGarra = GARRA_FECHADA;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_BOTAO, INPUT_PULLUP);
  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ);

  pwm.setPWM(CANAL_BASE, 0, map(90, 0, 180, SERVOMIN, SERVOMAX));
  pwm.setPWM(CANAL_OMBRO, 0, map(0, 0, 180, SERVOMIN, SERVOMAX));
  pwm.setPWM(CANAL_COTOVELO, 0, map(0, 0, 180, SERVOMIN, SERVOMAX));
  pwm.setPWM(CANAL_PULSO, 0, map(0, 0, 180, SERVOMIN, SERVOMAX));
  pwm.setPWM(CANAL_GARRA, 0, map(GARRA_FECHADA, 0, 180, SERVOMIN, SERVOMAX));

  Serial.println("Braço Pronto. Aguardando botão...");
}

void loop() {
  if (digitalRead(PIN_BOTAO) == LOW) {
    delay(250); 
    executarCicloCompleto();
  }
}

void mover(int canal, int &posAtual, int destino, int vel) {
  if (posAtual == destino) return;

  if (posAtual < destino) {
    for (int i = posAtual; i <= destino; i++) {
      pwm.setPWM(canal, 0, map(i, 0, 180, SERVOMIN, SERVOMAX));
      delay(vel);
    }
  } else {
    for (int i = posAtual; i >= destino; i--) {
      pwm.setPWM(canal, 0, map(i, 0, 180, SERVOMIN, SERVOMAX));
      delay(vel);
    }
  }
  posAtual = destino;
}

void executarCicloCompleto() {
  mover(CANAL_BASE, posBase, 0, VELOCIDADE_BASE);
  delay(ESTABILIZAR);

  mover(CANAL_GARRA, posGarra, GARRA_ABERTA, VELOCIDADE);
  delay(ESTABILIZAR);

  mover(CANAL_PULSO, posPulso, 45, VELOCIDADE);
  delay(ESTABILIZAR);

  mover(CANAL_COTOVELO, posCotovelo, 45, VELOCIDADE);
  delay(ESTABILIZAR);

  mover(CANAL_OMBRO, posOmbro, 30, VELOCIDADE_OMBRO);
  delay(ESTABILIZAR);

  mover(CANAL_GARRA, posGarra, GARRA_FECHADA_PEGAR, VELOCIDADE);
  delay(ESTABILIZAR);

  mover(CANAL_PULSO, posPulso, 25, VELOCIDADE);
  delay(ESTABILIZAR);
  
  mover(CANAL_BASE, posBase, 180, VELOCIDADE_BASE);
  delay(ESTABILIZAR);
  
  mover(CANAL_PULSO, posPulso, 42, VELOCIDADE);
  delay(ESTABILIZAR);

  mover(CANAL_GARRA, posGarra, GARRA_ABERTA, VELOCIDADE);
  delay(ESTABILIZAR);

  mover(CANAL_PULSO, posPulso, 25, VELOCIDADE);
  delay(ESTABILIZAR);

  delay(4000);

  resetarParaPosicaoInicial();
}

void resetarParaPosicaoInicial() {
  mover(CANAL_OMBRO, posOmbro, 0, VELOCIDADE_OMBRO);
  delay(ESTABILIZAR);
  mover(CANAL_COTOVELO, posCotovelo, 0, VELOCIDADE);
  delay(ESTABILIZAR);
  mover(CANAL_PULSO, posPulso, 0, VELOCIDADE);
  delay(ESTABILIZAR);
  mover(CANAL_GARRA, posGarra, GARRA_FECHADA, VELOCIDADE);
  delay(ESTABILIZAR);
  mover(CANAL_BASE, posBase, 90, VELOCIDADE_BASE);
  delay(ESTABILIZAR);
}