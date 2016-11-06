#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

using namespace std; 

void shuffle(int random[][4])
{
    int start = 0;
    
	int number[16] = {1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8}; // the random cards
	
	srand((unsigned)time(NULL));
    
	for (int j = 0; j < 16; j++) // random 16 times
    {
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
