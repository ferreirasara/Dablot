#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


bool verifica_captura(char [25][21], int, int, int, int);
bool verifica_casa(int, int);
bool verifica_jogada_normal(char [25][21], int, int, int, int);
bool verifica_pecas_proximas_jog2(char [25][21]);
char converte_jogada_x(int);
char converte_jogada_y(char);
void linha();
void limpatela();
int menu_jogo();
void printtabuleiro(char [25][21]);
void salva_jogo(char [25][21], char[], char[], int);
void tabuleiro_inicial(char [25][21]);


int player_dois(char TAB[25][21], char player1[], char player2[], int sorteio_result) {
	bool peca_certa, verificacao_casa1, verificacao_casa2, verificacao_captura, verificacao_jog_norm; 
	char ch, coord_y1, coord_y2; 
	int coord_x1, coord_x2, opcao;
	int jog_x1, jog_x2, jog_y1, jog_y2, i;
	
	// inicia o laço para solicitar a jogada
	do {
		// verifica existem jogadas possiveis
		verifica_pecas_proximas_jog2(TAB);
		// solicita as coordenadas da primeira jogada
		do {
			printtabuleiro(TAB);
			linha();
			printf("\t%s, digite a primeira coordenada da posicao inicial: ", player2);
			scanf("%d", &coord_x1);
			// faz a conversao para os indices da matriz
			jog_x1 = converte_jogada_x(coord_x1);
			// verifica se o jogador quer entrar no menu
			if (jog_x1 == 99) {
				// abre o menu
				opcao = menu_jogo();
				if (opcao == 2) {
					salva_jogo(TAB, player1, player2, sorteio_result);
				} else if (opcao == 4) {
					// sai da funcao
					return opcao;
				} else if (opcao == 3) {
					// reinicia o tabuleiro, com os mesmos jogadores
					tabuleiro_inicial(TAB);
					return opcao;
				}
			} else {
				break;
			}
		} while (opcao == 1);
		// repete, mas para as outras coordenadas
		do {
			printtabuleiro(TAB);
			linha();
			printf("\tDigite a segunda coordenada da posicao inicial: ");
			scanf(" %c", &coord_y1);
			coord_y1 = toupper(coord_y1);
			jog_y1 = converte_jogada_y(coord_y1);
			if (jog_y1 == 99) {
				opcao = menu_jogo();
				if (opcao == 2) {
					salva_jogo(TAB, player1, player2, sorteio_result);
				} else if (opcao == 4) {
					return opcao;
				} else if (opcao == 3) {
					tabuleiro_inicial(TAB);
					return opcao;
				}
			} else {
				break;
			}
		} while (opcao == 1);
		// solicita as coordenadas da segunda jogada
		do {
			printtabuleiro(TAB);
			linha();
			printf("\tDigite a primeira coordenada da posicao final: ");
			scanf("%d", &coord_x2);
			jog_x2 = converte_jogada_x(coord_x2);
			if (jog_x2 == 99) {
				opcao = menu_jogo();
				if (opcao == 2) {
					salva_jogo(TAB, player1, player2, sorteio_result);
				} else if (opcao == 4) {
					return opcao;
				} else if (opcao == 3) {
					tabuleiro_inicial(TAB);
					return opcao;
				}
			} else {
				break;
			}
		} while (opcao == 1);
		do {
			printtabuleiro(TAB);
			linha();
			printf("\tDigite a segunda coordenada da posicao final: ");
			scanf(" %c", &coord_y2);
			coord_y2 = toupper(coord_y2);
			jog_y2 = converte_jogada_y(coord_y2);
			if (jog_y2 == 99) {
				opcao = menu_jogo();
				if (opcao == 2) {
					salva_jogo(TAB, player1, player2, sorteio_result);
				} else if (opcao == 4) {
					return opcao;
				} else if (opcao == 3) {
					tabuleiro_inicial(TAB);
					return opcao;
				}
			} else {
				break;
			}
		} while (opcao == 1);
		// verifica se o jogador selecionou uma peca valida
		switch(TAB[jog_x1][jog_y1]) {
			case 'F':
			case 'f':
			case 'C': peca_certa = true; break;
			default: peca_certa = false;
		}
		// inicia a verificacao da jogada
		if (peca_certa) {
			// verifica se as coordenadas correspondem a uma "casa" valida
			verificacao_casa1 = verifica_casa(jog_x1, jog_y1);
			verificacao_casa2 = verifica_casa(jog_x2, jog_y2);
			if (!(verificacao_casa1 || verificacao_casa2)) {
				// caso uma das "casas" nao seja valida, informa o erro e volta ao inicio do laco
				limpatela();
				linha();
				printf("\tAlguma coordenada esta errada. Tente novamente.\n");
				printf("\tPressione qualquer tecla para continuar.");
				scanf(" %c", &ch);
				break;
			} else {
				// verifica se a jogada e valida
				verificacao_jog_norm = verifica_jogada_normal(TAB, jog_x1, jog_y1, jog_x2, jog_y2);
				verificacao_captura = verifica_captura(TAB, jog_x1, jog_y1, jog_x2, jog_y2);
				if ((!(verificacao_captura)) && (!(verificacao_jog_norm))) {
					// caso a jogada nao seja valida, informa o erro e volta ao inicio do laco
					limpatela();
					linha();
					printf("\tJogada invalida. Tente novamente.\n");
					printf("\tPressione qualquer tecla para continuar.");
					scanf(" %c", &ch);
				}
			}
		} else {
			// caso a peca nao seja valida, informa o erro e volta ao inicio do laco
			limpatela();
			linha();
			printf("\tOops, essa peca nao e sua. Tente novamente.\n");
			printf("\tPressione qualquer tecla para continuar.");
			scanf(" %c", &ch);
		}
	// repete o laco ate todas as condicoes serem validas
	} while ((!(verificacao_casa1 && verificacao_casa2 && peca_certa)) || (!(verificacao_jog_norm || verificacao_captura)));
}