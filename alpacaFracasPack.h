/*
 * File: alpacaFracasPack.h
 * Purpose: This is a class for containing a pack of attack alapacas who will be
 *          fighting to the death in an alpaca fracas.
 */
#ifndef ALPACAFRACASPACK_H
#define ALPACAFRACASPACK_H
#include <vector>
#include "alpaca.h"
#define MAX_POINTS 600
#define MAX_ALPACAS 15

class AlpacaFracasPack 
{
public:
    AlpacaFracasPack();
    ~AlpacaFracasPack();
    
    //returns the name of the pack
    virtual std::string name()=0;
    
    //Removes the first alpaca from the pack and returns it.  Returns null if there is no alpaca 
    Alpaca *unload();
    
    //Adds an alpaca to the pack returns true on success and false if this alpaca would push 
    //the points limit over the max points ormax alpacas
    bool load(Alpaca *a);
    
    //returns the number of remaining alpacas
    int packSize();
    
    //returns the number of remaining power points in the pack
    unsigned int power();
    
    //returns the power points at the time of pack creation 
    unsigned int originalPower();
    
    //allows access to the alpacas in the pack note that this does not return by reference.
    //you cannot change the alpacas around!
    Alpaca * operator[](unsigned int i);
    
private:
    std::vector<Alpaca*> alpacaList;
    unsigned int packPower;
};

#endif