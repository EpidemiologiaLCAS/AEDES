#ifndef _MOSQUITO_
#define _MOSQUITO_

#include "Posicao.cpp"

class Mosquito {
public:

	int id;
    char sexo; // macho (m) ou femea (f)
    char saudeWolbachia; // saudavel (s) ou infectado (i)
    char fase; // ovos (o), larvas (l), pupas (p), ativos (a) ou decadentes (d)
    int idade;
    bool vida;
    int idLoteAtual;
    Posicao posicaoAtual; // localizacao atual do agente

	Mosquito() {}

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

	~Mosquito() {}
    
};

#endif
