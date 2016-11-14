#include "RobotFactory.h"

Robot * RobotFactory::createRobot(string name, Head* head, Torso* torso, Battery* battery1, Battery* battery2, Battery* battery3, Leg* leftLeg, Leg* rightLeg, Arm* leftArm, Arm* rightArm, Locomotor* locomotor) {
    Robot * robot;
    robot = new Robot(name, head, torso, leftArm, rightArm, leftLeg, rightLeg, battery1, battery2, battery3, locomotor);

    return robot;
}

void RobotFactory::createModel(string name, Head* head, Torso* torso, Battery* battery1, Battery* battery2, Battery* battery3, Leg* leftLeg, Leg* rightLeg, Arm* leftArm, Arm* rightArm, Locomotor* locomotor) {
    Robot * robot = createRobot(name, head, torso, battery1, battery2, battery3, leftLeg, rightLeg, leftArm, rightArm, locomotor);
    models.push_back(robot);
}

Robot * RobotFactory::createRobotFromModel(Robot * robot) {
	robots.push_back(new Robot(*robot));
    return new Robot(*robot);
}

Robot * RobotFactory::createRobotFromModel(int i) {
	robots.push_back(new Robot(*models[i]));
    return new Robot(*models[i]);
}

void RobotFactory::del(Head * head) {
    headParts.erase(std::remove(headParts.begin(), headParts.end(), head), headParts.end());
}

void RobotFactory::del(Torso * torso) {
    torsoParts.erase(std::remove(torsoParts.begin(), torsoParts.end(), torso), torsoParts.end());
}

void RobotFactory::del(Battery * battery) {
    batteryParts.erase(std::remove(batteryParts.begin(), batteryParts.end(), battery), batteryParts.end());
}

void RobotFactory::del(Leg * leg) {
    legParts.erase(std::remove(legParts.begin(), legParts.end(), leg), legParts.end());
}

void RobotFactory::del(Arm * arm) {
    armParts.erase(std::remove(armParts.begin(), armParts.end(), arm), armParts.end());
}

void RobotFactory::del(Locomotor* locomotor) {
	locomotorParts.erase(std::remove(locomotorParts.begin(), locomotorParts.end(), locomotor), locomotorParts.end());
}

void RobotFactory::del(Robot * robot) {
    models.erase(std::remove(models.begin(), models.end(), robot), models.end());
}

Head* RobotFactory::createHead() {
	string name;
	string price_s;
	string SKU_s;
	double price;
	int SKU;
	cout << "\nWhat is the name of your new Head part?: ";
	getline(cin, name);
	cout << "\nWhat is the cost of your new Head part?: ";
	getline(cin, price_s);
	price = stod(price_s);
	cout << "\nWhat is the SKU of your new Head part?: ";
	getline(cin, SKU_s);
	SKU = stoi(SKU_s);
	Head* newbie = new Head(price, SKU, name);
	insert(newbie);
	return newbie;
}

Torso* RobotFactory::createTorso() {
	string name;
	string price_s;
	string SKU_s;
	string bat_s;
	double price;
	int SKU;
	int slots;
	cout << "\nWhat is the name of your new Torso part?: ";
	getline(cin, name);
	cout << "\nWhat is the cost of your new Torso part?: ";
	getline(cin, price_s);
	price = stod(price_s);
	cout << "\nWhat is the SKU of your new Torso part?: ";
	getline(cin, SKU_s);
	SKU = stoi(SKU_s);
	Torso* newbie = new Torso(price, SKU, name);
	cout << "\nHow many battery slots do you want in Torso? (Maximum of 3): ";
	getline(cin, bat_s);
	slots = stoi(bat_s);
	newbie->setBatterySlots(slots);
	insert(newbie);
	return newbie;
}

Battery* RobotFactory::createBattery() {
	string name;
	string price_s;
	string SKU_s;
	double price;
	int SKU;
	cout << "\nWhat is the name of your new Battery part?: ";
	getline(cin, name);
	cout << "\nWhat is the cost of your new Battery part?: ";
	getline(cin, price_s);
	price = stod(price_s);
	cout << "\nWhat is the SKU of your new Battery part?: ";
	getline(cin, SKU_s);
	SKU = stoi(SKU_s);
	Battery* newbie = new Battery(price, SKU, name);
	insert(newbie);
	cout << "\nSUP\n";
	return newbie;
}

Leg* RobotFactory::createLeg() {
	string name;
	string price_s;
	string SKU_s;
	double price;
	int SKU;
	cout << "\nWhat is the name of your new Leg part?: ";
	getline(cin, name);
	cout << "\nWhat is the cost of your new Leg part?: ";
	getline(cin, price_s);
	price = stod(price_s);
	cout << "\nWhat is the SKU of your new Leg part?: ";
	getline(cin, SKU_s);
	SKU = stoi(SKU_s);
	Leg* newbie = new Leg(price, SKU, name);
	insert(newbie);
	return newbie;
}

Arm* RobotFactory::createArm() {
	string name;
	string price_s;
	string SKU_s;
	double price;
	int SKU;
	cout << "\nWhat is the name of your new Arm part?: ";
	getline(cin, name);
	cout << "\nWhat is the cost of your new Arm part?: ";
	getline(cin, price_s);
	price = stod(price_s);
	cout << "\nWhat is the SKU of your new Arm part?: ";
	getline(cin, SKU_s);
	SKU = stoi(SKU_s);
	Arm* newbie = new Arm(price, SKU, name);
	insert(newbie);
	return newbie;
}

Locomotor* RobotFactory::createLocomotor() {
	string name;
	string price_s;
	string SKU_s;
	double price;
	int SKU;
	cout << "\nWhat is the name of your new Locomotor part?: ";
	getline(cin, name);
	cout << "\nWhat is the cost of your new Locomotor part?: ";
	getline(cin, price_s);
	price = stod(price_s);
	cout << "\nWhat is the SKU of your new Locomotor part?: ";
	getline(cin, SKU_s);
	SKU = stoi(SKU_s);
	Locomotor* newbie = new Locomotor(price, SKU, name);
	insert(newbie);
	return newbie;
}
RobotFactory::RobotFactory() {}
