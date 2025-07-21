// Codigo para controlar un sensor de vibracion 
//Prende un LED y un zumbador dependiendo de que tanto se vibre el sensor 

byte led1 = 2;
byte zumbador = 3;
byte sensor = 4;

bool vibracion;
int lecturas = 0;
unsigned long tiempoInicio = 0;
unsigned long tiempoActual = 0;
const unsigned long tiempoEspera = 1000; // Tiempo en milisegundos (1 segundo)

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(zumbador, OUTPUT);
  pinMode(sensor, INPUT);
 
}

void loop() {
  // Obtener el tiempo actual
  tiempoActual = millis();
  vibracion = digitalRead(sensor);

  //lecturas = lecturas + vibracion;
  lecturas += vibracion;

  Serial.println(lecturas);

  // Si ha pasado 1 segundo
  if (tiempoActual - tiempoInicio >= tiempoEspera) {
    Serial.print("Suma de lecturas: ");
    Serial.println(lecturas);
    
    // Reiniciar variables
    lecturas = 0;
    tiempoInicio = tiempoActual; // Actualizar el tiempo de inicio
  }
  
  if (lecturas > 60){ // Entre mas pequeño sea el valor que esta en el If MAS SENSIBLE SE VUELVE
    for(byte i = 0; i < 10; i++){
      Serial.print("Ciclo:  ");
      Serial.println(i);
      digitalWrite(led1, HIGH);
      digitalWrite(zumbador, HIGH);
      delay(300);
      digitalWrite(led1, LOW);
      digitalWrite(zumbador, LOW);
      delay(300);
    }
  }
}
