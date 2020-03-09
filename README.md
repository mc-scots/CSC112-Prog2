## Introduction

In this programming assignment, we are going to explore a classic in
Computer Science\! This is Conway's Game of of life. It will be a good
practice for using vectors, as well as making use of FLTK for
graphics and animation.

Conway's game of life was created by John Conway, a British
mathematician, some time in the 1970's. It was an example of a problem
first proposed by John Von Neumann (creator of the famous computer
architecture). Von Neumann's problem was in the study of
self-replicating machines. This proposal led Conway to create this
little game, which is one of the first examples of a field called
cellular automata (CA).

The basic idea of a CA is to use a simple set of rules to create a very
complex pattern. Don't be fooled by the easiness of understanding the
rules. Conway's game of life, when played on an infinite grid, is
capable of simulating a Turing machine. This means that the simple rules
we are about to look at are capable of universal computation. In fact,
randomly generated rule sets have a fairly high probability of being
capable of universal computation. Maybe the universe is geared toward
forming computers\!

## The Game of Life

Conway's game of life is played on an orthogonal grid. Each element in
the grid is a cell, and the cell is either alive or dead. Each grid
arrangement is used to generate the next "generation" of cells. The fate
of each cell is determined by it's neighbors. Take for instance, the
cell 0. The X's are it's neighbors:

`XXX`  
`X0X`  
`XXX`

So each cell has 8 neighboring cells. The number of living neighbors
surrounding a cell are what determines what the cell does in the next
generation. The rules that the game follows are:

1.  A living cell with fewer than 2 living neighbors dies. (Starvation)
2.  A living cell with more than 3 living neighbors dies. (Overcrowding)
3.  A living cell with 2 or 3 living neighbors lives on. (Stability)
4.  A dead cell with exactly 3 living neighbors will become a live cell
    (Reproduction)

So you can see that counting the cells around each cell, plus that
cell's state, determines what the cell does. Generally, this results in
weird and wonderful patterns. There are some patterns that are
interesting, however. Take for instance:

`   `
`***`
`   `

Following those rules, there are two possible iterations which this
oscillates through.

`   `
`***`
`   `
Followed by:

` * `  
` * `  
` * `

Then:

`   `
`***`
`   `
And so on. This is called a spinner. The next interesting one is the
glider. Use a sheet of paper and checkout what the glider does:

` * `  
`  *`  
`***`  
`   `

The glider moves\! How cool is that?

There are some other interesting shapes, and a few are included with the
assignment Director. That way you can run them through your own
programs.

So now, we want to program this thing\!

What follows is a specification of the program as well as some ideas to
get you started.

## Programming the Game of Life

Our program will be called "life". It will be an FLTK application with
the following appearance:

![life.png](images/life.png)

The buttons in this program perform the following actions:

* Clear - Sets all cells to black (dead)
* Random - Randomize the grid, setting some to life some to dead
* Go - Start the simulation.  The button will display "Stop" while the simulation is running
* Stop - Stop the simulation, display "Go"
* Load - Load a file into the grid
* Save - Save the current grid to a file

In addition to this, when we click on the cells, we toggle them
between living and dead.  So we can draw a new grid to try out, or we
can modify one that is in process.

The file format used by the program is very simple.  A space is in the
file in the position of a dead cell, and an asterisk is in the
position of a living cell.

Be sure to test your program with random grids, hand drawn grids, and
the files included in your directory.

  - spinner
  - glider
  - gosper-gun

The grid itself uses a 10x10 square for each cell.  Black is used for
dead cells and green is used for living cells.  The grid itself is
640x480 pixels making for a grid of 64x48 cells.

## Some Tips
  - I made a backend model of the cells consisiting of a grid class.
  - I made a count neighbors function
  - My grid class contains an update function which does the following

<!-- end list -->

    1.  Update the living status of each cell. (Which entity does this
        is a tricky point of concern\!)
    2.  Count the living neighbors of each cell and notify the cell of
        the living status.

<!-- end list -->

The biggest tip is this. Asking yourself the right questions is the most
important thing you can do. Try designing first and then coding, and
then identify additional questions that come up. Keep that conversation
between yourself and your code going, and you can write any program I
throw at you\!

Also, talk to each other. Talk to rubber ducks (that's a real method).
Draw pictures on windows with crayon. Do whatever you have to do to
tease out all of the detail and enjoy and savor the complexity that you
create.

## Notes

Handwritten notes are important\! Here are the ones I drew up before
writing even one line of code:

![LifeNotes.jpg](images/LifeNotes.jpg)
