#pragma once

#include <string>

// Name: 
//		substitutionCypherEncrypt
// Input:
//		1. A string (passed as constant reference) contining the cipher
//		2. A string (passed as constant reference) containing the text to encrypt
//		3. A string (passed by reference) that will eventually contain the encrypted text
// Output: 
//		None
// Side effects: 
//		None
// Summary:
//		Uses the inputted cipher to encrypt the inputted clear-text
//		Results go into 3rd argument
void substitutionCypherEncrypt(const std::string& cypher, const std::string& input, std::string& output);

// Name: 
//		substitutionCypherDecrypt
// Input:
//		1. A string (passed as constant reference) contining the cipher
//		2. A string (passed as constant reference) containing the text to decrypt
//		3. A string (passed by reference) that will eventually contain the decrypt text
// Output: 
//		None
// Side effects: 
//		None
// Summary:
//		Uses the inputted cipher to decrypted the inputted cipher-text
//		Results go into 3rd argument
void substitutionCypherDecrypt(const std::string& cypher, const std::string& input, std::string& output);
