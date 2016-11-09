#include "StateManager.h"

void quitCB(Fl_Widget * widget, void * ptr) {
	exit(0);
}

void StateManager::createMenuBar() {
	this->menu = new Fl_Menu_Bar(0, 0, 800, 25);

	menu->add("File/Quit", FL_CTRL + 'q', quitCB);
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
