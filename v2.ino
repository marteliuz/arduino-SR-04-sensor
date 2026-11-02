const int trigPin = 2;   // Pin Trigger Sensor 
const int echoPin = 3;   // Pin Echo Sensor
const int buzzerPin = 4; // Pin Buzzer
const int greenPin = 5;  // Pin para el LED verde (recipiente no lleno)
const int redPin = 6;    // Pin para el LED rojo (recipiente lleno)

// Configuración de distancias (en centímetros)
const float alturaTotal = 9.50;     // Altura total del recipiente
const float umbralLleno = 2.00;      // Distancia mínima para considerar lleno
const float umbralVacio = 8.50;      // Distancia a partir de la cual se considera vacío

bool estadoVerdeBlink = false;      // Variable auxiliar para hacer parpadear el LED verde

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);    // Configurar pin Trigger Sensor como salida
  pinMode(echoPin, INPUT);     // Configurar pin Echo Sensor como entrada
  pinMode(buzzerPin, OUTPUT);  // Configurar pin Buzzer como salida
  pinMode(greenPin, OUTPUT);   // Configurar pin del LED verde como salida
  pinMode(redPin, OUTPUT);     // Configurar pin del LED rojo como salida
  
  // Iniciar con el estado predeterminado (verde encendido, rojo y buzzer apagados)
  digitalWrite(buzzerPin, LOW);
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, LOW);
}
void loop() {
  // Limpiar el pin Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Enviar pulso ultrasónico de 10 microsegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Leer el tiempo que tarda en regresar el eco
  long duracion = pulseIn(echoPin, HIGH);
  
  // Calcular la distancia en cm
  float distancia = duracion * 0.034 / 2;
  
  // Mostrar datos en el Monitor Serie
  Serial.print("Distancia al agua: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  // ESTADO 1: Recipiente LLENO (Distancia menor o igual a 2.0 cm)
  if (distancia <= umbralLleno && distancia > 0.5) {
    Serial.println("¡ALERTA: El recipiente está LLENO!");
    digitalWrite(redPin, HIGH);    // Encender LED rojo
    digitalWrite(greenPin, LOW);   // Apagar LED verde
    digitalWrite(buzzerPin, LOW);  // Asegurar que comience apagado
    
    // Bucle para dar exactamente TRES PITIDOS
    for (int i = 0; i < 3; i++) {
      digitalWrite(buzzerPin, HIGH);
      delay(150);                  // Duración del pitido
      digitalWrite(buzzerPin, LOW);
      delay(150);                  // Pausa entre pitidos
    }
    
  } 
  // ESTADO 2: Recipiente LLENÁNDOSE (Entre 2.0 cm y 6.0 cm)
  else if (distancia > umbralLleno && distancia <= umbralVacio) {
    Serial.println("Recipiente llenándose... (LED verde parpadeando)");
    digitalWrite(redPin, LOW);     // Apagar LED rojo
    digitalWrite(buzzerPin, LOW);  // Apagar buzzer
    
    // Alternar el estado del LED verde para que parpadee en cada ciclo
    estadoVerdeBlink = !estadoVerdeBlink;
    digitalWrite(greenPin, estadoVerdeBlink);
    
  } 
  // ESTADO 3: Recipiente VACÍO (Mayor a 8.5 cm)
  else {
    Serial.println("Recipiente vacío. (LED verde fijo)");
    digitalWrite(redPin, LOW);     // Apagar LED rojo
    digitalWrite(buzzerPin, LOW);  // Apagar buzzer
    digitalWrite(greenPin, HIGH);  // Mantener LED verde encendido fijo
  }
  
  delay(500); // Pausa de medio segundo para que el parpadeo sea fluido
}