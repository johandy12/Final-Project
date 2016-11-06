#include <iostream>
#include "Access.hpp"
#include "matchingGame.cpp"

using namespace std; 

int main () 
{
	int homeAccess;
	
	Access access(homeAccess);
	
	cout << "============================" << endl;
	cout << "\t Memory Game" << endl;
	cout << "============================" << endl  << endl << endl;
	
	cout << "Matching Game" << endl << endl << endl;
	cout << "Press 1 to play the game. " << endl;
	cin >> homeAccess;
	
	if (homeAccess == 1) 
	{
	cout << string( 150, '\n' );
		matchingGame();
	}

	try 
	{
		access.ifAccess(access.getAccess(homeAccess)); 
	}
	
	catch(string error) 
	{
		cout << error;
		cout << endl;
		exit (0);
	}

	return 0;
}
