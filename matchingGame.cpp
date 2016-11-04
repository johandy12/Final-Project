#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

using namespace std; 

void shuffle(int [][4]);

void matchingGame() 
{
	char comma, ans = 'y';
    int r1;
	int c1;
	int r2;
	int c2;
	int random[4][4];
    bool cardstatus[4][4];   
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
        shuffle (random); // for shuffling
        
        sleep(time);
        cout << string(150, '\n');
        
		//display *
        cout << endl;
        for (int r = 0; r < 4; r++)
        {
            for (int c = 0; c < 4; c++)
            {
                cout << "* ";
            }
            cout << endl;
        }
        
		do //game start
        {
            do
            {
                //selection
                cout << "Please insert the first card row and column seperated by a comma: ";
                cin >> r1 >> comma >> c1;
                
				if(cardstatus[r1-1][c1-1] == true)
                { 
                    cout << "This card is already flipped! Select another card." << endl;
                }
            }
			while(cardstatus[r1-1][c1-1]!= false);
            
			do
            {
                cout <<"Please insert the second card row and column separated by a comma: ";
                cin >> r2 >> comma >> c2;
                if(cardstatus[r2-1][c2-1] == true)
                { 
                    cout << "This card is already flipped! Select another card." << endl;
                }
                if((r1 == r2) && (c1 == c2))
                {
                    cout << "You can't select same card twice!";
                    continue;
                }
            }
			while(cardstatus[r2-1][c2-1]!= false);
            
			//fix
            r1--;
            c1--;
            r2--;
            c2--;
            
			//to show * cards
            cout<<endl;
            for (int r = 0; r < 4; r++)
            {
                for (int c=0; c<4; c++)
                {
                    if ((r==r1)&&(c==c1))
                    {
                        cout << random[r][c]<<" ";
                    }
                    else if((r==r2)&&(c==c2))
                    {
                        cout << random[r][c]<<" ";
                    }
                    else if (cardstatus[r][c] == true)
                    {
                        cout << random[r][c]<<" ";
                    }
                    else
                    {
                        cout<<"* ";
                    }
                }
                cout<<endl;
            }                        
            
			//matching the number
            if (random[r1][c1] == random[r2][c2]) //if cards match, keep them flipped
            {
                cardstatus[r1][c1] = true;                             
                cardstatus[r2][c2] = true;                            
            }
            
			cin.get();
            cin.get();
            
			cout << string(150, '\n');
                
            for (int r = 0; r < 4; r++) //to show new board
            {
                for (int c = 0; c < 4; c++)
                {                
                    if (cardstatus[r][c] == true)
                    {
                        cout << random[r][c]<<" ";
                    }
                    else
                    {
                        cout<<"* ";
                    }
                }
                cout<<endl;
            }            
            
            gameover = true;
            for (int r = 0; r < 4; r++) //if all card is flipped the game is over, else continue
            {
                for (int c = 0; c < 4; c++)
                {
                    if(cardstatus[r][c]==false)
                    {
                      gameover = false;
                      break;
                    }
                }
                
				if(gameover == false)
                {
                    break;
                }
            }
            moves++;
            //repeat the game
        }
		while(gameover != true); //repeat until the game is finished
        cout << "Total: " << moves << " moves"<<endl<<endl;
        
		cout << "Would you like to play again? (y=Yes/n=No) : ";
        ans = cin.get();
    }
	while(ans == 'y' || ans == 'Y'); //to play again
    cin.get();	
}

void shuffle(int random[][4])
{
    int start = 0;
    
	int number[16]={1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8};//the random cards
	
    for (int j = 0; j < 16; j++)// random 16 times
    {
    	srand((unsigned)time(NULL));
		int start = rand()%(15-1+1)+1;
        int point = number[j];
        number[j] = number[start];
        number[start] = point;
    }
    
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            random[i][j] = number[start];
            cout << random[i][j];
            start = start + 1;
        }
        cout << endl;
    }
}
