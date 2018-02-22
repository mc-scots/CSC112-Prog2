/* This is a class which performs an alpaca fracas.
   Give it two packs, call go, and let the bloodbath begin! */
#ifndef FRACAS_H
#define FRACAS_H
#include "alpacaFracasPack.h"

class Fracas 
{
public:
    Fracas(AlpacaFracasPack *p1, AlpacaFracasPack *p2);
    
    //run the fracas and return the winner!  
    AlpacaFracasPack *go();
    
private:
    void printAlpaca(int x, AlpacaFracasPack *p, Alpaca *a);
    void clearStatusArea();
    AlpacaFracasPack *p1;
    AlpacaFracasPack *p2;
};
#endif