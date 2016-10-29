#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

using namespace std; 

void memoryGame ();
void numberGame ();

int main () {
	int homeAccess;
	
	cout << "============================" << endl;
	cout << "\t Memory Game" << endl;
	cout << "============================" << endl  << endl << endl;
	
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
	int number1;
	int number2;
	int square[5][5];
	int randomNumber[25];
	int counter=0;
	int random;
	int miss=0;
	char comma;
	
	// random number
	for (int i = 0; i < 25; i++) {
		randomNumber[i]= {rand()%(9-1+1)+1};
		if(counter%5==0 && counter!=0)
		cout<<endl;
		cout << randomNumber[i]<<" "; 
		counter++;
	}
	
	sleep (10);
	
	if (system("CLS")) system("clear");
	
	// square
	for (int length = 0; length < 5; length++) {
        for (int width = 0; width < 5; width++) {
            cout << "* ";
        }
        cout << endl;
    }
    
	cout<<endl;
    
    cout << "The place of the card start from upper left and moving to the right" << endl;
    cout << "Ex: 1 2 3 4 5" << endl;
	cout << "    * * * * *" << endl << endl;
    	
    //selection	
	cout << "Please insert the place of the first card." << endl;
    cin >> number1;
    
	cout << "Please insert the place of second card." << endl;
    cin >> number2;
    
    //fix
    number1--;
    number2--;
    
    //reveal
	for (int i = 0; i < 25; i++) {
		if (counter % 5 == 0 && counter != 0)
			cout<<endl;
		
		if (i == number1 || i == number2) {
			cout << randomNumber[i] << " ";
			}
		
		else cout << "* ";
		counter++;
		
		if (randomNumber[i] != randomNumber[i]) {
			miss = miss + 1;
		}
	}	
	
	cout << endl << endl;
	cout << "Miss: " << miss << endl << endl;
}

void numberGame() {
	unsigned number = time(0);
	srand (number);
	int number1;
	int number2;
	int square[5][5];
	int randomNumber[25];
	int counter=0;
	char comma;
	
		// random number
	for (int i = 0; i < 25; i++) {
		randomNumber[i]= {rand()%(9-1+1)+1};
		if(counter%5==0 && counter!=0)
		cout<<endl;
		cout << randomNumber[i]<<" "; 
		counter++;
	}
	
	sleep (10);
	
	if (system("CLS")) system("clear");
	
	// square
	for (int length = 0; length < 5; length++) {
        for (int width = 0; width < 5; width++) {
            cout << "* ";
        }
        cout << endl;
    }
    
	cout<<endl;
}
