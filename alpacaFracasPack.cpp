#include "alpacaFracasPack.h"

AlpacaFracasPack::AlpacaFracasPack()
{
   packPower = 0; 
}


AlpacaFracasPack::~AlpacaFracasPack()
{
    //delete all the alpacas!
    for(auto itr=alpacaList.begin(); itr != alpacaList.end(); itr++) {
        delete *itr;
    }
}

    
//Removes the first alpaca from the pack and returns it.  Returns null if there is no alpaca 
Alpaca *
AlpacaFracasPack::unload()
{
    Alpaca *result;
    
    //handle empty lists
    if(alpacaList.size() == 0) return NULL;
    
    //ok, we have an alpaca!
    result = alpacaList[0];
    alpacaList.erase(alpacaList.begin());
    
    return result;
}

    
//Adds an alpaca to the pack returns true on success and false if this alpaca would push 
//the points limit over the max points ormax alpacas
bool 
AlpacaFracasPack::load(Alpaca *a)
{
    //check legality
    if(packPower + a->getPower() > MAX_POINTS) {
        return false;
    } 
    
    //welcome to the fold!
    packPower += a->getPower();
    alpacaList.push_back(a);
    return true;
}
    
//returns the number of remaining alpacas
int 
AlpacaFracasPack::packSize()
{
    return alpacaList.size();
}
    

//returns the number of remaining power points in the pack
unsigned int 
AlpacaFracasPack::power()
{
    unsigned int result=0;
    
    for(auto itr=alpacaList.begin(); itr!=alpacaList.end(); itr++) {
        result += (*itr)->getPower();
    }
    
    return result;
}
    

//returns the power points at the time of pack creation 
unsigned int 
AlpacaFracasPack::originalPower()
{
    return packPower;
}


//allows access to the alpacas in the pack note that this does not return by reference.
//you cannot change the alpacas around!
Alpaca * 
AlpacaFracasPack::operator[](unsigned int i)
{
    //handle the possibility of an invalid index
    if(i < alpacaList.size()) {
        return alpacaList[i];
    }
    
    //if we make it here, the index was invalid
    return NULL;
}
 