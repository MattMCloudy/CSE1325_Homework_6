#include "StateManager.h"

StateManager::StateManager() {
    this->win = new Fl_Window(800, 600, "Robbie Robot Shop Manager");
    
}

void StateManager::showWindow() {
    this->win->show();

    Fl::run();
}
