/****************************************************************************************
 Robot Movil

  Programa para controlar un robot móvil de dos motores usando un módulo L298N, 
  permite controlar la velocidad movimientos del robot.  

 
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
  pin IN4 -> D3 Arduino
  pin OUT1-> +MA (Motor Izquierdo) 
  pin OUT2-> -MA (Motor Izquierdo) 
  pin OUT3-> -MB (Motor Derecho) 
  pin OUT4-> +MB (Motor Derecho) 
  ------------------
  *Puede cambiar las conexiones a otros pines del arduino modificando las variables que definen los pines
  *Si uno de los motores gira en sentido incorrecto, invertir su conexión 

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
  
  Mover_Adelante(200); //Desplazamiento hacia adelante con velocidad de 200(PWM 0-250)
  Serial.println("Desplazamiento hacia adelante");
  delay(3000);

  Mover_Izquierda(200); //Giro a la izquierda con velocidad de 200(PWM 0-250)
  Serial.println("Giro a la izquierda");
  delay(2000);

  Mover_Adelante(200); //Desplazamiento hacia adelante con velocidad de 200(PWM 0-250)
  Serial.println("Desplazamiento hacia adelante");
  delay(3000);
  
  Mover_Derecha(200); //Giro a la derecha con velocidad de 200(PWM 0-250)
  Serial.println("Giro a la derecha");
  delay(2000);

  Mover_Retroceso(200); //Desplazamiento hacia atrás con velocidad de 200(PWM 0-250)
  Serial.println("Desplazamiento hacia atras");
  delay(3000);

  Mover_Stop(); //Detener el Robot
  Serial.println("Robot Detenido");
  delay(2000);

  Mover_Diferencial(250,180); //Desplazamiento hacia adelante con dirección derecha
  Serial.println("Desplazamiento hacia adelante-derecha");
  delay(3000);

  Mover_Stop(); //Detener el Robot
  Serial.println("Robot Detenido");
  delay(2000);
       
}


//función para desplazarse hacia adelante
void Mover_Adelante(int velocidad) //velocidad 0-250
{
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);  
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
  analogWrite(PinENA,velocidad);
  analogWrite(PinENB,velocidad);
}

//función para desplazarse hacia atrás
void Mover_Retroceso(int velocidad) //velocidad 0-250
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);  
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
  analogWrite(PinENA,velocidad);
  analogWrite(PinENB,velocidad);
}

//función para girar hacia la derecha
void Mover_Derecha(int velocidad) //velocidad 0-250
{
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);  
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
  analogWrite(PinENA,velocidad);
  analogWrite(PinENB,velocidad);
}

//función para girar hacia la izquierda
void Mover_Izquierda(int velocidad) //velocidad 0-250
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);  
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
  analogWrite(PinENA,velocidad);
  analogWrite(PinENB,velocidad);
}

//función para detener el robot
void Mover_Stop() 
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, LOW);  
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, LOW);
  analogWrite(PinENA,0);
  analogWrite(PinENB,0);
}

//función para desplazamiento diferencial, permite hacer curvas suaves
//a mayor diferencia de velocidades la curva será más pronunciada
void Mover_Diferencial(int vel_izquierda, int vel_derecha) //velocidades 0-250
{
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);  
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
  analogWrite(PinENA,vel_izquierda);
  analogWrite(PinENB,vel_derecha);
}
