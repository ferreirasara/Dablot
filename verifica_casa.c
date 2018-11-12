#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool verifica_casa(unsigned int l, unsigned int c) {
	// verifica se a peca esta na casa certa
	bool x = false, y = false;
	if (l % 4 == 0 && c % 4 == 0) {
			return true;
	} else {
		switch (l) {
			case 2: x = true; break;
			case 6: x = true; break;
			case 10: x = true; break;
			case 14: x = true; break;
			case 18: x = true; break;
			case 22: x = true; break;
		}
		switch (c) {
			case 2: y = true; break;
			case 6: y = true; break;
			case 10: y = true; break;
			case 14: y = true; break;
			case 18: y = true; break;
		}
		if (x && y) {
			return true;
		} else {
			return false;
		}
	}	
}