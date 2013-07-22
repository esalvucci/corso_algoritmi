#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[]="mul(plus(4,6),pow(x,5))";     //stringa in imput
	int x = 0,y = 0, pt = 0, max, contatore_aperta = 0, contatore_chiusa = 0, contatore_virgola = 0;
	char parte_tok[50]="", funzione_1[50]="", funzione_2[50]="";					// stringa in output	
	
	max=strlen(str);
	printf("%s\n", str);					// stampa vett originale

	while(x <= max )							//ciclo per scorrere il vett
	{
		parte_tok[y]=str[x];	//copia cella per cella nel vett di out
z

		if ( str[x + 1] == '(' )
			{
				contatore_aperta++;

//				if ( contatore_chiusa < contatore_aperta)
					//richiama funzione
				for (pt = 0; pt < 50; pt++)
					parte_tok[pt] = 0;
				y = -1;
				x++;
				// y = -1;
			}
		
		if ( str[x + 1] == ',' )
			{	strcpy(funzione_1, parte_tok);
				contatore_virgola++;							// Controllare con il debugger passo passo quanto valgono i contatori!
				if ( contatore_virgola == contatore_aperta )
					{
						for (pt = 0; pt < 50; pt++)
							parte_tok[pt] = 0;
					}
				y = -1;	
				x++;
				// y = -1;
			}
		else if ( str[ x + 1 ] == ')' )
			{	
				contatore_chiusa++;
				strcpy(funzione_2, parte_tok);		
			}	
		x++;
		y++;
	}

	printf("funzione_1 = %s\n", funzione_1);
	printf("funzione_2 = %s\n\n", funzione_2);
		
/*		if(str[x+1]==')' && str[x+2]==',')
			{
				strcpy(funzione_2, parte_tok);
				printf("funzione_2 = %s", funzione_2);	
				for(pt = 0; pt < 50; pt++)
					parte_tok[pt]=0;
			
				x++;
				y = -1;
			}
		
	
		if(str[x+1]==')') // questo incremento di indice serve per non considerare il caso ci fossero x),ecc
				x++;
		

		
		

		if(str[x+1]=='(')	//se incontra '(' mette a sx e sett flag a 1 
			{
				//	Se parte_tok == al nome di una funzione richiamo quella funzione
						
						// 	copio in funzione_1 quello che c'è tra la "(" e "),"
						// 	e in funzione_2 quello che c'è tra ")," e ")"
				
	
				for(pt = 0; pt < 50; pt++)		// ciclo per svuotare il vett finale
					parte_tok[pt]=0;
			
				x++;			// incrementa x xke cosi a nuovo ciclo non considera la ( ) ,
				y = -1;		// imposta y a -1 xke a fine ciclo viene incrementato e cosi a nuovo ciclo parte da 0
			}
	
		x++;		// incremento dell'indice per scorrere il vett
		y++;		// incremento dell'indice per scorrere il vet di destinazione 
*/


	return 0;
}

