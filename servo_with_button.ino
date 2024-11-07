#include <Servo.h>

Servo myServo;

int buttonApin = 3;
int count = 0;
void setup() 
{
  pinMode(buttonApin, INPUT_PULLUP);  
  myServo.attach(11);
  Serial.begin(9600);
  myServo.write(0);
}

void loop() 
{
  if (digitalRead(buttonApin) == LOW)
  {
    if (count % 2 == 0)
    {
      //myServo.write(0);
      while (myServo.read() > 0)
      {
        myServo.write(myServo.read() - 2);
        delay(10);
      }
    }
    else
    {
      //myServo.write(90);
      while (myServo.read() < 90)
      {
        myServo.write(myServo.read() + 2);
        delay(10);
      }
    }
    count++;

    delay(300);
  }

  Serial.print(myServo.read());
  Serial.print("\n");
}

