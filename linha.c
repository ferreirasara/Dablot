#include <stdio.h>
#include <stdlib.h>

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

void linha() {
	int i;
	for (i = 0; i < 83; i++) {
		printf(C_YELLOW"═"NONE);
	}
	printf("\n");
}