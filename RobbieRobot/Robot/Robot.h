#ifndef HOMEWORK5_ROBOT_H
#define HOMEWORK5_ROBOT_H

#include <iostream>
#include "../Part/Arm.h"
#include "../Part/Torso.h"
#include "../Part/Head.h"
#include "../Part/Leg.h"
#include "../Part/Battery.h"
#include "../Part/Locomotor.h"
using namespace std;

class Robot {
public:
    Robot(string &name, Head* &head, Torso* &torso, Arm* &leftArm, Arm* &rightArm,
          Leg* &leftLeg, Leg* &rightLeg, Battery* &battery1, Battery* &battery2, Battery* &battery3, Locomotor* locomotor);

    double getPrice();
	string getName();
	void setName(string);
	void setCustomerName(string);
	string getCustomerName();
private:
	string name;
	string customer_name;
    Head* head;
    Torso* torso;
    Arm* leftArm;
    Arm* rightArm;
    Leg* leftLeg;
    Leg* rightLeg;
    Battery* battery1;
	Battery* battery2;
	Battery* battery3;
	Locomotor* locomotor;
};


#endif //HOMEWORK5_ROBOT_H
