/*
    Jared Yu
    CS 110B
    12/3/2017
    Prof. Harden
    Assignment 15b
    Cyberdemon.h

    The Cyberdemon class is a class which is a child to the demon class.
    This demon is like other characters, except it is an example of hierarchy
    which comes from inheritance. Cyberdemon inherits characteristics from demon,
    which in turn inherits characteristics from Creature. It has two constructors
    for a default object of the Cyberdemon class. The Cyberdemon then will sometimes
    call member functions which are inherited not from demon, but demon's
    parent which is Creature. The Cyberdemon class also allows for an object
    to have values for damage, and is also able to recognize that it's species
    is that of a Cyberdemon.

Cyberdemon();
    post: calling object Cyberdemon which has default strength 10 and default hitpoints 10.

Cyberdemon(int newStrength, int newHitpoints);
    post: calling object is equal to a Cyberdemon with strength newStrength
            and hitpoints = newHitpoints.

string getSpecies() const;
    post: this function will return the type of species that the object is. In the Creature class,
            the class will ask for the species by using getSpecies, and Cyberdemon will respond by stating
            that it is a 'Cyberdemon.'
*/

#ifndef CYBERDEMON_H
#define CYBERDEMON_H
#include "demon.h"
#include <string>
namespace cs_creature {

class Cyberdemon : public demon
{
    public:
        Cyberdemon();
        Cyberdemon(int newStrength, int newHitpoints);
        string getSpecies() const;
};
}

#endif // CYBERDEMON_H
