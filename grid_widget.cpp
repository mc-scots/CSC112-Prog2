// File: grid_widget.cpp
// Purpose: This is the implementation file of the Gride_Widdget class.
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "grid_widget.h"

//constructor
Grid_Widget::Grid_Widget(int x, int y, int w, int h, const char *l) :
    Fl_Box(x, y, w, h, l)  /* box consturctor delegation */
{
    _cell = nullptr;   //start with an empty set of cells

    //set the default cell size
    cell_size(DEFAULT_CELL_SIZE);
}


//destructor
Grid_Widget::~Grid_Widget()
{
    //delete the cells
    delete [] _cell[0];

    //delete the row pointers
    delete [] _cell;
}


//Return the number of rows
int Grid_Widget::rows() const
{
    return _rows;
}


//Return the number of columns
int Grid_Widget::cols() const
{
    return _cols;
}


//Return the size of each cell (they are square)
int Grid_Widget::cell_size()
{
    return _cell_size;
}


//Set the size of each cell (they are square)
void Grid_Widget::cell_size(int size)
{
    //calculate rows and columns
    int rows = h() / size;
    int cols = w() / size;

    //allocate the cell row pointers and cells
    Fl_Color **cell = new Fl_Color* [rows];
    cell[0] = new Fl_Color[rows * cols];

    //link up all the row pointers
    for(int i=1; i<rows; i++) {
        cell[i] = cell[i-1] + cols;
    }

    //set all the grid elements to black
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cell[i][j] = FL_BLACK;
        }
    }

    //if there are existing cells, copy them now
    if(_cell) {
        for(int i=0; i<_rows and i<rows; i++) {
            for(int j=0; j<_cols and j<cols; j++) {
                cell[i][j] = this->_cell[i][j];
            }
        }

        //remove the old ones
        delete _cell[0];
        delete _cell;
    }

    //set the member variables
    _rows = rows;
    _cols = cols;
    _cell_size = size;
    _cell = cell;
    redraw();
}


//Return reference to the color of the selected cell at row r column c
Fl_Color & Grid_Widget::cell(int r, int c)
{
    // The reference may result in a change, 
    //  so let's mark ourselves for redrawing.
    redraw();

    return _cell[r][c];
}


//Draw the grid
void Grid_Widget::draw()
{
    //render each cell
    for(int r = 0; r < _rows; r++) {
        for(int c = 0; c < _cols; c++) {
            fl_draw_box( FL_FLAT_BOX, 
                         x() + c * _cell_size,
                         y() + r * _cell_size,
                         _cell_size,
                         _cell_size,
                         _cell[r][c] );
        }
    }
}


//Handle event
int Grid_Widget::handle(int event)
{
    //process mouse clicks
    if(event == FL_PUSH || event == FL_DRAG) {
        //compute the row and column of the click
        int r = (Fl::event_y()-y()) / _cell_size;
        int c = (Fl::event_x()-x()) / _cell_size;
        
        //run our callback and indicate that we handled the event.
        if(r < rows() and c < cols()) {
            do_callback(this, &_cell[r][c]);
        }
        return 1;
    }

    //we did not handle the event
    return 0;
}
