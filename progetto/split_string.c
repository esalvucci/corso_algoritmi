#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

int main()
{
	char str[]= "plus(x,3)";     //stringa in imput
	char *output;

//	printf("%s\n", str);	// stampa vett originale

	split(str);

//	printf("funzione_1 = %s\n", funzione_1);
//	printf("funzione_2 = %s\n\n", funzione_2);
//	printf("primo_operando = p%s\n\n", primo_operando);

	output = Ricerca_e_deriva();

	printf("output = %s\n\n", output);

	return 0;
}
