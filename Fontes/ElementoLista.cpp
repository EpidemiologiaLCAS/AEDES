#ifndef _ELEMENTOLISTA_
#define _ELEMENTOLISTA_

template <class T> class ElementoLista {
public:

    T elementoLista;
    ElementoLista<T>* proximoLista;
    ElementoLista<T>* anteriorLista;

    ElementoLista(T _elementoLista) {
        proximoLista = NULL;
        anteriorLista = NULL;
        elementoLista = _elementoLista;
    }

    ~ElementoLista() {
        proximoLista = NULL;
        anteriorLista = NULL;
    }

};

#endif
