#ifndef _ELEMENTOLISTA_
#define _ELEMENTOLISTA_

template<class T> class ElementoLista {
public:

	T elementoLista;
	ElementoLista<T>* proximoLista;
	ElementoLista<T>* anteriorLista;

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
