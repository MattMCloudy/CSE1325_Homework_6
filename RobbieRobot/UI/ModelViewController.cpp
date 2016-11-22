#include "ModelViewController.h"

RobotFactory* ModelViewController::factory;
string ModelViewController::name;
Head* ModelViewController::head;
Torso* ModelViewController::torso;
Arm* ModelViewController::arm;
Leg* ModelViewController::leg;
Locomotor* ModelViewController::loco;
Battery** ModelViewController::batt;
int ModelViewController::bat_count;

/* string ModelViewController::stockParts(PART c) {
	string result = "";
	switch (c) {
		case head: {
				vector<Head*> heads = factory->getHeadParts();
				for (int i = 0; i < heads.size(); i++) {
					result = result + heads[i]->getName() + "\n";
				}
				break;
		}
		case torso: {
				vector<Torso*> torsos = factory->getTorsoParts();
				for (int i = 0; i < torsos.size(); i++) {
					result = result + torsos[i]->getName() + "\n";
				}
				break;
		}
		case arm: {
				vector<Arm*> arms = factory->getArmParts();
				for (int i = 0; i < arms.size(); i++) {
					result = result + arms[i]->getName() + "\n";
				}
				break;
		}
		case leg: {
				vector<Leg*> legs = factory->getLegParts();
				for (int i = 0; i < legs.size(); i++) {
					result = result + legs[i]->getName() + "\n";
				}
				break;
		}
		case locomotor: {
				vector<Locomotor*> locomotors = factory->getLocomotorParts();
				for (int i = 0; i < locomotors.size(); i++) {
					result = result + locomotors[i]->getName() + "\n";
				}
				break;
		}
		case battery: {
				vector<Battery*> batteries = factory->getBatteryParts();
				for (int i = 0; i < batteries.size(); i++) {
					result = result + batteries[i]->getName() + "\n";
				}
				break;
		}
	}
	return result;
} */

ModelViewController::ModelViewController(RobotFactory* fact) {
		batt = (Battery**) malloc(3 * sizeof(Battery*));
		batt[0] = NULL;
		batt[1] = NULL;
		batt[2] = NULL;
		
		factory = fact;
		bat_count = 0;
		head = NULL;
		torso = NULL;
		arm = NULL;
		leg = NULL;
		loco = NULL;
}

void ModelViewController::headChoiceCB(Fl_Widget* w, void* ptr) {
	Fl_Choice* head_choice = (Fl_Choice*) ptr;
	vector<Head *> heads = factory->getHeadParts();
	for (int i = 0; i < heads.size(); i++) {
		head_choice->add(heads[i]->getName().c_str());
	}
}


void ModelViewController::headButtonCB(Fl_Widget* w, void* ptr) {
	string result = "";
	vector<Head*> heads = factory->getHeadParts();
	Fl_Multiline_Output* out = (Fl_Multiline_Output*) ptr;
	for (int i = 0; i < heads.size(); i++) {
		result = result + heads[i]->getName() + "\n";
	}
	out->value(result.c_str());
	out->show();
}

void ModelViewController::torsoButtonCB(Fl_Widget* w, void* ptr) {
	string result = "";
	vector<Torso*> torsos = factory->getTorsoParts();
	Fl_Multiline_Output* out = (Fl_Multiline_Output*) ptr;
	for (int i = 0; i < torsos.size(); i++) {
		result = result + torsos[i]->getName() + "\n";
	}
	out->value(result.c_str());
	out->show();

}

void ModelViewController::armButtonCB(Fl_Widget* w, void* ptr) {
	string result = "";
	vector<Arm*> arms = factory->getArmParts();
	Fl_Multiline_Output* out = (Fl_Multiline_Output*) ptr;
	for (int i = 0; i < arms.size(); i++) {
		result = result + arms[i]->getName() + "\n";
	}
	out->value(result.c_str());
	out->show();

}

void ModelViewController::legButtonCB(Fl_Widget* w, void* ptr) {
	string result = "";
	vector<Leg*> legs = factory->getLegParts();
	Fl_Multiline_Output* out = (Fl_Multiline_Output*) ptr;
	for (int i = 0; i < legs.size(); i++) {
		result = result + legs[i]->getName() + "\n";
	}
	out->value(result.c_str());
	out->show();
}

void ModelViewController::locoButtonCB(Fl_Widget* w, void* ptr) {
	string result = "";
	vector<Locomotor*> locos = factory->getLocomotorParts();
	Fl_Multiline_Output* out = (Fl_Multiline_Output*) ptr;
	for (int i = 0; i < locos.size(); i++) {
		result = result + locos[i]->getName() + "\n";
	}
	out->value(result.c_str());
	out->show();
}

void ModelViewController::batteryButtonCB(Fl_Widget* w, void* ptr) {
	string result = "";
	vector<Battery*> batteries = factory->getBatteryParts();
	Fl_Multiline_Output* out = (Fl_Multiline_Output*) ptr;
	for (int i = 0; i < batteries.size(); i++) {
		result = result + batteries[i]->getName() + "\n";
	}
	out->value(result.c_str());
	out->show();
}

void ModelViewController::nameInputCB(Fl_Widget*w, void* ptr) {
	Fl_Input* input = (Fl_Input*) w;
	name = input->value();
}

void ModelViewController::headInputCB(Fl_Widget* w, void* ptr) {
	Fl_Input* input = (Fl_Input*) w;
	vector<Head*> heads = factory->getHeadParts();
	for (int i = 0; i < heads.size(); i++) {
		if (strcmp(input->value(), heads[i]->getName().c_str()) == 0){
			head = heads[i];
			input->hide();
		}
	}
}

void ModelViewController::torsoInputCB(Fl_Widget* w, void* ptr) {
	Fl_Input* input = (Fl_Input*) w;
	vector<Torso*> torsos = factory->getTorsoParts();
	for (int i = 0; i < torsos.size(); i++) {
		if (strcmp(input->value(), torsos[i]->getName().c_str()) == 0){
			torso = torsos[i];
			input->hide();
		}
	}
}

void ModelViewController::armInputCB(Fl_Widget* w, void* ptr) {
	Fl_Input* input = (Fl_Input*) w;
	vector<Arm*> arms = factory->getArmParts();
	for (int i = 0; i < arms.size(); i++) {
		if (strcmp(input->value(), arms[i]->getName().c_str()) == 0){
			arm = arms[i];
			input->hide();
		}
	}
}

void ModelViewController::legInputCB(Fl_Widget* w, void* ptr) {
	Fl_Input* input = (Fl_Input*) w;
	vector<Leg*> legs = factory->getLegParts();
	for (int i = 0; i < legs.size(); i++) {
		if (strcmp(input->value(), legs[i]->getName().c_str()) == 0){
			leg = legs[i];
			input->hide();
		}
	}
}

void ModelViewController::locoInputCB(Fl_Widget* w, void* ptr) {
	Fl_Input* input = (Fl_Input*) w;
	vector<Locomotor*> locos = factory->getLocomotorParts();
	for (int i = 0; i < locos.size(); i++) {
		if (strcmp(input->value(), locos[i]->getName().c_str()) == 0){
			loco = locos[i];
			input->hide();
		}
	}

}

void ModelViewController::batteryInputCB(Fl_Widget* w, void* ptr) {
	Fl_Input* input = (Fl_Input*) w;
	cout << "What\n";
	vector<Battery*> batts = factory->getBatteryParts();
	for (int i = 0; i < batts.size(); i++) {
		if (strcmp(input->value(), batts[i]->getName().c_str()) == 0){
			cout << "Where is the prob?\n";
			batt[bat_count] = batts[i];
			cout << "you might have made it once\n";
			if (torso->getBatterySlots() == bat_count+1)
				input->hide();
			bat_count++;
		}
	}

}

//void createModel(string name, Head* head, Torso* torso, Battery* battery1, 
//Battery* battery2, Battery* battery3, Leg* leftLeg, 
//Leg* rightLeg, Arm* leftArm, Arm* rightArm, Locomotor* locomotor);


void ModelViewController::makeModelCB(Fl_Widget* w, void* ptr) {
	factory->createModel(name, head, torso, batt[0], batt[1], batt[2], leg, leg, arm, arm, loco);
}

void ModelViewController::createModelWindow() {
	Fl_Window* win = new Fl_Window(800, 600, "Create Models");
	win->color(785150208);

	Fl_Tabs* tab = new Fl_Tabs(10, 30, 780, 500);
	tab->color(CREAM);
	tab->selection_color(CREAM);
	
	Fl_Group* model_maker = new Fl_Group(10, 55, 780, 450, "Model Maker");
	model_maker->labelfont(FL_COURIER_BOLD);
	model_maker->color(CREAM);
	model_maker->selection_color(CREAM);
		Fl_Input* name_model = new Fl_Input(200, 100, 200, 25, "Please name your Model");
		name_model->align(FL_ALIGN_LEFT);
		name_model->callback(nameInputCB, NULL);

		/***/

		Fl_Multiline_Output* head_out = new Fl_Multiline_Output(30, 175, 100, 100, "Head");
		head_out->align(FL_ALIGN_TOP);
		head_out->hide();
		
		Fl_Button* head_button = new Fl_Button(30, 300, 100, 25, "Show Heads");
		head_button->color(785150208);
		head_button->callback(headButtonCB, head_out);

		Fl_Input* head_in = new Fl_Input(30, 400, 100, 25, "Enter a Head");
		head_in->align(FL_ALIGN_TOP);
		head_in->callback(headInputCB, NULL);

		/***/

		Fl_Multiline_Output* torso_out = new Fl_Multiline_Output(155, 175, 100, 100, "Torso");
		torso_out->align(FL_ALIGN_TOP);
		torso_out->hide();
		
		Fl_Button* torso_button = new Fl_Button(155, 300, 100, 25, "Show Torso");
		torso_button->color(785150208);
		torso_button->callback(torsoButtonCB, torso_out);

		Fl_Input* torso_in = new Fl_Input(155, 400, 100, 25, "Enter a Torso");
		torso_in->align(FL_ALIGN_TOP);
		torso_in->callback(torsoInputCB, NULL);

		/***/

		Fl_Multiline_Output* leg_out = new Fl_Multiline_Output(280, 175, 100, 100, "Leg");
		leg_out->align(FL_ALIGN_TOP);
		leg_out->hide();

		Fl_Button* leg_button = new Fl_Button(280, 300, 100, 25, "Show Legs");
		leg_button->color(785150208);
		leg_button->callback(legButtonCB, leg_out);

		Fl_Input* leg_in = new Fl_Input(280, 400, 100, 25, "Enter a Leg");
		leg_in->align(FL_ALIGN_TOP);
		leg_in->callback(legInputCB, NULL);

		/***/

		Fl_Multiline_Output* arm_out = new Fl_Multiline_Output(405, 175, 100, 100, "Arm");
		arm_out->align(FL_ALIGN_TOP);
		arm_out->hide();

		Fl_Button* arm_button = new Fl_Button(405, 300, 100, 25, "Show Arms");
		arm_button->color(785150208);
		arm_button->callback(armButtonCB, arm_out);

		Fl_Input* arm_in = new Fl_Input(405, 400, 100, 25, "Enter an Arm");
		arm_in->align(FL_ALIGN_TOP);
		arm_in->callback(armInputCB, NULL);

		/***/

		Fl_Multiline_Output* loco_out = new Fl_Multiline_Output(530, 175, 100, 100, "Locomotor");
		loco_out->align(FL_ALIGN_TOP);
		loco_out->hide();

		Fl_Button* loco_button = new Fl_Button(525, 300, 117, 25, "Show Locomotors");
		loco_button->color(785150208);
		loco_button->callback(locoButtonCB, loco_out);

		Fl_Input* loco_in = new Fl_Input(530, 400, 100, 25, "Enter a Locomotor");
		loco_in->align(FL_ALIGN_TOP);
		loco_in->callback(locoInputCB, NULL);

		/***/

		Fl_Multiline_Output* bat_out = new Fl_Multiline_Output(655, 175, 100, 100, "Battery");
		bat_out->align(FL_ALIGN_TOP);
		bat_out->hide();

		Fl_Button* bat_button = new Fl_Button(650, 300, 117, 25, "Show Batteries");
		bat_button->color(785150208);
		bat_button->callback(batteryButtonCB,bat_out);

		Fl_Input* bat_in = new Fl_Input(655, 400, 100, 25, "Enter a Battery");
		bat_in->align(FL_ALIGN_TOP);
		bat_in->callback(batteryInputCB, NULL);

		/***/

		Fl_Button* make_model = new Fl_Button(300, 450, 200, 50, "Make Model");
		make_model->color(785150208);
		make_model->callback(makeModelCB, NULL);
		
	model_maker->end();
	
	tab->end();

	win->show();
	Fl::run();


}
