/*
    Jared Yu
    CS 110B
    12/3/2017
    Prof. Harden
    Assignment 15b
    Balrog.cpp

    CLASS INVARIANT:

    Whenever an object of class Balrog is called, it will be made from
    either the default constructor or the constructor which takes in values
    for strength and hitpoints. The class will also return the damage for
    an object which is generated with random values within a formula. The class
    will also always return 'Balrog' when getSpecies is called for a Balrog object.
*/

#include "Balrog.h"
#include "demon.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
namespace cs_creature {
    // Constructors

    Balrog::Balrog() : demon(){
        getStrength();
        getHitpoints();
    }






    Balrog::Balrog(int newStrength, int newHitpoints)
        : demon(newStrength, newHitpoints){
        newStrength = getStrength();
        newHitpoints = getHitpoints();
    }






    // Accessors

    /*
        post: a function which derives from both demon and Creature. This function determines
                the damage that Balrog will do. This value is pre-determined using random functions
                that allow for variability along with formulas that will specify the type of damage
                that a Creature is capable of. Due to inheritance, this will be called from the
                main, then the parent class demon, and finally the derived Balrog class.
        algorithm: the damage is determined by calling getDamage() which comes from the parent class
                    demon. The demon class will also call getDamage() from Creature. Therefore the
                    damage for Balrog stems from the base class Creature and parent class demon before
                    the random number and damage formula for Balrog is used. This therefore creates
                    an attack for Balrog which can possibly do damage from three sources.
    */

    int Balrog::getDamage(){
        int damage;
        damage = demon::getDamage();
        int damage2 = (rand() % demon::getStrength()) + 1;
        damage += damage2;

        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;

        return damage;
    }






    string Balrog::getSpecies() const {
        return "Balrog";
    }
}
