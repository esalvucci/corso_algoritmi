/*************************************************************************************************************
 * * In questo file verranno incluse le funzioni necessarie a costruire un albero binario, 
 * * e gestirlo tramite
 * * i puntatori che ogni radice ha verso il figlio destro e il figlio sinistro.
 * * L'interfaccia e' abbastanza semplice, una volta avviato si arriva ad un menu.
 * * Si consiglia per compilarlo sotto *nix di usare "gcc -o btree binarytree.c" , 
 * * Per avviarlo invece, come suggerisce l'ERRORE di parametri
 * * sarà utile seguire la forma ./btree <nomefile>, in cui nomefile può anche contenere il path completo.
 * * i dati presenti in nomefile devono essere degli interi separati da spazi.
 * **************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

FILE *intfile;
typedef struct T
	{			// comincio a definire la struttura che mi servirà
	int value;		// come posso notare ho il valore attuale
	struct T *T_l, *T_r;	// e due puntatori uno al figlio sinistro 
				// l'altro al figlio destro.
	} *tree, dim;

  
tree mergetree(int el, tree t1, tree t2)
	{ // mergetree unisce due alberi
		tree t0 = (tree)malloc(sizeof(dim));
		t0->T_l = t1;
		t0->T_r = t2;
		t0->value = el;
		return(t0);
	}
	
tree createleaf(int el)
	{
	
	return mergetree(el, NULL, NULL);	// ogni foglia e' formata da un valore 
						// e due puntatori nulli.
	}

int isvoidtree(tree t)
	{ // verifico che un albero sia vuoto
		if (t == NULL)                                      // se non c'e' nulla e' ovvio che e'un albero vuoto..
			return true;
		else return false;
	}
tree leftchild(tree t)
	{ // restituisce il figlio sinistro, accedendo alla struttura tree.
		return t->T_l;
	}
tree rightchild(tree t)
	{ // restituisce il figlio destro, accedendo alla struttura tree.
		return t->T_r;
	
	}

int root(tree t)
	{ // restituisce la radice, sempre facendo accesso alla struttura 
		return t->value;
	}

tree insert(int el, tree t)
	{ // si inserisce un intero el, nell'albero t
		if(isvoidtree(t))                                    // se l'albero e' vuoto, allora verrà creata una foglia
			return createleaf(el);
		if (root(t) >= el)                                   // altrimenti si procede da direttive, ovvero se il valore della radice e' >= dell'elemento
			return mergetree(root(t), insert(el,leftchild(t)), rightchild(t)); //andrà a sinistradd
		if (root(t) < el)                                    // se la radice e' invece minore dell'elemento verrà inserita a destra.
			return mergetree(root(t), leftchild(t), insert(el, rightchild(t)));
		else
			return t;
	}
int mintree(tree t)
	{ // Trovo il minimo per dicotomia: sapendo che più mi muovo in basso
		if(isvoidtree(leftchild(t)))
			return root(t);         // ed a sinistra, più ho un numero piccolo.
	       	else
			return mintree(leftchild(t));                   // ripeto la procedura ricorsivamente.
	}
	
int maxtree(tree t)
	{
		if(isvoidtree(rightchild(t)))
			return root(t);        // Come per il minimo, solo che in questo caso mi muovo in basso a destra.
		else
			return maxtree(rightchild(t));
	}

void showtree(tree t)
	{
       		int i;
		
		if (isvoidtree(t) == false)
			{
				showtree(leftchild(t));
				
				printf("%d ", root(t));
				showtree(rightchild(t));
	
			}
	}

int main(int argc, char *argv[])
	{
	
		if(argc<2)
			{                                           // controllo che ci siano tutti i parametri
				printf("ERRORE: Per avviare il programma la sintassi e' ./btree <file>\n");
				return(1);
			}

		if ((intfile = fopen(argv[1],"r")) == NULL)
			{         // apro il file che mi serve
				printf("ERRORE: Non riesco ad aprire il file %s\n",argv[1]);
				return(2);

			}
		
		printf("*Ho aperto il file %s.\n",argv[1]);

		int num;                                             // scansiono il file di interi
		tree albero = NULL;                                  // inizializzo l'albero vuoto

		while(fscanf(intfile,"%d", &num) != EOF)
			{
				albero = insert(num,albero);
			}

		printf("*Ho costruito l'albero binario\n\nCosa vuoi fare adesso?\n[s]tampare l'albero.\ncercare il [m]inimo.\ncercare il [M]assimo\n[u]scire.\n\n");
	
		char tmp;

		printf(">");

		while((tmp = getchar()) != 'u')
			{ 
				switch (tmp)
					{  
						case 's':                                    // serve a mostrare l'albero
			  			showtree(albero);
						printf("\n");
						break;

						case 'm':                                    // stampa a video il valore minimo
						printf("Il valore minimo dell'albero binario e' %d\n",mintree(albero));
						break;
						
						case 'M':                                    // stampa a video il valore massimo
						printf("Il valore massimo dell'albero binario e' %d\n",maxtree(albero));
						break;
						
						default:
						printf(">");
						break;
					}
			}

		fclose(intfile);

		return(0);

	}
