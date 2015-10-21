#ifndef _LISTAMOSQUITOS_
#define _LISTAMOSQUITOS_

#include "Lista.cpp"
#include "Mosquito.cpp"

// Classe que representa uma lista de agentes mosquitos
class ListaMosquitos: public Lista<Mosquito> {
public:

	Lista<Mosquito*>* lista; // lista de agentes mosquitos

	ListaMosquitos() {
		this->lista = new Lista<Mosquito*>();
	}

	~ListaMosquitos() {
		lista->preDestrutor();
		delete (lista);
	}

};

#endif
