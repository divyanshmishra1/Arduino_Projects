const int trigPin = 11;    // Trigger
const int echoPin = 12;    // Echo
const int LedPin = 5;

void setup() {
  // Serial Port begin
  Serial.begin(9600);
  // Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LedPin,OUTPUT);
}

void loop() {
  // Trigger the sensor with a HIGH pulse of 10 microseconds
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the duration of the echo pulse
  long duration = pulseIn(echoPin, HIGH);

  // Convert the time into a distance
  long cm = duration * 0.0343 / 2;   // (duration / 2) * 0.0343
  long inches = duration * 0.0135 / 2;  // (duration / 2) * 0.0135
  if(cm <= 100){
    digitalWrite(LedPin, HIGH);
  }
  else{
    digitalWrite(LedPin, LOW);
  }

  // Print the distance in inches and cm
  Serial.print(inches);
  Serial.print(" in, ");
  Serial.print(cm);
  Serial.println(" cm");

  delay(250); // Small delay to prevent excessive serial output
}
