#include "CreateParts.h"

Fl_Window* PartViewController::partsWindow;
Fl_Tabs* PartViewController::tabs;
RobotFactory* PartViewController::factory;


void colorCallback(Fl_Widget *w, void* ptr) {
	Fl_Tabs *tabs = (Fl_Tabs*)w;
	tabs->selection_color( (tabs->value())->color());
}

void inputNameCB(Fl_Widget* w, void* ptr){
	char* result;
	char** arr = (char**) ptr;
	Fl_Input* input = (Fl_Input*) w;
	result = (char*) input->value();
	arr[0] = result;
}

void inputCostCB(Fl_Widget* w, void* ptr) {
	char* result;
	char** arr = (char**) ptr;
	Fl_Input* input = (Fl_Input*) w;
	result = (char*) input->value();
	arr[1] = result;
}

void inputSKUCB(Fl_Widget* w, void* ptr) {
	char* result;
	char** arr = (char**) ptr;
	Fl_Input* input = (Fl_Input*) w;
	result = (char*) input->value();
	arr[2] = result;
}

void inputSlotsCB(Fl_Widget* w, void* ptr) {
	char* result;
	char** arr = (char**) ptr;
	Fl_Input* input = (Fl_Input*) w;
	result = (char*) input->value();
	arr[3] = result;
}

PartViewController::PartViewController(RobotFactory* fact) {
		factory = fact;
}


void PartViewController::headPartCB(Fl_Widget* w, void* ptr) {
	char** arr = (char**) ptr;
	Head* newbie = factory->createHead(arr[0], arr[1], arr[2]);
	Fl_Window* disp = new Fl_Window(100, 100, 100, 100, "Head Part Created");
}

void PartViewController::armPartCB(Fl_Widget* w, void* ptr) {
	char** arr = (char**) ptr;
	Arm* newbie = factory->createArm(arr[0], arr[1], arr[2]);
}

void PartViewController::legPartCB(Fl_Widget* w, void* ptr) {
	char** arr = (char**) ptr;
	Leg* newbie = factory->createLeg(arr[0], arr[1], arr[2]);
}

void PartViewController::torsoPartCB(Fl_Widget* w, void* ptr) {
	char** arr = (char**) ptr;
	Torso* newbie = factory->createTorso(arr[0], arr[1], arr[2], atoi(arr[3]));
}

void PartViewController::batteryPartCB(Fl_Widget* w, void* ptr) {
	char** arr = (char**) ptr;
	Battery* newbie = factory->createBattery(arr[0], arr[1], arr[2]);
}

void PartViewController::locomotorPartCB(Fl_Widget* w, void* ptr) {
	char** arr = (char**) ptr;
	Locomotor* newbie = factory->createLocomotor(arr[0], arr[1], arr[2]);
}

void PartViewController::createPartsWindow() {
    partsWindow = new Fl_Window(800, 600, "Create Parts");
	partsWindow->color(785150208);
	
	tabs = new Fl_Tabs(10, 30, 780, 500);
	tabs->color(CREAM);
	tabs->selection_color(CREAM);
	tabs->callback(colorCallback, NULL);

	Fl_PNG_Image *png = new Fl_PNG_Image("RobbiesLogo.png");

	Fl_Group *head_tab = new Fl_Group(10,55, 780,450, "Head");
		head_tab->labelfont(FL_COURIER_BOLD);
		head_tab->color(CREAM);
		head_tab->selection_color(CREAM);

		Fl_Box *head_box = new Fl_Box(225, 100, 10, 10);
		head_box->image(*png);

		char** head_cost_name;
		head_cost_name = (char**) malloc(3 * sizeof(char*));

		Fl_Input* input_head_name = new Fl_Input(30, 175, 300, 30, "What is the name of your Head part?");
		input_head_name->align(FL_ALIGN_TOP);
		input_head_name->labelfont(FL_COURIER_BOLD);
		input_head_name->callback(inputNameCB, head_cost_name);

		Fl_Input* input_head_cost = new Fl_Input(30, 250, 300, 30, "What is the cost of your Head part?");
		input_head_cost->align(FL_ALIGN_TOP);
		input_head_cost->labelfont(FL_COURIER_BOLD);
		input_head_cost->callback(inputCostCB, head_cost_name);
		
		Fl_Input* input_head_SKU = new Fl_Input(30, 325, 300, 30, "What is the SKU of your Head part?");
		input_head_SKU->align(FL_ALIGN_TOP);
		input_head_SKU->labelfont(FL_COURIER_BOLD);
		input_head_SKU->callback(inputSKUCB, head_cost_name);
			
		Fl_Multiline_Output* head_out = new Fl_Multiline_Output(475, 175, 150, 30);
		head_out->value("Part has been created!\n");
		head_out->hide();
		
		Fl_Button* make_head_button = new Fl_Button(30, 400, 100, 25, "Make Head");
		make_head_button->color(785150208);
		make_head_button->labelcolor(FL_WHITE);
		make_head_button->labelfont(FL_COURIER_BOLD);
		make_head_button->callback(headPartCB, head_cost_name);
	
		head_tab->end();

	Fl_Group *torso_tab = new Fl_Group(10,55,780,450, "Torso");
		torso_tab->labelfont(FL_COURIER_BOLD);
		torso_tab->color(CREAM);
		torso_tab->selection_color(CREAM);
		
		Fl_Box *torso_box = new Fl_Box(225, 100, 10, 10);
		torso_box->image(*png);
		
		char** torso_cost_name;
		torso_cost_name = (char**) malloc(4 * sizeof(char*));
		Fl_Input* input_torso_name = new Fl_Input(30, 175, 300, 30, "What is the name of your Torso part?");
		input_torso_name->align(FL_ALIGN_TOP);
		input_torso_name->labelfont(FL_COURIER_BOLD);
		input_torso_name->callback(inputNameCB, torso_cost_name);

		Fl_Input* input_torso_cost = new Fl_Input(30, 250, 300, 30, "What is the cost of your Torso part?");
		input_torso_cost->align(FL_ALIGN_TOP);
		input_torso_cost->labelfont(FL_COURIER_BOLD);
		input_torso_cost->callback(inputCostCB, torso_cost_name);

		Fl_Input* input_torso_SKU = new Fl_Input(30, 325, 300, 30, "What is the SKU of your Torso part?");
		input_torso_SKU->align(FL_ALIGN_TOP);
		input_torso_SKU->labelfont(FL_COURIER_BOLD);
		input_torso_SKU->callback(inputSKUCB, torso_cost_name);
		
		Fl_Input* input_torso_slots = new Fl_Input(305, 400, 25, 30, "Number of battery slots (0-3):");
		input_torso_slots->align(FL_ALIGN_LEFT);
		input_torso_slots->labelfont(FL_COURIER_BOLD);
		input_torso_slots->callback(inputSlotsCB, torso_cost_name);

		Fl_Multiline_Output* torso_out = new Fl_Multiline_Output(475, 175, 150, 30);
		torso_out->value("Part has been created!\n");
		torso_out->hide();

		Fl_Button* make_torso_button = new Fl_Button(30, 475, 100, 25, "Make Torso");
		make_torso_button->color(78515020);
		make_torso_button->labelcolor(FL_WHITE);
		make_torso_button->labelfont(FL_COURIER_BOLD);
		make_torso_button->callback(torsoPartCB, torso_cost_name);

	torso_tab->end();
	
	
	Fl_Group *arm_tab = new Fl_Group(10,55,780,450, "Arm");
		arm_tab->labelfont(FL_COURIER_BOLD);
		arm_tab->color(CREAM);
		arm_tab->selection_color(CREAM);
		
		Fl_Box *arm_box = new Fl_Box(225, 100, 10, 10);
		arm_box->image(*png);
		
		char** arm_cost_name;
		arm_cost_name = (char**) malloc(3 * sizeof(char*));
		Fl_Input* input_arm_name = new Fl_Input(30, 175, 300, 30, "What is the name of your Arm part?");
		input_arm_name->align(FL_ALIGN_TOP);
		input_arm_name->labelfont(FL_COURIER_BOLD);
		input_arm_name->callback(inputNameCB, arm_cost_name);


		Fl_Input* input_arm_cost = new Fl_Input(30, 250, 300, 30, "What is the cost of your Arm part?");
		input_arm_cost->align(FL_ALIGN_TOP);
		input_arm_cost->labelfont(FL_COURIER_BOLD);
		input_arm_cost->callback(inputCostCB, arm_cost_name);

		Fl_Input* input_arm_SKU = new Fl_Input(30, 325, 300, 30, "What is the SKU of your Arm part?");
		input_arm_SKU->align(FL_ALIGN_TOP);
		input_arm_SKU->labelfont(FL_COURIER_BOLD);
		input_arm_SKU->callback(inputSKUCB, arm_cost_name);

		Fl_Multiline_Output* arm_out = new Fl_Multiline_Output(475, 175, 150, 30);
		arm_out->value("Part has been created!\n");
		arm_out->hide();

		Fl_Button* make_arm_button = new Fl_Button(30, 400, 100, 25, "Make Arm");
		make_arm_button->color(78515020);
		make_arm_button->labelcolor(FL_WHITE);
		make_arm_button->labelfont(FL_COURIER_BOLD);
		make_arm_button->callback(armPartCB, arm_cost_name);

	arm_tab->end();
	
	
	Fl_Group *leg_tab = new Fl_Group(10,55,780,450, "Leg");
		leg_tab->labelfont(FL_COURIER_BOLD);
		leg_tab->color(CREAM);
		leg_tab->selection_color(CREAM);
		
		Fl_Box *leg_box = new Fl_Box(225, 100, 10, 10);
		leg_box->image(*png);
		
		char** leg_cost_name;
		leg_cost_name = (char**) malloc(3 * sizeof(char*));
		Fl_Input* input_leg_name = new Fl_Input(30, 175, 300, 30, "What is the name of your Leg part?");
		input_leg_name->align(FL_ALIGN_TOP);
		input_leg_name->labelfont(FL_COURIER_BOLD);
		input_leg_name->callback(inputNameCB, leg_cost_name);

		Fl_Input* input_leg_cost = new Fl_Input(30, 250, 300, 30, "What is the cost of your Leg part?");
		input_leg_cost->align(FL_ALIGN_TOP);
		input_leg_cost->labelfont(FL_COURIER_BOLD);
		input_leg_cost->callback(inputCostCB, leg_cost_name);

		Fl_Input* input_leg_SKU = new Fl_Input(30, 325, 300, 30, "What is the SKU of your Leg part?");
		input_leg_SKU->align(FL_ALIGN_TOP);
		input_leg_SKU->labelfont(FL_COURIER_BOLD);
		input_leg_SKU->callback(inputSKUCB, leg_cost_name);
		
		Fl_Multiline_Output* leg_out = new Fl_Multiline_Output(475, 175, 150, 30);
		leg_out->value("Part has been created!\n");
		leg_out->hide();

		Fl_Button* make_leg_button = new Fl_Button(30, 400, 100, 25, "Make Leg");
		make_leg_button->color(78515020);
		make_leg_button->labelcolor(FL_WHITE);
		make_leg_button->labelfont(FL_COURIER_BOLD);
		make_leg_button->callback(legPartCB, leg_cost_name);
	
	leg_tab->end();
	
	
	Fl_Group *battery_tab = new Fl_Group(10,55,780,450, "Battery");
		battery_tab->labelfont(FL_COURIER_BOLD);
		battery_tab->color(CREAM);
		battery_tab->selection_color(CREAM);
		
		Fl_Box *battery_box = new Fl_Box(225, 100, 10, 10);
		battery_box->image(*png);
		
		char** battery_cost_name;
		battery_cost_name = (char**) malloc(3 * sizeof(char*));
		Fl_Input* input_battery_name = new Fl_Input(30, 175, 300, 30, "What is the name of your Battery part?");
		input_battery_name->align(FL_ALIGN_TOP);
		input_battery_name->labelfont(FL_COURIER_BOLD);
		input_battery_name->callback(inputNameCB, battery_cost_name);

		Fl_Input* input_battery_cost = new Fl_Input(30, 250, 300, 30, "What is the cost of your Battery part?");
		input_battery_cost->align(FL_ALIGN_TOP);
		input_battery_cost->labelfont(FL_COURIER_BOLD);
		input_battery_cost->callback(inputCostCB, battery_cost_name);

		Fl_Input* input_battery_SKU = new Fl_Input(30, 325, 300, 30, "What is the SKU of your Battery part?");
		input_battery_SKU->align(FL_ALIGN_TOP);
		input_battery_SKU->labelfont(FL_COURIER_BOLD);
		input_battery_SKU->callback(inputSKUCB, battery_cost_name);
		
		Fl_Multiline_Output* battery_out = new Fl_Multiline_Output(475, 175, 150, 30);
		battery_out->value("Part has been created!\n");
		battery_out->hide();

		Fl_Button* make_battery_button = new Fl_Button(30, 400, 150, 25, "Make Battery");
		make_battery_button->color(78515020);
		make_battery_button->labelcolor(FL_WHITE);
		make_battery_button->labelfont(FL_COURIER_BOLD);
		make_battery_button->callback(batteryPartCB, battery_cost_name);

	battery_tab->end();


	Fl_Group *loco_tab = new Fl_Group(10,55,780,450, "Locomotor");
		loco_tab->labelfont(FL_COURIER_BOLD);
		loco_tab->color(CREAM);
		loco_tab->selection_color(CREAM);
		
		Fl_Box *loco_box = new Fl_Box(225, 100, 10, 10);
		loco_box->image(*png);
		
		char** loco_cost_name;
		loco_cost_name = (char**) malloc(3 * sizeof(char*));
		Fl_Input* input_loco_name = new Fl_Input(30, 175, 300, 30, "What is the name of your Locomotor part?");
		input_loco_name->align(FL_ALIGN_TOP);
		input_loco_name->labelfont(FL_COURIER_BOLD);
		input_loco_name->callback(inputNameCB, loco_cost_name);

		Fl_Input* input_loco_cost = new Fl_Input(30, 250, 300, 30, "What is the cost of your Locomotor part?");
		input_loco_cost->align(FL_ALIGN_TOP);
		input_loco_cost->labelfont(FL_COURIER_BOLD);
		input_loco_cost->callback(inputCostCB, loco_cost_name);

		Fl_Input* input_loco_SKU = new Fl_Input(30, 325, 300, 30, "What is the SKU of your Locomotor part?");
		input_loco_SKU->align(FL_ALIGN_TOP);
		input_loco_SKU->labelfont(FL_COURIER_BOLD);
		input_loco_SKU->callback(inputSKUCB, loco_cost_name);
		

		Fl_Multiline_Output* loco_out = new Fl_Multiline_Output(475, 175, 150, 30);
		loco_out->value("Part has been created!\n");
		loco_out->hide();

		Fl_Button* make_loco_button = new Fl_Button(30, 400, 150, 25, "Make Locomotor");
		make_loco_button->color(78515020);
		make_loco_button->labelcolor(FL_WHITE);
		make_loco_button->labelfont(FL_COURIER_BOLD);
		make_loco_button->callback(locomotorPartCB, loco_cost_name);

	loco_tab->end();
	tabs->end();

    partsWindow->end();	
    partsWindow->show();
}
