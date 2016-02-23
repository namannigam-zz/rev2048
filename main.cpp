#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#define ui unsigned int
#define MAX_DIMENSION 4 //Dimension of the grid could be an input from the user.

using namespace std;

unsigned int game_grid[MAX_DIMENSION][MAX_DIMENSION]={2,2,2,2,
                                                      16,32,64,64,
                                                      2048,512,0,2048,
                                                      512,0,1024,1024};

//List of functions to be used during entire code
void movedown();
void moveup();
void moveright();
void moveleft();
void print_grid();
void instructions();
bool isPlayable();
int myrandom (int i) { return rand()%i;} //Generate random numbers effectively
//Global variables

int main()
{
    instructions();//Instructions to play
    print_grid(); //Starting point of the game
    int move_count=0;
    //Game in Progress
    while(true)
    {
        //Get the direction to make the move
        char ch;
        switch(ch=getch())
        {
            case 'W' : case 'w' :
                movedown();
                break;
            case 'S' : case 's' :
                moveup();
                break;
            case 'A' : case 'a' :
                moveright();
                break;
            case 'D' : case 'd' :
                moveleft();
                break;
            default :
               continue;
        }
        if(isPlayable())
            {
                move_count++;
                cout<<"=========================================================================\n";
                print_grid();
                cout<<"Current Move Count :"<<move_count<<"\n";
                continue;
            }
        else
			{cout<<"Total Moves :"<<move_count<<"\n"; break;}
    }

    return 0;
}


/*Print the grid at any step of the game.*/
void print_grid()
{
    int i,j;
    for(i=0;i<MAX_DIMENSION;i++)
        {
            cout<<"                           ";
            for(j=0;j<MAX_DIMENSION;j++)
                {
                    //Conditions to convert into a 4 digit display for each digit
                    if((game_grid[i][j]<10)&&(game_grid[i][j])) cout<<"000"<<game_grid[i][j]<<"  ";
                    else if((game_grid[i][j]<100)&&(game_grid[i][j])) cout<<"00"<<game_grid[i][j]<<"  ";
                    else if((game_grid[i][j]<1000)&&(game_grid[i][j])) cout<<"0"<<game_grid[i][j]<<"  ";
                    else if(game_grid[i][j]==(0)) cout<<"____  ";
                    else cout<<game_grid[i][j]<<"  ";
                }
            cout<<"\n";
        }
}



void movedown()
{
int i,j,k;
	for(j=0;j<MAX_DIMENSION;j++)
    {
        for(i=MAX_DIMENSION-1;i>=0;i--)
        {
            if(game_grid[i][j]==0)
                continue; //Unless a value is encountered
            for(k=i-1;k>=0;k--)
            {
                if(game_grid[k][j]==0)
                    continue; //Again a value is encountered
                if(game_grid[k][j] == game_grid[i][j]) //Merging the values
                {
                    game_grid[i][j] /= 2;
                    game_grid[k][j] = 0;
                    i = k;
                }
                break;
            }
        }
	}

	for(j=0;j<MAX_DIMENSION;j++)
    {
		for(i=MAX_DIMENSION-1;i>=0;i--)
		{
			if(game_grid[i][j]!=0)
                continue; //Unless a 0 is encountered
			for(k=i-1;k>=0;k--)
            {
                if(game_grid[k][j]== 0)
                    continue; //Unless a value is encountered
                else
				{
				    game_grid[i][j]=game_grid[k][j];
                    game_grid[k][j]=0;
                    i=k;
                }
            }
		}
	}

}
void moveup()
{
    int i,j,k;
	for(j=0;j<MAX_DIMENSION;j++)
    {
        for(i=0;i<=MAX_DIMENSION-1;i++)
        {
            if(game_grid[i][j]==0)
                continue; //Unless a value is encountered
            for(k=i+1;k<=MAX_DIMENSION-1;k++)
            {
                if(game_grid[k][j]==0)
                    continue; //Again a value is encountered
                if(game_grid[k][j] == game_grid[i][j]) //Merging the values
                {
                    game_grid[i][j] /= 2;
                    game_grid[k][j] = 0;
                    i = k;
                }
                break;
            }
        }
	}

	for(j=0;j<MAX_DIMENSION;j++)
    {
		for(i=0;i<=MAX_DIMENSION-1;i++)
		{
			if(game_grid[i][j]!=0)
                continue; //Unless a 0 is encountered
			for(k=i+1;k<=MAX_DIMENSION-1;k++)
            {
                if(game_grid[k][j]== 0)
                    continue; //Unless a value is encountered
                else
				{
				    game_grid[i][j]=game_grid[k][j];
                    game_grid[k][j]=0;
                    i=k;
                }
            }
		}
	}
}

void moveleft()
{
    int i,j,k;
	for(i=0;i<MAX_DIMENSION;i++)
    {
        for(j=0;j<=MAX_DIMENSION-1;j++)
        {
            if(game_grid[i][j]==0)
                continue; //Unless a value is encountered
            for(k=j+1;k<=MAX_DIMENSION-1;k++)
            {
                if(game_grid[i][k]==0)
                    continue; //Again a value is encountered
                if(game_grid[i][k] == game_grid[i][j]) //Merging the values
                {
                    game_grid[i][j] /= 2;
                    game_grid[i][k] = 0;
                    j = k;
                }
                break;
            }
        }
	}

	for(i=0;i<MAX_DIMENSION;i++)
    {
		for(j=0;j<=MAX_DIMENSION-1;j++)
		{
			if(game_grid[i][j]!=0)
                continue; //Unless a 0 is encountered
			for(k=j+1;k<=MAX_DIMENSION-1;k++)
            {
                if(game_grid[i][k]== 0)
                    continue; //Unless a value is encountered
                else
				{
				    game_grid[i][j]=game_grid[i][k];
                    game_grid[i][k]=0;
                    j=k;
                }
            }
		}
	}
}

void moveright()
{
    int i,j,k;
	for(i=0;i<MAX_DIMENSION;i++)
    {
        for(j=MAX_DIMENSION-1;j>=0;j--)
        {
            if(game_grid[i][j]==0)
                continue; //Unless a value is encountered
            for(k=j-1;k>=0;k--)
            {
                if(game_grid[i][k]==0)
                    continue; //Again a value is encountered
                if(game_grid[i][k] == game_grid[i][j]) //Merging the values
                {
                    game_grid[i][j] /= 2;
                    game_grid[i][k] = 0;
                    j = k;
                }
                break;
            }
        }
	}

	for(i=0;i<MAX_DIMENSION;i++)
    {
		for(j=MAX_DIMENSION-1;j>=0;j--)
		{
			if(game_grid[i][j]!=0)
                continue; //Unless a 0 is encountered
			for(k=j-1;k>=0;k--)
            {
                if(game_grid[i][k]== 0)
                    continue; //Unless a value is encountered
                else
				{
				    game_grid[i][j]=game_grid[i][k];
                    game_grid[i][k]=0;
                    j=k;
                }
            }
		}
	}
}

void instructions()
{
    cout<<"===========================Instructions==================================\n";
    cout<<"        Press the A-D-W-S keys to play the game.\n";
    cout<<"   Reduce the highest element in the grid to 1 to make it disappear.   \n";
    cout<<"Score as much as possible while halving similar number by striking them.\n";
    cout<<"=========================================================================\n";
}

bool isPlayable()
{
    int i,j;
    bool flag=false;
    for(i=0;i<MAX_DIMENSION;i++)
        {
            for(j=0;j<MAX_DIMENSION;j++)
                {
                    if(game_grid[i][j]==0)
                        {flag=true;break;}
                    else
                        {flag=false;continue;}
                }
            if(flag)  break;
        }
    if(!(flag))
    {
        for(i=0;i<MAX_DIMENSION-1;i++)
        {
            for(j=0;j<MAX_DIMENSION-1;j++)
            {
                if((game_grid[i][j]==game_grid[i][j+1])||(game_grid[i][j]==game_grid[i+1][j]))
                {flag=true; break;}
            }
            if(flag) break;
        }
        if((game_grid[MAX_DIMENSION-1][MAX_DIMENSION-1]==game_grid[MAX_DIMENSION-2][MAX_DIMENSION-1]) || (game_grid[MAX_DIMENSION-1][MAX_DIMENSION-1]==game_grid[MAX_DIMENSION-1][MAX_DIMENSION-2]))
            flag=true;
    }
    return flag;
}

/* Challenges Faced
1. Merging along with Movement.
2. Generating a random new number in any of the empty cell.
3. Playable grid for all cases.
*/


/*
int NoSpaceAvailable(void)
{
	int i = 0;
	int allFill = 1;

	for(i = 0, allFill = 1; i < GAMESIZE && allFill; ++i){
		if(Tiles[i] == 0){
			allFill = 0;
		}
	}

	return allFill;
}

int SpaceAvailable(void)
{
	return !NoSpaceAvailable();
}

int NextStep(void)
{
	int random_loc = 0;
	int got_what_we_need = 1;
	// init random numbers generation seed

	if(NoSpaceAvailable()) return 0;

	srand(time(NULL));


	for(got_what_we_need = 1; got_what_we_need; got_what_we_need = 0 ){
		random_loc = rand() % GAMESIZE;
		if(Tiles[random_loc] == 0){
			Tiles[random_loc] = 2;
			got_what_we_need = 1;
		}
	}
	return 1; // yes, we got what we need.
}
================================================================
void MergeRight(void)
{
	int i = 0;
	int j = 0;
	int k = 0;

	for(i = 0; i < D; ++i){
		for(j = 4*i + D-1; j > 4*i; --j){
			if(Tiles[j]==0) continue;
			for(k = j-1; k >= 4*i; --k){
				if(Tiles[k]==0) continue;
				if(Tiles[k] == Tiles[j]){
					Tiles[j] *= 2;
					Tiles[k] = 0;
					j = k;
				}
				break;
			}
		}
	}

}
void ShiftRight(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	// most eligible space
	int mes = 0;

	for(i = 0; i < D; ++i){
		mes = 4*i + D-1;
		for(j = mes; j > 4*i; --j){
			if(Tiles[j] != 0) continue;

			for(k = j-1; k >= 4*i; --k){
				if(Tiles[k] != 0) break;
			}
			if(k >= 4*i && Tiles[k] != 0){ // put k >= 0 and boom, bad logic
				Tiles[j] = Tiles[k];
				Tiles[k] = 0;
			}
		}
	}
}
===================================================================
void MergeLeft(void)
{
	int i = 0;
	int j = 0;
	int k = 0;

	for(i = 0; i < D; ++i){
		for(j = 4*i; j < 4*i + D-1; ++j){
			if(Tiles[j] == 0) continue;
			for(k = j+1; k <= 4*i + D-1; ++k){
				if(Tiles[k] == 0) continue;
				if(Tiles[j] == Tiles[k]){
					Tiles[j] *= 2;
					Tiles[k] = 0;
					j = k;
				}
				break;
			}
		}
	}

}
void ShiftLeft(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	// most eligible space
	int mes = 0;

	for(i = 0; i < D; ++i)
    {
		mes = 4*i + 0;
		for(j = mes; j < 4*i + D-1; ++j)
        {
			if(Tiles[j] != 0) continue;

			for(k = j+1; k <= 4*i+D-1; ++k)
                {
                    if(Tiles[k] != 0) break;
                }
			if(k <= 4*i+D-1 && Tiles[k] != 0)
			{ // put k >= 0 and boom, bad logic
				Tiles[j] = Tiles[k];
				Tiles[k] = 0;
			}
		}
	}
}
===================================================================
void MergeDown(void)
{
	int i = 0;
	int j = 0;
	int k = 0;

	for(i = 0; i < D; ++i){
		for(j = D*(D-1) + i; j > i; j -= D){
			if(Tiles[j] == 0) continue;
			for(k = j - D; k >= i; k -= D){
				if(Tiles[k] == 0) continue;
				if(Tiles[j] == Tiles[k]){
					Tiles[j] *= 2;
					Tiles[k] = 0;
					j = k;
				}
				break;
			}
		}
	}
}

void ShiftDown(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	// most eligible space
	int mes = 0;

	for(i = 0; i < D; ++i){
		mes = i + D*(D-1);
		for(j = mes; j >  i; j-=4){
			if(Tiles[j] != 0) continue;

			for(k = j-4; k >= i; k-=4){
				if(Tiles[k] != 0) break;
			}
			if(k >= i && Tiles[k] != 0){ // put k >= 0 and boom, bad logic
				Tiles[j] = Tiles[k];
				Tiles[k] = 0;
			}
		}
	}
}
===========================================================================
void MergeUp(void)
{
	int i = 0;
	int j = 0;
	int k = 0;

	for(i = 0; i < D; ++i){
		for(j = i; j < D*(D-1) + i; j += D){
			if(Tiles[j] == 0) continue;
			for(k = j + D; k <= D*(D-1) + i; k += D){
				if(Tiles[k] == 0) continue;
				if(Tiles[j] == Tiles[k]){
					Tiles[j] *= 2;
					Tiles[k] = 0;
					j = k;
				}
				break;
			}
		}
	}


}
void ShiftUp(void)
{
	int i = 0;
	int j = 0;
	int k = 0;

	for(i = 0; i < D; ++i){
		for(j = i; j < D*(D-1) + i; j += 4){
			if(Tiles[j] != 0) continue;
			for(k = j+4; k <= D*(D-1)+i; k += 4){
				if(Tiles[k] != 0) break;
			}
			if(k <= D*(D-1)+i && Tiles[k]!= 0){
				Tiles[j] = Tiles[k];
				Tiles[k] = 0;
			}
		}
	}
}
=============================================================
void PrintTiles()
{
	int i = D, j = D;
	int val = 0, pair = 0;
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);

	for(i = 0; i < D; ++i){
		for(j = 0; j < D; ++j){
			val = Tiles[D*i+j];
			pair = 0;
			if(val >= 512){
				pair = 2;
			} else if(val >= 32){
				pair = 1;
			}
			if(pair)
			attron(COLOR_PAIR(pair));
			printf("%6d", val);
			if(pair)
			attroff(COLOR_PAIR(pair));

		}
		printf("\n\n");
	}
}

*/
