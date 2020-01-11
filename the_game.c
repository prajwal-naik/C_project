#include<stdio.h>
int the_game(char p, char c)
{
	switch (p)
	{		
		case 'R':
			if (c=='r')
				{return 2;
				break;}
			else if (c=='p')
				{return 0;
				break;}
			else
				{return 1;
				break;}
			
		case 'P':
			if (c=='p')
				{return 2;
				break;}
			else if(c=='s')
				{return 0;
				break;}
			else
				{return 1;
				break;}
			
		case 'S':
			if (c=='s')
				{return 2;
				break;}
			else if(c=='r')
				{return 1;
				break;}
			else
				{return 0;
				break;}

			
		}	
}
