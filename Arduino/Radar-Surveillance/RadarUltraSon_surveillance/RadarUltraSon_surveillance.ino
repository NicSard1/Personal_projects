#include <Servo.h> 

const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;
Servo myServo; 

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myServo.attach(3); 
}

void loop() {
  // Fait tourner le moteur servo de 20 à 140 degrés
  for(int i=0; i<=180; i++){  
    myServo.write(i); // Écrit l'angle au servo
    delay(20);
    distance = calculateDistance(); // Calcule la distance mesurée par le capteur ultrason
    
    Serial.print(i); // Envoie l'angle courant sur le port série
    Serial.print(","); // Envoie un caractère additionnel pour la séparation
    Serial.print(distance); // Envoie la valeur de distance sur le port série
    Serial.print("."); // Caractère de fin pour le traitement des données
  }
  // Balaye de retour de 140 à 20 degrés
  for(int i=180; i>=0; i--){  
    myServo.write(i); // Écrit l'angle au servo
    delay(20);
    distance = calculateDistance(); // Calcule à nouveau la distance
    
    Serial.print(i); // Envoie l'angle courant sur le port série
    Serial.print(","); // Caractère de séparation
    Serial.print(distance); // Envoie la valeur de distance
    Serial.print("."); // Caractère de fin
  }
}

int calculateDistance(){ 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Lit la durée du signal de retour
  distance = duration*0.034/2; // Calcule la distance en se basant sur la vitesse du son
  return distance;
}
