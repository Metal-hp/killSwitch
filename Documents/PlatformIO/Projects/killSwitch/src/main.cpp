/* Reads SD card .txt file and copies it to a string. String is later to
be compared with password. If string and password match, returns 1.
*/

#include <SPI.h>
#include <SD.h>
#include <string.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

File myFile;
String pass = "";
int key = 123; //Built-in key.
LiquidCrystal_I2C lcd(0x27, 16, 2); //Object, LCD.

byte Skull[] = {
  B00000,
  B01110,
  B10101,
  B11011,
  B01110,
  B01110,
  B00000,
  B00000
};

void setup() {
  lcd.init(); //Initialize LCD.
  lcd.backlight(); // LCD backlight.
  lcd.createChar(0, Skull);
  pinMode(2, OUTPUT); //red LED.
  pinMode(3, OUTPUT); //green LED.
  pinMode(6, OUTPUT); //Signal to MOSFET.
  Serial.begin(9600);
  while(!Serial) {
    ;
  }

  Serial.println("Initializing SD card...");
  if(!SD.begin()) {
    Serial.println("Initialization failed!");
    while(1);
  }

  Serial.println("Initialization done.");
  myFile = SD.open("test.txt");

  Serial.println("SD card contains: ");
  while(myFile.available()) {
    Serial.write(myFile.read());
  }
  myFile.close();

  myFile = SD.open("test.txt");
  while(myFile.available())
    pass += (char)myFile.read();

  Serial.println("String contains: ");
  Serial.println(pass);

  myFile.close();

  //access = key.compareTo(pass);
  if(pass.toInt() == key)
    Serial.println("Access granted!");
  else
    Serial.println("DENIED");
  }

void loop() {
  if(pass.toInt() == key) {
    lcd.setCursor(2,0);
    lcd.write(byte(0));
    lcd.setCursor(4, 0);
    lcd.print("Metal.hp");
    lcd.setCursor(13, 0);
    lcd.write(byte(0));
    lcd.setCursor(0, 1);
    lcd.print("Ignition: READY");
    digitalWrite(6, HIGH);
  }
  else {
    lcd.setCursor(2,0);
    lcd.write(byte(0));
    lcd.setCursor(4, 0);
    lcd.print("Metal.hp");
    lcd.setCursor(13, 0);
    lcd.write(byte(0));
    lcd.setCursor(0, 1);
    lcd.print("Ignition: DENIED");
  }
}
