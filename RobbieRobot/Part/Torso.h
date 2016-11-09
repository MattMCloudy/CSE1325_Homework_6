#ifndef HOMEWORK5_TORSO_H
#define HOMEWORK5_TORSO_H

#include <iostream>
#include "Part.h"

using namespace std;

class Torso : public Part {
public:
    Torso(double price, int SKU, string name);
	int getBatterySlots();
	void setBatterySlots(int n);
private:
	int battery_slots;
};


#endif //HOMEWORK5_TORSO_H
