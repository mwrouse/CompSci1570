/* 
	Program......: assignment_05.cpp
	Student......: Michael Rouse 
	Student ID...: 12442296
	Class........: Comp Sci 1570 Section D
	Instructor...: Fletcher
	Date.........: 03/04/2015
	Description..: Program to determine Time of Death using functions and menus
*/
#include <iostream>
#include <cmath>

using namespace std;

// Function Prototypes
void vGreeting();
void vSignOff();
char cMainMenu();
int iRigorMortis(float fBodyTemp, bool bVictimIll, bool bCompSci);
int iAlgorMortis(float fBodyTemp);
int iOccularMortis(bool bOccularDiscolor, bool bBulgingEyes);
int iVitPotassiumMortis(float fKConcentration);
int iStomachMortis(int iNumShots);
void vPresentResults(int iTimeOfDeath, int iTolerance);
bool getBool(string sPrompt); 	// Get Boolean Input
float getFloat(string sPrompt); // Get a float from input 
int getInt(string sPrompt); 		// Get integer input from user

int main()
{
	// Declare Constants for Error Tolerance
	const int RIGOR_MORTIS = 3;
	const int ALGOR_MORTIS = 2;
	const int OCCULAR_MORTIS = 5;
	const int POTASSIUM_MORTIS = 4;
	const int STOMACH_MORTIS = 0;
	
	// Declare Variables
	char cUserInput;
	int iErrorTolerance = 0;
	int iTimeOfDeath = 0;
	
	vGreeting(); // Display the greeting
	
	// Loop until the user has chosen to exit
	do
	{	
		// Reset Variables 
		iErrorTolerance = 0;
		iTimeOfDeath = 0;
		
		// Display the menu and get input 
		cUserInput = cMainMenu();
		
		cout << "\n";
		
		// Decide what to do based on input
		switch (cUserInput)
		{
			// Rigor Mortis
			case '1':
				// Set error tolerance
				iErrorTolerance = RIGOR_MORTIS;
				
				// Prompt to answer questions 
				cout << "Please answer these three questions:\n\n";
				
				// Calculate Time of Death while getting boolean and float input 
				iTimeOfDeath = iRigorMortis(getFloat("\tWhat is the body temperature?"), getBool("\tWas the victim ill before death (y/n)?"), getBool("\tWas the victim a Computer Scientist (y/n)?"));
				
				break;

			// Algor Mortis
			case '2':
				// Set error tolerance
				iErrorTolerance = ALGOR_MORTIS;
				
				// Prompt to answer questions 
				cout << "Please answer this question:\n\n";
				
				// Calculate time of death after getting input 
				iTimeOfDeath = iAlgorMortis(getFloat("\tWhat is the body temperature?"));
				
				break;

			// Occular Mortis 
			case '3':
				// Set Error Tolerance
				iErrorTolerance = OCCULAR_MORTIS;
				
				// Prompt to answer questions
				cout << "Please answer these two questions:\n";
				
				// Calculate the time of death also get boolean input for each value (saving variables)
				iTimeOfDeath = iOccularMortis(getBool("\tAre the eyes bulging (y/n)?"), getBool("\tIs there Occular Discoloration (y/n)?"));
				
				break;
				
			// Vitreous Potassium Mortis
			case '4':
				// Set Error Tolerance
				iErrorTolerance = POTASSIUM_MORTIS;
				
				// Prompt to answer question 
				cout << "Please answer this question:\n\n";
				
				// Calculate the time of death after getting input 
				iTimeOfDeath = iVitPotassiumMortis(getFloat("\tWhat is the Potassium Concentration from the eye fluid?"));
				
				break;

			// Stomach Mortis
			case '5':
				// Set error tolerance
				iErrorTolerance = STOMACH_MORTIS;
				
				// Prompt to answer a question 
				cout << "Please answer this question:\n\n";
				
				// Calculate time of death
				iTimeOfDeath = iStomachMortis(getInt("\tHow many shots of whiskey was in the victim's stomach?"));
				
				break;

			// Quit	
			case '6':
				break;
				
			default:
				cout << "\nUnknown menu option!\nPlease try again.\n";
		}
		
		// Display Results
		if (cUserInput != '6')
			vPresentResults(iTimeOfDeath, iErrorTolerance);
				
	}while(cUserInput != '6');

	// Display the sign off message
	vSignOff();
	
	return 0;
}

/* 
	Func Name....: Greeting 
	Syntax.......: vGretting()
	Return.......: N/A
	Description..: Greets the user, that's all...
*/
void vGreeting()
{
	cout << "Welcome to the Time-Of-Death Calculator!\n\nBy Michael Rouse\n";
	
	return;
}

/*
	Func Name....: Sign Off
	Syntax.......: vSignOff()
	Return.......: N/A
	Description..: Tells the user goodbye, that is all...
*/
void vSignOff()
{
	cout << "\n\nGoodbye! Have a nice day!\n\n";
	
	return;
}

/*
	Func Name....: Main Menu
	Syntax.......: cMainMenu()
	Return.......: User's Input
	Description..: Prompts the user with a menu and gets their input
*/
char cMainMenu()
{
	// Declare Variables
	char cUserInput;
	
	// Display the options
	cout << "\n\n\nTime-Of-Death Determination Options\n";
	cout << "-----------------------------------\n";
	cout << "\t1. Rigor Mortis\n";
	cout << "\t2. Algor Mortis\n";
	cout << "\t3. Occular Mortis\n";
	cout << "\t4. Vitreous Potassium Mortis\n";
	cout << "\t5. Stomach Mortis\n";
	cout << "\t6. Quit Mortis\n\n\n";
	cout << "Choose an Option (1-6): ";
	
	// Get Input 
	cin >> cUserInput;
	
	return cUserInput;
}

/*
	Func Name....: Rigor Mortis
	Syntax.......: iRigorMortis(fBodyTemp, bVictimIll, bCompSci)
	Parameters...: fBodyTemp (float) - The Body Temperature
								 bVictimIll (bool) - True if victim was ill before death 
								 bCompSci (bool) - True if the victim was a Computer Scientist
	Return.......: The estimated TOD
	Description..: Calculates and returns the time of death 
*/
int iRigorMortis(float fBodyTemp, bool bVictimIll, bool bCompSci)
{
	// Declare Variables 
	int iTimeOfDeath;
	
	// Calculate Time of Death 
	iTimeOfDeath = round((98.6 - fBodyTemp) / (2.1 + 1.5 * (bVictimIll?1:0) - 2.5 *(bCompSci?1:0)));
	
	return iTimeOfDeath;
}

/*
	Func Name....: Algor Mortis
	Syntax.......: iAlgorMortis(fBodyTemp)
	Parameters...: fBodyTemp (float) - The body temperature
	Return.......: Time of Death
	Description..: Calculates and returns the time of death
*/
int iAlgorMortis(float fBodyTemp)
{	
	// Declare Variables
	int iTimeOfDeath;
	
	// Calculate Time of Death 
	iTimeOfDeath = round((98.6 - fBodyTemp) / 1.5);
	
	return iTimeOfDeath;
}

/*
	Func Name....: Occular Mortis
	Syntax.......: iOccularMortis(bBulgingEyes, bOccularDiscolor)
	Parameters...: bOccularDiscolor (bool) - True if the occular was discolored
								 bBulgingEyes (bool) - True if the body has bulging eyes
	Return.......: The Time of death 
	Description..: Calculates and returns the time of death 
*/
int iOccularMortis(bool bBulgingEyes, bool bOccularDiscolor)
{
	// Declare Constants
	const int NO_DISCOLOR_NO_BULGING = 4;
	const int DISCOLOR_NO_BULGING = 7;
	const int NO_DISCOLOR_BULGING = 16;
	const int DISCOLOR_BULGING = 24;
	
	// Declare Variables
	int iTimeOfDeath = 0;
	
	// Calculate the Time of Death 
	if (!bOccularDiscolor && !bBulgingEyes)
		iTimeOfDeath = NO_DISCOLOR_NO_BULGING;
	else if (bOccularDiscolor && !bBulgingEyes)
		iTimeOfDeath = DISCOLOR_NO_BULGING;
	else if (!bOccularDiscolor && bBulgingEyes)
		iTimeOfDeath = NO_DISCOLOR_BULGING;
	else if (bOccularDiscolor && bBulgingEyes)
		iTimeOfDeath = DISCOLOR_BULGING;
	else
		cout << "\n\nWhoops!\nSomething went wrong.\n";
	
	return iTimeOfDeath;
}

/*
	Func Name....: Vitreous Potassium Mortis
	Syntax.......: iVitPotassiumMortis(fKConcentration)
	Parameters...: fKConcentration (float) - Potassium Concentration
	Return.......: The Estimated Time of death 
	Description..: Calculates and returns the time of death 
*/
int iVitPotassiumMortis(float fKConcentration)
{
	// Declare Variables
	int iTimeOfDeath;
	
	// Calculate Time of Death 
	iTimeOfDeath = round((17.14 * fKConcentration) - 39.1);
	
	return iTimeOfDeath;
}

/*
	Func Name....: Stomach Mortis
	Syntax.......: iStomachMortis(iNumShots)
	Parameters...: iNumShots (int) - Number of shots
	Return.......: The Estimated Time of death 
	Description..: Calculates and returns the time of death 
*/
int iStomachMortis(int iNumShots)
{
	// Declare Variables
	int iTimeOfDeath;
	
	// Calculate Time of Death 
	iTimeOfDeath = round(10 - iNumShots);
	
	return iTimeOfDeath;
}

/*
	Func Name....: Present Results
	Syntax.......: vPresentResults(iTimeOfDeath, iTolerance)
	Parameters...: iTimeOfDeath (int) - The Time of Death 
								 iTolerance (int) - Error Tolerance
	Return.......: N/A
	Description..: Displays the results in a nice format
*/
void vPresentResults(int iTimeOfDeath, int iTolerance)
{
	// Display Results 
	cout << "\nThe estimated Time of Death is between " << (((iTimeOfDeath - iTolerance) < 0) ? 0 : iTimeOfDeath - iTolerance) << " and " << iTimeOfDeath + iTimeOfDeath << " hours ago.\n";
	
	return;
}

/*
	Func Name....: Get Boolean Input
	Syntax.......: getBool(sPrompt)
	Parameters...: sPrompt (string) - The user prompt for input 
	Return.......: true or false
	Description..: Gets boolean input from the user
*/
bool getBool(string sPrompt)
{
	// Declare Variables 
	bool bValid = false; // True when the input is valid (will exit the do-while loop when true)
	bool bResult;
	char cUserInput;
	
	// Loop until input is valid
	do 
	{
		// Prompt the user and get input 
		cout << sPrompt << " ";
		cin >> cUserInput;
		
		// Check if answer is valid with true/yes or false/no
		if (cUserInput == 't' || cUserInput == 'T' || cUserInput == 'y' || cUserInput == 'Y')
		{
			// Answered yes or true
			bValid = true;
			bResult = true;
		}
		else if (cUserInput == 'f' || cUserInput == 'F' || cUserInput == 'n' || cUserInput == 'N')
		{
			// Answered no or false
			bValid = true;
			bResult = false;
		}
		else
		{
			// Unknown input
			cout << "\n\n Unknown input, please only enter T/Y or F/N. \n";
		}
	} while (!bValid);
	
	return bResult;
}

/*
	Func Name....: Get Float Input
	Syntax.......: getFloat(sPrompt)
	Parameters...: sPrompt (string) - The user prompt for input 
	Return.......: The float input
	Description..: Gets number input from the user
*/
float getFloat(string sPrompt)
{
	// Declare Variables
	float fUserInput;
	
	// Prompt the user and get Input
	cout << sPrompt << " ";
	cin >> fUserInput;

	return fUserInput;
}

/*
	Func Name....: Get Integer Input
	Syntax.......: getInt(sPrompt)
	Parameters...: sPrompt (string) - The user prompt for input 
	Return.......: The integer input
	Description..: Gets number input from the user
*/
int getInt(string sPrompt)
{
	// Declare Variables
	int iUserInput;
	
	// Prompt the user and get Input
	cout << sPrompt << " ";
	cin >> iUserInput;
	
	return iUserInput;
}