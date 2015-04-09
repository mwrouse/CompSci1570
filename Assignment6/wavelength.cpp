/* 
	Program......: Assignment 6
	File.........: wavelength.cpp
	Student......: Michael Rouse 
	Student ID...: 12442296
	Class........: Comp Sci 1570 Section D
	Instructor...: Fletcher
	Date.........: 03/11/2015
	Description..: Contains function prototypes for calculating wavelengths
*/
#include "wavelength.h"

/*
	Name.........: Hair WaveLength
	Author.......: Michael Rouse
	Syntax.......: hair();
	Return.......: Calculated WaveLength
	Description..: Calculate wavelength for certain hair (400 * hair_index)
*/
float getWaveLength(float fHairIndex)
{
	// Constants 
	const int BASE_WAVELENGTH = 400;

	return (BASE_WAVELENGTH * fHairIndex);
}

/*
	Name.........: Hair and Saliva WaveLength
	Author.......: Michael Rouse
	Syntax.......: getWaveLength(fHairIndex, iPrecision);
	Parameters...: float fHairIndex - The Index for the hair
								 int iPrecision - The precision value 
	Return.......: float fWaveLength - The calculated wavelength
	Description..: Calculates the wavelength for hair 
*/
float getWaveLength(float fHairIndex, int iPrecision)
{
	// Variables
	float fWaveLength = 1.0;
	
	// Compute the wavelength 
	for (float fCounter = 2; fCounter <= static_cast<float>(iPrecision); fCounter++)
	{
		fWaveLength += (1.0 / fCounter);
	}
	
	fWaveLength *= WAVELENGTH_MODIFIER;
	fWaveLength *= fHairIndex;
	
	return fWaveLength;
}

/*
	Name.........: Chicken Noodle Soup, Hair, and Saliva WaveLength
	Author.......: Michael Rouse
	Syntax.......: getWaveLength(iPrecision, bIsHomeMade);
	Parameters...: int iPrecision - The precision value 
								 bool bIsHomeMade - True if the soup looks homemade, false if it doesn't
	Return.......: float fWaveLength - The calculated wavelength 
	Description..: Calculates and returns the wavelength to show hair and saliva
*/ 
float getWaveLength(int iPrecision, bool bIsHomeMade)
{
	// Constants
	const float HOMEMADE_MODIFIER = 2.3;	// Modifier if the soup is homemade
	
	// Variables 
	float fWaveLength = 1.0;
	int iPrecisionPower;
	
	// Calculate 2^iPrecision
	for (int iExpCounter = 2; iExpCounter <= iPrecision; iExpCounter++)
	{
		iPrecisionPower *= 2;
	}
	
	// Calculate the WaveLength 
	for (float fCounter = 2; fCounter <= static_cast<float>(iPrecisionPower); fCounter *= 2)
	{
		fWaveLength += (1.00 / fCounter);
	}
	
	fWaveLength *= WAVELENGTH_MODIFIER;
	
	if (bIsHomeMade)
		fWaveLength *= HOMEMADE_MODIFIER;

	return fWaveLength;
}

/*
	Name.........: Green Goo WaveLength
	Author.......: Michael Rouse
	Syntax.......: getWaveLength(iGrade, iAlienHeight);
	Parameters...: int iGrade - The grade of the Green Goo 
								 int iAlienHeight - The height of the Alien the Green Goo came from 
	Return.......: float fWaveLength - The calculated wavelength
	Description..: Calculates and returns the wavelength to show Green Goo
*/
float getWaveLength(int iGrade, int iAlienHeight)
{	
	// Constants
	const int GRADE_0 = 200;
	const int GRADE_1 = 43;	
	const int GRADE_2 = 17;
	const int GRADE_3 = 23;
	const int GRADE_4 = 77; 
	const int GRADE_5 = 55;
	const int GRADE_6 = 35;
	
	// Variables 
	float fWaveLength = static_cast<float>(iAlienHeight);
	
	// Calculate the WaveLength
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
	
	return fWaveLength;
}