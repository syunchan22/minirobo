#ifndef DRV8835_H
#define DRV8835_H
#include <Arduino.h>

class DRV8835{

private:
    int _enable_pin;
    int _phase_pin;
    int _ch;
    static int _used_ch;
    bool _default_wise;

public:
    DRV8835(int enable_pin, int phase_pin, bool default_wise = true);
    ~DRV8835();
    void setDuty(double_t duty);
    void test();
};

int DRV8835::_used_ch;

void DRV8835::test(){
    Serial.println("yobidasareta2");
};

void DRV8835::setDuty(double_t duty){
    if (0 < duty)
        duty = (1.0 < duty)?1.0:duty;        
    else 
        duty = (-1.0 > duty)?1.0:-duty;

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
    Serial.println("yobidasareta");
}

DRV8835::~DRV8835(){
    Serial.println("sayounara");
}



#endif 