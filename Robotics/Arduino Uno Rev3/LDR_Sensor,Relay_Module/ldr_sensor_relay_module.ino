#define LDR_pin A0
#define led_pin 13
int LDR_value;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //TO print value in output
  pinMode(LDR_pin, INPUT); // input via ldr sensor
  pinMode(led_pin, OUTPUT); // output via l8
}

void loop() {
  // put your main code here, to run repeatedly:
  LDR_value = analogRead(LDR_pin); // Analog read as Analog pin se connect kr rhe..
  Serial.println(LDR_value);
  delay(100);

  if (LDR_value > 800){
    digitalWrite(led_pin, HIGH); //pin no 13 ko high kr rha,, high bhej rha pin 13 ko..when ldr value more than 800
  }
  else{
    digitalWrite(led_pin, 0);
  }
}
