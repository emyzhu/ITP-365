#include "cypher.h"
#include <iostream>


// Encrypts 2nd input
void substitutionCypherEncrypt(const std::string& cypher, const std::string& input, std::string& output)
{
    char outputChar;
    //loop thru each letter in the input
    for (int i = 0; i < input.length(); i++) {
        //letter in question
        char inputChar = input[i];
        //position of character in regular alphabet
        int cypherPosition;
        std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        //find position of decrypted letter in regular alphabet
        for (int j = 0; j < alpha.length(); j++) {
            if (toupper(inputChar) == cypher[j]) {
                cypherPosition = j;
            }
        }
        //alphaPosition will be the index you use to grab the letter from the cypher
        //this is a capital letter
        if(inputChar >= 'A' && inputChar <= 'Z') {
            outputChar = toupper(alpha[cypherPosition]);
        }
        // this is a lowercase letter
        else if(inputChar >= 'a' && inputChar <= 'z') {
            outputChar = tolower(alpha[cypherPosition]);
        }
        // it's something else. just stick in at end when we go to puch back
        else {
            outputChar = inputChar;
        }
        output.push_back(outputChar);
    }
}

// Decrypts 2nd input
void substitutionCypherDecrypt(const std::string& cypher, const std::string& input, std::string& output)
{
    char outputChar;
    //loop thru each letter in the input
    for (int i = 0; i < input.length(); i++) {
        //letter in question
        char inputChar = input[i];
        //position of character in regular alphabet
        int alphaPosition;
        std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        //find position of encrypted letter in regular alphabet
        for (int j = 0; j < alpha.length(); j++) {
            if (toupper(inputChar) == alpha[j]) {
                alphaPosition = j;
            }
        }
        //alphaPosition will be the index you use to grab the letter from the cypher
        //this is a capital letter
        if(inputChar >= 'A' && inputChar <= 'Z') {
            outputChar = toupper(cypher[alphaPosition]);
        }
        // this is a lowercase letter
        else if(inputChar >= 'a' && inputChar <= 'z') {
            outputChar = tolower(cypher[alphaPosition]);
        }
        // it's something else. just stick in at end when we go to puch back
        else {
            outputChar = inputChar;
        }
        output.push_back(outputChar);
    }
}
