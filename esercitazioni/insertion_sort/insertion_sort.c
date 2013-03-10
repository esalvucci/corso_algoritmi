

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define fflush(stdin) while (getchar() != '\n')

// Prototipi delle funzioni
int ordinamento(int vettore[], int totale);

// main()
int main()
	{

		int totale, *vettore, i = 0, k = 0; // i corrisponde all'indice del vettore

	
		printf("Questo programma ordina un insieme di numeri in modo crescente, dopo che è stato concluso il loro inserimento\n");
		printf("Si inserisca il numero delle cifre da ordinare: ");
		scanf(" %d", &totale);
		fflush(stdin);
	
		totale--;
		
		vettore = (int*)malloc(totale * sizeof(int));

		// inserimento dei valori all'interno del vettore
		for ( i = 0; i < totale; i++)
			{
				
		/*		printf("Si inserisca il %d° vettore\n", i);
				if ( scanf("%d", &vettore[i]) == 0 )
					{
						printf("Input errato!\n");
						return -1;
					}
				fflush(stdin);
			//	printf("vettore[%d] == %d", i,vettore[i]);			
	*/

				vettore[i] = rand() % totale;			
	
			}
	
		ordinamento( vettore, totale);	
			// stampo il vettore ordinato
			for ( k = 0; k <= totale; k++)
				{
					printf("%d\n", vettore[k]);
				}
			
		free(vettore);
		return 0;
	}


int ordinamento(int  vettore[], int totale)
	{

		int j, k, key;

		for ( j = 1; j <= totale; j++) // 3 operazioni: inizializzazione j, controllo finale e incremento
			{
				key = vettore[j]; // 1 operazione

				k = j - 1; // 1 operazione
				while( k >= 0 && vettore[ k ] > key ) // 1 operazione
					{
						vettore[ k + 1 ] = vettore[ k ];
						k = k - 1;
					}
				vettore[ k + 1 ] = key; // 1 operazione

			
			}

		// totale operazioni per la funzione ordinamento: 7 
		return 0;		
	}
