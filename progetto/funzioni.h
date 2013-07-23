#include <stdio.h>
#include <string.h>
#include <stdlib.h>



// Dichiarazione delle funzioni
char *Ricerca_e_deriva(char funzione_1[],char funzione_2[],char primo_operando[]);

char output[100];

char potenza[100];
char somma[100];

/*			Inizio funzioni di derivazione		*/

/*	Derivate fondamentali	*/
char *D_Principali(char *primo_operando)
{
	if ( strcmp( primo_operando, "x" ) != 0 )
		{
			return "0";
	
		}
	else	
		return "1";
	
}

/*	Funzione Potenza	*/
char *Pow(char *funzione_1,char *funzione_2)
{
	printf("funzione_1 = %s\nfunzione_2 = %s\n", funzione_1, funzione_2);
													// Bisognerebbe controllare che il primo parametro sia una x e il secondo no
													// contrariamente si potrebbe avere "2^x" la cui derivata (credo) 0 poichè è una costante
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

	// Qui andrebbe messo uno split per controllare le sottofunzioni
	// e poi si richiama la funzione Ricerca_e_deriva per calcolare le derivate delle due funzioni


/*	if ( funzione_1[0] == 'p') 	
		strcpy(funzione_1, Pow(funzione_1, funzione_2));	
	
	if ( funzione_2[0] == 'p') 	
		strcpy(funzione_2, Pow(funzione_2, funzione_1));	
	
	
	sprintf(somma, "Plus(%s,%s) ", funzione_1, funzione_2);		
	// strcat(output,stringa_temp);		// serve per sommare le stringhe
	return somma;					
*/
}


/*------------------------------------------------------*
*		    Funizione Prodotto			*
* 							*
*	        questa funzione calcola			*
*   	        la derivata del prodotto		*
*							*
*     D(f(x) * g(x)) = f'(x) * g(x) + f(x) * g'(x)	*
*-------------------------------------------------------*/
char *Mul(char *funzione_1, char *funzione_2)
	{
	//	char *d_funzione_2;	// d_funzione_* corrisponde alla derivata di quella funzione
		printf("funzione_1 = %s\nfunzione_2 = %s\n", funzione_1, funzione_2);
		

		// Prima faccio lo split
		//char *d_funzione_1 = Ricerca_e_deriva(funzione_1, funzione_2, primo_operando);

		
		
	
	}


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

	printf("primo_operando = %s", primo_operando);
	
	if ( strcmp(primo_operando,"x") == 0 || ( strcmp(primo_operando,"plus") != 0 && strcmp(primo_operando,"mul") != 0 && strcmp(primo_operando,"sot") != 0 && strcmp(primo_operando,"pow") != 0 ))
		output = D_Principali(primo_operando); // Se il primo operando è una x oppure non è nessuna delle funzioni previste allora chiama D_Principali 	
	
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
