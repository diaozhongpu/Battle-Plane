/* interface.h
 * 
 *
 * Author :
 * 
 */

#ifndef _movement_h
#define _movement_h


#include<stdio.h>
#include <math.h>

/* 
 * Function Prototype: movealongline(int ** PTR,int i,int n,int velocity)
 * Usage : movealongline(the pointer to the plane, 
 *                       the serial number of the first plane to move, 
 *						 the total number, 
 *                       the distance to move this time);
 *-------------------------------------------------------------------------------
 * this fuction write new x/y axis position for plane/bullet moving along a line;
 */

void movealongline(int ** PTR,int i,int n,int velocity);

/* 
 * Function Prototype: disperse(int ** PTR,int i,int n)
 * Usage : disperse(the pointer to the plane, 
 *                  the serial number of the first plane to move, 
 *					the total number)
 *-----------------------------------------------------------------------------------------------
 * this function produce a series of plane dispersed from one signle plane when called first time
 * 
 * attention! the storage after the first plane should be accessible
 *
 */

void disperse(int ** PTR,int i,int n);

/*
 * Function Prototype: interlude(int ** PTR,int i,int n,int h,int w)
 * Usage : disperse(the pointer to the plane, 
 *                  the serial number of the first plane to move, 
 *					the total number)
 *-------------------------------------------------------------------------------
 * 
 * 
 * 
 * 
 */

void interlude(int ** PTR,int i,int n,int h,int w);



#endif
