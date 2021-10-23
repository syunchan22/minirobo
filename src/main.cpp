#include <Arduino.h>
const int ain1_pin = 18;
const int ain2_pin = 17;
const int bin1_pin = 16;
const int bin2_pin = 4;

const uint8_t ain1_ch = 0;
const uint8_t ain2_ch = 1;
const uint8_t bin1_ch = 2;
const uint8_t bin2_ch = 3;




uint8_t pwm_init(const int pin, const uint8_t ch){
  ledcSetup(ch, 500000, 8);
  ledcAttachPin(pin, ch);
  return ch;
}

void motor_update(const float speed, const int ch1, const int ch2){
  if(speed > 0){
    ledcWrite(ch2, 50);
    ledcWrite(ch1, 0);
  }else{
    ledcWrite(ch1, 0);
    ledcWrite(ch2, 0);
  }
}

void setup() {
  // put your setup code here, to run once:
  pwm_init(ain1_pin, ain1_ch);
  pwm_init(ain2_pin, ain2_ch);
  pwm_init(bin1_pin, bin1_ch);
  pwm_init(bin2_pin, bin2_ch);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor_update(0.7, ain1_ch, ain2_ch);
  motor_update(0.7, bin1_ch, bin2_ch);
}