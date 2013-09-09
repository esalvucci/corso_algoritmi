#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funzioni.h"
#define MAX 1000

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
		potenza = (char *)malloc(sizeof(char)*(sizeof(funzione_1)+sizeof(funzione_2)*2+20));
		
		// Controllo che la malloc sia andata a buon fine
		if ( potenza == NULL )
			{
				printf("Errore nell'allocazione della memoria, esco dal programma!");
				exit (-1);
			}	
	
		
		// tramite la funzione sprintf scrivo il risultato della derivata sulla funzione di output (in questo caso potenza)
		sprintf(potenza, "Mul(%s,Pow(%s,Sot(%s,1)))", funzione_2,funzione_1,funzione_2);		
		return potenza;				
	}

char *Sum(char *funzione_1,char *funzione_2, char *somma)
	{

		somma = (char *)malloc(sizeof(char)*(sizeof(funzione_1)+sizeof(funzione_2)+8));
		
		// Controllo che la malloc sia andata a buon fine
		if ( somma == NULL )
			{
				printf("Errore nell'allocazione della memoria, esco dal programma!");
				exit (-1);
			}	
		

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
		sprintf(somma, "Plus(%s,%s)",funzione_1, funzione_2);		
		return somma;				

	}


char *Sot(char *funzione_1,char *funzione_2, char *differenza)
	{
		differenza = (char *)malloc(sizeof(char)*(sizeof(funzione_1)+sizeof(funzione_2)+8));
		
		// Controllo che la malloc sia andata a buon fine
		if ( differenza == NULL )
			{
				printf("Errore nell'allocazione della memoria, esco dal programma!");
				exit (-1);
			}	
		
		
		// Se la funzione non è tra le funzioni fondamentali eseguo lo split e calcolo la derivata di ciò che ottengo
		if(funzione_1[0] == 'm' || funzione_1[0] == 's' || funzione_1[0]=='p' || funzione_1[0] == 'c')
			funzione_1 = split(funzione_1);
		else
		// In caso contrario calcolo la derivata fondamentale
			funzione_1 = D_Fondamentali(funzione_1);

		
		// Il procedimento è analogo ma lo eseguo sul secondo parametro della funzione
		if(funzione_2[0] == 'm' || funzione_2[0] == 's' || funzione_2[0] == 'p' || funzione_1[0] == 'c')
			funzione_2 = split(funzione_2);
		else 
			funzione_2 = D_Fondamentali(funzione_2);

		// tramite la funzione sprintf scrivo il risultato della derivata sulla funzione di output (in questo caso differenza)
		sprintf(differenza, "Sot(%s,%s)",funzione_1, funzione_2);		
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
	
		if ( prodotto == NULL )
			{	
				printf("Errore nell'allocazione della memoria, esco dal programma!");
				exit (-1);
			}	
	
		
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
		sprintf(prodotto,"Plus(Mul(%s,%s),Mul(%s,%s))",d_funzione_1,funzione_2,funzione_1,d_funzione_2);
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
		d_funzione_1 = (char *)malloc(sizeof(char)*MAX);
		d_funzione_2 = (char *)malloc(sizeof(char)*MAX);
			
		// Controllo che le 3 malloc siano andate a buon fine	
		if ( rapporto == NULL || d_funzione_1 == NULL || d_funzione_2 == NULL)
			{	
				printf("Errore nell'allocazione della memoria, esco dal programma!");
				exit (-1);
			}	

		if(funzione_1[0]=='m' || funzione_1[0]=='s' || funzione_1[0]=='p'  || funzione_1[0] == 'c')
			d_funzione_1=split(funzione_1);
		else
			d_funzione_1=D_Fondamentali(funzione_1);


		if(funzione_2[0]=='m' || funzione_2[0]=='s' || funzione_2[0]=='p'  || funzione_2[0] == 'c')
			d_funzione_2=split(funzione_2);
		else 
			d_funzione_2=D_Fondamentali(funzione_2);
	
		// tramite la funzione sprintf scrivo il risultato della derivata sulla funzione di output (in questo caso rapporto)
		sprintf(rapporto,"Div(Sot(Mul(%s,%s),Mul(%s,%s)),pow(%s,2))",d_funzione_1,funzione_2,funzione_1,d_funzione_2,funzione_2);
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
		
		// Controllo che la malloc sia andata a buon fine
		if ( coseno == NULL )
			{
				printf("Errore nell'allocazione della memoria, esco dal programma!");
				exit (-1);	
			}	
	
		if(funzione_1[0] == 'm' || funzione_1[0] == 's' || funzione_1[0] == 'p'  || funzione_1[0] == 'c')
			derivata_1 = split(funzione_1);
		else
			derivata_1 = D_Fondamentali(funzione_1);

		// tramite la funzione sprintf scrivo il risultato della derivata sulla funzione di output (in questo caso coseno)
		sprintf(coseno, "Mul(-Sin(%s),%s)",funzione_1, derivata_1);		
	
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
		
		// Controllo che la malloc sia andata a buon fine
		if ( seno == NULL )
			{
				printf("Errore nell'allocazione della memoria, esco dal programma!");
				exit (-1);
			}


		if(funzione_1[0] == 'm' || funzione_1[0] == 's' || funzione_1[0] == 'p'  || funzione_1[0] == 'c')
			derivata_1 = split(funzione_1);
		else
			derivata_1 = D_Fondamentali(funzione_1);


		// tramite la funzione sprintf scrivo il risultato della derivata sulla funzione di output (in questo caso seno)
		sprintf(seno, "Mul(Cos(%s),%s)",funzione_1, derivata_1);		
	
		return seno;
	}




/*------------------------------------------------------*
*                Funzione Ricerca_e_deriva              *
*                                                       *
*       questa funzione ci permette di entrare nella    *
*      funzione corrispondente all'operatore in esame,  *
*     la quale successivamente calcolerà la derivata.   *
*                                                       *
*-------------------------------------------------------*/

char *Ricerca_e_deriva(char *funzione_1, char *funzione_2, char *operatore, char *output)
	{
		output = (char *)malloc(sizeof(char)*10000);
		if ( strcmp(operatore,"x") == 0 || ( strcmp(operatore,"plus") != 0 && strcmp(operatore,"mul") != 0 && strcmp(operatore,"sot") != 0 && strcmp(operatore,"pow") != 0 ))
			output = D_Fondamentali(operatore); // Se il primo operando è una x oppure non è nessuna delle funzioni previste allora chiama D_Fondamentali 	
	
		if(strcmp(operatore,"pow") == 0)	//	Potenza
			output = Pow(funzione_1,funzione_2, output);
	
		if(strcmp(operatore,"mul") ==  0)	//	Prodotto
			output = Mul(funzione_1 ,funzione_2, output);	
		
		if(strcmp(operatore,"div") == 0)	//	Rapporto
			output = Div(funzione_1 ,funzione_2, output);	
		
		if(strcmp(operatore,"plus") == 0)	//	Somma
			output = Sum(funzione_1,funzione_2, output);
		
		if(strcmp(operatore,"sot") == 0)	//	Differenza
			output = Sot(funzione_1,funzione_2, output);

		if(strcmp(operatore,"sin") == 0)	//	Seno
			output = Sin(funzione_1, "", output);
		
		if(strcmp(operatore,"cos") == 0)	//	Coseno
			output = Cos(funzione_1, "", output);
		
		
		return output;		// Ritorno la funzione già derivata	
}



/*------------------------------------------------------*
*                     Funzione Split                    *
*                                                       *
*    questa funzione divide la funzione in input in     *
*          operatore, funzione_1 e funzione_2           *
*       e richiama la funzione Ricerca_e_deriva         *
*                                                       *
*-------------------------------------------------------*/

char *split(char *str)
	{
		int x = 0,y = 0,yy=0, pt = 0,max,flag_primo=1, contatore_aperta = 1,cont_parentesi=0,bul_cos_sin=0;
		char parte_tok[MAX]="", funzione_1[MAX]="", funzione_2[MAX]="",operatore[MAX]="";	


		max=strlen(str);
		
		while(x <= max )							//ciclo per scorrere il vett
			{
				if(flag_primo==1)
					{
						operatore[x]=str[x];
						if(str[x+1]=='(' )
							flag_primo=0;
					}

				if(str[x-1]=='(')					// inizia a copiare 
					{	
						while(contatore_aperta>0)		// copia fino a quando 
							{	
								if( (str[x]=='c' && str[x+1]=='o'&& str[x+2]=='s') || (str[x]=='s' && str[x+1]=='i'&& str[x+2]=='n') )
									bul_cos_sin=1;
								if( bul_cos_sin==1)
								{
									if(str[x]=='(')
										cont_parentesi++;
									else if(str[x]==')')
										cont_parentesi--;
									if(cont_parentesi==0)
										contatore_aperta--;
								}
								if(str[x]=='(')
									contatore_aperta++;
								
								if(str[x+1]==',')
									contatore_aperta--;
			
								if(str[x-1]=='(' && str[x+1]==')')	// Attenzione! così si prende solo sin(x)
									contatore_aperta--;
								if( strcmp(operatore,"cos")==0 ||  strcmp(operatore,"sin") == 0)
								{
									if(str[x-1]=='(')
										cont_parentesi++;
									else if(str[x+1]==')')
										cont_parentesi--;
									if(cont_parentesi==0)
										contatore_aperta--;
								}

								parte_tok[y]=str[x];	//copia cella per cella nel vett di out
								x++,y++;
							}
		
						strcpy(funzione_1,parte_tok);
						x++;
				
						for(pt=0;pt<MAX;pt++)
							parte_tok[pt]=0;
					}
				else if(contatore_aperta==0)
					{
						while(x <= max-1 )
							{
								parte_tok[yy]=str[x-1];
								yy++,x++;
							}

						strcpy(funzione_2,parte_tok);
						for( pt=0; pt<MAX;pt++)
							parte_tok[pt]=0;
			
					}
				x++;
			}
	
		return Ricerca_e_deriva(funzione_1,funzione_2,operatore, NULL);	// Ritorno la funzione divisa in operatore, funzione_1, funzione_2
}

