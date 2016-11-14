#include "CreateParts.h"

void createPartsWindow() {
    partsWindow = new Fl_Window(400, 600, "Create Parts");

    partsWindow->end();
    partsWindow->show();
}
