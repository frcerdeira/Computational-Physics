#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include "latticeview.h"

#define N 100             // Lateral number of cells
#define ImageWidth 1000  // image width
#define ImageHeight 1000 // image height
#define down -1
#define up 1
#define J 1

using namespace std;

int main()
{
  int sizeLat = N*N;
  int lat[sizeLat];       // create lattice
  int i = 0;              // posição
  int icounter, jcounter; // counters
  int MCStep = sizeLat;
  int MCSweep = 10000;

  double r = 0;
  double Tc = 2/(log(1 + sqrt(2)));
  double T[] = {1.5, Tc, 3} ;
  int sizeT = (sizeof(T)/sizeof(*T));
  int Tcount = 0;
  double p = 0;
  char filename[160];
  int cores = 0;

  for(Tcount = 0; Tcount < sizeT; Tcount++)
    {
      
      for(icounter = 0; icounter < sizeLat; icounter++)
	{

	  lat[icounter] = up;

	}

      double deltaE = 0;
      double E = 0;
      int esq = 0;
      int dir = 0;
      int cima = 0;
      int baixo = 0;
      double Mag = 0;
      
      // energia e magnetização inicial
      for(icounter = 0; icounter < sizeLat; icounter++)
	{

	  // comparar a esquerda
	  if(icounter % N != 0)
	    {
	      esq = lat[icounter]*lat[icounter-1];
	    }
      
	  else
	    {
	      esq = lat[icounter]*lat[icounter + N - 1];
	    }
      
	  //comparar a direita  
	  if(icounter % N != N-1)
	    {
	      dir = lat[icounter]*lat[icounter + 1];
	    }
	  else
	    {
	      dir = lat[icounter]*lat[icounter - N + 1];
	    }

	  //comparar em cima
	  if(icounter/N != N-1)
	    {
	      cima = lat[icounter]*lat[icounter+N];
	    }
	  else
	    {
	      cima = lat[icounter]*lat[icounter - (N*(N-1))];
	    }
       
	  //comparar em baixo
	  if(icounter/N != 0)
	    {
	      baixo = lat[icounter]*lat[icounter-N];
	    }
	  else
	    {
	      baixo = lat[icounter]*lat[icounter + (N*(N-1))];
	    }
      
	  E += - J*(esq + dir + cima + baixo);
	  Mag += lat[icounter];

	}

      //Comparar localmente

      for(int amostra = 0; amostra <= MCSweep; amostra++) // Monte Carlo Sweep
	{

	  for(int alberto = 0; alberto <= MCStep; alberto++) // Monte Carlo Step
	    {
    
	      i = rand() % (sizeLat + 1);
	      //lat[i] = -lat[i];

	      // comparar a esquerda
	      if(i % N != 0)
		{
		  esq = lat[i]*lat[i-1];
		}
      
	      else
		{
		  esq = lat[i]*lat[i+N-1];
		}
      
	      //comparar a direita  
	      if(i % N != N-1)
		{
		  dir = lat[i]*lat[i+1];
		}
	      else
		{
		  dir = lat[i]*lat[i-N+1];
		}

	      //comparar em cima
	      if(i/N != N-1)
		{
		  cima = lat[i]*lat[i+N];
		}
	      else
		{
		  cima = lat[i]*lat[i - (N*(N-1))];
		}
       
	      //comparar em baixo
	      if(i/N != 0)
		{
		  baixo = lat[i]*lat[i-N];
		}
	      else
		{
		  baixo =lat[i]*lat[i + (N*(N-1))];
		}

	      deltaE = 2*J*(esq + dir + cima + baixo);

	      if(deltaE <= 0)
		{
		  lat[i] = -lat[i];
		  // Magnetização
		  Mag = Mag + 2*lat[i];

		  // Energia
		  E = E + deltaE;
		}
	      else if(deltaE > 0)
		{
		  r = drand48();
		  p = exp(-(deltaE/T[Tcount]));
	   
		  if(r < p)
		    {
		      lat[i] = -lat[i];
		      
		      // Magnetização
		      Mag = Mag + 2*lat[i];

		      // Energia
		      E = E + deltaE;
		    }
		  
		}
   
	    } // iterações para T[i] (Step)

	} // iterações para T[i] (Sweep)

      // Cores
      for(cores = 0; cores < sizeLat; cores++)
	{
	  
      	  if(lat[cores] == -1)
	    {
	      lat[cores] = 2;
	    }

	}

      sprintf(filename, "isingT%d.ppm", Tcount);
      Print_lattice (lat, N, N, ImageWidth, ImageHeight, filename);
      cout << Tcount << "\t" << E << endl;
   
    }// for Temperatura
  
}//int main

