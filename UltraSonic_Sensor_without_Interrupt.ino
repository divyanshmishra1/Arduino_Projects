// Define pin assignments for ultrasonic sensor and LED
const int trigPin = 11;    // Trigger pin
const int echoPin = 12;    // Echo pin
const int ledPin = 5;      // LED pin

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set pin modes for trigger, echo, and LED
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
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

  // Convert the duration into distance
  // Speed of sound is approximately 343 m/s or 0.0343 cm/µs
  long cm = duration * 0.0343 / 2;   // Calculate distance in cm
  long inches = duration * 0.0135 / 2;  // Calculate distance in inches

  // Control the LED based on distance
  if (cm <= 100) {
    digitalWrite(ledPin, HIGH); // Turn on LED if distance is less than or equal to 100 cm
  } else {
    digitalWrite(ledPin, LOW);  // Otherwise, turn off LED
  }

  // Print the distance in inches and cm to the serial monitor
  Serial.print(inches);
  Serial.print(" in, ");
  Serial.print(cm);
  Serial.println(" cm");

  delay(250); // Small delay to prevent excessive serial output
}
