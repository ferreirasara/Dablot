#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// converte as jogadas para os indices da matriz
char converte_jogada_x(int Y) {
	int y;
	switch (Y) {
		// se o jogador digitar 0, retorna 99 para abrir o menu
		case 0: y = 99; break;
		case 1: y = 0; break;
		case 2: y = 2; break;
		case 3: y = 4; break;
		case 4: y = 6; break;
		case 5: y = 8; break;
		case 6: y = 10; break;
		case 7: y = 12; break;
		case 8: y = 14; break;
		case 9: y = 16; break;
		case 10: y = 18; break;
		case 11: y = 20; break;
		case 12: y = 22; break;
		case 13: y = 24; break;
	}
	return y;
}