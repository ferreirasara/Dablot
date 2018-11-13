#include <stdio.h>
#include <stdlib.h>

// definicoes das cores e efeitos
#define C_RED       "\033[31m"
#define C_GREEN     "\033[32m"
#define C_YELLOW    "\033[33m"
#define NONE        "\033[0m"
#define BOLD        "\033[1m"

void imprime_coordenadas(int);

void printtabuleiro(char TAB[25][21]) {
	int l, c, i;
	// desenha as linhas do tabuleiro
	for (l = 0; l < 25; l += 4) {
		for (c = 0; c < 21; c++) {
			if (c == 0 || (c % 4) == 0) {
//				TAB[l][c] = ' ';
			} else {
				TAB[l][c] = '-';
			}
		}
	}
	for (l = 1; l < 25; l += 4) {
		for (c = 0; c < 21; c += 4) {
			TAB[l][c] = '|';
		}
		for (c = 1; c < 21; c += 4) {
			TAB[l][c] = '\\';
		}
		for (c = 3; c < 21; c += 4) {
			TAB[l][c] = '/';
		}
	}
	for (l = 2; l < 25; l += 4) {
		for (c = 0; c < 21; c += 4) {
			TAB[l][c] = '|';
		}
	}
	for (l = 3; l < 25; l += 4) {
		for (c = 0; c < 21; c += 4) {
			TAB[l][c] = '|';
		}
		for (c = 1; c < 21; c += 4) {
			TAB[l][c] = '/';
		}
		for (c = 3; c < 21; c += 4) {
			TAB[l][c] = '\\';
		}
	}
	// imprime o tabuleiro
	for (i = 0; i < 10; i++) {
		printf("\n");
	}
	printf("\t\t╔");
	
	for (i = 0; i < 50; i++) {
		printf("═");
	}
	printf("╗\n");
	// imprime as coordenadas de x
	printf("\t\t║    A   B   C   D   E   F   G   H   I   J   K     ║\n");
	printf("\t\t║ ");
	for (l = 0; l < 25; l++) {
		// imprime as coordenadas de y
		imprime_coordenadas(l);
		// imprime as pecas, com cores diferentes
		for (c = 0; c < 21; c++) {
			if (TAB[l][c] == 'G' || TAB[l][c] == 'p' || TAB[l][c] == 'R') {
				printf(C_RED BOLD "%c "NONE, TAB[l][c]);
			} else if (TAB[l][c] == 'C' || TAB[l][c] == 'f' || TAB[l][c] == 'F') {
				printf(C_GREEN BOLD "%c "NONE, TAB[l][c]);
			} else {
				printf( "%c " NONE, TAB[l][c]);
			}
		}
		imprime_coordenadas(l);
		printf(" ║\n");
		if (l < 24) {
			printf("\t\t║ ");
		}
	}
	printf("\t\t║    A   B   C   D   E   F   G   H   I   J   K     ║\n");
	printf("\t\t╚");
	
	for (i = 0; i < 50; i++) {
		printf("═");
	}
	printf("╝\n");
}
void imprime_coordenadas(int l) {
	switch (l) {
		case 0: printf("1  "); break;
		case 1: printf("   "); break;
		case 2: printf("2  "); break;
		case 3: printf("   "); break;
		case 4: printf("3  "); break;
		case 5: printf("   "); break;
		case 6: printf("4  "); break;
		case 7: printf("   "); break;
		case 8: printf("5  "); break;
		case 9: printf("   "); break;
		case 10: printf("6  "); break;
		case 11: printf("   "); break;
		case 12: printf("7  "); break;
		case 13: printf("   "); break;
		case 14: printf("8  "); break;
		case 15: printf("   "); break;
		case 16: printf("9  "); break;
		case 17: printf("   "); break;
		case 18: printf("10 "); break;
		case 19: printf("   "); break;
		case 20: printf("11 "); break;
		case 21: printf("   "); break;
		case 22: printf("12 "); break;
		case 23: printf("   "); break;
		case 24: printf("13 "); break;
	}
}