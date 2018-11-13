#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool verifica_fim_de_jogo1(char [25][21]);
bool verifica_fim_de_jogo2(char [25][21]);
bool verifica_pecas_proximas_jog1(char [25][21]);
bool verifica_pecas_proximas_jog2(char [25][21]);
int player_um(char [25][21], char[], char[], int);
int player_dois(char [25][21], char[], char[], int);
int peca_maior_perdida(char [25][21], char);
int tela_fim_de_jogo(char[], int);
void limpatela();
void linha();

int jogo(char TAB[25][21], char jog1[], char jog2[], int sorteio_result) {
	int fim, opcao, p;
	// quano o resultado do sorteio e 0, o jogador 1 comeca
	if (sorteio_result == 0) {
				do {
					do {
						// verifica se a peca mais importante foi capturada
						p = peca_maior_perdida(TAB, 'R');
						if (p == 1) {
							// mostra a tela de fim de jogo caso o jogador queira desistir
							fim = tela_fim_de_jogo(jog2, 1);
							if (fim == 1) {
								opcao = 3;
								break;
							} else if (fim == 2) {
								return EXIT_SUCCESS;
							}
							break;
						}
						opcao = player_um(TAB, jog1, jog2, sorteio_result);
						if (opcao == 4) {
							return EXIT_SUCCESS;
						} else if (opcao == 3) {
							break;
						}
						// faz a verificacao de fim de jogo
						if (verifica_pecas_proximas_jog1(TAB) || verifica_fim_de_jogo1(TAB)) {
							// mostra a tela de fim de jogo
							fim = tela_fim_de_jogo(jog2, 0);
							if (fim == 1) {
								opcao = 3;
								break;
							} else if (fim == 2) {
								return EXIT_SUCCESS;
							}
						}
						// faz a verificacao de fim de jogo
						if (verifica_pecas_proximas_jog2(TAB) || verifica_fim_de_jogo2(TAB)) {
							// mostra a tela de fim de jogo
							fim = tela_fim_de_jogo(jog1, 0);
							if (fim == 1) {
								opcao = 3;
								break;
							} else if (fim == 2) {
								return EXIT_SUCCESS;
							}
						}
						// verifica se a peca mais importante foi capturada
						p = peca_maior_perdida(TAB, 'F');
						if (p == 1) {
							// mostra a tela de fim de jogo caso o jogador queira desistir
							fim = tela_fim_de_jogo(jog2, 1);
							if (fim == 1) {
								opcao = 3;
								break;
							} else if (fim == 2) {
								return EXIT_SUCCESS;
							}
							break;
						}
						opcao = player_dois(TAB, jog1, jog2, sorteio_result);
						if (opcao == 4) {
							return EXIT_SUCCESS;
						} else if (opcao == 3) {
							break;
						}
						// faz a verificacao de fim de jogo
						if (verifica_pecas_proximas_jog1(TAB) || verifica_fim_de_jogo1(TAB)) {
							// mostra a tela de fim de jogo
							fim = tela_fim_de_jogo(jog2, 0);
							if (fim == 1) {
								opcao = 3;
								break;
							} else if (fim == 2) {
								return EXIT_SUCCESS;
							}
						}
						// faz a verificacao de fim de jogo
						if (verifica_pecas_proximas_jog2(TAB) || verifica_fim_de_jogo2(TAB)) {
							// mostra a tela de fim de jogo
							fim = tela_fim_de_jogo(jog1, 0);
							if (fim == 1) {
								opcao = 3;
								break;
							} else if (fim == 2) {
								return EXIT_SUCCESS;
							}
						}
					} while (opcao != 4);
				} while (fim != 2);
			// quano o resultado do sorteio e 1, o jogador 2 comeca
			} else if (sorteio_result == 1) {
				do {
					do {
						// verifica se a peca mais importante foi capturada
						p = peca_maior_perdida(TAB, 'F');
						if (p == 1) {
							// mostra a tela de fim de jogo caso o jogador queira desistir
							fim = tela_fim_de_jogo(jog2, 1);
							if (fim == 1) {
								opcao = 3;
								break;
							} else if (fim == 2) {
								return EXIT_SUCCESS;
							}
							break;
						}
						opcao = player_dois(TAB, jog1, jog2, sorteio_result);
						if (opcao == 4) {
							return EXIT_SUCCESS;
						} else if (opcao == 3) {
							break;
						}
						// faz a verificacao de fim de jogo
						if (verifica_pecas_proximas_jog1(TAB) || verifica_fim_de_jogo1(TAB)) {
							// mostra a tela de fim de jogo
							fim = tela_fim_de_jogo(jog2, 0);
							if (fim == 1) {
								opcao = 3;
								break;
							} else if (fim == 2) {
								return EXIT_SUCCESS;
							}
						}
						// faz a verificacao de fim de jogo
						if (verifica_pecas_proximas_jog2(TAB) || verifica_fim_de_jogo2(TAB)) {
							// mostra a tela de fim de jogo
							fim = tela_fim_de_jogo(jog1, 0);
							if (fim == 1) {
								opcao = 3;
								break;
							} else if (fim == 2) {
								return EXIT_SUCCESS;
							}
						}
						// verifica se a peca mais importante foi capturada
						p = peca_maior_perdida(TAB, 'R');
						if (p == 1) {
							// mostra a tela de fim de jogo caso o jogador queira desistir
							fim = tela_fim_de_jogo(jog2, 1);
							if (fim == 1) {
								opcao = 3;
								break;
							} else if (fim == 2) {
								return EXIT_SUCCESS;
							}
							break;
						}
						opcao = player_um(TAB, jog1, jog2, sorteio_result);
						if (opcao == 4) {
							return EXIT_SUCCESS;
						} else if (opcao == 3) {
							break;
						}
						// faz a verificacao de fim de jogo
						if (verifica_pecas_proximas_jog1(TAB) || verifica_fim_de_jogo1(TAB)) {
							// mostra a tela de fim de jogo
							fim = tela_fim_de_jogo(jog2, 0);
							if (fim == 1) {
								opcao = 3;
								break;
							} else if (fim == 2) {
								return EXIT_SUCCESS;
							}
						}
						// faz a verificacao de fim de jogo
						if (verifica_pecas_proximas_jog2(TAB) || verifica_fim_de_jogo2(TAB)) {
							// mostra a tela de fim de jogo
							fim = tela_fim_de_jogo(jog1, 0);
							if (fim == 1) {
								opcao = 3;
								break;
							} else if (fim == 2) {
								return EXIT_SUCCESS;
							}
						}
					} while (opcao != 4);
				} while (fim != 2);
			}	
}