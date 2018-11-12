#include <stdlib.h>
#include <stdio.h>

#define C_BLACK     "\033[30m"
#define C_RED       "\033[31m"
#define C_GREEN     "\033[32m"
#define C_YELLOW    "\033[33m"
#define C_BLUE      "\033[34m"
#define C_MAGENTA   "\033[35m"
#define C_CYAN      "\033[36m"
#define C_GRAY      "\033[37m"
#define NONE        "\033[0m"
#define BOLD        "\033[1m"
#define HALFBRIGHT  "\033[2m"
#define UNDERSCORE  "\033[4m"
#define BLINK       "\033[5m"
#define BG_YELLOW   "\033[43m"
#define BG_BLUE     "\033[1;44m"

void limpatela();
void linha();

int tela_fim_de_jogo(char jog[], int tipo) {
	int fim, i;
	limpatela();
	printf(C_YELLOW"                 __ _                 _          _                   _ \n");
	printf("                / _(_)               | |        (_)                 | |\n");
	printf("               | |_ _ _ __ ___     __| | ___     _  ___   __ _  ___ | |\n");
	printf("               |  _| | '_ ` _ \\   / _` |/ _ \\   | |/ _ \\ / _` |/ _ \\| |\n");
	printf("               | | | | | | | | | | (_| |  __/   | | (_) | (_| | (_) |_|\n");
	printf("               |_| |_|_| |_| |_|  \\__,_|\\___|   | |\\___/ \\__, |\\___/(_)\n");
	printf("                                               _/ |       __/ |        \n");
	printf("                                              |__/       |___/         \n"NONE);
	printf("\n");
	if (tipo == 0) {
		printf("\t\t\t Parabéns %s! Voce ganhou!", jog);
	} else if (tipo == 1) {
		printf("\t\t\t O jogo foi abandonado!");
	}
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
	printf(NONE C_YELLOW BOLD"2."NONE" Sair."NONE C_YELLOW"                    ║\n");
	printf("\t\t\t ╚");
	for (i = 0; i < 30; i++) {
		printf("═");
	}
	printf("╝\n" NONE);
	printf("\n");
	linha();
	printf("\tDigite sua escolha: ");
	scanf("%d", &fim);
	return fim;
}