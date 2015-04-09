/* 
	Program....: assignment_03.cpp
	Student....: Michael Rouse 
	Student ID.: 12442296
	Class......: Comp Sci 1570 Section D
	Instructor.: Fletcher
	Date.......: 02/13/2015
	Description: Probability for either cannibalism or robbery
*/
#include <iostream>

using namespace std;

int main()
{
	// Declare Variables (Hungarian Notation)
	string sName;			// User's Name
	int iCrime; 			// Crime Number
	string sCrime;    // Name of the crime (not user input)
	
	char cCluster;											// Suspect's Cluster
	int iDisorder;											// Suspect's Disorder 
	int iFeature;												// Suspect's Feature 
	int iSuspect, iOdds;								// Temp location for each suspect's odds and suspect number
	int iSuspect1Odds, iSuspect2Odds;		// Suspects Odds
	
	// Program Introduction 
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "============================================\n";
	cout << "|            CRIME SOLVER 2000              |\n";
	cout << "|                                           |\n";
	cout << "|            By Michael Rouse               |\n";
	cout << "============================================";
	// Get the name
	cout << "\n\nPlease enter your FIRST name: ";
	cin >> sName;
	
	// Get the crime number
	cout << "\nChoose a crime (1 = Cannibalism, 2 = Robbery): ";
	cin >> iCrime;
	
	if (iCrime == 1){
		sCrime = "Cannibalism";
	}else{
		sCrime = "Robbery";
	}
	
	// Thank the user, and then have them input info about customer 1 
	cout << "\n\n\nThank you, " << sName << ". Now you will enter in information for Suspect 1.\n";
	
	
	/*====================================
						GET SUSPECT INFORMATION
	======================================*/
	for (iSuspect = 1; iSuspect <= 2; iSuspect++)
	{
		cout << "\n\nSuspect " << iSuspect << "'s Cluster (A = Odd Disorders, B = Dramato-erratic): ";
		cin >> cCluster;
	
		// Branch off for each cluster for Suspect
		if (cCluster == 'a' || cCluster == 'A')
		{
			// Disorders for Cluster A 
			cout << "Suspect " << iSuspect << "'s Disorder (1 = Paranoid, 2 = Schizoid): ";
			cin >> iDisorder;
		
			// Branch off again for each disorder
			if (iDisorder == 1)
			{
				// Get feature for Paranoid
				cout << "Suspect " << iSuspect << "'s Feature (1 = Narcissistic, 2 = Sadistic): ";
				cin >> iFeature;
			
				// Calculate the odds for this suspect
				if (iFeature == 1)
				{
					// A Paranoid Narcissistic 
					if (iCrime == 1){
						// 3% of Cannibalism
						iOdds = 3;
					}else{
						// 12% of RObbery
						iOdds = 12;
					}
				}else{
					// A Paranoid Sadistic
					if (iCrime == 1)
					{
						// 4% of Cannibalism
						iOdds = 4;
					}else{
						// 1% of Robbery
						iOdds = 1;
					}
				}
			
			}else{
				// Get features for Schizoid
				cout << "Suspect " << iSuspect << "'s Feature (1 = Depressive, 2 = Compulsive): ";
				cin >> iFeature;
			
				// Calculate the odds for this suspect
				if (iFeature == 1)
				{
					// A Schizoid Depressive 
					if (iCrime == 1){
						// 5% of Cannibalism
						iOdds = 5;
					}else{
						// 3% of Robbery
						iOdds = 3;
					}
				}else{
					// A Schizoid Compulsive 
					if (iCrime == 1){
						// 3% of Cannibalism
						iOdds = 3;
					}else{
						// 7% of Robbery
						iOdds = 7;
					}
				}
			}
		
		}
		else if (cCluster == 'b' || cCluster == 'B')
		{
			// Disorders for Cluster B
			cout << "Suspect " << iSuspect << "'s Disorder (1 = Antisocial, 2 = Jerk): ";
			cin >> iDisorder;
		
			// Branch off again for each disorder
			if (iDisorder == 1)
			{
				// Get feature for an Antisocial 
				cout << "Suspect " << iSuspect << "'s Feature (1 = Avoidant, 2 = Creepy): ";
				cin >> iFeature;
			
				// Calculate the odds for this suspect
				if (iFeature == 1)
				{
					// B Antisocial Avoidant 
					if (iCrime == 1){
						// 2% of Cannibalism
						iOdds = 2;
					}else{
						// 8% of Robbery 
						iOdds = 8;
					}
				}else{
					// B Antisocial Creepy
					if (iCrime == 1)
					{
						// 9% of Cannibalism
						iOdds = 9;
					}else{
						// 3% of Robbery
						iOdds = 3;
					}
				}
			
			}else{
				// Get features for Jerk
				cout << "Suspect " << iSuspect << "'s Feature (1 = Stupid, 2 = Weirdo): ";
				cin >> iFeature;
			
				// Calculate the odds for this suspect
				if (iFeature == 1)
				{
					// B Jerk Stupid 
					if (iCrime == 1){
						// 12% of Cannibalism
						iOdds = 12;
					}else{
						// 22% of Robbery
						iOdds = 22;
					}
				}else{
					// B Jerk Weirdo 
					if (iCrime == 1){
						// 33% of Cannibalism
						iOdds = 33;
					}else{
						// 45% of Robbery
						iOdds = 45;
					}
				}
			}
		}
		
		// Move the temp iOdds value into the correct suspect odds variable
		if (iSuspect == 1){
			// Suspect 1
			iSuspect1Odds = iOdds;
		}else{	
			// Suspect 2
			iSuspect2Odds = iOdds;
		}
		
	} // End for-loop
	
	
	/*====================================
							MAKE A DECISION
	======================================*/
	if (iSuspect1Odds > iSuspect2Odds)
	{
		// Suspect 1 Committed the Crime 
		cout << "\n\n\n\nSuspect 1 is more likely to commit " << sCrime << ".\n";
	}
	else if (iSuspect1Odds < iSuspect2Odds) 
	{
		// Suspect 2 Committed the crime 
		cout << "\n\n\n\nSuspect 2 is more likely to commit " << sCrime << ".\n";
	}
	else if (iSuspect1Odds == iSuspect2Odds)
	{
		// Couldn't decide which suspect committed the crime
		cout << "\n\n\n\nIt looks like Suspect 1 and Suspect 2 both have the same odds for committing " << sCrime << ".\n";
	}
	else
	{
		// Something broke :(
		cout << "\n\n\n\nWhoops! Something broke in the program.\n Suspect 1's odds are not greater than, less than, or equal to Suspect 2's odds...\n :(\n";
	}
	
	// Print the odds for both suspects 
	cout << "Suspect 1: " << iSuspect1Odds << "%\n";
	cout << "Suspect 2: " << iSuspect2Odds << "%\n\n";
	
	
	cout << "Thank you for using the program, " << sName << " have a nice day!\n\n";
	
	return 0;
}