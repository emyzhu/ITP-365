#pragma once
#include <string>
#include <vector>
#include <ostream>

#include "powers.h"

class Hero
{
public:
    // Name:
    //        Hero parameterized constructor
    // Input:
    //        1. A string (passed as constant reference) with 3 fields.
    //              a. The hero name followed by a vertical bar "|"
    //              b. A list of comma separated power names followed by a vertical bar "|"
    //              c. The maximum health for that hero
    // Output:
    //        None (it's a constructor)
    // Side effects:
    //        Dynamically creates new powers and puts their memory addresses in the Power vector
    // Summary:
    //        
	Hero(const std::string& heroDef);

    // Name:
    //        getName
    // Input:
    //        None
    // Output:
    //        A std::string with the hero's name
    // Side effects:
    //        None
    // Summary:
    //        Name getter
	std::string getName();
    
    // Name:
    //      useRandomPower
    // Input:
    //      None
    // Output:
    //      A pointer to a random Power as determined by std::rand
    // Side effects:
    //      Displays the hero's name and that power's flavor text to COUT
    // Summary:
    //      Power is randomly chosen from the vector of powers
    //      COUT should be... mName " " powerText
    //      For example, mName = "Nate the Great", powerText = "swings his mighty hammer!"
    //      COUT will display "Nate the Great swings his mighty hammer!"
	Power* useRandomPower();

	// Name:
    //        getHealth
    // Input:
    //        None
    // Output:
    //        An int with the hero's current health
    // Side effects:
    //        None
    // Summary:
    //        Health getter
	int getHealth();

	// Name:
    //        getHealth
    // Input:
    //        None
    // Output:
    //        An int with the hero's current health
    // Side effects:
    //        None
    // Summary:
	//        Causes the hero to take one point of damage
	void takeDamage();


	// Name:
	//        getHealth
	// Input:
	//        None
	// Output:
	//        An int with the hero's current health
	// Side effects:
	//        None
	// Summary:
	//        Resets the heroes' health to the max value
	void resetHealth();

	// Name: 
    //		Stream operator <<
    // Input:
    //		Standard for stream operator overload (stream and object)
    // Output: 
    //		Standard for stream overload (modified stream)
    // Side effects: 
    //		Displays the hero's name and a list of their powers
    // Summary:
    //		Hero's name is listed, then each power (moved in 1 tab)
	friend std::ostream& operator<<(std::ostream& out, const Hero& h);

private:
	// Hero's maximum health
	int mMaxHealth;

	// Current health
	int mHealth;
	
    // Name of hero
	std::string mName;
	
    // Vector of pointers to powers
	std::vector<Power*> mPowers;
};
