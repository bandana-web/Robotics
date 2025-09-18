// Using Ldr sensor 
#define ldr A0
#define led_pin 9

int value;
int fade;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(ldr);
  Serial.println(value);


  fade = map(value,0,40,255,0);
  delay(50);
  analogWrite(led_pin, fade);
}


// void loop() {
//   // put your main code here, to run repeatedly:
//   value = analogRead(ldr);
//   Serial.println(value);
//   value = map(value,0, 30,255,0);
//   delay(300);

//   digitalWrite(led,value);
//   delay(15);
//   // if (value > 40){
//   //   digitalWrite(led, fade); 
//   // }
//   // else{
//   //   digitalWrite(led, 0);
//   // }
// }