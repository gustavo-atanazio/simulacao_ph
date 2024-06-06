#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Configurando LCD
LiquidCrystal_I2C lcd(0x27, 20, 4);

// Configurando DHT
#define DHTPIN 13
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

int phSensorPin = A0;
int oxiSensorPin = A1;
float fator_compensacao_de_temp_do_liquido = 0.03;

void setup() {
  Serial.begin(9600); // Inicializa monitor serial
  dht.begin(); // Inicializa sensor DHT

  // Inicializa LCD
  lcd.begin(20, 4);
  lcd.setBacklight(HIGH);

  // Organizando layout
  lcd.setCursor(0, 0);
  lcd.print("Dados coletados:");

  lcd.setCursor(0, 1);
  lcd.print("- Nivel de pH:");

  lcd.setCursor(0, 2);
  lcd.print("- Temperatura:");

  lcd.setCursor(0, 3);
  lcd.print("- Oxigenacao:");
}

void loop() {
  float temp = dht.readTemperature(); // Lê a temperatura do sensor DHT

  // Lê o valor do pino analógico do "sensor" de pH e oxigenação
  int phSensorValue = analogRead(phSensorPin);
  int oxiSensorValue = analogRead(oxiSensorPin);

  // Convertendo os valores em números válidos
  float phFinalValue = map(phSensorValue, 0, 1023, 0, 1400) / 100;
  float oxiFinalValue = map(oxiSensorValue, 0, 1023, 0, 100);

  phFinalValue += (temp - 25) * fator_compensacao_de_temp_do_liquido;

  // Garantindo que o valor do pH esteja entre 0 e 14
  if (phFinalValue < 0) phFinalValue = 0;
  if (phFinalValue > 14) phFinalValue = 14;

  // Exibindo pH
  lcd.setCursor(15, 1);
  lcd.print(phFinalValue, 0);

  // Exibindo temperatura
  lcd.setCursor(15, 2);
  lcd.print(temp, 0);
  
  // Exibindo oxigenação
  lcd.setCursor(15, 3);
  lcd.print(oxiFinalValue, 0);

  // Printando valores
  Serial.print("pH: ");
  Serial.println(phFinalValue, 2);

  Serial.print("Temperatura: ");
  Serial.print(temp, 2);
  Serial.println(" °C");

  Serial.print("Oxigenação: ");
  Serial.println(oxiFinalValue, 2);

  delay(1000);
}