#include <stdio.h>
#include <stdlib.h>

// definicoes das cores e efeitos
#define C_YELLOW    "\033[33m"
#define NONE        "\033[0m"

// insere uma linha pra servir de divisoria
void linha() {
	int i;
	for (i = 0; i < 83; i++) {
		printf(C_YELLOW"═"NONE);
	}
	printf("\n");
}