// Using the same Arduino code from class experiments
#define NUM_SENSORS 6
int sensorPins[NUM_SENSORS] = {A0, A1, A2, A3, A4, A5};
int sensorValues[NUM_SENSORS];
void setup() {
    Serial.begin(9600);
    for (int i = 0; i < NUM_SENSORS; i++) {
        pinMode(sensorPins[i], INPUT);
    }
}
void loop() {
    for (int i = 0; i < NUM_SENSORS; i++) {
        sensorValues[i] = analogRead(sensorPins[i]);
    }
   
    int threshold = 500;
    int binary[NUM_SENSORS];
    for (int i = 0; i < NUM_SENSORS; i++) {
        binary[i] = (sensorValues[i] > threshold) ? 0 : 1;
    }
   
    if (binary[0] == 1 && binary[1] == 1 && binary[2] == 1 &&
        binary[3] == 1 && binary[4] == 1 && binary[5] == 1) {
        Serial.println("STOP");
    }
    else if (binary[0] == 0 && binary[1] == 0 && binary[2] == 0 &&
             binary[3] == 0 && binary[4] == 0 && binary[5] == 0) {
        Serial.println("FORWARD");
    }
    else if (binary[0] == 0 || binary[1] == 0) {
        Serial.println("LEFT");
    }
    else if (binary[4] == 0 || binary[5] == 0) {
        Serial.println("RIGHT");
    }
    else {
        Serial.println("UNCERTAIN");
    }
   
    delay(200);
}