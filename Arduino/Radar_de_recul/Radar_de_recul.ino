#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Définition des dimensions de l'écran OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Initialisation de l'affichage OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

// Définition des pins utilisées
const int trigPin = 11;
const int echoPin = 12;
const int Led = 8;
const int Buzzer = 9;

// Définition des seuils de distance pour les alertes
int distanceDds = 15; // Distance pour débuter les signalements
int distanceDsc = 3;  // Distance pour le signalement continu

// Variables pour la mesure de la distance
float duration, distance;
unsigned long currentTime = 0, previousTime = 0;
boolean etatSignal;

// Variables pour le lissage des lectures
const int numReadings = 5;
float readings[numReadings]; 
int readIndex = 0;
float total = 0, average = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Buzzer, OUTPUT);
  pinMode(Led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialisation de l'écran OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Échec SSD1306 allocation"));
    for (;;); // Boucle infinie en cas d'échec
  }

  // Préparation de l'écran OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  // Initialisation du tableau des lectures
  for (int i = 0; i < numReadings; i++) {
    readings[i] = 0;
  }
}

// Fonction pour dessiner la barre de progression sur l'OLED
void drawProgressBar(int distance, int minDistance, int maxDistance) {
  int progressBarWidth = 100;
  int progressBarHeight = 10;
  int startX = (SCREEN_WIDTH - progressBarWidth) / 2;
  int startY = SCREEN_HEIGHT - 15;

  int fillLength = map(distance, minDistance, maxDistance, 0, progressBarWidth);
  fillLength = constrain(fillLength, 0, progressBarWidth);

  display.drawRect(startX, startY, progressBarWidth, progressBarHeight, WHITE);
  if (fillLength > 0) {
    display.fillRect(startX, startY, fillLength, progressBarHeight, WHITE);
  }
}

void loop() {
  currentTime = millis();
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = max(0.0, duration * 0.034 / 2 - 2); // Ajuste la distance en déduisant 2cm, traite les valeurs < 2cm comme 0cm

  // Gestion des lectures pour le lissage
  total = total - readings[readIndex];
  readings[readIndex] = distance;
  total = total + readings[readIndex];
  readIndex = (readIndex + 1) % numReadings;
  average = total / numReadings;

  // Mise à jour de l'affichage uniquement si la moyenne change
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Projet Radar de recul");
  display.print("Distance : ");
  display.print((int)average); // Affiche la distance moyenne sans décimales
  display.println(" cm");
  drawProgressBar((int)average, distanceDds, 2); // Utilise des valeurs entières pour la barre de progression
  display.display();

  // Logique d'alerte basée sur la distance moyenne
  if (average <= distanceDds) {
    if (average <= distanceDsc) {
      digitalWrite(Led, HIGH);
      digitalWrite(Buzzer, HIGH);
    } else {
      if ((currentTime - previousTime) > average * 10) {
        previousTime = currentTime;
        etatSignal = !etatSignal;
        digitalWrite(Led, etatSignal);
        digitalWrite(Buzzer, etatSignal);
      }
    }
  } else {
    digitalWrite(Led, LOW);
    digitalWrite(Buzzer, LOW);
  }
}
