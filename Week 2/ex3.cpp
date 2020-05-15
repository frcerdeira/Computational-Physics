#include "latticeview.h"
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>

// #define N 15             //Lateral number of cells
#define ImageWidth 1000  //image width
#define ImageHeight 1000 //image height
#define size_array 4
#define size_array_p 15
using namespace std;



double p[size_array_p] = {0.44, 0.46, 0.48, 0.50, 0.52, 0.54, 0.56, 0.58, 0.60, 0.62, 0.64, 0.68, 0.70, 0.72, 0.74};
int N [size_array] = {25, 50, 75, 100};
int sides = 0;  
int percent = 0;
int name [size_array] = {4, 5, 6, 7};
char filename[160];
int numbers = 0;
int amostras = 1000;


main ()
{
 
  int icounter, jcounter, a, b; //counters
  double rand = 0;
  int N2 = 0;

  // square generator

  for (sides = 0; sides < size_array; sides++)
    {
      int size = N[sides]*N[sides];
      int lat[size];  //create lattice
   
      for (percent = 0; percent < size_array_p; percent++)
	{
	  //reset na estatistica
	  int media_fast = 0;
	  int media_tempoqueima = 0;
	  int somaFast = 0;
	  int countNotFail = 0;
	  int somaTempoQueima = 0;
	  double frac = 0;
	  
	  for (numbers = 0; numbers < amostras; numbers++)
	    {
	      srand(time(NULL));
	      for (icounter = 0; icounter < N[sides]*N[sides]; icounter++)
		{     
		  rand = drand48();
		  if (rand < p[percent])
		    lat[icounter] = 1;
		  else
		    lat[icounter] = 0;
		}
    
	      sprintf(filename, "b&w_p%d_sides%d.ppm", name[percent], N[sides]); // now same as "colorcolumn.ppm"
	      // Print_lattice (lat, N[sides], N[sides], ImageWidth, ImageHeight,filename);

  
	      //metodo da queima
  
	      //branco(vazio) = 0            
	      //preto(ocupado) = 1            
	      //vermelho(a arder) = 2        
	      //verde(ardido) = 3             
	      //azul(arder a seguir) = 4      
  
	      for(a = 0; a < N[sides]; a++)
		{
	  
		  if(lat[a] == 1)
		    {
		      lat[a] = 2;
		      N2++;
		    }
		}

	      int count = 0;
	      int countfast = 0;
	  
	      while(N2 > 0)
		{
      
		  for(b = 0; b < N[sides]*N[sides]; b++)
		    {

		      if(lat[b] == 1)
			{
			  //comparar a esquerda
			  if(b % N[sides] != 0)
			    {
			      if(lat[b-1] == 2)
				{
				  lat[b] = 4;
				}
			    }

			  //comparar a direita

			  if(b % N[sides] != N[sides]-1)
			    {
			      if(lat[b+1] == 2)
				{
				  lat[b] = 4;
				}
			    }

			  // comparar cima
			  if(b/N[sides] != N[sides]-1)
			    {
			      if(lat[b + N[sides]] == 2)
				{
				  lat[b] = 4;
				}
			    }

			  //comparar baixo

			  if(b/N[sides] != 0)
			    {
			      if(lat[b - N[sides]] == 2)
				{
				  lat[b] = 4;
				}
			    }
			}
		    }
	

		  // 2 para 3; 4 para 2
		  for(b = 0; b < N[sides]*N[sides]; b++)
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

	     
		  // contar o numero de whiles
		  count++;
		  somaTempoQueima += count++;

		  // contar o numero de whiles ate um de cima estar a 3
	      
		  if(countfast == 0)
		    {
		      for(int x = 0; x < N[sides]; x++)
			{
			  int y = N[sides]-1;
			  if(lat[x+y*N[sides]]==2)
			    {
			      countfast = count;
			    }
			}
		    }
	     
		   
		  // sprintf(filename, "b&w_p%d_sides%d_queima.ppm", name[percent], N[sides]); // now same as "colorcolumn.ppm"
		  // Print_lattice (lat, N[sides], N[sides], ImageWidth, ImageHeight,filename);

     
		} //while	      

	      if(countfast != 0)
		{
		  countNotFail++;
		  somaFast += countfast;
		}

	    }//amostras

	  media_tempoqueima = somaTempoQueima/amostras; // faz a media do tempo de queima

	  //para nao dividir por zero
	  if(countNotFail != 0)
	    {	      
	      media_fast = somaFast/countNotFail; //faz a media das varias amostras do numero de whiles do caminho mais curto
	    }
	  else
	    {
	      media_fast = 0;
	    }
	     
	  frac = (double)countNotFail/amostras; // da frac dos que nao tem agregado com o total (rever)

	  cout << N[sides] << "\t" << p[percent] << "\t" << frac << "\t" << media_tempoqueima << "\t" << media_fast << endl;
	    
	} //percent
    }//L		     
}
