#include<stdio.h>
void game_instructions();
void game_play(int[][3]);
int verify_position(int[][3],int);
int check_win(int[][3]);

int main()
{
	int grid[3][3];
	int i,j,p=2,ch;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			grid[i][j]=p;
		p++;
		}
	}
	game_instructions();
	printf("\n\nWant to play game, Press 1 = ");
	scanf("%d",&ch);
	if(ch==1);
		system("cls");
		
	game_play(grid);
	return 0;
}

void game_instructions()
{
	printf("It is mandatory to follow instructions\nInstructions\n1. It is a two player game\n2. Player 1 will be given '0' symbol and Player 2 will be given '1' symbol\n");
	printf("3. First chance is of Player 1\n4. Each Player will get chance alternatively\n5. Each vacant position has its number ,player has to enter vacant position number inorder to choose that position\n");
	printf("6. If a player enters an already selected position their will be an error message");
}

void game_play(int grid[3][3])
{
	int i,j,f=1,win;
	int player=1,position;
	while(f==1)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				
				printf("%d ",grid[i][j]);
			}
			printf("\n");	
		}		
			printf("\n\nEnter your position player %d =",player);
			scanf("%d",&position);
		f=verify_position(grid,position);
		if(f==1)
		{
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					if(grid[i][j]==position)
					{
						if(player==1)
						{
							grid[i][j]=0;
						}
						else
						{
							grid[i][j]=1;
						}
					}
				}
			}
		}
		else
			break;
		if(player==1)
			player=2;
		else
			player=1;
		win=check_win(grid);
		if(win==1)
			f=0;
		else
		system("cls");
	}
}

int verify_position(int grid[3][3],int position)
{
	int i,j,f=0;
	if(position>10)
	{
		printf("Invalid position !!");
		f=0;
	}
	else
	{
		
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(grid[i][j]==position)
				{
					f=1;
					break;
				}
			}
		}
		if(f==0)
			printf("OOPs position is already occupied !!!!");
	}return f;
}
int check_win(int grid[][3])
{
	int i,j,t,win=0;
	t=grid[0][0];
	if(t==grid[0][1])
	{
		if(t==grid[0][2])
		{
			printf("player %d wins",t+1);
			win=1;
		}
	}
	if(win==0)
	{
		t=grid[1][0];
		if(t==grid[1][1])
		{
			if(t==grid[1][2])
			{
				printf("player %d wins",t+1);
				win=1;
			}
		}	
	}
	
	if(win==0)
	{
		t=grid[2][0];
		if(t==grid[2][1])
		{
			if(t==grid[2][2])
			{
				printf("player %d wins",t+1);
				win=1;
			}
		}	
	}
	
	if(win==0)
	{
		t=grid[0][0];
		if(t==grid[1][0])
		{
			if(t==grid[2][0])
			{
				printf("player %d wins",t+1);
				win=1;
			}
		}	
	}
	
	if(win==0)
	{
		t=grid[0][1];
		if(t==grid[1][1])
		{
			if(t==grid[2][1])
			{
				printf("player %d wins",t+1);
				win=1;
			}
		}	
	}
	
	if(win==0)
	{
		t=grid[0][2];
		if(t==grid[1][2])
		{
			if(t==grid[2][2])
			{
				printf("player %d wins",t+1);
				win=1;
			}
		}	
	}
	
	if(win==0)
	{
		t=grid[0][0];
		if(t==grid[1][1])
		{
			if(t==grid[2][2])
			{
				printf("player %d wins",t+1);
				win=1;
			}
		}	
	}
	
	if(win==0)
	{
		t=grid[0][2];
		if(t==grid[1][1])
		{
			if(t==grid[2][0])
			{
				printf("player %d wins",t+1);
				win=1;
			}
		}	
	}
	return win;
}
