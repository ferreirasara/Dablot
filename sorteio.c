#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sorteio() {
	srand(time(NULL));
	int i = rand() % 2;
	return i;
}