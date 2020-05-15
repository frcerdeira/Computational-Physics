#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int points[] = {250, 500, 750, 1000, 1250, 1500};
int size = (sizeof(points)/sizeof(*points)); 
int Np = 0;
int alberto = 0;
int L = 1;
int amostras[] = {100, 200, 500, 750, 1000, 1250, 1500, 2000, 2500, 5000};
int sizeAmostra = (sizeof(amostras)/sizeof(*amostras)); 
  
int main()
{ 
  for(alberto = 0; alberto < size; alberto++)
    {
      
      double x[points[alberto]];
      double y[points[alberto]];
      double z[points[alberto]];

      for (int b = 0; b < sizeAmostra; b++)
	{

	  double sum = 0;
	  double dMed = 0;
	  double media[sizeAmostra];
	  
	  for(int a = 0; a <= amostras[b]; a++)
	    {

	      double d = 0;
	      
	      for(Np = 0; Np <= points[alberto]; Np++)
		{
		  x[Np] = drand48()*L;
		  y[Np] = drand48()*L;
		  z[Np] = drand48()*L;
		}

	      for(int i = 0; i < points[alberto]; i++)
		{
		  
		  for(int j = i + 1; j <= points[alberto]; j++)
		    {
		      
		      d += sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2) + pow(z[i] - z[j], 2));
		    }
		}
    
	      dMed = (2 * d) / (points[alberto] * (points[alberto] - 1));
	      sum += dMed;
		
	    }
    
	  media[b] = sum/amostras[b];
	  cout << media[b] << "\t" << amostras[b] << "\t" << points[alberto] << endl;
	}
	    
    }
}
