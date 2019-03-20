/* File : miscellany.c
 * ----------------------------------------------
 * this library is a medley library of difficult-to-classify functions  
 * that determined this library is absolutely hard to maintain
 * so the comments are written as detailed as possible in my ability
 * if you see them in a whole in their combined version,you may understand them more deeply
 * but it is just fine that most of them are simple functions 
 * and the code is not so sophiscated for reading
 */ 



#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include"icons.h"

#define Thread_MAX 1000

int delay[Thread_MAX] = {0};//define arrays for inittime data storage

int pulse[Thread_MAX] = {0};

/*
 * Function : Delay
 * Usage : Delay(delaytime,threadnum)
 * ----------------------
 * this function returns 0 once it is called for delaytime milliseconds
 * after delaytime milliseconds it return 1 if it is called again in threadnumth thread
 * the mechanism is that it create a dynamic space to store the time when this function is called
 * and compare the time when it is called again to identify if has pased delaytime milliseconds
 */
 
int Delay(int delaytime,int threadnum)
{    
	static int flag[Thread_MAX] = {0};
	
	if(flag[threadnum] == 0)
	{
		delay[threadnum] = (int)time(NULL);
    	flag[threadnum] = 1;
	}
	
	if( (int)time(NULL) - delay[threadnum] >= delaytime )
	{
		delay[threadnum] = 0;
		flag[threadnum] = 0;
		return 1;
	}
	else return 0;
}


/*
 * Function : Pulse
 * Usage : Pulse(T)
 * ----------------------
 * this function keeps return 0 for T milliseconds in threadnumth thread
 * and return 1 when it has precisely passed k*T seconds(k is a positive integer)
 * it almost has the same design as Delay()
 * however it doesn't free its dynamic memory and keeping calculate the time
 * i am not sure the modular arithmetic is effective
 * maybe we need an episilon instead ------ but its value is waiting to be tested
 */
 
int Pulse(int T,int threadnum)
{
	static int flag[Thread_MAX] = {0};
	
	if(flag[threadnum] == 0)
	{
    	pulse[threadnum] = (int)time(NULL);
    	flag[threadnum] = 1;
	}
	
	if( ( (int)time(NULL) - pulse[threadnum] ) % T == 0 )return 1;
	else return 0;
}

/*
 * Function : Randnum
 * Usage : Randnum(a,b)
 * ----------------------
 * this function returns a pseudo random integral number between a and b  
 * a and b are not included in the range
 * the mechanism is using modular arithmetic to convert the reutrn value of rand() averagely
 * into integers between a and b
 */
 
int Randnum(int a,int b) 
{
	srand((int)time(NULL));
	int d = b - a + 1;
	return (a+rand()%d);	
}

/*
 * Function : Sound 
 * Usage : Sound(type)
 * -------------------------
 * this functoin produces a certain sound responding to type(~)
 * these sounds are produced by function Beep();
 * and controlled by a switch
 */ 

int Sound(int type)
{
	switch(type)
	{
		case 1:
			Beep(265,100);
			break;
		case 2:
			Beep(3900,200);
			break;
		case 3:
			Beep(100,1000);
			break;
		case 4:
			Beep(4000,1000);
			break;
		default:
			printf("\a");
			break;
	}
}

/*
 * Function : Clear 
 * Usage : Clear(width,height)
 * -------------------------
 * this functoin clears the showing domain by print spaces
 */  

void Clear(int x,int y,int width,int height)
{
	for(int j = y;j <= y + height;j++)
	{
		gotoXY(x,j);
	    for(int i = x;i <= x + width;i++)printf(" ");
	}
}









