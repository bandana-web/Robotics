#define Trig 2
#define Echo 3
#define Buzzer 5
float distance=0;
float time;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  
pinMode(Echo,INPUT);
pinMode(Trig,OUTPUT);
pinMode(Buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(Trig,LOW);
delayMicroseconds(2);
digitalWrite(Trig,HIGH);
delayMicroseconds(10);
digitalWrite(Trig,LOW);
time=pulseIn(Echo,HIGH);
distance= (time*0.0343)/2;
Serial.print("Distance in cm= ");
Serial.println(distance);

if(distance<=50){
  digitalWrite(Buzzer,HIGH);
  delay(500);
  digitalWrite(Buzzer,LOW);
  delay(500);
}
else if(distance<=40){
  digitalWrite(Buzzer,HIGH);
  delay(200);
  digitalWrite(Buzzer,LOW);
  delay(200);
}
else if(distance<=40){
  digitalWrite(Buzzer,HIGH);
  
}
else{
  digitalWrite(Buzzer,LOW);
}
delay(200);

}
