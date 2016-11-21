#ifndef STATEMANAGER_H_
#define STATEMANAGER_H_

#include <string>
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
#include "UI/CreateParts.h"
#include "UI/ModelViewController.h"
#include "Factory/RobotFactory.h"
#include "Robot/Robot.h"

enum State {
	WELCOME
};

class MainViewController
{
private:
	State curState;
	Fl_Window * win;
	Fl_Menu_Bar * menu;
	Fl_Tabs *tabs;
	bool catalogIsClicked;
	static RobotFactory* factory;

	void createWelcome();
	void createMenuBar();
	void createTabs();
	void render();

public:
	MainViewController(Fl_Window * window) : curState(WELCOME), win(window) {
		factory = new RobotFactory();
		this->createMenuBar();
		this->createTabs();
		this->win->end();
		this->win->show();

		Fl::run();
	};

	void changeState(State state);

	void createMenu() {};

	static void update(void* ptr);
	static void createPartCB(Fl_Widget *w, void* ptr);
	static void createModelCB(Fl_Widget* w, void* ptr);
};

#endif
