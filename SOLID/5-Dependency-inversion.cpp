/*

class should depend on interfaces rather than concrete class

*/

#include<iostream>

class LightBulb{
    public:

    void turnOn(){

    }

    void turnOff(){

    }
};

class Switch {

public:

    void operate(LightBulb& bulb) {
        if (!isOn) {
            bulb.turnOn();
            isOn = true;
        } else {
            bulb.turnOff();
            isOn = false;
        }
    }

private:
    bool isOn = false;
};

//Switch class directly depends on the LightBulb

class Switchable{
    public:
        virtual void turnOn() =0;
        virtual void turnOff() =0;
};

class LightBulb : public Switchable {
public:
    void turnOn() override {
        std::cout << "LightBulb is on." << std::endl;
    }
    
    void turnOff() override {
        std::cout << "LightBulb is off." << std::endl;
    }
};

class Switch {
public:
    void operate(Switchable& device) {
        if (!isOn) {
            device.turnOn();
            isOn = true;
        } else {
            device.turnOff();
            isOn = false;
        }
    }

private:
    bool isOn = false;
};

int main() {
    LightBulb bulb;
    Switch lightSwitch;

    lightSwitch.operate(bulb);

    return 0;
}





