# Ejemplos_L298N
Códigos de ejemplo para el módulo L298N

![Driver Puente H L298N 2A](https://naylampmechatronics.com/146-large_default/driver-puente-h-l298n.jpg)

Información detallada del módulo L298N en: [Tutorial L298N](https://naylampmechatronics.com/blog/11_Tutorial-de-Uso-del-M%C3%B3dulo-L298N.html)

## Contenido
* **SimpleMotor:** Control de un motor, permite girar el motor en sentido horario, sentido antihorario y detener el motor.
* **PwmMotor:** Control de un motor, permite controlar la velocidad, sentido horario, sentido antihorario y detener el motor.
* **DobleMotor:** Control de dos motores, permite controlar de forma independiente la velocidad, y giros de cada motor.  
* **RobotMovil:** Programa para controlar un robot móvil de dos motores usando un módulo L298N, 
  permite controlar la velocidad y movimientos del robot.  
 
## Requerimientos
 **Software**
  * IDE Arduino
  
 **Hardware**
  * [Arduino Uno](https://naylampmechatronics.com/arduino-tarjetas/8-arduino-uno-r3.html) (o cualquier modelo)
  * [Módulo L298N](https://naylampmechatronics.com/drivers/11-driver-puente-h-l298n.html)
  * Motor DC
  * Fuente DC (mismo voltaje que el motor)
  
## Conexiones
### Ejemplo 1: SimpleMotor
|Módulo L298N ||
|----|-----|
  pin +12V  | +12V(o voltaje del motor) 
  pin GND | GND (GND de fuente y Arduino unidos) 
  pin +5V | NC (Sin jumper conectar a +5V) 
  pin ENA | Jumper
  pin IN1 | D7 Arduino
  pin IN2 | D6 Arduino
  pin OUT1| +M (motor) 
  pin OUT2| -M (motor) 


### Ejemplo 2: PwmMotor
|Módulo L298N ||
|----|-----|
  pin +12V  | +12V(o voltaje del motor) 
  pin GND | GND (GND de fuente y Arduino unidos) 
  pin +5V | NC (Sin jumper conectar a +5V) 
  pin ENA | D8 Arduino
  pin IN1 | D7 Arduino
  pin IN2 | D6 Arduino
  pin OUT1| +M (motor) 
  pin OUT2| -M (motor) 


### Ejemplo 3: DobleMotor
|Módulo L298N ||
|----|-----|
  pin +12V  | +12V(o voltaje del motor) 
  pin GND | GND (GND de fuente y Arduino unidos) 
  pin +5V | NC (Sin jumper conectar a +5V) 
  pin ENA | D8 Arduino
  pin IN1 | D7 Arduino
  pin IN2 | D6 Arduino
  pin ENB | D5 Arduino
  pin IN3 | D4 Arduino
  pin IN4 | D3 Arduin0
  pin OUT1| +MA (Motor A) 
  pin OUT2| -MA (Motor A) 
  pin OUT3| +MB (Motor B) 
  pin OUT4| -MB (Motor B) 
  
  
 ### Ejemplo 4: RobotMovil
|Módulo L298N ||
|----|-----|
  pin +12V  | +12V(o voltaje del motor) 
  pin GND | GND (GND de fuente y Arduino unidos) 
  pin +5V | NC (Sin jumper conectar a +5V) 
  pin ENA | D8 Arduino
  pin IN1 | D7 Arduino
  pin IN2 | D6 Arduino
  pin ENB | D5 Arduino
  pin IN3 | D4 Arduino
  pin IN4 | D3 Arduino
  pin OUT1| +MA (Motor Izquierdo) 
  pin OUT2| -MA (Motor Izquierdo) 
  pin OUT3| -MB (Motor Derecho) 
  pin OUT4| +MB (Motor Derecho) 
  
  
Las conexiones son las mismas para cualquier modelo de arduino

Puede cambiar las conexiones a otros pines del arduino modificando las variables que definen los pines

## Licencia
Los ejemplos son Open Source, creados por el equipo de Naylamp Mechatronics bajo [licencia MIT](LICENSE)
 
## Links 
 * [Tutorial de Uso del Módulo L298N](https://naylampmechatronics.com/blog/11_Tutorial-de-Uso-del-M%C3%B3dulo-L298N.html)
 * [Driver Puente H L298N 2A](https://naylampmechatronics.com/drivers/11-driver-puente-h-l298n.html)
