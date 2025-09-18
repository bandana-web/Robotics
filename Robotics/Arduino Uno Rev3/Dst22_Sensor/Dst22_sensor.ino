//DST 22 Sensor
#include<DHT.h>//include library

//making object of DHT.h
#define DHTPIN 12//first define pin no--capital
#define DHTTYPE DHT22 //capital--offline 11

DHT dht22(DHTPIN, DHTTYPE);//object

float temp;//temp in float 
float humi;

//no pin mode define / calc etc --> done by library 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht22.begin();//calling sensor

  pinMode(7, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  temp = dht22.readTemperature();
  humi = dht22.readHumidity();

  Serial.print("temp = " );
  Serial.print(temp);
  Serial.print("°C");
  Serial.print(" || ");

  Serial.print("humi = " );
  Serial.print(humi);
  Serial.println("%");
  delay(500);

  if(temp>30){
    digitalWrite(7, HIGH);//pin 8(relay module), high onn
  }
  else if(temp<20){
    digitalWrite(7, LOW);
  }
}
