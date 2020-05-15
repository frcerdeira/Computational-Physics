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
	outfile1.open("pl8ex1EULER.dat");
	
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
		
		while(y[i] >= 0)
		{
			x[i+1] = x[i] + vx*delta;
			y[i+1] = y[i] + vy[i]*delta;// + 0.5*g*pow(delta, 2);
			vy[i+1] = vy[i] + g*delta;
			
			//outfile1 << x[i] << "\t" << y[i] << "\t" << delta[d] << endl;
			i++;
		}
		
		result = findZERO(x[i-1], x[i], y[i-1], y[i]);
		outfile1 << result << "\t" << delta << endl;
		
	}
	outfile1.close();
	
	return 0;	
}

