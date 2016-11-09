#ifndef HOMEWORK5_ARM_H
#define HOMEWORK5_ARM_H

#include <iostream>
#include "Part.h"

using namespace std;

class Arm : public Part {
public:
    Arm(double cost, int SKU, string name);
};


#endif //HOMEWORK5_ARM_H
