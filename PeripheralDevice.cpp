//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.
#pragma once
#include "PeripheralDevice.h"

PeripheralDevice::PeripheralDevice(int price, const string& manufacturer, const string& color, bool isWireless)
    : Item(price, manufacturer), color(color), isWireless(isWireless) //constructor of the PeripheralDevice class
{
	//computerConnectedTo = NULL;
}

string PeripheralDevice::getColor() const //getter for color
{
    return color;
}

void PeripheralDevice::setColor(const string& color) //setter for color
{
    this->color = color;
}

bool PeripheralDevice::getIsWireless() const //getter for isWireless
{
    return isWireless;
}

void PeripheralDevice::setIsWireless(bool isWireless) //setter for isWireless
{
    this->isWireless = isWireless;
}

void PeripheralDevice::connect(Computer* computer) //connect function to print connection details //////////// re-arrange
{

	if (computerConnectedTo != computer)
	{
		if (computerConnectedTo)
		{
			throw ConnectError();
		}
		else
		{
			std::cout << operator std::string();
			std::cout << " is connecting to computer: " + computer->Computer::operator std::string(); std::cout << std::endl;

			for (int i = 0; i < computer->connected.size(); i++)
			{
				if (typeid(computer->connected[i]) == typeid(*this))
				{
					throw ConnectError();
				}
			}
			if (computer->connected.size() == computer->getNumOfPorts())
			{
				throw ConnectError();
			}
			else
			{
				computer->connected.push_back(this);
				computerConnectedTo = computer;	
			}
		}
	}

}



void PeripheralDevice::disconnect() //////////////////////
{ 
    if (computerConnectedTo)
    {
        std::vector<PeripheralDevice*>::iterator neww;
        computerConnectedTo->connected.erase(std::remove(computerConnectedTo->connected.begin(), computerConnectedTo->connected.end(), this));
        computerConnectedTo = NULL;
    }
}

string PeripheralDevice::toString() const //toString function to return a string representation of the PeripheralDevice
{
    return Item::toString() + (this->isWireless ? "Wireless" : "Wired") + ", " + color;
}

PeripheralDevice::operator string() const   //string conversion operator for the PeripheralDevice class
{
    return toString();
}
