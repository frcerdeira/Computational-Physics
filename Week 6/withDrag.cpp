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
	
	double g = -9.80665; // ms⁻²
	double delta = 0.01;
	double Tsim = 100;
	int ite = round(Tsim/delta);
	////
	//double teste = M_PI/2.0;
	//cout << teste << endl;
	////
	ofstream outfile1;
	outfile1.open("pl8ex2.dat");
	
	for(double fGamma = 0.001; fGamma < 1; fGamma += 0.001)
	{
		double result = 0;
		double max = 0;
		double angleMAX = 0;
		int k = 0;
		
		for(double angle = 0.001; angle < M_PI/2.0; angle += 0.001)
		{
				
			int i = 0;
				
			
			double x[ite];
			double y[ite];
			x[0] = 0;
			y[0] = 0;
			double vx[ite];
			double vy[ite];
			vy[0] = v0 * sin(angle);
			vx[0] = v0 * cos(angle);
			
			double k1x = 0;
			double k1y = 0;
			double k1vx = 0;
			double k1vy = 0;
			
			double k2x = 0;
			double k2y = 0;
			double k2vx = 0;
			double k2vy = 0;
			
			double k3x = 0;
			double k3y = 0;
			double k3vx = 0;
			double k3vy = 0;
			
			double k4x = 0;
			double k4y = 0;
			double k4vx = 0;
			double k4vy = 0;
			
			double v = 0;
			
			while(y[i] >= 0)
			{
				
				k1x = vx[i];
				k1y = vy[i];
				
				v = sqrt(pow(k1x, 2) + pow(k1y, 2));
				
				k1vx = -fGamma*k1x*v;
				k1vy = g - fGamma*k1y*v;	
				
				/////////////////////////////////////////
				
				k2x =  vx[i] + 0.5*k1vx*delta;
				k2y =  vy[i] + 0.5*k1vy*delta;
				
				v = sqrt(pow(k2x, 2) + pow(k2y, 2));
				
				k2vx = -fGamma*k2x*v;
				k2vy = g - fGamma*k2y*v;	
				
				/////////////////////////////////////////

				k3x =  vx[i] + 0.5*k2vx*delta;
				k3y =  vy[i] + 0.5*k2vy*delta;
				
				v = sqrt(pow(k3x, 2) + pow(k3y, 2));
				
				k3vx = -fGamma*k3x*v;
				k3vy = g - fGamma*k3y*v;
				
				/////////////////////////////////////////
				
				k4x =  vx[i] + k3vx*delta;
				k4y =  vy[i] + k3vy*delta;
				
				v = sqrt(pow(k4x, 2) + pow(k4y, 2));
				
				k4vx = -fGamma*k4x*v;
				k4vy = g - fGamma*k4y*v;			
		
				/////////////////////////////////////////
				/////////////////////////////////////////
				
				x[i+1] = x[i] + delta*(k1x/6 + k2x/3 + k3x/3 + k4x/6);
				y[i+1] = y[i] + delta*(k1y/6 + k2y/3 + k3y/3 + k4y/6);
				vx[i+1] = vx[i] + delta*(k1vx/6 + k2vx/3 + k3vx/3 + k4vx/6);
				vy[i+1] = vy[i] + delta*(k1vy/6 + k2vy/3 + k3vy/3 + k4vy/6);
				
				//cout << x[i] << "\t" << y[i] << "\t" << fGamma << "\t" << angle << endl;
				
				i++;
				
			}	
			
			result = findZERO(x[i-1], x[i], y[i-1], y[i]);
			
			if(result > max)
			{
				angleMAX = angle;
				max = result;
			}
			
			//cout << result[k] << "\t" << max << "\t" << fGamma << "\t" << angle << endl;	
			k++;
			//cout << x[i] << "\t" << y[i] << "\t" << fGamma << "\t" << angle << "\t" << angleMAX << endl;	
			//outfile1 << angleMAX << "\t" << fGamma << endl;
		}
		
		outfile1 << angleMAX << "\t" << fGamma << endl;
		//cout << max << endl;
	}
	
	outfile1.close();
	
}		
