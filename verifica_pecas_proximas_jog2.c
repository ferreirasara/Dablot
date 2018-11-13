#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool verifica_casa(int, int);

bool verifica_pecas_proximas_jog2(char TAB[25][21]) {
	int l, c, capturas_possiveis = 0, jogadas_possiveis = 0;
	for (l = 0; l < 25; l++) {
		for (c = 0; c < 21; c++) {
			if (TAB[l][c] == 'F' || TAB[l][c] == 'f' || TAB[l][c] == 'C') {
				// verifica possiveis jogadas normais e as contabiliza
				if (l % 4 == 0 && c % 4 == 0) {
					if (l - 4 >= 0) {
						if (TAB[l - 4][c] == ' '){
							jogadas_possiveis++;
						}
					}
					if (l + 4 <= 24) {
						if (TAB[l + 4][c] == ' '){
							jogadas_possiveis++;
						}
					}
					if (c - 4 >= 0) {
						if (TAB[l][c - 4] == ' '){
							jogadas_possiveis++;
						}
					}
					if (c + 4 <= 20) {
						if (TAB[l][c + 4] == ' '){
							jogadas_possiveis++;
						}
					}
					if (l - 2 >= 0 && c - 2 >= 0) {
						if (TAB[l - 2][c - 2] == ' '){
							jogadas_possiveis++;
						}
					}
					if (l - 2 >= 0 && c + 2 <= 20) {
						if (TAB[l - 2][c + 2] == ' '){
							jogadas_possiveis++;
						}
					}
					if (l + 2 <= 24 && c - 2 >= 0) {
						if (TAB[l + 2][c - 2] == ' '){
							jogadas_possiveis++;
						}
					}
					if (l + 2 <= 24 && c + 2 <= 20) {
						if (TAB[l + 2][c + 2] == ' '){
							jogadas_possiveis++;
						}
					}	
				} else {
					if (l - 2 >= 0 && c - 2 >= 0) {
						if (TAB[l - 2][c - 2] == ' '){
							jogadas_possiveis++;
						}
					}
					if (l - 2 >= 0 && c + 2 <= 20) {
						if (TAB[l - 2][c + 2] == ' '){
							jogadas_possiveis++;
						}
					}
					if (l + 2 <= 24 && c - 2 >= 0) {
						if (TAB[l + 2][c - 2] == ' '){
							jogadas_possiveis++;
						}
					}
					if (l + 2 <= 24 && c + 2 <= 20) {
						if (TAB[l + 2][c + 2] == ' '){
							jogadas_possiveis++;
						}
					}	
				}
				// verifica possiveis capturas e as contabiliza
				switch (TAB[l][c]) {
					case 'F':
						if (l % 4 == 0 && c % 4 == 0) {
							if (l - 8 >= 0) {
								switch (TAB[l - 8][c]) {
									case 'R': case 'p': case 'G': jogadas_possiveis++; break;
								}	
							}
							if (l + 8 <= 24) {
								switch (TAB[l + 8][c]) {
									case 'R': case 'p': case 'G': jogadas_possiveis++; break;
								}	
							}
							if (c - 8 >= 0) {
								switch (TAB[l][c - 8]) {
									case 'R': case 'p': case 'G': jogadas_possiveis++; break;
								}	
							}
							if (c + 8 <= 20) {
								switch (TAB[l][c + 8]) {
									case 'R': case 'p': case 'G': jogadas_possiveis++; break;
								}	
							}
							if (l - 4 >= 0 && c - 4 >= 0) {
								switch (TAB[l - 4][c - 4]) {
									case 'R': case 'p': case 'G': jogadas_possiveis++; break;
								}
							}
							if (l + 4 >= 24 && c - 4 >= 0) {
								switch (TAB[l + 4][c - 4]) {
									case 'R': case 'p': case 'G': jogadas_possiveis++; break;
								}
							}
							if (l - 4 >= 0 && c + 4 <= 20) {
								switch (TAB[l - 4][c + 4]) {
									case 'R': case 'p': case 'G': jogadas_possiveis++; break;
								}
							}
							if (l + 4 <= 24 && c + 4 <= 20) {
								switch (TAB[l + 4][c + 4]) {
									case 'R': case 'p': case 'G': jogadas_possiveis++; break;
								}
							}
						} else {
							if (l - 4 >= 0 && c - 4 >= 0) {
								switch (TAB[l - 4][c - 4]) {
									case 'R': case 'p': case 'G': jogadas_possiveis++; break;
								}
							}
							if (l + 4 >= 24 && c - 4 >= 0) {
								switch (TAB[l + 4][c - 4]) {
									case 'R': case 'P': case 'G': jogadas_possiveis++; break;
								}
							}
							if (l - 4 >= 0 && c + 4 <= 20) {
								switch (TAB[l - 4][c + 4]) {
									case 'R': case 'P': case 'G': jogadas_possiveis++; break;
								}
							}
							if (l + 4 <= 24 && c + 4 <= 20) {
								switch (TAB[l + 4][c + 4]) {
									case 'R': case 'P': case 'G': jogadas_possiveis++; break;
								}
							}
						}
						break;
					case 'f':
						if (l % 4 == 0 && c % 4 == 0) {
							if (l - 8 >= 0) {
									switch (TAB[l - 8][c]) {
										case 'p': case 'G': jogadas_possiveis++; break;
									}	
								}
								if (l + 8 <= 24) {
									switch (TAB[l + 8][c]) {
										case 'p': case 'G': jogadas_possiveis++; break;
									}	
								}
								if (c - 8 >= 0) {
									switch (TAB[l][c - 8]) {
										case 'p': case 'G': jogadas_possiveis++; break;
									}	
								}
								if (c + 8 <= 20) {
									switch (TAB[l][c + 8]) {
										case 'p': case 'G': jogadas_possiveis++; break;
									}	
								}
								if (l - 4 >= 0 && c - 4 >= 0) {
									switch (TAB[l - 4][c - 4]) {
										case 'p': case 'G': jogadas_possiveis++; break;
									}
								}
								if (l + 4 >= 24 && c - 4 >= 0) {
									switch (TAB[l + 4][c - 4]) {
										case 'p': case 'G': jogadas_possiveis++; break;
									}
								}
								if (l - 4 >= 0 && c + 4 <= 20) {
									switch (TAB[l - 4][c + 4]) {
										case 'p': case 'G': jogadas_possiveis++; break;
									}
								}
								if (l + 4 <= 24 && c + 4 <= 20) {
									switch (TAB[l + 4][c + 4]) {
										case 'p': case 'G': jogadas_possiveis++; break;
									}
								}
							} else {
								if (l - 4 >= 0 && c - 4 >= 0) {
									switch (TAB[l - 4][c - 4]) {
										case 'p': case 'G': jogadas_possiveis++; break;
									}
								}
								if (l + 4 >= 24 && c - 4 >= 0) {
									switch (TAB[l + 4][c - 4]) {
										case 'p': case 'G': jogadas_possiveis++; break;
									}
								}
								if (l - 4 >= 0 && c + 4 <= 20) {
									switch (TAB[l - 4][c + 4]) {
										case 'p': case 'G': jogadas_possiveis++; break;
									}
								}
								if (l + 4 <= 24 && c + 4 <= 20) {
									switch (TAB[l + 4][c + 4]) {
										case 'p': case 'G': jogadas_possiveis++; break;
									}
								}
							}
							break;
					case 'C':
						if (l % 4 == 0 && c % 4 == 0) {
							if (l - 8 >= 0) {
									switch (TAB[l - 8][c]) {
										case 'G': jogadas_possiveis++; break;
									}	
								}
								if (l + 8 <= 24) {
									switch (TAB[l + 8][c]) {
										case 'G': jogadas_possiveis++; break;
									}	
								}
								if (c - 8 >= 0) {
									switch (TAB[l][c - 8]) {
										case 'G': jogadas_possiveis++; break;
									}	
								}
								if (c + 8 <= 20) {
									switch (TAB[l][c + 8]) {
										case 'G': jogadas_possiveis++; break;
									}	
								}
								if (l - 4 >= 0 && c - 4 >= 0) {
									switch (TAB[l - 4][c - 4]) {
										case 'G': jogadas_possiveis++; break;
									}
								}
								if (l + 4 >= 24 && c - 4 >= 0) {
									switch (TAB[l + 4][c - 4]) {
										case 'G': jogadas_possiveis++; break;
									}
								}
								if (l - 4 >= 0 && c + 4 <= 20) {
									switch (TAB[l - 4][c + 4]) {
										case 'G': jogadas_possiveis++; break;
									}
								}
								if (l + 4 <= 24 && c + 4 <= 20) {
									switch (TAB[l + 4][c + 4]) {
										case 'G': jogadas_possiveis++; break;
									}
								}
							} else {
								if (l - 4 >= 0 && c - 4 >= 0) {
									switch (TAB[l - 4][c - 4]) {
										case 'G': jogadas_possiveis++; break;
									}
								}
								if (l + 4 >= 24 && c - 4 >= 0) {
									switch (TAB[l + 4][c - 4]) {
										case 'G': jogadas_possiveis++; break;
									}
								}
								if (l - 4 >= 0 && c + 4 <= 20) {
									switch (TAB[l - 4][c + 4]) {
										case 'G': jogadas_possiveis++; break;
									}
								}
								if (l + 4 <= 24 && c + 4 <= 20) {
									switch (TAB[l + 4][c + 4]) {
										case 'G': jogadas_possiveis++; break;
									}
								}
							}
							break;
				}
			}
		}
	}
	// se nao existir jogadas possiveis, retorna verdadeira, se existir, retorna falso
	if (jogadas_possiveis == 0 && capturas_possiveis == 0) {
		return true;
	} else {
		return false;
	}
}