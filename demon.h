/*
    Jared Yu
    CS 110B
    12/3/2017
    Prof. Harden
    Assignment 15b
    demon.h

    The demon class is a class which is a child to the Creature class.
    This demon is like other characters, except it is an example of hierarchy
    which comes from inheritance. demon inherits characteristics from Creature,
    which in turn are passed down to Balrog and Cyberdemon. It has two constructors
    for a default object of the demon class. The demon then will sometimes
    call member functions which are inherited from Creature. The demon class also
    allows for an object to have values for damage, and is also able to recognize
    that it's species is that of a demon.

demon();
    post: calling object demon which has default strength 10 and default hitpoints 10.

demon(int newStrength, int newHitpoints);
    post: calling object is equal to a demon with strength newStrength
            and hitpoints = newHitpoints.

int getDamage();
    post: a function which derives from both demon and Creature. This function determines
            the damage that demon will do. This value is pre-determined using random functions
            that allow for variability along with formulas that will specify the type of damage
            that a Creature is capable of. Due to inheritance, this will be called from the
            main, then the parent class demon, and finally the derived demon class.

string getSpecies() const;
    post: this function will return the type of species that the object is. In the Creature class,
            the class will ask for the species by using getSpecies, and demon will respond by stating
            that it is a 'demon.'
*/

#ifndef DEMON_H
#define DEMON_H
#include "Creature.h"
#include <string>
namespace cs_creature {

class demon : public Creature
{
    public:
        demon();
        demon(int newStrength, int newHitpoints);
        int getDamage();
        string getSpecies() const;

};
}

#endif // DEMON_H
