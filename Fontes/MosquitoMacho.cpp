#ifndef _MOSQUITOMACHO_
#define _MOSQUITOMACHO_

#include "Mosquito.cpp"

// Classe que representa um agente mosquito macho
class MosquitoMacho: public Mosquito {
public:

	int contadorAcasalamentos; // contador da quantidade de acasalamentos realizados pelo macho

	MosquitoMacho() {
	}

	MosquitoMacho(int id, char saudeWolbachia, char fase, int idade, int idLoteAtual, int x, int y) {
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

	~MosquitoMacho() {
	}

};

#endif
