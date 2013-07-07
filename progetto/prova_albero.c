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
		printf("Scrivere... boh, tu scrivi qualcosa! ");
		while( fgets( word, MAXWORD, stdin ) != NULL )
			{
				printf("Scrivere... boh, tu scrivi qualcosa!");
				root = aggiungi_nodo(root,word);
				// premere CTRL-Z per terminare l'inserimento e CTRL-D su Linux / Mac
			}
		printf("\n------------------------------------------\n");


		stampa_albero(root);
		return 0;
	}

/*
struct nodo *copia(struct nodo *p)
	{
		struct nodo *root_2 = NULL;
		if( p == NULL )
			return NULL;
		root_2 = aggiungi_nodo(p, p->word);
		// memcpy(n,p,sizeof(struct tnodo));
		root_2->right = copia(p->right);
		root_2->left = copia(p->left);
		return root_2;
	}
*/
