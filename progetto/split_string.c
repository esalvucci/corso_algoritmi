
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"


int main()
{


	FILE *file_input, *file_output;
	char *risultato=NULL;

	char stringa[100];
	int scelta = 0;

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
					case 1 :
						{
							printf("Leggo il file funzione.txt\n");
					
							file_input = fopen("funzione.txt", "r");
							if ( file_input == NULL )
								{
									printf("Attenzione, il file funzione.txt non è stato trovato!");
									break;
								}
								
							fscanf(file_input, "%s", stringa);	
								
							risultato = split(stringa);
						
							fclose(file_input);
						
							file_output = fopen("derivata.txt", "w");
							if ( file_output == NULL )
								{
									printf("Attenzione, il file non è stato trovato!");
									break;
								}
						
							fprintf(file_output, "%s", risultato);

							printf("\nHo scritto il risultato della derivata in derivata.txt");			
							fclose(file_output);
					
							printf("\n\tf(x) = %s\n\n\tDerivata = %s\n\n", stringa, risultato);

							break;
						}
					case 2 :
						{
							printf("\nSi inserisca una funzione: (max 10000 caratteri)\n");
							fgets(stringa, 10000, stdin);

							stringa[strlen(stringa)-1] = '\0';	
									
							risultato = split(stringa);
							
							printf("\n\tf(x) = %s\n\n\tDerivata = %s\n\n", stringa, risultato);
							
							break;	
						}
					case 3:
						{
	
							file_output = fopen("derivata.txt", "w");
							if ( file_output == NULL )
								{
									printf("\nAttenzione, il file non è stato trovato!\n");
									break;
								}
							
							if ( risultato == NULL )
								{
									printf("\nNon è stata ancora calcolata nessuna derivata!\n\n");
									break;
								}
							fprintf(file_output, "%s", risultato);
							printf("%s", risultato);
	
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
