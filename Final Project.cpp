#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std; 

void memoryGame ();
void numberGame ();

int main () {
	int homeAccess;
	
	cout << "============================" << endl;
	cout << "\t Memory Game" << endl;
	cout << "============================" << endl  << endl << endl << endl;
	
	cout << "1. Matching Game" << endl;
	cout << "2. Number Game" << endl << endl << endl;
	cout << "Select the Game you want to play: ";
	cin >> homeAccess;
	
	while (homeAccess > 2) {
		cout << "Select the Game you want to play: ";
		cin >> homeAccess;
	}
	
	if (system("CLS")) system("clear");
	
	if (homeAccess = 1) {
		memoryGame();
	}
	
	else if (homeAccess = 2) {
		numberGame();
	}

	return 0;
}

void memoryGame() {
	unsigned number = time(0);
	srand (number);
	int row1;
	int column1;
	int row2;
	int column2;
	int lv;
	int area;
	int square[area][area];
	char comma;
	
	cout << "Choose the lv of difficulty you want to play (1-10): ";
	cin >> lv;
	
	while (lv> 10) {
		cout << "Choose the lv of difficulty you want to play (1-10): ";
		cin >> lv;
	}
	
	area = lv + 3;
	
	// random number
	for (int length = 0; length < area; length++) {
        for (int width = 0; width < area; width++) {
            square[length][width] = (rand()%(9-1+1))+1;
            cout << square[length][width];
        }
        cout<<endl;
    }
	
	// square
	for (int length = 0; length < area; length++) {
        for (int width = 0; width < area; width++) {
            cout << "*";
        }
        cout << endl;
    }
    
	cout<<endl;
    
    //selection
    cout << "Please insert the first card row and column seperated by a comma." << endl;
    cin >> row1 >> comma >> column1;
    cout << "Please insert the second card row and column seperated by a comma." << endl;
    cin >> row2 >> comma >> column2;
    
    //fix
    row1--;
    column1--;
    row2--;
    column2--;
    
    for (int length = 0; length < area; length++) {
        for (int width = 0; width < area; width++) {
            if ((length == row1) && (width == column1)) {
                cout << square[area][area] << " ";
            }
            
            else if((length == row2) && (width == column2)) {
                cout << square[area][area] << " ";
            }
            
            else {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

void numberGame() {
	unsigned number = time(0);
	srand (number);
	int row;
	int column;
	int lv;
	int area;
	int square[area][area];
	char comma;
	
	cout << "Choose the lv of difficulty you want to play (1-10): ";
	cin >> lv;
	
	while (lv> 10) {
		cout << "Choose the lv of difficulty you want to play (1-10): ";
		cin >> lv;
	}
	
	area = lv + 3;
	
    //selection
    cout << "Please insert the card row and column seperated by a comma." << endl;
    cin >> row >> comma >> column;
    
    //fix
    row--;
    column--;
}
