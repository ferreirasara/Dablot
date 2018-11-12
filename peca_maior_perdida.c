#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void linha();
void limpatela();

int peca_maior_perdida(char TAB[25][21], char peca) {
	int l, c, escolha, i = 0;
	bool perda = false;

	for (l = 0; l < 25; l++) {
		for (c = 0; c < 21; c++) {
			if (TAB[l][c] == peca) {
				i++;
				break;
			}
		}
	}
	if (i == 0) {
		perda = true;
	}
	if (perda) {
		limpatela();
		linha();
		printf("\tVoce perdeu sua peca principal.\n");
		printf("\tDeseja desistir? 1 para sim e 2 para não: ");
		scanf("%d", &escolha);
	} else {
		escolha = 0;
	}
	return escolha;
}