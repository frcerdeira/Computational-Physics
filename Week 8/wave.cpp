#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main()
{
	double b[] = {0.5, 1, 1.5};
	int sizeb = (sizeof(b)/sizeof(*b)); 
	
	int X = 30;
	double dx = 0.1;
	int SizeComp = X/dx;
	
	int Tsimul = 15;
	double dt = 0.1;
	
	int SizeTempo = Tsimul/dt;

	double u[SizeComp][SizeTempo];
	int xAnterior = 0;
	int xSeguinte = 0;
	
	char filename[160];
	
	for(int alb_b = 0; alb_b < sizeb; alb_b++)
	{
		
		ofstream outfile1;
		sprintf(filename,"pl10ex1B%d.dat",alb_b);
		outfile1.open(filename);
		
		double v = sqrt(b[alb_b])*(dx/dt);
		
		for(int alb = 0; alb < SizeComp; alb++)
		{
			
			u[alb][0] = exp(-pow((alb*dx - v*dt - 10), 2));
			u[alb][1] = exp(-pow((alb*dx - 10), 2));
			
		}
		
		for(int t = 1; t < SizeTempo; t++)
		{
			for(int x = 0; x < SizeComp; x++)
			{

				// Condições Periódicas
				if(x == 0) 
				{
					xAnterior = SizeComp - 1;
				}
				else if(x == SizeComp - 1)
				{
					xSeguinte = 0;		
				}

				else
				{
					xSeguinte = x + 1;
					xAnterior = x - 1;
				}			
				//
				
				u[x][t+1] = 2*(1 - b[alb_b])*u[x][t] + b[alb_b]*(u[xSeguinte][t] + u[xAnterior][t]) - u[x][t-1];
				
				outfile1 << x*dx << "\t" << t*dt << "\t" << u[x][t] << endl;

			}
			
		}
		
		outfile1.close();
			
	}
	
}		
	
	 
	
