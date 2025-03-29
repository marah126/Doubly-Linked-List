#include "UniqueID.hpp"

int UniqueID::id = 0;

int UniqueID::generateID()
{
    id++;
    return id;
}

int UniqueID::getLastID() {
    return id;
}
