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
const int TELAF = 1; // tel af tot spel start
const int SPEEL = 2; // speel het spel
const int WIN   = 3; // laat zien wie de winnaar is
int toestand = TELAF;
unsigned long toestandStartTijd = 0;

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
  if (toestand == TELAF) {
    telafLoop();
    if (millis() - toestandStartTijd > 2000) { // 2 seconden voorbij
      toestandStartTijd = millis();
      toestand = SPEEL;
      Serial.println("Nieuwe toestand: SPEEL");
    }
  }
  if (toestand == SPEEL) {
    speelLoop();
    if (millis() - toestandStartTijd > 5000) { // 5 seconden voorbij
      toestandStartTijd = millis();
      toestand = WIN;
      Serial.println("Nieuwe toestand: WIN");
    }
  }
  if (toestand == WIN) {
    winLoop();
    if (millis() - toestandStartTijd > 1000 &&  // 1 seconde voorbij en
        knopA == HIGH && knopB == HIGH) {       // beide knoppen ingedrukt
      toestandStartTijd = millis();
      toestand = TELAF;
      Serial.println("Nieuwe toestand: TELAF");
    }
  }

  // kleine vertraging, 100 keer per seconde loopen is genoeg
  delay(10);
}
