#ifndef _MOSQUITOMACHO_
#define _MOSQUITOMACHO_

#include "Mosquito.cpp"

class MosquitoMacho : public Mosquito {
public:

	int contadorAcasalamentos;

	MosquitoMacho(int _id, char _saudeWolbachia, char _fase, char _idade, int _idLoteAtual, int _x, int _y) {
		id = _id;
		sexo = 'm';
		saudeWolbachia = _saudeWolbachia;
		fase = _fase;
		idade = _idade;
		idLoteAtual = _idLoteAtual;
		posicaoAtual.x = _x;
		posicaoAtual.y = _y;
        vida = true;
        contadorAcasalamentos = 0;
	}
	
	MosquitoMacho() {}
	
	~MosquitoMacho() {}

};

#endif
