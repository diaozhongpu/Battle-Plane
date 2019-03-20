#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

#include"icons.h"
#include"interface.h"
#include"miscellany.h"
#include"datamalloc.h"

#define width 80
#define height 30

int BPLpos_x = width/2;
int BPLpos_y = height - 5;
int BPLhealth = 100;

int terminate = 0;

void Cannon(int x,int y){
	
	DrawLine(x,y,height - y,'*','C');
	DrawLine(x-1,y,height - y,'|','C');
	DrawLine(x-2,y,height - y,'|','C');
	DrawLine(x+1,y,height - y,'|','C');
	DrawLine(x+2,y,height - y,'|','C');
	
}

void BoundLine(void)
{
	DrawLine(1,1,height,'|','C');
    DrawLine(2,1,height,'|','C');
    DrawLine(3,1,height,'|','C');
    DrawLine(width-2,1,height,'|','C');
    DrawLine(width-1,1,height,'|','C');
	DrawLine(width  ,1,height,'|','C');
}

void Boss()
{ 
	//define static variables
	static int flag = 0;
	 
	 
	static int bosshealth ;
	static int bosspos_x ;
	static int bosspos_y ;
	 
	static int bossfirestate ;
	static int bossfiremode ;
	static int bossrudder ;
	static int cannonstate ;
	  
	static int movestate = 0;//an important index that contols the tempo of the game
	 
	
	 
	static int **battery_bullets1 = bullet(2,100);
		
	static int **battery_bullets2 = bullet(2,100);
		
	static int **disperse_bullets = bullet(0,150);
		
	static int **wingplanes1 = enemyplane(0,10);
   	 
	static int **wingplanes2 = enemyplane(0,10);
	 
	static int *UH1 = bomb(1);
	 	
	static int *UH2 = bomb(1);
	 
	 //initialize static variables 
	if(!flag)
	{
		for(int i = -7;i <= 4;i++)
		{
	 		for(int j = 1;j < i+1;j++)DrawLine(width/2 - 16,j,32,' ','R');
			DrawBoss(width/2,i);
	 		Sleep(150);
	 	}
	 	
	 	flag = 1;
	 	
	 	bosshealth = 1000;
	 	bosspos_x = width/2;
	    bosspos_y = 4;
	 
	 	bossfirestate = 0;
	 	bossfiremode = 2;
	 	bossrudder = 1;//1 is right,while -1 is left
	 	cannonstate = 0;
	 	
	 	Initbullet(battery_bullets1,0,0,0,0,0,100);
	 	Initbullet(battery_bullets2,0,0,0,0,0,100);
	 	Initbullet(disperse_bullets,0,0,0,0,0,100);
	 	
	 	Initenemyplane(wingplanes1,0,0,0,0,10,20);
	 	Initenemyplane(wingplanes2,0,0,0,0,10,20);
	 	
	 	Initbomb(UH1,0,0,0,0);
	 	Initbomb(UH2,0,0,0,0);
	 }
	 
	 
	 
	 //display icons and clear old icons
	 //by the way calculate the damage
	 
	for (int i = 0; i < 20; i++)//wingplanes1 
	{
			//clear last image
		if(wingplanes1[i][1] <= width - 3&&wingplanes1[i][2] <=height&&wingplanes1[i][1] > 3&&wingplanes1[i][2] > 0)
		{
			DrawLine(wingplanes1[i][1]-2,wingplanes1[i][2],5,' ','R');
		
			wingplanes1[i][1] = wingplanes1[i][3];
			wingplanes1[i][2] = wingplanes1[i][4];	
		}
			
			//display new image
		if(wingplanes1[i][3] <= width - 3&&wingplanes1[i][4] <=height&&wingplanes1[i][3] > 3&&wingplanes1[i][4] > 0)
		{
			DrawEPL(wingplanes1[i][3],wingplanes1[i][4],0);
					
			if(abs(wingplanes1[i][3] - BPLpos_x )< 2&&abs(wingplanes1[i][4] - BPLpos_y) < 2)
			{
				wingplanes1[i][3] = 0;
				wingplanes1[i][4] = 0;
			
				BPLhealth -= 10;
				wingplanes1[i][6] = 0;
			}
		}		
		
	}
	
	for (int i = 0; i < 20; i++)//wingplanes2
	{
		if(wingplanes2[i][1] <= width - 3&&wingplanes2[i][2] <=height&&wingplanes2[i][1] > 3&&wingplanes2[i][2] > 0)
		{
			DrawLine(wingplanes2[i][1]-2,wingplanes2[i][2],5,' ','R');
			wingplanes2[i][1] = wingplanes2[i][3];
			wingplanes2[i][2] = wingplanes2[i][4];
		}	
		
		if(wingplanes2[i][3] <= width - 3&&wingplanes2[i][4] <=height&&wingplanes2[i][3] > 3&&wingplanes2[i][4] > 0)
		{
			DrawEPL(wingplanes2[i][3],wingplanes2[i][4],0);
			
			if(abs(wingplanes2[i][3] - BPLpos_x) < 2&&abs(wingplanes2[i][4] - BPLpos_y) < 2)
			{
				wingplanes2[i][3] = 0;
				wingplanes2[i][4] = 0;
				
				BPLhealth -= 20;
			}
		}
	}
     
    if(UH1[1] <= width - 3&&UH1[2] <=height&&UH1[1] > 3&&UH1[2] > 0)//UH1
	{
			gotoXY(UH1[1],UH1[2]);
			printf(" ");
			gotoXY(UH1[1] - 1,UH1[2] - 1);
			printf("   ");
			
			if(UH1[3] == 0&&UH1[4] == 0)
			{
				gotoXY(UH1[1] - 1,UH1[2]);
				printf("   ");
			}
			
			UH1[1] = UH1[3];
		    UH1[2] = UH1[4];
	}
	
	if(UH1[3] <= width - 3&&UH1[4] <=height&&UH1[3] > 3&&UH1[4] > 0)
    {
    	DrawB(UH1[3],UH1[4],0);
		
		UH1[4]+=2;
		
		if(UH1[3] == BPLpos_x&&abs(UH1[4] - BPLpos_y)<2)
			{
				UH1[3] = 0;
				UH1[4] = 0;
				BBExplode(UH1[3],UH1[4],0);
				
				BPLhealth -= 30;
			}
    }
  
    if(UH2[3] <= width - 3&&UH2[4] <=height&&UH2[3] > 3&&UH2[4] > 0)//UH2
    {
    		gotoXY(UH2[1],UH2[2]);
			printf(" ");
			gotoXY(UH2[1] - 1,UH2[2] - 1);
			printf("   ");
			
			if(UH2[3] == 0&&UH2[4] == 0)
			{
				gotoXY(UH2[1] - 1,UH2[2]);
				printf("   ");
			}
			
			UH2[1] = UH2[3];
			UH2[2] = UH2[4];
    	}
		
	if(UH2[3] <= width - 3&&UH2[4] <=height&&UH2[3] > 3&&UH2[4] > 0)
    {
    	DrawB(UH2[3],UH2[4],0);
		
		UH2[4]+=2;
		
		if(UH2[3] == BPLpos_x&&abs(UH2[4] - BPLpos_y)<2)
			{
				
				UH2[3] = 0;
				UH2[4] = 0;
				
				BPLhealth -= 30;
			}
		
    }
     
    for (int i = 0; i < 100; i++)//battery_bullets1
	{
		if(battery_bullets1[i][1] <= width - 3&&battery_bullets1[i][2] <=height&&battery_bullets1[i][1] > 3&&battery_bullets1[i][2] > 0)
		{
			gotoXY(battery_bullets1[i][3],battery_bullets1[i][4]);
			printf(" ");
			battery_bullets1[i][1] = battery_bullets1[i][3];
			battery_bullets1[i][2] = battery_bullets1[i][4];
		}
		
		if(battery_bullets1[i][3] <= width - 3&&battery_bullets1[i][4] <=height&&battery_bullets1[i][3] > 3&&battery_bullets1[i][4] > 0)
		{
			DrawBUL(battery_bullets1[i][3],battery_bullets1[i][4],2);
			
			if(battery_bullets1[i][3] == BPLpos_x&&battery_bullets1[i][3] == BPLpos_y)
			{
				battery_bullets1[i][3] = 0;
				battery_bullets1[i][4] = 0;
				
				BPLhealth -= 15;
			}
			
		}
	}
	
	for (int i = 0; i < 100; i++)//battery_bullets2
	{
		if(battery_bullets2[i][1] <= width - 3&&battery_bullets2[i][2] <=height&&battery_bullets2[i][1] > 3&&battery_bullets2[i][2] > 0)
		{
			gotoXY(battery_bullets2[i][3],battery_bullets2[i][4]);
			printf(" ");
			battery_bullets2[i][1] = battery_bullets2[i][3];
			battery_bullets2[i][2] = battery_bullets2[i][4];
		}
		
		if(battery_bullets2[i][3] <= width - 3&&battery_bullets2[i][4] <=height&&battery_bullets2[i][3] > 3&&battery_bullets2[i][4] > 0)
		{
			DrawBUL(battery_bullets2[i][3],battery_bullets2[i][4],2);
			
			if(battery_bullets2[i][3] == BPLpos_x&&battery_bullets2[i][3] == BPLpos_y)
			{
				battery_bullets2[i][3] = 0;
				battery_bullets2[i][4] = 0;
				
				BPLhealth -= 15;
			}
			
		}
	}
	
	for (int i = 0; i < 150; i++)//disperse_bullets
	{
		if(disperse_bullets[i][1] <= width - 3&&disperse_bullets[i][2] <=height&&disperse_bullets[i][1] > 3&&disperse_bullets[i][2] > 0)
		{
			gotoXY(disperse_bullets[i][3],disperse_bullets[i][4]);
			printf(" ");
			disperse_bullets[i][1] = disperse_bullets[i][3];
			disperse_bullets[i][2] = disperse_bullets[i][4];
		}
		
		if(disperse_bullets[i][3] <= width - 3&&disperse_bullets[i][4] <=height&&disperse_bullets[i][3] > 3&&disperse_bullets[i][4] > 0)
		{
			DrawBUL(disperse_bullets[i][3],disperse_bullets[i][4],0);
			
			if(disperse_bullets[i][3] == BPLpos_x&&disperse_bullets[i][3] == BPLpos_y)
			{
				disperse_bullets[i][3] = 0;
				disperse_bullets[i][4] = 0;
				
				BPLhealth -= 10;
			}
		}
	}
     
    if(bosshealth > 0)//Boss
    {
     	Clear(bosspos_x - 16,bosspos_y - 3,32,10);
	 	DrawBoss(bosspos_x,bosspos_y);	
	 	if(abs(bosspos_x - BPLpos_x) <= 15&&abs(bosspos_y - BPLpos_y)<=7)BPLhealth-=10;
     }
    else //what happens if boss dead?
	{
	 	PLExplode(bosspos_x + 5 ,bosspos_y + 3,1);
	 	BBExplode(bosspos_x - 10 ,bosspos_y + 4,0);
	 	Sleep(1000);
	 	PLExplode(bosspos_x + 5 ,bosspos_y + 3,1);
	 	BBExplode(bosspos_x + 10 ,bosspos_y + 4,0);
	 	Sleep(1000);
	 	BBExplode(bosspos_x,bosspos_y,0);
	 	Sleep(1000);
	 	 
		  //free the buffer
	 	free(battery_bullets1);
	 	free(battery_bullets2);
	 	free(disperse_bullets);
	 	free(UH1);
	 	free(UH2);
	 	free(wingplanes1);
	 	free(wingplanes2);
	 	
	 		//break the while loop
	 	terminate = 1;
	 }
	  	 
	 
	 int fstate = bossfirestate%200;//this data is used in case 2
	 
	 switch(bossfiremode)//fire of boss
	 {
	 	case 1://case 1:batteries shoot @ bullets and UH missiles
			if(bossfirestate%10&&!(bossfirestate%5))
			Initbullet(battery_bullets1,
					   bosspos_x - 4,bosspos_y + 3,
					   bosspos_x - 4,bosspos_y + 3,
					   bossfirestate%80,10);
			
	 		if(!(bossfirestate%5))
			Initbullet(battery_bullets2,
			           bosspos_x + 4,bosspos_y + 3,
					   bosspos_x + 4,bosspos_y + 3,
					   bossfirestate%80,10);
	 		
	 		if(bossfirestate % 160 && !(bossfirestate%80))
			Initbomb(UH1,bosspos_x-10,bosspos_y+5,bosspos_x-10,bosspos_y+5);
	 		
	 		if(!(bossfirestate % 80))
			Initbomb(UH1,bosspos_x+10,bosspos_y+5,bosspos_x+10,bosspos_y+5);
	 		
	 		if(bossfirestate >= 800)
			 {
			 	bossfirestate = 0;
			 	while((bossfiremode = Randnum(1,4)) != 1);	
			 } 
			 else bossfirestate++;
			 
	 		 break;
	 		
	 	case 2://case 2:shoot disperse * bullets
			 if(!(fstate%40))
			 {
				 Initbullet(disperse_bullets,
				 			bosspos_x,bosspos_y+5,
							bosspos_x,bosspos_y+5,
							fstate/4*3,30);
			 	  
			 }
	 		
	 		 if(bossfirestate >= 800)
			 {
			 	bossfirestate = 0;
			 	while((bossfiremode = Randnum(1,4)) != 2);	
			 } 
			 else bossfirestate++;
	 		 break;
	 		
	 	case 3://case 3:nuclear cannon
	 		if(bossfirestate<=20)
			{
				if(bossfirestate % 4)SpecialEffects(bosspos_x,bosspos_y+5,2);
				else 
				{
					DrawLine(bosspos_x-2,bosspos_y+5,5,' ','R');
					DrawLine(bosspos_x-1,bosspos_y+6,3,' ','R');
				}
			} 
			 
	 	
	 		if(bossfirestate>20)Cannon(bosspos_x,bosspos_y+5);
	 		
	 		if(bossfirestate >= 50)
			 {
			 	bossfirestate = 0;
			 	while((bossfiremode = Randnum(1,4)) != 3);	
			 } 
			 else bossfirestate++;
	 		break;
	 		
	 	case 4://produce wing planes
			if(!(bossfirestate % 100))
			 {
				Initenemyplane(wingplanes1,
				               bosspos_x + 17 ,bosspos_y + 3,
							   bosspos_x + 17 ,bosspos_y + 3,
							   10,10);
							   
				Initenemyplane(wingplanes2,
				               bosspos_x - 17 ,bosspos_y + 3,
							   bosspos_x - 17 ,bosspos_y + 3,
							   10,10);
			 }
			 
			 if(bossfirestate >= 200)
			 {
			 	bossfirestate = 0;
			 	while((bossfiremode = Randnum(1,4)) != 4);	
			 } 
			 break;
			 	
	 	default:
	 		break;
	 }
	 
	 
	 if(!(movestate % 10))//boss will keep moving between width/2 - 10 and width/2 + 10
	 {
	 	 if(bossrudder == 1)
	 	 {
	 	 	bosspos_x+=2;
	 	 	if(bosspos_x >= width/2 + 10)bossrudder = -bossrudder;
	 	 }
	 	 
	 	 if(bossrudder == -1)
	 	 {
	 	 	bosspos_x-=2;
	 	 	if(bosspos_x <= width/2 - 10)bossrudder = -bossrudder;
	 	 }
	 	 	 	 
		 if(movestate >= 100)movestate = 0;
	 }
	 else if(bossfiremode != 3)movestate++;
	 
	 
	 
}


 
int main(){
	
	HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cinfo;

	cinfo.bVisible = 0;

	cinfo.dwSize = 1;

	SetConsoleCursorInfo(fd, &cinfo);
	
	while(!terminate)
	{
		BoundLine();
		
		Boss();
		
		Sleep(25);
	}
	
	return Completed(width,height);
}


/*
main(){
	
	int **disperse_bullets = bullet(1,100);
	
	Initbullet(disperse_bullets,40,4,0,100);
	
	while(1)
	{
		disperse(disperse_bullets,0,10);
	
		for(int i = 0;i < 100;i++)
		 {
			if(disperse_bullets[i][1]<width,disperse_bullets[i][2]<height)
			{
		 		DrawBUL(disperse_bullets[i][1],disperse_bullets[i][2],2);
				disperse_bullets[i][2]+=2;
			}
		 }
		 
		Sleep(1000);
	 
	}
	
}

*/
