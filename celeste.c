#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
#include <math.h>
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
void die(){/*to do*/}
//implement one ways
int getblock(int x,int y)
{
	return map[x + 80 * y];
}
void pixdataget(int x,int y){/*oh god please no*/
/*

blue for blocks, white for spikes
*/
char spritesheet[] = {
//         1   2   3   4   5   6   7   8   9   0   1   2
/*empty */' ','x','n','v','d','b',' ',' ',' ',' ',' ',' ',
/*block */'*','X',' ','V','d','b',' ',' ',' ',' ',' ',' ',
/*spup  */'^','A','M','N','&','&',' ',' ',' ',' ',' ',' ',
/*spdwn */'Y',' ','<','<','<','Z',' ',' ',' ',' ',' ',' ',
/*splft */'9','9','<','<','<','Z',' ',' ',' ',' ',' ',' ',
/*sprht */'P','P','>','>','Z','>',' ',' ',' ',' ',' ',' ',
/*lava  */' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
/*ice   */' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
/*owup  */' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
/*owdown*/' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
/*owleft*/' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
/*owrht */' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
};
//print(spritesheet[getblock(x,2*y) + 12 * getblock(x,2*y+1)]);

}
void render(){}
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
