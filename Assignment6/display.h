#ifndef display_h
#define display_h
/* 
	Program......: Assignment 6
	File.........: display.h
	Student......: Michael Rouse 
	Student ID...: 12442296
	Class........: Comp Sci 1570 Section D
	Instructor...: Fletcher
	Date.........: 03/11/2015
	Description..: Contains function prototypes for display functions
*/
#include <iostream>
#include "wavelength.h"

using namespace std;

// Function Prototypes
void displayResults(string sItemName, string sSecondLabel, float fSecondValue, float fWaveLength, string sThirdLabel = "", int iThirdValue = -1);
float getHairIndex();
int getPrecision(const int MIN_PRECISION, const int MAX_PRECISION);
int askYesOrNo(string sPrompt); // Asks the user a yes or no question (return 1 for yes, 0 for no)
int getNumInput(string sPrompt, const int MIN_VALUE, const int MAX_VALUE); // Gets an integer input from the user



#endif