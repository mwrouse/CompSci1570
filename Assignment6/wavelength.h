#ifndef wavelength_h
#define wavelength_h
/* 
	Program......: Assignment 6
	File.........: wavelength.h
	Student......: Michael Rouse 
	Student ID...: 12442296
	Class........: Comp Sci 1570 Section D
	Instructor...: Fletcher
	Date.........: 03/11/2015
	Description..: Contains function prototypes for calculating wavelengths
*/
#include <iostream>
#include <cmath>

using namespace std;

// Constants 
const int WAVELENGTH_MODIFIER = 100; 

// Function Prototypes
float getWaveLength(float fHairIndex); 								 // Hair 
float getWaveLength(float fHairIndex, int iPrecision); // Hair and saliva
float getWaveLength(int iPrecision, bool bIsHomeMade); // Soup, saliva, and hair 
float getWaveLength(int iGrade, int iAlienHeight); 		 // Green Goo



#endif