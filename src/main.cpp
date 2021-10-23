#include <Arduino.h>

enum Pattern{ //enum 列挙体 0,1,...
  INIT,
  TEST,
  MOTOR_TEST,
};
Pattern pattern;

String modelist(){
  String str;
  str += "  " + String(Pattern::INIT) + ":Initial mode\n";
  str += "  " + String(Pattern::TEST) + ":Test mode\n";
  str += "  " + String(Pattern::MOTOR_TEST) + ":Motor Test mode\n";
  return str;
};

void setup(){
  Serial.begin(9600);//[b/s]
  Serial.setTimeout(100000);
  pattern = Pattern::INIT;
  delay(5000);
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

    pattern = Pattern::INIT;
  
  default:
    Serial.println("return initial");
    pattern = Pattern::INIT;
    break;
  }
};