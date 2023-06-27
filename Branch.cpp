//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include "Branch.h"
#include "Computer.h"
#include "PeripheralDevice.h"

//Constructor
Branch::Branch(string location, int capacity) : location(location), capacity(capacity)
{
    //I need to initialize its values? 
}

Branch::Branch() : location("~"), capacity(0)
{
}

//Destructor
Branch::~Branch()
{
    std::vector<Item*>::iterator i; // Declare iterator before the for loop

    for (i = catalog.begin() ; i != catalog.end(); ++i)
    {
        delete* i;
    }
}

//Copy constructor 
Branch::Branch(const Branch& other) : location(other.location), capacity(other.capacity)
{
}

//Function to get the catalog of items in the branch . also returns the quantity of items 
std::vector<Item*> Branch::getCatalog() const /////////// changed it so it fit the one in the main file, added const also
{
    return catalog;
}

// to get the location of the branch
string Branch::getLocation() const
{
    return location;
}

//method to add an item 
void Branch::addItem(Item* item)
{

    if (find(catalog.begin(), catalog.end(), item) != catalog.end())
    {
        throw ExistingItemError();
    }

    if (catalog.size() >= capacity)
    {
        throw FullCatalogError();
    }
    
    catalog.push_back(item);

    if (typeid(*item) == typeid(Computer))
    {
        computers.push_back(dynamic_cast<Computer*>(item));
    }
}

//method that remove item by Id 
    Item* Branch::removeItem(int id)
    { 
        std::vector<Item*>::iterator i;
        Item* itemToRemove = nullptr; 
        for (i = catalog.begin(); i != catalog.end(); ++i)
        {
            if ((*i)->getId() == id)
            {
                itemToRemove = *i;
                catalog.erase(i);
                break;
            }
        }

        if (itemToRemove == nullptr)
        {
            throw NonExistingItemError();
        }
        else
        {
            int k = 0;
            for (; k < computers.size(); ++k)
            {
                for (int i = 0; i < computers[k]->connected.size(); i++) {
                    computers[k]->connected.erase(std::remove(computers[k]->connected.begin(), computers[k]->connected.end(), itemToRemove));
                }
            }
            return itemToRemove;
        }
    }

    int Branch::getItemsSum() const
    {
        int sum = 0;
        std::vector<Item*>::const_iterator i;
        for (i = catalog.begin(); i != catalog.end(); ++i)
        {
            sum += (*i)->getPrice();
        }
        return sum;
    }
