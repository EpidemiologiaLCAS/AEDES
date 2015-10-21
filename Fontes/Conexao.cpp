#ifndef _CONEXAO_
#define _CONEXAO_

using namespace std;

#include "Posicao.cpp"

// Classe que representa as conexões entre as posições de lotes vizinhos
class Conexao {
public:

	Posicao destino; // id do lote vizinho destino
	int idLoteDestino; // posição do lote vizinho destino

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

