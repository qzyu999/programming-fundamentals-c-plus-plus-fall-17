/*
    Jared Yu
    CS 110B
    12/3/2017
    Prof. Harden
    Assignment 15b
    Balrog.h

    The Balrog class is a class which is a child to the demon class.
    This demon is like other characters, except it is an example of hierarchy
    which comes from inheritance. Balrog inherits characteristics from demon,
    which in turn inherits characteristics from Creature. It has two constructors
    for a default object of the Balrog class. The Balrog then will sometimes
    call member functions which are inherited not from demon, but demon's
    parent which is Creature. The Balrog class also allows for an object
    to have values for damage, and is also able to recognize that it's species
    is that of a Balrog.

Balrog();
    post: calling object Balrog which has default strength 10 and default hitpoints 10.

Balrog(int newStrength, int newHitpoints);
    post: calling object is equal to a Balrog with strength newStrength
            and hitpoints = newHitpoints.

int getDamage();
    post: a function which derives from both demon and Creature. This function determines
            the damage that Balrog will do. This value is pre-determined using random functions
            that allow for variability along with formulas that will specify the type of damage
            that a Creature is capable of. Due to inheritance, this will be called from the
            main, then the parent class demon, and finally the derived Balrog class.

string getSpecies() const;
    post: this function will return the type of species that the object is. In the Creature class,
            the class will ask for the species by using getSpecies, and Balrog will respond by stating
            that it is a 'Balrog.'
*/

#ifndef BALROG_H
#define BALROG_H
#include "demon.h"
#include <string>
namespace cs_creature {

class Balrog : public demon
{
    public:
        Balrog();
        Balrog(int newStrength, int newHitpoints);
        int getDamage();
        string getSpecies() const;
};
}

#endif // BALROG_H
