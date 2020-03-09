// File: grid_widget.h
// Purpose: This is a widget that provides a grid of pixels.  The
//          pixels scale themselves to be the size of the widget
//          itself.
// 
//          It also provides a pixel click event, and the ability to
//          read the color state of each pixel.
#ifndef GRID_WIDGET_H
#define GRID_WIDGET_H
#include <FL/Fl_Box.H>

const int DEFAULT_CELL_SIZE=10;

class Grid_Widget : public Fl_Box
{
public:
    //constructor
    Grid_Widget(int x, int y, int w, int h, const char *l=0);

    //destructor
    ~Grid_Widget();

    //Return the number of rows
    int rows() const;

    //Return the number of columns
    int cols() const;

    //Return the size of each cell (they are square)
    int cell_size();

    //Set the size of each cell (they are square)
    void cell_size(int size);

    //Return reference to the color of the selected cell at row r column c
    Fl_Color &cell(int r, int c);

    //Draw the grid
    virtual void draw();

    //Handle event
    virtual int handle(int event);

private:
    int _rows;          //Number of rows
    int _cols;          //Number of columns
    int _cell_size;     //The size of each cell
    Fl_Color **_cell;   //The actual cell colors
};

#endif
