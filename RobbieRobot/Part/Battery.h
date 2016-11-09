#ifndef HOMEWORK5_BATTERY_H
#define HOMEWORK5_BATTERY_H

#include <iostream>
#include "Part.h"

using namespace std;

class Battery : public Part {
public:
    Battery(double price, int SKU, string name);
};


#endif //HOMEWORK5_BATTERY_H
