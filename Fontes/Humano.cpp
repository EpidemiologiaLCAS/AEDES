#ifndef HUMANO
#define HUMANO

#include "Lista.cpp"
#include "Posicao.cpp"

class Humano {
public:

    int id;
    int saude; // suscetivel (s), latente (l), infectante (i), imunizado (m), hemorragico (h), removido (r)
    int sorotipo; // tipo (1-5) ou 0 (ausente)
    Lista<int> listaSorotiposContraidos;
    int contagemCiclosPeriodos;
    int idLoteAtual;
    Posicao posicaoAtual;
    int idLoteInicial;
    Posicao posicaoInicial;

	Humano() {}

    Humano(int _id, int _saude, int _sorotipo, int _idLoteInicial, int _x, int _y) {
        id = _id;
        saude = _saude;
        sorotipo = _sorotipo;
        contagemCiclosPeriodos = 0;
        idLoteInicial = _idLoteInicial;
        idLoteAtual = _idLoteInicial;
        posicaoAtual.x = _x;
        posicaoAtual.y = _y;
        posicaoInicial.x = _x;
        posicaoInicial.y = _y;
    }
    
    ~Humano() {}

};

#endif
