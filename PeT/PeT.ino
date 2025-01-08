#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);

//Il ritardo tra ogni pressione del pulsante
int delayBetweenSkip = 250;


//VARIABILI BANK
String bankManager[][13]{
  {
    "Zoo Station",
    "The Fly",
    "Mysterious Ways",
    "MW Delay",
    "Until...World",
    "Satellite of Love",
    "Bullet...Sky",
    "Where...Name",
    "Pride",
    "With You",
    "Love...Blind",
    "Love...Blind - BOOST",
    "Can't falling in love"
  },
  {
    "Strat",
    "Metal"
  }
};
int bank_i = 0;
int songId_i = 0;

//VOID
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);

  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop() {
  //Costante
  bankManager[bank_i][songId_i];

  //Bank
  lcd.setCursor(0, 0);
  lcd.print("BANK");

  lcd.setCursor(5, 0);
  lcd.print(bank_i);

  //Song
  lcd.setCursor(9, 0);
  lcd.print("TONE");

  lcd.setCursor(14, 0);
  lcd.print(songId_i);

  lcd.setCursor(0, 1);
  lcd.print(bankManager[bank_i][songId_i]);



  //digitalRead
  if (digitalRead(2)==HIGH){
    goDown();
    lcd.clear();
  }
  else if (digitalRead(3)==HIGH){
    goUp();
    lcd.clear();
  }
  else if (digitalRead(4)==HIGH){
    goLeft();
    lcd.clear();
  }
  else if (digitalRead(5)==HIGH){
    goRight();
    lcd.clear();
  }
  else{}

  //Assicura che ogni libreria non vada fuori limite (0< o > max), e ritorna a 0
  if (bank_i > sizeof(bankManager)/sizeof(bankManager[0])-1 || bank_i<0){
    bank_i = 0;
  }
  if (songId_i > sizeof(bankManager[0])/sizeof(bankManager[0][0]) || songId_i<0){
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

void goUp(){
  bank_i++;
  delay(delayBetweenSkip);
}

void goDown(){
  bank_i--;
  delay(delayBetweenSkip);
}