#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool verifica_casa_preenchida(char [25][21], int, int);
bool verifica_proximidade(char [25][21], int, int, int, int);

// retorna verdadeiro se as condicoes das duas funcoes forem verdadeiras
bool verifica_jogada_normal(char TAB[25][21], int j1, int k1, int j2, int k2) {
	if (verifica_proximidade(TAB, j1, k1, j2, k2) && verifica_casa_preenchida(TAB, j2, k2)) {
		TAB[j2][k2] = TAB[j1][k1];
		TAB[j1][k1] = ' ';
		return true;
	} else {
		return false;
	}
}
// verifica se a casa de destino ja contém uma peça
bool verifica_casa_preenchida(char TAB[25][21], int j2, int k2) {
	if (TAB[j2][k2] == ' ') {
		return true;
	} else {
		return false;
	}
}
// verifica se a jogada sera em uma casa adjacente
bool verifica_proximidade(char TAB[25][21], int j1, int k1, int j2, int k2) {
	int l, c;
	if (j1 % 4 == 0 && k1 % 4 == 0) {
		if ((j2 == j1 - 2 && k2 == k1 - 2) || ((j2 == j1 + 2 && k2 == k1 - 2))) {
			return true;
		} else if ((j2 == j1 - 2 && k2 == k1 + 2) || ((j2 == j1 + 2 && k2 == k1 + 2))) {
			return true;
		} else if ((j2 == j1 && k2 == k1 - 4) || (j2 == j1 && k2 == k1 + 4)) {
			return true;
		} else if ((k2 == k1 && j2 == j1 - 4) || (k2 == k1 && j2 == j1 + 4)) {
			return true;
		} else {
			return false;
		}
	} else if (j2 == j1 - 2 && k2 == k1 - 2) {
		return true;
	} else if (j2 == j1 + 2 && k2 == k1 - 2) {
		return true;
	} else if (j2 == j1 - 2 && k2 == k1 + 2) {
		return true;
	} else if (j2 == j1 + 2 && k2 == k1 + 2) {
		return true;
	} else {
		return false;
	}
}