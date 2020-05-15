#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include "latticeview.h"

        
#define ImageWidth 1000  // image width
#define ImageHeight 1000 // image height
#define down -1
#define up 1
#define J 1

using namespace std;

int main()
{
  int N[] = {50, 100, 150};    // Lateral number of cells
  int sizeN = (sizeof(N)/sizeof(*N));   
  int i = 0;              // posição
  int icounter = 0;
  int esq = 0;
  int dir = 0;
  int cima = 0;
  int baixo = 0;
  double r = 0;
  double p = 0;

  for(int runa = 0; runa < sizeN; runa++)
    {
      
      int sizeLat = N[runa]*N[runa];
      int lat[sizeLat]; // create lattice
      int MCStep = sizeLat;
      int MCSweep = 5000;
      double Mag = 0;
      double deltaE = 0;
      double E = 0;

      for(icounter = 0; icounter < sizeLat; icounter++)
	{

	  lat[icounter] = up;

	}
  
      // energia e magnetização inicial
      for(icounter = 0; icounter < sizeLat; icounter++)
	{

	  // comparar a esquerda
	  if(icounter % N[runa] != 0)
	    {
	      esq = lat[icounter]*lat[icounter-1];
	    }
      
	  else
	    {
	      esq = lat[icounter]*lat[icounter + N[runa] - 1];
	    }
      
	  //comparar a direita  
	  if(icounter % N[runa] != N[runa]-1)
	    {
	      dir = lat[icounter]*lat[icounter + 1];
	    }
	  else
	    {
	      dir = lat[icounter]*lat[icounter - N[runa] + 1];
	    }

	  //comparar em cima
	  if(icounter/N[runa] != N[runa]-1)
	    {
	      cima = lat[icounter]*lat[icounter+N[runa]];
	    }
	  else
	    {
	      cima = lat[icounter]*lat[icounter - (N[runa]*(N[runa]-1))];
	    }
       
	  //comparar em baixo
	  if(icounter/N[runa] != 0)
	    {
	      baixo = lat[icounter]*lat[icounter-N[runa]];
	    }
	  else
	    {
	      baixo = lat[icounter]*lat[icounter + (N[runa]*(N[runa]-1))];
	    }
      
	  E += - J*(esq + dir + cima + baixo);
	  Mag += lat[icounter];

	}

      //cout << E/sizeLat << "\t" << Mag/sizeLat << endl;
 
      //Comparar localmente

      for(double T = 0.5; T < 3.5; T = T + 0.01)
	{

	  int countMedia = 0;
	  double EMedia = 0;
	  double MagMedia = 0;
	  double ESigma = 0;
	  double MagSigma = 0;

	  for(int amostra = 0; amostra <= MCSweep; amostra++) // Monte Carlo Sweep
	    {

	      for(int alberto = 0; alberto <= MCStep; alberto++) // Monte Carlo Step
		{
    
		  // i = rand() % (sizeLat + 1);
		  i = drand48()*sizeLat;

		  // comparar a esquerda
		  if(i % N[runa] != 0)
		    {
		      esq = lat[i]*lat[i-1];
		    }
      
		  else
		    {
		      esq = lat[i]*lat[i+N[runa]-1];
		    }
      
		  //comparar a direita  
		  if(i % N[runa] != N[runa]-1)
		    {
		      dir = lat[i]*lat[i+1];
		    }
		  else
		    {
		      dir = lat[i]*lat[i-N[runa]+1];
		    }

		  //comparar em cima
		  if(i/N[runa] != N[runa]-1)
		    {
		      cima = lat[i]*lat[i+N[runa]];
		    }
		  else
		    {
		      cima = lat[i]*lat[i - (N[runa]*(N[runa]-1))];
		    }
       
		  //comparar em baixo
		  if(i/N[runa] != 0)
		    {
		      baixo = lat[i]*lat[i-N[runa]];
		    }
		  else
		    {
		      baixo =lat[i]*lat[i + (N[runa]*(N[runa]-1))];
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
		      p = exp(-(deltaE/T));
	   
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

	      // calcula E por celula a cada 3 MC Sweep

	      if((amostra + 1) % 3 == 0)
		{
		  ESigma += E/sizeLat;
		  MagSigma += Mag/sizeLat;
		  countMedia++;
		}

	    } // iterações para T[i] (Sweep)

	  EMedia = ESigma/countMedia; 
	  MagMedia = MagSigma/countMedia;
	  
	  cout << EMedia << "\t" << MagMedia << "\t" << T << "\t" << N[runa] << endl;
      
	}// for Temperatura
      
    }// tamanho
  
}//int main
