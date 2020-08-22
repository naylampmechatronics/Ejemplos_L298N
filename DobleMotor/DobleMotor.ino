/****************************************************************************************
 PWM Motor

  Programa para controlar dos motores con un módulo L298N, permite controlar de forma independiente la velocidad, 
  y giros de cada motor.  
 
 Conexiones:
  -------------------
  Módulo  L298N
  -------------------
  pin +12V  -> +12V(o voltaje del motor) 
  pin GND -> GND (GND de fuente y Arduino unidos) 
  pin +5V -> NC (Sin jumper conectar a +5V) 
  pin ENA -> D8 Arduino
  pin IN1 -> D7 Arduino
  pin IN2 -> D6 Arduino
  pin ENB -> D5 Arduino
  pin IN3 -> D4 Arduino
  pin IN4 -> D3 Arduin
  pin OUT1-> +MA (Motor A) 
  pin OUT2-> -MA (Motor A) 
  pin OUT3-> +MB (Motor B) 
  pin OUT4-> -MB (Motor B) 
  ------------------
  *Puede cambiar las conexiones a otros pines del arduino modificando las variables que definen los pines

 Ejemplo desarrollado por Naylamp Mechatronics bajo licencia MIT (puede copiar, modificar, integrar o redistribuir) 
 
 Última modificación el 21/08/2020

 Más información en:
   -https://naylampmechatronics.com/blog/11_Tutorial-de-Uso-del-M%C3%B3dulo-L298N.html
   -https://github.com/naylampmechatronics/Ejemplos_L298N

 **************************************************************************************************/

//definición de pines
const int PinENA = 8;
const int PinIN1 = 7;
const int PinIN2 = 6;
const int PinENB = 5;
const int PinIN3 = 4;
const int PinIN4 = 3;

void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  // configuramos los pines como salida
  pinMode(PinENA, OUTPUT);
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  pinMode(PinENB, OUTPUT);
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);
  //Inicializamos los pines
  analogWrite(PinENA,0);
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, LOW);
  analogWrite(PinENB,0);
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, LOW);
  
}

void loop() {
  
  MotorA_Horario(200); //Motor A horario con velocidad de 200(PWM 0-250)
  MotorB_Horario(150); //Motor B horario con velocidad de 150(PWM 0-250)
  Serial.println("Giro del Motor A y B en sentido horario");
  delay(5000);
  
  MotorA_Antihorario(200);  //Motor A horario con velocidad de 200(PWM 0-250)
  MotorB_Antihorario(150);  //Motor B horario con velocidad de 150(PWM 0-250)
  Serial.println("Giro del Motor A y B en sentido antihorario");
  delay(5000);

  MotorB_Horario(250); //Motor B horario a maxima velocidad;
  Serial.println("Giro del Motor B a maxima velocidad");
  delay(3000);
  
  MotorA_Stop(); //Motor Apagado
  MotorB_Stop(); //Motor Apagado
  Serial.println("Motor A y B detenidos");
  delay(3000);
    
}

//función para girar el motor A en sentido horario
void MotorA_Horario(int velocidad) //velocidad 0-250
{
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);
  analogWrite(PinENA,velocidad);
}
//función para girar el motor A en sentido anthorario
void MotorA_Antihorario(int velocidad) //velocidad 0-250
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
  analogWrite(PinENA,velocidad);
}

//función para apagar el motor A
void MotorA_Stop()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, LOW);
  analogWrite(PinENA,0);
}

//función para girar el motor B en sentido horario
void MotorB_Horario(int velocidad) //velocidad 0-250
{
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
  analogWrite(PinENB,velocidad);
}
//función para girar el motor B en sentido anthorario
void MotorB_Antihorario(int velocidad) //velocidad 0-250
{
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
  analogWrite(PinENB,velocidad);
}

//función para apagar el motor B
void MotorB_Stop()
{
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, LOW);
  analogWrite(PinENB,0);
}
