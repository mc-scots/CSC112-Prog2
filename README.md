![Attack Alpaca by Lydia Harrison, who is also the originator of
the attack alpaca concept](images/Alpaca.jpg
"Attack Alpaca by Lydia Harrison, who is also the originator of the attack alpaca concept")


Farmer George comes from a long line of alpaca farmers. They have raised
alpacas for generations, peacefully shearing them for their valuable
fibers. But then, one day, George became very bored with his life, and
he thought it would be more fun to try to make these majestic
pseudo-ruminants fight to the death.

Soon, other alpaca farmers began to follow suit. Packs of attack alpacas
were soon fighting in alpaca fracases the whole world over. It was a
glorious, if not disturbing, sight. Unfortunately, actual alpaca blood
sports are illegal, immoral, and extremely wasteful. So, instead, we are
going to write a program to simulate the sport, so that we may partake
of the blood-lust without harming any actual alpacas.

## The Rules of Alpaca Fracas

An alpaca fracas works by loading packs of attack alpacas into alpaca
attack chutes, and then letting them fight each other. The order of
events are:

1.  A pack of alpacas is chosen and loaded into the attack chutes.
2.  The chutes open and the first alpaca from each pack enters the
    arena.
3.  The two alpacas fight. When one dies, it is replaced by the next one
    in the chute.
4.  The farmer who runs out of alpacas first loses. The other wins.
5.  If all alpacas die, the game ends in a tie.

## Alpaca Mechanics

An alpaca has the following statistics:

  - **Status** - One of NONE, ASLEEP, or STUNNED
      - NONE - This is a healthy alpaca. Fear it.
      - ASLEEP - This is a sleeping alpaca. It will not be able to
        attack for a while.
      - STUNNED - A stunned alpaca will usually not be able to attack,
        but sometimes it can.
  - **HP** - This is the number of remaining hit points for the alpaca.
    If this reaches 0, the alpaca dies.
  - **Power** - This is the amount of fighting power left in the alpaca.
    Attacks expend power points, and once these reach 0 the alpaca dies.
  - **Defense** - This is a percent reduction in damage this alpaca will
    take.
  - **Attack** - This is a modifier which indicates how much damage an
    attack causes.

## Alpaca Attack Actions

An alpaca attack can be one or more of the following actions:

  - Attack the Enemy
  - Stun the Enemy
  - Put the Enemy to Sleep
  - Decrease the Enemy's Defense
  - Decrease the Enemy's Attack
  - Increase your Attack
  - Increase your Defense
  - Increase your HP

## The Alpaca Code
Explore the starter files and look at how the alpaca are implemented. You can go
ahead and build the program by changing into the alpaca directory and
typing:

` make`

Run the alpacaFracas program a few times to get a feel for what it does.

## Your Task

In this programming assignment, we will be implementing an alpaca pack
which acts on its own. To do this, you must do the following:

1.  Implement Alpacas with act functions which carry out the alpaca's
    attack strategy. (See randalpaca.h and randalpaca.cpp for an
    example)
2.  Create a derived AlpacaFracasPack, named FracasPack, which contains
    a no-arg constructor which builds your battle pack. (See randPack.h
    and randPack.cpp for an example)

When you build and run the program, you will be able to kick back and
watch two alpaca packs battle to the death\!

### Namespace Requirements

Because everyone's pack is going to be named FrackasPack, you must
create your own namespace. (Eventually these will all be compiled into a
master fracas tournament\!).

Your namespaces should be named as follows: first initial last name. For
instance, mine would be 'rlowe'. All classes and functions you create
should be part of this namespace.

Note that the namespace for the random alpaca fracas pack is randPack.
Look at how this is done in the random alpaca files. There's really not
much to it.

### Testing

Test your attack alpaca fracas pack by changing main.cpp so that one of
the packs is yours. I would recommend trying out being both pack 1 and
pack 2. In the tournament this choice will be made randomly, so be able
to win while going second\!

### Tournament

The alpaca tournament will take place on March 9th. All of the alpaca
packs will fight it out, and there will be one winner. The first second
and third place winners will receive points and prizes\!

Your strategy should be coded into your alpaca's act functions as well
as the makeup of your pack.

Good Luck\!
