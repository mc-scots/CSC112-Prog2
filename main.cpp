// The alpaca arena!
// It goes without saying, you are not allowed to modify anything in this file.
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include "randPack.h"
#include "fracas.h"
#include "alpaca.h"
#include "termmanip.h"


using namespace std;

int main(int argc, char** argv) {
    //Make our two packs
    randPack::FracasPack *p1 = new randPack::FracasPack();
    randPack::FracasPack *p2 = new randPack::FracasPack();
   
    //seed the random number generator
    srand(time(0));
    
    //Create the fracas
    Fracas *f = new Fracas(p1, p2);
    
    
    //run the fracas!
    cout << clearScreen << cursorOff << cursorPosition(1,1);
    cout.flush();
    f->go();
    cout << cursorOn;
    cout.flush();
    
    
    return 0;
}
