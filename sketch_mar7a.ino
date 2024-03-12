#include <Servo.h>



Servo myservo;
unsigned long lastTime = 0; //used for sampling time
int lastState = 0; //State of the button 
unsigned long dt = 20; // dt in milliseconds

const int buttonPin = 4;  // the number of the pin where pedometer connected
int buttonState = 0;  // variable for reading the pedometer status
int counter = 0; //count number of steps
void setup() {
myservo.attach(3); //servo motor
  Serial.begin(9600);
  pinMode(buttonPin, INPUT); //pedometer

}

void loop() {

    
  if (millis() - lastTime  >= dt)   // wait for dt milliseconds
  {
    
    buttonState = digitalRead(buttonPin); // read button state
    lastTime = millis();
    //check 
    if (lastState == 1 && buttonState == 0){
      //+1 for each step
      counter++;
      Serial.println(counter);
    }
    
    lastState = buttonState;
    //Serial.println(counter);
    if (counter == 10){
      //open the lid
      myservo.write(55);
      delay(200);
      //reset counter
      counter =0;
    }

    else{
      //close the lid
      myservo.write(0);
    }
  }

}
