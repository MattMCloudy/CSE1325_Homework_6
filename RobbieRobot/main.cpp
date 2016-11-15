#include "MainViewController.h"

int main() {
	Fl_Window* window = new Fl_Window(800, 600, "Robbie Robot Shop");
	window->color(785150208);
	MainViewController* controller = new MainViewController(window);
}
