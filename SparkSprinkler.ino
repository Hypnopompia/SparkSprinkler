#include "TimeAlarms/TimeAlarms.h"

void setup()
{
    Time.zone(-6); // MDT = -6, MST = -7
    Serial.begin(9600);
    
    // Initialize the IO pins
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
    pinMode(D5, OUTPUT);
    pinMode(D6, OUTPUT);
    pinMode(D7, OUTPUT);
    
    // Turn everything off
    Off();

    // create the schedule
    Alarm.alarmRepeat(21,0,0,  Zone1); //  9:00 pm
    Alarm.alarmRepeat(21,20,0, Zone2); //  9:20 pm
    Alarm.alarmRepeat(21,40,0, Zone3); //  9:40 pm
    Alarm.alarmRepeat(22,0,0,  Zone4); // 10:00 pm
    Alarm.alarmRepeat(22,20,0, Zone5); // 10:20 pm
    Alarm.alarmRepeat(22,30,0, Off);   // 10:30 pm
}

void  loop(){  
    digitalClockDisplay();
    Alarm.delay(1000); // wait one second between clock display
}

void Off() {
    Serial.println("All Off");
    digitalWrite(D0, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW);
    digitalWrite(D5, LOW);
    digitalWrite(D6, LOW);
    digitalWrite(D7, LOW);
}

void Zone1() {
    Off();
    Serial.println("Zone 1 On");
    digitalWrite(D0, LOW);
}

void Zone2() {
    Off();
    Serial.println("Zone 2 On");
    digitalWrite(D1, LOW);
}

void Zone3() {
    Off();
    Serial.println("Zone 3 On");
    digitalWrite(D2, LOW);
}

void Zone4() {
    Off();
    Serial.println("Zone 4 On");
    digitalWrite(D3, LOW);
}

void Zone5() {
    Off();
    Serial.println("Zone 5 On");
    digitalWrite(D4, LOW);
}

void Zone6() {
    Off();
    Serial.println("Zone 6 On");
    digitalWrite(D5, LOW);
}

void Zone7() {
    Off();
    Serial.println("Zone 7 On");
    digitalWrite(D6, LOW);
}

void Zone8() {
    Off();
    Serial.println("Zone 8 On");
    digitalWrite(D7, LOW);
}

void digitalClockDisplay()
{
  // digital clock display of the time
  Serial.print(Time.hour());
  printDigits(Time.minute());
  printDigits(Time.second());
  Serial.println(); 
}

void printDigits(int digits)
{
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
