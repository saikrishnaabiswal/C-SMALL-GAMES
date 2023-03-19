#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
char board[3][3];
const char player = 'X';
const char comp = 'O';
void resetboard();
void printboard();
int check();
void play1();
void comp1();
char checckwinner();
void winner(char);


int main()
{
	char winn =' ';
	
	resetboard();
	while(winn == ' ' && check() != 0)
	{
	printboard();
	play1();
	winn =checckwinner();
	if(winn!= ' '|| check()==0)
	{
		break;
	}
	comp1();
	winn =checckwinner();
	if(winn!= ' '|| check()==0)
	{
		break;
	}
	}
	printboard();
	winner(winn);

	return 0;
}
void resetboard()
{
	for(int i =0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			board[i][j]=' ';
		}
	}
	
}
void printboard()
{
 	printf(" %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
	printf("\n---|---|---\n");	
	printf(" %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
	printf("\n---|---|---\n");
	printf(" %c | %c | %c ",board[2][0],board[2][1],board[2][2]);
	printf("\n");
}
int check()
{
	int free = 9;
	for(int i =0;i<3;i++)
	{
		for(int j =0;j<3;j++)
	{
	    if( board[i][j] != ' ')	
	    {
	    	free--;
		}
	}	
	}
	return free; 
}
void play1()
{
		int x,y;
do
{
	
	printf("Enter row number (1-3)\n");
	scanf("%d",&x);
	x--;
	printf("Enter column number (1-3)\n");
	scanf("%d",&y);
	y--;
	if(board[x][y]!=' ')
	{ 
	printf("invalid  move!");
	}
	else
	{
		board[x][y]=player;
		break;
	}
}while(board [x][y]!= ' ');
}
void comp1()
{
	srand(time(0));
	int x,y;
	if(check()>0)
	{
		do
		{
			x=rand()%3;
			y=rand()%3;
		}while(board[x][y] != ' ');
		board[x][y] = comp;
	}
	else
	  winner(' ');
}
char checckwinner()
{
	for(int i=0;i<3;i++)
	{
		if(board[i][0] == board[i][1] && board[i][0]==board[i][2])
		{
			return board[i][0];
		}
	}
	for(int i=0;i<3;i++)
	{
		if(board[0][i] == board[1][i] && board[0][i]==board[2][i])
		{
			return board[0][i];
		}
	}
	if(board[0][0] == board[1][1] && board[0][0]==board[2][2])
		{
			return board[0][0];
		}
	if(board[0][2] == board[1][1] && board[0][2]==board[2][0])
		{
			return board[0][2];
		}
		return ' ';
}
void winner(char winner)
{
	if(winner == player)
	{
		printf("you win!");
		
	}
	else if(winner == comp)
	{
		printf("you lose!");
	}
	else
	printf("its a draw!");
}