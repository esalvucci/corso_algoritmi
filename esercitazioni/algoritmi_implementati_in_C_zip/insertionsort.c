#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int i, j, key, *buffer, time1, time2;
	
	long int length;
	
	length = atoi(argv[1]); //prende il valore da input e lo mette in length
	
	buffer = (int*) malloc(sizeof(int) * length);
	
	//random initialization of buffer
	srand(time(NULL));
	for(i=0; i!=length; i++)
		buffer[i] = rand() % 2000;
	
	time1 = time(0); //avvio cronometro
	
	//insertion sort
	for(j=1; j!=length; j++) {
		key = buffer[j];
		i = j - 1;
		while (i>=0 && buffer[i]>key) {
			buffer[i+1] = buffer[i];
			i--;
		}
		buffer[i+1] = key;
	}
	
	time2 = time(0) - time1; //fine cronometro
	
	printf("%d\n", time2);
	
	return 0;
}
