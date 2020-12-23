#include <Servo.h>

int boton = 4 , LED = 12;
Servo servoSubirBajar;
Servo servoRotarTorreta;

int lecturaEjeX = 0;
int lecturaEjeY = 0;
int anguloEjeX = 0;
int anguloEjeY = 0;


void setup()
{
  servoRotarTorreta.attach(5);
  servoSubirBajar.attach(6);
  
  pinMode( boton, INPUT_PULLUP);
}
    
void loop()
{
  manejarTorre(servoRotarTorreta, A1);
  manejarGrua(servoSubirBajar, A2);

  prenderLuz(boton, LED);
}

void manejarTorre(Servo motorEjeX, int mandoEjeX) {
  lecturaEjeX = analogRead(mandoEjeX);
  anguloEjeX  = map( lecturaEjeX, 0, 1023, 0, 180);
  motorEjeX.write(anguloEjeX);
}

void manejarGrua(Servo motorEjeY, int mandoEjeY {
  lecturaEjeY = analogRead(mandoEjeY);
  anguloEjeY  = map( lecturaEjeY, 0, 1023, 0, 180);
  motorEjeY.write(anguloEjeY);
}

void prenderLuz(int boton, int LED){
  if ( ! digitalRead(boton))
    digitalWrite(LED, HIGH);
  else
    digitalWrite(LED, LOW);
  delay(250) ;
}
