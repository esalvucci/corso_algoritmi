// Questa è una libreria che implementa le funzioni per la gestione di uno stack, in particolare per push e pop

#include <stdio.h>
#include <stdlib.h>

// Dichiarazione delle funzioni della libreria
void push(char valore);
int pop();

struct node
		{
			char valore;	// valore dell'elemento da inserire nello stack
			struct node *next;
		};

struct queue
	{
		struct node *first, *last;
	} coda;

void push(char carattere)
	{
		struct node *new_c;

		new_c = (struct node*)malloc(sizeof(struct node));

		// Controllo che la malloc sia andata a buon fine
		if ( new_c == NULL )
			{
				printf("Errore di memoria!");
				return;
			}
		else
			{
				if ( coda.first == NULL )
					coda.first = new_c;
				else
					coda.last->next = new_c;
				coda.last = new_c;

				new_c->valore = carattere;
			}




	}

int pop()
	{
		struct node *tmp;

		// Controllo se la lista è vuota, nel caso non restituisco niente
		if ( coda.first == NULL )
			return 0;
		
		tmp = coda.first;
		coda.first = coda.first->next;	// il secondo elemento dello stack diventa la testa
		
		if ( coda.first->next == NULL )
			{
				coda.first = NULL;
				coda.last = NULL;
			}

		return tmp->valore;
	}
