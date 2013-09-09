
/*	Header	*/

/*          Funzioni di derivazione          */
char *D_Fondamentali(char *primo_operando);   // Funzione che deriva i casi base: costante (n) e variabile (x)
char *Pow(char *funzione_1,char *funzione_2, char *potenza);    // Funzione che calcola la derivata della potenza
char *Sum(char *funzione_1,char *funzione_2, char *somma);      // Funzione che calcola la derivata della somma
char *Sot(char *funzione_1,char *funzione_2, char *sottrazione);// Funzione che calcola la derivata della sottrazione
char *Mul(char *funzione_1, char *funzione_2, char *prodotto);  // Funzione che calcola la derivata del prodotto
char *Div(char *funzione_1, char *funzione_2, char *rapporto);  // Funzione che calcola la derivata del rapporto
char *Cos(char *funzione_1, char *derivata_1, char *coseno);    // Funzione che calcola la derivata del coseno
char *Sin(char *funzione_1, char *derivata_1, char *seno);      // Funzione che calcola la derivata del sen



char *split(char *str);	// Funzione che divide la stringa in operatore funzione_1 e funzione_2

char *Ricerca_e_deriva(char *funzione_1, char *funzione_2, char *primo_operando, char *output);		// Funzione che controlla quale funzione di derivazione eseguire ed entra nella stessa
