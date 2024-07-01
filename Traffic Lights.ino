// Define pins for traffic lights and pedestrian lights
int redCar = 13; // Pin for red car light
int yellowCar = 12; // Pin for yellow car light
int greenCar = 11; // Pin for green car light
int greenPed = 2; // Pin for green pedestrian light
int redPed = 3; // Pin for red pedestrian light
int button = 7; // Pin for pedestrian button

// Define timing variables
int crossTime = 2000; // Time for pedestrian to cross
unsigned long changeTime; // Last time the lights were changed
bool carGreenBlink = true; // Flag to blink green car light

void setup() {
  // Initialize the changeTime variable
  changeTime = millis();

  // Set pin modes for traffic lights and pedestrian lights
  pinMode(redCar, OUTPUT);
  pinMode(yellowCar, OUTPUT);
  pinMode(greenCar, OUTPUT);
  pinMode(redPed, OUTPUT);
  pinMode(greenPed, OUTPUT);
  pinMode(button, INPUT);

  // Set initial states for lights
  digitalWrite(greenCar, HIGH); // Green car light on
  digitalWrite(redPed, HIGH); // Red pedestrian light on
  digitalWrite(redCar, LOW); // Red car light off
  digitalWrite(yellowCar, LOW); // Yellow car light off
  digitalWrite(greenPed, LOW); // Green pedestrian light off

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Blink the green car light if carGreenBlink is true
  if (carGreenBlink) {
    digitalWrite(greenCar, !digitalRead(greenCar)); // Toggle green car light
    delay(500); // Wait for 500ms
  }

  // Read the state of the pedestrian button
  int state = digitalRead(button); 
  Serial.println(state); // Print the state to the serial monitor

  // If the button is pressed and more than 5 seconds have passed since the last change
  if (state == HIGH && (millis() - changeTime) > 5000) {
    changeLights(); // Change the lights
  }
}

void changeLights() {
  // Turn off the green car light and turn on the yellow car light
  digitalWrite(greenCar, LOW);
  digitalWrite(yellowCar, HIGH);
  delay(2000); // Wait for 2 seconds

  // Turn off the yellow car light and turn on the red car light
  digitalWrite(yellowCar, LOW);
  digitalWrite(redCar, HIGH);

  // Turn off the red pedestrian light and turn on the green pedestrian light
  digitalWrite(redPed, LOW);
  digitalWrite(greenPed, HIGH);
  delay(crossTime); // Wait for pedestrian to cross

  // Blink the green pedestrian light for 5 seconds
  for (int x = 0; x < 10; x++) {
    digitalWrite(greenPed, !digitalRead(greenPed)); // Toggle green pedestrian light
    delay(500); // Wait for 500ms
    digitalWrite(greenPed, !digitalRead(greenPed)); // Toggle green pedestrian light
    delay(500); // Wait for 500ms
  }

  // Turn off the green pedestrian light and turn on the red pedestrian light
  digitalWrite(greenPed, LOW);
  digitalWrite(redPed, HIGH);

  // Turn off the red car light
  digitalWrite(redCar, LOW);

  // Set the flag to blink the green car light
  carGreenBlink = true;

  // Update the changeTime variable
  changeTime = millis();
}
