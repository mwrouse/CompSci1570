/* 
	Program......: Assignment 6
	File.........: menu.cpp
	Student......: Michael Rouse 
	Student ID...: 12442296
	Class........: Comp Sci 1570 Section D
	Instructor...: Fletcher
	Date.........: 03/11/2015
	Description..: Contains functions for the program menu items
*/
#include "menu.h"


/*
	Name.........: Main Menu 
	Syntax.......: mainMenu();
	Return.......: N/A
	Description..: Displays the main menu for the program and loops until the user exits
*/
void mainMenu()
{
	// Variables 
	int iUserChoice; 
	
	// Loop until the user exits
	do
	{
		// Display the menu 
		cout << "\n\n\tCrime-O-Light 450\n"
				<< "\t-----------------\n\n"
				<< "1. Hair\n"
				<< "2. Saliva and hair\n"
				<< "3. Chicken noodle soup, saliva, and hair\n"
				<< "4. Green Goo\n"
				<< "5. Exit\n\n";
				
		iUserChoice = getNumInput("Choose an option", 1, 5);
		
		cout << "\n";
		
		// Choose what to do based on the user's choice
		switch (iUserChoice)
		{
			// Hair
			case 1:
				hair();				
				break;
				
			// Saliva and hair
			case 2:
				salivaAndHair();
				break;
				
			// Chicken Noodle Soup, Saliva, and Hair
			case 3:
				soupSalivaAndHair();
				break;
			
			// Green Goo 
			case 4:
				greenGoo();
				break; 
		}
		
	}while (iUserChoice != 5);
	
	// Say Goodbye
	cout << "\n\nThank you for using the program, have a nice day.\n\n";
	
	return;
	
}

/*
	Name.........: Find Hair Wavelength
	Syntax.......: hair();
	Return.......: N/A
	Description..: Calculates and displays the wavelength for certain hair
*/
void hair()
{
	// Variables 
	float fWaveLength;
	float fHairIndex = getHairIndex();
	
	// Calculate the wavelength
	fWaveLength = getWaveLength(fHairIndex);
	
	// Display the wavelength 
	displayResults("Hair", "Index.......", fHairIndex, fWaveLength);
	
	return;
}

/*
	Name.........: Saliva and Hair WaveLength
	Syntax.......: salivaAndHair();
	Return.......: N/A
	Description..: Calculates and displays wavelength for saliva and hair
*/
void salivaAndHair()
{	
	// Constants
	const int MIN_PRECISION = 2;	// Minimum allowed precision 
	const int MAX_PRECISION = 8;	// Maximum allowed precision
	
	// Variables 
	float fWaveLength;
	int iPrecision;
	float fHairIndex;
	
	// Get Precision
	iPrecision = getPrecision(MIN_PRECISION, MAX_PRECISION);
	
	// Get Hair Index 
	fHairIndex = getHairIndex();
	
	// Calculate the WaveLength
	fWaveLength = getWaveLength(fHairIndex, iPrecision);
	
	// Display results
	displayResults("Saliva and Hair", "Index.......", fHairIndex, fWaveLength, "Precision...", iPrecision);
	
	return;
}

/*
	Name.........: Soup, Saliva, and Hair 
	Syntax.......: soupSalivaAndHair();
	Return.......: N/A
	Description..: Calculates and displays the wavelength for soup, saliva, and hair
*/
void soupSalivaAndHair()
{
	// Constants
	const int MIN_PRECISION = 1;		// Minimum allowed precision 
	const int MAX_PRECISION = 100;	// Maximum allowed precision

	// Variables 
	bool bIsHomemade;
	int iPrecision;
	float fWaveLength;
	string sTitle = "Chicken Noodle Soup, Saliva and Hair";
	
	// Get the precision
	iPrecision = getPrecision(MIN_PRECISION, MAX_PRECISION);
	
	// Ask if the soup is homemade
	bIsHomemade = askYesOrNo("Is the soup homemade");
	
	// Change the title if the soup is homemade
	if (bIsHomemade)
		sTitle = "Homemade Chicken Noodle Soup, Saliva, and Hair";
	
	// Calculate the WaveLength 
	fWaveLength = getWaveLength(iPrecision, bIsHomemade);
	
	// Display the results 
	displayResults(sTitle, "Precision...", static_cast<float>(iPrecision), fWaveLength);
	
	return;
}

/*
	Name.........: Green Goo
	Syntax.......: greenGoo();
	Return.......: N/A
	Description..: Calculates and displays the wavelength for Green Goo
*/
void greenGoo()
{
	// Constants	
	const int MIN_GRADE = 0;	// Minimum Goo Grade
	const int MAX_GRADE = 6;	// Maximum Goo Grade
	
	const int MIN_HEIGHT = 1; // Minimum alien height 
	const int MAX_HEIGHT = 3;	// Maximum alien height
	
	// Variables 
	int iGrade;
	int iHeight;
	float fWaveLength;
	
	// Get the Goo Grade 
	iGrade = getNumInput("Enter Goo Grade", MIN_GRADE, MAX_GRADE);
	
	// Get alien height
	iHeight = getNumInput("Alien's height in feet", MIN_HEIGHT, MAX_HEIGHT);
	
	// Calculate the WaveLength
	fWaveLength = getWaveLength(iGrade, iHeight);
	
	// Display results 
	displayResults("Green Goo", "Goo Grade...", static_cast<float>(iGrade), fWaveLength, "Height(ft)..", iHeight);
	
	return;
}