#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
void sleep_ms(int milliseconds)
{
    #ifdef WIN32
        Sleep(milliseconds);
    #elif _POSIX_C_SOURCE >= 199309L
        struct timespec ts;
        ts.tv_sec = milliseconds / 1000;
        ts.tv_nsec = (milliseconds % 1000) * 1000000;
        nanosleep(&ts, NULL);
    #else
        usleep(milliseconds * 1000);
    #endif
}

char readfile(char file[],long bytenum)
{
FILE* fptr;
fptr = fopen(file,"rb");
int a = 0;
unsigned char b[1]; 
    fseek(fptr,bytenum,SEEK_SET);
	fread(b,1,1,fptr);
	fclose(fptr);
    return(b[0]);

}
char map[4000] = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};
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

void bufferinsert(char* rend,int x,int y,char* string)
{
	int offset = 0;
	int baseoff = 9 * x + (9 * 80 + 1) * y;
	while(string[offset] != '\0' && string[offset] != ':')
	{
		rend[baseoff + offset] = string[offset];
		offset++;
	}
}
void die(){/*to do*/}
//implement one way collision properly
double fmod(double a,double b)
{
	
	while(a < 0 || a > b)
	{
		if (a < 0)
		{
			a += b;
		}
		else
		{
			a -= b;
		}
	}
	return(a);
}
int getblock(int x,int y)
{
	

	
	return(map[x + 80 * y]);
}
int colread(char chr)
{
	switch(chr)
	{
		case 'k':
			return(0);
			break;
		case 'r':
			return(1);
			break;
		case 'g':
			return(2);
			break;
		case 'y':
			return(3);
			break;
		case 'b':
			return(4);
			break;
		case 'm':
			return(5);
			break;
		case 'c':
			return(6);
			break;
		case 'w':
			return(7);
			break;

	}
		
}
char* colman(char bg,char fg)
{
	int bgint = colread(bg);
	int fgint = colread(fg);
	char* str = (char*)malloc(9);
	sprintf(str,"\x1b[9%d;10%dm",bgint,fgint);
	return(str);
	
	
}
char* pixrender(int x,int y,char* buffer){/*oh god please no*/

/*

b blue
r red
w white
k black
blue for blocks, white for spikes
*/
char fku = 'f';
char spritesheet[144] = {
//         0   1   2   3   4   5   6   7   8   9   0   1
/*empty */'k','x','n','v','d','b',' ',' ','-','_','[',']',
/*block */'*','X',fku,'V','d','b',' ',' ',fku,fku,'[',']',
/*spup  */'^','A','M','N','&','&',' ',' ','A',fku,'P','9',
/*spdwn */'Y',fku,'<','<','<','Z',' ',' ',fku,fku,fku,fku,
/*splft */'9','9','<','<','<','Z',' ',' ','<','<','<',fku,
/*sprht */'P','P','>','>','Z','>',' ',' ','>','>',fku,'>',
/*lava  */' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
/*ice   */' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
/*owup  */'~','~',fku,'T','Z','Z',' ',' ','~',fku,'[',']',
/*owdown*/'-','x','7','v','z','z',' ',' ','-','=','[',']',
/*owleft*/'[','[','9','Y','<','<',' ',' ','[','L','[','|',
/*owrht */']','h','R','j','>','>',' ',' ','[',']','|',']'
};
char bgsheet[144] = {
//         0   1   2   3   4   5   6   7   8   9   0   1
/*empty */'k','b','k','k','k','k','k','k','k','k','k','k',
/*block */'b','b',fku,'k','k','k','k','k',fku,fku,'k','k',
/*spup  */'k','k','k','k','k','k','k','k','k','k','k','k',
/*spdwn */'k',fku,'k','k','k','k','k','k',fku,fku,fku,fku,
/*splft */'k','k','k','k','k','k','k','k','k','k','k',fku,
/*sprht */'k','k','k','k','k','k','k','k','k','k',fku,'k',
/*lava  */'k','k','k','k','k','k','k','k','k','k','k','k',
/*ice   */'k','k','k','k','k','k','k','k','k','k','k','k',
/*owup  */'k','k',fku,'k','k','k','k','k','k',fku,'k','k',
/*owdown*/'k','k','k','k','k','k','k','k','k','k','k','k',
/*owleft*/'k','k','k','k','k','k','k','k','k','k','k','k',
/*owrht */'k','k','k','k','k','k','k','k','k','k','k','k',
};
char fgsheet[144] = {
//         0   1   2   3   4   5   6   7   8   9   0   1
/*empty */'k','b','w','w','w','w',' ',' ','y','y','y','y',
/*block */'b','b',fku,'w','w','w',' ',' ',fku,fku,'y','y',
/*spup  */'w','w','w','w','w','w',' ',' ','y',fku,'y','y',
/*spdwn */'w',fku,'w','w','w','w',' ',' ',fku,fku,fku,fku,
/*splft */'w','w','w','w','w','w',' ',' ','y','y','y',fku,
/*sprht */'w','w','w','w','w','w',' ',' ','y','y',fku,'y',
/*lava  */' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
/*ice   */' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
/*owup  */'y','y',fku,'y','y','y',' ',' ','y',fku,'y','y',
/*owdown*/'y','y','y','y','y','y',' ',' ','-','y','y','y',
/*owleft*/'y','[','y','Y','y','y',' ',' ','y','y','y','y',
/*owrht */'y','h','y','y','y','y',' ',' ','y','y','y','y'
};
//segfault before here
int pos = getblock(x,2*y) + 12 * getblock(x,2*y+1);

char* cstr;
cstr = (char*)malloc(10);

cstr[9]=':';
char* subcharstr = colman(bgsheet[pos],fgsheet[pos]);
int i = 0;
while(i < 9)
{
	cstr[i] = subcharstr[i];
	i++;
}
free(subcharstr);
cstr[8] = spritesheet[pos];
return(cstr);

}
void render()
{
	int y = 0;
	int x;
	char buffer[18024];
	char* str;
	while (y < 25)
	{
		x = 0;
		while(x < 80)
		{
			str = pixrender(x,y,buffer);
			bufferinsert(buffer,x,y,str);
			free(str);
			x++;
		}
		if (y <24)
		{
			bufferinsert(buffer,80,y,"\n");
		}
		y++;
	}
	printf(buffer);
	printf("\x1b[97;40mfrane rendered");

}
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
		
		render();
		sleep_ms(16);
		framecount();
	}
}
int main()
{
	

	
	game();
	return(0);

}
/*
	unused
	bool climb = (readfile("tmp",6) == 49);
	bool demo = (readfile("tmp",7) == 49);
	bool reset = (readfile("tmp",8) == 49);
	input detection method is temporary, read from /dev/input instead
*/	
