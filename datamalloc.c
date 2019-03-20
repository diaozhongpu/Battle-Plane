#include<stdlib.h>
#include<stdio.h>

int **bullet(int type,int num)
{
	int i;
	int **bup;
	bup = (int**) malloc (num * sizeof ( int ) );
	for(i = 0;i < num;i++)
	{
		bup[i] = (int *)malloc( 6 * sizeof ( int ) );
		bup[i][0] = type;
	}
	return bup;
}

int **enemyplane(int type,int num)
{
	int i;
	int ** ptr;
	ptr = (int **)malloc(num * sizeof (int *));
	for(i=0;i<num;i++)
	{
		ptr[i] = (int *)malloc(7 * sizeof (int));
		ptr[i][0] = type;
	}
	return ptr;
}

int *bomb(int type)
{
	int *bop;
	bop = (int *) malloc ( 6 * sizeof ( int )) ;
	bop[0] = type;
	return bop;
}

void Initbullet(int **bup,int last_x,int last_y,int pos_x,int pos_y,int index,int num)
{
	for(int i = index;i<index+num;i++)
	{ 
		bup[i][1] = last_x;
		bup[i][2] = last_y;
		bup[i][3] = pos_x;
		bup[i][4] = pos_y;
		bup[i][5] = 0;
	}	 
}

void Initenemyplane(int **ptr,int last_x,int last_y,int pos_x,int pos_y,int health,int num)
{
	for(int i = 0;i < num ;i++)
	{
		ptr[i][1] = last_x;
		ptr[i][2] = last_y;
		ptr[i][3] = pos_x;
		ptr[i][4] = pos_y;
		ptr[i][5] = 0;
		ptr[i][6] = health;
	}
}

void Initbomb(int *bop,int last_x,int last_y,int pos_x,int pos_y)
{
		bop[1] = last_x;
		bop[2] = last_y;
		bop[3] = pos_x;
		bop[4] = pos_y;
		bop[5] = 0;
}

void FreeMemoryBomb(int *ptr)
{
		free(ptr);	
}


void InnerFreeMemory(int **ptr,int index,int num)
{
	for(int i = index;i < index + num;i++)
	{
			free(ptr[i]);	
	}	
}


void OuterFreeMemory(int **ptr)
{
	free(ptr);
}


void CompleFreeMemory(int **ptr,int index,int num)
{
	for(int i = index;i < index + num;i++)
	{
			free(ptr[i]);	
	}
	free(ptr);	
}




