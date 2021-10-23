#include <Arduino.h>
#include "DRV8835.hpp"

enum Pattern{
  INIT,
  TEST,
  MOTOR_TEST,
};
Pattern pattern;

String modelist();
void motor_test();

void setup(){
  Serial.begin(9600);//[b/s]
  Serial.setTimeout(100000);
  pattern = Pattern::INIT;
  Serial.println("\n\n\n\n");
};


void loop(){
  String str;
  
  switch (pattern)
  {
  case Pattern::INIT:
    Serial.println("select mode:");
    Serial.println(modelist());
    str = Serial.readStringUntil('\n');
    pattern = (Pattern)str.toInt();
    Serial.println(str);

    break;

  case Pattern::TEST:
    Serial.println("test mode:");
    pattern = Pattern::INIT;

    break;

  case Pattern::MOTOR_TEST:
    Serial.println("Motor test mode:");
    motor_test();
    pattern = Pattern::INIT;
  
  default:
    Serial.println("return initial");
    pattern = Pattern::INIT;
    break;
  }
};

String modelist(){
  String str;
  str += "  " + String(Pattern::INIT) + ":Initial mode\n";
  str += "  " + String(Pattern::TEST) + ":Test mode\n";
  str += "  " + String(Pattern::MOTOR_TEST) + ":Motor Test mode\n";
  return str;
};

void motor_test(){
  DRV8835 left(4,16);
  while (true)
  {
    String str;
    Serial.print("set duty:");
    str = Serial.readStringUntil('\n');
    Serial.println(str);
    str.setCharAt(str.length()-1,0);
    if (str.equals("end")) break;
    left.setDuty(str.toDouble());
  }
  
}