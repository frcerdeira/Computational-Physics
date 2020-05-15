#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>

#define v0 10

#define _USE_MATH_DEFINES

using namespace std;

double findZERO(double xInicial, double xFinal, double yInicial, double yFinal)
{
	double declive = (yFinal - yInicial)/(xFinal - xInicial);
	double intersectYY = yInicial - declive*xInicial;
	double alcance = -(intersectYY/declive);
	
	return alcance;
}

int main()
{
	double angle = M_PI/4;
	double g = -9.80665; // ms⁻²
	//double delta[] = {0.1, 0.05, 0.01, 0.005, 0.001};
	//int sizeArray = sizeof(delta)/sizeof(*delta);
	double Tsim = 100;
	
	ofstream outfile1;
	outfile1.open("pl8ex1RUNGE.dat");
	
	for(double delta = 0.001; delta <= 0.5; delta = delta + 0.001)
	{

		int ite = round(Tsim/delta);
		double x[ite] = {};
		double y[ite] = {};
		x[0] = 0;
		y[0] = 0;
		double vy[ite] = {};
		vy[0] = v0 * sin(angle);
		double vx = v0 * cos(angle);
		
		int i = 0;
		double result = 0;

		double k1y = 0;
		double k1v = 0;

		double k2y = 0;
		double k2v = 0;
		
		double k3y = 0;
		double k3v = 0;
		
		double k4y = 0;
		double k4v = 0;
		

		while(y[i] >= 0)
		{
			k1y = vy[i];
			k1v = g;

			k2y = vy[i] + 0.5*k1v*delta;
			k2v = g;
			
			k3y = vy[i] + 0.5*k2v*delta;
			k3v = g;			
			
			k4y = vy[i] + 0.5*k3v*delta;
			k4v = g;		

			x[i+1] = x[i] + delta*vx;
			y[i+1] = y[i] + delta*(k1y/6 + k2y/3 + k3y/3 + k4y/6);
			vy[i+1] = vy[i] + delta*(k1v/6 + k2v/3 + k3v/3 + k4v/6);		
						
			i++;
		}
		
		result = findZERO(x[i-1], x[i], y[i-1], y[i]);
		outfile1 << result << "\t" << delta << endl;
	}
	
	outfile1.close();
	
	return 0;
		
}
