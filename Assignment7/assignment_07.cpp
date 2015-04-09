/* 
	Program......: Assignment 07
	File.........: assignment_07.cpp
	Student......: Michael Rouse 
	Student ID...: 12442296
	Class........: Comp Sci 1570 Section D
	Instructor...: Fletcher
	Date.........: 03/20/2015
	Description..: 
*/
#include "bullet.h"
#include "general.h"

int mainMenu();


int main()
{	
	// Constants 
	const int DATABASE_SIZE = 25;
	
	// Variables 
	int iUserInput; 
	bullet database[DATABASE_SIZE]; // Database of bullets 
	
	srand(unsigned(time(NULL))); // Randomize seed
	
	// Welcome the user 
	cout << "\n\nWelcome to the Bullet Database Program!\n\n";
	cout << "Please help us fill out this bullet database with names:\n\n";
	
	// Fill the database of bullets 
	populateDatabase(database, DATABASE_SIZE);

	// Display the database
	printDatabase(database, DATABASE_SIZE);
	
	// Sort by Caliber and display the database
	sortByCaliber(database, DATABASE_SIZE);
	printDatabase(database, DATABASE_SIZE);
	
	// Display the bullet with the largest groove
	findLargestGroove(database, DATABASE_SIZE);
	
	// Main Menu Choices 
	do
	{
		// Show menu and get input 
		iUserInput = mainMenu();
		
		
		switch (iUserInput)
		{
			// Display the database
			case 1:
				printDatabase(database, DATABASE_SIZE);
				break;
				
			// Find a bullet 
			case 2:
				findBullet(database, DATABASE_SIZE);
				break;
		}
	
	} while (iUserInput != 0);
	
	return 0;
}


int mainMenu()
{
	int iUserInput;
	
	cout << "\n\nWelcome to the Bullet Program\n";
	cout << "\t1. Display Database\n";
	cout << "\t2. Find a bullet\n";
	cout << "\t0. Exit\n\n";
	
	do
	{
		cout << "Choose an Option: ";
		cin >> iUserInput;
		
	} while (iUserInput != 0 && iUserInput != 1 && iUserInput != 2);
	
	return iUserInput;
}