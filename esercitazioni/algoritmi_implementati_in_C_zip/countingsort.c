#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print(int*, int);
void counting_sort(int*, int, int);

int main(int argc, char* argv[]) {
	int i, *buffer, time1, time2;
	
	if(argc < 3) {
		printf("USAGE: countingsort <buffer dimesnion> <number range>\n");
		return 0;
	}
	
	long int length;
	
	length = atoi(argv[1]); //prende il valore da input e lo mette in length
	
	buffer = (int*) malloc(sizeof(int) * length);
	
	//random initialization of buffer
	srand(time(NULL));
	for(i=0; i!=length; i++)
		buffer[i] = rand() % atoi(argv[2]);
	
	time1 = time(0); //avvio cronometro
	
	counting_sort(buffer, length, atoi(argv[2]));
	
	time2 = time(0) - time1; //fine cronometro
	
	if(length < 13) print(buffer, length);
	
	printf("%d seconds\n", time2);
	
	return 0;
}

void counting_sort(int* buffer, int buffer_size, int range) {
	int *occurrencies;
	int i, j;
	
	occurrencies = (int*) malloc(sizeof(int) * range);
	
	for(i=0; i!=buffer_size; i++)
		occurrencies[i] = 0;
	
	for(i=0; i!=buffer_size; i++)
		occurrencies[buffer[i]]++;
	
	int current = 0;
	for(i=0; i!=range; i++)
		for(j=0; j!=occurrencies[i]; j++)
			buffer[current++] = i;
}

void print(int* buffer, int length) {
	int i;
	for(i=0; i!=length; i++)
		printf("%d ", buffer[i]);
	printf("\n");
}
