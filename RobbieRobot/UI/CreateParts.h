#ifndef CREATE_PARTS_H_
#define CREATE_PARTS_H_

#include <string>
#include <iostream>
#include <vector>
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
#include "../Factory/RobotFactory.h"
#include "../Part/Head.h"
#include "../Part/Torso.h"
#include "../Part/Arm.h"
#include "../Part/Leg.h"
#include "../Part/Battery.h"
#include "../Part/Locomotor.h"
#include "../Part/Part.h"

#define CREAM 4294964992


class PartViewController {
	private:
			static RobotFactory* factory;
			static Fl_Window* partsWindow;
			static Fl_Tabs* tabs;

	public:
			PartViewController(RobotFactory* fact);
			void createPartsWindow();
			static void headPartCB(Fl_Widget* w, void* ptr);
			static void armPartCB(Fl_Widget* w, void* ptr);
			static void legPartCB(Fl_Widget* w, void* ptr);
			static void torsoPartCB(Fl_Widget* w, void* ptr);
			static void batteryPartCB(Fl_Widget* w, void* ptr);
			static void locomotorPartCB(Fl_Widget* w, void* ptr);
};

	Fl_Button* button = (Fl_Button*) w;
	button->color(FL_BLUE);
#endif
