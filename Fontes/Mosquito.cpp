#ifndef MOSQUITO
#define MOSQUITO

#include "Posicao.cpp"

class Mosquito {
public:

	int id;
    char sexo; // macho (m) ou femea (f)
    char saudeWolbachia; // saudavel (s) ou infectado (i)
    char fase; // ovos (o), larvas (l), pupas (p), ativos (a) ou decadentes (d)
    int idade;
    bool vida;
    int idLoteAtual;
    Posicao posicaoAtual; // localizacao atual do agente

	Mosquito() {}

	~Mosquito() {}
    
};

#endif
