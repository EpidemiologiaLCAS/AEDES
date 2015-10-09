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

    Lote(int _id, int linhasLote, int colunasLote) {
        id = _id;
        lote = new Matriz<ElementoLote>(linhasLote, colunasLote);
        controleQuimicoLarvas = -1;
        controleQuimicoPupas = -1;
        controleMecanicoNaoAlados = false;
        controleQuimicoAlados = false;
    }

    ~Lote() {
		delete(lote);
    }
    
};

#endif


