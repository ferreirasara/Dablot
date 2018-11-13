#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// conta as pecas do jogador 2, se nao houver nenhuma, o jogo acabou
bool verifica_fim_de_jogo2(char TAB[25][21]) {
	int l, c;
	int contador_jog2 = 0;
	for (l = 0; l < 25; l++) {
		for (c = 0; c < 21; c++) {
			switch (TAB[l][c]) {
				case 'F':
				case 'f':
				case 'C': contador_jog2++;
			}
		}
	}
	if (contador_jog2 == 0) {
		return true;
	} else {
		return false;
	}
}