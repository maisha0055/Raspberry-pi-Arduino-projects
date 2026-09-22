#Arduino Code:
const int ledPin = 13;
void setup() {
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
Serial.println("Arduino is ready. Waiting for command...
");
}
void loop() {
if (Serial.available() > 0) {
char command = Serial.read();
if (command == '1') {
Serial.println("Button pressed: Blinking LED...
digitalWrite(ledPin, HIGH); // Turn the LED on
delay(1000); // Wait for 1 second
digitalWrite(ledPin, LOW); // Turn the LED off
Serial.println("LED blinked.
");
");
}
}
}