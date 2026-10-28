// --- Control de carro con Motor Shield L298P ---
// Motor A conectado a M1 (lado izquierdo)
// Motor B conectado a M2 (lado derecho)

// Pines Motor A
#define IN1 12
#define IN2 13
#define ENA 10

// Pines Motor B
#define IN3 9
#define IN4 8
#define ENB 11

// Pines receptor KRF100
#define D0 2   // Botón A → Adelante
#define D1 3   // Botón B → Izquierda
#define D2 4   // Botón C → Atrás
#define D3 5   // Botón D → Derecha

void setup() {
  Serial.begin(9600);

  // Configurar pines del motor
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Configurar pines del receptor
  pinMode(D0, INPUT);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);

  Serial.println("🚗 Sistema listo: Usa los botones A–D para mover el carro.");
}

void loop() {
  if (digitalRead(D0) == HIGH) {        // Botón A → Adelante
    Adelante(200, 200);
    Serial.println("Avanzando...");
  } 
  else if (digitalRead(D1) == HIGH) {   // Botón B → Izquierda
    Izquierda(180, 180);
    Serial.println("Girando a la izquierda...");
  } 
  else if (digitalRead(D2) == HIGH) {   // Botón C → Atrás
    Atras(200, 200);
    Serial.println("Retrocediendo...");
  } 
  else if (digitalRead(D3) == HIGH) {   // Botón D → Derecha
    Derecha(180, 180);
    Serial.println("Girando a la derecha...");
  } 
  else {
    Parar();
  }
}

// --- FUNCIONES DE MOVIMIENTO ---

void Adelante(int velIzq, int velDer) {
  // Ambos motores hacia adelante
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velIzq);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velDer);
}

void Atras(int velIzq, int velDer) {
  // Ambos motores hacia atrás
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, velIzq);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, velDer);
}

void Izquierda(int velIzq, int velDer) {
  // Gira hacia la izquierda: solo se mueve la rueda derecha hacia ADELANTE
  // Motor izquierdo (detenido)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  // Motor derecho (avanza hacia adelante)
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, velDer);
}

void Derecha(int velIzq, int velDer) {
  // Gira hacia la derecha: solo se mueve la rueda izquierda hacia ADELANTE
  // Motor izquierdo (avanza hacia adelante)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, velIzq);

  // Motor derecho (detenido)
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}


void Parar() {
  // Detener ambos motores
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}