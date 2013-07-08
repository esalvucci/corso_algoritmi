/* bozza di programma */
#include <stdio.h>
#include "albero.h"
#include <stack.h>
#define MAXWORD 100

//void leggi_albero(struct nodo *);
struct nodo *copia(struct nodo *);
char *somma(struct nodo *root);
char *lettura(struct nodo *root);


/*		Funzione main	*/
int main()
	{

		struct nodo *root = NULL;
		char word[MAXWORD];
		
		// Prendo in input la funzione, a noi questo non servirà perchè la prenderemo da un file di testo
		printf("Scrivere... boh, tu scrivi qualcosa! ");
		while( fgets( word, MAXWORD, stdin ) != NULL )
			{
				printf("Scrivere... boh, tu scrivi qualcosa!");
				// root = aggiungi_nodo(root,word);
				push(word);
				// premere CTRL-Z per terminare l'inserimento e CTRL-D su Linux / Mac
			}
		printf("\n------------------------------------------\n");
		
		lettura(root);

		stampa_albero(root);
		return 0;
	}

