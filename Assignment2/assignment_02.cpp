/* 
	Program....: assignment_02.cpp
	Student....: Michael Rouse 
	Student ID.: 12442296
	Class......: Comp Sci 1570 Section D
	Instructor.: Fletcher
	Date.......: 02/06/2015
	Description: Green Goo Pattern Analysis
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// Constants
	const int GOO_CONVERSION = 1;
	
	// Declare Variables
	int iHeight; 		// Height of the green goo spatter
	int iWidth;			// The width of the green goo spatter
	int iLength; 		// Length of the green goo spatter 
	float fGamma;		// Angle in radians (γ)
	
	float fAngleA;  // α = arcsin(width/length)
	float fAngleB;  // β = arctan(tan(α) / sin(γ))
	float iVy;			// Vy = height * tan(α)
	float iVx;			// Vx = Vy * tan(β)

	// Welcome the user
	cout << "Green Goo Pattern Analyser 2000\n\n";
	
	// Prompt the user to input information
	cout << "Height (whole inches)..: ";
	cin >> iHeight;
	
	cout << "Width (whole inches)...: ";
	cin >> iWidth;
	
	cout << "Length (whole inches)..: ";
	cin >> iLength;
	
	cout << "Angle γ (radians)......: ";
	cin >> fGamma;
	
	// Separate the information
	cout << "\n\n\n";
	
	// Perform Computations
	fAngleA = asin(static_cast<double>(iWidth - GOO_CONVERSION) / (iLength - GOO_CONVERSION));
	fAngleB = atan(static_cast<double>(tan(fAngleA) / sin(static_cast<double>(fGamma))));
	
	// Calculate Spatter Origin
	iVy = static_cast<float>(iHeight) * tan(fAngleA); // x-position
	iVx = iVy * tan(static_cast<double>(fAngleB));    // y-position
	
	// Show results
	cout << "********* ANALYSIS COMPLETE *********\n";
	cout << "Height..: " << iHeight << " inches\n";
	cout << "Width...: " << iWidth << " inches\n";
	cout << "Length..: " << iLength << " inches\n";
	cout << "Gamma...: " << fGamma << " radians\n\n";
	cout << "Based on your input (shown above), the origin of the splatter is:\n";
	cout << "X: " << iVx << "\n";
	cout << "Y: " << iVy << "\n\n\n\n";
	
	// Thank the user for using the program
	cout << "Thank you for using the Green Goo Pattern Analyser 2000, have a nice day!\n\n";
	return 0;
}