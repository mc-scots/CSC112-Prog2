#include <iostream>
#include <unistd.h>
#include "fracas.h"
#include "alpaca.h"
#include "alpacaFracasPack.h"
#include "termmanip.h"

#define DELAY 500000
#define FRACAS_LINE 13

using namespace std;

Fracas::Fracas(AlpacaFracasPack *p1, AlpacaFracasPack *p2) 
{
    //load the packs!
    this->p1 = p1;
    this->p2 = p2;
}
    

//run the fracas and return the winner!  
AlpacaFracasPack *
Fracas::go()
{
    Alpaca *a1;
    Alpaca *a2;
    AlpacaFracasPack *winner;
    
    //unload the first two combatiants
    a1=p1->unload();
    a2=p2->unload();
    cout << cursorPosition(1, FRACAS_LINE+1);
    
    //let the fracas commence!
    while(a1 != NULL and a2 != NULL) {
        clearStatusArea();
        printAlpaca(1, p1, a1); 
        printAlpaca(41, p2, a2);
        cout.flush();
        usleep(DELAY);
        
        //a1 goes first
        a1->performRound(a2);
        //update the display
        clearStatusArea();
        printAlpaca(1, p1, a1); 
        printAlpaca(41, p2, a2);
        cout.flush();
        if(a2->getHp() <= 0 || a2->getPower() == 0) {
            cout << a2->name() << " dies." << endl;
            a2 = p2->unload();
            if(a2==NULL) continue;
            cout << a2->name() << " comes out." << endl;
        }
       
        
        //a2 goes second
        a2->performRound(a1);
        //update the display
        clearStatusArea();
        printAlpaca(1, p1, a1); 
        printAlpaca(41, p2, a2);
        cout.flush();
        if(a1->getHp() <= 0 || a1->getPower()==0) {
            cout << a1->name() << " dies." << endl;
            a1 = p1->unload();
            if(a1==NULL) continue;
            cout << a1->name() << " comes out." << endl;
        }
    }
   
    //detect the winner
    if(a1!=NULL) {
        winner = p1;
    } else {
        winner = p2;
    }
    
    //print the winner
    cout << cursorPosition(30, FRACAS_LINE-3) << "** " << winner->name() << " wins! **";
    cout.flush();
    sleep(5);
    
    return winner;
}
    

//display the alpaca at the given x coordinate
void 
Fracas::printAlpaca(int x, AlpacaFracasPack *p, Alpaca *a)
{
    int y=1;
    
    cout << saveCursor;
    
    //print the pack information
    cout << cursorPosition(x,y) << p->name() << "  " << p->packSize() << " remaining alpacas";
    y+=2;
    
    
    //print the alpaca information in a nice pack-like way
    cout << cursorPosition(x, y) << a->name();
    y++;
    cout << cursorPosition(x+2,y) << "HP: " << cursorPosition(x+12, y) << a->getHp();
    y++;
    cout << cursorPosition(x+2,y) << "Power: " << cursorPosition(x+12, y) << a->getPower();
    y++;
    cout << cursorPosition(x+2,y) << "Attack: " << cursorPosition(x+12, y) << a->getAttack();
    y++;
    cout << cursorPosition(x+2, y) << "Defense: " << cursorPosition(x+12, y) << a->getDefense();
    y++;
    cout << cursorPosition(x+2, y) << "Status: " << cursorPosition(x+12, y);
    switch(a->getStatus()) {
    case NONE:
            cout << "Normal";
            break;
    case ASLEEP:
            cout << "Asleep";
            break;
    case STUNNED:
            cout << "Stunned";
            break;
    }
    
    cout << restoreCursor;
}


void
Fracas::clearStatusArea()
{
    cout << saveCursor;
    //clear the top FRACAS_LINE lines
    for(int i=1; i<=FRACAS_LINE; i++) {
        cout << cursorPosition(1,i) << clearLine;
    }
    cout << restoreCursor;
}