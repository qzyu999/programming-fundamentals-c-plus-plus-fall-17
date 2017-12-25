/*
    Jared Yu
    CS 110B
    12/3/2017
    Prof. Harden
    Assignment 15b
    Cyberdemon.cpp

    CLASS INVARIANT:

    Whenever an object of class Cyberdemon is called, it will be made from
    either the default constructor or the constructor which takes in values
    for strength and hitpoints. The class will also always return 'Cyberdemon'
    when getSpecies is called for a Cyberdemon object.
*/

#include "Cyberdemon.h"
#include "demon.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
namespace cs_creature {
    // Constructors

    Cyberdemon::Cyberdemon() : demon(){
        getStrength();
        getHitpoints();
    }






    Cyberdemon::Cyberdemon(int newStrength, int newHitpoints)
        : demon(newStrength, newHitpoints){
        newStrength = getStrength();
        newHitpoints = getHitpoints();
    }






    // Accessors
    string Cyberdemon::getSpecies() const {
        return "Cyberdemon";
    }
}
