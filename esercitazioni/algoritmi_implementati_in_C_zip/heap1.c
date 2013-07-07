#include "stdio.h"
#include <stdlib.h>
#include <time.h>

void print(), insert(), heapify(int), random_init();
int getMax();

struct heap { //il mio alberello
	int *buffer; //vettore
	int length; //numero di nodi
	int buffer_len;
} myHeap;

int main() {
	int quit = 0;
	myHeap.length = 0;
	
	int dim;
	printf("insert buffer dimension:\n");
	do {
		scanf("%d", &dim);
		fflush(stdin);
	} while(dim < 0);
	myHeap.buffer = (int*) malloc(sizeof(int) * dim);
	myHeap.buffer_len = dim;
	
	while(!quit) {
		printf("\n\n_______________________________________\n\n\n");
		int scelta;
		printf("1: random initialization of the array\n");
		printf("2: insert an element\n");
		printf("3: get the max\n");
		printf("4: print\n");
		printf("5: exit\n");
		
		do {
			scanf("%d", &scelta);
			fflush(stdin);
		} while(scelta < 1 && scelta > 5);
		
		switch(scelta) {
			case 1: random_init(); break;
			case 2: insert(); break;
			case 3: printf("%d\n", getMax()); break;
			case 4: print(); break;
			case 5: quit = 1; break;
			default: break;
		}
	}
	return 0;
}

void insert() {
	if(myHeap.length < myHeap.buffer_len) {
		int newElement;
		int index;
		
		printf("insert the new element\n");
		scanf("%d", &newElement); //prendi in input l'elemento da inserire nell'heap
		fflush(stdin);
		
		myHeap.length++; //l'heap ora ha un elemento aggiuntivo!
		index = myHeap.length - 1;
		myHeap.buffer[index] = newElement;
		
		while(myHeap.buffer[index] > myHeap.buffer[(index - 1) / 2]) { //non posso fare (index/2) perchè il vettore parte da 0 e non da 1
			int appoggio;
			
			//scambio
			appoggio = myHeap.buffer[index];
			myHeap.buffer[index] = myHeap.buffer[(index - 1) / 2];
			myHeap.buffer[(index - 1) / 2] = appoggio;
			
			index = (index - 1) / 2;
		}
	}
	else printf("buffer is full\n");
}

void print() { //stampo tutto l'albero
	int i=0, j, h=1;
	
	printf("\n");
	while(i!=myHeap.length) {
		for(j=0; j!=h && i!=myHeap.length ; j++) {
			printf("%d ", myHeap.buffer[i]);
			i++;
		}
		h *= 2;
		printf("\n");
	}
}

int getMax() {
	int index;
	int max;
	int done = 0; //variabile booleana che mi dice quanto posso uscire dal ciclo
	int appoggio;
	
	if(myHeap.length == 0) {
		printf("the heap is empty\n");
		return 0;
	}
	
	max = myHeap.buffer[0];
	
	myHeap.length--;
	index = 0;
	
	myHeap.buffer[index] = myHeap.buffer[myHeap.length]; //porto l'ultima foglia in radice
	
	do {
		int child;
		
		child = ((index + 1) * 2) - 1; //non posso fare (index * 2) perchè il vettore parte da 0 e non da 1
		
		if(child > myHeap.length) //se sono andato oltre all'ultima foglia
			done = 1;
		else if(child == myHeap.length) { //se ho un solo figlio
			if(myHeap.buffer[index] > myHeap.buffer[child])
				done = 1;
			else {
				appoggio = myHeap.buffer[index];
				myHeap.buffer[index] = myHeap.buffer[child];
				myHeap.buffer[child] = appoggio;
				
				index = child;
			}
		}
		else { //se ho entrambi i figli
			if(myHeap.buffer[index] > myHeap.buffer[child] && myHeap.buffer[index] > myHeap.buffer[child + 1])
				done = 1;
			else {
				if(myHeap.buffer[child] < myHeap.buffer[child + 1])
					child++;
				
				//scambio
				appoggio = myHeap.buffer[index];
				myHeap.buffer[index] = myHeap.buffer[child];
				myHeap.buffer[child] = appoggio;
				
				index = child;
			}
		}
	} while(!done);
	
	return max;
}

void random_init() {
	int i;
	
	srand(time(NULL));
	for(i=0; i!=myHeap.buffer_len; i++)
		myHeap.buffer[i] = rand() % 10000;
	
	myHeap.length = myHeap.buffer_len;
	
	for(i=myHeap.length / 2; i>=0; i--) {
		heapify(i);
	}
}

void heapify(int parent) {
	int left = parent * 2;
	int right = left + 1;
	int largest, temp;
	
	if(left < myHeap.length && myHeap.buffer[left] > myHeap.buffer[parent])
		largest = left;
	else
		largest = parent;
	if(right < myHeap.length && myHeap.buffer[right] > myHeap.buffer[largest])
		largest = right;
	if(largest != parent) {
		temp = myHeap.buffer[parent];
		myHeap.buffer[parent] = myHeap.buffer[largest];
		myHeap.buffer[largest] = temp;
		
		heapify(largest);
	}
}
