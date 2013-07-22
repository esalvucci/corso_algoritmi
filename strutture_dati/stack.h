// Questa è una libreria che implementa le funzioni per la gestione di uno stack, in particolare per push e pop

#include <stdio.h>
#include <stdlib.h>

// Dichiarazione delle funzioni della libreria
void push(char valore);
int pop();

struct stack
		{
			char valore;	// valore dell'elemento da inserire nello stack
			struct stack *next;
		};

struct stack *head = NULL;

void push(char carattere)
	{
		struct stack *new_s;

		new_s = (struct stack*)malloc(sizeof(struct stack));

		// Controllo che la malloc sia andata a buon fine
		if ( new_s == NULL )
			{
				printf("Errore di memoria!");
				return;
			}
		else
			{
				new_s->valore = carattere;
				new_s->next = head;
				head = new_s;

			}




	}

int pop()
	{
		struct stack *tmp;

		// Controllo se la lista è vuota, nel caso non restituisco niente
		if ( head == NULL )
			return 0;

		tmp = head;
		head = head->next;	// il secondo elemento dello stack diventa la testa
		tmp->next = NULL;

		return tmp->valore;
	}
