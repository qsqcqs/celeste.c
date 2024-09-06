#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
//#include <curses.h>

char readfile(char file[],long bytenum)
{
FILE* fptr;
fptr = fopen(file,"rb");
int a = 0;
unsigned char b[1];
    fseek(fptr,bytenum,SEEK_SET);
	fread(b,1,1,fptr);
//	printf("%x",b[0]);
	fclose(fptr);
    return(b[0]);

//printf("\n");
}

double playerx = 0;
double playery = 0;
bool grounded = true;
double xspeed = 0;
double yspeed = 0;
char prevlr = 'n';
char prevud = 'n';
bool prevdash = false;
void interactions()
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
//main dir determiner
	char lr = 'n';
	if (prevlr == 'l')
	{
		if (left)
		{
				lr = 'l';
		}
		else
		{
			if (right)
			{
				lr = 'r';
			}
			else
			{
				lr = 'n';
			}
		}
	}
	if (prevlr == 'r')
	{
		if (right)
		{
			lr = 'r';
		}
		else
		{
			if (left)
			{
				lr = 'l';
			}
			else
			{
				lr = 'n';
			}
		}
	}
	if (prevlr == 'n')
	{
		if (left)
		{
			if (right)
			{
				lr = 'n';
			}
			else 
			{
				lr = 'l';
			}
		}
		else
		{
			if (right)
			{
				lr = 'r';
			}
			else
			{
				lr = 'n';
			}
		}
	}

	char ud = 'n';
	if (prevud == 'u')
	{
		if (up)
		{
				ud = 'u';
		}
		else
		{
			if (down)
			{
				ud = 'd';
			}
			else
			{
				ud = 'n';
			}
		}
	}
	if (prevud == 'd')
	{
		if (down)
		{
			ud = 'd';
		}
		else
		{
			if (up)
			{
				ud = 'u';
			}
			else
			{
				ud = 'n';
			}
		}
	}
	if (prevud == 'n')
	{
		if (up)
		{
			if (down)
			{
				ud = 'n';
			}
			else 
			{
				ud = 'u';
			}
		}
		else
		{
			if (down)
			{
				ud = 'd';
			}
			else
			{
				ud = 'n';
			}
		}
	}
	if (lr != 'n' || ud != 'n')
	{
		prevud = ud;
		prevlr = lr;
	}
//actions determiner
	if (grounded)
	{
		if (xspeed > 5)
		{
			xspeed = xspeed * 9 / 10 - 5;
		}
		if (xspeed < -5)
		{
			xspeed = xspeed * 9 / 10 + 5;
		}
		if (xspeed >= -5 && xspeed <= 5)
		{
			xspeed = 0;
		}
		if (lr == 'r')
		{
			xspeed = 5;
		}
		if (lr == 'l')
		{
			xspeed = -5;
		}
		if (lr == 'n')
		{
			xspeed = 0;
		}
	
		if (jump)
		{
			yspeed = 5;
		}
	}
	else 
	{
		if (lr = 'r')
		{
			if (xspeed < 0)
			{
				xspeed = .95 * xspeed + 5;
			}
			else
			{
				if (xspeed < 5)
				{
					xspeed = 5;
				}
			}
		}
		if (lr = 'l')
		{
			if (xspeed > 0)
			{
				xspeed = .95 * xspeed - 5;
			}
			else
			{
				if (xspeed > -5)
				{
					xspeed = -5;
				}
			}
		}
		if (lr = 'n')
		{
			if (xspeed > 5 || xspeed < -5)
			{
				xspeed = .95 * xspeed;
			}
		}
	}
	if (dash)
	{
	if (!prevdash)
	{
		if (lr == 'n' && ud == 'n')
			lr == prevlr;
			ud == prevud;
		if (ud == 'n')
		{
			if (lr == 'r')
			{
				if (xspeed < 0)
				{
					xspeed = xspeed * 1.2;
				}
				xspeed = xspeed + 5;
			}
			else
			{
				if (xspeed > 0)
				{
					xspeed = xspeed + 1.2;
				}
				xspeed = xspeed -5;
			}
		}
		else
		{
			if (lr == 'n')
			{
				if (ud = 'u')
				{
					yspeed = yspeed + 5;
				}
				else
				{
					yspeed = yspeed - 5;
				}
			}
			else
			{
				if (ud == 'u')
				{
					if (lr = 'r')
					{
						if (xspeed > 0)
						{
							xspeed = 1.2 * xspeed;
						}
						xspeed = xspeed + 3.54;
					}
					else
					{
						if (xspeed < 0)
						{
							xspeed = 1.2 * xspeed;
						}
					}

				yspeed = yspeed + 3.54;
				}
				else
				{
					if (lr = 'r')
					{
						if (xspeed > 0)
						{
							xspeed = 1.2 * xspeed;
						}
						xspeed = xspeed + 3.54;
					}
					else
					{
						if (xspeed < 0)
						{
							xspeed = 1.2 * xspeed;
						}
					}
				yspeed = yspeed - 3.54;
				}
			}
		}
	}
	prevdash = true;
	}
	else
	{
	prevdash = false;
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
	
	bool run = true;
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
