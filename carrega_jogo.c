#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int jogo(char [25][21], char[], char[], int);
void linha();
void limpatela();

void carrega_jogo(char TAB [25][21]) {
    int l, c, i;
    char ch, descarte, jog1[50], jog2[50], nome[50];

    limpatela();
    linha();
    printf("\tDigite o nome do arquivo que contem o jogo: ");
    scanf("%s", nome);
    // abre o arquivo que contem o jogo salvo
    FILE* jogo_salvo = fopen(nome, "r");
    
    for (l = 0; l < 25; l++) {
        for (c = 0; c < 21; c++) {
            // le um caractere do arquivo
            ch = fgetc(jogo_salvo);
            // se o arquivo nao for uma quebra de linha, o caractere vai para a matriz do tabuleiro
            if (ch != '\n') {
                TAB[l][c] = ch;
            } else {
                descarte = ch;
            }
        }
    }
    descarte = fgetc(jogo_salvo);
    // le os nomes dos jogadores
    fgets(jog1, sizeof(jog1), jogo_salvo);
    // remove a quebra de linha da string
    for (l = 0; l < strlen(jog1); l++) {
        if (jog1[l] == '\n') {
            jog1[l] = jog1[l + 1];
        }
    }
    fgets(jog2, sizeof(jog2), jogo_salvo);
    // remove a quebra de linha da string
    for (l = 0; l < strlen(jog2); l++) {
        if (jog2[l] == '\n') {
            jog2[l] = jog2[l + 1];
        }
    }
    // le o inteiro que informa quem tava na vez de jogar
    fscanf(jogo_salvo, "%d", &i);
    // fecha o arquivo
    fclose(jogo_salvo);
    // inicia o jogo com as informacoes lidas
    jogo(TAB, jog1, jog2, i);
}