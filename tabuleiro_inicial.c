#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool verifica_casa(int, int);

void tabuleiro_inicial(char TAB[25][21]) {
	int l, c, i;
	for (l = 0; l < 25; l++) {
		for (c = 0; c < 21; c++) {
			if (verifica_casa(l, c)) {
				TAB[l][c] = ' ';
			}
		}
	}
	for (l = 0; l < 9; l += 2) {
		if (l % 4 == 0) {
			for (c = 0; c < 21; c += 4) {
				TAB[l][c] = 'G';
			}
		} else {
			for (c = 2; c < 19; c += 4) {
				for (i = 17; i < 28; i++) {
					TAB[l][c] = 'G';
				}
			}
		}
	}
    for (l = 16; l < 25; l += 2) {
		if (l % 4 == 0) {
			for (c = 0; c < 21; c += 4) {
				for (i = 0; i < 18; i++) {
					TAB[l][c] = 'C';
					break;
				}
			}
		} else {
			for (c = 2; c < 19; c += 4) {
				for (i = 17; i < 28; i++) {
					TAB[l][c] = 'C';
					break;
				}
			}
		}
	}

	TAB[12][0] = 'R';
	TAB[12][20] = 'F';
	TAB[10][2] = 'p';
	TAB[14][18] = 'f';
}