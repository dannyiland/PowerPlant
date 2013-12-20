// Gardening with an Arduino and a DS1302 RTC.
// RTC code based on example from DS1302 library
// http://quadpoint.org/projects/arduino-ds1302

#include <stdio.h>
#include <DS1302.h>

namespace {

const int kCePin   = 15;  // Chip Enable
const int kIoPin   = 16;  // Input/Output
const int kSclkPin = 17;  // Serial Clock

// Transistor control
const int TIP120pin = 5; 

// A 2 minute watering at 9:03 AM
boolean watering = false;
const int watering_hour = 9;
const int watering_minute = 03;
const int watering_duration = 2;

DS1302 rtc(kCePin, kIoPin, kSclkPin);

String dayAsString(const Time::Day day) {
  switch (day) {
    case Time::kSunday: return "Sunday";
    case Time::kMonday: return "Monday";
    case Time::kTuesday: return "Tuesday";
    case Time::kWednesday: return "Wednesday";
    case Time::kThursday: return "Thursday";
    case Time::kFriday: return "Friday";
    case Time::kSaturday: return "Saturday";
  }
  return "(unknown day)";
}

void printTime() {
  // Get the current time and date from the chip.
  Time t = rtc.time();

  // Name the day of the week.
  const String day = dayAsString(t.day);

  // Format the time and date and insert into the temporary buffer.
  char buf[50];
  snprintf(buf, sizeof(buf), "%04d-%02d-%02d %02d:%02d:%02d",
           t.yr, t.mon, t.date,
           t.hr, t.min, t.sec);

  // Print the formatted string to serial so we can see the time.
  Serial.println(buf);
}

}  // namespace

void setup() {
  Serial.begin(9600);
  pinMode(TIP120pin, OUTPUT); // Control TIP120 Base pin to enable pump
  analogWrite(TIP120pin, 0);  // Default to off!
  Serial.println("Watering the garden ...");
  rtc.writeProtect(false);
  rtc.halt(false);
  // Make a new time object to set the date and time.
  //Time t(Year Month Day Hour Minute Second Day)
  //Time t(2013, 12, 19, 21, 27, 00, Time::kThursday);
  // Set the time and date on the chip.
  //rtc.time(t);
}

// Enable the pump at the specified minute for the
// given duration.
// This functions has a bad bug. The watering period
// MUST start and stop within the same hour.
// This is a bad bug because if you try to water
// from 8:58 to 9:01, the pump will never turn off!
void loop() {
  printTime();
  Time t = rtc.time();
  if(t.hr == watering_hour) {
    if(t.min == watering_minute) {
      if(!watering) {
        watering = true;
        analogWrite(TIP120pin, 255); 
        Serial.println("Watering on!");
      }
    }
    if(t.min == watering_minute + watering_duration) {
      if(watering) {
         analogWrite(TIP120pin, 0);
         watering = false;
         Serial.println("Watering off!");
      }
    }
  }
  delay(5000);
}
