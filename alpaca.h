/*
 * This is the base class for the attack alapcas.  You are not allowed
 * to modify this class, nor are you allowed to attempt to get at the
 * private memory of this class.
 *
 * The idea of this animal is that it can attack others of its kind.
 * The alpaca works by the following points scheme:
 *   Power - This is the number of power points the alpaca has.
 *           Performing actions costs alpaca power points.
 *  
 *   Attack - This modifier determines how much damage the alpaca can
 *            do.  This can be modified, but doing so costs alpaca
 *            power points.
 *   
 *   Defense - This number decreases the damage the alpaca will
 *             absorb.  This number can be increased, which costs
 *             alpaca power points.
 *
 *   HP      - The remaining hitpoints for the alpaca.  If this number
 *             falls below zero, the alpaca loses the battle.
 *
 *   Status  - The alpaca can be in the following states: NORMAL,
 *             ASLEEP, STUNNED. Statuses can be modified by 
 *             attacks, but doing so costs points.
 */
#ifndef ALPACA_H
#define ALPACA_H
#include <string>

enum alpacaStatus {NONE, ASLEEP, STUNNED};

class Fracas;

class Alpaca {
public:
    //the constructor sets the power and the default attack and defense values
    Alpaca(unsigned int power);

    //pure virtual functions (those which makes each alpaca special)
    virtual std::string name()=0;  //returns the alpaca's name
    virtual void act(Alpaca *opponent)=0;  //do the alpaca's actions in a given round

    //alpaca actions.  These are not virtual, and so you cannot override them!
    //(at least, you cannot override them in a way that will matter.)
    void attack(Alpaca *opponent, unsigned int p);  //attack an alpaca's life.  expend p points
    void sleep(Alpaca *opponent, unsigned int p);   //put an alpaca to sleep. expend p points
    void stun(Alpaca *opponent, unsigned int p);    //stun an alpaca to sleep. expend p points
    void decreaseDefense(Alpaca *opponent, unsigned int p);
    void decreaseAttack(Alpaca *opponent, unsigned int p);

    //alpaca buffs you can apply to yourself!
    void increaseAttack(unsigned int p);
    void increaseDefense(unsigned int p);
    void increaseHp(unsigned int p);



    //perform multi-attack moves  (Each option multiplies the total point
    //expendature, so 2 combos cost twice as much as 1 move, 3 cost 3, etc.
    //put points into each attack category, 0 if you don't want to use that
    void comboAttack(Alpaca *opponent,
                     unsigned int attackPoints,
                     unsigned int sleepPoints,
                     unsigned int stunPoints,
                     unsigned int decDefensePoints,
                     unsigned int decAttackPoints);


    //perform a multi-buf move.  (Each option multiplies the total point
    //expendature, so 2 combos cost twice as much as 1 move, and so on.
    void comboBuf(unsigned int incAttackPoints,
                  unsigned int incDefensePoints,
                  unsigned int incHpPoints);


    //buffs you can apply to allies (or enemies if you are nuts)
    //this works like the combo buf function
    void bufAlly(Alpaca *ally,
                 unsigned int incAttackPoints,
                 unsigned int incDefensePoints,
                 unsigned int incHpPoints);

    //checks the remaining Alpaca power
    unsigned int getPower();

    //checks the attack score of the alpaca
    double getAttack();

    //checks the defense score of the alpaca
    double getDefense();

    //checks the hp of the alpaca
    double getHp();

    //checks the turn status
    bool isMyTurn();

    //checks the alpaca status
    alpacaStatus getStatus();

    //checks how long the status will remain in effect
    unsigned int getStatusCounter();

    //checks to see if alpaca is alive or dead
    bool isAlive();
    
private:
    void performRound(Alpaca *opponent);  //runs the alpaca attack round
    friend Fracas;

    unsigned int power;      //power points
    double attackScore;  //attack score
    double defense; //defense score
    double hp;      //hitpoints
    bool myTurn;    //true only during an alpaca's turn
    alpacaStatus status;
    unsigned int statusCounter;
    
    //prevent cheaters!
    Alpaca(const Alpaca& a) { myTurn=false; hp=0; /* death to cheaters */ }
    void operator=(const Alpaca& rhs) { /* nice try */ this->hp=0; }
};
#endif



