#include "fight.h"

bool loadHeroes(const std::string& fileName, std::vector<Hero*>& heroVector)
{
    heroVector.clear();
    
    bool dataSuccess = false;
    std::ifstream fileInput(fileName);
    if (fileInput.is_open()) {
        //until end of function, add each line to the data vector while the file is open
        while (fileInput.eof()!= true) {
            std::string line;
            std::getline(fileInput, line);
            //convert each line (which is a string for now) into a hero and then make the hero into a pointer
            Hero* newHero = new Hero(line);
            heroVector.push_back(newHero);
        }
        fileInput.close();
        dataSuccess = true;
    }
    else {
        std::cout << "Unable to load file \"" << fileName << "\"!" << std::endl;
    }
    return dataSuccess;
}

Hero* selectHero(std::vector<Hero*>& heroVector, const std::string& prompt, std::ostream& out, std::istream& in)
{
    
    //print prompt (so now we can call this function twice once for each of the two different heroes to choose - giving different prompts)
    out << prompt;

    // choice represents the index correspoing to the list of heros shown to user
    int choice;
    in >> choice;
    
    Hero* pointToHero = heroVector[choice];
    
    return pointToHero;
}

void heroCombat(Hero* heroA, Hero* heroB, std::ostream& output)
{
    heroA->resetHealth();
    heroB->resetHealth();

    while( (heroA->getHealth() > 0) && (heroB->getHealth() > 0) ) {
        output << heroA->getName() << " has " << heroA->getHealth() << " health " << std::endl;
        output << heroB->getName() << " has " << heroB->getHealth() << " health " << std::endl;
        
        Power* powerAUsed = heroA->useRandomPower();
        Power* powerBUsed = heroB->useRandomPower();
        
        int outcome = powerAUsed->fight(powerBUsed);
        
        if(outcome == -1) {
            heroA->takeDamage();
        }
        else {
            heroB->takeDamage();
        }
            
        output << "---------------------------------------" << std::endl;
    }
    if(heroA->getHealth() > heroB->getHealth()) {
        output << heroA->getName() << "  WINS!!!" << std::endl;
    }
    else {
        output << heroB->getName() << "  WINS!!!" << std::endl;
    }
}

int fight(const std::string& inputFileName, const std::string& outputFileName, unsigned seed)
{
    std::ifstream  input(inputFileName);
    std::ofstream  output(outputFileName);
    fight(input, output, seed);
    
    return 0;
}

int fight(std::istream& input, std::ostream& output, unsigned seed)
{
    std::srand(seed);
    
    bool isRunning = true;
    std::vector<Hero *> vectorOfHeroes;
    // while loop allows us to exit program when isRunning is false
    while (isRunning == true) {
    
        //need to go to new line and put in alligator - no endl otherwise Travis will count it as wrong
        output << "Choose an option: \n1. Load Heroes \n2. Print Hero Roster \n3. Hero Fight! \n4. Quit\n> ";
        int response = -1;
        input >> response;
        
        //input/heroes.txt
        if (response == 1) {
            std::string fileName;
            output << "Enter the file to load: ";
            input >> fileName;
            loadHeroes(fileName, vectorOfHeroes);
        }
        
        else if(response == 2) {
            output << "The following " << vectorOfHeroes.size() << " heroes are loaded..." << std::endl;
            // bar is printed after name of each leg grows back
            output << "---------------------------------------" << std::endl;
            for(Hero* hero : vectorOfHeroes) {
               output << *hero ;
            }
        }
        
        else if(response == 3) {
            //print list of heroes
            for(int i =0; i < vectorOfHeroes.size(); i++) {
                //access pointer element; referring to individual member of hero class
                output << i << ": " << vectorOfHeroes[i]->getName() << std::endl;
            }
            //creating the heroes
            Hero* playerOne = selectHero(vectorOfHeroes, "Select your first hero: ", output, input);
            Hero* playerTwo = selectHero(vectorOfHeroes, "Select your second hero: ", output, input);
            
            // actual fighting
            heroCombat(playerOne, playerTwo, output);
        }
        
        else if(response == 4) {
            isRunning = false;
        }
        
        else {
            output << "Please enter a valid number." << std::endl;
        }
    }
        
	return 0;
}
