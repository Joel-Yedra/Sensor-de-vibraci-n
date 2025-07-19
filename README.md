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
  ```
  void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(zumbador, OUTPUT);
  pinMode(sensor, INPUT);
  tiempoInicio = millis(); // Inicializar el tiempo de inicio
}
```
5. 
```
void loop() {
  // Obtener el tiempo actual
  tiempoActual = millis();
  vibracion = digitalRead(sensor);

  //lecturas = lecturas + vibracion;
  lecturas += vibracion;

  Serial.println(lecturas);
```




   


