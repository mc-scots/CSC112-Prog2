/*
 * Implementation of a generic attack alpaca.
 */
#include <cmath>
#include <iostream>
#include <cstdlib>
#include "alpaca.h"

using namespace std;

//a hardened version of log.  Returns 0 in the case of any
//would-be chicanery
static double alpacaLog(double x)
{
    double result;

    //handle 0
    if(x==0) {
        return 0;
    }

    //try to get the log
    result = log(x);

    //any other wierdness will be dealt with
    if(!isnormal(x)) {
        result = 0;
    }

    return result;
}


Alpaca::Alpaca(unsigned int power) {
    this->power = power;

    //set all the defaults
    hp=100;
    attackScore=5;
    defense=0.05;
    myTurn = false;
    status = NONE;
    statusCounter=0;
}


void
Alpaca::attack(Alpaca *opponent, unsigned int p) {
    double damage;

    if(!myTurn) return;

    //limit ourselves to our remaining power
    if(p > power) {
        p = power;
    }

    //we use a O(m lg n) attack rate
    damage = attackScore * alpacaLog(p);

    //opponents can defend according to 
    damage -= (damage * opponent->defense);

    //make it happen, and report it
    cout << "  " << opponent->name()
         << " takes " << damage << " points of damage!" << endl;
    opponent->hp -= damage;

    //we just used some power
    power -= p;

    //you get one action!
    myTurn = false;
}


void
Alpaca::sleep(Alpaca *opponent, unsigned int p) {
    int r;  //number of rounds for the status counter

    if(!myTurn) return;

    //limit ourselves to our remaining power
    if(p > power) {
        p = power;
    }

    //sleep like a alpacaLog.  fnord!
    r = (int) ceil(alpacaLog(p));

    //if the alpaca is currently asleep, we are adding rounds
    if(opponent->status == ASLEEP) {
        r = opponent->statusCounter + r;
    }

    //put the alpaca to sleep
    power-=p;
    opponent->status = ASLEEP;
    opponent->statusCounter = r;
    cout << "  " << opponent->name() << " goes to sleep." << endl;

    //you get one action!
    myTurn = false;
}

void
Alpaca::stun(Alpaca *opponent, unsigned int p) {
    if(!myTurn) return;
    int r;  //number of rounds for the status counter

    if(!myTurn) return;

    //limit ourselves to our remaining power
    if(p > power) {
        p = power;
    }

    //sleep like a alpacaLog.  fnord!
    r = (int) ceil(alpacaLog(2*p));

    //if the alpaca is currently asleep, we are adding rounds
    if(opponent->status == STUNNED) {
        r = opponent->statusCounter + r;
    }

    //put the alpaca to sleep
    opponent->status = STUNNED;
    opponent->statusCounter = r;
    power-=p;
    cout << "  " << opponent->name() << " suffers a mild concussion!" << endl;

    //you get one action!
    myTurn = false;
}


void
Alpaca::decreaseDefense(Alpaca *opponent, unsigned int p) {
    double d;
    if(!myTurn) return;

    //limit ourselves to our remaining power
    if(p > power) {
        p = power;
    }

    //decrease the defense according to the alpacaLog growth rate formula
    d=opponent->defense * 100;
    if(d>1) {
        d-=alpacaLog(d) + alpacaLog(p);
    } else {
        d-=alpacaLog(p);
    }

    //we can't do negative defense
    if(d<0) d = 0;

    //set the defense
    opponent->defense = d/100.0;
    cout << "  " << opponent->name() << "'s defense falls!" << endl;
    power -= p;

    //you get one action!
    myTurn = false;
}

void
Alpaca::decreaseAttack(Alpaca *opponent, unsigned int p) {
    double a;

    if(!myTurn) return;
    //limit ourselves to our remaining power
    if(p > power) {
        p = power;
    }

    //make it happen
    a = opponent->attackScore - alpacaLog(opponent->attackScore) - alpacaLog(p);
    if(a<0) a = 0;
    power -= p;
    opponent->attackScore = a;

    cout << "  " << opponent->name() << "'s attack falls!" << endl;

    //you get one action!
    myTurn = false;

}

void
Alpaca::increaseAttack(unsigned int p) {
    if(!myTurn) return;

    //limit ourselves to our remaining power
    if(p > power) {
        p = power;
    }

    //raise our attack
    attackScore += alpacaLog(attackScore) + alpacaLog(p);
    power-=p;
    cout << "  " << name() << " is getting pumped!" << endl;

    //you get one action!
    myTurn = false;
}

void
Alpaca::increaseDefense(unsigned int p) {
    if(!myTurn) return;

    //limit ourselves to our remaining power
    if(p > power) {
        p = power;
    }

    //raise our defense
    defense *= 100;
    defense += alpacaLog(defense) + alpacaLog(p);
    if(defense >= 100) defense = 99;
    defense /= 100.0;
    power -= p;
    cout << "  " << name() << " looks a little tougher." << endl;

    //you get one action!
    myTurn = false;
}

void
Alpaca::increaseHp(unsigned int p) {
    if(!myTurn) return;

    //limit ourselves to our remaining power
    if(p > power) {
        p = power;
    }

    //increase the hp
    hp += alpacaLog(hp) + alpacaLog(p);
    power-=p;
    cout << "  " << name() << " looks healthier." << endl;

    //you get one action!
    myTurn = false;
}

//perform multi-attack moves  (Each option multiplies the total point
//expendature, so 2 combos cost twice as much as 1 move, 3 cost 3, etc.
//put points into each attack category, 0 if you don't want to use that
void
Alpaca::comboAttack(Alpaca *opponent,
                    unsigned int attackPoints,
                    unsigned int sleepPoints,
                    unsigned int stunPoints,
                    unsigned int decDefensePoints,
                    unsigned int decAttackPoints)
{
    if(!myTurn) return;

    //first, get the multiplier
    int mult=0;
    if(attackPoints) mult++;
    if(sleepPoints) mult++;
    if(stunPoints) mult++;
    if(decDefensePoints) mult++;
    if(decAttackPoints) mult++;

    //if there is no multiplier, return.  Nothing to do!
    if(!mult){ myTurn=false; return; }

    //pay the multi-attack cost
    int sum = attackPoints + sleepPoints + stunPoints + decDefensePoints + decAttackPoints;
    sum -= sum/mult;
    if(sum > power) power = 0; else power-=sum;

    //and perform each action
    if(attackPoints) {
        myTurn=true;
        attack(opponent, attackPoints/mult);
    }

    if(sleepPoints) {
        myTurn = true;
        sleep(opponent, sleepPoints/mult);
    }

    if(stunPoints) {
        myTurn = true;
        stun(opponent, stunPoints/mult);
    }

    if(decDefensePoints) {
        myTurn = true;
        decreaseDefense(opponent, decDefensePoints/mult);
    }

    if(decAttackPoints) {
        myTurn = true;
        decreaseAttack(opponent, decDefensePoints/mult);
    }

    //regardless, our turn ends here!
    myTurn = false;
}



//perform a multi-buf move.  (Each option multiplies the total point
//expendature, so 2 combos cost twice as much as 1 move, and so on.
void
Alpaca::comboBuf(unsigned int incAttackPoints,
                 unsigned int incDefensePoints,
                 unsigned int incHpPoints)
{
    if(!myTurn) return;

    //first work out the multiplier
    int mult = 0;
    if(incAttackPoints) mult++;
    if(incDefensePoints) mult++;
    if(incHpPoints) mult++;

    //if there is no multiplier, we are done
    if(!mult) { myTurn = false; return; }


    //pay the multi-attack cost
    int sum = incAttackPoints + incDefensePoints + incHpPoints;
    sum -= sum/mult;
    if(sum > power) power = 0; else power-=sum;

    //do the buffs
    if(incAttackPoints) {
        myTurn = true;
        increaseAttack(incAttackPoints/mult);
    }

    if(incDefensePoints) {
        myTurn = true;
        increaseDefense(incDefensePoints/mult);
    }

    if(incHpPoints) {
        myTurn = true;
        increaseHp(incHpPoints/mult);
    }
}


//buffs you can apply to allies (or enemies if you are nuts)
//this works like the combo buf function
void
Alpaca::bufAlly(Alpaca *ally,
                unsigned int incAttackPoints,
                unsigned int incDefensePoints,
                unsigned int incHpPoints)
{
    if(!myTurn) return;

    //first work out the multiplier
    int mult;
    if(incAttackPoints) mult++;
    if(incDefensePoints) mult++;
    if(incHpPoints) mult++;

    //if there is no multiplier, we are done
    if(!mult) { myTurn = false; return; }

    //work out the total cost
    int powerCost = (incAttackPoints + incDefensePoints + incHpPoints);

    //transfer the power!
    if(powerCost > power) powerCost = power;
    power -= powerCost;
    ally->power += powerCost;

    //and let the alpaca buf itself
    ally->myTurn = true;
    ally->comboBuf(incAttackPoints, incDefensePoints, incHpPoints);
    ally->myTurn = false;

    myTurn = false;
}


//checks the remaining alpaca power
unsigned int
Alpaca::getPower()
{
    return power;
}


//checks the attack score of the alpaca
double
Alpaca::getAttack()
{
    return attackScore;
}


//checks the defense score of the alpaca
double
Alpaca::getDefense()
{
    return defense;
}


//checks the hp of the alpaca
double
Alpaca::getHp()
{
    return hp;
}

//checks the turn status
bool
Alpaca::isMyTurn()
{
    return myTurn;
}


//checks the alpaca status
alpacaStatus
Alpaca::getStatus()
{
    return status;
}


//checks how long the status will remain in effect
unsigned int
Alpaca::getStatusCounter()
{
    return statusCounter;
}


bool
Alpaca::isAlive() {
  return hp > 0 && power != 0; 
}


/*
 * This function runs the alpaca round.  It starts by beginning the turn
 * and then checks the alpaca status.  If appropriate, it lets an alpaca 
 * act, or it updates statuses.
 */
void
Alpaca::performRound(Alpaca *opponent) {
    myTurn = true;  //it's my turn!

    //act according to the status
    switch(status) {
    case NONE:
        act(opponent);
        break;

    case ASLEEP:
        statusCounter--;  //sleep this round
        if(statusCounter <= 0) {
            status = NONE;
            cout << name() << " woke up!" << endl;
        } else {
            cout << name() << " is asleep." << endl;
        }
        break;

    case STUNNED:
        statusCounter--; //be stunned this round
        if(statusCounter <=0) {
            status = NONE;
            cout << name() << " can move again!" << endl;
        } else {
            cout << name() << " is stunned.  It may not attack." << endl;
            if(rand() % 10 <= 3) act(opponent);
        }
        break;
    }

    //end my turn
    myTurn = false;
}
