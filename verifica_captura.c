#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool verifica_captura(char TAB[25][21], int j1, int k1, int j2, int k2) {
	int l, c;
	if (TAB[j2][k2] != ' ') {
		return false;
	}
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
		case 'R': 
			switch(TAB[l][c]) {
				case 'F': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				case 'f': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				case 'C': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				default: return false;
			}
		case 'p':
			switch(TAB[l][c]) {
				case 'F': return false;
				case 'f': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				case 'C': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				default: return false;
			}
		case 'G':
			switch(TAB[l][c]) {
				case 'F': return false;
				case 'f': return false;
				case 'C': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				default: return false;
			}
		case 'F': 
			switch(TAB[l][c]) {
				case 'R': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				case 'p': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				case 'G': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				default: return false;
			}
		case 'f':
			switch(TAB[l][c]) {
				case 'R': return false;
				case 'p': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				case 'G': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				default: return false;
			}
		case 'C':
			switch(TAB[l][c]) {
				case 'R': return false;
				case 'p': return false;
				case 'G': TAB[l][c] = ' '; TAB[j2][k2] = TAB[j1][k1]; TAB[j1][k1] = ' '; return true;
				default: return false;
			}
		default: return false;
		}
	}


