/*
    Jared Yu
    CS 110B
    12/3/2017
    Prof. Harden
    Assignment 15b
    Elf.h

    The Elf class is a class which is a child to the Creature class.
    This Elf is an example of hierarchy which comes from inheritance. Elf
    inherits inherits characteristics from Creature. It has two constructors
    for a default object of the Elf class. The Elf then will sometimes
    call member functions which are inherited from Creature. The Elf class
    also allows for an object to have values for damage, and is also able to
    recognize that it's species is that of a Elf.

Elf();
    post: calling object Elf which has default strength 10 and default hitpoints 10.

Elf(int newStrength, int newHitpoints);
    post: calling object is equal to a Elf with strength newStrength
            and hitpoints = newHitpoints.

int getDamage();
    post: a function which derives from Creature. This function determines
            the damage that Elf will do. This value is pre-determined using random functions
            that allow for variability along with formulas that will specify the type of damage
            that a Creature is capable of. Due to inheritance, this will be called from the
            main, then the parent class demon, and finally the derived Elf class.

string getSpecies() const;
    post: this function will return the type of species that the object is. In the Creature class,
            the class will ask for the species by using getSpecies, and Elf will respond by stating
            that it is a 'Elf.'
*/

#ifndef ELF_H
#define ELF_H
#include "Creature.h"
#include <string>
namespace cs_creature {

class Elf : public Creature
{
    public:
        Elf();
        Elf(int newStrength, int newHitpoints);
        int getDamage();
        string getSpecies() const;

};
}
#endif // ELF_H
