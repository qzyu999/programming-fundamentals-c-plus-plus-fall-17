/*
    Jared Yu
    CS 110B
    12/3/2017
    Prof. Harden
    Assignment 15b
    Human.cpp

    CLASS INVARIANT:

    Whenever an object of class Human is called, it will be made from
    either the default constructor or the constructor which takes in values
    for strength and hitpoints. The class will also always return 'Human'
    when getSpecies is called for a Human object.
*/

#include "Human.h"
#include "Creature.h"
#include <iostream>

using namespace std;
namespace cs_creature {
    // Constructors

    Human::Human() : Creature(){
        getStrength();
        getHitpoints();
    }






    Human::Human(int newStrength, int newHitpoints)
        : Creature(newStrength, newHitpoints){
        newStrength = getStrength();
        newHitpoints = getHitpoints();
    }






    // Accessors

    string Human::getSpecies() const {
        return "Human";
    }
}
