#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funzioni.h"
#define MAX 1000

// Impostiamo un limite massimo di lunghezza per tutti i vettori

/*          Derivate fondamentali          */
// Questa funzione ritorna la derivata dei due casi base: costante (n) e variabile (x)
char *D_Fondamentali(char *operatore)
	{
		if ( strcmp( operatore, "x" ) != 0 )
			return "0";	// Se l'operatore è una x la sua derivata è 0
		else	
			return "1";	// Se l'operatore è una costante la sua derivata è 1
	}

/*-------------- Derivata della potenza --------------*
*                                                     *
*      D(Pow(x,exp)) = Mul(exp,Pow(x,Sot(exp,1)))     *
*                                                     *
*-----------------------------------------------------*/

char *Pow(char *funzione_1,char *funzione_2, char *potenza)
	{	
		potenza = (char *)malloc(sizeof(char)* MAX);
	
		// tramite la funzione sprintf scrivo il risultato della derivata sulla funzione di output (in questo caso potenza)
		sprintf(potenza, "mul(%s,pow(%s,sot(%s,1)))", funzione_2,funzione_1,funzione_2);		
		return potenza;				
	}

char *Sum(char *funzione_1,char *funzione_2, char *somma)
	{

		somma = (char *)malloc(sizeof(char)*MAX);
		if(funzione_1[0] == 'm' || funzione_1[0] == 's' || funzione_1[0] == 'p' || funzione_1[0] == 'c')
		// Se la funzione non è tra le funzioni fondamentali eseguo lo split e calcolo la derivata di ciò che ottengo
			funzione_1 = split(funzione_1);
		else
		// In caso contrario calcolo la derivata fondamentale
			funzione_1 = D_Fondamentali(funzione_1);

	
		// Il procedimento è analogo ma lo eseguo sul secondo parametro della funzione
		if(funzione_2[0]=='m' || funzione_2[0]=='s' || funzione_2[0]=='p' || funzione_2[0] == 'c' )
			funzione_2 = split(funzione_2);	
		else 
			funzione_2 = D_Fondamentali(funzione_2);

		// tramite la funzione sprintf scrivo il risultato della derivata sulla funzione di output (in questo caso somma)
		sprintf(somma, "plus(%s,%s)",funzione_1, funzione_2);		
		return somma;				

	}


char *Sot(char *funzione_1,char *funzione_2, char *differenza)
	{
		differenza = (char *)malloc(sizeof(char)*MAX);
		
		// Se la funzione non è tra le funzioni fondamentali eseguo lo split e calcolo la derivata di ciò che ottengo
		if(funzione_1[0] == 'm' || funzione_1[0] == 's' || funzione_1[0]=='p' || funzione_1[0] == 'c')
			funzione_1 = split(funzione_1);
		else
		// In caso contrario calcolo la derivata fondamentale
			funzione_1 = D_Fondamentali(funzione_1);

		
		// Il procedimento è analogo ma lo eseguo sul secondo parametro della funzione
		if(funzione_2[0] == 'm' || funzione_2[0] == 's' || funzione_2[0] == 'p' || funzione_2[0] == 'c')
			funzione_2 = split(funzione_2);
		else 
			funzione_2 = D_Fondamentali(funzione_2);

		// tramite la funzione sprintf scrivo il risultato della derivata sulla funzione di output (in questo caso differenza)
		sprintf(differenza, "sot(%s,%s)",funzione_1, funzione_2);		
		return differenza;				
}



/*------------------ Derivata del Prodotto -----------------------*
*                                                                 *
*   D(Mul(f(x),g(x))) = Plus(Mul(f'(x),g(x)),Mul(f(x),g'(x)))     *
*                                                                 *
*-----------------------------------------------------------------*/
char *Mul(char *funzione_1, char *funzione_2, char *prodotto)
	{
		char *d_funzione_2;	
		char *d_funzione_1;   // d_funzione_* corrisponde alla derivata di quella funzione
	
	
		d_funzione_1 = (char *)malloc(sizeof(char)*MAX);
		d_funzione_2 = (char *)malloc(sizeof(char)*MAX);
		prodotto = (char *)malloc(sizeof(char)*MAX);
		
		// Se la funzione non è tra le funzioni fondamentali eseguo lo split e calcolo la derivata di ciò che ottengo
		if(funzione_1[0] == 'm' || funzione_1[0] == 's' || funzione_1[0]=='p' || funzione_1[0] == 'c')
			d_funzione_1 = split(funzione_1);
		else
		// In caso contrario calcolo la derivata fondamentale
			d_funzione_1 = D_Fondamentali(funzione_1);
		
		
		// Il procedimento è analogo ma lo eseguo sul secondo parametro della funzione
		if(funzione_2[0] == 'm' || funzione_2[0] == 's' || funzione_2[0] == 'p' || funzione_2[0] == 'c')
			d_funzione_2 = split(funzione_2);
		else 
			d_funzione_2 = D_Fondamentali(funzione_2);

		// tramite la funzione sprintf scrivo il risultato della derivata sulla funzione di output (in questo caso prodotto)
		sprintf(prodotto,"plus(mul(%s,%s),mul(%s,%s))",d_funzione_1,funzione_2,funzione_1,d_funzione_2);
		return prodotto;
	}



/*------------------ Derivata del Quoziente -----------------------*
*                                                                  *
*   D(Div(f(x),g(x))) = Div(Sot(Mul(f'(x),g(x)),Mul(f(x),g'(x))))  *
*                                                                  *
*------------------------------------------------------------------*/

char *Div(char *funzione_1, char *funzione_2, char *rapporto)
	{
		char *d_funzione_2;	
		char *d_funzione_1;   // d_funzione_* corrisponde alla derivata della funzione corrispondente
		
		rapporto = (char *)malloc(sizeof(char)*MAX);

		if(funzione_1[0]=='m' || funzione_1[0]=='s' || funzione_1[0]=='p'|| funzione_1[0] == 'c')
			d_funzione_1=split(funzione_1);
		else
			d_funzione_1=D_Fondamentali(funzione_1);


		if(funzione_2[0]=='m' || funzione_2[0]=='s' || funzione_2[0]=='p'|| funzione_2[0] == 'c')
			d_funzione_2=split(funzione_2);
		else 
			d_funzione_2=D_Fondamentali(funzione_2);
	
		// tramite la funzione sprintf scrivo il risultato della derivata sulla funzione di output (in questo caso rapporto)
		sprintf(rapporto,"div(sot(mul(%s,%s),mul(%s,%s)),pow(%s,2))",d_funzione_1,funzione_2,funzione_1,d_funzione_2,funzione_2);
		return rapporto;
	}



/*------------------ Derivata del Coseno ------------------------*
*                                                                *
*             D(Cos(f(x)) = Mul(-Sin(f(x)),f'(x))                *
*                                                                *
*----------------------------------------------------------------*/

char *Cos(char *funzione_1, char *derivata_1, char *coseno)
	{

		coseno = (char *)malloc(sizeof(char)*MAX);
		if(funzione_1[0] == 'm' || funzione_1[0] == 's' || funzione_1[0] == 'p'|| funzione_1[0] == 'c')
			derivata_1 = split(funzione_1);
		else
			derivata_1 = D_Fondamentali(funzione_1);

		// tramite la funzione sprintf scrivo il risultato della derivata sulla funzione di output (in questo caso coseno)
		sprintf(coseno, "mul(-Sin(%s),%s)",funzione_1, derivata_1);		
	
		return coseno;
	}



/*-------------------- Derivata del Seno ------------------------*
*                                                                *
*             D(Sin(f(x)) = Mul(-Sin(f(x)),f'(x))                *
*                                                                *
*----------------------------------------------------------------*/

char *Sin(char *funzione_1, char *derivata_1, char *seno)
	{

		seno = (char *)malloc(sizeof(char)*MAX);


		if(funzione_1[0] == 'm' || funzione_1[0] == 's' || funzione_1[0] == 'p'|| funzione_1[0] == 'c')
			derivata_1 = split(funzione_1);
		else
			derivata_1 = D_Fondamentali(funzione_1);


		// tramite la funzione sprintf scrivo il risultato della derivata sulla funzione di output (in questo caso seno)
		sprintf(seno, "mul(Cos(%s),%s)",funzione_1, derivata_1);		
	
		return seno;
	}




/*------------------------------------------------------*
*		Funzione Ricerca_e_deriva		*
*							*
*	questa funzione ci permette di entrare nella	*
*      funzione corrispondente all'operatore in esame,	*
*     la quale successivamente calcolerà la derivata.	*
*							*
*-------------------------------------------------------*/

char *Ricerca_e_deriva(char *funzione_1, char *funzione_2, char *operatore, char *output)
	{
		output = (char *)malloc(sizeof(char)*10000);
		if ( strcmp(operatore,"x") == 0 || (strcmp(operatore,"sin")!=0 && strcmp(operatore,"sin")!=0 && strcmp(operatore,"plus") != 0 && strcmp(operatore,"mul") != 0 && strcmp(operatore,"sot") != 0 && strcmp(operatore,"pow") != 0 ))
			output=D_Fondamentali(operatore); // Se il primo operando è una x oppure non è nessuna delle funzioni previste allora chiama D_Fondamentali 	
	
		if(strcmp(operatore,"pow") == 0)		//	Potenza
			output=Pow(funzione_1,funzione_2, output);
	
		if(strcmp(operatore,"mul") ==  0)		//	Prodotto
			output=Mul(funzione_1 ,funzione_2, output);	
		
		if(strcmp(operatore,"div") == 0)		//	Rapporto
			output=Div(funzione_1 ,funzione_2, output);	
		
		if(strcmp(operatore,"plus") == 0)	//	Somma
			output=Sum(funzione_1,funzione_2, output);
		
		if(strcmp(operatore,"sot") == 0)	//	Differenza
			output=Sot(funzione_1,funzione_2, output);

		if(strcmp(operatore,"sin") == 0)	//	Seno
			output = Sin(funzione_1, "", output);
		
		if(strcmp(operatore,"cos") == 0)	//	Coseno
			output = Cos(funzione_1, "", output);
		
		
		return output;		// Ritorno la funzione già derivata	
}



/*------------------------------------------------------*
*		     Funzione Split	                *
*                                                       *
*    questa funzione divide la funzione in input in     *
*          operatore, funzione_1 e funzione_2           *
*       e richiama la funzione Ricerca_e_deriva         *
*							*
*-------------------------------------------------------*/

char *split(char *str)
	{
		int x = 0,y = 0,yy=0, pt = 0,max,flag_primo=1, contatore_aperta = 1,bul_cos=0,cont_parentesi=0;
		char parte_tok[MAX]="", funzione_1[MAX]="", funzione_2[MAX]="",operatore[MAX]="";	


		max=strlen(str);
		
		while(x <= max )							//ciclo per scorrere il vett fino a max
			{
				if(flag_primo==1)					//a inizio funzione setta flag a 1 qundi fino a '(' scrive in operatore
					{
						operatore[x]=str[x];		// copia cella per cella
						if(str[x+1]=='(' )			//quando incontra '(' setta flag a 0 cosi non entra fino alla nuova chiamata della funzione
							flag_primo=0;
					}

				if(str[x-1]=='(')					// inizia a copiare 
					{	
						while(contatore_aperta>0)		// copia fino a quando 
							{	
								if((str[x]=='c' && str[x+1]=='o'&& str[x+2]=='s')||(str[x]=='s' && str[x+1]=='i'&& str[x+2]=='n'))//se incontra i due casi del sin e del cos divide tenendo conto delle '(' o')' xke non hanno ','
									bul_cos=1;				//setta bul_cos_sin a 1 per iniziare a contare a dividere in base alle parentesi
								if( (strcmp(operatore,"cos")==0 && bul_cos==1 )|| (strcmp(operatore,"sin")==0 && bul_cos==1))
								{
									if(str[x]=='(')			// incrementa un cont per tenere conto delle'('
										cont_parentesi++;
									else if(str[x+1]==')')	//dec il contatore sopra
										cont_parentesi--;
									if(cont_parentesi==0)	// se le '(' sono uguali alle ')' risetta
										contatore_aperta--;	// decrementa il con principale perchè in cos e sin non sono presenti le ','
								}
													
								if(str[x]=='(')			//incrementa un cont per capire quando finisce funzione_1
									contatore_aperta++;
								if(str[x+1]==',')		//decrementa il cont per sapere quando finisce funzione_1
									contatore_aperta--;
								if(str[x-1]=='(' && str[x+1]==')')		// questo if serve per gestire il caso semplice del seno o del coseno
									contatore_aperta--;
								if( (strcmp(operatore,"cos")==0) || (strcmp(operatore,"sin")==0))//funziona come sopra solo che serve per dividere 
								{
									if(str[x-1]=='(')		//incrementa un cont per gestire i casi del coseno e del seno
										cont_parentesi++;
									else if(str[x+1]==')')	// decrementa il contatore sopra
										cont_parentesi--;
									if(cont_parentesi==0)	//quando le '(' sono uguali alle')' decrementa di 1 il contatore principale xke in cos o sin non ci sono le ',' 
										contatore_aperta--;
								}
								
								parte_tok[y]=str[x];	//copia cella per cella nel vett di out
								x++,y++;
							}
						strcpy(funzione_1,parte_tok);	//copio la stringa ottenuta prima nella stringa funzione_1
						x++;
						for(pt=0;pt<MAX;pt++)	//ciclo per pulire parte_tok
							parte_tok[pt]=0;
					}
				else if(contatore_aperta==0)
					{
						while(x <= max-1 )	//finisco di copiare il resto della stringa fino a lunghezza meno 1 per escudere l'ultima ')' 
							{
								parte_tok[yy]=str[x-1];
								yy++,x++;
							}

						strcpy(funzione_2,parte_tok);		//copio parte_tok in funzione_2
						for( pt=0; pt<MAX;pt++)//pulisco parte_tok
							parte_tok[pt]=0;
			
					}
				x++;
			}
		printf("operatore %s\n",operatore);
		printf("funzione_1 %s\n",funzione_1);
		printf("funzione_2 %s\n",funzione_2);

		return Ricerca_e_deriva(funzione_1,funzione_2,operatore, NULL);	// Ritorno la funzione divisa in: operatore, funzione_1, funzione_2;
}

