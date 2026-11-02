const int trigPin = 2; // Pin Trigger Sensor
const int echoPin = 3; // Pin Echo Sensor
const int buzzerPin = 4; // Pin Buzzer
const int greenPin = 5; // Pin para el LED verde (recipiente no lleno)
const int redPin = 6; // Pin para el LED rojo (recipiente lleno)

// Configuración de distancias (en centímetros)
const float alturaTotal = 9.50; // Altura total del recipiente
const float umbralLleno = 2.0; // Distancia mínima para considerar lleno

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);   // Configurar pin Trigger Sensor como salida
  pinMode(echoPin, INPUT);    // Configurar pin Echo Sensor como entrada
  pinMode(buzzerPin, OUTPUT); // Configurar pin Buzzer como salida
  pinMode(greenPin, OUTPUT);  // Configurar pin del LED verde como salida
  pinMode(redPin, OUTPUT);    // Configurar pin del LED rojo como salida

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


  // Lógica de detección de llenado
  if (distancia <= umbralLleno && distancia > 0.5) {      // Recipiente LLENO
  Serial.println("¡ALERTA: El recipiente está LLENO!");
  digitalWrite(buzzerPin, HIGH);                          // Encender buzzer
  digitalWrite(redPin, HIGH);                             // Encender LED rojo
  digitalWrite(greenPin, LOW);                            // Apagar LED verde
  } else {                                                // Recipiente en proceso de llenado o vacío
    digitalWrite(buzzerPin, LOW);                         // Apagar buzzer
    digitalWrite(redPin, LOW);                            // Apagar LED rojo
    digitalWrite(greenPin, HIGH);                         // Encender LED verde (se mantiene verde)

    if (distancia > alturaTotal) {
      Serial.println("Recipiente vacío o fuera de rango.");
    } else {
      Serial.println("Recipiente llenándose...");
    }

  }

  delay(1000); // Esperar 1 segundo entre mediciones
}