#include "latticeview.h"
#include <stdlib.h>


#define N 15             //Lateral number of cells
#define ImageWidth 1000  //image width
#define ImageHeight 1000 //image height


using namespace std;

main ()
{
  int lat[N*N];  //create lattice
  int icounter, jcounter; //counters
  double rand = 0;
  int N2 = 0;
  int a = 0;
  int b = 0;

  for (icounter = 0; icounter < N*N; icounter++)
    {     
      rand = drand48();
      if (rand < 0.5)
	lat[icounter] = 1;
      else
	lat[icounter] = 0;
    }
	    
  Print_lattice (lat, N, N, ImageWidth, ImageHeight, "b&w_5.ppm");
  
  //metodo da queima lat "b&w_5.ppm"
  
  //branco(vazio) = 0            
  //preto(ocupado) = 1            
  //vermelho(a arder) = 2        
  //verde(ardido) = 3             
  //azul(arder a seguir) = 4      
  
  for(a = 0; a < N; a++)
    {
	  
      if(lat[a] == 1)
	{
	  lat[a] = 2;
	  N2++;
	}
    }
	  
  while(N2 > 0)
    {
      
      for(b = 0; b < N*N; b++)
	{

	  if(lat[b] == 1)
	    {
	      //comparar a esquerda
	      if(b % N != 0)
		{
		  if(lat[b-1] == 2)
		    {
		      lat[b] = 4;
		    }
		}

	      //comparar a direita

	      if(b % N != N-1)
		{
		  if(lat[b+1] == 2)
		    {
		      lat[b] = 4;
		    }
		}

	      // comparar cima
	      if(b/N != N-1)
		{
		  if(lat[b+N] == 2)
		    {
		      lat[b] = 4;
		    }
		}

	      //comparar baixo

	      if(b/N != 0)
		{
		  if(lat[b-N] == 2)
		    {
		      lat[b] = 4;
		    }
		}
	    }
	}
	

      // 2 para 3; 4 para 2
      for(int b = 0; b < N*N; b++)
	{
	  if(lat[b] == 2)
	    { 
	      lat[b] = 3;
	      N2--;  
	    }

	  if(lat[b] == 4)
	    {	      
	      lat[b] = 2;
	      N2++;
	    }
	}      
    }
  
  Print_lattice (lat, N, N, ImageWidth, ImageHeight, "b&w_5_queima.ppm");
   
		     
}
	     
