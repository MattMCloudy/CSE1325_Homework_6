#include "StateManager.h"

#define CREAM 4294964992

RobotFactory* StateManager::factory;

void tabCallback(Fl_Widget *w, void* ptr) {
	Fl_Tabs *tabs = (Fl_Tabs*)w;
	tabs->selection_color( (tabs->value())->color());
}

void quitCB(Fl_Widget * widget, void * ptr) {
	exit(0);
}

void createPartCB(Fl_Widget * widget, void * ptr) {
	createPartsWindow();
}

void catalogCB(Fl_Widget *w, void* ptr) {
	Fl_Multiline_Output *output = (Fl_Multiline_Output*) ptr;
	StateManager::update(ptr);
	output->show();
}

void StateManager::update(void * ptr) {
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

void StateManager::createMenuBar() {
	this->menu = new Fl_Menu_Bar(0, 0, 800, 25);

	menu->add("File/Quit", FL_CTRL + 'q', quitCB);
}

void StateManager::createTabs() {

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
		
		
		Fl_Button* button_part = new Fl_Button(30, 175, 125, 30, "Create Parts");
		button_part->color(785150208);
		button_part->labelcolor(FL_WHITE);
		button_part->labelfont(FL_COURIER_BOLD);
		button_part->callback(createPartCB, NULL);


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

void StateManager::render() {
	switch (this->curState) {
	case WELCOME:
		this->createWelcome();
	}
}

void StateManager::changeState(State state) {
	this->curState = state;
	this->render();
}

void StateManager::createWelcome() {

}
