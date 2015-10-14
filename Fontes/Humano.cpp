#ifndef _HUMANO_
#define _HUMANO_

#include "Lista.cpp"
#include "Posicao.cpp"

class Humano {
public:

    int id;
    int saude; // suscetivel (s), latente (l), infectado (i), imunizado (m), hemorragico (h), removido (r)
    int sorotipo; // tipo (1 - 5) ou ausente (0)
    Lista<int> listaSorotiposContraidos;
    int contagemCiclosPeriodos;
    int idLoteAtual;
    Posicao posicaoAtual;
    int idLoteInicial;
    Posicao posicaoInicial;

	Humano() {}

    Humano(int id, int saude, int sorotipo, int idLoteInicial, int x, int y) {
        this->id = id;
        this->saude = saude;
        this->sorotipo = sorotipo;
        this->contagemCiclosPeriodos = 0;
        setLoteAtualPosicaoAtual(idLoteInicial, x ,y);
        setLoteInicialPosicaoInicial(idLoteInicial, x ,y);
    }
    
    void setPosicaoAtual(int x, int y) {
		posicaoAtual.x = x;
		posicaoAtual.y = y;
	}
   
	void setLoteAtualPosicaoAtual(int idLote, int x, int y) {
		idLoteAtual = idLote;
		setPosicaoAtual(x, y);
	}
	
	void setPosicaoInicial(int x, int y) {
		posicaoInicial.x = x;
		posicaoInicial.y = y;
	}
	
	void setLoteInicialPosicaoInicial(int idLote, int x, int y) {
		idLoteInicial = idLote;
		setPosicaoInicial(x, y);
	}
	
	void setLoteAtualPosicaoAtualLoteInicialPosicaoInicial() {
		setLoteAtualPosicaoAtual(idLoteInicial, posicaoInicial.x, posicaoInicial.y);
	}
    
    ~Humano() {}

};

#endif
