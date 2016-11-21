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
	Robot* newbie = new Robot(*robot);
	robots.push_back(newbie);
    return newbie;
}

Robot * RobotFactory::createRobotFromModel(int i) {
	Robot* newbie = new Robot(*models[i]);
	robots.push_back(newbie);
    return newbie;
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

Head* RobotFactory::createHead(string name, string price_s, string SKU_s) {
	double price;
	int SKU;
	try {
			price = stod(price_s);
			SKU = stod(SKU_s);
	} catch(const exception& e) {
			cerr << "invalid SKU or price\n";
			return NULL;
	}

	Head* newbie = new Head(price, SKU, name);
	insert(newbie);
	return newbie;
}

Torso* RobotFactory::createTorso(string name, string price_s, string SKU_s, int batSlots) {
	double price;
	int SKU;
	
	try {
			price = stod(price_s);
			SKU = stod(SKU_s);
	} catch(const exception& e) {
			cerr << "Invalid price or SKU\n";
			return NULL;
	}

	Torso* newbie = new Torso(price, SKU, name);
	newbie->setBatterySlots(batSlots);
	cout << "It inserts here\n";
	insert(newbie);
	cout << newbie->getName() << "\n";
	return newbie;
}

Battery* RobotFactory::createBattery(string name, string price_s, string SKU_s) {
	double price;
	int SKU;
	try {
			price = stod(price_s);
			SKU = stod(SKU_s);
	} catch(const exception& e) {
			cerr << "invalid SKU or price\n";
			return NULL;
	}

	Battery* newbie = new Battery(price, SKU, name);
	insert(newbie);
	return newbie;

}

Leg* RobotFactory::createLeg(string name, string price_s, string SKU_s) {
	double price;
	int SKU;
	try {
			price = stod(price_s);
			SKU = stod(SKU_s);
	} catch(const exception& e) {
			cerr << "invalid SKU or price\n";
			return NULL;
	}

	Leg* newbie = new Leg(price, SKU, name);
	insert(newbie);
	return newbie;
}

Arm* RobotFactory::createArm(string name, string price_s, string SKU_s) {
	double price;
	int SKU;
	try {
			price = stod(price_s);
			SKU = stod(SKU_s);
	} catch(const exception& e) {
			cerr << "invalid SKU or price\n";
			return NULL;
	}

	Arm* newbie = new Arm(price, SKU, name);
	insert(newbie);
	return newbie;
}

Locomotor* RobotFactory::createLocomotor(string name, string price_s, string SKU_s) {
	double price;
	int SKU;
	try {
			price = stod(price_s);
			SKU = stod(SKU_s);
	} catch(const exception& e) {
			cerr << "invalid SKU or price\n";
			return NULL;
	}

	Locomotor* newbie = new Locomotor(price, SKU, name);
	insert(newbie);
	return newbie;

}
RobotFactory::RobotFactory() {}
