#include "powers.h"
#include <iostream>
#include <string>
#include <vector>

POWER_ID Power::getID()
{
    POWER_ID POWER_STRENGTH = mPowerID;
	return POWER_STRENGTH;
}

//overloading the << operator so whenever it's called when there's a power in question, then a description for the power will show up on the console
std::ostream& operator<<(std::ostream& out, const Power& p)
{
    out << p.mDescription;
	return out;
}
StrengthPower::StrengthPower() {
    mDescription = "Superhuman strength";
    mPowerID = POWER_STRENGTH;
}
std::string StrengthPower::use() {
    std::string display = " SMASH!!";
    return display;
}
int StrengthPower::fight(Power *other) {
    int outcome;
    //because other is actually a pointer to a power, we must dereference the pointer when we get the ID of the power
    POWER_ID otherPowerID = other->getID();
    // or operator is used for each power in the case that the main power loses to the other power
    if(otherPowerID == POWER_FLIGHT || otherPowerID == POWER_INTEL) {
        if(otherPowerID == POWER_FLIGHT) {
            std::cout << "FLIGHT WINS - Your fists of fury can't stop them from flying away." << std::endl;
        }
        else {
            std::cout << "INTELLIGENCE WINS - Can't do much against the thinking man." << std::endl;
        }
        outcome = -1;
    }
    // compares power IDs to see which powers are being used. if they're the same, then it's a tie.
    else if(otherPowerID == mPowerID) {
        std::cout << "TIE - You beat each other into unconsciousness." << std::endl;
        outcome = 0;
    }
    else {
        std::cout << "STRENGTH WINS - You smashed them into pieces." << std::endl;
        outcome = 1;
    }
    return outcome;
}

// same three functions but for five more powers
FlightPower::FlightPower() {
    mDescription = "Ability to fly";
    mPowerID = POWER_FLIGHT;
}
std::string FlightPower::use() {
    std::string display = " flies away, maybe far from this place.";
    return display;
}
int FlightPower::fight(Power *other) {
    int outcome;
    POWER_ID otherPowerID = other->getID();
    if(otherPowerID == POWER_LASER || otherPowerID == POWER_GADGETS) {
        if(otherPowerID == POWER_LASER) {
            std::cout << "LASER WINS - They have a good sniper shot so flying doesn't help." << std::endl;
        }
        else {
            std::cout << "GADGETS WINS - Takes a gadget to the face." << std::endl;
        }
        outcome = -1;
    }
    else if(otherPowerID == mPowerID) {
        std::cout << "TIE - You both fly far away." << std::endl;
        outcome = 0;
    }
    else {
        std::cout << "FLIGHT WINS - You flew far away." << std::endl;
        outcome = 1;
    }
    return outcome;
}


LaserPower::LaserPower() {
    mDescription = "Can shoot lasers";
    mPowerID = POWER_LASER;
}
std::string LaserPower::use() {
    std::string display = " shoots lasers from their eyes. PEWPEWPEW!!!";
    return display;
}
int LaserPower::fight(Power *other) {
    int outcome;
    POWER_ID otherPowerID = other->getID();
    if(otherPowerID == POWER_GADGETS || otherPowerID == POWER_STRENGTH) {
        if(otherPowerID == POWER_STRENGTH) {
            std::cout << "STRENGTH WINS - Laser beams can't melt steel fists." << std::endl;
        }
        else {
            std::cout << "GADGETS WINS - Takes a gadget to the face." << std::endl;
        }
        outcome = -1;
    }
    else if(otherPowerID == mPowerID) {
        std::cout << "TIE - You both have the same type of laser." << std::endl;
        outcome = 0;
    }
    else {
        std::cout << "LASER WINS - Your beams burned a hole through them." << std::endl;
        outcome = 1;
    }
    return outcome;
}

IntelPower::IntelPower() {
    mDescription = "Superhuman Intelligence";
    mPowerID = POWER_INTEL;
}

std::string IntelPower::use() {
    std::string display = " ponders deeply.";
    return display;
}
int IntelPower::fight(Power *other) {
    int outcome;
    POWER_ID otherPowerID = other->getID();
    if(otherPowerID == POWER_FLIGHT || otherPowerID == POWER_LASER) {
        if(otherPowerID == POWER_FLIGHT) {
            std::cout << "FLIGHT WINS - Thinking isn't effective when your brains are getting smashed." << std::endl;
        }
        else {
            std::cout << "LASER WINS - It's hard to think when being fried by a laser." << std::endl;
        }
        outcome = -1;
    }
    else if(otherPowerID == mPowerID) {
        std::cout << "TIE - Like chess, this fight ends in a stalemate because no one can be outwitted." << std::endl;
        outcome = 0;
    }
    else {
        std::cout << "INTELLIGENCE WINS -  Can't do much against the thinking man." << std::endl;
        outcome = 1;
    }
    return outcome;
}

GadgetPower::GadgetPower() {
    mDescription = "Uses some crazy gadgets";
    mPowerID = POWER_GADGETS;
}
std::string GadgetPower::use() {
    std::string display = " uses what's (hopefully) the right tool for the job...";
    return display;
}
int GadgetPower::fight(Power *other) {
    int outcome;
    POWER_ID otherPowerID = other->getID();
    if(otherPowerID == POWER_INTEL || otherPowerID == POWER_STRENGTH) {
        if(otherPowerID == POWER_INTEL) {
            std::cout << "INTELLIGENCE WINS - Your toys have been outwitted." << std::endl;
        }
        else {
            std::cout << "STRENGTH WINS - The gadget gets SMASHED." << std::endl;
        }
        outcome = -1;
    }
    else if(otherPowerID == mPowerID) {
        std::cout << "TIE - You two must have the same tools or something." << std::endl;
        outcome = 0;
    }
    else {
        std::cout << "GADGET WINS -  Go go gadget." << std::endl;
        outcome = 1;
    }
    return outcome;
}

NationalPower::NationalPower() {
    mDescription = "A strong belief in their mother country.";
    mPowerID = POWER_NATIONAL;
}
std::string NationalPower::use() {
    std::string display = " screams AMERICA F*** YEAH!!";
    return display;
}
int NationalPower::fight(Power *other) {
    int outcome;
    POWER_ID otherPowerID = other->getID();
    if(otherPowerID != mPowerID) {
        std::cout << "NATIONALISM LOSES - only love for your country won't win any battles." << std::endl;
        outcome = -1;
    }
    else {
        std::cout << "TIE - You both love America so much that you guys become brother in arms." << std::endl;
        outcome = 0;
    }
    return outcome;
}

Power* powerFactory(const std::string& powerName)
{
    // program sees if name passed through matches with anything. if it does, then the appropriate power is assigned
    Power* choosePower;
    if(powerName == "strength") {
        choosePower = new StrengthPower();
    }
    if(powerName == "flight") {
        choosePower = new FlightPower();
    }
    if(powerName == "laser") {
        choosePower = new LaserPower();
    }
    if(powerName == "intel") {
        choosePower = new IntelPower();
    }
    if(powerName == "gadget") {
        choosePower = new GadgetPower();
    }
    if(powerName == "national") {
        choosePower = new NationalPower();
    }
	return choosePower;
}

