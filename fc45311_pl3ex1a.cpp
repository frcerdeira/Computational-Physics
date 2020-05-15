#include <iostream>
#include <math.h>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

//n points
int N = 1000;

//valores 1.1a)
int c_a = 3;
int p_a = 31;


//valores 1.1c)
int c_c = 16807;
int p_c = pow(2, 31) - 1;



int main ()

{
  srand(time(NULL));
  int X_a[N];
  int X_c[N];
  int X_rand[N];
  int X_drand48[N];

    
  //sementes
  X_a[0] = 7;
  X_c[0] = 524287;
  
  for (int alberto = 0; alberto < N; alberto++)
    
    {
      
      X_a[alberto + 1] = c_a*X_a[alberto] % p_a;
      X_c[alberto + 1] = c_c*X_c[alberto] % p_c;
      X_rand[alberto] = rand() % N;
      X_drand48[alberto] = drand48() * N;
       
    }

   for (int alberto = 0; alberto < N - 2; alberto++)
     {
       cout << X_a[alberto] << "\t" << X_a[alberto + 1] << "\t" << X_a[alberto + 2] << endl;
     }

  return 0;
  
}
