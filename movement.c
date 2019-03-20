//movement

#include <math.h>


void movealongline(int ** PTR,int i,int n,int velocity)	//left right velocity
													// position={x,y} the dimension needs altering
{
	for(int j=i;j<n+i;j++)
	{
		PTR[j][0]+=velocity;
	}

	
}



void disperse(int ** PTR,int i,int n)	  // PTR pointer to plane, i number of certain plane (start) , n total number
										//pass this function original plane, and n avaliable storage
{
	static int original_x=PTR[i][1], original_y=PTR[i][0];
	static int dispersetimes=1;
	static double tane=tan(180.0/n);
	
	if(dispersetimes)				// create n planes
	{
		for(int j=i;j<n+i;j++)
		{
			PTR[j][0]=original_y;
			PTR[j][1]=original_x;
			//PTR[j][2]=HEALTH;		
		}
		 dispersetimes=0;
	}
	else
	{
		int delta=PTR[i][0]-original_y+1;
		for(int j=i;j<n+i;j++)
		{
			PTR[j][0]=original_y+delta;
			PTR[j][1]=original_x+(int)delta*tane;
	
		}
		
				
	}
	
		
	
}






void interlude(int ** PTR,int i,int n,int h,int w)
{

	int hpern=h/(n-1), wpern=w/(n-1);
	for(int j=i;j<n+i;j++)
	{
	
	//	signle_interlude(*(*(group)+0),*(*(group)+1),*(*(group)+2),h/(n-1),w/(n-1));	//call  seperately
	
							//h=h/(n-1) may be prefered					   //statue where it is			h,w the height and width in a T
												   //n number of onjects== need modifying after storage method has been completed
// statue along a T, the line contains 2n-1 points
	if(PTR[j][3]>=0&&PTR[j][3]<=n-1)
	{
		PTR[j][1]+=hpern;			// 1, height y axis
		PTR[j][0]+=wpern;				// 0, wide x axis
				
	}
	else
	{
		PTR[j][1]-=hpern;
		PTR[j][0]+=wpern;
		
	}
	
	PTR[j][3]=(PTR[j][3])%(2*n-1)+1;
	
	
	
	

	
	}


}












