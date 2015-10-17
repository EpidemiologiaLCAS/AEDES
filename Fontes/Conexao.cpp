#ifndef _CONEXAO_
#define _CONEXAO_

using namespace std;

#include "Posicao.cpp"

class Conexao {
public:

	Posicao destino;
	int idLoteDestino;

	Conexao() {
	}

	Conexao(Posicao destino, int idLoteDestino) {
		this->destino = destino;
		this->idLoteDestino = idLoteDestino;
	}

	~Conexao() {
	}

};

#endif

