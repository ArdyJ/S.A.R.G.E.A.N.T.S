#include <Servo.h>

Servo dispenser;
Servo flipper;
const int motor = 3;
const int button = 4;
int buttonState = 0;
int pos = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
  dispenser.attach(13);
  dispenser.write(140);
  flipper.attach(5);
  flipper.write(180);
}

void loop()
{
  buttonState = digitalRead(button);
  if(buttonState == HIGH)
  {
    for(pos = 145 ; pos > 100; pos -= 1)  // goes from 0 degrees to 180 degrees 
    {  
      dispenser.write(pos);              // tell servo to go to position in variable 'pos'                       // waits 15ms for the servo to reach the position 
      delay(5);
    }                                
    dispenser.write(140);              // tell servo to go to position in variable 'pos'                       // waits 15ms for the servo to reach the position 
    delay(1200);
    flipper.write(140);
    delay(100                                                                                 );
    flipper.write(180);
    
    turn();
    
    for(pos = 180 ; pos > 0; pos -= 1)  // goes from 0 degrees to 180 degrees 
    {  
      flipper.write(pos);              // tell servo to go to position in variable 'pos'                       // waits 15ms for the servo to reach the position 
      delay(5);
    }  
    for(int i = 0 ; i < 5; i += 1) // goes from 0 degrees to 180 degrees 
    {  
      flipper.write(40);              // tell servo to go to position in variable 'pos'                       // waits 15ms for the servo to reach the position 
      delay(100);
      flipper.write(0);
    }    
    delay(1000);
    flipper.write(180);              // tell servo to go to position in variable 'pos'                       // waits 15ms for the servo to reach the position 
    delay(20);
    
    unturn();
  }
}

void turn()
{
  digitalWrite(motor, HIGH);
  delay(2000);
}

void unturn()
{
  digitalWrite(motor, LOW);
  delay(100);
}
