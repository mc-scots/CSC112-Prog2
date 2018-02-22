#ifndef Randalpaca_H
#define Randalpaca_H
#include "alpaca.h"
#include "alpacaFracasPack.h"

class Randalpaca : public Alpaca
{
public:
    //set up the alapca with 100 points
    Randalpaca(const std::string &nickName, AlpacaFracasPack *p) : Alpaca(100), nickName(nickName), pack(p) {}

    //the alpaca's brain!
    virtual std::string name();
    virtual void act(Alpaca *oponent);

    //stuff this alpaca does
    virtual void kick(Alpaca *opponent);
    virtual void hypnotize(Alpaca *opponent);
    virtual void headbutt(Alpaca *opponent);
    virtual void spit(Alpaca *opponent);
    virtual void mock(Alpaca *opponent);
    virtual void concentrate();
    virtual void dazzle(Alpaca *opponent);
    virtual void compassionatize(Alpaca *buddy);
    virtual void selfSooth();

protected:
    std::string nickName;
    AlpacaFracasPack *pack;
};

#endif
