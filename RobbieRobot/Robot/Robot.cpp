#include "Robot.h"

Robot::Robot(string &name, Head* &head, Torso* &torso, Arm* &leftArm, Arm* &rightArm,
             Leg* &leftLeg, Leg* &rightLeg, Battery* &battery1, Battery* &battery2, Battery* &battery3, Locomotor* locomotor) : 
		name(name), head(head), torso(torso), leftArm(leftArm), rightArm(rightArm), leftLeg(leftLeg), rightLeg(rightLeg), battery1(battery1), battery2(battery2), battery3(battery3), locomotor(locomotor) {}

double Robot::getPrice() {
    double price = 0;
	if (head != NULL)
		price += head->getCost();
	if (torso != NULL) 
		price += torso->getCost();
	if (leftArm != NULL)
		price += leftArm->getCost();
    if (rightArm != NULL)
		price += rightArm->getCost();
    if (leftLeg != NULL)
		price += leftLeg->getCost();
    if (rightLeg != NULL)
		price += rightLeg->getCost();
	if (battery1 != NULL)
		price += battery1->getCost();
	if (battery2 != NULL)
		price += battery2->getCost();
	if (battery3 != NULL)
		price += battery3->getCost();
	if (locomotor != NULL)
		price += locomotor->getCost();

    return price;
}

string Robot::getName() {return name;}
void Robot::setName(string str) {
	name = str;
	return;
}

string Robot::getCustomerName() {return customer_name;}
void Robot::setCustomerName(string str) {customer_name = str;}
