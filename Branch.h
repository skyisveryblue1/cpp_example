//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include "Item.h"
#include "HWExceptions.h"
#include "Computer.h"
#include <vector>
#include <algorithm>
#define BRANCH_SIZE 10
//Branch class
class Branch
{
    std::vector<Item*> catalog; //An Array of Item pointers, the store's item catalog 
    int capacity; //integer to keep track of the current quantity of items in the catalog
    string location;

	std::vector<Computer*> computers; //An Array of Computers pointers

public:
    Branch(std::string location, int capacity); //Constructor
    Branch(); // Default constructor
    ~Branch(); //Destructor
    Branch(const Branch& other); //Copy constructor

    std::vector<Item*> getCatalog() const;  //to get the catalog of items in the branch
    string getLocation() const; //get the loaction of teh branch

    void addItem(Item* item); //add an item to the catalog
    Item* removeItem(int id); //remove item by id 

	template<class T>
	T* giveMeFinest(T* item) const
	{
		int highPrice = 0;
		T* highItem = NULL;
		for (int i = 0; i < catalog.size(); i++)
		{
			if (typeid(*catalog[i]) == typeid(*item))
			{
				if (catalog[i]->getPrice() > highPrice)
				{
					highPrice = catalog[i]->getPrice();
					(highItem) = (dynamic_cast<T*>(catalog[i]));
				}
			}
		}
		if (highItem) 
		{
			if (dynamic_cast<T*>(highItem))
				return highItem;
		}
		else
		{
			throw NoneExistingItemTypeError();
		}
	}


	/*
		template<class T>
	T* giveMeFinest(T* item) const
	{
		int highPrice = 0;
		T* highItem = NULL;
		std::vector<Item*>::iterator i;
		for (i = catalog.begin(); i != catalog.end(); ++i)
		{
			if (typeid(*i) == typeid(*item))
				if ((*i)->getPrice() > highPrice)
				{
					highPrice = (*i)->getPrice();
					(highItem) = (dynamic_cast<T*>(*i));
				}
		}
		if (highItem) 
		{
			if (dynamic_cast<T*>(highItem))
				return highItem;
		}
		else
			throw NoneExistingItemTypeError();
	}
	*/

	int getItemsSum() const;
};

