#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_.h>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Group.h>
#include <FL/Fl_Tabs.h>
#include <FL/Fl_Button.h>
#include <FL/Fl_Input.h>
#include <FL/Fl_Text_Display.h>
#include <FL/Fl_Multiline_Output.h>
#include <FL/Fl_PNG_Image.h>
#include "Factory/RobotFactory.h"

enum State {
	WELCOME
};

class StateManager
{
private:
	State curState;
	Fl_Window * win;
	Fl_Menu_Bar * menu;
	Fl_Tabs *tabs;
	bool catalogIsClicked;

	void createWelcome();
	void createMenuBar();
	void createTabs();
	void render();

public:
	StateManager(Fl_Window * window) : curState(WELCOME), win(window) {
		this->createMenuBar();
		this->createTabs();
		this->win->end();
		this->win->show();

		Fl::run();
	};

	void changeState(State state);

	void createMenu() {};

	static void update(void* ptr);
};
