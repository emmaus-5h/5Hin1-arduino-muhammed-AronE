/*****************************************
   Game Startcode
   met toestansdiagrammen
   Emmauscollege
   v20201114GEE
 *****************************************/

/*****************************************
   variabelen die je gebruikt maken
 *****************************************/
// gebruikte pinnen
const int pinLedA   = 12; // pin van LED voor speler 1
const int pinLedB   = 10; // pin van LED voor speler 2
const int pinLedC   = 9;
const int pinLedD   = 11;
const int pinKnopA  = 8; // pin van knop voor speler 1
const int pinKnopB  = 7; // pin van knop voor speler 2
const int pinKnopC  = 6;
const int pinKnopD  = 5;

// variabelen om waarden van sensoren en actuatoren te onthouden
int knopA = 0;
int knopB = 0;
int knopC = 0;
int knopD = 0;

// variabelen voor de toestanden
int toestand = 1;
const int KNOP = 2; // tel af tot spel start
const int AAN = 3;
unsigned long toestandStartTijd = 0;
unsigned long beginTijd = 0;

/*****************************************
   functies die je gebruikt maken
 *****************************************/
// code die steeds wordt uitgevoerd in toestand TELAF
void telafLoop() {
  // tel af
}

// code die steeds wordt uitgevoerd in toestand SPEEL
void speelLoop() {
  // speel spel
}

// code die steeds wordt uitgevoerd in toestand SPEEL
void winLoop() {
  // toon wie gewonnen heeft
}


/*****************************************
   setup() en loop()
 *****************************************/

void setup() {
  // enable console en stuur opstartbericht
  Serial.begin(9600);
  Serial.println("Game start");

  // zet pinmode voor leds
  pinMode(pinLedA, OUTPUT);
  pinMode(pinLedB, OUTPUT);
  pinMode(pinLedC, OUTPUT);
  pinMode(pinLedD, OUTPUT);

  // zet pinmode voor knoppen
  pinMode(pinKnopA, INPUT);
  pinMode(pinKnopB, INPUT);
  pinMode(pinKnopC, INPUT);
  pinMode(pinKnopD, INPUT);
}

void loop() {
  // lees sensorwaarden
  knopA = digitalRead(pinKnopA);
  knopB = digitalRead(pinKnopB);
  knopC = digitalRead(pinKnopC);
  knopD = digitalRead(pinKnopD);

  // bepaal toestand
  
if (toestand == AAN) {
  digitalWrite(pinLedA, HIGH);
  if (millis()-beginTijd >= 1000) {
  digitalWrite(pinLedA, LOW);
  toestand = KNOP;
beginTijd = millis();
}
}
if (toestand == KNOP) {
  if (millis() -beginTijd >= 3000) {
    (digitalRead(pinKnopA) == LOW); 
      digitalWrite(pinLedA, LOW);
    
    }
      toestand = AAN;
    } else {
        digitalWrite(pinLedA, HIGH);
       
    }
  



  // kleine vertraging, 100 keer per seconde loopen is genoeg
  delay(10);
}
