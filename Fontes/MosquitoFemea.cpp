#ifndef _MOSQUITOFEMEA_
#define _MOSQUITOFEMEA_

#include "Mosquito.cpp"
#include "Posicao.cpp"

class MosquitoFemea : public Mosquito {
public:

    char saudeDengue; // saudavel (s), latente (l) ou infectante (i)
    int sorotipo; // (1-5) infectado e (0) ausente
	int ciclosLatencia;
	char tipoAcasalamento; // nao acasalado 'n', acasalado saudavel 'a' ou infectado 'i'
	int contadorPosturas;
	int ciclosGestacao;
	int contadorCiclosEntrePosturas;
    char tipoProle; // saudavel 's', infectado 'i', esteril 'e', nenhum 'n'
	Posicao posicaoAlimento; // posicao onde a femea encontrou alimento
    bool alimento; // indica se a femea esta ou nao alimentada

	MosquitoFemea(int id, char saudeWolbachia, char saudeDengue, int sorotipo, char fase, int idade, int idLoteAtual, int x, int y) {
		this->id = id;
		this->sexo = FEMEA;
		this->saudeWolbachia = saudeWolbachia;
		this->saudeDengue = saudeDengue;
        this->sorotipo = sorotipo;
		this->fase = fase;
		this->idade = idade;
		setLoteAtualPosicaoAtual(idLoteAtual, x, y);     
        this->vida = true;
        this->ciclosLatencia = 0;
        this->tipoAcasalamento = NENHUM;
        this->contadorPosturas = 0;
        this->ciclosGestacao = 0;
        this->contadorCiclosEntrePosturas = 0;
        this->tipoProle = NENHUM;  
        setPosicaoAlimento(-1, -1);
        this->alimento = false;
	}
	
	void setPosicaoAlimento(int x, int y) {
		posicaoAlimento.x = x;
		posicaoAlimento.y = y;
	}

	MosquitoFemea() {}
	
	~MosquitoFemea() {}

};

#endif
