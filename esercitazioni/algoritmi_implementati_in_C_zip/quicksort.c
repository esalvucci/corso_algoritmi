#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void quick_sort(int*, int, int);
int partition(int*, int, int);
void print(int*, int);

int main(int argc, char* argv[]) {
	int i, *buffer, time1, time2;
	
	long int length;
	
	length = atoi(argv[1]); //prende il valore da input e lo mette in length
	
	buffer = (int*) malloc(sizeof(int) * length);
	
	//random initialization of buffer
	srand(time(NULL));
	for(i=0; i!=length; i++)
		buffer[i] = rand() % 2000;
	
	time1 = time(0); //avvio cronometro
	
	quick_sort(buffer, 0, length - 1);
	
	time2 = time(0) - time1; //fine cronometro
	
	if(length < 13) print(buffer, length);
	
	printf("%d\n", time2);
	
	return 0;
}

void quick_sort(int* buffer, int a, int b) {
	if(a < b) {
		int pivot;
		
		pivot = partition(buffer, a, b);
		quick_sort(buffer, a, pivot);
		quick_sort(buffer, pivot + 1, b);
	}
}

int partition(int* buffer, int a, int b) {
	int pivot, temp;
	
	pivot = buffer[a];
	
	a--;
	b++;
	
	while(a < b) {
		while(buffer[++a] < pivot);
		while(buffer[--b] > pivot);
		if(a < b) {
			temp = buffer[a];
			buffer[a] = buffer[b];
			buffer[b] = temp;
		}
	}
	return b;
}

void print(int* buffer, int length) {
	int i;
	for(i=0; i!=length; i++)
		printf("%d ", buffer[i]);
	printf("\n");
}
