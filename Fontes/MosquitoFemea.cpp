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

	MosquitoFemea(int _id, char _saudeWolbachia, char _saudeDengue, int _sorotipo, char _fase, int _idade, int _idLoteAtual, int _x, int _y) {
		id = _id;
		sexo = 'f';
		saudeWolbachia = _saudeWolbachia;
		saudeDengue = _saudeDengue;
        sorotipo = _sorotipo;
		fase = _fase;
		idade = _idade;
		setLoteAtualPosicaoAtual(_idLoteAtual, _x, _y);     
        vida = true;
        ciclosLatencia = 0;
        tipoAcasalamento = 'n';
        contadorPosturas = 0;
        ciclosGestacao = 0;
        contadorCiclosEntrePosturas = 0;
        tipoProle = 'n';  
        setPosicaoAlimento(-1, -1);
        alimento = false;
	}
	
	void setPosicaoAlimento(int x, int y) {
		posicaoAlimento.x = x;
		posicaoAlimento.y = y;
	}

	MosquitoFemea() {}
	
	~MosquitoFemea() {}

};

#endif
