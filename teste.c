#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

int jogo(char [25][21], char[], char[], int);
int sorteio();
int tela_inicio();
void carrega_jogo(char [25][21]);
void linha();
void limpatela();
void regras();
void tabuleiro_inicial(char [25][21]);

int main(void) {
	bool novo_game;
	char ch, jog1[50], jog2[50], tabuleiro[25][21];
	int l, c, i, p, escolha, fim, opcao, sorteio_result;
	
	// limpa o lixo de memoria da matriz
	for (l = 0; l < 27; l++) {
		for (c = 0; c < 23; c++) {
			tabuleiro[l][c] = ' ';
		}
	}
	// mostra a tela inicial
	do {
		escolha = tela_inicio();
		switch (escolha) {
			case 1: novo_game = true; break;
			case 2: regras(); break;
			case 3: carrega_jogo(tabuleiro); break;
			case 4: return EXIT_SUCCESS;
		}	
	} while (escolha != 1);
	// inicia um novo jogo
	if (novo_game) {
		for (i = 0; i < 100; i++) {
			printf("\n");
		}
		// zera o tabuleiro
		tabuleiro_inicial(tabuleiro);
		int sair;
		linha();
		// solicita os nomes dos jogadores
		printf("\tPlayer 1, voce jogara com o time dos guerreiros.\n");
		printf("\tDigite seu nome: ");
		scanf("%s", jog1);
		limpatela();
		linha();
		printf("\tPlayer 2, voce jogara com o time dos camponeses.\n");
		printf("\tDigite seu nome: ");
		scanf("%s", jog2);
		limpatela();
		linha();
		// informa que o sorteio sera realizado
		printf("\tVamos fazer um sorteio. Se der cara, os Sami comecam.\n");
		printf("\tSe der coroa, os Camponeses comecam.\n");
		for (int i=1; i<5; i++) {
			printf("\t.\n");
			sleep(1);
		}
		sorteio_result = sorteio();
		limpatela();
		linha();
		// informa qual jogador ira comecar
		if (sorteio_result == 0) {
			printf("\tOs Sami vao comecar. %s, pode comecar!\n", jog1);
		} else if (sorteio_result == 1) {
			printf("\tOs Camponeses vao comecar. %s, pode comecar!\n", jog2);
		}
		printf("\tLembre-se, para acessar o menu durante o jogo, digite 0.\n");
		printf("\tPressione qualquer tecla pra continuar: ");
		scanf(" %c", &ch);
		// chama a funcao do jogo
		jogo(tabuleiro, jog1, jog2, sorteio_result);
		
	printf("\tFim de jogo.\n");
	}
}