#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>

using namespace std; 

void shuffle2(int [][5]);

void connectingGame() 
{
	char comma, ans = 'y';
	int r;
	int c;
	int random2[5][5];
    bool cardstatus[5][5];    
    bool gameover = false;
    int moves;
    int lv;
    int time;
    
	do
    {
        cout << "Choose the lv of difficulty you wanto to play(1-10): ";
        cin >> lv;
        while (lv > 10) {
        	cout << "Error !!!";
        	cout << string( 150, '\n' );
			cout << "Choose the lv of difficulty you wanto to play(1-10): ";
        	cin >> lv;
		}
        cout << string(150, '\n');
        
		time = 20 - lv;
		
		moves = 0;
        
        //shuffle
        shuffle2 (random2); // I think shuffling cards is better idea than shuffling base start array.
        
        sleep(time);
        cout << string(150, '\n');
}

void shuffle2(int random2[][5])
{
    int start = 0;
    
	int number[25]={1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24};
	
	for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            srand((unsigned)time(NULL));
		    int start = rand()%(25-1+1)+1;
            int point = number[j];
            number[j] = number[start];
            number[start] = point;
        }
    }
    
    for (int r = 0; r < 5; r++) // put values in cards here
    {
        for (int c = 0; c < 5; c++)
        {
            random2[r][c] = number[start];
            cout << setfill('0') << setw(2) << random2[r][c] << " ";
            start = start + 1;
        }
        cout << endl;
    }
}
