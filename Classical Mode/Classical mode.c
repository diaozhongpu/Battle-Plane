/* Classical mode
 * based on 0.23 beta
 */
#include<stdio.h>
#include<time.h>

#include"icons.h"
#include"miscellany.h"
#include"datamalloc.h"
#include"interface.h"
#include"movement.h" 
 
 
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEYUP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

int BPLpos_x;
int BPLpos_y;
int BPLhealth;
int BPLspeed;
int BPLdef;

int firemod;
int firepower;
int laser[3];

int score;
int level;

int inittime;
int nowtime;



void mainloop(void);
void Auto(void);
void Dataops(void);
void Damage(void);
void Input(void);
void Fire(void);
void Levelup(void);
void Bombset(void);
 
 
 
int Classical(void)
{
	
	static int flag = 0;
	static int ** enemyplane1 = enemyplane(0,10);
	static int ** enemyplane2 = enemyplane(1,10);
	static int ** enemyplane3 = enemyplane(2,10);
	
	static int ** bullets1 = bullet(0,300);
	static int ** bullets2 = bullet(3,400);
	static int * bomb[5];
	
	static int explodepoint[5];
	
	if(!flag)
	{
		flag = 1;
		
		for(int i = 0;i < 5;i++)
		{
			bomb[i] = bomb(0);
			Initbomb(bomb[i],0,0,0,0);
			
			explodepoint[5] = 0;
		}
		
		Initenemyplane(enemyplane1,0,0,0,0,10,10);
		Initenemyplane(enemyplane2,0,0,0,0,50,10);
		Initenemyplane(enemyplane3,0,0,0,0,50,10);
		
		Initbullet(bullets1,0,0,0,0,0,300);
		Initbullet(bullets1,0,0,0,0,0,400);
		
		inittime = (int)time(NULL);
	} 
	
	mainloop();
	
}

void mainloop(void)
{
	while()
	{
		Auto();
		Input();
	}
}	

void Auto(void)
{	
	Dataops();//update health,reset the dead and used bullet,plus score

	Levelup();//raise the game level according to time passed

	Sleep(25);//waiting for a short tim
}

void Input(void)
{
	if( GetAsyncKeyState(0x57) & 0x8000 ) //'w':forward
	{	
		if(planepos_y > speedup + 1)planepos_y -= (speedup + 1);
		else if(planepos_y > 2)planepos_y--;
	}
	
	if( GetAsyncKeyState(0x53) & 0x8000 ) //'s':backward
	{
		if(planepos_y < height - speedup - 1)planepos_y += (speedup + 1);
		else if(planepos_y < height - 2)planepos_y++;		
	}
	
	if( GetAsyncKeyState(0x41) & 0x8000 ) //'a':left
	{ 
		if(planepos_x > speedup + 1)planepos_x -= (speedup + 1);
		else if(planepos_x > 2)planepos_x--;//this idedtifaction prevents the plane leap up of sight when speedup is high
	}
			
	if( GetAsyncKeyState(0x44) & 0x8000 ) //'d':right 
	{
		if(planepos_x < width - speedup - 1)planepos_x += (speedup + 1);
			else if(planepos_x < width -2)planepos_x++;
	}
	
	if( GetAsyncKeyState(0x20) & 0x8000 ) //space:fire of the battleplane
		Fire();
	
	if( GetAsyncKeyState(0x4D) & 0x8000 ) //'n':bomb
		Bombset();
		
		
	if( GetAsyncKeyState(0x52) & 0x8000 ) //'r':pause
	{
		switch(Pausegame(width,height))
		{
			case 2£º
				goto L3;
				break;
			
			case 4:
				break;
				
			case 6:
				//storedata();
				goto L1;
				break;
		}
}

void Dataops(void)
{	
	nowtime = (int)time(NULL);

	for(int i = 0,i < 10;i++)
	{
		if(enemyplane1[i][1] <= width&&enemyplane1[i][2]<=height&&enemyplane1[i][1] > 0&&enemyplane1[i][2] > 0)
		{
			DrawLine(enemyplane1[i][1]-2,enemyplane1[i][2],5,' ','R');
			enemyplane1[i][1] = enemyplane1[i][3];
			enemyplane1[i][2] = enemyplane1[i][4]; 
		}
		 
		if(enemyplane1[i][3] <= width&&enemyplane1[i][4] <=height&&enemyplane1[i][3] > 0&&enemyplane1[i][4] > 0)
		{
			DrawEPL(enemyplane1[i][3],enemyplane1[i][4],0);
			
			if(abs(enemyplane1[i][3] - BPLpos_x)<2&&abs(enemyplane1[i][4] - BPLpos_y)<2)
			{
				enemyplane1[i][3] = 0;
				enemyplane1[i][4] = 0;
				
				enemyplane1[i][6] = 0;
				BPLhealth -= 10;
			}
			
		}
	}
	
	for(int i = 0,i < 10;i++)
	{	
		if(enemyplane2[i][1] <= width&&enemyplane2[i][2]<=height&&enemyplane2[i][1] > 0&&enemyplane2[i][2] > 0)
		{
			DrawLine(enemyplane2[i][1]-2,enemyplane2[i][2],5,' ','R');
			enemyplane2[i][1] = enemyplane2[i][3];
			enemyplane2[i][2] = enemyplane2[i][4];
		}
		 
		if(enemyplane2[i][3] <= width&&enemyplane2[i][4] <=height&&enemyplane2[i][3] > 0&&enemyplane2[i][4] > 0)
		{
			DrawEPL(enemyplane2[i][3],enemyplane2[i][4],1);
			
			if(abs(enemyplane2[i][3] - BPLpos_x)<2&&abs(enemyplane2[i][4] - BPLpos_y)<2)
			{
				enemyplane2[i][3] = 0;
				enemyplane2[i][4] = 0;
				
				enemyplane2[i][6] = 0;
				BPLhealth -= 30;
			}
		}
	}
		
	for(int i = 0,i < 10;i++)
	{	
		if(enemyplane3[i][1] <= width&&enemyplane3[i][2]<=height&&enemyplane3[i][1] > 0&&enemyplane3[i][2] > 0)
		{
			DrawLine(enemyplane3[i][1]-2,enemyplane3[i][2],5,' ','R');
			enemyplane3[i][1] = enemyplane3[i][3];
			enemyplane3[i][2] = enemyplane3[i][4];
		}
		 
		if(enemyplane3[i][3] <= width&&enemyplane3[i][4] <=height&&enemyplane3[i][3] > 0&&enemyplane3[i][4] > 0)
		{
			DrawEPL(enemyplane3[i][3],enemyplane3[i][4],2);
			
			if(abs(enemyplane3[i][3] - BPLpos_x)<2&&abs(enemyplane3[i][4] - BPLpos_y)<2)
			{
				enemyplane3[i][3] = 0;
				enemyplane3[i][4] = 0;
				
				enemyplane3[i][6] = 0;
				BPLhealth -= 30;
			}
		}
	}
	
	for(int i = 0;i < 5;i++)
	{
		if(bomb[i][1] <= width&&bomb[i][2]<=height&&bomb[i][1] > 0&&bomb[i][2] > 0)
		{
			gotoXY(bomb[i][1],bomb[i][2])printf(" ");
			gotoXY(bomb[i][1],bomb[i][2] + 1)printf(" ");
			
			bomb[i][1] = bomb[i][3];
			bomb[i][2] = bomb[i][4];
		}
		if(bomb[i][3] <= width&&bomb[i][4] <=height&&bomb[i][3] > 0&&bomb[i][4] > 0)
		{
			DrawB(bomb[i][3],bomb[i][4]);
			
			bomb[i][4]--;
			
		}
	}
}
	
void Damage(void)
{
	if(health == 0)
	{
		switch(Gameover())
				{
					case 2:
						goto L3;
						break;
					
					case 4:
						
						//load data
						
						//reinitialize basic data
						
						goto L3;
						break;
				
					case 6:
						goto L1;
						break;
				}
	}
}

void Fire()
{
	if (firemod == 0) 
	{
			int u[firepower];
		
			for (int w = 0; w < firepower; w++) 
			u[w] = 1 + (BULLETMAX - firepower) / firepower * w;
		

			for (int v = 0; v < firepower; v++) 
			{
				while (1) 
				{
					if (bullet[u[v]][4] == width + 5 && bullet[u[v][5] == height + 5) 
					{
						bullet[u[v]][5] = BPLpos_y - 1;
						bullet[u[v]][4] = BPLpos_x - firepower + 1 + 2 * v;
						break;
					}
					else {
						u[v]++;
						if (u[v] >= BULLETMAX) u[v] = 0;
					}
				}
			}
		
			firestate = 0;
		}
	}
	
	else if (firemod == 1) //use laser to attack
		{
			if(firepower == 1 || firepower == 2)
			    laser[1] = 1;
			    
			if(firepower == 3)
			{
				laser[0] = 1;
				laser[2] = 1;
			}
			
			if(firepower == 4)
			{
				laser[0] = 1;
				laser[1] = 1;
				laser[2] = 1;
			}

		}	
}

void Bombset(void)
{
	int i = 1;
	while(1)
	{
		if(bomb[i][1] == 0)
		{
			Initbomb(bomb[i],BPLpos_x,BPLpos_y - 1,BPLpos_x,BPLpos_y - 1);
			break;	
		}
		else i++;
	}
}

















