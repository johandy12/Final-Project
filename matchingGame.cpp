#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include "shuffle.cpp"

using namespace std; 

void shuffle(int [][4]);

void matchingGame() 
{
	char comma;
	char ans = 'y';
    int r1;
	int c1;
	int r2;
	int c2;
	int random[4][4];
    bool randomStatus[4][4];   
    bool gameOver = false;
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
        
        // call shufle
        shuffle (random);
        
        sleep(time);
        cout << string(150, '\n');
        
		// display *
        cout << endl;
        for (int r = 0; r < 4; r++)
        {
            for (int c = 0; c < 4; c++)
            {
                cout << "* ";
                randomStatus[r][c] = false;
            }
            cout << endl;
        }
        
		do //game start
        {
            do
            {
                //selection
                cout << "Please insert the first card row and column seperated by comma: ";
                cin >> r1 >> comma >> c1;
                
				if(randomStatus[r1-1][c1-1] == true) //-1 because array usually start from 0
                { 
                    cout << "This card is already flipped! Select another card." << endl;
                }
            }
			while (randomStatus[r1-1][c1-1] != false);
            
			do
            {
                cout <<"Please insert the second card row and column separated by comma: ";
                cin >> r2 >> comma >> c2;
                if(randomStatus[r2-1][c2-1] == true)
                { 
                    cout << "This card is already flipped! Select another card." << endl;
                }
            }
			while(randomStatus[r2-1][c2-1] != false);
            
			// fix
            r1--;
            c1--;
            r2--;
            c2--;
            
			// to show * cards
            for (int r = 0; r < 4; r++)
            {
                for (int c = 0; c < 4; c++)
                {
                    if ((r == r1) && (c == c1))
                    {
                        cout << random[r][c] << " ";
                    }
                   
				    else if((r == r2) && (c == c2))
                    {
                        cout << random[r][c] << " ";
                    }
                    
					else
                    {
                        cout << "* ";
                    }
				}
                cout << endl;
            }                        
            
			// matching the number
            if (random[r1][c1] == random[r2][c2]) //if cards match, keep them flipped
            {
                randomStatus[r1][c1] = true;                             
                randomStatus[r2][c2] = true;                            
            }
            
			cin.get();
            cin.get();
            
			cout << string(150, '\n');
                
            for (int r = 0; r < 4; r++) //to show new board
            {
                for (int c = 0; c < 4; c++)
                {                
                    if (randomStatus[r][c] == true)
                    {
                        cout << random[r][c] << " ";
                    }
                    else
                    {
                        cout << "* ";
                    }
                }
                cout << endl;
            }            
            
            gameOver = true;
            for (int r = 0; r < 4; r++) // if all card is flipped the game is over, else continue
            {
                for (int c = 0; c < 4; c++)
                {
                    if(randomStatus[r][c]==false)
                    {
                      gameOver = false;
                      break;
                    }
                }
                
				if(gameOver == false)
                {
                    break;
                }
            }
            moves++;
            // repeat the game
        }
		
		while(gameOver != true); // repeat until the game is finished
        cout << "Total: " << moves << " moves"<<endl<<endl;
        
        cout << "Game Over" << endl << endl << endl;
        
		cout << "Would you like to play again? (y=Yes/n=No) : ";
        ans = cin.get();
    }
	while(ans == 'y' || ans == 'Y'); // to play again
    cin.get();	
}
