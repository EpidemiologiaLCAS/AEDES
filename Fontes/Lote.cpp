#ifndef _LOTE_
#define _LOTE_

using namespace std;

#include "Posicao.cpp"
#include "Matriz.cpp"
#include "ElementoLote.cpp"
#include "Lista.cpp"

class Lote {
public:

    int id;
    Matriz<ElementoLote>* lote;
    double controleQuimicoLarvas, controleQuimicoPupas;
    bool controleMecanicoNaoAlados, controleQuimicoAlados;

    Lote() {}

    Lote(int id, int linhas, int colunas) {
        this->id = id;
        this->lote = new Matriz<ElementoLote>(linhas, colunas);
        this->controleQuimicoLarvas = -1;
        this->controleQuimicoPupas = -1;
        this->controleMecanicoNaoAlados = false;
        this->controleQuimicoAlados = false;
    }

    ~Lote() {
		delete(lote);
    }
    
};

#endif


