#ifndef HWEXCEPTIONS_H
#define HWEXCEPTIONS_H

#include <exception>
#include <string>

class ExistingBranchInsertError : public std::exception {
public:
    const char* what() const throw() {
        return "Trying to add a branch with an already existing location";
    }
};

class NonExistingBranchRemoveError : public std::exception {
public:
    const char* what() const throw() {
        return "Trying to remove a branch with a non existing location";
    }
};

class NonExistingBranchRetrieveError : public std::exception {
public:
    const char* what() const throw() {
        return "Trying to retrieve a branch with a non existing location";
    }
};

class ExistingItemError : public std::exception {
public:
    const char* what() const throw() {
        return "Trying to add an item with an id already in the catalog";
    }
};

class FullCatalogError : public std::exception {
public:
    const char* what() const throw() {
        return "Trying to add an item to a full catalog";
    }
};

class NonExistingItemError : public std::exception {
public:
    const char* what() const throw() {
        return "Trying to remove an item with a non existing id";
    }
};

class NoneExistingItemTypeError : public std::exception {
public:
    const char* what() const throw() {
        return "Trying to get an item with a non existing type";
    }
};

class ConnectError : public std::exception {
public:
    const char* what() const throw() {
        return "Failed connection attempt";
    }
};

#endif // HWEXCEPTIONS_H
#pragma once
