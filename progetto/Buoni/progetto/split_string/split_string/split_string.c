
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

int main()
{
	char *ris=NULL;
	
	//char str[]= "plus(plus(plus(plus(plus(5,6),x),x),5),x)";     //stringa in imput
//char str[] = "plus(mul(mul(12,pow(x,3)),mul(16,pow(x,2))),mul(cos(x),sin(x)))";


//char str[] = "mul(sin(x),mul(cos(x),plus(mul(pow(x,3),plus(x,5)),mul(4,pow(x,2)))))";


// 1 Funzione
//char str[] = "plus(plus(plus(mul(3,pow(x,3)),mul(5,pow(x,2))),mul(12,x)),5)";
// La prima funzione è corretta



// 2° funzione
//char str[] = "plus(mul(mul(12,pow(x,3)),mul(16,pow(x,2))),mul(cos(x),sin(x)))";
// La seconda funzione è corretta

// 3° Funzione
//char str[] = "mul(mul(cos(x),plus(mul(sin(x),x),mul(4,pow(x,3)))),mul(sin(x),sot(5,x)))";

// prova
//char str[] = "plus(mul(3,pow(x,3)),mul(4,pow(x,5)))";

//char str[] = "div(plus(x,4),x)";

char str[] = "div(plus(x,7),pow(x,2))";


//char str[] = "plus(pow(x,4),sot(x,1))";

/*	Test Set	*/
/*


plus(mul(mul(12,pow(x 3 mul(16,pow(x 2 mul(c(x) s(x)

mul(mul(mul(c(x) plus(mul(4,pow(x 3 mul(x s(x) s(x) - 5 x

mul(s (x) mul(c(x) plus(mul(^ x 3 plus(x 5 mul(4,pow(x 2

plus(mul(plus(c(x) x plus(mul(mul(mul(2 s(x) 4 x c(x) mul(c(x) s(x)

*/

	ris = split(str);

	printf("\n\tf(x) = %s\n\n\tDerivata = %s\n\n", str, ris);
	return 0;
}
