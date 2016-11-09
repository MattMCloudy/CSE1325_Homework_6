#ifndef HOMEWORK5_LEG_H
#define HOMEWORK5_LEG_H

#include <iostream>
#include "Part.h"

using namespace std;

class Leg : public Part {
public:
    Leg(double price, int SKU, string name);
};


#endif //HOMEWORK5_LEG_H
