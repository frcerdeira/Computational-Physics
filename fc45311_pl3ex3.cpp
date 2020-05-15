#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

// numero de pontos gerados
int nPoints = 200;

// hist bars
int bin_1a[20];
int bin_1c[20];
double prob = 0.05;

// chi-squared
int soma_1a = 0;
int soma_1c = 0;
  
// valores 1.1a)
int c_1a = 3;
int p_1a = 31;

// valores 1.1c)
int c_1c = 16807;
int p_1c = pow(2, 31) - 1;


int main ()

{
  
  // valores 1.1a)
  int X_1a[nPoints];
  double ger_1a[nPoints];

  // valores 1.1c)
  int X_1c[nPoints];
  double ger_1c[nPoints];

  X_1a[0] = 7; // semente ex 1.1a)
  X_1c[0] = 524287; // semente ex 1.1c)
  
  for (int alberto = 0; alberto < nPoints; alberto++)
    
    {

      // 1.1a)
      X_1a[alberto + 1] = c_1a * X_1a[alberto] % p_1a;
      ger_1a[alberto] = (double)X_1a[alberto] / (double)p_1a;
      
      // 1.1c)
      X_1c[alberto + 1] = c_1c * X_1c[alberto] % p_1c;
      ger_1c[alberto] = (double)X_1c[alberto] / (double)p_1c;

      // file
      //cout << ger_1a[alberto] << endl;

      // histogram 1.1a
      if (ger_1a[alberto] >= 0 && ger_1a[alberto] < 0.05)
	bin_1a[0]++;
      else if (ger_1a[alberto] >= 0.05 && ger_1a[alberto] < 0.1)
	bin_1a[1]++;
      else if (ger_1a[alberto] >= 0.1 && ger_1a[alberto] < 0.15)
	bin_1a[2]++;
      else if (ger_1a[alberto] >= 0.15 && ger_1a[alberto] < 0.2)
	bin_1a[3]++;
      else if (ger_1a[alberto] >= 0.2 && ger_1a[alberto] < 0.25)
	bin_1a[4]++;
      else if (ger_1a[alberto] >= 0.25 && ger_1a[alberto] < 0.3)
	bin_1a[5]++;
      else if (ger_1a[alberto] >= 0.3 && ger_1a[alberto] < 0.35)
	bin_1a[6]++;
      else if (ger_1a[alberto] >= 0.35 && ger_1a[alberto] < 0.4)
	bin_1a[7]++;
      else if (ger_1a[alberto] >= 0.4 && ger_1a[alberto] < 0.45)
	bin_1a[8]++;
      else if (ger_1a[alberto] >= 0.45 && ger_1a[alberto] < 0.5)
	bin_1a[9]++;
      else if (ger_1a[alberto] >= 0.5 && ger_1a[alberto] < 0.55)
	bin_1a[10]++;
      else if (ger_1a[alberto] >= 0.55 && ger_1a[alberto] < 0.6)
	bin_1a[11]++;
      else if (ger_1a[alberto] >= 0.6 && ger_1a[alberto] < 0.65)
	bin_1a[12]++;
      else if (ger_1a[alberto] >= 0.65 && ger_1a[alberto] < 0.7)
	bin_1a[13]++;
      else if (ger_1a[alberto] >= 0.7 && ger_1a[alberto] < 0.75)
	bin_1a[14]++;
      else if (ger_1a[alberto] >= 0.75 && ger_1a[alberto] < 0.8)
	bin_1a[15]++;
      else if (ger_1a[alberto] >= 0.8 && ger_1a[alberto] < 0.85)
	bin_1a[16]++;
      else if (ger_1a[alberto] >= 0.85 && ger_1a[alberto] < 0.9)
	bin_1a[17]++;
      else if (ger_1a[alberto] >= 0.9 && ger_1a[alberto] < 0.95)
	bin_1a[18]++;
      else if (ger_1a[alberto] >= 0.95 && ger_1a[alberto] < 1)
	bin_1a[19]++;

            // histogram 1.1c
      if (ger_1c[alberto] >= 0 && ger_1c[alberto] < 0.05)
	bin_1c[0]++;
      else if (ger_1c[alberto] >= 0.05 && ger_1c[alberto] < 0.1)
	bin_1c[1]++;
      else if (ger_1c[alberto] >= 0.1 && ger_1c[alberto] < 0.15)
	bin_1c[2]++;
      else if (ger_1c[alberto] >= 0.15 && ger_1c[alberto] < 0.2)
	bin_1c[3]++;
      else if (ger_1c[alberto] >= 0.2 && ger_1c[alberto] < 0.25)
	bin_1c[4]++;
      else if (ger_1c[alberto] >= 0.25 && ger_1c[alberto] < 0.3)
	bin_1c[5]++;
      else if (ger_1c[alberto] >= 0.3 && ger_1c[alberto] < 0.35)
	bin_1c[6]++;
      else if (ger_1c[alberto] >= 0.35 && ger_1c[alberto] < 0.4)
	bin_1c[7]++;
      else if (ger_1c[alberto] >= 0.4 && ger_1c[alberto] < 0.45)
	bin_1c[8]++;
      else if (ger_1c[alberto] >= 0.45 && ger_1c[alberto] < 0.5)
	bin_1c[9]++;
      else if (ger_1c[alberto] >= 0.5 && ger_1c[alberto] < 0.55)
	bin_1c[10]++;
      else if (ger_1c[alberto] >= 0.55 && ger_1c[alberto] < 0.6)
	bin_1c[11]++;
      else if (ger_1c[alberto] >= 0.6 && ger_1c[alberto] < 0.65)
	bin_1c[12]++;
      else if (ger_1c[alberto] >= 0.65 && ger_1c[alberto] < 0.7)
	bin_1c[13]++;
      else if (ger_1c[alberto] >= 0.7 && ger_1c[alberto] < 0.75)
	bin_1c[14]++;
      else if (ger_1c[alberto] >= 0.75 && ger_1c[alberto] < 0.8)
	bin_1c[15]++;
      else if (ger_1c[alberto] >= 0.8 && ger_1c[alberto] < 0.85)
	bin_1c[16]++;
      else if (ger_1c[alberto] >= 0.85 && ger_1c[alberto] < 0.9)
	bin_1c[17]++;
      else if (ger_1c[alberto] >= 0.9 && ger_1c[alberto] < 0.95)
	bin_1c[18]++;
      else if (ger_1c[alberto] >= 0.95 && ger_1c[alberto] < 1)
	bin_1c[19]++;

    }

  for(int alberto = 0; alberto <= 19; alberto++)

    {

      soma_1a += pow((bin_1a[alberto] - nPoints*prob), 2) / (nPoints*prob);
      soma_1c += pow((bin_1c[alberto] - nPoints*prob), 2) / (nPoints*prob);
    }

  cout << "chi-squared ex 1.1 a) = " << soma_1a << "\n" <<  "chi-squared ex 1.1 c) = " << soma_1c << endl;
      
  return 0;
  
}
