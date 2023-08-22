//Mover a inicial distancia para visualizar que mire a los dos lados, sentido en reloj, condiciones de elección
//Programador: Marvin Araúz
#include <Wire.h> // biblioteca de para la comunicacion en arduino
#include <Servo.h> //biblioteca del servo motor
#define Motor 6
#define MD 8
#define Est 3
#define Trig  13
#define Echo  12
#define Max_distance 200
int Derecha=0;
int Izquierda=0;
int Vuelta=0;
int sentido=0;
int Tempo=0;
int Ida=0;
Servo Servo_S;
Servo Servo_Dire;
9
void stopTime(int mS) {
digitalWrite(Est, LOW);   // Entra en modo de espera
delay(mS);                 // Espera el tiempo definido
digitalWrite(Est, HIGH);  // Sale del modo de espera
}

void setup() {
Serial.begin(9600);
Servo_S.attach(10);
Servo_Dire.attach(11);
pinMode (Motor, OUTPUT);
pinMode (MD, OUTPUT);
pinMode (Est, OUTPUT);
pinMode(Trig, OUTPUT);
pinMode(Echo, INPUT);
}

void loop() {
if (Ida == 0) {
 Servo_S.write(180);
 delay(1500);
 digitalWrite(Trig, LOW);
 delayMicroseconds (2);
 digitalWrite(Trig, HIGH);
 delayMicroseconds (10);
 digitalWrite(Trig, LOW);
 delayMicroseconds (2);
 Izquierda = ((unsigned int)pulseIn(Echo, HIGH)/58);

 Servo_S.write(0);
 delay(1500);
 digitalWrite(Trig, LOW);
 delayMicroseconds (2);
 digitalWrite(Trig, HIGH);
 delayMicroseconds (10);
 digitalWrite(Trig, LOW);
 delayMicroseconds (2);
 Derecha = ((unsigned int)pulseIn(Echo, HIGH)/58);
   if (Derecha < 150 && Izquierda < 150) {
   stopTime(1);
   digitalWrite(MD, LOW); // Forward direction
   analogWrite(Motor, 255); // Full power
   delay(250); //delay 2000mS
   analogWrite(Motor, 0);
   delay(400);
   }

   else {
   Servo_S.write(90);
   delay(1500);
   Ida = Ida+1;
   }
}

else {
 Servo_S.write(90);
 delay(1500);
 digitalWrite(Trig, LOW);
 delayMicroseconds (2);
 digitalWrite(Trig, HIGH);
 delayMicroseconds (10);
 digitalWrite(Trig, LOW);
 delayMicroseconds (2);
 Tempo = ((unsigned int)pulseIn(Echo, HIGH)/58);

 if (Izquierda > Derecha) { //Sentido contrarreloj
   if (Tempo <= 110 && Tempo > 0) { 
   Servo_Dire.write(155);
   delay(2000);
   stopTime(1);
   digitalWrite(MD, LOW); // Forward direction
   analogWrite(Motor, 255); // Full power
   delay(1200); //delay 2000mS
   analogWrite(Motor, 0);
   delay(400);
   Vuelta = Vuelta+1;
   Servo_Dire.write(120);
   delay(1500);
   }
   else {
   Servo_Dire.write(120);
   delay(1500);
   stopTime(1);
   digitalWrite(MD, LOW); // Forward direction
   analogWrite(Motor, 255); // Full power
   delay(300); //delay 2000mS
   analogWrite(Motor, 0);
   delay(400);
   }
   if (Vuelta == 12) {
   Servo_Dire.write(120);
   delay(1500);
   stopTime(1);
   digitalWrite(MD, LOW); // Forward direction
   analogWrite(Motor, 255); // Full power
   delay(1000); //delay 2000mS
   analogWrite(Motor, 0);
   delay(400);
   while (Vuelta == 12) {
   }
   }
 }
 else { //Sentido del reloj
   if (Tempo <= 110 && Tempo > 0) {

   Servo_Dire.write(35);
   delay(2000);
   stopTime(1);
   digitalWrite(MD, LOW); // Forward direction
   analogWrite(Motor, 255); // Full power
   delay(1200); //delay 2000mS
   analogWrite(Motor, 0);
   delay(400);
   Vuelta = Vuelta+1;
   Servo_Dire.write(120);
   delay(1500);
   }
   else {
   Servo_Dire.write(120);
   delay(1500);
   stopTime(1);
   digitalWrite(MD, LOW); // Forward direction
   analogWrite(Motor, 255); // Full power
   delay(300); //delay 2000mS
   analogWrite(Motor, 0);
   delay(400);
   }
   if (Vuelta == 12) {
   Servo_Dire.write(120);
   delay(1600);
   stopTime(1);
   digitalWrite(MD, LOW); // Forward direction
   analogWrite(Motor, 255); // Full power
   delay(1000); //delay 2000mS
   analogWrite(Motor, 0);
   delay(400);
   while (Vuelta == 12) {
   }
   }
 }
}

}


//digitalWrite(MD, LOW); // Forward direction
//analogWrite(Motor, 255); // Full power
//delay(2000); //delay 2000mS
//stopTime(2000);
//digitalWrite(MD, HIGH); // Backward direction
//analogWrite(Motor, 255); // Full power
//delay(2000); //delay 2000mS
//stopTime(2000);

//Servo_Dire.write(100);

//digitalWrite(Trig, LOW);
//delayMicroseconds (2);
//digitalWrite(Trig, HIGH);
//delayMicroseconds (10);
//digitalWrite(Trig, LOW);
//Tempo = ((unsigned int)pulseIn(Echo, HIGH)/58);