// PIR MOTION SENSOR
#define pir_pin 3
int pir_value;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//print reading
  pinMode(pir_pin,INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  pir_value = digitalRead(pir_pin);
  Serial.println(pir_value);
  delay(900);
}
