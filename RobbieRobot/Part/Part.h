#ifndef HOMEWORK5_PART_H
#define HOMEWORK5_PART_H

#include <iostream>

using namespace std;

enum PartType {
    HEAD,
    ARM,
    TORSO,
    LEG,
    BATTERY,
    LOCOMOTOR
};

class Part {
public:
    Part(PartType type, double cost, int SKU, string name);

    Part();

    PartType getType() const;

    void setType(PartType type);

    double getCost() const;

    void setCost(double cost);

    bool isIsObsolete() const;

    void setIsObsolete(bool isObsolete);

	string getName();

private:
    PartType type;
    double cost;
    bool isObsolete;
    int SKU;
    string name;
};


#endif //HOMEWORK5_PART_H
