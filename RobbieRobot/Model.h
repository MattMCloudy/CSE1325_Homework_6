#ifndef MODEL_H
#define MODEL_H

#include "Part/Head.h"
#include "Part/Arm.h"
#include "Part/Torso.h"
#include "Part/Leg.h"
#include "Part/Part.h"
#include "Part/Battery.h"

class Model {
	private:
		string name;
		string ID;
		Head head;
		Arm l_arm;
		Arm r_arm;
		Torso torso;
		Leg l_leg;
		Leg r_leg;
		Battery battery;
		//Locomotor locomotor;
	public:
		Model(string name , string ID, Head head, Arm l_arm, Arm r_arm, Torso torso, Leg l_leg, Battery battery);
};

#endif
