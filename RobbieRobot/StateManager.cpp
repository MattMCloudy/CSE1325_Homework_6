#include "StateManager.h"


/* void tabCallback(Fl_Widget *w, void* ptr) {
	Fl_Tabs *tabs = (Fl_Tabs*)w;
	tabs->selection_color( (tabs->value())->color());
} */

void quitCB(Fl_Widget * widget, void * ptr) {
	exit(0);
}

void StateManager::createMenuBar() {
	this->menu = new Fl_Menu_Bar(0, 0, 800, 25);

	menu->add("File/Quit", FL_CTRL + 'q', quitCB);
}

void StateManager::createTabs() {
	this->tabs = new Fl_Tabs(10, 30, 780, 500); {
		Fl_Group *cust_tab = new Fl_Group(10,55,780,450, "Customer"); {
		}
		cust_tab->end();
		Fl_Group *pm_tab = new Fl_Group(10,55,780,450, "Product Manager"); {
		}
		pm_tab->end();

		Fl_Group *sa_tab = new Fl_Group(10,55,780,450, "Sales Associate"); {
		}
		sa_tab->end();
		
		Fl_Group *boss_tab = new Fl_Group(10,55,780,450, "Boss"); {
		}
		boss_tab->end();

		Fl_Group *help_tab = new Fl_Group(10,55,780,450, "Help"); {
		}
		help_tab->end();
	}
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
