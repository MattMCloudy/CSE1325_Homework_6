#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include "StateManager.h"
#include "Factory/RobotFactory.h"

Fl_Window * window;
StateManager * state;
RobotFactory * factory;

#endif
