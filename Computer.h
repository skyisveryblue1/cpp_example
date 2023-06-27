//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include "Item.h"
#include <vector>
#include <algorithm>

class PeripheralDevice; //to avoid circular dependency 

class Computer : public virtual Item //Computer class, which is a subclass of Item //////added virtual
{
    std::string cpu;
    bool isALaptop;
    int numOfPorts; 

public:
    std::vector<PeripheralDevice*> connected;
    Computer(int price, const std::string& manufacturer, const std::string& cpu, bool isALaptop, int numOfPorts); //Constructor for the Computer class
    ~Computer(); ////

    std::string getCpu() const; //to get the CPU of the computer
    void setCpu(const std::string& cpu); //to set the CPU
    bool getIsALaptop() const; //to get whether the computer is a laptop
    void setIsALaptop(bool isALaptop); //to set whether the computer is a laptop
    int getNumOfPorts() const; /////

    virtual string toString() const; //Virtual method to get a string representation of the computer
    operator string() const; // Overloaded operator to convert the computer to a string

    void printConnected() const; ////
};

