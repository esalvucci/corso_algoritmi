
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

int main()
{
	char *ris=NULL;
	
	//char str[]= "plus(plus(plus(plus(plus(5,6),x),x),5),x)";     //stringa in imput
	char str[]= "plus(plus(x,3),plus(33,4))";     //stringa in imput
	ris=split(str);
	printf("Risultato =%s\n",ris);
	return 0;
}
