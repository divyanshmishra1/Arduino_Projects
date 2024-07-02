#include <LiquidCrystal.h>

// Initialize the LCD library with the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define pin assignments and variables
const int potPin = A0;       // Analog pin for the LED brightness potentiometer
const int ledPin = 6;        // PWM pin for controlling the LED
int potValue = 0;            // Store the value from the potentiometer
int brightness = 0;          // Calculated brightness level for the LED
int progressSteps = 17;      // Number of steps for the progress bar
int progressBarLength = 8;   // Length of the progress bar on the LCD
byte progressBar[8] = {      // Custom character for the progress bar
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

void setup() {
  // Set up the LED pin as an output
  pinMode(ledPin, OUTPUT); 

  // Set up the LCD with 16 columns and 2 rows
  lcd.begin(16, 2);

  // Display initial message on the LCD
  lcd.print(" LED Brightness");

  // Create custom character for the progress bar
  lcd.createChar(0, progressBar);
}

void loop() {
  // Clear the LCD screen
  lcd.clear();

  // Display message on the LCD
  lcd.print(" LED Brightness");

  // Set the cursor to the second line
  lcd.setCursor(0, 1);

  // Read the value from the potentiometer
  potValue = analogRead(potPin);        

  // Map the potentiometer value to LED brightness (0-255)
  brightness = map(potValue, 0, 1023, 0, 255); 

  // Adjust the LED brightness
  analogWrite(ledPin, brightness); 

  // Map brightness to the progress bar length
  int progressBarLength = map(brightness, 0, 255, 0, progressSteps);

  // Display the progress bar on the LCD
  for (int i = 0; i < progressBarLength; i++) {
    lcd.setCursor(i, 1);   
    lcd.write(byte(0));  
  }

  // Delay before updating again
  delay(750);        
}
