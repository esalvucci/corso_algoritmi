#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *split(char *str);



char output[100];

// dichiarazione delle variabili per la funzione split()




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
	// segmentation fault con char *potenza;	
	char potenza[50] = "";
	
	//printf("funzione_1 = %s\nfunzione_2 = %s\n", funzione_1, funzione_2);
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

char *Sum(char *funzione_1,char *funzione_2,char *primo_operando)
{

	char somma[50] = "";
	char *derivata_1;	
	// verifico se ci sono funzioni composte
	
	// Qui andrebbe messo uno split per controllare le sottofunzioni
	// e poi si richiama la funzione Ricerca_e_deriva per calcolare le derivate delle due funzioni
	derivata_1 = split(funzione_1);

	sprintf(somma, "Plus(%s,%s) ", derivata_1, funzione_2);		
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

char *Ricerca_e_deriva(char *funzione_1, char *funzione_2, char *primo_operando)
{

	char *output = NULL;

//	printf("primo_operando = %s\n", primo_operando);
	
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
		output = Sum(funzione_1,funzione_2,primo_operando);
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



char *split(char *str)
{
	int x = 0,y = 0,yy=0, pt = 0,max,flag_primo=1, contatore_aperta = 1;
	char parte_tok[50]="", funzione_1[50]="", funzione_2[50]="",primo_operando[5]="";					// stringa in output	


	max=strlen(str);
	printf("stringa principale = %s\n", str);	// stampa vett originale
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
			printf("primo_operando = %s\n", primo_operando);
			while(contatore_aperta>0)		// copia fino a quando 
			{
				if(str[x]=='(')
				contatore_aperta++;
				if(str[x+1]==',')
				contatore_aperta--;
				parte_tok[y]=str[x-1];	//copia cella per cella nel vett di out
				x++,y++;
			}
			strcpy(funzione_1,parte_tok);
			for(pt=0;pt<50;pt++)
			{
				parte_tok[pt]=0;
			}
			x++;
			//printf("livello %d\n",liv++);
			//printf("derivata= %s\n", Ricerca_e_deriva(funzione_1, funzione_2, primo_operando));
			if(funzione_1[0]=='m' || funzione_1[0]=='s' || funzione_1[0]=='p')
			{split(funzione_1);}
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
			//printf("livello %d\n",liv++);
			printf("derivata= %s\n", Ricerca_e_deriva(funzione_1, funzione_2, primo_operando));
			if(funzione_2[0]=='m' || funzione_2[0]=='s' || funzione_2[0]=='p')
			{split(funzione_2);}
		}
		x++;
	}
	
	return Ricerca_e_deriva(funzione_1, funzione_2, primo_operando);

}

