#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

#include "srcmain.h"
#include "fileio.h"
#include "cypher.h"


// Implementation of ProcessCommandArgs
int ProcessCommandArgs(int argc, const char* argv[])
{
	// Interactive mode
	if (argc == 1)
	{
		// Not used for this assignment	
	}

	// Command line testing mode
	else if (argc == 4)
	{
		// Then input[0] is the type of encryption / decryption to do
		std::string edType(argv[0]);
        
		// input[1] is the input file name
		std::string inputFileName(argv[1]);

		// input[2] is the output file name
		std::string outputFileName(argv[2]);
                
        std::vector<std::string> inputData;
        std::vector<std::string> outputData;
        
        getData(inputFileName, inputData);
                
        std::string encryptedAlphabet = inputData[0];
        //add cypher into the vector of strings that will appear on output file
        outputData.push_back(encryptedAlphabet);
        
        //loop through vector from getData
        for (int i = 1; i < inputData.size(); i++) {
            std::string outputText = "";
            if(edType == ESUB) {
                substitutionCypherEncrypt(encryptedAlphabet, inputData[i], outputText);
            }
            else if(edType == DSUB) {
                substitutionCypherDecrypt(encryptedAlphabet, inputData[i], outputText);
            }
            outputData.push_back(outputText);
        }
        putData(outputFileName, outputData);
	}
	return 0;
}
