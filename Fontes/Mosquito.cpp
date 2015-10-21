#ifndef _MOSQUITO_
#define _MOSQUITO_

#include "Posicao.cpp"

// Classe que representa um agente mosquito genérico
class Mosquito {
public:

	int id; // id do agente mosquito
	char sexo; // macho (m) ou femea (f)
	char saudeWolbachia; // saudavel (s) ou infectado (i)
	char fase; // ovos (o), larvas (l), pupas (p), ativos (a) ou decadentes (d)
	int idade; // idade do agente mosquito
	bool vida; // vida do agente mosquito (se morto ou vivo)
	int idLoteAtual; // id do lote atual do mosquito
	Posicao posicaoAtual;  // posição atual do mosquito

	Mosquito() {
	}

	void addPosicaoAtual(int px, int py) {
		posicaoAtual.x += px;
		posicaoAtual.y += py;
	}

	void setPosicaoAtual(int x, int y) {
		posicaoAtual.x = x;
		posicaoAtual.y = y;
	}

	void setLoteAtualPosicaoAtual(int idLote, int x, int y) {
		idLoteAtual = idLote;
		setPosicaoAtual(x, y);
	}

	~Mosquito() {
	}

};

#endif
