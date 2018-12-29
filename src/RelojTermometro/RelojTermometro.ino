#include <LiquidCrystal_I2C.h>
#include <Wire.h>             //Comunicación serie
#include <Adafruit_Sensor.h>  //Librería para el sensor AM2302
#include <DHT.h>              //Librería auxiliar para el sensor

#define dhtPin 9      //Pin de entrada de datos en el Arduino
#define dhtTipo DHT22 //Estoy utilizando un AM2302 con la misma librería
  
#define lineaTemperatura 2  //Define la linea que ocupa la temperatura
#define lineaHumedad 1      //Define la línea que ocupa la humedad3

LiquidCrystal_I2C lcd(0x38F, 20, 4);
DHT dht(dhtPin, dhtTipo);
void MostrarTemperatura(float temperatura) {
  lcd.clear();
  lcd.setCursor(0, lineaTemperatura);
  lcd.print("Temp: ");
  lcd.print(temperatura);
  lcd.print(" C   ");
}

void MostrarHumedad(float humedad) {
  lcd.setCursor(0, lineaHumedad);
  lcd.print("Humedad: ");
  lcd.print(humedad);
  lcd.print(' ');
}

void setup() {
  Serial.begin(9600);
  delay(3000); 

  dht.begin();
}

void loop() {
  float tempActual = dht.readTemperature(); 
  MostrarTemperatura(tempActual);

  Serial.println(tempActual);

  float humeActual = dht.readHumidity();   
  MostrarHumedad(humeActual);
  Serial.println(humeActual);
     
  delay(4000);          
}   
