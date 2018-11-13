#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool verifica_casa(int, int);
void linha();
void limpatela();

void salva_jogo(char TAB [25][21], char nome1[], char nome2[], int sort) {
	char nome_arquivo[50], ch;
	int l, c;
	// solicita um nome
	printf("Digite o nome para o arquivo (sem espacos): ");
	scanf("%s", nome_arquivo);
	// cria um arquivo com o nome que o usuario digitou
	FILE* arquivo = fopen(nome_arquivo, "w");
	// verifica se o arquivo foi criado
	if (arquivo == 0) {
		perror("Não foi possivel criar o arquivo.");
		fclose(arquivo);
	} else {
		puts("Arquivo criado com sucesso!");
	}
	// escreve a matriz no arquivo
	for (l = 0; l < 25; ++l) {
		for (c = 0; c < 21; c++) {
				fprintf(arquivo, "%c", TAB[l][c]);
		}
	}
	fprintf(arquivo, "\n");
	// escreve os nomes dos jogadores no arquivo
	fprintf(arquivo, "%s\n%s\n", nome1, nome2);
	// escreve o inteiro que mostra de quem e a vez de jogar
	fprintf(arquivo, "%d", sort);
	// fecha o arquivo
	fclose(arquivo);
	limpatela();
	linha();
	// informa que o arquivo foi criado com sucesso
	puts("\tJogo Salvo!");
	printf("\tPressione qualquer tecla pra continuar: ");
	scanf(" %c", &ch);
}