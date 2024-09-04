#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
//#include <curses.h>

int fileread(char file[],long bytenum)
{
FILE* fptr;
fptr = fopen(file,"rb");
int a = 0;
unsigned char b[1];
    fseek(fptr,bytenum,SEEK_SET);
	fread(b,1,1,fptr);
//	printf("%x",b[0]);
    return(b[0]);
fclose(fptr);
//printf("\n");
}

double playerx = 0;
double playery = 0;
grounded = 0;
double xspeed;
double yspeed;

interactions()
{
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
	bool jump = false;
	bool dash = false;
	bool climb = false;
	bool demo = false;
	bool reset = false;
	if (readfile("tmp",0) == 49)
		{
			up = true;
		}
	if (readfile("tmp",1) == 49)
		{
			down = true;
		}
	if (readfile("tmp",2) == 49)
		{
			left = true;
		}
	if (readfile("tmp",3) == 49)
		{
			right= true;
		}
	if (readfile("tmp",4) == 49)
		{
			jump = true;
		}
	if (readfile("tmp",5) == 49)
		{
			dash = true;
		}
	if (readfile("tmp",6) == 49)
		{
			climb = true;
		}
	if (readfile("tmp",7) == 49)
		{
			demo = true;
		}
	if (readfile("tmp",8) == 49)
		{
			reset = true;
		}
	if (grounded == 1)
		{
		if (xspeed > 10):
			{
			xspeed = xspeed * 9 / 10;
			}
		if (xspeed < -10)
			{
			xspeed = xspeed * 9 / 10;
			}
		}
}

long framecount()
{
static int fc = 0;
fc ++;
return(fc);
}
void game()
{
	

	while (run)
	{

		interactions();
		framecount();
	}
}
int main()
{
initscr();
//getch();
start_color();

game();
endwin();
return(0);

}
