#include "CreateParts.h"
void colorCallback(Fl_Widget *w, void* ptr) {
	Fl_Tabs *tabs = (Fl_Tabs*)w;
	tabs->selection_color( (tabs->value())->color());
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


		Fl_Input* input_head_name = new Fl_Input(30, 250, 300, 30, "What is the name of your Head part?");
		input_head_name->align(FL_ALIGN_TOP);
		input_head_name->labelfont(FL_COURIER_BOLD);

		Fl_Input* input_head_cost = new Fl_Input(30, 325, 300, 30, "What is the cost of your Head part?");
		input_head_cost->align(FL_ALIGN_TOP);
		input_head_cost->labelfont(FL_COURIER_BOLD);

	head_tab->end();

	Fl_Group *torso_tab = new Fl_Group(10,55,780,450, "Torso");
		torso_tab->labelfont(FL_COURIER_BOLD);
		torso_tab->color(CREAM);
		torso_tab->selection_color(CREAM);
		
		Fl_Box *torso_box = new Fl_Box(225, 100, 10, 10);
		torso_box->image(*png);
		
		Fl_Input* input_torso_name = new Fl_Input(30, 250, 300, 30, "What is the name of your Torso part?");
		input_torso_name->align(FL_ALIGN_TOP);
		input_torso_name->labelfont(FL_COURIER_BOLD);

		Fl_Input* input_torso_cost = new Fl_Input(30, 325, 300, 30, "What is the cost of your Torso part?");
		input_torso_cost->align(FL_ALIGN_TOP);
		input_torso_cost->labelfont(FL_COURIER_BOLD);

	torso_tab->end();

	tabs->end();

    partsWindow->end();	
    partsWindow->show();
}
