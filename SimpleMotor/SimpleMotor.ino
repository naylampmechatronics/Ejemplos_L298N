/****************************************************************************************
 Simple Motor

  Programa para controlar un motor con un módulo L298N, permite 
  girar el motor en sentido horario, en sentido antihorario y detener el motor.  
 
 Conexiones:
  -------------------
  Módulo  L298N  
  -------------------
  pin +12V  -> +12V(o voltaje del motor) 
  pin GND -> GND (GND de fuente y Arduino unidos) 
  pin +5V -> NC (Sin jumper conectar a +5V) 
  pin ENA -> Jumper
  pin IN1 -> D7 Arduino
  pin IN2 -> D6 Arduino
  pin ENB -> NC 
  pin IN3 -> NC
  pin IN4 -> NC
  pin OUT1-> +M (motor) 
  pin OUT2-> -M (motor) 
  pin OUT3-> NC 
  pin OUT4-> NC
  ------------------
  *Puede cambiar las conexiones a otros pines del arduino modificando las variables que definen los pines

 Ejemplo desarrollado por Naylamp Mechatronics bajo licencia MIT (puede copiar, modificar, integrar o redistribuir) 
 
 Última modificación el 21/08/2020

 Más información en:
   -https://naylampmechatronics.com/blog/11_Tutorial-de-Uso-del-M%C3%B3dulo-L298N.html
   -https://github.com/naylampmechatronics/Ejemplos_L298N

 **************************************************************************************************/

//definición de pines
const int PinIN1 = 7;
const int PinIN2 = 6;

void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  // configuramos los pines como salida
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
}

void loop() {
  
  MotorHorario();
  Serial.println("Giro del Motor en sentido horario");
  delay(5000);
  
  MotorAntihorario();
  Serial.println("Giro del Motor en sentido antihorario");
  delay(5000);
  
  MotorStop();
  Serial.println("Motor Detenido");
  delay(3000);
  
}

//función para girar el motor en sentido horario
void MotorHorario()
{
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);
}
//función para girar el motor en sentido antihorario
void MotorAntihorario()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
}

//función para apagar el motor
void MotorStop()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, LOW);
}
