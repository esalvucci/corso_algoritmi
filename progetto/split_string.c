#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bintree.h"

//	flag=1 mette a sx
//	flag=-1 mette a dx
//	flag=0 mette in padre
int main()
{
	char str[]="mul(plus(4,6),pow(x,5))";     //stringa in imput
	int x = 0,y = 0, pt = 0, max,flag=0;
	char parte_tok[50]="";					// stringa in output	
	
	struct albero *root = NULL;


	max=strlen(str);
	printf("%s\n", str);					// stampa vett originale

	while(x <= max)							//ciclo per scorrere il vett
	{
		parte_tok[y]=str[x];	//copia cella per cella nel vett di out
		if(str[x+1]=='(')	//se incontra '(' mette a sx e sett flag a 1 
		{
			if (flag==1 && root->left == NULL)	// caso flag =1
				{
			//		printf("a sx %s\n",parte_tok);
					// inserisco a sinistra
					root->left = nuovo_nodo(root->left, parte_tok);

				}		
			else if(flag==-1 && root->right == NULL)		// caso flag=-1
				{
				//	printf("a dx %s\n",parte_tok);	
					// inserisco a destra
					root->right = nuovo_nodo(root->right, parte_tok);
				}
			else if(flag==0 && root == NULL)		// primo caso mette a padre
				{
				//	printf("il padre %s\n",parte_tok);
					// Inserisco il padre
					root = nuovo_nodo(root, parte_tok);
				}
			
			
			for(pt = 0; pt < 50; pt++)		// ciclo per svuotare il vett finale
				parte_tok[pt]=0;
			
			flag=1;			// setta flag=1 per mettere a sx nel prossimo ciclo
			x++;			// incrementa x xke cosi a nuovo ciclo non considera la ( ) ,
			y = -1;		// imposta y a -1 xke a fine ciclo viene incrementato e cosi a nuovo ciclo parte da 0
		}
		else if(str[x+1]==',' || str[x+1]==')')  //se deve mettere a dx come sopra
		{
			if(str[x+1]==')') // questo incremento di indice serve per non considerare il caso ci fossero x),ecc
				x++;
			
			if (flag==1 && root->left == NULL )
				{
					printf("a sx %s\n",parte_tok);
					root->left = nuovo_nodo(root->left, parte_tok);
				}
			else if(flag==-1 && root->right == NULL )
				{
					printf("a dx %s\n",parte_tok);
					root->right = nuovo_nodo(root->right, parte_tok);
				}
			
			for(pt = 0; pt < 50; pt++)
				parte_tok[pt]=0;
			
			flag=-1;		// flag per mettere a dx il prossimo ciclo
			x++;
			y = -1;
		}
		x++;		// incremento dell'indice per scorrere il vett
		y++;		// incremento dell'indice per scorrere il vet di destinazione 
	}	

	stampa_albero(root);

	

	return 0;
}

