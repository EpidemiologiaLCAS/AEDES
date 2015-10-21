#ifndef _POSICAO_
#define _POSICAO_

// Classe que representa uma posição de um lote
class Posicao {
public:

	int x; // coordenada x da posição
	int y; // coordenada y da posição

	Posicao() {
	}

	Posicao(int x, int y) {
		this->x = x;
		this->y = y;
	}

	// Retorna verdadeiro se duas posições são iguais
	bool operator==(Posicao pos) {
		if ((x = pos.x) && (y = pos.y)) {
			return true;
		}
		return false;
	}

	~Posicao() {
	}

};

#endif
