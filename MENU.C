#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<graphics.h>
void get_choice(char*);
void menu_main();
char choice;
int main()
{	int gd = DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	clrscr();
	setbkcolor(BLACK);
	cleardevice();
	members();
	cleardevice();
	closegraph();
	clrscr();
	menu_main();
	return 0;
}
void get_choice(char *p)
{
	scanf("%c",p);
}
void menu_main()
{
	clrscr();

	printf("The following are the games available:\n1: Tic Tac Toe\n2: Rock Paper Scissors\n3: Chain Reaction\n4: Exit\nEnter the required choice\n");
	get_choice(&choice);
	switch(choice)
	{
		case '1':game();menu_main();break;
		case '2':main_rps();menu_main();break;
		case '3':main_menu();menu_main();break;
		case '4':exit(0);break;
		default:printf("Invalid Choice");delay(800);menu_main();
	}
}