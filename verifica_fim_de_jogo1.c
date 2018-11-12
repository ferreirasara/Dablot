#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool verifica_fim_de_jogo1(char TAB[25][21]) {
	int l, c;
	int contador_jog1 = 0;
	for (l = 0; l < 25; l++) {
		for (c = 0; c < 21; c++) {
			switch (TAB[l][c]) {
				case 'R':
				case 'p':
				case 'G': contador_jog1++;
			}
		}
	}
	if (contador_jog1 == 0) {
		return true;
	} else {
		return false;
	}
}