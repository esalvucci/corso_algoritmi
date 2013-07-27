
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

int main()
{
	char *ris=NULL;
	
	//char str[]= "plus(plus(plus(plus(plus(5,6),x),x),5),x)";     //stringa in imput
	char str[]= {"plus(plus(plus(plus(plus(plus(mul(pow(x,6),10),mul(pow(x,5),4)),mul(pow(x,4),21)),mul(pow(x,3),18)),mul(pow(x,2),7)),mul(x,2)),sin(x))"};     //stringa in imput
//char str[] = "plus(mul(mul(12,pow(x,3)),mul(16,pow(x,2))),mul(cos(x),sin(x)))";

/*	Test Set	*/
/*

char str[] = "plus(plus(plus(mul(3,pow(x,3)),mul(5,pow(x,2))),mul(12,x),5)))";

plus(mul(mul(12,pow(x 3 mul(16,pow(x 2 mul(c(x) s(x)

mul(mul(mul(c(x) plus(mul(4,pow(x 3 mul(x s(x) s(x) - 5 x

mul(s (x) mul(c(x) plus(mul(^ x 3 plus(x 5 mul(4,pow(x 2

plus(mul(plus(c(x) x plus(mul(mul(mul(2 s(x) 4 x c(x) mul(c(x) s(x)

*/

	ris=split(str);
	printf("Risultato =%s\n",ris);
	return 0;
}
