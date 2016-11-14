#include "globals.h"

int main() {
	factory = new RobotFactory();
	window = new Fl_Window(800, 600, "Robbie Robot Shop");
	window->color(785150208);
	state = new StateManager(window);
}
