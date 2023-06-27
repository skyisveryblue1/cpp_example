//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.
#include "Tablet.h"

Tablet::Tablet(int price, const std::string& manufacturer, const std::string& color, const std::string& cpu, int numOfPorts, int screenSize)
    : Item(price, manufacturer), PeripheralDevice(price, manufacturer, color, true), Computer(price, manufacturer, cpu, 0, numOfPorts), screenSize(screenSize)
{
}

Tablet::~Tablet()
{
}

int Tablet::getScreenSize() const
{
    return screenSize;
}

void Tablet::setScreenSize(int screenSize)
{
    this->screenSize = screenSize;
}

string Tablet::toString() const //to rewrite
{
    return PeripheralDevice::toString() + ", Mouse with dpi : " + std::to_string(screenSize);
}

Tablet::operator string() const
{
    return toString();
}

void Tablet::connect( Computer& computer)  /////////deleted the two consts and add & before computer in eripheralDevice::connect(&computer);
{
    std::cout << "Connecting a tablet" << std::endl;
    PeripheralDevice::connect(&computer);
}
