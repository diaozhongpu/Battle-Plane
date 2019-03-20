/* interface.c
 * this library contains functions that produce menu options,
 * which help the player start game, choose game mode and level, exit ,check their record ,etc. 
 * these finctions are simple fuctions that print backgrounds and options
 * use a loop to check the of the input of a player timely
 * the design is awkward ,even digusting,but the writter promised that time permitting
 * he will deal with this small mess in person
 */
  
#include<stdio.h> 
#include"icons.h"
#include<windows.h>


int Startgame(int width,int height)
{
	int lastop = height / 2 + 2;
	
	gotoXY(width/2-10,lastop);
	printf("[>");
	gotoXY(width/2-4,height/2+2);
	printf(" New Game");
	gotoXY(width/2-4,height/2+4);
	printf("  Reload ");
	gotoXY(width/2-4,height/2+6);
	printf("   Exit  ");
	
	gotoXY(width/2-12,height/2+11);
	printf("Press 'W' and 'S' To Switch");
	gotoXY(width/2-9,height/2+12);
	printf("Press Space To Select ");
		
	while(1)
	{		
		if(GetAsyncKeyState(0x57) & 0x8000 ) 
		{
			gotoXY(width/2-10,lastop);
			printf("  ");
			
			if(lastop > height/2 + 2 )lastop -= 2;
		    
			gotoXY(width/2-10,lastop);
			printf("[>");
			
			Sleep(150);
		}
			
		if( GetAsyncKeyState(0x53) & 0x8000 ) 
		{
			gotoXY(width/2-10,lastop);
			printf("  ");
			
			if(lastop < height/2 + 6)lastop += 2;
			
			gotoXY(width/2-10,lastop);
			printf("[>");
			
			Sleep(150);
		}
			
		if( GetAsyncKeyState(0x20) & 0x8000 )
		{
			Sleep(100);
			gotoXY(width/2-10,lastop);
			printf("  ");
			for(int i = 0;i < 3;i++)
			{
				DrawLine(width/2-5,lastop-1,10,'_','R');
				DrawLine(width/2-7,lastop,1,'[','R');
				DrawLine(width/2+7,lastop,1,']','R');
				DrawLine(width/2-5,lastop+1,10,'-','R');
				Sleep(150);
				DrawLine(width/2-5,lastop-1,10,' ','R');
				DrawLine(width/2-7,lastop,1,' ','R');
				DrawLine(width/2+7,lastop,1,' ','R');
				DrawLine(width/2-5,lastop+1,10,' ','R');
				Sleep(50);
			}
			return (lastop - height/2);			
		}
	}
}

int Modechoose(int width,int height)
{
	int lastop = height / 2 - 2;
	
	gotoXY(width/2-6,height/2 - 6);
	printf(" Mode Choose ");
	DrawLine(width/2-6,height/2 - 5,12,'-','R');
	gotoXY(width/2-12,lastop);
	printf("[>");
	gotoXY(width/2-8,height/2 - 2);
	printf(" Adventure Mode ");
	gotoXY(width/2-8,height/2);
	printf(" Challenge Mode ");
	gotoXY(width/2-8,height/2 + 2);
	printf(" Classical Mode");
	gotoXY(width/2-8,height/2 + 4);
	printf("   War     Mode ");
	gotoXY(width/2-4,height/2 + 8);
	printf("  Exit  ");
	
	while(1)
	{		
		if(GetAsyncKeyState(0x57) & 0x8000 ) 
		{
			gotoXY(width/2-12,lastop);
			printf("  ");
			
			if(lastop == height/2 + 8)lastop -= 4;
			else if(lastop > height/2 - 2 )lastop -= 2;
		    
			gotoXY(width/2-12,lastop);
			printf("[>");
			
			Sleep(150);
			
		}
			
		if( GetAsyncKeyState(0x53) & 0x8000 ) 
		{
			gotoXY(width/2-12,lastop);
			printf("  ");
			
			if(lastop < height/2 + 4)lastop += 2;
			else if(lastop == height/2 + 4)lastop += 4;
		
			gotoXY(width/2-12,lastop);
			printf("[>");
			
			Sleep(150);
			
		}
			
		if( GetAsyncKeyState(0x20) & 0x8000 )
		{
			Sleep(100);
			gotoXY(width/2-12,lastop);
			printf("  ");
			for(int i = 0;i < 3;i++)
			{
				DrawLine(width/2-10,lastop-1,19,'_','R');
				DrawLine(width/2-11,lastop,1,'[','R');
				DrawLine(width/2+9,lastop,1,']','R');
				DrawLine(width/2-10,lastop+1,19,'-','R');
				Sleep(150);
				DrawLine(width/2-10,lastop-1,19,' ','R');
				DrawLine(width/2-11,lastop,1,' ','R');
				DrawLine(width/2+9,lastop,1,' ','R');
				DrawLine(width/2-10,lastop+1,19,' ','R');
				Sleep(50);
			}
			return (lastop - height/2 + 2);					
		}
	}
}

int Levelchoose(int width,int height)
{
	int lastop = height / 2;
	
	gotoXY(width/2-7,height/2 - 6);
	printf(" Level Choose ");
	DrawLine(width/2-7,height/2 - 5,14,'-','R');
	gotoXY(width/2-10,lastop);
	printf("[>");
	gotoXY(width/2-4,height/2);
	printf("  Easy  ");
	gotoXY(width/2-4,height/2 + 2);
	printf(" Normal ");
	gotoXY(width/2-4,height/2 + 4);
	printf("  Hard  ");
	
	gotoXY(width/2-4,height/2 + 8);
	printf("  Exit  ");
	
	while(1)
	{		
		if(GetAsyncKeyState(0x57) & 0x8000 ) 
		{
			gotoXY(width/2-10,lastop);
			printf("  ");
			
			if(lastop == height/2 + 8)lastop -= 4;
			else if(lastop > height/2)lastop -= 2;
		    
			gotoXY(width/2-10,lastop);
			printf("[>");
			
			Sleep(150);
			
		}
			
		if( GetAsyncKeyState(0x53) & 0x8000 ) 
		{
			gotoXY(width/2-10,lastop);
			printf("  ");
			
			if(lastop < height/2 + 4)lastop += 2;
			else if(lastop == height/2 + 4)lastop += 4;
		
			gotoXY(width/2-10,lastop);
			printf("[>");
			
			Sleep(150);
			
		}
			
		if( GetAsyncKeyState(0x20) & 0x8000 )
		{
			Sleep(100);
			gotoXY(width/2-10,lastop);
			printf("  ");
			for(int i = 0;i < 3;i++)
			{
				DrawLine(width/2-8,lastop-1,15,'_','R');
				DrawLine(width/2-9,lastop,1,'[','R');
				DrawLine(width/2+7,lastop,1,']','R');
				DrawLine(width/2-8,lastop+1,15,'-','R');
				Sleep(150);
				DrawLine(width/2-8,lastop-1,15,' ','R');
				DrawLine(width/2-9,lastop,1,' ','R');
				DrawLine(width/2+7,lastop,1,' ','R');
				DrawLine(width/2-8,lastop+1,15,' ','R');
				Sleep(50);
			}
			return (lastop - height/2 + 2);					
		}
	}
}


int Clearance(int width,int height)
{
	DrawLine(4,height/2 - 3,width - 8,'-','R');
	DrawLine(4,height/2 + 3,width - 8,'-','R');
	DrawLine(4,height/2 - 2,width - 8,'*','R');
	DrawLine(4,height/2 + 2,width - 8,'*','R');
	DrawLine(4,height/2 - 1,width - 8,'-','R');
	DrawLine(4,height/2 + 1,width - 8,'-','R');
	gotoXY(width/2 - 9,height/2);
	printf(" Mission Completed ");
	
	Sleep(3000);
	
	//load data...
	
	DrawLine(4,height/2 - 1,width - 8,' ','R');
	DrawLine(4,height/2 - 2,width - 8,'_','R');
	for(int i = 2;i < 9; i++)
	{
		DrawLine(4,height/2 + i - 1,width - 8,' ','R');
		DrawLine(4,height/2 + i + 1,width - 8,' ','R');
		DrawLine(4,height/2 + i    ,width - 8,'_','R');
		DrawLine(4,height/2 + i + 2,width - 8,'-','R');
		Sleep(20);
	}
	
	
	int lastop = height / 2 + 2;
	gotoXY(width/2-10,lastop);
	printf("[>");
	gotoXY(width/2-6,height/2 + 2);
	printf(" Next Level ");
	gotoXY(width/2-3,height/2 + 4);
	printf(" Load ");
	gotoXY(width/2-3,height/2 + 6);
	printf(" Quit ");
	
	while(1)
	{		
		if(GetAsyncKeyState(0x57) & 0x8000 ) 
		{
			gotoXY(width/2-10,lastop);
			printf("  ");
			
		    if(lastop > height/2 + 2)lastop -= 2;
		    
			gotoXY(width/2-10,lastop);
			printf("[>");
			
			Sleep(150);
			
		}
			
		if( GetAsyncKeyState(0x53) & 0x8000 ) 
		{
			gotoXY(width/2-10,lastop);
			printf("  ");
			
			if(lastop < height/2 + 6)lastop += 2;
			
		
			gotoXY(width/2-10,lastop);
			printf("[>");
			
			Sleep(150);
			
		}
			
		if( GetAsyncKeyState(0x20) & 0x8000 )
		{
			Sleep(100);
			gotoXY(width/2-10,lastop);
			printf("  ");
			for(int i = 0;i < 3;i++)
			{
				DrawLine(width/2-8,lastop-1,15,'_','R');
				DrawLine(width/2-9,lastop,1,'[','R');
				DrawLine(width/2+7,lastop,1,']','R');
				DrawLine(width/2-8,lastop+1,15,'-','R');
				Sleep(150);
				DrawLine(width/2-8,lastop-1,15,' ','R');
				DrawLine(width/2-9,lastop,1,' ','R');
				DrawLine(width/2+7,lastop,1,' ','R');
				DrawLine(width/2-8,lastop+1,15,' ','R');
				Sleep(50);
			}
			return (lastop - height/2);					
		}
	}
}

int Pausegame(int width,int height)
{
	
	DrawLine(6,height/2 - 4,width - 12,'_','R');
	DrawLine(6,height/2 - 1,width - 12,'_','R');
	gotoXY(width/2 - 3,height/2 - 2);
	printf(" Pause ");
	Sleep(100);
	for(int i = 0;i < 9; i++)
	{
		DrawLine(6,height/2 + i - 1,width - 12,' ','R');
		DrawLine(6,height/2 + i,width - 12,'_','R');
	}
	
	int lastop = height / 2 + 2;
	gotoXY(width/2-10,lastop);
	printf("[>");
	gotoXY(width/2-3,height/2 + 2);
	printf(" Renew ");
	gotoXY(width/2-4,height/2 + 4);
	printf(" Continue ");
	gotoXY(width/2-3,height/2 + 6);
	printf(" Quit  ");
	
	while(1)
	{		
		if(GetAsyncKeyState(0x57) & 0x8000 ) 
		{
			gotoXY(width/2-10,lastop);
			printf("  ");
			
		    if(lastop > height/2 + 2)lastop -= 2;
		    
			gotoXY(width/2-10,lastop);
			printf("[>");
			
			Sleep(150);
			
		}
			
		if( GetAsyncKeyState(0x53) & 0x8000 ) 
		{
			gotoXY(width/2-10,lastop);
			printf("  ");
			
			if(lastop < height/2 + 6)lastop += 2;
			
		
			gotoXY(width/2-10,lastop);
			printf("[>");
			
			Sleep(150);
			
		}
			
		if( GetAsyncKeyState(0x20) & 0x8000 )
		{
			Sleep(100);
			gotoXY(width/2-10,lastop);
			printf("  ");
			for(int i = 0;i < 3;i++)
			{
				DrawLine(width/2-6,lastop-1,12,'_','R');
				DrawLine(width/2-7,lastop,1,'[','R');
				DrawLine(width/2+6,lastop,1,']','R');
				DrawLine(width/2-6,lastop+1,12,'-','R');
				Sleep(150);
				DrawLine(width/2-6,lastop-1,12,' ','R');
				DrawLine(width/2-7,lastop,1,' ','R');
				DrawLine(width/2+6,lastop,1,' ','R');
				DrawLine(width/2-6,lastop+1,12,' ','R');
				Sleep(50);
			}
			return (lastop - height/2);					
		}
	}
}


int Gameover(int width,int height)
{
	
	DrawLine(4,height/2 - 1,width - 8,'-','R');
	DrawLine(4,height/2 + 1,width - 8,'-','R');
	gotoXY(width/2 - 5,height/2);
	printf(" Game Over ");
	
	Sleep(1000);
	
	//load data...
	
	DrawLine(4,height/2 - 1,width - 8,' ','R');
	DrawLine(4,height/2 - 2,width - 8,'_','R');
	for(int i = 2;i < 9; i++)
	{
		DrawLine(4,height/2 + i - 1,width - 8,' ','R');
		DrawLine(4,height/2 + i,width - 8,'_','R');
		Sleep(20);
	}
	
	int lastop = height / 2 + 2;
	gotoXY(width/2-8,lastop);
	printf("[>");
	gotoXY(width/2-3,height/2 + 2);
	printf(" Renew  ");
	gotoXY(width/2-3,height/2 + 4);
	printf(" Revive ");
	gotoXY(width/2-3,height/2 + 6);
	printf(" Quit ");
	
	while(1)
	{		
		if(GetAsyncKeyState(0x57) & 0x8000 ) 
		{
			gotoXY(width/2-8,lastop);
			printf("  ");
			
		    if(lastop > height/2 + 2)lastop -= 2;
		    
			gotoXY(width/2-8,lastop);
			printf("[>");
			
			Sleep(150);
			
		}
			
		if( GetAsyncKeyState(0x53) & 0x8000 ) 
		{
			gotoXY(width/2-8,lastop);
			printf("  ");
			
			if(lastop < height/2 + 6)lastop += 2;
			
		
			gotoXY(width/2-8,lastop);
			printf("[>");
			
			Sleep(150);
			
		}
			
		if( GetAsyncKeyState(0x20) & 0x8000 )
		{
			Sleep(100);
			gotoXY(width/2-10,lastop);
			printf("  ");
			for(int i = 0;i < 3;i++)
			{
				DrawLine(width/2-4,lastop-1,8,'_','R');
				DrawLine(width/2-5,lastop,1,'[','R');
				DrawLine(width/2+5,lastop,1,']','R');
				DrawLine(width/2-4,lastop+1,8,'-','R');
				Sleep(150);
				DrawLine(width/2-4,lastop-1,8,' ','R');
				DrawLine(width/2-5,lastop,1,' ','R');
				DrawLine(width/2+5,lastop,1,' ','R');
				DrawLine(width/2-4,lastop+1,8,' ','R');
				Sleep(50);
			}
			return (lastop - height/2);					
		}
	}
}





