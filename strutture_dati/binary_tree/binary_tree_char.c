/*************************************************************************************************************
* In questo file verranno incluse le funzioni necessarie a costruire un albero binario, 
* e gestirlo tramite i puntatori che ogni radice ha verso il figlio destro e il figlio sinistro.
* L'interfaccia è abbastanza semplice, una volta avviato si arriva ad un menu.
* Si consiglia per compilarlo sotto *nix di usare "gcc -o btree binarytree.c" , 
* Per avviarlo invece, come suggerisce l'ERRORE di parametri
* sarà utile seguire la forma ./btree <nomefile>, in cui nomefile può anche contenere il path completo.
* i dati presenti in nomefile devono essere degli interi separati da spazi.
**************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
FILE *intfile;
struct nodo
	{
				// comincio a definire la struttura che mi servirà
		char word;                                          // come posso notare ho il valore attuale
		struct nodo *left, *right;                                // e due puntatori uno al figlio sinistro 
		
	}*tree;
 
struct nodo *mergetree(char el, struct nodo *left, struct nodo *right)
	{
		 // mergetree unisce due alberi
		struct nodo *p = (struct nodo*)malloc(sizeof(struct nodo));
		p->left = left;
		p->right = right;
		p->word = el;
 		return p;
}
struct nodo *nuovo_nodo(char el)
	{
     		return mergetree(el, NULL, NULL);                   // ogni foglia è formata da un valore 
                                                         // e due puntatori nulli.
	}
struct nodo *insert(char el, struct nodo *root){ // si inserisce un intero el, nell'albero t
		if(root == NULL)                                    // se l'albero e' vuoto, allora verrà creata una foglia
			return nuovo_nodo(el);
		if ( el == '+' || el == '-' || el == '*')                                   // altrimenti si procede da direttive, ovvero se il valore della radice e' >= dell'elemento
			return mergetree(root->word, insert(el,root->left), root->right); //andrà a sinistradd
		else
				return mergetree(root->word, root->left, insert(el, root->right));
		
	}

void showtree(struct nodo *root)
	{
	    if (root != NULL)
		{
			showtree(root->left);
			printf("%c ", root->word);
			showtree(root->right);
		} 
   	}

int main(int argc, char *argv[]){
    if(argc<2){                                           // controllo che ci siano tutti i parametri
        printf("ERRORE: Per avviare il programma la sintassi è ./btree <file>\n");
        return(1);
    }
    if ((intfile = fopen(argv[1],"r")) == NULL){         // apro il file che mi serve
        printf("ERRORE: Non riesco ad aprire il file %s\n",argv[1]);
        return(2);
    } printf("*Ho aperto il file %s.\n",argv[1]);
    char carattere;                                             // scansiono il file di interi
    struct nodo *albero = NULL;                                  // inizializzo l'albero vuoto
    while(fscanf(intfile,"%c", &carattere) != EOF){
        albero = insert(carattere,albero);
    }
    printf("*Ho costruito l'albero binario\n\nCosa vuoi fare adesso?\n[s]tampare l'albero.\ncercare il [m]inimo.\ncercare il [M]assimo\n[u]scire.\n\n");
    char tmp;
    printf(">");
    while((tmp = getchar()) != 'u'){
        switch (tmp){
             case 's':                                    // serve a mostrare l'albero
                 showtree(albero);
                 printf("\n");
                 break;
             default:
                 printf(">");
                 break;
        }
    }
    fclose(intfile);
    return(0);
}
