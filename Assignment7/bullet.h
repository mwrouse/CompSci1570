#ifndef bullet_h
#define bullet_h
/* 
	Program......: Assignment 07
	File.........: bullet.h
	Student......: Michael Rouse 
	Student ID...: 12442296
	Class........: Comp Sci 1570 Section D
	Instructor...: Fletcher
	Date.........: 03/20/2015
	Description..: Header file for bullet information
*/
#include <iostream>
#include "general.h"

using namespace std;

struct bullet
{
	float caliber; 					// The bullet's caliber
	short numberOfLands; 		// The number of grooves/lands on the bullet 
	float landWidth;				// The width of a land on the bullet 
	float grooveWidth;			// The width of a groove on the bullet 
	bool chamberMarkings;		// True if the bullet has chamber markings 
	string lastOwner;				// Last known owner of the gun
};


// Function Prototypes
void initialOutput();
void populateDatabase(bullet database[], const int DATABASE_SIZE);
void printDatabase(bullet database[], const int DATABASE_SIZE);
void sortByCaliber(bullet database[], const int DATABASE_SIZE);
void findLargestGroove(bullet database[], const int DATABASE_SIZE);
void findBullet(bullet database[], const int DATABASE_SIZE);
float getCaliber();
int getLands();
float getWidth(string prompt);
bool getYesOrNo(string prompt);
void matchBullet(bullet userBullet, bullet database[], const int DATABASE_SIZE);



#endif