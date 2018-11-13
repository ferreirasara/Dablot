#include <stdio.h>
#include <stdlib.h>

// definicoes das cores e efeitos
#define C_YELLOW    "\033[33m"
#define NONE        "\033[0m"


int pag1();
int pag2();
void limpatela();
void linha();

void regras() {
	int a1, a2;
	do {
		a1 = pag1();
		if (a1 == 1) {
			a2 = pag2();
		}
	} while (a1 != 2 || a1 != 2);
}
// primeira pagina das regras
int pag1() {
	int a;
	int i;
	limpatela();
	printf(C_YELLOW"                   _____  ______ _____ _____             _____ \n");
	printf("                  |  __ \\|  ____/ ____|  __ \\     /\\    / ____|\n");
	printf("                  | |__) | |__ | |  __| |__) |   /  \\  | (___  \n");
	printf("                  |  _  /|  __|| | |_ |  _  /   / /\\ \\  \\___ \\ \n");
	printf("                  | | \\ \\| |___| |__| | | \\ \\  / ____ \\ ____) |\n");
	printf("                  |_|  \\_\\______\\_____|_|  \\_\\/_/    \\_\\_____/ \n"NONE);
	printf("\n");
	printf(C_YELLOW "\t ╔");
	for (i = 0; i < 60; i++) {
		printf("═");
	}
	printf("╗\n");
	printf("\t ║  "NONE"\tDablot é um jogo de tabuleiro, parecido com o jogo de "C_YELLOW"║\n");
	printf("\t ║  "NONE"Damas. E originario da Lapônia, e representa uma disputa  "C_YELLOW"║\n");
	printf("\t ║  "NONE"entre um povo nomade denominado Sami, e os fazendeiros    "C_YELLOW"║\n");
	printf("\t ║  "NONE"donos de terras.                                          "C_YELLOW"║\n");
	printf("\t ║  "NONE"\tNeste jogos temos 30 pecas para cada jogador. O lado  "C_YELLOW"║\n");
	printf("\t ║  "NONE"dos Sami tem um rei, um princepe, e 28 guerreiros. O lado "C_YELLOW"║\n");
	printf("\t ║  "NONE"dos fazendeiros tem um fazendeiro, um filho do fazendeiro,"C_YELLOW"║\n");
	printf("\t ║  "NONE"e 28 camponeses.                                          "C_YELLOW"║\n");
	printf("\t ║  "NONE"\tAs regras do Dablot sao bem simples, as pecas andam   "C_YELLOW"║\n");
	printf("\t ║  "NONE"pelas casas seguindo as linhas do tabuleiro, e pulam umas "C_YELLOW"║\n");
	printf("\t ║  "NONE"sobre as outras para fazer a captura. Mas existe uma      "C_YELLOW"║\n");
	printf("\t ║  "NONE"entre as peças. Os guerreiros so podem capturar os        "C_YELLOW"║\n");
	printf("\t ║  "NONE"fazendeiros, e vice versa. O princepe so pode capturar o  "C_YELLOW"║\n");
	printf("\t ║  "NONE"filho do fazendeiro e os camponeses, e o mesmo para o     "C_YELLOW"║\n");
	printf("\t ║  "NONE"filho do fazendeiro. Ja o rei e o fazendeiro, podem       "C_YELLOW"║\n");
	printf("\t ║  "NONE"capturar um ao outro e qualquer uma das outras pecas. Nao "C_YELLOW"║\n");
	printf("\t ║  "NONE"existe promocao de hierarquia e pecas capturadas nao      "C_YELLOW"║\n");
	printf("\t ║  "NONE"voltam ao jogo.                                           "C_YELLOW"║\n");
	printf("\t ╚");
	for (i = 0; i < 60; i++) {
		printf("═");
	}
	printf("╝\n" NONE);
	printf(C_YELLOW "\t ╔");
	for (i = 0; i < 60; i++) {
		printf("═");
	}
	printf("╗\n");
	printf("\t ║"NONE" 1. Proxima pagina.                   2. Voltar para o menu."C_YELLOW"║\n");
	printf("\t ╚");
	for (i = 0; i < 60; i++) {
		printf("═");
	}
	printf("╝\n" NONE);
	printf("\n");
	linha();
	printf("\tDigite sua escolha: ");
	scanf("%d", &a);
	return a;
}
// segunda pagina das regras
int pag2() {
	int a, i;
	limpatela();
	printf(C_YELLOW"                   _____  ______ _____ _____             _____ \n");
	printf("                  |  __ \\|  ____/ ____|  __ \\     /\\    / ____|\n");
	printf("                  | |__) | |__ | |  __| |__) |   /  \\  | (___  \n");
	printf("                  |  _  /|  __|| | |_ |  _  /   / /\\ \\  \\___ \\ \n");
	printf("                  | | \\ \\| |___| |__| | | \\ \\  / ____ \\ ____) |\n");
	printf("                  |_|  \\_\\______\\_____|_|  \\_\\/_/    \\_\\_____/ \n"NONE);
	for (i = 0; i < 5; i++) {
		printf("\n");
	}
	printf(C_YELLOW "\t ╔");
	for (i = 0; i < 60; i++) {
		printf("═");
	}
	printf("╗\n");
	printf("\t ║  "NONE"\tAs \"casas\" do jogo ficam nas interseccoes das linhas  "C_YELLOW"║\n");
	printf("\t ║  "NONE"do tabuleiro. Cada peca pode se mover para uma interseccao"C_YELLOW"║\n");
	printf("\t ║  "NONE"adjacente que esteja livre. Uma captura so e possivel se a"C_YELLOW"║\n");
	printf("\t ║  "NONE"peca a ser capturada esteja em uma casa adjacente, e a    "C_YELLOW"║\n");
	printf("\t ║  "NONE"casa atras dela esteja livre.                             "C_YELLOW"║\n");
	printf("\t ║  "NONE"\tVence quem capturar todas as pecas do adversario, ou  "C_YELLOW"║\n");
	printf("\t ║  "NONE"se o adversario ficar sem movimentos possiveis.           "C_YELLOW"║\n");
	printf("\t ║  "NONE"\tDurante o jogo, cada jogador deve digitar as          "C_YELLOW"║\n");
	printf("\t ║  "NONE"coordenadas da posicao inicial da peca, e as coordenadas  "C_YELLOW"║\n");
	printf("\t ║  "NONE"da posicao final. As coordenadas sao formadas por um      "C_YELLOW"║\n");
	printf("\t ║  "NONE"numero (eixo X) e uma letra (eixo Y).                     "C_YELLOW"║\n");
	printf("\t ╚");
	for (i = 0; i < 60; i++) {
		printf("═");
	}
	printf("╝\n" NONE);
	printf(C_YELLOW "\t ╔");
	for (i = 0; i < 60; i++) {
		printf("═");
	}
	printf("╗\n");
	printf("\t ║"NONE" 1. Pagina anterior.                  2. Voltar para o menu."C_YELLOW"║\n");
	printf("\t ╚");
	for (i = 0; i < 60; i++) {
		printf("═");
	}
	printf("╝\n" NONE);
	printf("\n");
	linha();
	printf("\tDigite sua escolha: ");
	scanf("%d", &a);
	return a;
}