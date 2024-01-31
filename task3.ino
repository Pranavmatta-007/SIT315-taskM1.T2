const int Sensor = 4;
const int LED = 7;
const int button = 2;

int LED_State = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(Sensor, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), SensorInterrupt, CHANGE);
}

void loop() {
  // Detect motion
  int Motion = digitalRead(Sensor);

  // Process the detection
  if (Motion == HIGH) {
    Serial.println("Motion Detected!");
    LED_State = HIGH;
    digitalWrite(LED, LED_State);
    delay(5000);
  } else {
    Serial.println("No Motion Detected");
    LED_State = LOW;
    digitalWrite(LED, LED_State);
  }

  delay(500);
}

void SensorInterrupt() {
  // Toggle the LED state
  digitalWrite(LED, !LED_State);
  Serial.println("Interupt occured");
  delay(1000);
}
