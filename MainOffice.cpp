//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#include "MainOffice.h"

void MainOffice::addBranch(const std::string& location, int capacity)
{
    std::pair<std::map<std::string, Branch>::iterator, bool> result = branches.try_emplace(location, location, capacity);
    if (!result.second)
        throw ExistingBranchInsertError();
}

void MainOffice::removeBranch(const std::string& location)
{
    if (branches.erase(location) == 0)
        throw NonExistingBranchRemoveError();
}

Branch& MainOffice::getBranch(const std::string& location)
{
    std::map<std::string, Branch>::iterator it = branches.find(location);
    if (it == branches.end())
        throw NonExistingBranchRetrieveError();
    return it->second;
}

void MainOffice::printBranchesByLocation(void (*printFunction)(const Branch&)) const
{
    std::map<std::string, Branch>::const_iterator it;
    for (it = branches.begin(); it != branches.end(); ++it)
        printFunction(it->second);
}

void MainOffice::printBranchesByValue(void (*printFunction)(const Branch&)) const
{
    std::vector<std::pair<std::string, Branch>> branchVector;
    std::map<std::string, Branch>::const_iterator it;
    for (it = branches.begin(); it != branches.end(); ++it)
        branchVector.push_back(*it);

    std::sort(branchVector.begin(), branchVector.end(),
        [](const std::pair<std::string, Branch>& a, const std::pair<std::string, Branch>& b) {
            int sumA = a.second.getItemsSum();
            int sumB = b.second.getItemsSum();
            if (sumA == sumB)
                return a.first < b.first;
            return sumA < sumB;
        });

    std::vector<std::pair<std::string, Branch>>::const_iterator it_vec;
    for (it_vec = branchVector.begin(); it_vec != branchVector.end(); ++it_vec)
        printFunction(it_vec->second);
}
