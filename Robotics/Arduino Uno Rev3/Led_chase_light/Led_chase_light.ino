//lED Chase Light

int counts=8;
int pins[]={13,12,11,10,9,8,7,6};

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);  
for(int i=0;i<counts;i=i+1)
{
  pinMode(pins[i],OUTPUT);
}
}

void loop() {
for(int j=0;j<counts;j++)
{
  Serial.println(pins[j]);
  digitalWrite(pins[j],HIGH);
  delay(500);
  digitalWrite(pins[j],LOW);
}
for(int j=counts-1;j>=0;j--)
{
  Serial.println(pins[j]);
  digitalWrite(pins[j],HIGH);
  delay(500);
  digitalWrite(pins[j],LOW);
}
}
