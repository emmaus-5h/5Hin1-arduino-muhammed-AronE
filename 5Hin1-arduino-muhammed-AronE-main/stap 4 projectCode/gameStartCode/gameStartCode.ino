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
const int pinLedRood= 12; // pin van LED voor speler 1
const int pinLedGroen   = 10; // pin van LED voor speler 2
const int pinLedGeel   = 9;
const int pinLedBlauw   = 11;
const int pinKnopRood  = 8; // pin van knop voor speler 1
const int pinKnopGroen  = 7; // pin van knop voor speler 2
const int pinKnopGeel  = 6;
const int pinKnopBlauw  = 5;

// variabelen om waarden van sensoren en actuatoren te onthouden
int knopRood = 0;
int knopGroen = 0;
int knopGeel = 0;
int knopBlauw = 0;

// variabelen voor de toestanden
const int AAN = 1; // tel af tot spel start // 
const int SPEEL = 2; // speel het spel
const int WIN   = 3; // laat zien wie de winnaar is
int toestand = AAN;
unsigned long toestandStartTijd = 0;

/*****************************************
   functies die je gebruikt maken
 *****************************************/
// code die steeds wordt uitgevoerd in toestand AAN
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
  pinMode(pinLedRood, OUTPUT);
  pinMode(pinLedGroen, OUTPUT);
  pinMode(pinLedGeel, OUTPUT);
  pinMode(pinLedBlauw, OUTPUT);

  // zet pinmode voor knoppen
  pinMode(pinKnopRood, INPUT);
  pinMode(pinKnopGroen, INPUT);
  pinMode(pinKnopGeel, INPUT);
  pinMode(pinKnopBlauw, INPUT);
}

void loop() {
  // lees sensorwaarden
  knopRood = digitalRead(pinKnopRood);
  knopGroen = digitalRead(pinKnopGroen);
  knopGeel = digitalRead(pinKnopGeel);
  knopBlauw = digitalRead(pinKnopBlauw);

  // bepaal toestand
  if (toestand == AAN) {
    telafLoop();
    if (digitalRead(pinKnopRood) == LOW ) { // 2 seconden voorbij
      digitalWrite(pinLedRood, HIGH );
    } else 
      digitalWrite(pinLedRood, LOW);
  }
    
  
  if (toestand == SPEEL) {
    speelLoop();
    if (millis() - toestandStartTijd > 5000) { // 5 seconden voorbij
      toestandStartTijd = millis();
      toestand = WIN;
      Serial.println("Nieuwe toestand: WIN");
    }
  
  if (toestand == WIN) {
    winLoop();
    if (millis() - toestandStartTijd > 1000 &&  // 1 seconde voorbij en
        knopRood == HIGH && knopGroen == HIGH) {       // beide knoppen ingedrukt
      toestandStartTijd = millis();
      toestand = AAN;
      Serial.println("Nieuwe toestand: AAN");
        }
  }
  

  // kleine vertraging, 100 keer per seconde loopen is genoeg
