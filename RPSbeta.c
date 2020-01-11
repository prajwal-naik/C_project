#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>





int the_game(char p, char c, int *comp_score, int *user_score)
{
	switch (p)
	{		
		case 'R':
			if (c=='R')
				{return 2;
				break;}
			else if (c=='P')
				{(*comp_score)++;
				return 0;
				break;}
			else if(c=='S')
				{(*user_score)++;
				return 1;
				break;}
			
		case 'P':
			if (c=='P')
				{return 2;
				break;}
			else if(c=='S')
				{(*comp_score)++;
				return 0;				
				break;}
			else if(c=='R')
				{(*user_score)++;
				return 1;				
				break;}
				
		case 'S':
			if (c=='S')
				{return 2;
				break;}
			else if(c=='R')
				{(*comp_score)++;
				return 0;				
				break;}
			else if(c=='P')
				{(*user_score)++;
				return 1;				
				break;}

			
		}	
}




int main()
{
	char p, c, r;
	int cchoice, flag, result;
	int user_score=0, comp_score=0;
	char name[100];
	char u_score[100];
	char c_score[100];
		
	time_t t;
	srand((unsigned)time(&t));
	do
	{
	play:	
		
		printf("Enter your choice:\n'r' for rock\n'p' for paper\n's' for scissor\n");
		fflush(stdin);
		p=getchar();
		
		
		if (p >= 'a' && p <= 'z') 
	        	p = p - 32;
	        if(p!='R'&&p!='P'&&p!='S')
	        {
	        	printf("Invalid input. Try again.\n");
	        	goto play;
	        }
	         
		cchoice = rand()%3+1;
		if (cchoice==1)	
			c='r';
		else 
		if (cchoice==2)
			c='p';
		else
			c='s';
		
		if (c >= 'a' && c <= 'z') 
	        	c = c - 32;
	        
		printf("You chose %c\n", p);
		printf("Computer chooses %c\n", c);
		result=the_game(p,c, &comp_score, &user_score); 	
		if(result==2)
			printf("DRAW !\n");
		else if(result==0)
			printf("LOSER !\n");
		else if(result==1)
			printf("WINNER !\n");
		printf("Your score : %d\n", user_score);
		printf("Computer's score: %d\n", comp_score);

	play_again:
		printf("Play again ?\n y: YES\n n: NO\n");
		fflush(stdin);
		r=getchar();	
		if (r >= 'a' && r <= 'z') 
		    r = r - 32;
	    	if(r!='Y'&& r!='N')
	        {
	        	printf("Invalid input. Try again.\n");
	        	goto play_again;
	        }
	    	else if(r=='Y')
	    		flag=1;
	    	else if( r=='N')
	    		flag=0;
	    	


    }
    while(flag==1);
    printf("Thank you for playing\n");
    printf("Please enter your name for score\n");
    fflush(stdin);
    scanf("%[^\n]s", name);
    FILE *fp=fopen("highscores.txt", "a");
    fputs("\n", fp);
    fputs(name, fp);
    fputs("	  - 	", fp);
    fputs(itoa(user_score, u_score, 10), fp);
    fputs("   ;   ", fp);
    fputs("Computer", fp);
    fputs("	-	", fp);
    fputs(itoa(comp_score, u_score, 10), fp);
    
    fclose(fp);
    FILE *fp1=fopen("highscores.txt", "r");
    char scores[1000];
    while(!feof(fp))
    {
    	printf("%s", fgets(scores, 1000, fp));
    	printf("\n");
    } 
    printf("\nPress any key to exit");
    getch();
    
    	
	
	fclose(fp1);	
	
	return 0;
}
	
