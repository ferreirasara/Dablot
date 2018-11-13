#include <stdlib.h>
#include <stdio.h>

// definicoes das cores e efeitos
#define C_YELLOW    "\033[33m"
#define NONE        "\033[0m"
#define BOLD        "\033[1m"

void limpatela();
void linha();

int menu_jogo() {
	int a, i;
	limpatela();
	printf(C_YELLOW "\t\t\t ╔");
	
	for (i = 0; i < 30; i++) {
		printf("═");
	}
	printf("╗\n");
	printf("\t\t\t ║  ");
	printf(NONE C_YELLOW BOLD"1."NONE" Continuar."NONE C_YELLOW"               ║\n");
	printf("\t\t\t ║  ");
	printf(NONE C_YELLOW BOLD"2."NONE" Salvar."NONE C_YELLOW"                  ║\n");
	printf("\t\t\t ║  ");
	printf(NONE C_YELLOW BOLD"3."NONE" Reiniciar."NONE C_YELLOW"               ║\n");
	printf("\t\t\t ║  ");
	printf(NONE C_YELLOW BOLD"4."NONE" Sair para o menu."NONE C_YELLOW"        ║\n");
	printf("\t\t\t ╚");
	for (i = 0; i < 30; i++) {
		printf("═");
	}
	printf("╝\n" NONE);
	for (i = 0; i < 13; i++) {
		printf("\n");
	}
	linha();
	printf("\tDigite sua escolha: ");
	scanf("%d", &a);
	return a;
}