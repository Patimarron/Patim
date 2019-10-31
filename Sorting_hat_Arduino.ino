/*
  Harry Potter Sorting Hat

*/

// these constants won't change:
#include <Servo.h>                    // We tell the progam we are going to use a serve motor in order to include it in the code
int trigPin = 10;                     // The distance sensor trigger is connected to pin 10
int echoPin = 11;                     // The distance sensor echo is connected to pin 10
int Limite = 30 ;                     // Maximum distance 30 cm
Servo boca;                           // We declare a servo motor for the mouth
Servo ojos;                           // We declare a servo motor for the eyes

void setup()
{ Serial.begin (9600);                // use the serial port
  pinMode(trigPin, OUTPUT);           // declare the trigger of the Sensor as as OUTPUT
  pinMode(echoPin, INPUT);            // declare the echo of the Sensor as as INPUT
  pinMode(4, OUTPUT);                 // declare each color of the RGB as as OUTPUT and the pin they are connected to
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  boca.attach(9);                     // the mouth servo is connected to pin 9
  ojos.attach(3);                     // the eyes servo is connected to pin 3
}

void loop()
{
  if ( measureDistance() < Limite) {  // we program checks if the distance of the objects is less to the limit stablished, if it is true the code continues
    int t = random (1, 5);            // the program chooses randomly a numeber between 1 and 5 each one represents a house of Hogwarts (since the orgram rounds up one ose appears two times because otherwise their color would bearly pop up
    boca.write(100);                  // mouth servo goes to a 100º position
    if (t == 1) {                     // if the random variable is 1 do the following:
      digitalWrite(4, HIGH) ;         // turn the green light on (Ravenclaw)
    } else if (t == 2) {              // if the random variable is 2 do the following:
      digitalWrite(5, HIGH) ;         // turn the red light on (Gryffindor)
    } else if (t == 3) {              // if the random variable is 3 do the following:
      digitalWrite (6, HIGH) ;        // turn the blue light on (Slytherin)
    } else if (t == 4) {              // if the random variable is 4 do the following:
      digitalWrite(5, HIGH) ;         // turn the red light on
      digitalWrite (4, HIGH) ;        // turn the green light on, the result the color yellow(Hufflepuff)
    } else if (t == 5) {              // if the random variable is 5 do the following:
      digitalWrite (5, HIGH) ;        // turn the red light on (Gryffindor)
    }
    ojos.write(20);                   // Eyes servo goes to 20º position
    delay(200);
    delay(1500);
    boca.write(0);                    // Mouth servo goes to 0º position
    delay(200);
    boca.write(100);                  // Mouth servo goes to 100º position
    delay(200);
    boca.write(0);                    // Mouth servo goes to 0º position
    delay(200);
    boca.write(90);                   // Mouth servo goes to 90º position
    delay(200);
    boca.write(0);                    // Mouth servo goes to 0º position
    delay(200);
    boca.write(100);                  // Mouth servo goes to 100º position
    delay(200);

    while (measureDistance() < Limite) { // Mantein the position until the distance is bigger than the limir stablished

    }                                 // Once the distance is bigger than the limit, do the following:
    digitalWrite (4, LOW) ;           // Turn the RGB off
    digitalWrite (5, LOW) ;
    digitalWrite (6, LOW) ;
    ojos.write(40);                   // Eyes servo goes to 40º position
    delay(1000);
  }
}


long measureDistance() {
  long duracion, distancia ;
  digitalWrite(trigPin, LOW);                  // We make sure the trigger is disabled
  delayMicroseconds(2);                        // To make sure the trigger is LOW
  digitalWrite(trigPin, HIGH);                 // We activate the output pulse
  delayMicroseconds(10);                       // We wait for 10µs. (the pulse is still active during this 10µs)
  digitalWrite(trigPin, LOW);                  // We cut the pulse and wait until the echo activates
  duracion = pulseIn(echoPin, HIGH) ;          // The duration depends of the pulse detected by the sensor
  distancia = duracion / 2 / 29.1  ;           // We relate the distance to the duration
  Serial.println(String(distancia) + " cm.");  // The program reads and shows the distance meassured by the sensor
  return distancia;                            // The program returns the valur obtained of the distance
}
