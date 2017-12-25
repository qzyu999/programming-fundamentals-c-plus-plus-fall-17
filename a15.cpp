/*
    Jared Yu
    CS 110B
    12/3/2017
    Prof. Harden
    Assignment 15b
    a15.cpp

    This program simulates a game where two different creatures are created using
    inheritance. In the main, two different creature type are initialized, and then
    they are to fight against each other until the other dies. If one of the creature's
    hitpoints is below 0, then the battle will end. The different Creature types are
    Human, Elf, demon, Cyberdemon, and Balrog. The Creature types which are able to
    fight are Human, Elf, Cyberdemon, and Balrog. Both Creature and demon aren't supposed
    to be created as objects. This program shows how inheritance and hierarchy can lead
    to a functional game where data members and member functions can flow from top to
    bottom such that the different classes can function in an environment with each other
    without there being an issue of hierarchy.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Human.h"
#include "Elf.h"
#include "demon.h"
#include "Cyberdemon.h"
#include "Balrog.h"
#include <ctime>

using namespace std;
using namespace cs_creature;

// Prototype
void battleArena(Creature& Creature1, Creature& Creature2);






int main() {
    srand((time(0)));

	Elf e(50,50);
	Balrog b(50,50);;

	// Perform four battles between creatures
	cout << "\nFirst battle: Elf vs. Balrog" << endl;
	battleArena(e, b);

    Human h(100,300);
	Cyberdemon c(150,200);

    cout << "\nSecond battle: Human vs. Cyberdemon" << endl;
	battleArena(h,c);

	Human h2(10,500);
	Balrog b2(25,100);

    cout << "\nThird battle: Human vs. Balrog" << endl;
	battleArena(h2,b2);

	Elf e2(10,60);
	Cyberdemon c2(15,50);

	cout << "\nLast battle: Elf vs. Cyberdemon" << endl;
	battleArena(e2,c2);
}






/*
    This function is called battleArena and accepts two objects in the parameter
    through Creature &Creature1 and Creature& Creature2. These two objects then
    will loop through a single battle where each does damage to the other's
    hitpoints. This happens as long as both of their hitpoints at least 0.
    When this battle ends, the function will output the results by saying
    that there has either been a 'Tie' or a winner along with the remaining
    health left for that Creature.
*/

void battleArena (Creature &Creature1, Creature& Creature2)
{
    while (Creature2.getHitpoints() >= 0 && Creature1.getHitpoints() >= 0)
    {
        Creature1.setHitpoints(Creature1.getHitpoints() - Creature2.getDamage());
        Creature2.setHitpoints(Creature2.getHitpoints() - Creature1.getDamage());
    }

    if (Creature1.getHitpoints() < 0 && Creature2.getHitpoints() < 0)
        cout << "Tie." << endl;

    if (Creature1.getHitpoints() > 0 && Creature2.getHitpoints() < 0)
        cout << "The " << Creature1.getSpecies() << " wins with "
            << Creature1.getHitpoints() << " health points remaining." << endl;

    if (Creature1.getHitpoints() < 0 && Creature2.getHitpoints() > 0)
        cout << "The " << Creature2.getSpecies() << " wins with "
            << Creature2.getHitpoints() << " health points remaining." << endl;
}

/*
    First battle: Elf vs. Balrog
    The Balrog attacks for 9 points!
    Balrog speed attack inflicts 10 additional damage points!
    The Elf attacks for 18 points!
    The Balrog attacks for 34 points!
    Balrog speed attack inflicts 25 additional damage points!
    The Elf attacks for 48 points!
    Magical attack inflicts 48 additional damage points!
    Tie.

    Second battle: Human vs. Cyberdemon
    The Cyberdemon attacks for 27 points!
    Demonic attack inflicts 50 additional damage points!
    The Human attacks for 79 points!
    The Cyberdemon attacks for 42 points!
    The Human attacks for 43 points!
    The Cyberdemon attacks for 136 points!
    The Human attacks for 38 points!
    The Cyberdemon attacks for 76 points!
    The Human attacks for 25 points!
    The Cyberdemon wins with 15 health points remaining.

    Third battle: Human vs. Balrog
    The Balrog attacks for 17 points!
    Balrog speed attack inflicts 19 additional damage points!
    The Human attacks for 2 points!
    The Balrog attacks for 17 points!
    Demonic attack inflicts 50 additional damage points!
    Balrog speed attack inflicts 24 additional damage points!
    The Human attacks for 1 points!
    The Balrog attacks for 4 points!
    Balrog speed attack inflicts 15 additional damage points!
    The Human attacks for 3 points!
    The Balrog attacks for 19 points!
    Balrog speed attack inflicts 7 additional damage points!
    The Human attacks for 4 points!
    The Balrog attacks for 22 points!
    Balrog speed attack inflicts 21 additional damage points!
    The Human attacks for 4 points!
    The Balrog attacks for 2 points!
    Balrog speed attack inflicts 13 additional damage points!
    The Human attacks for 9 points!
    The Balrog attacks for 12 points!
    Balrog speed attack inflicts 22 additional damage points!
    The Human attacks for 5 points!
    The Balrog attacks for 2 points!
    Balrog speed attack inflicts 3 additional damage points!
    The Human attacks for 4 points!
    The Balrog attacks for 21 points!
    Balrog speed attack inflicts 12 additional damage points!
    The Human attacks for 8 points!
    The Balrog attacks for 7 points!
    Balrog speed attack inflicts 12 additional damage points!
    The Human attacks for 6 points!
    The Balrog attacks for 24 points!
    Balrog speed attack inflicts 6 additional damage points!
    The Human attacks for 10 points!
    The Balrog attacks for 5 points!
    Balrog speed attack inflicts 3 additional damage points!
    The Human attacks for 3 points!
    The Balrog attacks for 4 points!
    Demonic attack inflicts 50 additional damage points!
    Balrog speed attack inflicts 2 additional damage points!
    The Human attacks for 4 points!
    The Balrog attacks for 8 points!
    Demonic attack inflicts 50 additional damage points!
    Balrog speed attack inflicts 6 additional damage points!
    The Human attacks for 5 points!
    The Balrog attacks for 14 points!
    Demonic attack inflicts 50 additional damage points!
    Balrog speed attack inflicts 8 additional damage points!
    The Human attacks for 9 points!
    The Balrog wins with 23 health points remaining.

    Last battle: Elf vs. Cyberdemon
    The Cyberdemon attacks for 3 points!
    The Elf attacks for 1 points!
    Magical attack inflicts 1 additional damage points!
    The Cyberdemon attacks for 8 points!
    Demonic attack inflicts 50 additional damage points!
    The Elf attacks for 10 points!
    The Cyberdemon wins with 28 health points remaining.

    Process returned 0 (0x0)   execution time : 0.269 s
    Press any key to continue.
*/
