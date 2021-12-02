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
const int ledPinA   = 12; // pin van LED voor speler 1
const int pinLedB   = 10; // pin van LED voor speler 2
const int pinLedC   = 9;
const int pinLedD   = 11;
const int knopPinA  = 8; // pin van knop voor speler 1
const int pinKnopB  = 7; // pin van knop voor speler 2
const int pinKnopC  = 6;
const int pinKnopD  = 5;

// variabelen om waarden van sensoren en actuatoren te onthouden
int knopA = 0;
int knopB = 0;
int knopC = 0;
int knopD = 0;

// variabelen voor de toestanden
const int AAN_LOS = 1; // tel af tot spel start
const int AAN_UIT = 2; // speel het spel
const int UIT_IN   = 3; // laat zien wie de winnaar is
int toestand = AAN_LOS;
const int  NOGIETS = 4;
const int UIT_LOS = 5;
const int AAN_IN = 6;
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
  pinMode(ledPinA, OUTPUT);
  pinMode(pinLedB, OUTPUT);
  pinMode(pinLedC, OUTPUT);
  pinMode(pinLedD, OUTPUT);

  // zet pinmode voor knoppen
  pinMode(knopPinA, INPUT);
  pinMode(pinKnopB, INPUT);
  pinMode(pinKnopC, INPUT);
  pinMode(pinKnopD, INPUT);
}

void loop() {
  // lees sensorwaarden
  knopA = digitalRead(knopPinA);
  knopB = digitalRead(pinKnopB);
  knopC = digitalRead(pinKnopC);
  knopD = digitalRead(pinKnopD);

  // bepaal toestand


if (toestand == UIT_LOS) {
    if (digitalRead(knopPinA) == HIGH) {
      toestand = AAN_IN;
      digitalWrite(ledPinA, HIGH);
    }
} 
if (toestand == AAN_IN) {
if (digitalRead(knopPinA) == LOW) {
toestand = AAN_LOS;
      digitalWrite(ledPinA, HIGH);
    }
}


if (toestand == AAN_UIT) {
if (digitalRead(knopPinA) == LOW) {
toestand = AAN_LOS;
      digitalWrite(ledPinA, HIGH);
    }
}

if (toestand == UIT_IN) {
if (digitalRead(knopPinA) == LOW) {
toestand = AAN_LOS;
      digitalWrite(ledPinA, HIGH);
    }
}




  // kleine vertraging, 100 keer per seconde loopen is genoeg
  delay(10);
}
