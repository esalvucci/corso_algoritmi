/*
	Enrico Salvucci

	Programma per l'ordinamento di un vettore di interi tramite l'algoritmo Quick Sort

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define fflush(stdin) while (getchar() != '\n')

// Prototipi delle funzioni
int quick_sort(int vettore[], int left, int right);
// int merge(int vettore[], int tmp[], int left, int middle, int right);
int partition(int vettore[], int left, int right);
void swap( int vettore[], int p, int j);

// main()
int main()
	{

		int totale, *vettore, i = 0, k = 0; // i corrisponde all'indice del vettore
		double tempo;
		clock_t start, end;
	
		printf("Questo programma ordina un insieme di numeri in modo crescente, dopo che è stato concluso il loro inserimento (tramite Quick Sort)\n");
		printf("Si inserisca il numero delle cifre da ordinare: ");
		scanf(" %d", &totale);
		fflush(stdin);
	
		totale--;
		
		
		vettore = (int*)malloc(totale * sizeof(int));
		
		// inserimento dei valori all'interno del vettore
		for ( i = 0; i < totale; i++)
			{
				vettore[i] = rand() % totale;			
			}
	
		// inizio timer
		start = clock();

		quick_sort( vettore, 0, totale - 1);	

		//fine timer
		end = clock();

		tempo = (double) (end - start) / CLOCKS_PER_SEC;
			
		// stampo il vettore ordinato
		for ( k = 0; k <= totale; k++)
			{
				printf(" %d ", vettore[k]);
			}
	
		printf("Insertion Sort eseguito in %f secondi\n\n", tempo);
		
		free(vettore);

		return 0;
	}


int quick_sort(int vettore[], int left, int right)
	{

		int p; // Pivot

		if ( left < right )
			{
				p = partition(vettore, left, right);
				quick_sort(vettore, left, p - 1);
				quick_sort(vettore, p + 1, right);
			}
		
		return 0;
	}

int partition(int vettore[], int left, int right)
	{
		int i, j, indice = 0;

		i = vettore[right];
		// j = left - 1;
		j = left;
		
		for ( indice = left; indice <= right - 1; indice++ )
			{
				if ( vettore[indice] <= i )
					{
						j++;
						swap(vettore, j, indice);
					}
			}
		swap(vettore, j + 1, right);		
		
		return j + 1;

	}

void swap( int vettore[], int p, int j)
	{
		int tmp;

		tmp = p;
		
		p = j;
		j = tmp;
	}













































