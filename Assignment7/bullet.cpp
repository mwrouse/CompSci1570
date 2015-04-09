/* 
	Program......: Assignment 07
	File.........: bullet.cpp
	Student......: Michael Rouse 
	Student ID...: 12442296
	Class........: Comp Sci 1570 Section D
	Instructor...: Fletcher
	Date.........: 03/20/2015
	Description..: Functions for finding info about the bullet
*/

#include "bullet.h"


void populateDatabase(bullet database[], const int DATABASE_SIZE)
{
	// Variables 
	string sUserInput;
	
	// Populate the database 
	for (int i = 0; i < DATABASE_SIZE; i++)
	{
		int iRandom;
		
		// Caliber
		iRandom = random(1, 3);
		
		switch (iRandom)
		{
			case 1:
				database[i].caliber = .22;
				break;
			case 2:
				database[i].caliber = .38;
				break;
			case 3:
				database[i].caliber = .50;
		}
		
		// Lands/Ridges
		database[i].numberOfLands = random(1, 3) + 4;
			
		// Width of lands/ ridges
		database[i].landWidth = (static_cast<float>(random(25, 30))) / 1000.0;
		database[i].grooveWidth = (static_cast<float>(random(25, 30))) / 1000.0;
		
		// Chamber Markings
		database[i].chamberMarkings = (random(0, 1) == 1)?true:false;
		
		// Last Owner
		cout << "Please enter a first name: ";
		cin >> database[i].lastOwner;

	}
	
	cout << "\n\n";
	
	return;
}


void printDatabase(bullet database[], const int DATABASE_SIZE)
{
	// Print the database
	cout << "The Bullet Database: \n";
	
	for (int i = 0; i < DATABASE_SIZE; i++)
	{
		cout << "\t" << i + 1 << ") ";
		cout << database[i].caliber << ", ";
		cout << database[i].numberOfLands << ", ";
		cout << database[i].landWidth << ", ";
		cout << database[i].grooveWidth << ", ";
		if (database[i].chamberMarkings)
			cout << "Marks\n";
		else
			cout << "No Marks\n";
	}
	return;
}

void sortByCaliber(bullet database[], const int DATABASE_SIZE)
{
	// Variables 
	bool swap;
	bullet temp;
	
	cout << "\nSorting By Caliber...\n\n";
	
	do
	{
		swap = false;
		for (int i = 0; i < DATABASE_SIZE; i++)
		{
			if (database[i].caliber < database[i + 1].caliber)
			{
				// swap the two
				temp = database[i];
				
				database[i] = database[i + 1];
				database[i + 1] = temp;
				
				swap = true;
			}
		}
	
	}while (swap);
	
	return;
}

void findLargestGroove(bullet database[], const int DATABASE_SIZE)
{	
	// Variables 	
	bullet largest;
	int bulletNumber = 0;
	largest.grooveWidth = 0.0;

	cout << "\n\nFinding 38 Caliber Bullet with Largest Groove Width...\n\n";

	for (int i = 0; i < DATABASE_SIZE; i++)
	{
		if (database[i].caliber != .5 && database[i].caliber != .22)
		{	
			if (database[i].grooveWidth > largest.grooveWidth)
			{
				largest = database[i];
				bulletNumber = i + 1;
			}

		}
	}
	
	cout << "Bullet Found:\n\t";
	cout << bulletNumber << ") ";
	cout << largest.caliber << ", ";
	cout << largest.numberOfLands << ", ";
	cout << largest.landWidth << ", ";
	cout << largest.grooveWidth << ", ";
	if (largest.chamberMarkings)
		cout << "Marks\n";
	else
		cout << "No Marks\n";	

	return;
}

void findBullet(bullet database[], const int DATABASE_SIZE)
{
	// Variables 
	bullet userBullet;
	
	cout << "\nPlease enter the bullet information:\n\n";
	
	// Please enter information about the bullet
	userBullet.caliber = getCaliber();
	userBullet.numberOfLands = getLands();
	userBullet.landWidth = getWidth("Width of the Lands: ");
	userBullet.grooveWidth = getWidth("Width of the Grooves: ");
	userBullet.chamberMarkings = getYesOrNo("Does the bullet have chamber markings (Y/N)? ");
	
	cout << "\n\nLocating bullet in database...\n\n";
	
	matchBullet(userBullet, database, DATABASE_SIZE);
	return;
}

float getCaliber()
{
	int iUserInput;
	float calibers[3] = {.22, .38, .50};
	
	cout << "\nWhat Caliber is the bullet?\n";
	cout << "\t1. .22\n";
	cout << "\t2. .38\n";
	cout << "\t3. .50\n\n";
	
	do
	{
		cout << "Choose an Option (1-3): ";
		cin >> iUserInput;
	} while (iUserInput != 1 && iUserInput != 2 && iUserInput != 3);
	
	return calibers[iUserInput - 1];
}

int getLands()
{
	int iUserInput;
	int lands[3] = {5, 6, 7};
	
	cout << "\nHow many lands/grooves are there?\n";
	cout << "\t1. 5\n";
	cout << "\t2. 6\n";
	cout << "\t3. 7\n\n";
	
	do
	{
		cout << "Choose an Option (1-3): ";
		cin >> iUserInput;
	} while (iUserInput != 1 && iUserInput != 2 && iUserInput != 3);
	
	return lands[iUserInput - 1];
}

float getWidth(string prompt)
{
	// Variables 
	float fUserInput;
		
	do
	{
		cout << prompt;
		cin >> fUserInput;
	} while (fUserInput < 0.025 || fUserInput > 0.030);
	
	return fUserInput;
}

bool getYesOrNo(string prompt)
{
	bool returnValue;
	char cUserInput;
	bool valid = false;
	
	do
	{
		cout << prompt;
		cin >> cUserInput;
		
		switch (cUserInput)
		{
			case 'y':
			case 'Y':
				returnValue = true;
				valid = true;
				break;
				
			case 'n':
			case 'N':
				returnValue = false;
				valid = true;
				break;
			
		}
	}while (!valid);
	
	
	return returnValue;
}

void matchBullet(bullet userBullet, bullet database[], const int DATABASE_SIZE)
{
	bool matchFound = false;
	
	// Match the bullet 
	for (int i = 0; i < DATABASE_SIZE; i++)
	{
		if (database[i].caliber == userBullet.caliber)
		{
			if (database[i].numberOfLands == userBullet.numberOfLands)
			{
				if (database[i].landWidth <= userBullet.landWidth + 0.001 && database[i].landWidth >= userBullet.landWidth - 0.001)
				{
					if (database[i].grooveWidth <= userBullet.grooveWidth + 0.001 && database[i].grooveWidth >= userBullet.grooveWidth - 0.001)
					{
						if (database[i].chamberMarkings == userBullet.chamberMarkings)
						{
							// Match Found 
							int randomNumber = random(1, 4);
							cout << "\n\n";
							
							// Display output
							switch (randomNumber)
							{
								case 1:
									cout << "Got it! That bullet belongs to the scumbag, " << database[i].lastOwner << "!";
									break;
									
								case 2:
									cout << "Match Found! It belongs to " << database[i].lastOwner << ", I heard he's from Mars";
									break;
									
								case 3:
									cout << "Yay! Your bullet belongs to the low-life that goes by the name of " << database[i].lastOwner << ", go get 'em!";
									break;
								
								case 4:
									cout << "Looks like " << database[i].lastOwner << " is going to be in trouble, that's his bullet!";
									break;								
							}
							cout << "\n\n";
							matchFound = true;
							break;
						}
					}
				}
			}
		}
	}
	
	if (!matchFound)
		cout << "\n\nWell, it looks like there isn't a match for that bullet in our database...\n\n";
	
	return;
}