#include<stdio.h>
#include<windows.h>
#include<conio.h>

#define ROW 9
#define COL 12

char map[ROW][COL]={
	{"*#*********"},
	{"***###*###*"},
	{"###**#****#"},
	{"*#**###**#*"},
	{"***********"},
	{"#####*##*##"},
	{"**#*****#*E"},
	{"***#*###**#"},
	{"*#*********"},
};

void print_map()
{
	int i;
	for(i=0;i<ROW;i++)
	{
		puts(map[i]);
	}
}

void show_yiran(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	printf("curX=%d,curY=%d\n",x,y);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int curX,curY;
void main()
{
	while(1)
	{
		system("cls");
		print_map();
		show_yiran(curX,curY);

		char t=getch();
		if(t=='w')
		{
			if((curY-1>=0&&map[curY-1][curX]=='*'||map[curY-1][curX]=='E'))
				curY--;
		}
		if(t=='s')
		{
			if((curY-1)>=0&&(map[curY-1][curX=='*']||map[curY-1][curX]=='E'))
			    curY++;
		}
		if(t=='a')
		{
		    if((curX-1)>=0&&(map[curY][curX-1]=='*'||map[curY][curX-1]=='E'))
			    curX++;
		}
	    if(t=='d')
		{
		    if((curX+1)<COL&&(map[curY][curX+1]=='*'||map[curY][curX+1]=='E'))
			    curX++;
		}
    	if(map[curY][curX]=='E')
		{
		printf("\n");
		printf("恭喜你成功通关！");
		printf("\n");
		break;
		}
	}
}