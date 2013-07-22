#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Dichiarazione delle funzioni
char *Ricerca_e_deriva(char funzione_1[],char funzione_2[],char primo_operando[]);


char output[100];



char potenza[100];
char somma[100];

/*			Inizio funzioni di derivazione		*/

/*	Funzione Potenza	*/
char *Pow(char *funzione_1,char *funzione_2)
{
	printf("funzione_1 = %s\nfunzione_2 = %s\n", funzione_1, funzione_2);

	sprintf(potenza, "Mul(%s,(Pow(%s,Sot(%s,1)))", funzione_2,funzione_1,funzione_2);		
	// strcat(output,stringa_temp);		// serve per sommare le stringhe
	return potenza;					
}

/*------------------------------------------------------*
*		    Funizione Somma			*
* 							*
*	        questa funzione calcola			*
*   	        la derivata della somma			*
*							*
*            D(f(x) + g(x)) = a*f'(x)+b*g'(x)		*
*-------------------------------------------------------*/

char *Sum(char *funzione_1,char *funzione_2)
{
	printf("funzione_1 = %s\nfunzione_2 = %s\n", funzione_1, funzione_2);
	
	// verifico se ci sono funzioni composte
	if ( funzione_1[0] == 'p') 	
		strcpy(funzione_1, Pow(funzione_1, funzione_2));	
	
	if ( funzione_2[0] == 'p') 	
		strcpy(funzione_2, Pow(funzione_2, funzione_1));	
	
	
	sprintf(somma, "Plus(%s,%s) ", funzione_1, funzione_2);		
	// strcat(output,stringa_temp);		// serve per sommare le stringhe
	return somma;					
}


/*------------------------------------------------------*
*		    Funizione Prodotto			*
* 							*
*	        questa funzione calcola			*
*   	        la derivata del prodotto		*
*							*
*     D(f(x) * g(x)) = f'(x) * g(x) + f(x) * g'(x)	*
*-------------------------------------------------------*/
/*char *Mul(char *funzione_1, char *funzione_2)
	{
	//	char *d_funzione_2;	// d_funzione_* corrisponde alla derivata di quella funzione
		printf("funzione_1 = %s\nfunzione_2 = %s\n", funzione_1, funzione_2);
		

		// Prima faccio lo split
		char *d_funzione_1 = Ricerca_e_deriva(funzione_1, funzione_2, );

		
		
	
	}
*/
/*------------------------------------------------------*
*		Funzione Ricerca_e_deriva		*
*							*
*	questa funzione ci permette di entrare nella	*
*      funzione corrispondente all'operatore in esame,	*
*     la quale successivamente calcolerà la derivata.	*
*							*
*-------------------------------------------------------*/

char *Ricerca_e_deriva(char funzione_1[],char funzione_2[],char primo_operando[])
{

	char *output;
	
	if(strcmp(primo_operando,"pow")==0)
	{
		output = Pow(funzione_1,funzione_2);
	}
	else if(strcmp(primo_operando,"mul")== 0)	 //------------------------------------------- Mul
	{
		//Mul();
	}
	else if(strcmp(primo_operando,"plus") == 0)	//------------------------------------------- Add
	{ 
		//Add();
		output = Sum(funzione_1,funzione_2);
	}
	else if(strcmp(primo_operando,"sot") == 0)	//------------------------------------------- Sot
	{ 
		//Sot();
	}
/*	if(strcmp(primo_operando,"div")== 0)	//------------------------------------------- Div
	{ 
		//Div();
	}*/

	return output;	

}
