#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include "StateManager.h"
int main() {
	Fl_Window * window = new Fl_Window(800, 550, "Robbie Robot Shop");
	window->color(785150208);
	StateManager *state = new StateManager(window);
}
