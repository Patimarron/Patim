#include <Servo.h>
int trigPin = 10;
int echoPin = 11;
int Limite = 30 ;                  // Medida en vacío del senso
Servo boca;
Servo ojos;
int pos;

void setup()
{ Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  boca.attach(9);
  ojos.attach(3);
}

void loop()
{


  if ( measureDistance() < Limite) {

    int t = random (1, 5); //4azul  5rojo 6verde
    boca.write(100);
    if (t == 1) {
      digitalWrite(4, HIGH) ;
    } else if (t == 2) {
      digitalWrite(5, HIGH) ;
    } else if (t == 3) {
      digitalWrite (6, HIGH) ;
    } else if (t == 4) {
      digitalWrite(5, HIGH) ;
      digitalWrite (4, HIGH) ;
    } else if (t == 5) {
      digitalWrite (5, HIGH) ;
    }
    ojos.write(20);
    delay(200);
    delay(1500);
    boca.write(0);
    delay(200);
    boca.write(100);
    delay(200);
    boca.write(0);
    delay(200);
    boca.write(90);
    delay(200);
    boca.write(0);
    delay(200);
    boca.write(100);
    delay(200);

    while (measureDistance() < Limite) {

    }
    digitalWrite (4, LOW) ;
    digitalWrite (5, LOW) ;
    digitalWrite (6, LOW) ;
    ojos.write(40);
    delay(1000);
  }
}


long measureDistance() {
  long duracion, distancia ;
  digitalWrite(trigPin, LOW);        // Nos aseguramos de que el trigger está desactivado
  delayMicroseconds(2);              // Para asegurarnos de que el trigger esta LOW
  digitalWrite(trigPin, HIGH);       // Activamos el pulso de salida
  delayMicroseconds(10);             // Esperamos 10µs. El pulso sigue active este tiempo
  digitalWrite(trigPin, LOW);        // Cortamos el pulso y a esperar el echo
  duracion = pulseIn(echoPin, HIGH) ;
  distancia = duracion / 2 / 29.1  ;
  Serial.println(String(distancia) + " cm.") ;
  return distancia;
}
