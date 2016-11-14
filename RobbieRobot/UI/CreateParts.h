#ifndef CREATE_PARTS_H_
#define CREATE_PARTS_H_

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

#define CREAM 4294964992

static Fl_Window * partsWindow;
static Fl_Tabs * tabs;

void createPartsWindow();

#endif
