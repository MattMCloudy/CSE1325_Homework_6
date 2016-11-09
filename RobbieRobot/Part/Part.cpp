#include "Part.h"

Part::Part(PartType type, double cost, int SKU, string name) : type(type), cost(cost), isObsolete(false), SKU(SKU), name(name) {}

PartType Part::getType() const {
    return type;
}

void Part::setType(PartType type) {
    Part::type = type;
}

double Part::getCost() const {
    return cost;
}

void Part::setCost(double cost) {
    Part::cost = cost;
}

bool Part::isIsObsolete() const {
    return isObsolete;
}

void Part::setIsObsolete(bool isObsolete) {
    Part::isObsolete = isObsolete;
}

string Part::getName() {
	return name;
}
