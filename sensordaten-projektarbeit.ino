/*
 * Beispiel:  Temperatur und Luftfeuchtigkeitsmesser mit LEDs und LCD für Klimabox
 * Autor:     Daniel Tscheremnych
 * Datum:     05/01/2024 
 */

#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <TM1637TinyDisplay.h>

// Pin-Definitionen
#define DHTPIN 12          // Pin für den DHT-Sensor
#define DHTTYPE DHT22     // DHT 22 (oder DHT11)
#define BLUE_LED 6
#define RED_LED 4
#define GREEN_LED 5
#define POTENTIOMETER A0  // Analogpin für das Potentiometer
#define CLK 10            // Clock Digitalpin für TM1637 Display
#define DIO 11            // Data Digitalpin für TM1637 Display

// Konstanten und Variablen
const int messIntervall = 5000; // Messintervall in Millisekunden
unsigned long letzteMessung = 0;
const float minTemp = 20.0;     // Minimale Temperatur für den Messbereich
float maxTemp = 24.0;           // Maximale Temperatur, wird durch das Potentiometer eingestellt

// Initialisierung von Sensor und Displays
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
TM1637TinyDisplay display(CLK, DIO);

void setup() {
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  dht.begin();
  lcd.init();
  lcd.backlight();
  display.begin();

  Serial.begin(9600);
}

void loop() {
  if (millis() - letzteMessung >= messIntervall) {
    letzteMessung = millis();

    // Temperatur und Luftfeuchtigkeit lesen
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    // Überprüfen, ob Messwerte gültig sind
    if (isnan(h) || isnan(t)) {
      Serial.println("Fehler beim Lesen des Sensors!");
      return;
    }

    // Maximalen Temperaturwert vom Potentiometer einlesen und auf TM1637 Display ausgeben
    maxTemp = map(analogRead(POTENTIOMETER), 0, 1024, 21, 31);
    display.showNumber(maxTemp);

    // LEDs steuern
    if (t < minTemp) {
      digitalWrite(BLUE_LED, HIGH);
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
    } else if (t > maxTemp) {
      digitalWrite(BLUE_LED, LOW);
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
    } else {
      digitalWrite(BLUE_LED, LOW);
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
    }

    // Daten auf dem LCD anzeigen
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("r.F.: ");
    lcd.print(h);
    lcd.print(" %");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print(" C");

    Serial.print("Luftfeuchtigkeit: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperatur: ");
    Serial.print(t);
    Serial.print(" *C\t");
    Serial.print("Max. Temp:");
    Serial.print(maxTemp);
    Serial.println(" *C");
  }
}