#include <cstdlib>
#include <iostream>
#include "randalpaca.h"

using namespace std;

std::string 
Randalpaca::name() {
    return nickName;
}


void 
Randalpaca::act(Alpaca *opponent) {
    //make a random move.  Does Randal feel lucky?  Well does he punk?
    switch(rand()%8) {
        case 0:
            kick(opponent);
            break;

        case 1:
            hypnotize(opponent);
            break;

        case 2:
            headbutt(opponent);
            break;

        case 3:
            spit(opponent);
            break;

        case 4:
            mock(opponent);
            break;

        case 5:
            concentrate();
            break;

        case 6:
            dazzle(opponent);
            break;

        case 7:
            if(pack->packSize()) {
                compassionatize((*pack)[0]);
            } else {
                selfSooth();
            }
            break;
    }
}

//our moves
void
Randalpaca::kick(Alpaca *opponent) {
    cout << name() << " uses kick." << endl;
    attack(opponent, 10);
}

void
Randalpaca::hypnotize(Alpaca *opponent) {
    cout << name() << " uses hypnotize." << endl;
    sleep(opponent, 10);
}

void
Randalpaca::headbutt(Alpaca *opponent) {
    cout << name() << " uses headbutt." << endl;
    stun(opponent, 10);
}


void
Randalpaca::spit(Alpaca *opponent) {
    cout << name() << " spits!" << endl;
    decreaseDefense(opponent, 10);
}


void
Randalpaca::mock(Alpaca *opponent) {
    cout << name() << " says mocking things." << endl;
    decreaseAttack(opponent, 10);
}


void
Randalpaca::concentrate() {
    cout << name() << " contemplates the art of war." << endl;
    increaseAttack(10);
}


void 
Randalpaca::dazzle(Alpaca *opponent)
{
    cout << name() << " throws a flashbang hairball." << endl;
    comboAttack(opponent, 20, 0, 20, 0, 0);
}

void 
Randalpaca::compassionatize(Alpaca *buddy)
{
    cout << name() << " spreads the love." << endl;
    bufAlly(buddy, 0, 20, 20);
}


void
Randalpaca::selfSooth()
{
    cout << name() << " licks his own wounds." << endl;
    comboBuf(0, 20, 20);
}
