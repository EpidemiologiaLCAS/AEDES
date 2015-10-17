#ifndef _MOSQUITOMACHO_
#define _MOSQUITOMACHO_

#include "Mosquito.cpp"

class MosquitoMacho: public Mosquito {
public:

	int contadorAcasalamentos;

	MosquitoMacho(int id, char saudeWolbachia, char fase, char idade, int idLoteAtual, int x, int y) {
		this->id = id;
		this->sexo = MACHO;
		this->saudeWolbachia = saudeWolbachia;
		this->fase = fase;
		this->idade = idade;
		this->idLoteAtual = idLoteAtual;
		this->posicaoAtual.x = x;
		this->posicaoAtual.y = y;
		this->vida = true;
		this->contadorAcasalamentos = 0;
	}

	MosquitoMacho() {
	}

	~MosquitoMacho() {
	}

};

#endif
