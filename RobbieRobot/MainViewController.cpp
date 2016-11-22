#include "MainViewController.h"

#define CREAM 4294964992

RobotFactory* MainViewController::factory;

void tabCallback(Fl_Widget *w, void* ptr) {
	Fl_Tabs *tabs = (Fl_Tabs*)w;
	tabs->selection_color( (tabs->value())->color());
}

void quitCB(Fl_Widget * widget, void * ptr) {
	exit(0);
}

void MainViewController::createPartCB(Fl_Widget * widget, void * ptr) {
	PartViewController* partView = new PartViewController(factory);
	partView->createPartsWindow();
}

void MainViewController::createModelCB(Fl_Widget* w, void* ptr) {
	ModelViewController* modelView = new ModelViewController(factory);
	modelView->createModelWindow();
}

void catalogCB(Fl_Widget *w, void* ptr) {
	Fl_Multiline_Output *output = (Fl_Multiline_Output*) ptr;
	MainViewController::update(ptr);
	output->show();
}

void MainViewController::modelInputCB(Fl_Widget* w, void* ptr) {
	char** values = (char**) ptr;
	Fl_Input* input = (Fl_Input*) w;
	values[0] = (char*) input->value();
}

void MainViewController::robotNameCB(Fl_Widget* w, void* ptr) {
	char** values = (char**) ptr;
	Fl_Input* input = (Fl_Input*) w;
	values[1] = (char*) input->value();
}

void MainViewController::showModelsCB(Fl_Widget* w, void* ptr) {
	string result = "";
	vector<Robot*> models = factory->getModels();
	Fl_Multiline_Output* out = (Fl_Multiline_Output*) ptr;
	for (int i = 0; i < models.size(); i++) {
		result = result + models[i]->getName() + "\n";
	}
	out->value(result.c_str());
	out->show();
}

void MainViewController::makeRobotCB(Fl_Widget* w, void* ptr) {
	char** values = (char**) ptr;
	Fl_Button* button = (Fl_Button*) w;
	vector<Robot*> models = factory->getModels();
	for (int i = 0; i < models.size(); i++) {
		if (strcmp(values[0], models[i]->getName().c_str()) == 0){
			Robot* temp = factory->createRobotFromModel(values[1], models[i]);
			button->color(FL_BLUE);
		}
	}
}

void MainViewController::update(void * ptr) {
	std::string result = "";
	Fl_Multiline_Output *output = (Fl_Multiline_Output*) ptr;
	vector<Robot *> robots = factory->getRobots();
	if (robots.empty()){
		output->value("We currently have no robots.\n");
		return;
	}

	for (int i = 0; i < robots.size(); i++) {
	     result = result + robots[i]->getName() + "\n";
	}
	output->value(result.c_str());	
}

void MainViewController::createMenuBar() {
	this->menu = new Fl_Menu_Bar(0, 0, 800, 25);

	menu->add("File/Quit", FL_CTRL + 'q', quitCB);
}

void MainViewController::createTabs() {

	this->tabs = new Fl_Tabs(10, 30, 780, 500);
	tabs->callback(tabCallback, NULL);

	Fl_PNG_Image *png = new Fl_PNG_Image("RobbiesLogo.png");

	Fl_Group *cust_tab = new Fl_Group(10,55, 780,450, "Customer");
		cust_tab->labelfont(FL_COURIER_BOLD);
		cust_tab->color(CREAM);
		cust_tab->selection_color(CREAM);

		Fl_Box *cust_box = new Fl_Box(225, 100, 10, 10);
		cust_box->image(*png);


		Fl_Multiline_Output *output = new Fl_Multiline_Output(500, 175, 200, 200);
		output->hide();

		Fl_Button* button_catalog = new Fl_Button(30, 175, 100, 30, "Catalog");
		button_catalog->color(785150208);
		button_catalog->labelcolor(FL_WHITE);
		button_catalog->labelfont(FL_COURIER_BOLD);
		button_catalog->callback(catalogCB, output);

		Fl_Input* input_purchase = new Fl_Input(30, 250, 300, 30, "Which robot would you like to buy?");
		input_purchase->align(FL_ALIGN_TOP);
		input_purchase->labelfont(FL_COURIER_BOLD);

		Fl_Input* input_cust_sales_rec = new Fl_Input(30, 325, 300, 30, "Enter your name to see past purchases");
		input_cust_sales_rec->align(FL_ALIGN_TOP);
		input_cust_sales_rec->labelfont(FL_COURIER_BOLD);

	cust_tab->end();

	Fl_Group *pm_tab = new Fl_Group(10,55,780,450, "Product Manager");
		pm_tab->labelfont(FL_COURIER_BOLD);
		pm_tab->color(CREAM);
		pm_tab->selection_color(CREAM);
		
		Fl_Box *pm_box = new Fl_Box(225, 100, 10, 10);
		pm_box->image(*png);
		
		char** robot_search_name = (char**) malloc(2 * sizeof(char*));
		Fl_Button* button_part = new Fl_Button(30, 175, 125, 30, "Create Parts");
		button_part->color(785150208);
		button_part->labelcolor(FL_WHITE);
		button_part->labelfont(FL_COURIER_BOLD);
		button_part->callback(createPartCB, NULL);

		
		Fl_Button* button_model = new Fl_Button(30, 250, 125, 30, "Create Model");
		button_model->color(785150208);
		button_model->labelcolor(FL_WHITE);
		button_model->labelfont(FL_COURIER_BOLD);
		button_model->callback(createModelCB, NULL);

		Fl_Multiline_Output* view_models = new Fl_Multiline_Output(500, 175, 200, 200, "Models");
		view_models->align(FL_ALIGN_TOP);
		view_models->hide();

		Fl_Button* button_show= new Fl_Button(250, 175, 125, 30, "Show Models");
		button_show->color(785150208);
		button_show->labelcolor(FL_WHITE);
		button_show->labelfont(FL_COURIER_BOLD);
		button_show->callback(showModelsCB, view_models);

		Fl_Input* model_input = new Fl_Input(250, 325, 150, 30, "What model robot will you make?");
		model_input->align(FL_ALIGN_LEFT);
		model_input->callback(modelInputCB, robot_search_name);

		Fl_Input* robot_name = new Fl_Input(250, 400, 150, 30, "What will be the name of your robot?");
		robot_name->align(FL_ALIGN_LEFT);
		robot_name->callback(robotNameCB, robot_search_name);

		Fl_Button* button_robot = new Fl_Button(250, 250, 125, 30, "Make New Robot");
		button_robot->color(785150208);
		button_robot->labelcolor(FL_WHITE);
		button_robot->labelfont(FL_COURIER_BOLD);
		button_robot->callback(makeRobotCB, robot_search_name);

	pm_tab->end();

	Fl_Group *sa_tab = new Fl_Group(10,55,780,450, "Sales Associate");
		sa_tab->labelfont(FL_COURIER_BOLD);
		sa_tab->color(CREAM);
		sa_tab->selection_color(CREAM);

		Fl_Box *sa_box = new Fl_Box(225, 100, 10, 10);
		sa_box->image(*png);
	sa_tab->end();

	Fl_Group *boss_tab = new Fl_Group(10,55,780,450, "Boss");
		boss_tab->labelfont(FL_COURIER_BOLD);
		boss_tab->color(CREAM);
		boss_tab->selection_color(CREAM);

		Fl_Box *boss_box = new Fl_Box(225, 100, 10, 10);
		boss_box->image(*png);
	boss_tab->end();

	Fl_Group *help_tab = new Fl_Group(10,55,780,450, "Help");
		help_tab->labelfont(FL_COURIER_BOLD);
		help_tab->color(CREAM);
		help_tab->selection_color(CREAM);

		Fl_Box *help_box = new Fl_Box(225, 100, 10, 10);
		help_box->image(*png);
	help_tab->end();

	tabs->selection_color( (tabs->value())->color() );
	tabs->end();
}

void MainViewController::render() {
	switch (this->curState) {
	case WELCOME:
		this->createWelcome();
	}
}

void MainViewController::changeState(State state) {
	this->curState = state;
	this->render();
}

void MainViewController::createWelcome() {

}
