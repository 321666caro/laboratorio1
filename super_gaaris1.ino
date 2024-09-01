// Definición de pines para las luces
int ledR = 12;
int ledA = 13;
int ledV = 11;

// Variables para los estados de los LEDs
bool ledRState = false;
bool ledAState = false;
bool ledVState = false;

// Variable para el modo intermitente
bool blinkMode = false;

void setup() {
  // Configurar los pines como salida
  pinMode(ledR, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledV, OUTPUT);
  
  // Iniciar la comunicación serial
  Serial.begin(9600);
  Serial.println("     LABORATORIO LED.");
  mostrarMenu();  // Mostrar el menú al iniciar
 
 
}

void loop() {
  // Verifica si hay datos disponibles en el Serial Monitor
  if (Serial.available()) {
    // Leer el comando enviado desde el Serial Monitor
    char comando = Serial.read();

    // Validación y ejecución de comandos usando switch-case
    switch (comando) {
      case '1':
        ledVState = !ledVState;  // Alternar estado de la luz verde
        digitalWrite(ledV, ledVState ? HIGH : LOW);
        Serial.println(ledVState ? "  LUZ VERDE ENCENDIDA." : "   LUZ VERDE APAGADA.");
        break;
        
      case '2':
        ledRState = !ledRState;  // Alternar estado de la luz roja
        digitalWrite(ledR, ledRState ? HIGH : LOW);
        Serial.println(ledRState ? "LUZ ROKA ENCENDIDA encendida." : "Luz roja apagada.");
        break;
        
      case '3':
        ledAState = !ledAState;  // Alternar estado de la luz amarilla
        digitalWrite(ledA, ledAState ? HIGH : LOW);
        Serial.println(ledAState ? "Luz amarilla encendida." : "Luz amarilla apagada.");
        break;
        
      case '4':
        ledVState = true;  // Encender todas las luces
        ledRState = true;
        ledAState = true;
        digitalWrite(ledV, HIGH);
        digitalWrite(ledR, HIGH);
        digitalWrite(ledA, HIGH);
        Serial.println("Todas las luces encendidas.");
        break;
        
      case '5':
        ledVState = false;  // Apagar todas las luces
        ledRState = false;
        ledAState = false;
        digitalWrite(ledV, LOW);
        digitalWrite(ledR, LOW);
        digitalWrite(ledA, LOW);
        Serial.println("Todas las luces apagadas.");
        break;
        
      case '6':
        blinkMode = !blinkMode;  // Alternar modo intermitente
        if (blinkMode) {
          Serial.println("Modo intermitente activado.");
        } else {
          Serial.println("Modo intermitente desactivado.");
          // Apagar todas las luces si se desactiva el modo intermitente
          digitalWrite(ledV, LOW);
          digitalWrite(ledR, LOW);
          digitalWrite(ledA, LOW);
        }
        break;
        
      default:
        Serial.println("  DATO NO VALIDO.");
        break;
    }
    
    // Volver a mostrar el menú después de cada comando
    mostrarMenu();
  }

  // Si el modo intermitente está activado, parpadea las luces
  if (blinkMode) {
    digitalWrite(ledR, HIGH);
    digitalWrite(ledA, HIGH);
    digitalWrite(ledV, HIGH);
    delay(500);
    digitalWrite(ledR, LOW);
    digitalWrite(ledA, LOW);
    digitalWrite(ledV, LOW);
    delay(500);
  }
}

// Función para mostrar el menú en el Serial Monitor
void mostrarMenu() {//no devuelve ningun valor
  Serial.println("Seleccione una opcion:");
  Serial.println("1: prende /paga luz verde");
  Serial.println("2: prende/paga la luz roja");
  Serial.println("3:prende /paga Luz amarilla");
  Serial.println("4: Encender todas las luces");
  Serial.println("5: Apagar todas las luces");
  Serial.println("6: Activar/Desactivar modo intermitente");
}

