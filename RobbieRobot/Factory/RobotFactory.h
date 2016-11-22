#ifndef HOMEWORK5_ROBOTFACTORY_H
#define HOMEWORK5_ROBOTFACTORY_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "../Part/Head.h"
#include "../Part/Torso.h"
#include "../Part/Battery.h"
#include "../Part/Leg.h"
#include "../Part/Arm.h"
#include "../Part/Locomotor.h"
#include "../Robot/Robot.h"
#include "../Model.h"

using namespace std;

class RobotPartNotFound {};

class RobotFactory {
private:
    vector <Head *> headParts;
    vector <Torso *> torsoParts;
    vector <Battery *> batteryParts;
    vector <Leg *> legParts;
    vector <Arm *> armParts;
	vector <Locomotor *> locomotorParts;
	vector <Robot *> models;
	vector <Robot *> robots;
public:
    RobotFactory();

    void insert(Head * head) { headParts.push_back(head); }
    void insert(Torso * torso) { torsoParts.push_back(torso); }
    void insert(Battery * battery) { batteryParts.push_back(battery); }
    void insert(Leg * leg) { legParts.push_back(leg); }
    void insert(Arm * arm) { armParts.push_back(arm); }
	void insert(Locomotor * locomotor) { locomotorParts.push_back(locomotor); }

    void del(Head * head);
    void del(Torso * torso);
    void del(Battery * battery);
    void del(Leg * leg);
    void del(Arm * arm);
	void del(Locomotor * locomotor);
    void del(Robot * robot);


    const vector<Head *> &getHeadParts() const { return headParts; }
    const vector<Torso *> &getTorsoParts() const { return torsoParts; }
    const vector<Battery *> &getBatteryParts() const { return batteryParts; }
    const vector<Leg *> &getLegParts() const { return legParts; }
    const vector<Arm *> &getArmParts() const { return armParts; }
	const vector<Locomotor *> &getLocomotorParts() const { return locomotorParts;}
    const vector<Robot *> &getModels() const { return models; }
	const vector<Robot *> &getRobots() const { return robots; }
	
	Head* createHead(string name, string price_s, string SKU_s);
	Torso* createTorso(string name, string price_s, string SKU_s, int batSlots);
	Battery* createBattery(string name, string price_s, string SKU_s);
	Leg* createLeg(string name, string price_s, string SKU_s);
	Arm* createArm(string name, string price_s, string SKU_s);
	Locomotor* createLocomotor(string name, string price_s, string SKU_s);

    Robot * createRobot(string name, Head* head, Torso* torso, Battery* battery1, Battery* battery2, Battery* battery3, Leg* leftLeg, Leg* rightLeg, Arm* leftArm, Arm* rightArm, Locomotor* locomotor);
	void createModel(string name, Head* head, Torso* torso, Battery* battery1, Battery* battery2, Battery* battery3, Leg* leftLeg, Leg* rightLeg, Arm* leftArm, Arm* rightArm, Locomotor* locomotor);
    Robot * createRobotFromModel(string name, Robot * robot);
    Robot * createRobotFromModel(string name, int i);
};


#endif //HOMEWORK5_ROBOTFACTORY_H
