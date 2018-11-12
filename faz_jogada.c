#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void faz_jogada(char TAB[25][21], int j1, int k1, int j2, int k2) {
	char temp;

	TAB[j2][k2] = TAB[j1][k1];
	TAB[j1][k1] = ' ';
	
}