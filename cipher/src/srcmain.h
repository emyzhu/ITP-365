#pragma once

#include <string>

// Constants for the different types of cyphers
const std::string ESUB = "esub";    // Encryption with substitution cypher
const std::string DSUB = "dsub";    // Decryption with substitution cypher

// Name: 
//		ProcessCommandArgs
// Input:
//		1. Integer indicating the number of items in argv
//		2. An array of character pointers containing all the command line input
//		NOTE: The first item is ALWAYS the name of the executable 
//		(so it'll be "main" in our case)
// Output: 
//		Integer, 0 = success, anything else indicates an issue
// Side effects: 
//		1. With no command line input, will generate interactive console
//		2. With 3 command line arguments will generate output files
// Summary:
//		Based on command line input, will perform the encryption or decryption indicated
//		When given invoking command ("main") + 0 input:
//			Generates interactive mode where user indicates encrypt / decrypt, then
//			(using a pre-generated cipher) encrypts or decrypts a single line of text
//		When given invoking command ("main") + encrypt/decrypt command (from above constants)
//		+ input file name (as an std::string) + output file name (as an std::string) creates
//		encrypted / decrypted file based on input file
int ProcessCommandArgs(int argc, const char* argv[]);

