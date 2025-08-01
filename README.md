# 🚨 Arduino Vibration Alert System

This project consists of a homemade vibration alert system developed using Arduino. It was designed as a protective method for vending machines by detecting abnormal vibrations that may indicate tampering or theft attempts.


## 🔧 How does it work?

  1. A vibration sensor monitors the machine movements
  2. Each vibration is recorded and counted by the system.
  3. If the number of vibrations exceeds a predefined threshold, a red LED blinks, and a buzzer is activated 10 times as a warning signal for 
  4. If no suspicious vibration activity is detected, the system remains in a passive state

---

## 🧰 Components Used

-Arduino UNO board
-Vibration sensor (SW-420)
-Red LED
-Buzzer
-Resistor of 220 Ohms
-Jumper wires and breadboard

---



## 🎯 Objective

The objective of the project is to develop a low-cost solution to detect abnormal movements or impacts on vending machines. By issuing visual and audible alerts, the system helps deter theft and provides a basic level of security for publicly accessible equipment.

---

##  🧐 Program Usage

1. We declare the variables that we will use for the pins of each component in the project.
   ```
   byte led1 = 2;
   byte zumbador = 3;
   byte sensor = 4;
   ```
2. We declare the variables that will be used to read the sensor and count the number of vibrations detected by the sensor.
    ```
   bool vibracion;
   int lecturas = 0;
    
   ```
3. Since in this case we don’t want to get readings all the time, we are going to use the polling method to register the sensor readings at specific time intervals.
  ```
  unsigned long tiempoInicio = 0;
  unsigned long tiempoActual = 0;
  const unsigned long tiempoEspera = 1000; // Tiempo en milisegundos (1 segundo)
  ```
4. The pins that will be used as inputs and outputs are declared using the variables from point 1, as well as the serial communication between the Arduino and the computer.

     There is a command called millis() that takes the time in milliseconds since the Arduino board was connected to the computer. It doesn't matter where the line of code is located, because when the program reaches that line where the command is, it will give you the time that has passed since the board was connected up to that point in the code.

    I wanted to give it an initial time using that command, which is why it's in void setup, but simply initializing it to zero is enough, and it's better to use that command inside void loop.

  ```
  void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(zumbador, OUTPUT);
  pinMode(sensor, INPUT);
 /* tiempoInicio = millis(); */ // Inicializar el tiempo de inicio
}
```
5. In addition to using the "millis()" command, we are also going to use the "digitalRead()" command to get all the readings from the sensor and be able to count them later. That’s why we use the variable "lecturas", because it will count the number of vibrations detected by the sensor each time the loop repeats.

```
void loop() {
  // Obtener el tiempo actual
  tiempoActual = millis();
  vibracion = digitalRead(sensor);

  //lecturas = lecturas + vibracion;
  lecturas += vibracion;

  Serial.println(lecturas);

```
6. The variable "tiempoEspera" represents the amount of time we want the sensor to be taking readings and displaying them on the monitor. In order for these readings to appear on the screen, this condition was created to check whether that amount of time has indeed passed.

     We assign the variable "tiempoInicio" to "tiempoActual" so that time can continue passing without issues and we can continue with the readings.
   
```
    if (tiempoActual - tiempoInicio >= tiempoEspera) {
    Serial.print("Suma de lecturas: ");
    Serial.println(lecturas);
    
    // Reiniciar variables
    lecturas = 0;
    tiempoInicio = tiempoActual; // Actualizar el tiempo de inicio
  }
```
7. When a certain number of readings is reached, an LED and a buzzer will turn on and off as an alert signal.

    The number of times this repeats will depend on the value set inside the for loop. In this case, I programmed it to run 10 times.
```
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
```
   
##  📹 Demo Video 

[Arduino Vibration Alert System](https://www.youtube.com/shorts/2jzDF9op100)



   


