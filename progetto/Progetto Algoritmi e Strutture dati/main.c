#include <stdio.h>
#include "stack.h"

void main()		// 2+(3*4) = +*342 =  (nello stack) 432, il + sta tra l'ultimo e il penultimo numero, il per tra il penultimo e il terzultimo e così via!
	{
		int valore = 5;

				while ( valore >= 0 )
					{
						push(valore+1);
						valore--;
					}

				valore = pop();

				printf("valore = %d", valore);


	}
