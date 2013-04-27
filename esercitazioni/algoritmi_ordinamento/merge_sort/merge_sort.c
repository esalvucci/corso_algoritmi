/*
	Enrico Salvucci

	Programma per l'ordinamento di un vettore di interi tramite l'algoritmo Merge Sort

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define fflush(stdin) while (getchar() != '\n')

// Prototipi delle funzioni
int merge_sort(int vettore[], int tmp[], int left, int right);
int merge(int vettore[], int tmp[], int left, int middle, int right);


// main()
int main()
	{

		int totale, *vettore, *tmp, i = 0, k = 0; // i corrisponde all'indice del vettore
		double tempo;
		clock_t start, end;
	
		printf("Questo programma ordina un insieme di numeri in modo crescente, dopo che è stato concluso il loro inserimento (tramite Merge Sort)\n");
		printf("Si inserisca il numero delle cifre da ordinare: ");
		scanf(" %d", &totale);
		fflush(stdin);
	
		totale--;
		
		
		vettore = (int*)malloc(totale * sizeof(int));
		tmp = (int*)malloc(totale * sizeof(int));
		
		// inserimento dei valori all'interno del vettore
		for ( i = 0; i < totale; i++) {
				vettore[i] = rand() % totale;			
			}
	
		// inizio timer
		start = clock();

		merge_sort( vettore, tmp, 0, totale - 1);	

		//fine timer
		end = clock();

		tempo = (double) (end - start) / CLOCKS_PER_SEC;
			
		// stampo il vettore ordinato
//		for ( k = 0; k <= totale; k++)
//			{
//				printf(" %d ", vettore[k]);
//			}
	
		printf("Insertion Sort eseguito in %f secondi\n\n", tempo);
		
		free(vettore);
		free(tmp);

		return 0;
	}


int merge_sort(int  vettore[], int tmp[], int left, int right)
	{
		int middle;

		if ( left < right )
			{
				middle = ( left + right ) / 2;
				merge_sort(vettore, tmp, left, middle);
				merge_sort(vettore, tmp, middle + 1, right);
				merge(vettore, tmp, left, middle + 1, right);
			}

		return 0;		
	}


int merge(int vettore[], int tmp[], int left, int middle, int right)
	{


		int i, left_end, num_elements, tmp_pos;

		left_end = middle - 1;

		tmp_pos = left;

		num_elements = right - left + 1;

		while ( (left <= left_end) && (middle <= right))
			{
				if (vettore[left] <= vettore[middle])
					{
	
						tmp[tmp_pos] = vettore[left];
		
						tmp_pos = tmp_pos + 1;

						left = left +1;
					}
				else
					{

						tmp[tmp_pos] = vettore[middle];

						tmp_pos = tmp_pos + 1;
	
						middle = middle + 1;

					}	
			}



		while (left <= left_end)
			{

				tmp[tmp_pos] = vettore[left];
				left = left + 1;
				tmp_pos = tmp_pos + 1;
			}



		while (middle <= right)
			{	

				tmp[tmp_pos] = vettore[middle];
				middle = middle + 1;
				tmp_pos = tmp_pos + 1;

			}	



		for (i = 0; i <= num_elements; i++)
			{
				vettore[right] = tmp[right];

				right = right - 1;

			}

		return 0;
	}
