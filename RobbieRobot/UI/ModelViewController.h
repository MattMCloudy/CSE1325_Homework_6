#ifndef MODELVIEWCONTROLLER_H
#define MODELVIEWCONTROLLER_H


#include <string>
#include <iostream>
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
#include <FL/Fl_Choice.h>
#include "../Factory/RobotFactory.h"
#include "../Robot/Robot.h"


#define CREAM 4294964992

class ModelViewController { 
	private:
			static RobotFactory* factory;
			static string name;
			static Head* head;
			static Torso* torso;
			static Arm* arm;
			static Leg* leg;
			static Locomotor* loco;
			static Battery** batt;
			static int bat_count;
	public:
			ModelViewController(RobotFactory* fact);
			void createModelWindow();
			static void headChoiceCB(Fl_Widget* w, void* ptr);
			
			static void headButtonCB(Fl_Widget* w, void* ptr);
			static void torsoButtonCB(Fl_Widget* w, void* ptr);
			static void armButtonCB(Fl_Widget* w, void* ptr);
			static void legButtonCB(Fl_Widget* w, void* ptr);
			static void locoButtonCB(Fl_Widget* w, void* ptr);
			static void batteryButtonCB(Fl_Widget* w, void* ptr);

			static void nameInputCB(Fl_Widget* w, void* ptr);
			static void headInputCB(Fl_Widget* w, void* ptr);
			static void torsoInputCB(Fl_Widget* w, void* ptr);
			static void armInputCB(Fl_Widget* w, void* ptr); 
			static void legInputCB(Fl_Widget* w, void* ptr);
			static void locoInputCB(Fl_Widget* w, void* ptr);
			static void batteryInputCB(Fl_Widget* w, void* ptr);

			static void makeModelCB(Fl_Widget* w, void* ptr);
};

#endif
