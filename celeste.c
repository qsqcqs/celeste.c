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

<<<<<<< HEAD

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
=======
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
>>>>>>> refs/remotes/origin/main
		}
		else
		{
			if (right)
			{
<<<<<<< HEAD
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
=======
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
>>>>>>> refs/remotes/origin/main
		}
		else
		{
			if (left)
			{
<<<<<<< HEAD
				horizontal = 'l';
			}
			else
			{
				horizontal = 'n';
			}
		}
	}
	if (previoushorizontal == 'n')
=======
				lr = 'l';
			}
			else
			{
				lr = 'n';
			}
		}
	}
	if (prevlr == 'n')
>>>>>>> refs/remotes/origin/main
	{
		if (left)
		{
			if (right)
			{
<<<<<<< HEAD
				horizontal = 'n';
			}
			else 
			{
				horizontal = 'l';
=======
				lr = 'n';
			}
			else 
			{
				lr = 'l';
>>>>>>> refs/remotes/origin/main
			}
		}
		else
		{
			if (right)
			{
<<<<<<< HEAD
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
=======
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
>>>>>>> refs/remotes/origin/main
		}
		else
		{
			if (down)
			{
<<<<<<< HEAD
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
=======
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
>>>>>>> refs/remotes/origin/main
		}
		else
		{
			if (up)
			{
<<<<<<< HEAD
				vertical = 'u';
			}
			else
			{
				vertical = 'n';
			}
		}
	}
	if (previousvertical == 'n')
=======
				ud = 'u';
			}
			else
			{
				ud = 'n';
			}
		}
	}
	if (prevud == 'n')
>>>>>>> refs/remotes/origin/main
	{
		if (up)
		{
			if (down)
			{
<<<<<<< HEAD
				vertical = 'n';
			}
			else 
			{
				vertical = 'u';
=======
				ud = 'n';
			}
			else 
			{
				ud = 'u';
>>>>>>> refs/remotes/origin/main
			}
		}
		else
		{
			if (down)
			{
<<<<<<< HEAD
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
=======
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
>>>>>>> refs/remotes/origin/main
		}
	
		if (jump)
		{
<<<<<<< HEAD
			maddie->prevjump = true;
			if (!maddie->prevjump)
			{
				maddie->yspeed = 20;
			}
		}
		else
		{
			maddie->prevjump = false;
=======
			yspeed = 5;
>>>>>>> refs/remotes/origin/main
		}
	}
	else 
	{
<<<<<<< HEAD
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
=======
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
>>>>>>> refs/remotes/origin/main
			}
		}
	}
	if (dash)
	{
<<<<<<< HEAD
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
=======
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
>>>>>>> refs/remotes/origin/main
				}
			}
			else
			{
<<<<<<< HEAD
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
=======
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


>>>>>>> refs/remotes/origin/main
}

long framecount()
{
static int fc = 0;
fc ++;
return(fc);
}
void game()
{
<<<<<<< HEAD

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
=======
	
	bool run = true;
	while (run)
	{

		interactions();
>>>>>>> refs/remotes/origin/main
		framecount();
	}
}
int main()
{
initscr();
<<<<<<< HEAD
=======
//getch();
>>>>>>> refs/remotes/origin/main
start_color();

game();
endwin();
return(0);

}
<<<<<<< HEAD
/*
	unused
	bool climb = (readfile("tmp",6) == 49);
	bool demo = (readfile("tmp",7) == 49);
	bool reset = (readfile("tmp",8) == 49);
	input detection method is temporary, read from /dev/input instead
*/	
=======
>>>>>>> refs/remotes/origin/main
