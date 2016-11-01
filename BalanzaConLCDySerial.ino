/*
 Ejemplo Usando salida serial y LCD
 By: Eduardo V de Miguel
 Date: Octubre 19th, 2016
  
 Libreria en uso: https://github.com/bogde/HX711
 Libreria bajo una GNU GENERAL PUBLIC LICENSE
 

// Conexiones HX711
// Hx711.GND
// Hx711.VDD
// Hx711.Data-OUT - pin #A1 y A2
// Hx711.SigClocK - pin #A0 y A3

// Conexiones del LCD:
// LCD 1.GND 
// LCD 2.VDD
// LCD 3.VO Para maximo contraste a GND 
// LCD 4.RS - pin 12
// LCD 5.RW - par write mode a GND
// LCD 6.En - pin 11
// LCD11.D4 - pin 5
// LCD12.D5 - pin 4
// LCD13.D6 - pin 3
// LCD14.D7 - pin 2
// LCD15.LED1  R220homs a VDD 
// LCD16.LED2  GND 

----------------------------------CODIGO----------------------------------
*/
#include <LiquidCrystal.h>
#include "HX711.h"

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define DOUT1  A1
#define CLK1  A0
#define DOUT2  A2
#define CLK2  A3
HX711 CELDA1(DOUT1, CLK1, 128);
HX711 CELDA2(DOUT2, CLK2, 128);

#define FactorCalibracionCelda_1 43600 //calibrado con  SparkFun_HX711_Calibration sketch
#define FactorCalibracionCelda_2 43600 //calibrado con  SparkFun_HX711_Calibration sketch

void setup() {
  Serial.begin(9600);
  Serial.println("HX711 Kg Meter usando dos celdas de carga half bridge en paralelo");
  lcd.begin(16, 2);
  CELDA1.set_scale(FactorCalibracionCelda_1); //aplico el factor de calibracion de la linea 35
  CELDA1.tare();	//se supone que no hay ningun peso en el momento de encendido y se setea a cero

  CELDA2.set_scale(FactorCalibracionCelda_2); //aplico el factor de calibracion de la linea 35
  CELDA2.tare();	//se supone que no hay ningun peso en el momento de encendido y se setea a cero

  Serial.println("Puesta a CERO:");
}

void loop() {
  Serial.print("Celda1:  ");
  Serial.print(CELDA1.get_units(), 1); //scale.get_units() depende de la libreria, cambia de HX711 a hx711
  Serial.print(" Kilos"); //si cambio esta unidad debo reclaibrar en FactorCalibracion.
  Serial.println();
   Serial.print("Celda2:  ");
  Serial.print(CELDA2.get_units(), 1); //scale.get_units() depende de la libreria, cambia de HX711 a hx711
  Serial.print(" Kilos"); //si cambio esta unidad debo reclaibrar en FactorCalibracion.
  Serial.println();
  Serial.println();
      
    lcd.setCursor(0, 0);
  lcd.print("Celda1: ");
  lcd.print(CELDA1.get_units(), 1); //Muestra el HX711 conectado en A0 y A1
  lcd.print(" Kg");
  lcd.print("       ");
    lcd.setCursor(0, 1);
  lcd.print("Celda2: ");
  lcd.print(CELDA2.get_units(), 1); //Muestra el HX711 conectado en A0 y A1
  lcd.print(" Kg");
  lcd.print("       ");
   
  delay(50); 
  
}
