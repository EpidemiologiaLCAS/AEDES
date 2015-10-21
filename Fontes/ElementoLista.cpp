#ifndef _ELEMENTOLISTA_
#define _ELEMENTOLISTA_

// Classe que representa o elemento genérico de uma lista
template<class T> class ElementoLista {
public:

	T elementoLista; // elemento da lista
	ElementoLista<T>* proximoLista; // próximo elemento da lista
	ElementoLista<T>* anteriorLista; // elemento anterior da lista

	ElementoLista(T elementoLista) {
		this->proximoLista = NULL;
		this->anteriorLista = NULL;
		this->elementoLista = elementoLista;
	}

	~ElementoLista() {
		this->proximoLista = NULL;
		this->anteriorLista = NULL;
	}

};

#endif
