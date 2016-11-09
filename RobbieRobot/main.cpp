#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include "StateManager.h"
int main() {
	Fl_Window * window = new Fl_Window(800, 600, "Robbie Robot Shop");
	StateManager *state = new StateManager(window);
}
