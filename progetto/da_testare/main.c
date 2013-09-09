
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"


int main()
{


	FILE *file_input = NULL, *file_output;
	char *risultato;
	char stringa[1000];
	int scelta = 0;

	// Eseguo un while che permette la scelta all'utente tra tre possibilità
	do
		{
			printf("\nSi scelga una tra queste opzioni\n");
			printf("\n1 - Aprire il file funzione.txt che contiene la funzione da derivare\n");
			printf("\n2 - Inserire la funzione in input tramite tastiera\n");
			printf("\n3 - Leggere il contenuto del file in output (risultato della derivata)\n");
			printf("\n4 - Uscire dal programma\n");
		
			printf("\n\n--> ");	
			fscanf(stdin, "%d", &scelta);	
			while ( getchar() != '\n' );
							
			
			switch ( scelta )
				{
					// Nel primo caso viene letto un file che si trova nella directory corrente e viene data in pasto alla funzione split la stringa contenuta da funzione.txt
					case 1 :
						{

							printf("Leggo il file funzione.txt\n");
					
							// Apro il file
							file_input = fopen("funzione.txt", "r");
							
							// Verifico che il file sia stato aperto correttamente	
							if ( file_input == NULL )
								{
									printf("Attenzione, il file funzione.txt non è stato trovato!");
									break;
								}
								
							// stampo il contenuto del file sulla stringa
							fscanf(file_input, "%s", stringa);	
								

							// eseguo la funzione split calcolando la derivata della funzione data in input
							risultato = split(stringa);
						
							// chiudo il file in input e successivamente apro quello su cui scriverò la funzione in output
							fclose(file_input);
						
							file_output = fopen("derivata.txt", "w");
							if ( file_output == NULL )
								{
									printf("Attenzione, il file non è stato trovato!");
									break;
								}
						
							// Scrivo la derivata sul file di output
							fprintf(file_output, "%s", risultato);

							printf("\nHo scritto il risultato della derivata in derivata.txt");	
	
							// chiudo il file di output		
							fclose(file_output);
					
							printf("\n\tf(x) = %s\n\n\tDerivata = %s\n\n", stringa, risultato);
							break;
						}
					case 2 :
						{
							printf("\nSi inserisca una funzione: (max 10000 caratteri)\n");
							fgets(stringa, 10000, stdin);	// tramite la fgets prendo in input una stringa ponendo però un limite sul numero di caratteri, in questo modo evito un possibile (ma improbabile) stack overflow causato dall'inserimento, oppuro semplicemente un overflow involontario da parte dell'utente

							stringa[strlen(stringa)-1] = '\0';	// elimino il carattere terminatore della stringa presa in input ( \n )	
									
							// calcolo la derivata della funzione passata in input e successivamente la stampo a video
							risultato = split(stringa);
							
							printf("\n\tf(x) = %s\n\n\tDerivata = %s\n\n", stringa, risultato);
							
							break;	
						}
					case 3:
						{
							// stampo il contenuto del file derivata.txt, su cui è stato scritto il risultato della derivata calcolata nel punto 1
							
							// apro il file
							file_output = fopen("derivata.txt", "w");
							
							// verifico che il file sia stato aperto correttamente
							if ( file_output == NULL )
								{
									printf("\nAttenzione, il file non è stato trovato!\n");
									break;
								}
							// se risultato == NULL significa che il punto 1 non è stato ancora eseguito
							if ( risultato == NULL )
								{
									printf("\nNon è stata ancora calcolata nessuna derivata!\n\n");
									break;
								}

							// stampo il risultato della derivata precedentemente calcolata sul file derivata.txt
							fprintf(file_output, "%s", risultato);
							printf("%s", risultato);
	
							// chiudo il file
							fclose(file_output);
							break;
						}
					case 4: return 1;
				
					default: break;
				}
			}	
		while (scelta > 0 || scelta < 4 );

		return 0;
	}
