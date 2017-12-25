/*
    Jared Yu
    CS 110B
    12/3/2017
    Prof. Harden
    Assignment 15b
    Creature.h

    The Creature class is a class which is a base class to all the derived classes.
    This Creature is like other characters, except it is an example of hierarchy
    which comes from inheritance. Creature passes on characteristics from itself,
    so all other derived objects can have traits of a Creature. The Creature class
    also has the ability to determine the strength and hitpoints beyond just using
    values determined with a Constructor. It also has the ability to get these values
    that are related to private data members strength and hitpoints. This class also
    utilizes virtual and pure virtual functions so that derived classes can properly
    use their member functions along side the member functions of this base class.

Creature();
    post: calling object Creature which has default strength 10 and default hitpoints 10.

Creature(int newStrength, int newHitpoints);
    post: calling object is equal to a Creature with strength newStrength
            and hitpoints = newHitpoints.

void setStrength(int newStrength);
    post: this function will set the strength according to int newStrength. This is another
            way to determine the strength of an object apart from the Constructor values.

void setHitpoints(int newHitpoints);
    post: this function will set the hitpoints according to int newHitpoints. This is another
            way to determine the hitpoints of an object apart from the Constructor values.

virtual int getDamage();
    post: this function determines the base damage that all inherited class objects will do
            when they call getDamage(). Due to the order of base functions displaying their values
            first, this function makes sure that all derived objects have some basic damage ability.
            This function is a virtual function, and is an example of polymorphism in this program.
            The getDamage() is called from the derived classes, but never actually used for a Creature
            object. However, since the getDamage() for Creature is used by derived classes, it is not
            quite a pure virtual function.

virtual string getSpecies() const = 0;
    post: this function is a pure virtual function. It is this way because the getSpecies() is called
            from the derived classes, however getSpecies is never used for Creature. Therefore it
            makes the function into a pure virtual function, and so the class is an abstract class.
*/

#ifndef CREATURE_H
#define CREATURE_H
#include <string>
using namespace std;
namespace cs_creature {
    class Creature
    {
        public:
            Creature();
            Creature(int newStrength, int newHitpoints);
            void setStrength(int newStrength);
            void setHitpoints(int newHitpoints);
            int getStrength();
            int getHitpoints();
            virtual int getDamage();
            virtual string getSpecies() const = 0;
        private:
            int strength;
            int hitpoints;
    };
}
#endif // CREATURE_H
