//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once

#include <map>
#include "Branch.h"
#include <algorithm>

class MainOffice
{
private:
    MainOffice() {}
    MainOffice(const MainOffice&) = delete;
    void operator=(const MainOffice&) = delete;

    std::map<std::string, Branch> branches;
public:
    static MainOffice& getInstance()
    {
        static MainOffice instance;
        return instance;
    }

    void addBranch(const std::string& location, int capacity);
    void removeBranch(const std::string& location);
    Branch& getBranch(const std::string& location);
    void printBranchesByLocation(void (*printFunction)(const Branch&)) const;
    void printBranchesByValue(void (*printFunction)(const Branch&)) const;
};


