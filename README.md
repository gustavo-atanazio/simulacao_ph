# Projeto de monitoramento de pH, temperatura e oxigenação da água

## Descrição

Este projeto utiliza um Arduino Uno para monitorar o nível de pH, a temperatura e a oxigenação de um líquido. Os valores são exibidos em um display LCD I2C e enviados para o monitor serial. A temperatura é medida com um sensor DHT22, e os níveis de pH e oxigenação são simulados usando potenciômetros. [Confira o projeto por este link](https://wokwi.com/projects/399970994004903937).

## Componentes utilizados

- Arduino Uno
- Sensor de temperatura e umidade DHT22
- Display LCD 20x4 I2C
- 2 potenciômetros (para simular sensores de pH e oxigenação)
- Protoboard e fios de conexão

## Esquemático de conexões

### Conexões do sensor DHT22

- VCC -> 5V no Arduino
- GND -> GND no Arduino
- DATA -> Pino 13 no Arduino

### Conexões do display LCD I2C

- SDA -> Pino A4 no Arduino
- SCL -> Pino A5 no Arduino
- VCC -> 5V no Arduino
- GND -> GND no Arduino

### Conexões dos potenciômetros

- Potenciômetro 1 (simula sensor de pH)
  - VCC -> 5V no Arduino
  - GND -> GND no Arduino
  - SIG -> Pino A0 no Arduino

- Potenciômetro 2 (simula sensor de oxigenação)
  - VCC -> 5V no Arduino
  - GND -> GND no Arduino
  - SIG -> Pino A1 no Arduino

## Código fonte
Verifique o arquivo 'sketch.ino'.

## JSON de configuração do Wokwi
Verifique o arquivo 'diagram.json'.

## Como usar

1. Conecte todos os componentes conforme o esquemático acima.
2. Faça upload do código para o Arduino Uno.
3. Abra o monitor serial da IDE do Arduino para visualizar os valores de pH, temperatura e oxigenação.
4. Ajuste os potenciômetros para simular diferentes valores de pH e oxigenação.
5. Observe os valores sendo exibidos no display LCD e no monitor serial.

## Integrantes

- Gustavo Atanazio, RM: 559098
- Lucca Cardinale, RM: 556668