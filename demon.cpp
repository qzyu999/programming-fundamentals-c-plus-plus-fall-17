/*
    Jared Yu
    CS 110B
    12/3/2017
    Prof. Harden
    Assignment 15b
    demon.cpp

    CLASS INVARIANT:

    The demon class is a parent class to Cyberdemon and Balrog. Therefore
    an actual demon object is never directly called or created. However,
    through inheritance the member functions and data members from Creature
    are inherited through demon, and passed down to Cyberdemon and Balrog.
    It will have default constructors for strength and hitpoints equal to 10
    as well. Also, even though it is never directly called, it will still
    have the ability to output the species as 'demon.'
*/

#include "demon.h"
#include "Creature.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
namespace cs_creature {
    // Constructors

    demon::demon() : Creature(){
        getStrength();
        getHitpoints();
    }






    demon::demon(int newStrength, int newHitpoints)
        : Creature(newStrength, newHitpoints){
        newStrength = getStrength();
        newHitpoints = getHitpoints();
    }






    // Accessors

    /*
        post: This function acts as a parent to Cyberdemon and Balrog, therefore
                when both of them are called, they will first get damage from
                the Creature class, then possible damage from the demon class,
                and finally they will output their damage from their derived classes.
        algorithm: damage is determined by calling the getDamage() function from the
                    Creature class. It is then put through a damage formula that
                    includes random numbers before cout explains the additional
                    attack, along with returning the damage done.
    */

    int demon::getDamage(){
        int damage;
        damage = Creature::getDamage();

        if (rand() % 4 == 0) {
            damage = damage + 50;
            cout << "Demonic attack inflicts 50 additional damage points!" << endl;
        }
        return damage;
    }






    string demon::getSpecies() const {
        return "demon";
    }
}
