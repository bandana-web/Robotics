int ledPin = 4; // The digital pin to which the LED is connected
char incomingByte = 0; // A variable to store the incoming byte

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
  digitalWrite(ledPin, LOW); // Start with the LED off
}

void loop() {
  // Check if there is any data available to read from the serial port
  if (Serial.available() > 0) { 
    incomingByte = Serial.read(); // Read the incoming byte
    
    // Print the received data to the Serial Monitor (for debugging)
    Serial.print("Received: ");
    Serial.println(incomingByte);

    // Control the LED based on the received data
    if (incomingByte == '1') {
      digitalWrite(ledPin, HIGH); // Turn the LED ON
      delay(300);
      digitalWrite(ledPin, LOW); 
    } else if (incomingByte == '0') {
      digitalWrite(ledPin, LOW);  // Turn the LED OFF
    }
  }
}