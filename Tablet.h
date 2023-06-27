//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.
#pragma once
#include "PeripheralDevice.h"
#include "Computer.h"

class Tablet : public PeripheralDevice, public Computer
{
    int screenSize;

public:
    std::vector<PeripheralDevice*> connected; 
    Tablet(int price, const std::string& manufacturer, const std::string& color, const std::string& cpu, int numOfPorts, int screenSize);
    ~Tablet();

    int getScreenSize() const;
    void setScreenSize(int screenSize);

    virtual void connect( Computer& computer) ;

    virtual string toString() const; 
    operator string() const;

};
