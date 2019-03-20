   
#ifndef _datamalloc_h
#define _datamalloc_h

#include<stdio.h>

int **bullet(int type,int num);
/*
* Function :create a two-dimensional pointer to store bullet's data
* Usage : bullet(type,num)
------------------------------------
* this function creating two-dimensional bullet pointer the first dimension stored 
* ordinal number (from 0 to num-1) and first address [ 0 ] of the second dimension 
* stored the type of the bullet 
*/
int **enemyplane(int type,int num);
/*
* Function :create a two-dimensional pointer to store enemyplane's data
* Usage : enemyplane(type,num)
------------------------------------
* this function creating two-dimensional  pointer the first dimension stored 
* ordinal number (from 0 to num-1) and first address [ 0 ] of the second dimension 
* stored the type of the enemyplane 
*/
int *bomb(int type);
/*
* Function :create a one-dimensional pointer to store bomb's data
* Usage : bomb(type)
------------------------------------
* this function creating one-dimensional pointer malloc the memory of 
* six int lengths and the first one store the type of the bomb
*/
void Initbullet(int **bup,int last_x,int last_y,int pos_x,int pos_y,int index,int num);
/*
* Function :initialize bullets' data
* Usage : Initbullet(**bup,last_x,last_y,pos_x,pos_y, index, num);
------------------------------------
* this function use the pointer to find address of the bullets 
* and then initialize their parameters
* bijection below
* point[num][0]     type
* point[num][1]     last_x 
* point[num][2]     last_y 
* point[num][3]     pos_x  
* point[num][4]     pos_y
* point[num][5]     statue     
*/
void Initenemyplane(int **ptr,int last_x,int last_y,int pos_x,int pos_y,int health,int num);
/*
* Function :initialize enemyplane' data
* Usage : Initenemyplane(**ptr,last_x,last_y,pos_x,pos_y,health,num);
------------------------------------
* this function use the pointer to find address of the enemyplanes
* and then initialize their parameters
* bijection below
* point[num][0]     type
* point[num][1]     last_x 
* point[num][2]     last_y 
* point[num][3]     pos_x  
* point[num][4]     pos_y
* point[num][5]     statue
* point[num][6]     health  
*/
void Initbomb(int *bop,int last_x,int last_y,int pos_x,int pos_y);
/*
* Function :initialize bomb' data
* Usage : Initbullet(*bop,last_x,last_y,pos_x,pos_y);
------------------------------------
* this function use the pointer to find address of the bomb
* and then initialize it's parameters
* bijection below
* point[0]     type
* point[1]     last_x 
* point[2]     last_y 
* point[3]     pos_x  
* point[4]     pos_y
* point[5]     statue     
*/
void FreeMemoryBomb(int *ptr);
/*
* Function :free bomb memory
* Usage : FreeMemoryBomb (*ptr)
---------------------------
* release dynamic memory that is no longer needed
*/
void InnerFreeMemory(int **ptr,int index,int num);
/*
* Function :partly free bullet or plane memory
* Usage : InnerFreeMemory(**ptr,index,num)
---------------------------
* release dynamic memory that is no longer needed
* but it can just release the second required allocation
* memory , and the first time required memory still has
* inner memory 
*/
void OuterFreeMemory(int **ptr);
/*
* Function :partly free bullet or plane memory
* Usage : OuterFreeMemory(**ptr)
---------------------------
* release dynamic memory that is no longer needed
* be sure that all the memory related to this pointer has
* been released then use this function to release 
* outer memory to free it completely
*/
void CompleFreeMemory(int **ptr,int index,int num);
/*
* Function :completely free bullet or plane memory
* Usage : CompleFreeMemory(**ptr,index,num)
---------------------------
* release dynamic memory that is no longer needed
* it can release all the memory extended by this 
* pointer
*/

#endif
