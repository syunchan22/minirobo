#include "DRV8835.hpp"



int DRV8835::_used_ch;

void DRV8835::test(){
    Serial.println("yobidasareta2");
};

void DRV8835::setDuty(double_t duty){
    if (0 < duty){
        duty = (1.0 < duty)?1.0:duty; 
        digitalWrite(_phase_pin,LOW);       
    }else{ 
        duty = (-1.0 > duty)?1.0:-duty;
        digitalWrite(_phase_pin,HIGH);
    }
    ledcWrite(_ch,(int)(duty*255));
}

DRV8835::DRV8835(int enable_pin, int phase_pin, bool default_wise){
    _enable_pin = enable_pin;
    _phase_pin = phase_pin;
    _default_wise = default_wise;
    _ch = _used_ch;
    _used_ch += 1;
    ledcSetup(_ch, 500000, 8);
    ledcAttachPin(_enable_pin, _ch);
    pinMode(_phase_pin,OUTPUT);
}

DRV8835::~DRV8835(){
    setDuty(0.0);
}
