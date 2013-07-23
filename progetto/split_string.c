#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

// dichiarazione delle variabili
char funzione_1[50] = "", funzione_2[50] = "", primo_operando[50] = "";


void split(char *str);

int main()
{
	char str[]= "pow(x,3)";     //stringa in imput
	char *output = NULL;

	printf("%s\n", str);	// stampa vett originale

	split(str);

	printf("funzione_1 = %s\n", funzione_1);
	printf("funzione_2 = %s\n\n", funzione_2);
	printf("primo_operando = p%s\n\n", primo_operando);

	output = Ricerca_e_deriva(funzione_1,funzione_2,primo_operando);

	printf("output = %s\n\n", output);

	return 0;
}


void split(char *str)
	{
		int x = 0,y = 0,yy=0, pt = 0, flag_primo=1, contatore_aperta = 1;
		int max = strlen(str);
		char parte_tok[50] = ""; 
		
		while(x <= max )							//ciclo per scorrere il vett
			{
				if(flag_primo==1)
					{
						primo_operando[x]=str[x];
						if(str[x+1]=='(' )
							flag_primo=0;
					}

				if(str[x-1]=='(')					// inizia a copiare 
					{
						while(contatore_aperta>0)		// copia fino a quando 
							{
								if(str[x]=='(')
									contatore_aperta++;
								if(str[x]==',')
									contatore_aperta--;
								parte_tok[y]=str[x];	//copia cella per cella nel vett di out
								x++,y++;
							}
						strcpy(funzione_1,parte_tok);
						for(pt=0;pt<50;pt++)
							{
								parte_tok[pt]=0;
							}
					}
				else if(contatore_aperta==0)
					{
						while(x <= max-1 )
							{
								parte_tok[yy]=str[x-1];
								yy++,x++;
							}
						strcpy(funzione_2,parte_tok);
						for( pt=0; pt<50;pt++)
							{
								parte_tok[pt]=0;
							}
					}
				x++;
			}
	}
