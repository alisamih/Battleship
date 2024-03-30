#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include <MMsystem.h>
#include "CC212VSGL.h"
#pragma comment(lib, "cc212vsgl.lib")
#pragma comment(lib,"Winmm.lib")



int toString(char a[]);
void drawn()//game name
{
	int x = CC212VSGL::getWindowWidth() / 2, y = CC212VSGL::getWindowHeight();
	CC212VSGL::beginDraw();
	CC212VSGL::setDrawingThickness(3);
	CC212VSGL::setDrawingColor(RED);
	CC212VSGL::drawText(x - 50, y - 28, "- Battleship Game -");
	CC212VSGL::drawRectangle(x -673, y -780 , 700, 450);
	CC212VSGL::drawRectangle(x-70 , y-35, 145, 30);
	CC212VSGL::drawText(x - 100, y - 50, "P1,Please place your H ships");
	//CC212VSGL::drawText(x - 667, y - 720, "1 2");
	CC212VSGL::drawText(x - 673, y - 250, "Enter coord for horizontal ship x axis");
    //CC212VSGL::drawSolidCircle(x + 163, y / 2 + 204, 50);
	//CC212VSGL::drawSolidCircle(x + 188, y / 2 + 247, 50);
	//CC212VSGL::drawSolidCircle(x + 138, y / 2 + 247, 50);
	//CC212VSGL::drawSolidCircle(x + 113, y / 2 + 290, 50);
	//CC212VSGL::drawSolidCircle(x + 163, y / 2 + 290, 50);
	//CC212VSGL::drawSolidCircle(x + 213, y / 2 + 290, 50);
	//CC212VSGL::drawSolidCircle(x + 88, y / 2 + 333, 50);
	//CC212VSGL::drawSolidCircle(x + 238, y / 2 + 333, 50);
	//CC212VSGL::drawSolidCircle(x + 138, y / 2 + 333, 50);
	//CC212VSGL::drawSolidCircle(x + 188, y / 2 + 333, 50);
	//CC212VSGL::setDrawingThickness(5);
	//CC212VSGL::drawLine(x + 560, y / 2 + 235, x + 600, y / 2 + 240);
	//CC212VSGL::drawSolidCircle(x + 545, y / 2 + 220, 25);
	//CC212VSGL::drawSolidCircle(x + 300, y / 2 + 307, 75);
    //CC212VSGL::drawSolidCircle(x + 575, y / 2 + 307, 75);
	//CC212VSGL::drawSolidRectangle(x + 280, y / 2 + 250, 400, 70);
	//CC212VSGL::setDrawingThickness(100);
	//CC212VSGL::drawLine(x + 100, y / 2 + 50, x + 500, y / 2 + 225);
	//CC212VSGL::setDrawingThickness(55);
	//CC212VSGL::drawLine(x + 71, y / 2 + 60, x + 94, y / 2+16 );
	//CC212VSGL::setDrawingThickness(100);
	//CC212VSGL::drawLine(x + 400, y / 2 + 200, x + 400, y / 2 + 250);
	CC212VSGL::endDraw();
}
void rectangle()
{
	int x = CC212VSGL::getWindowWidth() / 2, y = CC212VSGL::getWindowHeight();
	CC212VSGL::beginDraw();
	CC212VSGL::setDrawingThickness(3);
	CC212VSGL::setDrawingColor(RED);
	CC212VSGL::drawRectangle(x -160, y - 70, 145, 30);
	CC212VSGL::drawLine(x + 100, y + 50, x + 500, y + 225);
	CC212VSGL::endDraw();

}

void read(char *a, char *b)
{

	for (int i = 0; i < 10; i++) //intialize strike board
		for (int j = 0; j < 10; j++)
			*a = '-';
	for (int i = 0; i < 10; i++)// intialize strike board
		for (int j = 0; j < 10; j++)
			*b = '-';

	printf("Player 1, Enter your name without spaces: ");
	scanf("%s", a);
	system("cls");
	

	printf("Player 2, Enter your name without spaces: ");
	scanf("%s", b);
	system("cls");
	

	printf("Battleship Game Instructions\n\n1.Each player must place 6 ships.\n2.All ships with the same length of 3 squares.\n3.Three of these ships can be placed horizontally and the three others are placed vertically.\n4.A game ends when a player hits and sinks all the other player's ships.\n5.You have the option to reset the game by pressing R button every turn.\n6.Coordinates must be numbers from 1 to 10. - any other numbers won't be accepted -\n7.ships can't be placed in the same coordinates. - any overlap won't be accepted -\n8.Please don't input any character in coordinates or it will result in a bug.\n9.H means strike hit a ship - M means strike missed.\n\nEnter any button to continue..");
	getch();
	system("cls");
	


}
void textbackground(int color);


void main()
{
	CC212VSGL::setFullScreenMode();
	CC212VSGL::hideCursor();
	//system("start beethoven.mp3");//
	//system("cmd /c start /beethoven.mp3");//
	//PlaySound(TEXT("beethoven.wav"), NULL, SND_SYNC);//
	//Beep(500, 500);//
	for (;;) //main loop
	{



		system("cls");
		char r = 'x'; //reset button
		int win = 100; //win check
		char player1[10][10], player2[10][10], board1[10][10], board2[10][10]; // 4 grids 1 grid to arrange ships and record enemy shots and other for player own shots
		char p1[20], p2[20];
		char s[100];
		char s1[100];
		int c1 = 0;
		int c = 0;
		read(p1, p2);
		for (int i = 0; i < 10; i++) // intialize player 1 board 
			for (int j = 0; j < 10; j++)
				player1[i][j] = '-';
		// prompt player 1 to enter Horizontal ships
		for (int i = 0; i < 3; )
		{
			int x=0, y=0;
			system("cls");
			drawn();
			//printf("%s,Please place your H ships..\n\n\n", p1);
			printf("\t\t\t\t\t\t\t\t\t\t\n\n\n\n1\t");
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					printf("%c\t", player1[i][j]);
				}
				if (i < 9)
					printf("\n\n\r%d\t", i + 2);
			}
			 

			//printf("\n\nEnter coord for horizontal ship %d: ", i + 1);
			do
			{
				//printf("\n\n\n\n\nEnter coord for horizontal ship x axis %d: ", i + 1);
				scanf("%s", s);
				c = 0;
				for (int i = 0; i < strlen(s); i++)
				{
					if (s[i] >= 'a' && s[i] <= 'z') {
						//x = s[c] - 'a';
						c++;
					}
				}
				if (c == 0)
					break;
				//printf("Please re-enter coordinates of x axis .");
				
			} while (c >= 1);
			//printf("\n\nEnter coord for horizontal ship %d: ", i + 1);
			do
			{
				printf("\n\nEnter coord for horizontal ship y axis %d: ", i + 1);
				scanf("%s", s1);
				c1 = 0;
				for (int i = 0; i < strlen(s1); i++)
				{
					if (s1[i] >= 'a' && s1[i] <= 'z') {
						//x = s[c] - 'a';
						c1++;
					}
				}
				if (c1 == 0)
					break;
				printf("Please re-enter coordinates of y axis .");
			} while (c1 >= 1);


			
			x = toString(s);
			
			y = toString(s1);
				x--;
				y--;	//adjust to array index
				if (x > 9 || y >= 9 || x < 0 || y <= 0)
				{
					continue;
				}
				else if (player1[x][y] != '-' || player1[x][y - 1] != '-' || player1[x][y + 1] != '-')
				{
					continue;
				}
				else i++;

				player1[x][y] = '#';
				player1[x][y - 1] = '#';
				player1[x][y + 1] = '#';
				rectangle();
				system("cls");
				drawn();
			}
			
			// player1 vertical ships
			for (int i = 0; i < 3;)
			{
				int x, y;
				system("cls");
				drawn();
				printf("%s,Please place your V ships..\n\n\n", p1);
				printf("\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n\n\n\n1\t");
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						printf("%c\t", player1[i][j]);
					}
					if (i < 9)
						printf("\n\n\r%d\t", i + 2);
				}
				printf("\n\nEnter coord for vertical ship %d: ", i + 1);
				scanf("%d%d", &x, &y);
				x--;
				y--;
				if (x >= 9 || y > 9 || x <= 0 || y < 0) // if coord in corner loop skips iteration
				{
					continue;
				}
				if (player1[x][y] != '-' || player1[x + 1][y] != '-' || player1[x - 1][y] != '-')// coord not empty iteration is skipped
				{
					continue;
				}
				else i++;
				player1[x][y] = '#';
				player1[x - 1][y] = '#';
				player1[x + 1][y] = '#';
				system("cls");
				drawn();
			}
			printf("%s Final board..\n\n\n", p1);
			printf("\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n\n\n\n1\t");
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					printf("%c\t", player1[i][j]);
				}
				if (i < 9)
					printf("\n\n\r%d\t", i + 2);
			}
			printf("\n\nEnter any key to continue..");
			getch();
			system("cls");
			drawn();

			for (int i = 0; i < 10; i++) // intialize player 2 board
				for (int j = 0; j < 10; j++)
					player2[i][j] = '-';
			// prompt player 2 to enter Horizontal ships
			for (int i = 0; i < 3; )
			{
				int x, y;
				system("cls");
				drawn();
				printf("%s,Please place your H ships..\n\n\n", p2);
				printf("\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n\n\n\n1\t");
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						printf("%c\t", player2[i][j]);
					}
					if (i < 9)
						printf("\n\n\r%d\t", i + 2);
				}
				printf("\n\nEnter coord for horizontal ship %d: ", i + 1);
				scanf("%d%d", &x, &y);
				x--;
				y--;	//adjust to array index

				if (x > 9 || y >= 9 || x < 0 || y <= 0)
				{
					continue;
				}
				else if (player2[x][y] != '-' || player2[x][y - 1] != '-' || player2[x][y + 1] != '-')
				{
					continue;
				}
				else i++;

				player2[x][y] = '#';
				player2[x][y - 1] = '#';
				player2[x][y + 1] = '#';
				system("cls");
				drawn();
			}
			// player2 vertical ships
			for (int i = 0; i < 3;)
			{
				int x, y;
				system("cls");
				drawn();
				printf("%s,Please place your V ships..\n\n\n", p2);
				printf("\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n\n\n\n1\t");
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						printf("%c\t", player2[i][j]);
					}
					if (i < 9)
						printf("\n\n\r%d\t", i + 2);
				}
				printf("\n\nEnter coord for vertical ship %d: ", i + 1);
				scanf("%d%d", &x, &y);
				x--;
				y--;
				if (x >= 9 || y > 9 || x <= 0 || y < 0) // if coord in corner loop skips iteration
				{
					continue;
				}
				else if (player2[x][y] != '-' || player2[x + 1][y] != '-' || player2[x - 1][y] != '-')
				{
					continue;
				}
				else i++;
				player2[x][y] = '#';
				player2[x + 1][y] = '#';
				player2[x - 1][y] = '#';
				system("cls");
				drawn();
			}
			printf("%s Final board..\n\n\n", p2);
			printf("\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n\n\n\n1\t");
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					printf("%c\t", player2[i][j]);
				}
				if (i < 9)
					printf("\n\n\r%d\t", i + 2);
			}
			printf("\n\nEnter any key to start the game..");
			getch();
			system("cls");
			drawn();
			for (;;)//Game loop
			{
				int x, y;
				if (r == 'r' || r == 'R')//reset
					break;
				win = 100;
				for (;;)// condition loop 1
				{
					system("cls");
					drawn();
					printf("%s Turn..\n\n\n", p1);
					printf("\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n\n\n\n1\t");
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							printf("%c\t", board1[i][j]);
						}
						if (i < 9)
							printf("\n\n\r%d\t", i + 2);
					}
					printf("\n\nEnter coordinates of your strike: ");
					scanf("%d%d", &x, &y);
					x--;
					y--;
					if (x > 9 || y > 9 || x < 0 || y < 0)
					{
						continue;
					}
					else if (board1[x][y] == 'H' || board1[x][y] == 'M')
					{
						continue;
					}
					else
						break;
				}
				if (player2[x][y] == '#')//strike check
				{
					player2[x][y] = '-';
					board1[x][y] = 'H'; // H means strike hits ship
					for (int i = 0; i < 10; i++)   //win check 1
					{
						if (win == 0)
							break;
						for (int j = 0; j < 10; j++)
						{
							if (player2[i][j] == '#')
							{
								win = 0; break;
							}
							else
								win = 1;
						}
					}
				}
				else
				{
					board1[x][y] = 'M'; // M  means strike missed ship
				}
				system("cls");
				drawn();
				printf("%s Turn..\n\n\n", p1);
				printf("\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n\n\n\n1\t");
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						printf("%c\t", board1[i][j]);
					}
					if (i < 9)
						printf("\n\n\r%d\t", i + 2);
				}
				if (win == 1) //win check
				{
					printf("\n\n%s won!\nPress R to reset game.\nPress any other key to exit game.", p1);
					r = getch();
					if (r == 'r' || r == 'R')
					{
						break;
					}
					else
						return;
				}
				win = 100;
				printf("\n\nPress R to reset game.\nPress any other key to continue.");
				r = getch();
				if (r == 'r' || r == 'R')
				{
					break;
				}

				for (;;)// condition loop 2
				{
					system("cls");
					drawn();
					printf("%s Turn..\n\n\n", p2);
					printf("\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n\n\n\n1\t");
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							printf("%c\t", board2[i][j]);
						}
						if (i < 9)
							printf("\n\n\r%d\t", i + 2);
					}
					printf("\n\nEnter coordinates of your strike: ");
					scanf("%d%d", &x, &y);
					x--;
					y--;
					if (x > 9 || y > 9 || x < 0 || y < 0)
					{
						continue;
					}
					else if (board2[x][y] == 'H' || board2[x][y] == 'M')
					{
						continue;
					}
					else
						break;
				}
				if (player1[x][y] == '#')//strike check
				{
					player1[x][y] = '-';
					board2[x][y] = 'H'; // H means strike hits ship
					for (int i = 0; i < 10; i++)   //win check 2
					{
						if (win == 0)
							break;
						for (int j = 0; j < 10; j++)
						{
							if (player1[i][j] == '#')
							{
								win = 0; break;
							}
							else
								win = 2;
						}
					}
				}
				else
				{
					board2[x][y] = 'M'; // M  means strike missed ship
				}
				system("cls");
				drawn();
				printf("%s Turn..\n\n\n", p2);
				printf("\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n\n\n\n1\t");
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						printf("%c\t", board2[i][j]);
					}
					if (i < 9)
						printf("\n\n\r%d\t", i + 2);
				}
				if (win == 2)
				{
					printf("\n\n%s won!\nPress R to reset game.\nPress any other key to exit game.", p2);
					r = getch();
					if (r == 'r' || r == 'R')
					{
						break;
					}
					else
						return;
				}
				printf("\n\nPress R to reset game.\nPress any other key to continue.");
				r = getch();
				if (r == 'r' || r == 'R')
				{
					break;
				}
			}
		}
		getch();
	}
	int toString(char a[]) {
  int c, sign=0, offset, n;
 
  if (a[0] == '-') {  // Handle negative integers
    sign = -1;
  }
 
  if (sign == -1) {  // Set starting position to convert
    offset = 1;
  }
  else {
    offset = 0;
  }
 
  n = 0;
 
  for (c = offset; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0';
  }
 
  if (sign == -1) {
    n = -n;
  }
 
  return n;
}

