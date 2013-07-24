#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void merge_sort(int*, int, int);
void merge(int*, int, int, int);

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
	
	merge_sort(buffer, 0, length - 1);
	
	time2 = time(0) - time1; //fine cronometro
	
	printf("%d\n", time2);
	
	return 0;
}

void merge_sort(int* buffer, int a, int b) {
	if(a < b) {
		int m;
		
		m = (a + b) / 2;
		merge_sort(buffer, a, m);
		merge_sort(buffer, m + 1, b);
		merge(buffer, a, m, b);
	}
}

void merge(int* buffer, int a, int m, int b) {
	int i, k, h;
	int* sorted;
	
	sorted = (int *) malloc(sizeof(int) * (b - a + 1));
	
	//indici relativi delle due partizioni di buffer
	k = a;
	h = m+1;
	
	i=0;
	for(i=0; i<=(b - a); i++) {
		if(k > m) { //la prima metà è vuota
			sorted[i] = buffer[h];
			h++;
		}
		else if(h > b) { //la seconda metà è vuota
			sorted[i] = buffer[k];
			k++;
		}
		else {
			if(buffer[k] < buffer[h]) {
				sorted[i] = buffer[k];
				k++;
			}
			else {
				sorted[i] = buffer[h];
				h++;
			}
		}
	}
	
	//copy sorted vector on buffer
	for(i=0; i<=(b - a); i++)
		buffer[i + a] = sorted[i];
	
	free(sorted);
}
