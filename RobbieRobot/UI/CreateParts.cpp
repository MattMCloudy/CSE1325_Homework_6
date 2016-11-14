#include "CreateParts.h"
void colorCallback(Fl_Widget *w, void* ptr) {
	Fl_Tabs *tabs = (Fl_Tabs*)w;
	tabs->selection_color( (tabs->value())->color());
}

void inputNameCB(Fl_Widget* w, void* ptr){
	char* result;
	char** arr = (char**) ptr;
	Fl_Input* input = (Fl_Input*) w;
	result = (char*) input->value();
	std::cout << "This is not a\n";
	arr[0] = result;
}

void inputCostCB(Fl_Widget* w, void* ptr) {
	char* result;
	char** arr = (char**) ptr;
	Fl_Input* input = (Fl_Input*) w;
	result = (char*) input->value();
	arr[1] = result;
}

void partCB(Fl_Widget* w, void* ptr) {
	char** arr = (char**) ptr;
	std::cout << arr[0] << arr[1] << "\n";
}

void createPartsWindow() {
    partsWindow = new Fl_Window(800, 600, "Create Parts");
	partsWindow->color(785150208);
	
	tabs = new Fl_Tabs(10, 30, 780, 500);

	tabs->callback(colorCallback, NULL);

	Fl_PNG_Image *png = new Fl_PNG_Image("RobbiesLogo.png");

	Fl_Group *head_tab = new Fl_Group(10,55, 780,450, "Head");
		head_tab->labelfont(FL_COURIER_BOLD);
		head_tab->color(CREAM);
		head_tab->selection_color(CREAM);

		Fl_Box *head_box = new Fl_Box(225, 100, 10, 10);
		head_box->image(*png);

		char** head_cost_name;
		head_cost_name = (char**) malloc(2 * sizeof(char*));
		Fl_Input* input_head_name = new Fl_Input(30, 175, 300, 30, "What is the name of your Head part?");
		input_head_name->align(FL_ALIGN_TOP);
		input_head_name->labelfont(FL_COURIER_BOLD);
		input_head_name->callback(inputNameCB, head_cost_name);

		Fl_Input* input_head_cost = new Fl_Input(30, 250, 300, 30, "What is the cost of your Head part?");
		input_head_cost->align(FL_ALIGN_TOP);
		input_head_cost->labelfont(FL_COURIER_BOLD);
		input_head_cost->callback(inputCostCB, head_cost_name);
		
		Fl_Button* make_head_button = new Fl_Button(30, 325, 100, 50, "Make Head");
		make_head_button->color(785150208);
		make_head_button->labelcolor(FL_WHITE);
		make_head_button->labelfont(FL_COURIER_BOLD);
		make_head_button->callback(partCB, head_cost_name);

	head_tab->end();

	Fl_Group *torso_tab = new Fl_Group(10,55,780,450, "Torso");
		torso_tab->labelfont(FL_COURIER_BOLD);
		torso_tab->color(CREAM);
		torso_tab->selection_color(CREAM);
		
		Fl_Box *torso_box = new Fl_Box(225, 100, 10, 10);
		torso_box->image(*png);
		
		Fl_Input* input_torso_name = new Fl_Input(30, 175, 300, 30, "What is the name of your Torso part?");
		input_torso_name->align(FL_ALIGN_TOP);
		input_torso_name->labelfont(FL_COURIER_BOLD);

		Fl_Input* input_torso_cost = new Fl_Input(30, 250, 300, 30, "What is the cost of your Torso part?");
		input_torso_cost->align(FL_ALIGN_TOP);
		input_torso_cost->labelfont(FL_COURIER_BOLD);

	torso_tab->end();
	
	
	Fl_Group *arm_tab = new Fl_Group(10,55,780,450, "Arm");
		arm_tab->labelfont(FL_COURIER_BOLD);
		arm_tab->color(CREAM);
		arm_tab->selection_color(CREAM);
		
		Fl_Box *arm_box = new Fl_Box(225, 100, 10, 10);
		arm_box->image(*png);
		
		Fl_Input* input_arm_name = new Fl_Input(30, 175, 300, 30, "What is the name of your Arm part?");
		input_arm_name->align(FL_ALIGN_TOP);
		input_arm_name->labelfont(FL_COURIER_BOLD);

		Fl_Input* input_arm_cost = new Fl_Input(30, 250, 300, 30, "What is the cost of your Arm part?");
		input_arm_cost->align(FL_ALIGN_TOP);
		input_arm_cost->labelfont(FL_COURIER_BOLD);

	arm_tab->end();
	
	
	Fl_Group *leg_tab = new Fl_Group(10,55,780,450, "Leg");
		leg_tab->labelfont(FL_COURIER_BOLD);
		leg_tab->color(CREAM);
		leg_tab->selection_color(CREAM);
		
		Fl_Box *leg_box = new Fl_Box(225, 100, 10, 10);
		leg_box->image(*png);
		
		Fl_Input* input_leg_name = new Fl_Input(30, 175, 300, 30, "What is the name of your Leg part?");
		input_leg_name->align(FL_ALIGN_TOP);
		input_leg_name->labelfont(FL_COURIER_BOLD);

		Fl_Input* input_leg_cost = new Fl_Input(30, 250, 300, 30, "What is the cost of your Leg part?");
		input_leg_cost->align(FL_ALIGN_TOP);
		input_leg_cost->labelfont(FL_COURIER_BOLD);

	leg_tab->end();
	
	
	Fl_Group *battery_tab = new Fl_Group(10,55,780,450, "Battery");
		battery_tab->labelfont(FL_COURIER_BOLD);
		battery_tab->color(CREAM);
		battery_tab->selection_color(CREAM);
		
		Fl_Box *battery_box = new Fl_Box(225, 100, 10, 10);
		battery_box->image(*png);
		
		Fl_Input* input_battery_name = new Fl_Input(30, 175, 300, 30, "What is the name of your Battery part?");
		input_battery_name->align(FL_ALIGN_TOP);
		input_battery_name->labelfont(FL_COURIER_BOLD);

		Fl_Input* input_battery_cost = new Fl_Input(30, 250, 300, 30, "What is the cost of your Battery part?");
		input_battery_cost->align(FL_ALIGN_TOP);
		input_battery_cost->labelfont(FL_COURIER_BOLD);

	battery_tab->end();


	Fl_Group *loco_tab = new Fl_Group(10,55,780,450, "Locomotor");
		loco_tab->labelfont(FL_COURIER_BOLD);
		loco_tab->color(CREAM);
		loco_tab->selection_color(CREAM);
		
		Fl_Box *loco_box = new Fl_Box(225, 100, 10, 10);
		loco_box->image(*png);
		
		Fl_Input* input_loco_name = new Fl_Input(30, 175, 300, 30, "What is the name of your Locomotor part?");
		input_loco_name->align(FL_ALIGN_TOP);
		input_loco_name->labelfont(FL_COURIER_BOLD);

		Fl_Input* input_loco_cost = new Fl_Input(30, 250, 300, 30, "What is the cost of your Locomotor part?");
		input_loco_cost->align(FL_ALIGN_TOP);
		input_loco_cost->labelfont(FL_COURIER_BOLD);

	loco_tab->end();
	tabs->end();

    partsWindow->end();	
    partsWindow->show();
}
