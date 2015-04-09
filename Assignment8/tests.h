#ifndef TESTS_H
#define TESTS_H
/* 
	Program......: Assignment 08
	File.........: tests.h
	Student......: Michael Rouse 
	Student ID...: 12442296
	Class........: Comp Sci 1570 Section D
	Instructor...: Fletcher
	Date.........: 04/06/2015
	Description..: Functions and variables for Test 1 and Test 2
*/
#include <iostream>
#include "general.h"
#include "string.h"
#include <string>

using namespace std;

// Constants
const int DNA_SIZE = 128;
const int DEAD_DNA_SIZE = 16;
const int DENTAL_SIZE = 32;
const int NUMBER_OF_MISSING_COWS = 5;
const int NUMBER_OF_DEAD_COWS = 3;

// Structs
struct bovine
{
	string name;
	char DNA[DNA_SIZE + 1];
	char dental[DENTAL_SIZE + 1];
};

/*
	Name.........: Cow Birth
	Syntax.......: cowBirth(cows[], NUMBER_OF_COWS, DEAD_COWS);
	Description..: Will fill an array with bovine (name, dental records, and a DNA sample)
*/
void cowBirth(bovine cows[], const int NUMBER_OF_COWS, const bool DEAD_COWS = false);

/*
	Name.........: Perform Tests
	Syntax.......: performTests();
	Description..: Will perform the task of Test 1
*/
void performTests(bovine deadCows[], bovine missingCows[]);

/*
	Name.........: Generate DNA
	Syntax.......: generateDNA(DNA_SIZE[, MISSING_STRANDS]);
	Description..: Will create a random strand of DNA letters for use in the program
*/
void generateDNA(char DNA[], const int DNA_SIZE, const bool MISSING_STRANDS = false);

/*
	Name.........: Check DNA Match
	Syntax.......: checkDNAMatch(missingDNA, foundDNA);
	Description..: Will check to see if foundDNA matches with any substring inside of missingDNA of at-least 90% matches
*/
bool checkDNAMatch(char missingDNA[], char foundDNA[], string cowName);

/*
	Name.........: Generate Dental 
	Syntax.......: generateDental(DENTAL_SIZE);
	Description..: Will generate and return a character array of size DENTAL_SIZE representing the dental records
*/ 
void generateDental(char dental[], const int DENTAL_SIZE);

/*
	Name.........: Check Dental Match 
	Syntax.......: checkDentalMatch(missingDental[], foundDental[], cowName);
	Description..: Will check to see if the missingDental[] matches with foundDental[]
*/
bool checkDentalMatch(char missingDental[], char foundDental[], string cowName);

/*
	Name.........: Get Percentage
	Syntax.......: getPercentage(NUM, PER);
	Description..: Will calculate a percentage of a number
*/
int getPercentage(const int NUM, const double PER);

#endif