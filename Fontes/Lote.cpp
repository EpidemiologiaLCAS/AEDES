#ifndef _LOTE_
#define _LOTE_

using namespace std;

#include "Posicao.cpp"
#include "Matriz.cpp"
#include "ElementoLote.cpp"
#include "Lista.cpp"

// Classe que representa um lote
class Lote {
public:

	int id; // id do lote
	Matriz<ElementoLote>* lote; // matriz que representa o lote
	double controleQuimicoLarvas, controleQuimicoPupas; // efeito residual de controle químico em larvas e pupas
	bool controleMecanicoNaoAlados, controleQuimicoAlados; // aplicação de controle mecânico e químico

	Lote() {
	}

	Lote(int id, int linhas, int colunas) {
		this->id = id;
		this->lote = new Matriz<ElementoLote>(linhas, colunas);
		this->controleQuimicoLarvas = -1;
		this->controleQuimicoPupas = -1;
		this->controleMecanicoNaoAlados = false;
		this->controleQuimicoAlados = false;
	}

	~Lote() {
		delete (lote);
	}

};

#endif

