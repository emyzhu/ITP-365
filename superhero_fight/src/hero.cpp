#include "hero.h"
#include "strlib.h"
#include <iostream>

Hero::Hero(const std::string& heroDef)
{
    std::vector<std::string> heroCharacteristics =  strSplit(heroDef, '|');
    
    mName = heroCharacteristics[0];
    
    // splits the string of powers which are separated by a comma
    std::string strPowers = heroCharacteristics[1];
    std::vector<std::string> listOfPowers = strSplit(strPowers, ',');
    std::vector<Power*> heroPowers;

    for(int i = 0; i < listOfPowers.size(); i++) {
        Power* aPower = powerFactory(listOfPowers[i]);
        heroPowers.push_back(aPower);
    }
    mPowers = heroPowers;
    
    std::string strHealth = heroCharacteristics[2];
    mHealth = mMaxHealth = std::stoi(strHealth);

}

//getter typical of what you'd see in other languages
std::string Hero::getName()
{
    std::string heroName = mName;
	return heroName;
}

// gerneates a random number, which serves as an index amongst the list of powers specific to that hero
Power* Hero::useRandomPower()
{
    int randIndex = rand() % mPowers.size();
    Power* randPower = mPowers[randIndex];
    
    std::string randPowDescription = randPower->use();
    std::cout << mName << randPowDescription << std::endl;
    
	return randPower;
}

int Hero::getHealth()
{
	return mHealth;
}

void Hero::takeDamage()
{
    mHealth = mHealth - 1;
}

void Hero::resetHealth()
{
    mHealth = mMaxHealth;
}

std::ostream& operator<<(std::ostream& out, const Hero& h)
{
    out << h.mName << " has the following powers..." << std::endl;
    out << "---------------------------------------" << std::endl;
    for(int i = 0; i < h.mPowers.size(); i++) {
        std::cout << "\t" << *h.mPowers[i] << std::endl;
    }
	return out;
}
