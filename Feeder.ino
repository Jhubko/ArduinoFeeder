#include <Stepper.h>
#include <RTClib.h>

#define stepNumber 32

RTC_DS3231 rtc;
Stepper Motor(stepNumber,8,9,10,11);

void setup() 
{  
  rtc.begin();
  if (rtc.lostPower()) 
  {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() 
{
  DateTime now = rtc.now();

    if ((now.hour() == 07 && now.minute() == 00 && now.second() == 0)) 
    {
      dispense();
      delay(1000);
    }

  delay(500);
}

void dispense()
{
  Motor.setSpeed(500);
  for (int i=0; i<5; i++) 
  {
    Motor.step(-268);
    delay(20);
    Motor.step(512);
    delay(20);
  }
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}
