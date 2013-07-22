#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

int main()
{
	char str[]="plus(8,pow(x,2))";     //stringa in imput
	int x = 0,y = 0,yy=0, pt = 0,max,flag_primo=1, contatore_aperta = 1;
	char parte_tok[50]="", funzione_1[50]="", funzione_2[50]="",primo_operando[5]="";					// stringa in output	
	
	max=strlen(str);
	printf("%s\n", str);	// stampa vett originale
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

	printf("funzione_1 = %s\n", funzione_1);
	printf("funzione_2 = %s\n\n", funzione_2);
	printf("primo_operando = %s\n\n", primo_operando);

	char *output = Ricerca_e_deriva(funzione_1,funzione_2,primo_operando);

	printf("output = %s\n\n", output);

	return 0;
}

