#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "connectingGame.cpp"
#include "matchingGame.cpp"

using namespace std; 

class Access {
	private:
		int homeAccess;
	
	public:
		Access(int homeAccess) {
			this -> homeAccess = homeAccess;
		}
		
		int getAccess(int homeAccess) {
			return homeAccess;
		}
		
		void setAccess(int homeAccess) {
			this -> homeAccess = homeAccess;
		}
		
		int ifAccess(int) {
			if (homeAccess > 2) {
				string error = "error";
				throw error;
				
				cout << error;
			}
			
			return homeAccess;
		}
};

int main () 
{
	int homeAccess;
	
	Access access(homeAccess);
	
	cout << "============================" << endl;
	cout << "\t Memory Game" << endl;
	cout << "============================" << endl  << endl << endl;
	
	cout << "1. Matching Game" << endl;
	cout << "2. Connecting Game" << endl << endl << endl;
	cout << "Select the Game you want to play: ";
	cin >> homeAccess;
	
	if (homeAccess == 1) {
	cout << string( 150, '\n' );
		matchingGame();
	}
	
	else if (homeAccess == 2) {
	cout << string( 150, '\n' );
		connectingGame();
	}

	try {
		access.ifAccess(access.getAccess(homeAccess)); 
	}
	
	catch(string error) {
		cout << error;
		cout << endl;
		exit (0);
	}

	return 0;
}
