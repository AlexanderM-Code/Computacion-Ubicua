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
#define D0 2    // Botón A → Adelante
#define D1 3    // Botón B → Izquierda
#define D2 4    // Botón C → Atrás
#define D3 5    // Botón D → Derecha

// *** AJUSTE DE VELOCIDADES ***
const int VELOCIDAD_RECTA = 255; 
const int VELOCIDAD_GIRO = 200;

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
  if (digitalRead(D0) == HIGH) {
    Adelante(VELOCIDAD_RECTA, VELOCIDAD_RECTA);
    Serial.println("Avanzando...");
  }
  else if (digitalRead(D1) == HIGH) {
    Izquierda(VELOCIDAD_GIRO, VELOCIDAD_GIRO); // Ahora es giro de tanque
    Serial.println("Girando a la izquierda (Tanque)...");
  }
  else if (digitalRead(D2) == HIGH) {
    Atras(VELOCIDAD_RECTA, VELOCIDAD_RECTA);
    Serial.println("Retrocediendo...");
  }
  else if (digitalRead(D3) == HIGH) {
    Derecha(VELOCIDAD_GIRO, VELOCIDAD_GIRO); // Ahora es giro de tanque
    Serial.println("Girando a la derecha (Tanque)...");
  }
  else {
    Parar();
  }
}

// --- FUNCIONES DE MOVIMIENTO (MODIFICADAS) ---

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
  
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, LOW); 
  analogWrite(ENA, 0); 


  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW); 
  analogWrite(ENB, velDer); 
}

void Derecha(int velIzq, int velDer) {
  
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW); 
  analogWrite(ENA, velIzq); 

  
  digitalWrite(IN4, LOW);  
  digitalWrite(IN3, LOW); 
  analogWrite(ENB, 0); 
}


void Parar() {
  // Detener ambos motores
  digitalWrite(IN1, LOW); //desactiva la direccion del motor A
  digitalWrite(IN2, LOW); //desactiva la direccion del motor A
  digitalWrite(IN3, LOW); //desactiva la direccion del motor B
  digitalWrite(IN4, LOW); //desactiva la direccion del motor b 
  analogWrite(ENA, 0); // detiene el motor A
  analogWrite(ENB, 0); // detiene el motor B
}