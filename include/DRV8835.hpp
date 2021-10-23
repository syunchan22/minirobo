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




#endif 