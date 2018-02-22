#include "randalpaca.h"
#include "randPack.h"
#include "alpaca.h"
#include <sstream>

static int packNum = 0;


randPack::FracasPack::FracasPack()
{
    std::ostringstream os;
   
    //give the packa a unique name
    os << "Random Pack " << packNum++;
    packName=os.str();
  
    //pack up 6 randals!
    for(int i=0; i<6; i++) {
        //name and load a randal
        os.str("");  //reset 
        os << "Randal #" << packNum-1 << "-" << i;
        load(new Randalpaca(os.str(), this));
    }
}


std::string 
randPack::FracasPack::name()
{
    return packName;
}