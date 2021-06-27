//LED blinking function
void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
}

//SD card passKey: 12345 
//saved as "key.txt"

