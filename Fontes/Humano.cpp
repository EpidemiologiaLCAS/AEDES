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
    
    Humano(Humano* h) {
        this->id = h->id;
        this->saude = h->saude;
        this->sorotipo = h->sorotipo;
		ElementoLista<int>* i = h->listaSorotiposContraidos.cabecaLista;
		while (i != NULL) {
			this->listaSorotiposContraidos.insercaoLista(new ElementoLista<int>(i->elementoLista));
			i = i->proximoLista;
		}
        this->contagemCiclosPeriodos = h->contagemCiclosPeriodos;
        this->idLoteInicial = h->idLoteInicial;
        this->idLoteAtual = -h->idLoteAtual;
        this->posicaoAtual.x = h->posicaoAtual.x;
        this->posicaoAtual.y = h->posicaoAtual.y;
        this->posicaoInicial.x = h->posicaoInicial.x;
        this->posicaoInicial.y = h->posicaoInicial.y;
    }

    ~Humano() {}

};

#endif
