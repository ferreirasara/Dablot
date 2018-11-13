#include <stdio.h>
#include <stdlib.h>

// definicoes das cores e efeitos
#define C_YELLOW    "\033[33m"
#define NONE        "\033[0m"
#define BOLD        "\033[1m"
#define HALFBRIGHT  "\033[2m"
#define BLINK       "\033[5m"
#define BG_YELLOW   "\033[43m"


void linha();
void limpatela();

int tela_inicio() {
	int escolha, i;
	limpatela();
	// arte com ASCII :)
	printf(BG_YELLOW BOLD"                  ______   _______  _______  ___      _______  _______               \n");
	printf("                 |      | |   _   ||  _    ||   |    |       ||       |\n");
	printf("                 |  _    ||  |_|  || |_|   ||   |    |   _   ||_     _|\n");
	printf("                 | | |   ||       ||       ||   |    |  | |  |  |   |  \n");
	printf("                 | |_|   ||       ||  _   | |   |___ |  |_|  |  |   |  \n");
	printf("                 |       ||   _   || |_|   ||       ||       |  |   |  \n");
	printf("                 |______| |__| |__||_______||_______||_______|  |___|  \n");
	printf("\n");
	printf("                                    "BLINK"INSERT COIN"NONE BG_YELLOW"                                    \n" NONE);
	for (i = 0; i < 10; i++) {
		printf("\n");
	}
	
	printf(C_YELLOW "\t\t\t ╔");
	for (i = 0; i < 30; i++) {
		printf("═");
	}
	printf("╗\n");
	printf("\t\t\t ║  ");
	printf(NONE C_YELLOW BOLD"1."NONE" Iniciar um novo jogo."NONE C_YELLOW"    ║\n");
	printf("\t\t\t ║  ");
	printf(NONE C_YELLOW BOLD"2."NONE" Ler as regras."NONE C_YELLOW"           ║\n");
	printf("\t\t\t ║  ");
	printf(NONE C_YELLOW BOLD"3."NONE" Retomar um jogo salvo."NONE C_YELLOW"   ║\n");
	printf("\t\t\t ║  ");
	printf(NONE C_YELLOW BOLD"4."NONE" Sair."NONE C_YELLOW"                    ║\n");
	printf("\t\t\t ╚");
	for (i = 0; i < 30; i++) {
		printf("═");
	}
	printf("╝\n" NONE);
	printf("\n");
	linha();
	printf("\tDigite sua escolha: ");
	scanf("%d", &escolha);
	return escolha;
}