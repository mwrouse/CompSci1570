/* 
	Program......: Assignment 06
	File.........: display.cpp
	Student......: Michael Rouse 
	Student ID...: 12442296
	Class........: Comp Sci 1570 Section D
	Instructor...: Fletcher
	Date.........: 03/11/2015
	Description..: Contains functions for display results, getting input, etc.
*/
#include "display.h"


/*
	Name.........: Display Results
	Author.......: Michael Rouse
	Syntax.......: displayResults(sItemName, sSecondLabel, fSecondValue, fWaveLength[, sThirdLabel, iThirdValue]);
	Parameters...: string sItemName - The label for the Item 
								 string sSecondLabel - Label for the second item in the results 
								 float fSecondValue - The value of the second item 
								 float fWaveLength - The wavelength value (will be turned into int) 
								 
								 string sThirdLabel - label for third item (optional; default is an empty string)
								 int iThirdValue - The value for the third item (optional; default is -1)
	Return.......: N/A
	Description..: Displays the results with multiple options
*/
void displayResults(string sItemName, string sSecondLabel, float fSecondValue, float fWaveLength, string sThirdLabel, int iThirdValue)
{
	cout << "\n======== RESULTS ========\n\n";
	cout << " Item........: " << sItemName << "\n";
	cout << " " << sSecondLabel << ": " << fSecondValue << "\n";
	
	if (sThirdLabel != "" && iThirdValue != -1)
		cout << " " << sThirdLabel << ": " << iThirdValue << "\n";	
	
	cout << " Wavelength..: " << static_cast<int>(fWaveLength) << " nm\n";
	cout << "\n=========================\n\n";
	
	return;
}

/*
	Name.........: Get Hair Index
	Author.......: Michael Rouse
	Syntax.......: getHairIndex();
	Return.......: float fHairIndex - The hair index for the color the user picked
	Description..: Gets the hair index from the user and returns it as a float
*/
float getHairIndex()
{
	// Constants
	const float BLONDE_HAIR = 1.2;
	const float BROWN_HAIR = 1.3;
	const float BLACK_HAIR = 1.7;
	
	// Variables
	int iUserInput;
	float fHairIndex;
	
	// Display hair color options
	cout << "\nHair Colors:\n"
			 << "\t1 - Blonde\n"
			 << "\t2 - Brown\n"
			 << "\t3 - Black\n\n";
	
	// Get user input
	iUserInput = getNumInput("Choose a hair color", 1, 3);
	
	switch (iUserInput)
	{
		// Blonde Hair
		case 1:
			fHairIndex = BLONDE_HAIR;
			break;
		
		// Brown Hair 
		case 2:
			fHairIndex = BROWN_HAIR;
			break;
			
		// Black Hair 
		case 3:
			fHairIndex = BLACK_HAIR;
			break;
	}
	
	return fHairIndex;
}

/*
	Name.........: Get Precision
	Author.......: Michael Rouse
	Syntax.......: getPrecision(MIN_PRECISION, MAX_PRECISION);
	Parameters...: const int MIN_PRECISION - the minimum value the user is allowed to input 
								 const int MAX_PRECISION - the maximum value the user is allowed to input 
	Return.......: int iPrecision - the value that the user input 
	Description..: Gets user input for the precision and returns the value
*/
int getPrecision(const int MIN_PRECISION, const int MAX_PRECISION)
{
	// Variables
	int iPrecision;
	
	// Get Precision 
	iPrecision = getNumInput("Enter Precision", MIN_PRECISION, MAX_PRECISION);
	
	return iPrecision;
}

/*
	Name.........: Ask Yes or No
	Author.......: Michael Rouse
	Syntax.......: askYesOrNo(sPrompt);
	Parameters...: string sPrompt - Prompt for the user 
	Return.......: int iResult - 1 for Yes, 0 for No
	Description..: Will get user input and return a 1 and 0 for yes and no.
*/
int askYesOrNo(string sPrompt)
{
	// Variables 
	int iResult;
	int bValid = false;
	char cUserInput;
	
	// Loop until answer is valid 
	do
	{
		// Prompt 
		cout << sPrompt << " (Y/N)? ";
		cin >> cUserInput;
		
		switch (cUserInput)
		{
			// Yes (Y or y)
			case 'y':
			case 'Y':
				iResult = 1;
				bValid = true;
				
				break;
			
			// No (N or n)
			case 'n':
			case 'N':
				iResult = 0;
				bValid = true;
				
				break;			
		}
	} while (!bValid); // Loop until input is y,Y,n, or N
	
	return iResult;
}

/*
	Name.........: Get Number input
	Author.......: Michael Rouse
	Syntax.......: getNumInput(sPrompt, MIN_VALUE, MAX_VALUE);
	Parameters...: string sPrompt - The prompt for the user 
								 const int MIN_VALUE - Minumum value the user can input 
								 const int MAX_VALUE - Maximum value the user can input 
	Return.......: int iUserInput - the valid user input 
	Description..: Gets a integer number within a certain range from the user
*/
int getNumInput(string sPrompt, const int MIN_VALUE, const int MAX_VALUE)
{
	// Variables 
	int iUserInput;
	bool bValid = false;
	
	// Loop until iUserInput is within the range
	do
	{
		// Prompt 
		cout << sPrompt << " (" << MIN_VALUE << "-" << MAX_VALUE << "): ";
		cin >> iUserInput;
		
		if (iUserInput >= MIN_VALUE && iUserInput <= MAX_VALUE)
			bValid = true;

	} while (!bValid);
	
	return iUserInput;
}
