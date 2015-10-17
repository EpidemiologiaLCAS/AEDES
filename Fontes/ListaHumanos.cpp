#ifndef _LISTAHUMANOS_
#define _LISTAHUMANOS_

#include "Lista.cpp"
#include "Humano.cpp"

class ListaHumanos: public Lista<Humano> {
public:

	Lista<Humano*>* lista;

	ListaHumanos() {
		this->lista = new Lista<Humano*>();
	}

	~ListaHumanos() {
		lista->preDestrutor();
		delete (lista);
	}

};

#endif
