#ifndef _LISTAHUMANOS_
#define _LISTAHUMANOS_

#include "Lista.cpp"
#include "Humano.cpp"

// Classe que representa uma lista de agentes humanos
class ListaHumanos: public Lista<Humano> {
public:

	Lista<Humano*>* lista; // lista de agentes humanos

	ListaHumanos() {
		this->lista = new Lista<Humano*>();
	}

	~ListaHumanos() {
		lista->preDestrutor();
		delete (lista);
	}

};

#endif
