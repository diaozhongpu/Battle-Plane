/*
 * File : iocns.c
 * ------------------
 * including a series of functions printing charactor icons used in our project
 * the mechanism is very plain,so there is not much comments
 * just see what written in icons.h for some necessary information
 */
 
 #include<stdio.h>
 #include<windows.h>


/* Function : gotoXY()
 * --------------------------------------------------
 * this function is modified from a prototype on CSDN
 * I am not familiar with crood so it is only used in this function
 * but that is enough for us
 */
 
 void gotoXY(int x, int y)
{
	//Initialize the coordinates
	COORD coord = { x-1, y-1 };
	//Set the position
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}


void Character(int x,int y,char ch)
{
	switch(ch)
	{
		case 'B':
			gotoXY(x,y-4);
			if(y>4&&x>0)printf(" __");
			gotoXY(x,y-3);
			if(y>3&&x>0)printf("|  \\");
			gotoXY(x,y-2);
			if(y>2&&x>0)printf("|__/");
			gotoXY(x,y-1);
			if(y>1&&x>0)printf("|  \\");
			gotoXY(x,y);
			if(y>0&&x>0)printf("|__/");
			break;
			
		case 'A':
			gotoXY(x,y-2);			
			if(y>2&&x>0)printf(" _");
			gotoXY(x,y-1);
			if(y>1&&x>0)printf("/_\\");
			gotoXY(x,y);
			if(y>0&&x>0)printf("| |");
			break;
			
		case 't':
			gotoXY(x,y-2);
			if(y>2&&x>0)printf("_|_");
			gotoXY(x,y-1);
			if(y>1&&x>0)printf(" |");
			gotoXY(x,y);
			if(y>0&&x>0)printf(" |_");
			break;
			
		case 'L':
			gotoXY(x,y-2);
			if(y>2&&x>0)printf("|");
			gotoXY(x,y-1);
			if(y>1&&x>0)printf("|");
			gotoXY(x,y);
			if(y>0&&x>0)printf("|_");
			break;
			
		case 'e':
			gotoXY(x,y-2);
			if(y>2&&x>0)printf(" __");
			gotoXY(x,y-1);
			if(y>1&&x>0)printf("/__\\");
			gotoXY(x,y);
			if(y>0&&x>0)printf("\\__");
			break;
			
		case 'P':
			gotoXY(x,y-2);
			if(y>2&&x>0)printf(" _");
			gotoXY(x,y-1);
			if(y>1&&x>0)printf("|_)");
			gotoXY(x,y);
			if(y>0&&x>0)printf("|");
			break;
			
		case 'l':
			gotoXY(x,y-1);
			if(y>1&&x>0)printf("|");
			gotoXY(x,y);
			if(y>0&&x>0)printf("|_");
			break;
			
		case 'N':
			gotoXY(x,y-1);
			if(y>1&&x>0)printf("|\\ |");
			gotoXY(x,y);
			if(y>0&&x>0)printf("| \\|");
			break;
			
		case 'E':
			gotoXY(x,y-2);
			if(y>2&&x>0)printf(" __");
			gotoXY(x,y-1);
			if(y>1&&x>0)printf("|__");
			gotoXY(x,y);
			if(y>0&&x>0)printf("|__");
			break;
			
		default:
			gotoXY(x,y);
			printf("Invalid Value!");	
			break;
	}
}

void Warning(int width,int height)
{
	int i;
	for(i = 1 ;i < width-1 ;i++)
			{
				gotoXY(i,height/2-2);
				printf("/");
				gotoXY(i,height/2+2);
				printf("/");
			}
	
	for(i = width/2-8 ;i < width/2+9 ;i++)
			{
				gotoXY(i,height/2-1);
				printf("-");
				gotoXY(i,height/2+1);
				printf("-");
			}
			
	gotoXY(width/2-7,height/2);
	printf("W A R N I N G !");

	
}

void Levelicon(int width,int height,int num)
{
	int i;
	for(i = 1 ;i < width-1 ;i++)
			{
				gotoXY(i,height/2-3);
				printf("-");
				gotoXY(i,height/2+3);
				printf("-");
			}
	
	for(i = width/2-8 ;i < width/2+9 ;i++)
			{
				gotoXY(i,height/2-2);
				printf("_");
				gotoXY(i,height/2+1);
				printf("_");
			}
			
	gotoXY(width/2-6,height/2);
	printf("L E V E L   %d",num);

}

void DrawBPL(int x,int y,int type)
{
	switch(type)
	{
		case 0:
			gotoXY(x,y-1);
			if(y>1)printf("A");
			gotoXY(x-1,y);
			if(y>0)printf("/0\\");
			gotoXY(x-1,y+1);
			if(y>-1)printf("'^'");
			break;
		case 1:
			gotoXY(x-1,y-1);
			if(y>1)printf("_ _");
			gotoXY(x-2,y);
			if(y>0)printf("/,0,\\");
			break;
		
		case 2:
			gotoXY(x-1,y-1);
			if(y>1)printf("= =");
			gotoXY(x-1,y);
			if(y>0)printf("|0|");
			gotoXY(x-1,y+1);
			if(y>-1)printf("^ ^");
			break;
			
		case 3:
			gotoXY(x,y-1);
			if(y>1)printf("|");
			gotoXY(x-1,y);
			if(y>0)printf("|0|");
			gotoXY(x-1,y+1);
			if(y>-1)printf("-H-");
			break;
		    
		default:
			printf("Invalid Value!");
			break;
	}
}

void DrawEPL(int x,int y,int type)
{
	switch(type)
	{
		case 0:
			gotoXY(x-2,y);
			if(y>0)printf("<[0]>");
			break;
		
		case 1:
			gotoXY(x-2,y);
			if(y>0)printf("([0])");
			break;
		
		case 2:
			gotoXY(x-2,y);
			if(y>0)printf("/!0!\\");
			gotoXY(x,y+1);
			if(y>-1)("V");
			break;
			
		case 3:
			gotoXY(x-1,y-1);
			if(y>1)printf("_W_");
			gotoXY(x-2,y);
		    if(y>0)printf("\\_0_/");
		    gotoXY(x-1,y+1);
		    if(y>-1)printf("^ ^");
		    break;
		    
		default:
			printf("Invalid Value!");
			break;
	}
		
}

void DrawBUL(int x,int y,int type)
{
	switch(type)
	{
		case 0:
			gotoXY(x,y);
			if(x>0&&y>0)printf("o");
			break;
			
		case 1:
			gotoXY(x,y);
			if(x>0&&y>0)printf("*");
			break;
			
		case 2:
			gotoXY(x,y);
			if(x>0&&y>0)printf("@");
			break;
			
		case 3:
			gotoXY(x,y);
			if(x>0&&y>0)printf(":");
			break;
					
		default:
			printf("Invalid Value!");
			break;
		
	}
}

void DrawLR(int x,int y,int type)
{
	int i;
	for(i = 1 ; i < y ; i++)
	{
		gotoXY(x,i);
		if(x>0)switch(type)
		{
			case 0:
				printf("|");
				break;
			case 1:
				printf("*");
				break;
			case 2:
				printf("$");
				break;
			default:
				printf("Invalid Value!");
				break;
		}
		
	}
}

void DrawBag(int x,int y,int type)
{
	switch(type)
	{
		case 0:
			gotoXY(x,y);
			if(x>0&&y>0)printf("+");
			break;
	
		case 1:
			gotoXY(x,y);
			if(x>0&&y>0)printf("B");
			break;
			
		case 2:
			gotoXY(x,y);
			if(x>0&&y>0)printf("L");			
			break;
			
		case 3:
		    gotoXY(x,y);
			if(x>0&&y>0)printf("E");
			break;
			
		case 4:
			gotoXY(x,y);
			if(x>0&&y>0)printf("S");
			break;
			
		case 5:
			gotoXY(x,y);
			if(x>0&&y>0)printf("D");
			break;
			
		default:
			printf("Invalid Value!");
			break;
			
	}
}

void DrawB(int x,int y,int type)
{
	switch(type)
	{
		case 0:
		 	gotoXY(x,y);
			if(y>0)printf("A");
			gotoXY(x,y+1);
			if(y>-1)printf("M");
			break;
		
		case 1:
			gotoXY(x-1,y-1);
			if(y>1)printf("'H'");
			gotoXY(x,y);
			if(y>0)printf("U");
			break;
			
		case 2:
			gotoXY(x,y-1);
			if(y>1)printf("I");
			gotoXY(x,y);
			if(y>0)printf("V");
			break;
			
		case 3:
			gotoXY(x,y);
			if(y>0)printf("A");
			gotoXY(x,y+1);
			if(y>-1)printf("T");
			break;
			
		case 4:
			gotoXY(x,y);
			if(y>1)printf("=");
			gotoXY(x,y+1);
			if(y>0)printf("I");
			gotoXY(x,y+2);
			if(y>-1)printf("^");
			break;
			
		case 5:
			gotoXY(x-1,y-1);
			if(x>1&&y>1)printf("\\|/");
			gotoXY(x-2,y);
			if(x>2&&y>0)printf("--*--");
			gotoXY(x-1,y+1);
			if(x>1&&y>-1)printf("/|\\");
			break;
			
		default:
			printf("Invalid Value!");
			break;
	}

}

void DrawBoss(int x,int y)
{
	
	gotoXY(x-1,y-2);
	if(y>2)printf(".'.");
	
	gotoXY(x-11,y-1);
	if(y>1)printf(".'.      '.=.'      .'.");
	
	gotoXY(x-13,y);
	if(y>0)printf("/|:_:|\\___/=[0]=\\___/|:_:|\\");
	
	
	gotoXY(x-14,y+1);
	if(y>-1)printf("| \\_=_/    \\ \\:/ /    \\_=_/ |");
	
	gotoXY(x-14,y+2);
	if(y>-2)printf("\\  |||  [O]   Y   [O]  |||  /");
	
	
	gotoXY(x-13,y+3);
	if(y>-3)printf("]  H    Y   | |   Y    H  [");
	
	gotoXY(x-14,y+4);
	if(y>-4)printf("|| |=| ||_|  | |  |_|| |=| ||");
	
	
	gotoXY(x-13,y+5);
	if(y>-5)printf("\\_/w\\_/   \\=/*\\=/   \\_/W\\_/");
	
}

void DrawMTX(int x,int y)
{
	gotoXY(x-1,y-5);
	if(y>5)printf(". .");
	gotoXY(x-1,y-4);
    if(y>4)printf("I=I");
    gotoXY(x-2,y-3);
    if(y>3)printf("|[ ]|");
    gotoXY(x-2,y-2);
    if(y>2)printf("|[_]|");
    gotoXY(x-3,y-1);
    if(y>1)printf("+[|^|]+");
    gotoXY(x-3,y);
    if(y>0)printf("!|[0]|!");
    gotoXY(x-3,y+1);
    if(y>-1)printf("' \\;/ '");
}

void PrintInfor(int health,int bombnum,int score,int level,int y)
{
	gotoXY(1,y);
	printf("Health : %d  Bombnum : %d", health, bombnum);
	gotoXY(1,y+1);
	printf("Score  : %d   Level  : %d", score, level);	
}

void DrawLine(int x,int y,int length,char ch,char type) 
{
	int i;
	switch(type)
	{
		case 'R':
			for(i = x ;i < x+length ;i++)
			{
				gotoXY(i,y);
				printf("%c",ch);
			}
			break;
			
		case 'C':
			for(i = y;i < y+length ;i++)
			{
				gotoXY(x,i);
				printf("%c",ch);
			}
			break;

		default:
			printf("Invalid Value!");
	} 
}

void PLExplode(int x,int y,int type)
{
	switch(type)
	{
		case 0:
			gotoXY(x-1,y);
			printf("{ }");
			break;
			
		case 1:
			gotoXY(x-1,y-1);
			printf(". ,");
			gotoXY(x-1,y);
			printf("   ");
			gotoXY(x-1,y+1);
			printf("' '");
			break;
		
		case 2:
			gotoXY(x-2,y);
			printf("(( ))");
			break;
			
		default:
			printf("Invalid Value!");
	}
}
void BBExplode(int x,int y,int type)			
{
	switch(type)
	{	
		case 0:
			gotoXY(x-3,y-3);
			printf("o o o o");
			gotoXY(x-5,y-2);
			printf("o  o o o  o");
			gotoXY(x-6,y-1);
			printf("o  o     o  o");
			gotoXY(x-6,y);
			printf("o o   o   o o");
			gotoXY(x-6,y+1);
			printf("o  o     o  o");
			gotoXY(x-5,y+2);
			printf("o  o o o  o");
			gotoXY(x-3,y+3);
			printf("o o o o");
			break;
		
		case 1:
			gotoXY(x-1,y);
			printf("( )");
			break;
				
		case 2:
			gotoXY(x-1,y-1);
			printf("\\^/");
			gotoXY(x-1,y);
			printf("< >");
			gotoXY(x-1,y+1);
			printf("/V\\");
			break;
			
		case 3:
			gotoXY(x-1,y-2);
			printf("___");
			gotoXY(x-3,y-1);
			printf("//   \\\\");
			gotoXY(x-3,y);
			printf("|     |");
			gotoXY(x-3,y+1);
			printf("\\\\___//");
			break;
			
		case 4:
			gotoXY(x-1,y-1);
			printf("###");
			gotoXY(x-2,y);
			printf("#####");
			gotoXY(x-1,y+1);
			printf("###");
			break;
					
		default:
			printf("Invalid Value!");
			break;
	}
}

void SpecialEffects(int x,int y,int type)
{
	switch(type)
	{
		case 0:
			gotoXY(x-2,y);
			printf("(");
			gotoXY(x+2,y);
			printf(")");
			break;
		
		case 1:
			gotoXY(x-1,y-2);
			printf("___");
			gotoXY(x-2,y-1);
			printf("/   \\");
			gotoXY(x-3,y);
			printf("|     |");
			gotoXY(x-2,y+1);
			printf("\\___/");
			break;
			
		case 2:
			gotoXY(x-2,y);
			printf(": * :");
			gotoXY(x-1,y+1);
			printf("' '");
			break;
			
		default:
			printf("Invalid Value!");
			break;
			
	}
}

void StartAmi(int width,int height)
{
	//side boundry line
	 DrawLine(1,1,height,'|','C');
	 DrawLine(2,1,height,'|','C');
	 DrawLine(3,1,height,'|','C');
	 DrawLine(width-2,1,height,'|','C');
	 DrawLine(width-1,1,height,'|','C');
	 DrawLine(width  ,1,height,'|','C');

	//appearance of the battleplane
   	 for(int i = 0;i < 7;i++ )
	{
		for(int j = 0;j < i;j++)DrawLine(width/2-1,height-j+1,3,' ','R');//erase the last icon
		DrawBPL(width/2,height-i,0);//draw a new icon
		Sleep(40);//wait for a short time to ensure you can see it
	}
		
	 //ring a roll around(width/2,height - 10)
	 
	 int bombtime=0;//this index controls the erase of a bomb after the last loop
	 
	 //left lower round
	 for( int i = 1;i < 9;i++)
	 {
	 	for(int j = -1;j < 2;j++)DrawLine(width/2 - i,height - 6 + j-(i-1)/2,3,' ','R');
		DrawBPL(width/2 - i,height-6-i/2,0);
		
		for(int j = 0;j < 2;j++)DrawLine(width/2-1,4*(i-1)-j-2,3,' ','R');
		DrawB(width/2,4*i-2,1);
		bombtime++;
		
		if(bombtime == 8)
		{
			for(int j = 0;j < 2;j++)DrawLine(width/2-1,30-j,3,' ','R');
			bombtime=0;
		}
		
		Sleep(30);		
	 }
	 //left upper round
	 for( int i = 1;i < 9;i++)
	 {
	 	for(int j = -1;j < 2;j++)DrawLine(width/2 +i-10,height - 10 + j-(i-1)/2,3,' ','R');
		DrawBPL(width/2 + i - 8,height-10-i/2,0);
		
		for(int j = 0;j < 2;j++)DrawLine(width/2-11,4*(i-1)-j-2,3,' ','R');
		DrawB(width/2-10,4*i-2,1);
		bombtime++;
		
		if(bombtime == 8)
		{
			for(int j = 0;j < 2;j++)DrawLine(width/2-11,30-j,3,' ','R');
			bombtime=0;
		}
		
		Sleep(30);
	 }
	 //right upper round
	 for( int i = 1;i < 9;i++)
	 {
	 	for(int j = -1;j < 2;j++)DrawLine(width/2+i-2,height - 14 + j +(i-1)/2,3,' ','R');
		DrawBPL(width/2 + i,height-14+i/2,0);
		
		for(int j = 0;j < 2;j++)DrawLine(width/2,4*(i-1)-j-2,3,' ','R');
		DrawB(width/2+1,4*i-2,2);
		bombtime++;
		
		if(bombtime == 8)
		{
			for(int j = 0;j < 2;j++)DrawLine(width/2,30-j,3,' ','R');
			bombtime=0;
		}
		
		Sleep(30);
	 }
	 //right lower round
	 for( int i = 1;i < 9;i++)
	 {
	 	for(int j = -1;j < 2;j++)DrawLine(width/2+8-i,height - 10 + j + (i-1)/2,3,' ','R');
		DrawBPL(width/2 + 8 - i,height-10+i/2,0);
		
		for(int j = 0;j < 2;j++)DrawLine(width/2+7,4*(i-1)-j-2,3,' ','R');
		DrawB(width/2+8,4*i-2,2);
		bombtime++;
		
		if(bombtime == 8)
		{
			for(int j = 0;j < 2;j++)DrawLine(width/2+7,30-j,3,' ','R');
			bombtime=0;
		}
		
		Sleep(30);
	 }
	
//some enemyplanes' appearance
	 for(int i =1;i<13;i++)
	 { 
	   if(i>6)DrawLine(8,i-6,5,' ','R');
	   DrawEPL(10,i-5,0);
	   
	   if(i>1)DrawLine(width - 12,i-1,5,' ','R');
	   DrawEPL(width - 10,i,1); 
	   
	   for(int j = 1;j < i-8;j++)if(j>0)DrawLine(width - 22,j,5,' ','R');
	   DrawEPL(width - 20,i-8,3);
	   Sleep(80);
	 }

	 //appearance of the boss
	 for(int i = -7;i < 4;i++)
	 {
	 	for(int j = 1;j < i+1;j++)DrawLine(width/2 - 16,j,32,' ','R');
		DrawBoss(width/2,i);
	 	Sleep(200);
	 }
	 
	 //boss's nuclear cannon 's charge 
	 for(int i = 0;i<3;i++)
	 {
	 	SpecialEffects(width/2,9,2);
	 	Sleep(200);
	 	DrawLine(width/2 - 2,9,5,' ','R');
	 	DrawLine(width/2 - 1,10,3,' ','R');
	 	Sleep(100); 
	 }
	 
	 //print the title'BAttLe PLANE' and shine three times
	 for(int i =0;i < 3;i++)
	 {
	 	DrawLine(width/2-26,height/2-7,3,' ','R');
	 	DrawLine(width/2-26,height/2-6,5,' ','R');
	  	for(int j =height/2-5;j<height/2;j++)DrawLine(width/2-26,j,50,' ','R');
	  	Sleep(150);
		
		Character(width/2-26,height/2-3,'B');
		Character(width/2-21,height/2-2,'A');
		Character(width/2-17,height/2-3,'t');
		Character(width/2-13,height/2-3,'t');
		Character(width/2-9,height/2-2,'L');
		Character(width/2-5,height/2-2,'e');
	 
		Character(width/2+4,height/2-1,'P');
		Character(width/2+8,height/2-1,'l');
		Character(width/2+12,height/2-1,'A');
		Character(width/2+16,height/2-1,'N');
		Character(width/2+21,height/2-1,'E');
		Sleep(200);
	 }
	 
}




