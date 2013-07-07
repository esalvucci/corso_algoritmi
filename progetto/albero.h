/* bozza di programma */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 100


/*		Dichiarazione delle strutture dati	*/
struct nodo
	{
		char *word;
		struct nodo *left, *right;
	};

struct nodo *aggiungi_nodo(struct nodo *,char *);

/*		Dichiarazione delle funzioni	*/
void stampa_albero(struct nodo *);

struct nodo *aggiungi_nodo(struct nodo *p,char *w)
	{
		// Controllo se l'albero è vuoto, o se il nodo in cui mi trovo è vuoto (perchè potrei per esempio spostarmi a sinistra e trovare un nodo == NULL)
		if (p == NULL)
			{

				p = malloc(sizeof(struct nodo));
				p->word = strdup(w);		// strdup(); copia e restituisce la stringa data come parametro, questa viene messa in p->word
				p->left = p->right = NULL;
			}
	 	// Attenzione! Manca il contrllo sulla malloc (che però mi da problemi)	
		else if ( !strcmp(w,"plus") )

			p->left = aggiungi_nodo(p->left,w);	// Se il nodo contiene un operatore (in questa prova "plus") allora lo inserisco a sinistra

		else p->right = aggiungi_nodo(p->right,w);	// Se il nodo contiene una variabile, oppure una costante, allora lo inserisco a destra

		return p;
		

		// Manca la free();

	}


void stampa_albero(struct nodo *p)
	{
		// Stampo l'albero tramite In Order Method
		if (p != NULL)
			{

				stampa_albero(p->left);
				printf("%s ",p->word);
				stampa_albero(p->right);

			}

	}

/*
struct nodo *duplica(struct *p)
	{
		
		if (!p) return NULL;

		struct nodo *root_2 = NULL;
		
		root_2 = aggiungi_nodo(root_2, p->word);
		
		root_2->word = p->word;
		root_2->left = duplica(p->left);
		root_2->right = duplica(p->right);
		return root_2;
	}
*/
