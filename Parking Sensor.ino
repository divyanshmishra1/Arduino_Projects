const int TONE_PIN = 4;    // Tone - Red Jumper
const int TRIG_PIN = 9;    // Trig - Violet Jumper
const int ECHO_PIN = 10;   // Echo - Yellow Jumper
const int CLOCK_PIN = 11;  // IC Pin 11 - White Jumper
const int LATCH_PIN = 12;  // IC Pin 12 - Blue Jumper
const int DATA_PIN = 13;   // IC Pin 14 - Green Jumper

const byte POSSIBLE_PATTERNS[9] = {
  B00000000, 
  B00000001,
  B00000011,
  B00000111,
  B00001111,
  B00011111,
  B00111111, 
  B01111111, 
  B11111111,
};

const int MAX_DISTANCE = 300; // Maximum distance to measure (in cm)
const int MIN_DISTANCE = 0;   // Minimum distance to measure (in cm)

void setup() {
  // Initialize Serial Port
  Serial.begin(9600);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(TONE_PIN, OUTPUT);
}

void loop() {
  int distance = measureDistance();
  printDistance(distance);
  int proximity = mapProximity(distance);
  if (distance < MAX_DISTANCE) {
    playTone(proximity);
  }
  displayPattern(proximity);
  delay(600);
  noTone(TONE_PIN);
}

int measureDistance() {
  digitalWrite(LATCH_PIN, LOW);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = (duration / 2) / 29.1;
  return distance;
}

void printDistance(int distance) {
  if (distance >= MAX_DISTANCE || distance <= MIN_DISTANCE) {
    Serial.println("Out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }
}

int mapProximity(int distance) {
  if (distance >= MAX_DISTANCE) {
    return 0;
  }
  int proximity = map(distance, MIN_DISTANCE, MAX_DISTANCE, 8, 0);
  proximity = constrain(proximity, 0, 8);
  return proximity;
}

void playTone(int proximity) {
  switch(proximity) {
    case 0:
      tone(TONE_PIN, 2000, 200);   // Highest tone for closest range
      break;
    case 1:
      tone(TONE_PIN, 1800, 200);   
      break;
    case 2:
      tone(TONE_PIN, 1600, 200);
      break;
    case 3:
      tone(TONE_PIN, 1400, 200);
      break;
    case 4:
      tone(TONE_PIN, 1200, 200);
      break;
    case 5:
      tone(TONE_PIN, 1000, 200);
      break;
    case 6:
      tone(TONE_PIN, 800, 200);
      break;
    case 7:
      tone(TONE_PIN, 600, 200);
      break;
    case 8:
      tone(TONE_PIN, 400, 200);   // Lowest tone for farthest range within the specified range
      break;
    default:
      noTone(TONE_PIN);           // No tone for out of range
      break;
  }
}

void displayPattern(int proximity) {
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, POSSIBLE_PATTERNS[proximity]);
  digitalWrite(LATCH_PIN, HIGH);
}
