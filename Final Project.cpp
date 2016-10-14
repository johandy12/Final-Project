#include <iostream>
#include <string>
 
using namespace std; 

int gameStartOption (int);

int main () {
	int home1;
	int home2;
	int home3;
	int homeAccess;
	
	cout << "Memory Game";
	
	cout << endl << endl << endl;
	
	cout << "1. Matching Game" << endl;
	
	cout << "2. Number Game" << endl << endl << endl;
	
	cout << "\t Enter the number to access: ";
	cin >> homeAccess;
	
	while (homeAccess > 2) {
		cout << "\t Enter the number to access: ";
		cin >> homeAccess;
	}
	
	if (system("CLS")) system("clear");
	
	if (homeAccess = 1) {
		gameStartOption;
		memoryGame;
	}
	
	else (homeAccess = 2) {
		gameStartOption;
		numberGame;
	}

	return 0;
}

int gameStartOption (int lv) {
	cout << "Choose the lv of difficulty you want to play (1-10): ";
	cin >> lv;
	
	while (lv> 10) {
		cout << "Choose the lv of difficulty you want to play (1-10): ";
		cin >> lv;
	}
	return lv;
}

int memoryGame () {
	// square
	for (int length = 0; length < area; length++) {
        for (int width = 0; width < area; width++) {
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<endl;
}
