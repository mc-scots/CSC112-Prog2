// File: grid_test.cpp
// Purpose: Test the grid widget
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include "grid_widget.h"


void grid_callback(Grid_Widget *widget, Fl_Color *cell)
{
    *cell = FL_WHITE;
    widget->redraw();
}

int main(int argc, char ** argv)
{
    //create the window, grid, and callback
    Fl_Window *window = new Fl_Window(640, 480);
    Grid_Widget *grid = new Grid_Widget(0, 0, 640, 480);
    grid->callback((Fl_Callback*) grid_callback);

    //end the window and show it
    window->end();
    window->show(argc, argv);

    //run the event loop
    return Fl::run();
}
