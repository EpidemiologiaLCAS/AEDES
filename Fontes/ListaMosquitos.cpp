#ifndef _LISTAMOSQUITOS_
#define _LISTAMOSQUITOS_

#include "Lista.cpp"
#include "Mosquito.cpp"

class ListaMosquitos: public Lista<Mosquito> {
public:

	Lista<Mosquito*>* lista;

	ListaMosquitos() {
		this->lista = new Lista<Mosquito*>();
	}

	~ListaMosquitos() {
		lista->preDestrutor();
		delete (lista);
	}

};

#endif
