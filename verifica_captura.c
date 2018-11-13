#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// verifica se a captura e possivel
bool verifica_captura(char TAB[25][21], int j1, int k1, int j2, int k2) {
	int l, c;
	// se a "casa" de destino estiver ocupada retorna falso
	if (TAB[j2][k2] != ' ') {
		return false;
	}
	// calcula as coordenadas da peca que sera capturada
	if (j1 == j2) {
		l = j1;
		if (k1 > k2) {
			c = k1 - 4;
		} 
		if (k1 < k2) {
			c = k2 - 4;
		}
	} else if (k1 == k2) {
		c = k1;
		if (j1 > j2) {
			l = j1 - 4;
		} 
		if (j1 < j2) {
			l = j2 - 4;
		}
	} else if (j1 < j2 && k1 < k2) {
		l = j2 - 2;
		c = k2 - 2;
	} else if (j1 < j2 && k1 > k2) {
		l = j2 - 2;
		c = k1 - 2;
	} else if (j1 > j2 && k1 < k2) {
		l = j1 - 2;
		c = k2 - 2;
	} else if (j1 > j2 && k1 > k2) {
		l = j1 - 2;
		c = k1 - 2;
	}
	
	switch (TAB[j1][k1]) {
		// inicia as verificacoes para saber se a captura e possivel
		case 'R':
			// o rei pode capturar qualquer peca adversaria
			switch(TAB[l][c]) {
				case 'F': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				case 'f': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				case 'C': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				default: return false;
			}
		case 'p':
			// o princepe so captura o filho e os camponeses
			switch(TAB[l][c]) {
				case 'F': return false;
				case 'f': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				case 'C': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				default: return false;
			}
		case 'G':
			// os guerreiros so capturam os camponeses
			switch(TAB[l][c]) {
				case 'F': return false;
				case 'f': return false;
				case 'C': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				default: return false;
			}
		case 'F':
			// o fazendeiro pode capturar qualquer peca adversaria
			switch(TAB[l][c]) {
				case 'R': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				case 'p': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				case 'G': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				default: return false;
			}
		case 'f':
			// o filho so captura o princepe e os guerreiros
			switch(TAB[l][c]) {
				case 'R': return false;
				case 'p': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				case 'G': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				default: return false;
			}
		case 'C':
			// os camponeses so capturam os guerreiros
			switch(TAB[l][c]) {
				case 'R': return false;
				case 'p': return false;
				case 'G': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				default: return false;
			}
		default: return false;
		}
	}