#ifndef HOMEWORK5_STATEMANAGER_H
#define HOMEWORK5_STATEMANAGER_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>

Fl_Menu_Item items[] = {
    { "&File", 0, 0, 0, FL_SUBMENU },
        { "&New", FL_ALT + 'n', (Fl_Callback *) NULL },
        { "&Open", FL_ALT + 'o', (Fl_Callback *) NULL },
        { "&Save", FL_ALT + 's', (Fl_Callback *) NULL },
        { "&Save", FL_ALT + FL_SHIFT + 'n', (Fl_Callback *) NULL },
        { "&Quit", FL_ALT + 'q', (Fl_Callback *) NULL },
        {0},
    {0}
};

class StateManager {
private:
    Fl_Window * win;
    Fl_Menu_Bar * menu;

    StateManager();
    void showWindow();

public:
    static StateManager& getInstance() {
        static StateManager gInstance;
        return gInstance;
    }
};

#endif
