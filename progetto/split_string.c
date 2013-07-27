
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

int main()
{
	
	//char str[]= "plus(plus(plus(plus(plus(5,6),x),x),5),x)";     //stringa in imput
	char str[]= {"plus(x,sin(x))"};     //stringa in imput

	char *ris;

	ris = (char*)malloc(sizeof(char)*strlen(str));

	printf("\n%s\n\n\n\n", str);

	ris=split(str);
	printf("Risultato =%s\n",ris);
	return 0;
}
