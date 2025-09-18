// switch case, double button, multiple pages
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd1(0x27,20,4);
#define button1 4
int value1;
#define button2 5
int value2;
int counter=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(button1,INPUT);
pinMode(button2,INPUT);
lcd1.init();
lcd1.backlight();
lcd1.clear();
lcd1.setCursor(5,0);
lcd1.print("hello hi");

delay(2000);
lcd1.setCursor(2,1);
lcd1.print("how are you?");

lcd1.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
value1= digitalRead(button1);
value2= digitalRead(button2);

if(value1==1){
  counter=counter+1;
  delay(2000);
  
}
if(value2==1){
  counter=counter-1;
  Serial.println(counter);
  delay(2000);

}
Serial.println(counter);
switch (counter) {
        case 1:
            lcd1.setCursor(0,0);
            lcd1.print("     ");
            lcd1.setCursor(5,0);
            lcd1.print("   page   ");

               
            lcd1.setCursor(2,1);
            lcd1.print("1");
            break; // Exits the switch statement
        case 2:
              lcd1.setCursor(0,0);
               lcd1.print("    ");
               lcd1.setCursor(5,0);
               lcd1.print("   page2   ");

               
            lcd1.setCursor(2,1);
            lcd1.print("2");
            break;
        
        default: // Executed if no case matches
            lcd1.setCursor(5,0);
            lcd1.print("hello hi");

             delay(2000);
             lcd1.setCursor(2,1);
             
            break;
    }


}


//4. PAGE 1 AND PAGE 2 //

// BUTTON 1 ,2 
// VALUE 1 ,2

// LOOP ME KHELA 
// IF --PAGE 1...2SEC DELAY
// ELSEIF --PAGE 2...
// ELSE --HOME PAGE

// 4.b. Switch Case LCD 20x4 PAGES SCROOL

// button 1 4
// int value1;
// button 2 5
// int value2
// int counter = 0;

// void setup(
// pinMode(button1, InPUT)
// pint b8tton2
// lcd1.int();
// lcd1.back
// 2

// )

// loop 
// value1 = digitalRead(button1);
// value2 = digitalRead(button2);

// if(value1 == 1) {
//   counter++;
//   delay(2000);
//   Serial.println(counter);
// }
// if(value2 == 1) {
//   counter = counter -1;
//   Serial.println(counter);
//   delay(2000);
// }
// //now switchcase lga do,  no less than 0 counter(as no minus case in switch case or said to be default), 
// //button press page 0,1,2,3 etcc..

// Serial.println(counter);

//   switch (counter) {
//     case 1:
//     // lcd1.clear();
//     lcd1.setCursor(0,0);
//       lcd1.print("    ");
//     lcd1.setCursor(5,0);
//       lcd1.print("   page1   ");
      
//       lcd2.setCursor(2,1);
//       lcd1.print("1");
//       break;

//     case 2:
//       // lcd1.clear();
//       lcd1.setCursor(0,0);
//       lcd1.print("    ");
//       lcd1.setCursor(5,0);
//       lcd1.print("    page2   ");

//       lcd2.setCursor(2,1);
//       lcd1.print("2");
//       break;

//     default:
//       lcd1.setCursor(5, 0);//Inside define row/column...indexing starts form 0
//   lcd1.print("Hello Hi");//print 1 time

//   delay(2000);
//   lcd1.setCursor(2, 1);//Inside define row/column...indexing starts form 0  
  
//       break;
//   }
// }

