//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include "Mouse.h"

Mouse::Mouse(int price, const string& manufacturer, const string& color, bool isWireless, int dpi)
    : Item(price, manufacturer), PeripheralDevice(price, manufacturer, color, isWireless), dpi(dpi) //the constructor for the Mouse class
{
}

int Mouse::getDpi() const //to get the DPI of the Mouse
{
    return dpi;
}

void Mouse::setDpi(int dpi) //to set the DPI of the Mouse
{
    this->dpi = dpi;
}

void Mouse::connect( Computer& computer)  //to simulate connecting the Mouse to a Computer /////////////deleted the two consts and add & before computer in eripheralDevice::connect(&computer);
{
    std::cout << "Connecting a mouse" << std::endl;
    PeripheralDevice::connect(&computer);
}

string Mouse::toString() const //to get a string representation of the Mouse
{
    return PeripheralDevice::toString() + ", Mouse with dpi : " + std::to_string(dpi);
}

Mouse::operator string() const //string conversion operator for the Mouse class
{
    return toString();
}
