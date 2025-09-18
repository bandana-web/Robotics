#include <WiFi.h> 

// WiFi credentials
const char* ssid = "S21";        // Replace with your WiFi SSID
const char* password = "clib3528";    // Replace with your WiFi password

WiFiServer server(80);  // Set server port to 80 
String header;  // Stores the HTTP request

// Define the GPIO pins for appliances (Relays)
#define APP1_PIN  2  // Change to any available ESP32 GPIO pin

String app1state = "off"; // Track the state of appliance 1

void setup() {
    Serial.begin(115200); // AS here is esp32 we use, needs more power

    pinMode(APP1_PIN, OUTPUT);
    digitalWrite(APP1_PIN, LOW);  // Ensure the relay is OFF at startup

    // Connect to WiFi
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected.");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP()); // Display ESP32's local IP 
    server.begin();
}

void loop() {
    WiFiClient client = server.available();  // Listen for incoming clients

    if (client) {  
        Serial.println("New Client Connected.");
        String currentLine = "";  // To store incoming HTTP request data
        while (client.connected()) {
            if (client.available()) {
                char c = client.read();  
                Serial.write(c);  // Print HTTP request data to Serial Monitor
                header += c;

                if (c == '\n') {  
                    if (currentLine.length() == 0) {  
                        // Send HTTP response headers
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/html");
                        client.println("Connection: close");
                        client.println();

                        // Toggle appliances based on the received request
                        if (header.indexOf("GET /app1/on") >= 0) {
                            Serial.println("Appliance 1 ON");
                            app1state = "on";
                            digitalWrite(APP1_PIN, HIGH);
                        } 
                        else if (header.indexOf("GET /app1/off") >= 0) {
                            Serial.println("Appliance 1 OFF");
                            app1state = "off";
                            digitalWrite(APP1_PIN, LOW);
                        }

                        // Send HTML Web Page
                        client.println("<!DOCTYPE html><html>");
                        client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
                        client.println("<link rel=\"icon\" href=\"data:,\">");
                        client.println("<style>html { font-family: Helvetica; text-align: center;}");
                        client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
                        client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
                        client.println(".button2 {background-color: #77878A;}</style></head>");
                        client.println("<body><h1>ESP32 Web Server</h1>");

                        // Display appliance state and control buttons
                        client.println("<p>Appliance 1 - State: " + app1state + "</p>");
                        if (app1state == "off") {
                            client.println("<p><a href=\"/app1/on\"><button class=\"button\">ON</button></a></p>");
                        } else {
                            client.println("<p><a href=\"/app1/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }

                        client.println("</body></html>");
                        client.println();
                        break;  // Exit the while loop
                    } 
                    else {
                        currentLine = "";
                    }
                } 
                else if (c != '\r') {
                    currentLine += c;
                }
            }
        }
        // Clear the header variable and close the client connection
        header = "";
        client.stop();
        Serial.println("Client Disconnected.");
    }
}
