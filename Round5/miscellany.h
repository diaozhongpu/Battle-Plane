/* File : miscellany.h
 * ------------------------------------------------------------------------------
 * there are many functions that difficult to set them in an indivitual interface
 * so this interface is created for these functions
 * these funtions are very important and powerful on usage,see their usage in their respective comments
 * many of them are modified from the compositive version and previously selected to write in this interface 
 * others are added to this interface gradually to meet our requirements in application
 * though the production of this interface is inferior
 * however,I think it is relatively useful in such a small project
 * that is what tools.h contains ^_^
 */



#ifndef _miscellany_h
#define _miscellany_h


#include<stdio.h>

/*
 * Function : Delay
 * Usage : Delay(delaytime,threadnum)
 * ----------------------
 * this function returns 0 once it is called for t milliseconds
 * then it returns 1 in threadnum(<1000)th thread
 */
 
int Delay(int delaytime,int threadnum);


/*
 * Function : Pulse
 * Usage : Pulse(T)
 * ----------------------
 * this function keeps return 0 for T seconds 
 * and return 1 when it has precisely passed k*T seconds(k is a positive integer) 
 * in threadnum(<1000)th thread
 */
 
int Pulse(int T,int threadnum);

/*
 * Function : Randnum
 * Usage : Randnum(a,b)
 * ----------------------
 * this function returns a pseudo random integral number between a and b  
 * a and b are not included in the range
 */
 
int Randnum(int a,int b); 
 
/*
 * Function : Sound 
 * Usage : Sound(type)
 * -------------------------
 * this functoin produces a certain sound responding to type
 * just call it and listen what them are
 */ 
 
int Sound(int type); 
 
/*
 * Function : Clear 
 * Usage : Clear(width,height)
 * -------------------------
 * this functoin clears the domain (x,y) to (x+width,y+height)by print spaces cover them
 *
 * To use this function,you need icons.h included
 */  
 
void Clear(int x,int y,int width,int height); 
 
 #endif
