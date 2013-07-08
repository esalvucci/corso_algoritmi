/* bozza di programma */
#include <stdio.h>
#include "albero.h"
#define MAXWORD 100

void leggi_albero(struct nodo *);
struct nodo *copia(struct nodo *);
/*		Funzione main	*/
int main()
	{

		struct nodo *root = NULL;
		struct nodo *root_2 = NULL;
		char word[MAXWORD];
		
		// Prendo in input la funzione, a noi questo non servirà perchè la prenderemo da un file di testo
		printf("\npremere CTRL-Z per terminare l'inserimento e CTRL-D su Linux / Mac\n\n");
		printf("Scrivere... boh, tu scrivi qualcosa!");
		while( fgets( word, MAXWORD, stdin ) != NULL )
			{
				// premere CTRL-Z per terminare l'inserimento e CTRL-D su Linux / Mac
				printf("Scrivere... boh, tu scrivi qualcosa!");
				root = aggiungi_nodo(root,word);
			}
		printf("\n------------------------------------------\n");


		stampa_albero(root);
		return 0;
	}