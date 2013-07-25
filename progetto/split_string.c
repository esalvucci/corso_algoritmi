#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

int liv=0;
int main()
{
	char *ris=NULL;
	char str[]= "cos(x)";     //stringa in imput
	ris=split(str);
	printf("Risultato =%s\n",ris);
	return 0;
}
