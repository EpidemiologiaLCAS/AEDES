#ifndef _CONEXAO_
#define _CONEXAO_

using namespace std;

#include "Posicao.cpp"

class Conexao {
public:

    Posicao destino;
	int idLoteDestino;

    Conexao() {}

    Conexao(Posicao _destino, int _idLoteDestino) {
		destino = _destino;
		idLoteDestino = _idLoteDestino;
    }

    ~Conexao() {}

};

#endif

