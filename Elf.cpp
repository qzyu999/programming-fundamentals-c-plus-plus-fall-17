/*
    Jared Yu
    CS 110B
    12/3/2017
    Prof. Harden
    Assignment 15b
    Elf.cpp

    CLASS INVARIANT:

    Whenever an object of class Elf is called, it will be made from
    either the default constructor or the constructor which takes in values
    for strength and hitpoints. The class will also return the damage for
    an object which is generated with random values within a formula. The class
    will also always return 'Elf' when getSpecies is called for a Elf object.
*/

#include "Elf.h"
#include "Creature.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
namespace cs_creature {
    // Constructors

    Elf::Elf() : Creature(){
        getStrength();
        getHitpoints();
    }






    Elf::Elf(int newStrength, int newHitpoints)
        : Creature(newStrength, newHitpoints){
        newStrength = getStrength();
        newHitpoints = getHitpoints();
    }






    // Accessors

    /*
        post: this function determines the damage that an Elf object will do. It uses
                random values included into a damage formula which outputs the damage
                that the derived object will be doing. Due to inheritance, this will
                come after the damage that is done from the Creature's getDamage() will
                be doing.
        algorithm: the function will call the getDamage() from the Creature class, and
                    then implement a damage formula which includes a random value. The
                    result is output using cout, and a value is returned as an integer.
    */

    int Elf::getDamage(){
        int damage;
        damage = Creature::getDamage();

        if ((rand() % 2) == 0) {
            cout << "Magical attack inflicts " << damage
                << " additional damage points!" << endl;
        }
        return damage *= 2;
    }






    string Elf::getSpecies() const {
        return "Elf";
    }
}
