#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include "callbacks.h"

enum State {
	WELCOME
};

class StateManager
{
private:
	State curState;
	Fl_Window * win;
	Fl_Menu_Bar * menu;

	void createWelcome();
	void createMenuBar();
	void render();
	void changeState(State state);

public:
	StateManager(Fl_Window * window) : curState(WELCOME), win(window) {
		this->createMenuBar();

		this->win->end();
		this->win->show();

		Fl::run();
	};
};

