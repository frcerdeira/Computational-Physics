#include <iostream>
#include <ctime>
#include <cstdlib>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

using namespace std;

int points [] = {500, 1000, 2500, 5000, 10000, 25000, 50000, 100000, 250000, 500000, 750000, 1000000, 2000000, 3000000, 10000000, 50000000, 100000000};
int size = (sizeof(points)/sizeof(*points)); 



int main()
{
  //srand(time(Null));
  double x = 0;
  double y = 0;
  double pi[size];
  double desvio[size];
 
  for(int array = 0; array < size; array++)
    {
      int Np = 0;
      int nDentro = 0;
      
      for(Np = 0; Np <= points[array]; Np++)
	{
	  x = drand48();
	  y = drand48();

	  if (pow(x,2) + pow(y,2) <= 1)
	    {

	      nDentro++;

	    }
  
	} 

      pi[array] = 4*((double)nDentro/(double)points[array]);
      desvio[array] = abs(M_PI - pi[array]);
      
      cout << points[array] << "\t" << pi[array] << "\t" << desvio[array] << endl;
    
    }
      
}
      
