#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool verifica_pecas_proximas_jog1(char TAB[25][21]) {
	int l, c, jogadas_possiveis = 0, capturas_possiveis = 0;
	// sem contar as pecas dos cantos
	for (l = 0; l < 25; l++) {
		for (c = 0; c < 21; c++) {
			if (TAB[l][c] == 'R' || TAB[l][c] == 'p' || TAB[l][c] == 'G') {
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
					case 'R':
						if (l % 4 == 0 && c % 4 == 0) {
							if (l - 8 >= 0) {
								switch (TAB[l - 8][c]) {
									case 'F': case 'f': case 'C': jogadas_possiveis++; break;
								}	
							}
							if (l + 8 <= 24) {
								switch (TAB[l + 8][c]) {
									case 'F': case 'f': case 'C': jogadas_possiveis++; break;
								}	
							}
							if (c - 8 >= 0) {
								switch (TAB[l][c - 8]) {
									case 'F': case 'f': case 'C': jogadas_possiveis++; break;
								}	
							}
							if (c + 8 <= 20) {
								switch (TAB[l][c + 8]) {
									case 'F': case 'f': case 'C': jogadas_possiveis++; break;
								}	
							}
							if (l - 4 >= 0 && c - 4 >= 0) {
								switch (TAB[l - 4][c - 4]) {
									case 'F': case 'f': case 'C': jogadas_possiveis++; break;
								}
							}
							if (l + 4 >= 24 && c - 4 >= 0) {
								switch (TAB[l + 4][c - 4]) {
									case 'F': case 'f': case 'C': jogadas_possiveis++; break;
								}
							}
							if (l - 4 >= 0 && c + 4 <= 20) {
								switch (TAB[l - 4][c + 4]) {
									case 'F': case 'f': case 'C': jogadas_possiveis++; break;
								}
							}
							if (l + 4 <= 24 && c + 4 <= 20) {
								switch (TAB[l + 4][c + 4]) {
									case 'F': case 'f': case 'C': jogadas_possiveis++; break;
								}
							}
						} else {
							if (l - 4 >= 0 && c - 4 >= 0) {
								switch (TAB[l - 4][c - 4]) {
									case 'F': case 'f': case 'C': jogadas_possiveis++; break;
								}
							}
							if (l + 4 >= 24 && c - 4 >= 0) {
								switch (TAB[l + 4][c - 4]) {
									case 'F': case 'f': case 'C': jogadas_possiveis++; break;
								}
							}
							if (l - 4 >= 0 && c + 4 <= 20) {
								switch (TAB[l - 4][c + 4]) {
									case 'F': case 'f': case 'C': jogadas_possiveis++; break;
								}
							}
							if (l + 4 <= 24 && c + 4 <= 20) {
								switch (TAB[l + 4][c + 4]) {
									case 'F': case 'f': case 'C': jogadas_possiveis++; break;
								}
							}
						}
						break;
					case 'p':
						if (l % 4 == 0 && c % 4 == 0) {
							if (l - 8 >= 0) {
									switch (TAB[l - 8][c]) {
										case 'f': case 'C': jogadas_possiveis++; break;
									}	
								}
								if (l + 8 <= 24) {
									switch (TAB[l + 8][c]) {
										case 'f': case 'C': jogadas_possiveis++; break;
									}	
								}
								if (c - 8 >= 0) {
									switch (TAB[l][c - 8]) {
										case 'f': case 'C': jogadas_possiveis++; break;
									}	
								}
								if (c + 8 <= 20) {
									switch (TAB[l][c + 8]) {
										case 'f': case 'C': jogadas_possiveis++; break;
									}	
								}
								if (l - 4 >= 0 && c - 4 >= 0) {
									switch (TAB[l - 4][c - 4]) {
										case 'f': case 'C': jogadas_possiveis++; break;
									}
								}
								if (l + 4 >= 24 && c - 4 >= 0) {
									switch (TAB[l + 4][c - 4]) {
										case 'f': case 'C': jogadas_possiveis++; break;
									}
								}
								if (l - 4 >= 0 && c + 4 <= 20) {
									switch (TAB[l - 4][c + 4]) {
										case 'f': case 'C': jogadas_possiveis++; break;
									}
								}
								if (l + 4 <= 24 && c + 4 <= 20) {
									switch (TAB[l + 4][c + 4]) {
										case 'f': case 'C': jogadas_possiveis++; break;
									}
								}
							} else {
								if (l - 4 >= 0 && c - 4 >= 0) {
									switch (TAB[l - 4][c - 4]) {
										case 'f': case 'C': jogadas_possiveis++; break;
									}
								}
								if (l + 4 >= 24 && c - 4 >= 0) {
									switch (TAB[l + 4][c - 4]) {
										case 'f': case 'C': jogadas_possiveis++; break;
									}
								}
								if (l - 4 >= 0 && c + 4 <= 20) {
									switch (TAB[l - 4][c + 4]) {
										case 'f': case 'C': jogadas_possiveis++; break;
									}
								}
								if (l + 4 <= 24 && c + 4 <= 20) {
									switch (TAB[l + 4][c + 4]) {
										case 'f': case 'C': jogadas_possiveis++; break;
									}
								}
							}
							break;
					case 'G':
						if (l % 4 == 0 && c % 4 == 0) {
							if (l - 8 >= 0) {
									switch (TAB[l - 8][c]) {
										case 'C': jogadas_possiveis++; break;
									}	
								}
								if (l + 8 <= 24) {
									switch (TAB[l + 8][c]) {
										case 'C': jogadas_possiveis++; break;
									}	
								}
								if (c - 8 >= 0) {
									switch (TAB[l][c - 8]) {
										case 'C': jogadas_possiveis++; break;
									}	
								}
								if (c + 8 <= 20) {
									switch (TAB[l][c + 8]) {
										case 'C': jogadas_possiveis++; break;
									}	
								}
								if (l - 4 >= 0 && c - 4 >= 0) {
									switch (TAB[l - 4][c - 4]) {
										case 'C': jogadas_possiveis++; break;
									}
								}
								if (l + 4 >= 24 && c - 4 >= 0) {
									switch (TAB[l + 4][c - 4]) {
										case 'C': jogadas_possiveis++; break;
									}
								}
								if (l - 4 >= 0 && c + 4 <= 20) {
									switch (TAB[l - 4][c + 4]) {
										case 'C': jogadas_possiveis++; break;
									}
								}
								if (l + 4 <= 24 && c + 4 <= 20) {
									switch (TAB[l + 4][c + 4]) {
										case 'C': jogadas_possiveis++; break;
									}
								}
							} else {
								if (l - 4 >= 0 && c - 4 >= 0) {
									switch (TAB[l - 4][c - 4]) {
										case 'C': jogadas_possiveis++; break;
									}
								}
								if (l + 4 >= 24 && c - 4 >= 0) {
									switch (TAB[l + 4][c - 4]) {
										case 'C': jogadas_possiveis++; break;
									}
								}
								if (l - 4 >= 0 && c + 4 <= 20) {
									switch (TAB[l - 4][c + 4]) {
										case 'C': jogadas_possiveis++; break;
									}
								}
								if (l + 4 <= 24 && c + 4 <= 20) {
									switch (TAB[l + 4][c + 4]) {
										case 'C': jogadas_possiveis++; break;
									}
								}
							}
							break;
				}
			}
		}
	}
	if (jogadas_possiveis == 0 && capturas_possiveis == 0) {
		//printf("Sem movimentos possiveis. Fim de jogo!\n");
		return true;
	} else {
		//printf("Ainda restam %u jogadas possiveis e %d capturas possiveis.\n", jogadas_possiveis, capturas_possiveis);
		return false;
	}
}
