#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

int main()
{
	char *ris=NULL;
	char str[]= "plus(pow(x,23),pow(x,2))";     //stringa in imput
	ris=split(str);
	printf("Risultato =%s\n",ris);
	return 0;
}
