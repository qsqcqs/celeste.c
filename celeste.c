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
char horizontaldirection(bool left,bool right,char previoushorizontal)
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
char verticaldirection(bool up, bool down,char previousvertical)
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
void movement(char horizontaldirection,char verticaldirection,bool jump,bool dash,struct player* maddie)
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
		if (horizontaldirection == 'r')
		{
			maddie->xspeed = 5;
		}
		if (horizontaldirection == 'l')
		{
			maddie->xspeed = -5;
		}
		if (horizontaldirection == 'n')
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

		if (verticaldirection = 'd')
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
		if (horizontaldirection = 'r')
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
		if (horizontaldirection = 'l')
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
		if (horizontaldirection = 'n')
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
			if (horizontaldirection == 'n' && verticaldirection == 'n')
				horizontaldirection == maddie->previoushorizontal;
				verticaldirection == maddie->previousvertical;
			if (verticaldirection == 'n')
			{
				if (horizontaldirection == 'r')
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
				if (horizontaldirection == 'n')
				{
					if (verticaldirection = 'u')
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
					if (verticaldirection == 'u')
					{
						if (horizontaldirection = 'r')
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
						if (horizontaldirection = 'r')
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
	bool up = (readfile("tmp",0) == 49);
	bool down = (readfile("tmp",1) == 49);
	bool left = (readfile("tmp",2) == 49);
	bool right = (readfile("tmp",3) == 49);
	bool jump = readfile("tmp",4) == 49;
	bool dash = (readfile("tmp",5) == 49);
	char horizontal = horizontaldirection(left,right,maddyptr->previoushorizontal);
	char vertical = verticaldirection(up,down,maddyptr->previousvertical);
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