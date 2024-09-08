#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
//#inclxdire <curses.h>

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


struct player
{
	double playerx;
	double playery;
	bool grounded;
	double xspeed;
	double yspeed;
	char previoushorizontal;
	char previousvertical;
	bool prevjump;
	bool prevdash;
};
char xdir(bool left,bool right,char previoushorizontal)
{
	char horizontal = 'n';
	if (previoushorizontal == 'l')
	{
		if (left)
		{
				horizontal = 'l';
		}
		else
		{
			if (right)
			{
				horizontal = 'r';
			}
			else
			{
				horizontal = 'n';
			}
		}
	}
	if (previoushorizontal == 'r')
	{
		if (right)
		{
			horizontal = 'r';
		}
		else
		{
			if (left)
			{
				horizontal = 'l';
			}
			else
			{
				horizontal = 'n';
			}
		}
	}
	if (previoushorizontal == 'n')
	{
		if (left)
		{
			if (right)
			{
				horizontal = 'n';
			}
			else 
			{
				horizontal = 'l';
			}
		}
		else
		{
			if (right)
			{
				horizontal = 'r';
			}
			else
			{
				horizontal = 'n';
			}
		}
	}
	return(horizontal);
}
char ydir(bool up, bool down,char previousvertical)
{
	char vertical = 'n';
	if (previousvertical == 'u')
	{
		if (up)
		{
				vertical = 'u';
		}
		else
		{
			if (down)
			{
				vertical = 'd';
			}
			else
			{
				vertical = 'n';
			}
		}
	}
	if (previousvertical == 'd')
	{
		if (down)
		{
			vertical = 'd';
		}
		else
		{
			if (up)
			{
				vertical = 'u';
			}
			else
			{
				vertical = 'n';
			}
		}
	}
	if (previousvertical == 'n')
	{
		if (up)
		{
			if (down)
			{
				vertical = 'n';
			}
			else 
			{
				vertical = 'u';
			}
		}
		else
		{
			if (down)
			{
				vertical = 'd';
			}
			else
			{
				vertical = 'n';
			}
		}
	}
	return(vertical);
}
void movement(char xdir,char ydir,bool jump,bool dash,struct player* maddie)
{
	if (maddie->grounded)
	{
		if (maddie->xspeed > 5)
		{
			maddie->xspeed = maddie->xspeed * 9 / 10 - 5;
		}
		if (maddie->xspeed < -5)
		{
			maddie->xspeed = maddie->xspeed * 9 / 10 + 5;
		}
		if (maddie->xspeed >= -5 && maddie->xspeed <= 5)
		{
			maddie->xspeed = 0;
		}
		if (xdir == 'r')
		{
			maddie->xspeed = 5;
		}
		if (xdir == 'l')
		{
			maddie->xspeed = -5;
		}
		if (xdir == 'n')
		{
			maddie->xspeed = 0;
		}
	
		if (jump)
		{
			maddie->prevjump = true;
			if (!maddie->prevjump)
			{
				maddie->yspeed = 20;
			}
		}
		else
		{
			maddie->prevjump = false;
		}
	}
	else 
	{
		if (maddie->yspeed > -10)
		{
		maddie->yspeed=maddie->yspeed-1;
		}

		if (ydir = 'd')
		{
			maddie->yspeed = maddie->yspeed - 1;
		}
		else
		{
			if (maddie->yspeed < -10)
			{
				maddie->yspeed = -10;
			}
		}
		if (xdir = 'r')
		{
			if (maddie->xspeed < 0)
			{
				maddie->xspeed = .95 * maddie->xspeed + 5;
			}
			else
			{
				if (maddie->xspeed < 5)
				{
					maddie->xspeed = 5;
				}
			}
		}
		if (xdir = 'l')
		{
			if (maddie->xspeed > 0)
			{
				maddie->xspeed = .95 * maddie->xspeed - 5;
			}
			else
			{
				if (maddie->xspeed > -5)
				{
					maddie->xspeed = -5;
				}
			}
		}
		if (xdir = 'n')
		{
			if (maddie->xspeed > 5 || maddie->xspeed < -5)
			{
				maddie->xspeed = .95 * maddie->xspeed;
			}
		}
	}
	if (dash)
	{
		if (!maddie->prevdash)
		{
			if (xdir == 'n' && ydir == 'n')
				xdir == maddie->previoushorizontal;
				ydir == maddie->previousvertical;
			if (ydir == 'n')
			{
				if (xdir == 'r')
				{
					if (maddie->xspeed < 0)
					{
						maddie->xspeed = maddie->xspeed * 1.2;
					}
					maddie->xspeed = maddie->xspeed + 5;
				}
				else
				{
					if (maddie->xspeed > 0)
					{
						maddie->xspeed = maddie->xspeed + 1.2;
					}
					maddie->xspeed = maddie->xspeed -5;
				}
			}
			else
			{
				if (xdir == 'n')
				{
					if (ydir = 'u')
					{
						maddie->yspeed = maddie->yspeed + 5;
					}
					else
					{
						maddie->yspeed = maddie->yspeed - 5;
					}
				}
				else
				{
					if (ydir == 'u')
					{
						if (xdir = 'r')
						{
							if (maddie->xspeed > 0)
							{
								maddie->xspeed = 1.2 * maddie->xspeed;
							}
							maddie->xspeed = maddie->xspeed + 3.54;
						}
						else
						{
							if (maddie->xspeed < 0)
							{
								maddie->xspeed = 1.2 * maddie->xspeed;
							}
						}

					maddie->yspeed = maddie->yspeed + 3.54;
					}
					else
					{
						if (xdir = 'r')
						{
							if (maddie->xspeed > 0)
							{
								maddie->xspeed = 1.2 * maddie->xspeed;
							}
							maddie->xspeed = maddie->xspeed + 3.54;
						}
						else
						{
							if (maddie->xspeed < 0)
							{
								maddie->xspeed = 1.2 * maddie->xspeed;
							}
						}
					maddie->yspeed = maddie->yspeed - 3.54;
					}
				}
			}
		}
		maddie->prevdash = true;
	}
	else
	{
		maddie->prevdash = false;
	}

}

void interactions(struct player* maddyptr,bool* run)
{

	//nobody shall see these horrors
	bool up = readfile("tmp",0);
	bool down = readfile("tmp",1);
	bool left = readfile("tmp",2);
	bool right = readfile("tmp",3);
	bool jump = readfile("tmp",4);
	bool dash = readfile("tmp",5);
	char horizontal = xdir(left,right,maddyptr->previoushorizontal);
	char vertical = ydir(up,down,maddyptr->previousvertical);
	if (horizontal != 'n' || vertical != 'n'){maddyptr->previousvertical = vertical;maddyptr->previoushorizontal = horizontal;}
	movement(horizontal,vertical,jump,dash,maddyptr);
}

long framecount()
{
static int fc = 0;
fc ++;
return(fc);
}
void game()
{

	bool run;
	struct player maddy;
	maddy.playerx=0;
	maddy.playery = 0;
	maddy.grounded = true;
	maddy.xspeed = 0;
	maddy.yspeed = 0;
	maddy.previoushorizontal = 'n';
	maddy.previousvertical = 'n';
	maddy.prevjump = false;
	maddy.prevdash = false;
	run = true;
	while (run)
	{
		interactions(&maddy,&run);
		framecount();
	}
}
int main()
{
initscr();
start_color();

game();
endwin();
return(0);

}
/*
	unused
	bool climb = (readfile("tmp",6) == 49);
	bool demo = (readfile("tmp",7) == 49);
	bool reset = (readfile("tmp",8) == 49);
	input detection method is temporary, read from /dev/input instead
*/	
