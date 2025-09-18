#include <WiFi.h> 
#include <HTTPClient.h>
#include "DHT.h" 
//inko install krna h

// WiFi Credentials
const char* ssid = "S21";  // Replace with your WiFi SSID //* for input lena hai 
const char* password = "clib3528";  // Replace with your WiFi password 

// ThingSpeak API Key
const char* apiKey = "5T6FYCWC16QSDCL9";

// DHT11 Configuration
#define DHTPIN 4  // GPIO pin where DHT11 is connected
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    dht.begin();

    // Connect to WiFi
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi!");
}

void loop() {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // Check if reading is valid
    if (isnan(temperature) || isnan(humidity)) {  //isnan means no value //
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        String url = "http://api.thingspeak.com/update?api_key=" + String(apiKey) +
                     "&field1=" + String(temperature) + "&field2=" + String(humidity);

        http.begin(url);
        int httpResponseCode = http.GET();

        if (httpResponseCode > 0) {
            Serial.print("Data sent to ThingSpeak, Response: ");
            Serial.println(httpResponseCode);
        } else {
            Serial.print("Error sending data, HTTP Response code: ");
            Serial.println(httpResponseCode);
        }

        http.end();
    }

    delay(2000);  // Update every 15 seconds (minimum delay for ThingSpeak)
}
