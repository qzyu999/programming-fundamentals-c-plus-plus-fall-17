/*
    Jared Yu
    CS 110B
    12/3/2017
    Prof. Harden
    Assignment 15b
    Human.h

    The Human class is a class which is a child to the Creature class.
    This Human is an example of hierarchy which comes from inheritance. Human
    inherits inherits characteristics from Creature. It has two constructors
    for a default object of the Human class. The Human then will sometimes
    call member functions which are inherited from Creature. The Human class
    is also able to recognize that it's species is that of a Human.

Human();
    post: calling object Human which has default strength 10 and default hitpoints 10.

Human(int newStrength, int newHitpoints);
    post: calling object is equal to a Human with strength newStrength
            and hitpoints = newHitpoints.

string getSpecies() const;
    post: this function will return the type of species that the object is. In the Creature class,
            the class will ask for the species by using getSpecies, and Human will respond by stating
            that it is a 'Human.'
*/

#ifndef HUMAN_H
#define HUMAN_H
#include "Creature.h"
#include <string>
namespace cs_creature {

class Human : public Creature
{
    public:
        Human();
        Human(int newStrength, int newHitpoints);
        string getSpecies() const;
};
}
#endif // HUMAN_H
