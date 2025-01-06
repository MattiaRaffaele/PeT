#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);

//Il ritardo tra ogni pressione del pulsante
int delayBetweenSkip = 250;

//Il massimo raggiungibile dalle bank
int songId_max = 13;

//VARIABILI BANK
String bank[] = {
  "ZOOTV",
  "Classic"
};
int bank_i = 0;
////////////////////////////
String songId[] = {
  "Zoo Station",
  "The Fly",
  "Mysterious ways",
  "MW-Delay",
  "Until..world",
  "Until..world - dist",
  "Satellite..Love",
  "Bullet the blue sky",
  "Running to Stand Still",
  "Where ... Name",
  "Pride",
  "With or Without You",
  "Love..,Blind",
  "Love...Blind BOOST"
};
int songId_i = 0;
/////////////////////////////

//VOID
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);

  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop() {

  lcd.setCursor(0, 0);
  lcd.print(bank[bank_i]);
  lcd.setCursor(0, 1);
  lcd.print(songId[songId_i]);

  //Numerino
  lcd.setCursor(14, 0);
  lcd.print(songId_i);

  if (digitalRead(3)==HIGH){
    goRight();
    lcd.clear();
  }
  else if (digitalRead(2)==HIGH){
    goLeft();
    lcd.clear();
  }
  else{}

  //Assicura che ogni libreria non vada fuori limite (0< o > max), e ritorna a 0
  if (songId_i > songId_max || songId_i<0){
    songId_i = 0;
  }
}

void goRight(){
  songId_i++;
  delay(delayBetweenSkip);
}

void goLeft(){
  songId_i--;
  delay(delayBetweenSkip);
}
