#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// sorteia qual dos times ira comecar
int sorteio() {
	srand(time(NULL));
	int i = rand() % 2;
	return i;
}