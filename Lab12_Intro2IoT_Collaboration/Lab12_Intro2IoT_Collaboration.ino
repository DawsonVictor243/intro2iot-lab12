// === Automatic Room Light with Manual Override ===

const int lightSensorPin = A0;   // Photoresistor connected to A0
const int buttonPin = 2;         // Button connected to D2
const int ledPin = 9;            // LED (room light) connected to D9

const int darkThreshold = 500; // Adjust based on ambient light conditions

int lightLevel;  

bool isDark = false;
bool isButtonOn = false;
bool state;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);  // Use internal pull-up resistor
  pinMode(ledPin, OUTPUT);
}

void loop() {
  isDark = isRoomDark();             // Light detection logic
  isButtonOn = isButtonActivated();  // Button-based manual override

  // Control the LED
  if (isDark || isButtonOn) {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED: ON");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("LED: OFF");
  }

  delay(200); // basic debounce + sampling interval
}

// ===============================
// Light Detection – Student 1
bool isRoomDark() {
  lightLevel = analogRead(lightSensorPin);
  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  // TODO: Fix this logic so it returns true when it's dark
  if(lightLevel < 500){
    return true;
  }else{
    return false; // <-- incorrect for now
  }
}

// ===============================
// Manual Switch Control – Student 2
bool isButtonActivated() {
  state = digitalRead(buttonPin);
  
  Serial.print("Button: ");

  // TODO: Fix this logic and print the correct status
  // Button is normally HIGH
  if (state == HIGH) {
    // Button not pressed
    return false;
  } else {
    // Button pressed
    return true;
  }

  // HINT: Serial.print should say "ON" or "OFF" too
}
