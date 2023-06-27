//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include "Item.h"
#include "HWExceptions.h"
#include "Computer.h"
#include <iostream>

class PeripheralDevice : public virtual Item  //the PeripheralDevice class, which is a child class of Item //////added virtual
{
    std::string color;
    bool isWireless;
    Computer* computerConnectedTo = NULL; //////////////////try to initialize it here back

public:
    PeripheralDevice(int price, const std::string& manufacturer, const std::string& color, bool isWireless); //constructor

    std::string getColor() const; //to get the color
    void setColor(const std::string& color); //to set teh color
    bool getIsWireless() const; //to get if its Wireless
    void setIsWireless(bool isWireless); //to set it whether Wireless

    virtual void connect(Computer* computer); //virtual connect functio
    virtual void disconnect(); /////////

    virtual string toString() const; //virtual toString function to get a string representation of the PeripheralDevice
    operator string() const; //string conversion operator for the PeripheralDevice class
};
