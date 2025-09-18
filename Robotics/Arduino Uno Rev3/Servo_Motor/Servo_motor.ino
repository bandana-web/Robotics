//SERVO.H BY DEFAULT INCLUDE IN ADRUINO IDE..NO IDE INSTALLATION NEEDED
// 
#include <Servo.h>

Servo servo1; //object
Servo servo2; //object
int rain = 300;

void setup() {
  // put your setup code here, to run once:

  servo1.attach(3);// attach pin 3
  servo2.attach(5);// attach pin 5
  
}

void loop() {
  // put your main code here, to run repeatedly:\

   // Forward motion
  if(rain > 200){
    for(int i = 0; i<= 90; i++){
    servo1.write(i);
    servo2.write(i);
    delay(40);
  }

  // Reverse motion
  for(int i = 90; i>= 0; i--){
    servo1.write(i);
    servo2.write(i);
    delay(40);
  }
  }
  else{
    // If rain <= 200, reset to 0 immediately
    servo1.write(0);
    servo2.write(0);
  }

  //angle define
  // servo1.write(90);
  // delay(2000);
  // servo1.write(0);
  // delay(2000);
}



//battery(AS EXAMPLE LED BAR GRAPH) FOR PARALLEL CONNECTION--FOR 7VOLT