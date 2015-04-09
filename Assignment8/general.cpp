/* 
	Program......: Assignment 07
	File.........: general.cpp
	Student......: Michael Rouse 
	Student ID...: 12442296
	Class........: Comp Sci 1570 Section D
	Instructor...: Fletcher
	Date.........: 03/20/2015
	Description..: CPP file for general functions to use in the program
*/
#include "general.h"


int random(const int MIN, const int MAX)
{	
	// Generate a random number
	int returnValue = rand() % (MAX - MIN + 1) + MIN;

	return returnValue;
	
}

void randomize()
{
	srand(unsigned(time(NULL))); // Randomize seed
	return;
}