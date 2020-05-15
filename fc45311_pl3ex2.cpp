#include <iostream>
#include <ctime>
#include <cstdlib>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int np = 2000;
int R = 1;

int main()
{
  
  double r[np];
  double theta[np];
  double x[np];
  double y[np];
  srand(time(NULL));
  
  for (int alberto = 0; alberto <= np; alberto++)
    {
      
      // gerar os numeros
      r[alberto] = R * sqrt((double) rand() / RAND_MAX); // rand() % R
      theta[alberto] = 2 * M_PI * ((double) rand() / RAND_MAX); // rand() % R

      // converter para coordenadas cartesianas
      x[alberto] = r[alberto] * cos(theta[alberto]);
      y[alberto] = r[alberto] * sin(theta[alberto]);

      // mostra os numeros
      cout << x[alberto] << "\t" << y[alberto] << endl;
    }
  
  return 0;
}
      

      

     
      



