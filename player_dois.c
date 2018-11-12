#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void linha();
void limpatela();
bool verifica_casa(int, int);
char converte_jogada_x(int);
char converte_jogada_y(char);
void faz_jogada(char [25][21], int, int, int, int);
bool verifica_jogada_normal(char [25][21], int, int, int, int);
bool verifica_captura(char [25][21], int, int, int, int);
void printtabuleiro(char [25][21]);
bool verifica_pecas_proximas_jog2(char [25][21]);

void player_dois(char TAB[25][21], char player2[]) {
	char coord_y1, coord_y2, ch; 
	int coord_x1, coord_x2;
	int jog_x1, jog_x2, jog_y1, jog_y2, i;
	bool verificacao_jog_norm, verificacao_captura;
	bool peca_certa;
	bool verificacao_casa1, verificacao_casa2; 

	
	do {	
		printtabuleiro(TAB);
		verifica_pecas_proximas_jog2(TAB);
		// solicita as coordenadas da primeira jogada
		linha();
		printf("\t%s, digite a primeira coordenada da posicao inicial: ", player2);
		scanf("%d", &coord_x1);
		jog_x1 = converte_jogada_x(coord_x1);
		
		printf("\tDigite a segunda coordenada da posicao inicial: ");
		scanf(" %c", &coord_y1);
		coord_y1 = toupper(coord_y1);
		jog_y1 = converte_jogada_y(coord_y1);
		// solicita as coordenadas da segunda jogada
		printf("\tDigite a primeira coordenada da posicao final: ");
		scanf("%d", &coord_x2);
		jog_x2 = converte_jogada_x(coord_x2);
		printf("\tDigite a segunda coordenada da posicao final: ");
		scanf(" %c", &coord_y2);
		coord_y2 = toupper(coord_y2);
		jog_y2 = converte_jogada_y(coord_y2);
		switch(TAB[jog_x1][jog_y1]) {
			case 'F':
			case 'f':
			case 'C': peca_certa = true; break;
			default: peca_certa = false;
		}
		// inicia a verificacao da jogada
		if (peca_certa) {
			verificacao_casa1 = verifica_casa(jog_x1, jog_y1);
			verificacao_casa2 = verifica_casa(jog_x2, jog_y2);
			if (!(verificacao_casa1 || verificacao_casa2)) {
				limpatela();
				linha();
				printf("\tAlguma coordenada esta errada. Tente novamente.\n");
				printf("\tPressione qualquer tecla para continuar.");
				scanf(" %c", &ch);
				break;
			} else {
				verificacao_jog_norm = verifica_jogada_normal(TAB, jog_x1, jog_y1, jog_x2, jog_y2);
				verificacao_captura = verifica_captura(TAB, jog_x1, jog_y1, jog_x2, jog_y2);
				if ((!(verificacao_captura)) && (!(verificacao_jog_norm))) {
					limpatela();
					linha();
					printf("\tJogada invalida. Tente novamente.\n");
					printf("\tPressione qualquer tecla para continuar.");
					scanf(" %c", &ch);
				}
			}
		} else {
			limpatela();
			linha();
			printf("\tOops, essa peca nao e sua. Tente novamente.\n");
			printf("\tPressione qualquer tecla para continuar.");
			scanf(" %c", &ch);
		}
		// se a jogada nao foi possivel, mostra uma mensagem de erro pro usuario
		
	} while ((!(verificacao_casa1 && verificacao_casa2 && peca_certa)) || (!(verificacao_jog_norm || verificacao_captura)));
}