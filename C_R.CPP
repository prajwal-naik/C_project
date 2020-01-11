/*********
Project Name : "chain reaction game in C graphics"
By:	Mayur P L
	Avinash Kashyap Ratnam
	Prajwal K Naik

Description: This source code is useful for students to learn C graphics. Students may refer this
	     as ideal C graphics game. This game provides basic graphics functionality such as mouse handling,
	     and different C graphics function such as line, setcolor, setfillstyle, floodfill intx86 etc.

*********/

# include <stdio.h>
#include<iostream.h>
#include<stdlib.h>
# include <dos.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
////////////declarations////////
extern "C" void start();
extern "C" void drawOutline()  ;
extern "C" void k(int ,int ,int );
extern "C" void drawCircle();
extern "C" int check();
extern "C" void winner(int );
extern "C" void menu();
extern "C" void loading();
extern "C" void end();
////////////////////////
union REGS i, o;
int arr[10][10][2],xc,yc,c;
extern "C" int initmouse()
{
   i.x.ax = 0;
   int86(0X33,&i,&o);
   return ( o.x.ax );
}
extern "C" void showmouseptr()
{
   i.x.ax = 1;
   int86(0X33,&i,&o);
}
extern "C" void getmousepos(int *button, int *x, int *y)
{
   i.x.ax = 3;
   int86(0X33,&i,&o);

   *button = o.x.bx;
   *x = o.x.cx;
   *y = o.x.dx;
}
extern "C" void members()
{


	int _,i=1;

	while(i==1)
	{

		cleardevice();

		for(_=1;_<=500;_+=1)
		{
			setcolor(14);
			putpixel(random(640),random(500),15);
		}
		settextstyle(1,0,2);
		outtextxy(50,100,"G                                  "); sound(457);  delay(150);  nosound();
		outtextxy(50,100,"  r                                "); sound(557);  delay(150);  nosound();
		outtextxy(50,100,"    o                              "); sound(557);  delay(150);  nosound();
		outtextxy(50,100,"      u                            "); sound(557);  delay(150);  nosound();
		outtextxy(50,100,"        p                          "); sound(557);  delay(150);  nosound();
		outtextxy(50,100,"           M                       "); sound(557);  delay(150);  nosound();
		outtextxy(50,100,"              e                    "); sound(557);  delay(150);  nosound();
		outtextxy(50,100,"                m                  "); sound(557);  delay(150);  nosound();
		outtextxy(50,100,"                   b               "); sound(557);  delay(150);  nosound();
		outtextxy(50,100,"                     e             "); sound(557);  delay(150);  nosound();
		outtextxy(50,100,"   	                    r         "); sound(7);  delay(150);  nosound();
		outtextxy(50,100,"     	                    s:-"); sound(7);  delay(150);  nosound();

		setcolor(10);
		outtextxy(70,130,"1.Mayur P L");
		outtextxy(70,150,"2.Avinash Kashyap Ratnam");
		outtextxy(70,170,"3.Prajwal K Naik");

		setcolor(12);
		outtextxy(400,300,"G"); sound(427); delay(150); nosound();
		outtextxy(400,300," u"); sound(427); delay(150); nosound();
		outtextxy(400,300,"  i"); sound(427); delay(150); nosound();
		outtextxy(400,300,"   d"); sound(427); delay(150); nosound();
		outtextxy(400,300,"    e"); sound(427); delay(150); nosound();
		outtextxy(400,300,"     d"); sound(427); delay(150); nosound();
		outtextxy(400,300,"      	 B"); sound(427); delay(150); nosound();
		outtextxy(400,300,"        y:-"); sound(427); delay(150); nosound();

		setcolor(2);
		outtextxy(420,330,"GITHUB");
		delay(2000);
		i=0;
	}

	cleardevice();
}

extern "C" void help()
{


	int i;
	cleardevice();

	//textcolor(9+BLINK);
    //		textbackground(7);

	gotoxy(27,3);
	cprintf("HELP TO PLAY GAME");
	delay(350);

	gotoxy(10,5);
	cout<<"1). A Strategy game for 2 players.";
	delay(350);

	gotoxy(10,7);
	cout<<"2). The Objective of Chain Reaction is to take control of the board by eliminating your opponents  orbs\n";
	delay(350);


	gotoxy(10,10);
	cout<<"3). Playars take turns to palce their orbs in cell.";
	delay(350);

	gotoxy(10,12);
	cout<<"4). Once a cell has reached critical mass the orbs explode into the surrounding cell adding an extra orbs and claimaining the cell for the player.";
	delay(350);

	gotoxy(10,16);
	cout<<"5). A Players may only place their orbs in an blank cell or the cell that contains orbs of their own colour.";
	cout<<"As soon as player looses all their orbs they are out of the game";
	delay(350);

	//textcolor(RED +BLINK) ;
	textbackground(7);
	gotoxy(27,20);
	cout<<"PRESS ANY KEY TO CONTINUE...... ";
	getch();
	for(i=30;i>=0;i--)
	{
		delay(300);
		gotoxy(1,i);
		clreol();
		textbackground(0);
	}

	
	

}

extern "C" void exit1()
{
	int midx,midy;
	midx=getmaxx()/2;
	midy=getmaxy()/2;

	setbkcolor(CYAN);
	settextstyle(7,0,3);
	outtextxy(250,50,"THANKS");
	////////////////outside
	setcolor(4);
	setfillstyle(6,14);
	ellipse(midx,midy,0,360,170,150);
	fillellipse(midx,midy,170,150) ;
	///////eye
	setfillstyle(6,4);
	ellipse(midx-70,200,0,360,20,10);
	fillellipse(midx-70,200,20,10);
	ellipse(midx+70,200,0,360,20,10);
	fillellipse(midx+70,200,20,10);
	arc(midx,midy+20,180,360,60);          //mouth
	line(midx,midy-20,midx,midy+20);
	getch();
	
}
extern "C" void menu()
{

///////////////////menu button
	cleardevice();
	setcolor(9);
	setbkcolor(CYAN);
	setfillstyle(9,9);
	rectangle(250,50,400,100);
	floodfill(251,51,9);

	settextstyle(3,0,2);
	setcolor(11);
	outtextxy(300,65,"EXIT");

	///////////////START button
	setcolor(9);
	setbkcolor(CYAN);
	setfillstyle(9,9);
	rectangle(250,150,400,200);
	floodfill(251,151,9);

	settextstyle(3,0,2);
	setcolor(11);
	outtextxy(300,165,"START");
	/////////////help button

	setcolor(9);
	setbkcolor(CYAN);
	setfillstyle(9,9);
	rectangle(250,250,400,300);
	floodfill(251,251,9);

	settextstyle(3,0,2);
	setcolor(11);
	outtextxy(300,265,"HELP");
       ///////////////////////quit button
	setcolor(9);
	setbkcolor(CYAN);
	setfillstyle(9,9);
	rectangle(250,350,400,400);
	floodfill(251,351,9);

	settextstyle(3,0,2);
	setcolor(11);
	outtextxy(300,365,"QUIT");


/////////////////////////	//////////////////mouse event

	int button=-1,x,y;
	int status=initmouse();
	showmouseptr();
	if(status==0)
	{
		printf("sorry mouse is not supported");
		getch();
		return ;
	}

	while(!kbhit())
	{
		getmousepos(&button,&x,&y);

		if(button==1)
		{
			button=-1;
			if((x>=250&&x<=400)&&(y>=150&&y<=200))
			{

				start();
			}
			if((x>=250&&x<=400)&&(y>=50&&y<=100))
			{	closegraph();
				exit(0);
				
			}
			if((x>=250&&x<=400)&&(y>=250&&y<=300))
			{

			       help();
			       setbkcolor(BLACK);
			}

			if((x>=250&&x<=400)&&(y>=350&&y<=400))
			{

				cleardevice();

			       exit1();
			}

		}

	}
	getch();
}

/////////////////////////////////////////////////////////////////////
void start()
{
	int button,x,y,f,c=0;

	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			arr[i][j][1]=0,arr[i][j][0]=0;

	setbkcolor(BLACK);
	loading();
	cleardevice();
	drawOutline();
	if (initmouse()== 0 )
	printf("Mouse support not available.\n");
	else
	{
		drawOutline();
		showmouseptr();
		getmousepos(&button,&x,&y);
		while(!kbhit())
		{
			c++;
			k(button,x,y);
			delay(500);
			cleardevice();
			drawOutline();
			drawCircle();
			if((f=check())!=0&&c>2)
			{
				clrscr();
				cleardevice();
				winner(f);
				break;
			}
		}
	}
	menu();
 }
 void loading()
{
	char msg[33];
	clrscr();

	int gdriver=DETECT,gmode,errorcode,c1x,c2x,c3x,c4x,c5x,c6x;
	int c1y,c2y,c3y,c4y,c5y,c6y;

	initgraph (&gdriver, &gmode,"C:\\TURBOC3\\BGI");
	setfillstyle(1,8);
	outtextxy(250,250,"PLEASE WAIT......");
	setcolor(8);
	line (320-150,320-13,320+150,320-13);
	line (320-150,320+12,320+150,320+12);
	line (320-150,320-13,320-150,320+12);
	line (320+150,320+12,320+150,320-13);
	int s=30,w;
	gotoxy(20,23);
	cout<<"LOADING . . .";
	for (int x1=171,x2=171,y1=308,y2=331,y=1,S=0;x1<470;x1++,x2++,y++,S++)
	{
		setcolor(4);
		line (x1,y1,x2,y2);
		w=(x1-169)/3;
		for (int i=34; i<=78; i++)
		{
			gotoxy(i,23) ;
			cout <<" " ;
		}
		gotoxy(34,23); cout<<w<<"%";
		if (x2>270) s=45; if (x2>370) s=10;
		if (x2==320) delay(999); else
		delay(s);
		}
		delay(800);
		for (int i=27; i<=78; i++)
		{
			gotoxy(i,23) ;
			cout <<" " ;
		}

	gotoxy(28,23);
	cout<<"COMPLETE";  gotoxy(20,25);
	getch();
}
extern "C" void drawOutline()
{
	setcolor(c);
	int x=getmaxx()/10,y=getmaxy()/10;
	for(int i=0;i<getmaxx();i+=x)
	{
		for(int j=0;j<getmaxy();j+=y)
		{
			line(i,j,i,getmaxy());
			line(i,j,getmaxx(),j);
		}
	}
}
void drawCircle()
{
	int x=getmaxx()/10,y=getmaxy()/10;
	for(int m=0;m<10;m++)
	{
		for(int n=0;n<10;n++)
		{
		if(arr[m][n][0]!=0){
		setcolor(arr[m][n][0]);
		if(arr[m][n][1]==1)
		{

			circle(x*(m)+15,y*(n)+12,10);
			setfillstyle(1,arr[m][n][0]);
			floodfill(x*(m)+15,y*(n)+12,arr[m][n][0]);
		}
		else if(arr[m][n][1]==2)
		{
			circle(x*(m)+15,y*(n)+12,10);
			circle(x*(m)+45,y*(n)+12,10);
			setfillstyle(1,arr[m][n][0]);
			floodfill(x*(m)+15,y*(n)+12,arr[m][n][0]);
			floodfill(x*(m)+45,y*(n)+12,arr[m][n][0]);
		}
		else if(arr[m][n][1]==3)
		{
			circle(x*(m)+15,y*(n)+12,10);
			circle(x*(m)+45,y*(n)+12,10);
			circle(x*(m)+30,y*(n)+35,10);
			setfillstyle(1,arr[m][n][0]);
			floodfill(x*(m)+15,y*(n)+12,arr[m][n][0]);
			floodfill(x*(m)+45,y*(n)+12,arr[m][n][0]);
			floodfill(x*(m)+30,y*(n)+35,arr[m][n][0]);
		}
		}
		}
	}
}
void rec(int cx,int cy)
{

	if(((cx==0&&cy==0)||(cx==0&&cy==9)||(cx==9&&cy==0)||(cx==9&&cy==9))&&arr[cx][cy][1]>=1)
	{
		if(cx-1>=0)                        //right up corner
		{
			arr[cx][cy][1]=arr[cx][cy][0]=0;
			rec(cx-1,cy);
		}
		if(cx+1<=9)       ///left up corner
		{
			arr[cx][cy][1]=arr[cx][cy][0]=0;
			rec(cx+1,cy);
		}
		if(cy-1>=0)     ///lower
		{
			arr[cx][cy][1]=arr[cx][cy][0]=0;
			rec(cx,cy-1);
		}
		if(cy+1<=9)             //lower
		{
			arr[cx][cy][1]=arr[cx][cy][0]=0;
			rec(cx,cy+1);
		}
	}
	else if((cx==0||cx==9||cy==0||cy==9)&&arr[cx][cy][1]>=2)
	{
		if(cx-1>=0)
		{
			arr[cx][cy][1]=arr[cx][cy][0]=0;
			rec(cx-1,cy);
		}
		if(cx+1<=9)
		{
			arr[cx][cy][1]=arr[cx][cy][0]=0;
			rec(cx+1,cy);
		}
		if(cy-1>=0)
		{
			arr[cx][cy][1]=arr[cx][cy][0]=0;
			rec(cx,cy-1);
		}
		if(cy+1<=9)
		{
			arr[cx][cy][1]=arr[cx][cy][0]=0;
			rec(cx,cy+1);
		}
	}
	else if(arr[cx][cy][1]>=3)
	{
		arr[cx][cy][1]=arr[cx][cy][0]=0;
		rec(cx-1,cy);
		rec(cx+1,cy);
		rec(cx,cy-1);
		rec(cx,cy+1);
	}
	else
	{
		arr[cx][cy][1]++;
		arr[cx][cy][0]=c;
	}
}
int updatearray()
{
	if(arr[xc][yc][1]==0)
	{
		arr[xc][yc][0]=c;
		arr[xc][yc][1]++;
	}
	else
		rec(xc,yc);
	return 1;
}
int ctoarr(int cx,int cy)
{
	int x=getmaxx()/10,y=getmaxy()/10;
	for(int i=0,x1=0;i<getmaxx()-x;i+=x,x1++)
	{
		if(cx>i&&cx<i+x)
		for(int j=0,y1=0;j<getmaxy()-y;j+=y,y1++)
		{
			if(cy>j&&cy<j+y)
			{
				xc=x1;
				yc=y1;
				if(arr[xc][yc][0]==0)
					return updatearray();
				if(arr[xc][yc][0]!=c)
					return 0;
				else
					return updatearray();
			}
		}
	}
	return 1;
}
void k(int button,int x,int y)
{
	while(!kbhit())
		{
			getmousepos(&button,&x,&y);
			if( button == 1 )
			{
				button = -1;
				if(ctoarr(x,y)!=0)             //if not zero then redraw
				{
					if(c==1)
						c=2;
					else
						c=1;
				}
				return;
			}
		}
}
int check()
{
	int color=0,f=0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(f==0)
				color=f=arr[i][j][0];
			if(arr[i][j][0]!=0)
				color=arr[i][j][0];
			if(color!=f)
			{
				return 0;
			}
		}
	}
	return f;
}
void winner(int);
extern "C" int main_menu()
{
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	clrscr();
	setbkcolor(BLACK);
	cleardevice();

	help();
	cleardevice();

	menu();
	setbkcolor(BLACK);
	cleardevice();


	getch();
	closegraph();
	return 0;
}
void winner(int p)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	setbkcolor(CYAN);
	settextstyle(1,0,3);

	if(p==1)
	{
		    outtextxy((getmaxx()/2)-100,(getmaxy()/2)-50,"PLAYER ONE IS WINNER");
		    outtextxy((getmaxx()/2)-200,(getmaxy()/2),"PLAYER TWO BETTER LUCK NEXT TIME ");
	}
	if(p==2)
	{
		    outtextxy((getmaxx()/2)-100,(getmaxy()/2)-50,"PLAYER TWO IS WINNER");
		    outtextxy((getmaxx()/2)-200,(getmaxy()/2),"PLAYER ONE BETTER LUCK NEXT TIME ");
	}
	getch();
	cleardevice();
	menu();
}
