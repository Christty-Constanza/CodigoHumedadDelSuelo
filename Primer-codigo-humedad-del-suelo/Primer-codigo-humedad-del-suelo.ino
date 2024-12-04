#include <LCDI2C_UTF8.h>
#include <ROM_Standard_EU.h>
#include <Wire.h>
LiquidCrystal_I2C_UTF8 lcd(0x27, 16, 2);  // I2C address: 0x27; Display size: 20x4

// Definición del pin donde se conecta el sensor de humedad
const int sensorPin = A0; // Pin AO del sensor conectado al pin digital 2 del Arduino

void setup() {
  // Inicializar la pantalla LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Humedad:");

   // Iniciar la comunicación serie
  Serial.begin(9600);  // Configurar la velocidad de transmisión a 9600 baudios

  // Configurar el pin del sensor como entrada
  pinMode(sensorPin, INPUT);
}

void loop() {
  // Limpiar la pantalla al inicio del loop
  lcd.clear();

  // Volver a escribir el título en la primera línea
  lcd.setCursor(0, 0);
  lcd.print("Humedad:");

  // Leer el valor analógico del sensor de humedad
  int humedadValor = analogRead(sensorPin);

  // Convertir el valor a un porcentaje (opcional, según el sensor usado)
  int humedadPorcentaje = map(humedadValor, 0, 1023, 0, 100);

  // Mostrar el valor en la pantalla LCD
  lcd.setCursor(0, 1);  // Segunda línea de la pantalla
  lcd.print("Valor: " + String(humedadPorcentaje) + "%   ");

    // Imprimir el valor en el Monitor Serial
  Serial.print("Humedad: ");
  Serial.print(humedadPorcentaje);
  Serial.println("%");  // Imprime el porcentaje y salta a la siguiente línea


  // Esperar un tiempo antes de la siguiente lectura
  delay(1000);
}