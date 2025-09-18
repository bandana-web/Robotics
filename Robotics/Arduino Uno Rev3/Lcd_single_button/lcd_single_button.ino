//  without switch case single button, single page

#include <LiquidCrystal_I2C.h> //library define
//Library install--making object--for calling 1. Addresss, 2. Size screen, 3. Row or Column 
LiquidCrystal_I2C lcd1(0x27,20,4); //object// address find via i2c scanner inside bracket, screen size
#define button 4
int value;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);

  
  // pinMode(button, INPUT);//////////////

  // Serial.begin(9600);//To print
  
  lcd1.init(); //initialize lcd
  lcd1.backlight();//To activate backlight

  //To erase..cmd is lcdClear..OVerwrite ho jataa mix hojata purana nhi metta
  lcd1.clear(); //Can define column and row number

  lcd1.setCursor(5, 0);//Inside define row/column...indexing starts form 0
  lcd1.print("Hello Hi");//print 1 time
  delay(2000);
  lcd1.setCursor(2, 1);//Inside define row/column...indexing starts form 0
  lcd1.print("okay Bruhh!!");//print 1 time

  lcd1.clear();
}

void loop(){
  value = digitalRead(button);
  Serial.println(value);
  lcd1.setCursor(1,0);
  lcd1.print(value);
 
  if(value==1){///////////////////////////////
     lcd1.clear();///////////
     lcd1.setCursor(1, 2);
    lcd1.print("page 1. Button Pressed");
  
    lcd1.setCursor(1, 3);
    lcd1.print("First Screen");

    delay(2000);
  }
  else{
      // for printing counter aplying for loop
    lcd1.clear();
  
  for(int i=0; i<=100; i++){
  lcd1.setCursor(6, 2);
  lcd1.print("Counter");
  
  lcd1.setCursor(8, 3);
  lcd1.print(i);
  lcd1.print(" ");
  // delay(1000);
  }

  // lcd1.setCursor(1, 0);
  // lcd1.print(value);
  }
}












// // BUTTON 2
//   else if(value2 ==1){///////////////////////////////
//      lcd1.clear();///////////
//      lcd1.setCursor(1, 2);
//     lcd1.print("Page 2(button pressed)");
  
//     lcd1.setCursor(1, 3);
//     lcd1.print("Second Screen");

//     delay(2000);
//   }

// OR USING SWITCH CASE