#ifndef HUMANO
#define HUMANO

#include "Lista.cpp"
#include "Posicao.cpp"

class Humano {
public:

    int id;
    int saude; // suscetivel (s), latente (l), infectante (i), imunizado (m), hemorragico (h), removido (r)
    int sorotipo; // tipo (1 - 5) ou ausente (0)
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
        setLoteAtualPosicaoAtual(_idLoteInicial, _x ,_y);
        setLoteInicialPosicaoInicial(_idLoteInicial, _x ,_y);
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
