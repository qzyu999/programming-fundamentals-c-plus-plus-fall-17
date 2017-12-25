/*
    Jared Yu
    CS 110B
    12/3/2017
    Prof. Harden
    Assignment 15b
    Creature.cpp

    CLASS INVARIANT:

    This is the base class for all derived classes for this program. The
    Creature class is used as the default object from which other derived
    objects have their default values stemming from. Therefore it will generate
    objects with strength and hitpoints equal to 10 by default. It will also
    always return the default species of 'Human' for getSpecies.
*/

#include "Creature.h"
#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;
namespace cs_creature {
    // Constructors

    Creature::Creature(){
        strength = 10;
        hitpoints = 10;
    }






    Creature::Creature(int newStrength, int newHitpoints){
        strength = newStrength;
        hitpoints = newHitpoints;
    }






    // Mutators

    void Creature::setStrength(int newStrength){
        strength = newStrength;
    }






    void Creature::setHitpoints(int newHitpoints){
        hitpoints = newHitpoints;
    }






    // Accessors

    int Creature::getStrength(){
        return strength;
    }






    int Creature::getHitpoints(){
        return hitpoints;
    }






    /*
        post: this function determines the base damage that all inherited class objects will do
                when they call getDamage(). Due to the order of base functions displaying their values
                first, this function makes sure that all derived objects have some basic damage ability.
                this function is a virtual function, and is an example of polymorphism in this program.
                The getDamage() is called from the derived classes, but never actually used for a Creature
                object. However, since the getDamage() for Creature is used by derived classes, it is not
                quite a pure virtual function.
        algorithm: damage is determined randomly between 1 and the strength of the Creature object. This
                    value is then displayed through cout, where the species of the object that is calling
                    this function will be displayed. The actual damage is also returned.
    */

    int Creature::getDamage(){
        int damage;
        damage = (rand() % strength) + 1;

        cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;

        return damage;
    }






    string Creature::getSpecies() const {
        return "Human";
    }
}
