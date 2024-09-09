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

char map[3600];
struct inputs
{
	bool up;
	bool down;
	bool left;
	bool right;
	bool jump;
	bool dash;
	bool prevjump;
	bool prevdash;
	char xdir;
	char ydir;
	char prevxdir;
	char prevydir;
};
struct player
{
	double x;
	double y;
	bool grounded;
	double xspeed;
	double yspeed;

};
die(){/*to do*/}

int getblock(x,y)
{
	return map[x + 80 * y];
}
void pixrender(x,y){/*oh god please no*/
/*
characters for this shit
^vpbBd89 for spikes
X for blocks
blue for blocks, white for spikes
*/
switch (getblock(x,2*y) + 8 * getblock(x,2*y+1))
{
	case 0:
		printf(' ');
		break;
	case 1:
		printf('x');
		break;
	case 2:
		printf('n');
		break;
	case 3:
		printf('v');
		break;
	case 4:
		printf('d');
		break;
	case 5:
		printf('b');
		break;
	case 6:
		//lava not implemented
		break;
	case 7:
		//ice not implemented
		break;
	case 8:
		printf('*');
		break;
	case 9:
		printf('X');
		break;
	case 10:
		//bruh this is a spike pointing at a block
		break;
	case 11:
		printf('V');
		break;
	case 12:
		printf('d');
		break;
	case 13:
		printf('b');
		break;
	case 14:
		//lava not implemented
		break;
	case 15:
		//ice not implemented
		break;
	case 16:
			printf('^');
		break;
	case 17:
			printf('A');
		break;
	case 18:
		printf('M');
		break;
	case 19:
		printf('N');
		break;
	case 20://20 is fine-ish, 21 is iffier
		printf('&');
		break;
	case 21:
		printf('&');
		break;
	case 22:
		//lava not implemented
		break;
	case 23:
		//ice not implemented
		break;
	case 24:
		printf('Y');
		break;
	case 25:
		//spike into a block again?
		break;
	case 26: //26 and 27 are such a compromise
		printf('<');
		break;
	case 27:
		printf('<');
		break;
	case 28:
		printf('<');
		break;
	case 29:
		printf('Z');
		break;
	case 30:
		//lava not implemented
		break;
	case 31:
		//ice not implemented
		break;
	case 32:
		printf('9');
		break;
	case 33:
		printf('9');
		break;
	case 34://more compromises for 34 35
		printf('<');
		break;
	case 35:
		printf('<');
		break;
	case 36:
		printf('<');
		break;
	case 37:
		printf('Z');
		break;
	case 38:
		//lava not implemented
		break;
	case 39:
		//ice not implemented
		break;
	case 40:
		printf('p');
		break;
	case 41:
		printf('p');
		break;
	case 42://compromises for 42 43
		printf('>');
		break;
	case 43:
		printf('>');
		break;
	case 44:
		printf('Z');
		break;
	case 45:
		printf('>');
		break;
		//a lot of lava and ice not implemented
	case 46:
		break;
	case 47:
		break;
	case 48:
		break;
	case 49:
		break;
	case 50:
		break;
	case 51:
		break;
	case 52:
		break;
	case 53:
		break;
	case 54:
		break;
	case 55:
		break;
	case 56:
		break;
	case 57:
		break;
	case 58:
		break;
	case 59:
		break;
	case 60:
		break;
	case 61:
		break;
	case 62:
		break;
	case 63:
		break;
};


}
render(){}
void collide(struct player* maddyptr)
{
	/*
	0->empty
	1->wall
	2->spikeup
	3->spikedown
	4->spikeleft
	5->spikeright
	6->lava
	7->ice
	*/
	int leftaligint = (int)(maddyptr->x);
	int heightalignint = (int)(maddyptr->y);
	double xoffset = fmod(maddyptr->x,1)-.5;
	double yoffset = fmod(maddyptr->y,1)-.5;
	int xalignment = 0;
	int yalignment = 0;
	switch (getblock(leftaligint,heightalignint))
	{
		case 0:
			break;
		case 1:
			die();
			break;
		case 2:
			if (maddyptr->yspeed <= 0)
			{
				die();
			}
			break;
		case 3:
			if (maddyptr->yspeed >= 0)
			{
				die();
			}
			break;
		case 4:
			if (maddyptr->xspeed >= 0)
			{
				die();
			}
			break;
		case 5:
			if (maddyptr->xspeed <= 0)
			{
				die();
			}
			break;
		case 6:
			//to do
			break;
		case 7:
			//to do
			break;
	}
	if (yoffset > 0)
	{
		yalignment += 1;
	}
	else
	{
		if (yoffset < 0)
		{
			yalignment -= 1;
		}
	}
	if (xoffset > 0)
	{
		xalignment += 1;
	}
	else
	{
		if (xoffset < 0)
		{
			xalignment -= 1;
		}
	}


	//lazy spike detection is intentional (totally the truth ok)
	
	switch (yalignment)
	{
	case -1:
		if (getblock(leftaligint,heightalignint-1) == 1)
		{
			maddyptr->y += yoffset;
			maddyptr->yspeed = 0;
		}
		break;
	case 0:
		break;
	case 1:
		if (getblock(leftaligint,heightalignint+1) == 1)
		{
			maddyptr->y -= yoffset;
			maddyptr->yspeed = 0;
		}
		break;
	}
	switch (xalignment)
	{
	case -1:
		if (getblock(leftaligint-1,heightalignint) == 1)
		{
			maddyptr->x += xoffset;
			maddyptr->xspeed = 0;
		}
		break;
	case 0:
		break;
	case 1:
		if (getblock(leftaligint+1,heightalignint) == 1)
		{
			maddyptr->x -= xoffset;
			maddyptr->xspeed = 0;
		}
		break;
	}


	
}
char xdir(struct inputs* inputptr)
{
	if (inputptr->prevxdir == -1)
	{
		if (inputptr->left)
		{
				return(-1);
		}
		else
		{
			if (inputptr->right)
			{
				return(1);
			}
			else
			{
				return(0);
			}
		}
	}
	if (inputptr->prevxdir == 1)
	{
		if (inputptr->right)
		{
			return(1);
		}
		else
		{
			if (inputptr->left)
			{
				return(-1);
			}
			else
			{
				return(0);
			}
		}
	}
	return((char)(inputptr->left) + (char)(inputptr->right));
}
char ydir(struct inputs* inputptr)
{
	if (inputptr->prevydir == 1)
	{
		if (inputptr->up)
		{
				return(1);
		}
		else
		{
			if (inputptr->down)
			{
				return(-1);
			}
			else
			{
				return(0);
			}
		}
	}
	if (inputptr->prevydir == -1)
	{
		if (inputptr->down)
		{
			return(-1);
		}
		else
		{
			if (inputptr->up)
			{
				return(1);
			}
			else
			{
				return(0);
			}
		}
	}
	return((char)(inputptr->up) + (char)(inputptr->down));
}
void friction(struct inputs* inputptr,struct player* maddieptr)
{
	if (maddieptr->grounded)
	{
		if (maddieptr->xspeed > 5)
		{
			maddieptr->xspeed = maddieptr->xspeed * 9 / 10 - 5;
		}
		if (maddieptr->xspeed < -5)
		{
			maddieptr->xspeed = maddieptr->xspeed * 9 / 10 + 5;
		}
		if (maddieptr->xspeed >= -5 && maddieptr->xspeed <= 5)
		{
			maddieptr->xspeed = 0;
		}
	}
	else
	{
		if (inputptr->xdir = 1)
		{
			if (maddieptr->xspeed < 0)
			{
				maddieptr->xspeed = .95 * maddieptr->xspeed + 5;
			}
			else
			{
				if (maddieptr->xspeed < 5)
				{
					maddieptr->xspeed = 5;
				}
			}
		}
		if (inputptr->xdir = -1)
		{
			if (maddieptr->xspeed > 0)
			{
				maddieptr->xspeed = .95 * maddieptr->xspeed - 5;
			}
			else
			{
				if (maddieptr->xspeed > -5)
				{
					maddieptr->xspeed = -5;
				}
			}
		}
		if (inputptr->xdir = 0)
		{
			if (maddieptr->xspeed > 5 || maddieptr->xspeed < -5)
			{
				maddieptr->xspeed = .95 * maddieptr->xspeed;
			}
		}
	}
}
void jumpphys(struct inputs* inputptr,struct player* maddieptr)
{
	if (maddieptr->grounded && inputptr -> jump)
	{
		inputptr->prevjump = true;
		if (!inputptr->prevjump)
		{
			maddieptr->yspeed = 20;
		}
	}
	else
	{
		inputptr->prevjump = false;
	}
}
void dashphys(struct inputs* inputptr,struct player* maddieptr)
{
	if (!inputptr->prevdash)
		{
			if (inputptr->xdir == 0 && inputptr->ydir == 0)
				inputptr->xdir == inputptr->prevxdir;
				inputptr->ydir == inputptr->prevydir;
			if (inputptr->ydir == 0)
			{
				if (inputptr->xdir == 1)
				{
					if (maddieptr->xspeed < 0)
					{
						maddieptr->xspeed = maddieptr->xspeed * 1.2;
					}
					maddieptr->xspeed = maddieptr->xspeed + 5;
				}
				else
				{
					if (maddieptr->xspeed > 0)
					{
						maddieptr->xspeed = maddieptr->xspeed + 1.2;
					}
					maddieptr->xspeed = maddieptr->xspeed -5;
				}
			}
			else
			{
				if (inputptr->xdir == 0)
				{
					if (inputptr->ydir = 1)
					{
						maddieptr->yspeed = maddieptr->yspeed + 5;
					}
					else
					{
						maddieptr->yspeed = maddieptr->yspeed - 5;
					}
				}
				else
				{
					if (inputptr->ydir == 1)
					{
						if (inputptr->xdir = 1)
						{
							if (maddieptr->xspeed > 0)
							{
								maddieptr->xspeed = 1.2 * maddieptr->xspeed;
							}
							maddieptr->xspeed = maddieptr->xspeed + 3.54;
						}
						else
						{
							if (maddieptr->xspeed < 0)
							{
								maddieptr->xspeed = 1.2 * maddieptr->xspeed;
							}
						}

					maddieptr->yspeed = maddieptr->yspeed + 3.54;
					}
					else
					{
						if (inputptr->xdir = 1)
						{
							if (maddieptr->xspeed > 0)
							{
								maddieptr->xspeed = 1.2 * maddieptr->xspeed;
							}
							maddieptr->xspeed = maddieptr->xspeed + 3.54;
						}
						else
						{
							if (maddieptr->xspeed < 0)
							{
								maddieptr->xspeed = 1.2 * maddieptr->xspeed;
							}
						}
					maddieptr->yspeed = maddieptr->yspeed - 3.54;
					}
				}
			}
		}
		inputptr->prevdash = true;
}
void xdirhold(struct inputs* inputptr,struct player* maddieptr)
{
	if (maddieptr->grounded)
	{
		if (inputptr->xdir == 1)
		{
			maddieptr->xspeed = 5;
		}
		if (inputptr->xdir == -1)
		{
			maddieptr->xspeed = -5;
		}
		if (inputptr->xdir == 0)
		{
			maddieptr->xspeed = 0;
		}
	}
	else
	{
		if (inputptr->xdir == 1)
		{
			maddieptr->xspeed + 1;
			if (maddieptr->xspeed > 5)
			{
				maddieptr->xspeed = 5;
			}
		}
		if (inputptr->xdir == -1)
		{
			maddieptr->xspeed - 1;
			if (maddieptr->xspeed < -5)
			{
				maddieptr->xspeed = -5;
			}
			
		}
		if (inputptr->xdir == 0)
		{
			if (maddieptr->xspeed > -1)
			{	if (maddieptr->xspeed < 1)
				{
					maddieptr->xspeed = 0;
				}
				maddieptr->xspeed = maddieptr->xspeed - 1;
			}
			else
			{
				if (maddieptr->xspeed < 1)
				{
					maddieptr->xspeed = maddieptr->xspeed + 1;
				}
			}
		
		}
	}
}
void gravity(struct inputs* inputptr,struct player* maddieptr)
{
	if (maddieptr->yspeed > -10)
	{
	maddieptr->yspeed=maddieptr->yspeed-1;
	}
	if (inputptr->ydir = -1)
	{
		maddieptr->yspeed = maddieptr->yspeed - 1;
	}
	else
	{
		if (maddieptr->yspeed < -10)
		{
			maddieptr->yspeed = -10;
		}
	}
}
void movement(struct inputs* inputptr,struct player* maddieptr)
{
	friction(inputptr,maddieptr);
	jumpphys(inputptr,maddieptr);
	xdirhold(inputptr,maddieptr);
	if (inputptr->dash)
	{
		dashphys(inputptr,maddieptr);
	}
	else
	{
		inputptr->prevdash = false;
	}
	maddieptr->x += maddieptr->xspeed;
	maddieptr->y += maddieptr->yspeed;

}

void interactions(struct inputs* inputptr,struct player* maddyptr,bool* run)
{

	//nobody shall see these horrors

	inputptr->up = (bool)readfile("tmp",0);
	inputptr->down = (bool)readfile("tmp",1);
	inputptr->left = (bool)readfile("tmp",2);
	inputptr->right = (bool)readfile("tmp",3);
	inputptr->jump = (bool)readfile("tmp",4);
	inputptr->dash = (bool)readfile("tmp",5);
	inputptr->xdir = xdir(inputptr);
	inputptr->ydir = ydir(inputptr);
	if (inputptr->xdir != 0 || inputptr->ydir != 0){inputptr->prevydir = inputptr->ydir;inputptr->prevxdir = inputptr->xdir;}
	movement(inputptr,maddyptr);
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
	maddy.x=0;
	maddy.y = 0;
	maddy.grounded = true;
	maddy.xspeed = 0;
	maddy.yspeed = 0;

	struct inputs input;
	input.prevxdir = 0;
	input.prevydir = 0;
	input.prevjump = false;
	input.prevdash = false;
	run = true;
	while (run)
	{
		interactions(&input,&maddy,&run);
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
