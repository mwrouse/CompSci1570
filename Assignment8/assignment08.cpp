/* 
	Program......: Assignment 08
	File.........: assignment08.cpp
	Student......: Michael Rouse 
	Student ID...: 12442296
	Class........: Comp Sci 1570 Section D
	Instructor...: Fletcher
	Date.........: 04/06/2015
	Description..: Run Tests to see if DNA matches a body
*/
#include "general.h"
#include "tests.h"

// Prototypes
void welcome();

int main()
{	
	// Variables
	bovine missingCows[NUMBER_OF_MISSING_COWS];
	bovine deadCows[NUMBER_OF_DEAD_COWS];
	
	randomize();
	
	// Generate the cows
	cowBirth(missingCows, NUMBER_OF_MISSING_COWS);
	cowBirth(deadCows, NUMBER_OF_DEAD_COWS, true);
	
	// Welcome the user 
	welcome();
	
	// Perform tests on the dead cows against the recorded cows
	performTests(deadCows, missingCows);
	
	cout << "\n\nThank you for using the MIlkanizer 3000, have a nice day! :) \n\n";
	
	return 0;
}


void welcome()
{
	cout << "======================================\n";
	cout << "    Welcome to the Milkanizer 3000    \n";
	cout << "         By: Michael Rouse            \n";
	cout << "======================================\n\n";
	
	return;
}