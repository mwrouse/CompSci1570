/* 
	Program......: assignment_04.cpp
	Student......: Michael Rouse 
	Student ID...: 12442296
	Class........: Comp Sci 1570 Section D
	Instructor...: Fletcher
	Date.........: 02/20/2015
	Description..: Give a user a menu, after input decide the wavelength needed to reveal that object at a crime scene
*/
#include <iostream>

using namespace std;

int main()
{
	// Declare Constants for the GOO Grades
	// E.g., Grade 1 Wavelength = BASE_GRADE + 43 (GRADE_1 Constant)
	const int GRADE_0 = 200;
	const int GRADE_1 = 43;	
	const int GRADE_2 = 17;
	const int GRADE_3 = 23;
	const int GRADE_4 = 77; 
	const int GRADE_5 = 55;
	const int GRADE_6 = 35;
	
	// Declare Variables
	int iUserChoice;			// User Input at the main menu
	int iPrecision;				// Number for precision on certain menu items
	int iGrade; 					// Grade of the GOO
	long iPrecisionPower; // Chicken Noodle Soup, value of 2^iPrecision
	
	float fWaveLength;		// Wavelength required

	// Loop until the user exits
	do
	{
		// Reset/Initialize certain variables every loop
		fWaveLength = 0.00;
		iPrecisionPower = 2;
		iGrade = 0;
		
		// Display the menu
		cout << "\n\n\tCrime-O-Light 400\n";
		cout << "\t-----------------\n\n";
		cout << "1. Hair\n";
		cout << "2. Saliva and hair\n";
		cout << "3. Chicken noodle soup, saliva, and hair\n";
		cout << "4. Green Goo\n";
		cout << "5. Exit\n\n";
		
		// Get User Input
		cout << "Please choose an option (1-5): ";
		cin >> iUserChoice;
		
		cout << "\n\n";
		
		// Choose an option and display the wavelength
		switch (iUserChoice)
		{
			// =================================================	
			// Hair
			// =================================================
			case 1:
				cout << "\n======== RESULTS ========\n\n";
				cout << " Item........: Hair\n";
				cout << " Precision...: N/A\n";
				cout << " Wavelength..: 400 nm\n";
				cout << "\n=========================\n\n";
				break;
				
			// =================================================
			// Saliva and hair
			// =================================================
			case 2:
				do 
				{
					// Get Input
					cout << "Enter precision for Saliva and Hair (between 1 and 8): ";
					cin >> iPrecision;
				
					// Alert about invalid precision
					if (iPrecision < 2 || iPrecision >= 8)
						cout << "\nError: The precision must be greater than 1 and less than 8.\n";
					
				}while (iPrecision < 2 || iPrecision >= 8);
				
				// Calculate the wavelength
				fWaveLength = 1.0;
				for (float fCounter = 2; fCounter <= static_cast<float>(iPrecision); fCounter++)
				{
					fWaveLength += ( 1.000 / fCounter);
				}
				
				fWaveLength *= 100;	// multiply by 100
				
				// Display the wavelength
				cout << "\n======== RESULTS ========\n\n";
				cout << " Item........: Saliva and Hair\n";
				cout << " Precision...: " << iPrecision << "\n";
				cout << " Wavelength..: " << static_cast<int>(fWaveLength) << " nm\n";
				cout << "\n=========================\n\n";
				
				break;
				
			// =================================================
			// Chicken Noodle Soup, Saliva, and Hair
			// =================================================
			case 3:
				do
				{
					// Get Input
					cout << "Enter the precision for chicken noodle soup, saliva, and hair (greater than 0): ";
					cin >> iPrecision;
					
					// Alert about an invalid precision
					if (iPrecision < 1) 
						cout << "\nError: The precision must be greater than 0.\n";
					
				}while (iPrecision < 1);
				
				// Calculate the wavelength 
				fWaveLength = 1.0;
				
				// Calculate 2^iPrecision
				for (int iExpCounter = 2; iExpCounter <= iPrecision; iExpCounter++)
				{
					iPrecisionPower *= 2;
				}
				
				for (float fCounter = 2; fCounter <= static_cast<float>(iPrecisionPower); fCounter *= 2)
				{
					fWaveLength += (1.00 / fCounter);
				}
				
				fWaveLength *= 100; // Multiply by 100 
				
				// Display the wavelength
				cout << "\n======== RESULTS ========\n\n";
				cout << " Item........: Chicken Noodle Soup, Saliva, and Hair\n";
				cout << " Precision...: " << iPrecision << "\n";
				cout << " Wavelength..: " << static_cast<int>(fWaveLength) << " nm\n";
				cout << "\n=========================\n\n";
				
				break;
			
			// =================================================
			// Green Goo 
			// =================================================
			case 4:
				// Loop until valid input
				do 
				{
					// Get Input
					cout << "Enter Goo Grade (0-6): ";
					cin >> iGrade;
					
					// Alert for an invalid Grade
					if (iGrade < 0 || iGrade > 6)
						cout << "\nError: The Goo Grade must be greater than or equal to zero.\n";
					
				}while(iGrade < 0 || iGrade > 6);
				
				switch (iGrade)
				{
					case 6:
						// Grade 6
						fWaveLength += GRADE_6;
						
					case 5:
						// Grade 5
						fWaveLength += GRADE_5;
						
					case 4:
						// Grade 4 
						fWaveLength += GRADE_4; 

					case 3:
						// Grade 3 
						fWaveLength += GRADE_3;
						
					case 2:
						// Grade 2
						fWaveLength += GRADE_2;
					
					case 1:
						// Grade 1
						fWaveLength += GRADE_1;
						
					case 0:
						// Grade 0 
						fWaveLength += GRADE_0;
				}
				
				// Display the wavelength 
				cout << "\n======== RESULTS ========\n\n";
				cout << " Item........: Green Goo\n";
				cout << " Grade.......: " << iGrade << "\n";
				cout << " Wavelength..: " << static_cast<int>(fWaveLength) << " nm\n";
				cout << "\n=========================\n\n";
				
				break; 

			// =================================================
			// Unknown 
			// =================================================
			default: 
				// Whoops?
				cout << "\n\nWhoops! Something went wrong, try running the program again.\n";
		}
		
	}while(iUserChoice != 5);
	
	// Close the program
	cout << "\n\nThank you for using the program, have a nice day.\n";
	cout << "\nGoodbye.\n\n";
	
	return 0;
}