#define S0 A0		// S0 a pin 4
#define S1 A1		// S1 a pin 5
#define S2 A3		// S2 a pin 6
#define S3 A4		// S3 a pin 7
#define salidaTCS A2	// salidaTCS a pin 8

 
void setup() {
  pinMode(S0, OUTPUT);		// pin 4 como salida
  pinMode(S1, OUTPUT);		// pin 5 como salida
  pinMode(S2, OUTPUT);		// pin 6 como salida
  pinMode(S3, OUTPUT);		// pin 7 como salida
  pinMode(salidaTCS, INPUT);	// pin 8 como salida
  
  digitalWrite(S0,HIGH);	// establece frecuencia de salida
  digitalWrite(S1,LOW);		// del modulo al 20 por ciento
  
  Serial.begin(9600);		// inicializa monitor serie a 9600 bps
}

void loop() {
  digitalWrite(S2,LOW);			// establece fotodiodos
  digitalWrite(S3,LOW);			// con filtro rojo
  int rojo = pulseIn(salidaTCS, LOW);	// obtiene duracion de pulso de salida del sensor
  delay(200);				// demora de 200 mseg
  
  digitalWrite(S2,HIGH);		// establece fotodiodos
  digitalWrite(S3,HIGH);		// con filtro verde
  int verde = pulseIn(salidaTCS, LOW);	// obtiene duracion de pulso de salida del sensor
  delay(200);				// demora de 200 mseg
  
  digitalWrite(S2,LOW);			// establece fotodiodos
  digitalWrite(S3,HIGH);		// con filtro azul
  int azul = pulseIn(salidaTCS, LOW);	// obtiene duracion de pulso de salida del sensor
  delay(200);				// demora de 200 mseg
  
  Serial.print("R:");			// muestra texto
  Serial.print(rojo);			// muestra valor de variable rojo

  Serial.print("\t");			// espacio de tabulacion

  Serial.print("V:");			// muestra texto
  Serial.print(verde);			// muestra valor de variable verde

  Serial.print("\t");			// espacio de tabulacion

  Serial.print("A:");			// muestra texto
  Serial.println(azul);			// muestra valor de variable azul
  					// y salto de linea
  
  if ( rojo < 150 && verde > 300 && azul > 60){		// si valores dentro del rango
    Serial.println("ROJO");				// muestra texto
  } 
    else if ( verde < 300 && rojo > 300 && azul > 80){	// si valores dentro del rango
    Serial.println("VERDE");				// muestra texto
  }
    else if ( azul < 50 && rojo > 200 && verde > 100){	// si valores dentrol del rango
    Serial.println("AZUL");				// muestra texto
  }

}