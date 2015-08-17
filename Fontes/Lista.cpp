#ifndef LISTA
#define LISTA

#include "ElementoLista.cpp"

template <class T> class Lista {
public:

    ElementoLista<T>* cabecaLista;
    ElementoLista<T>* caudaLista;
    int tamanhoLista;
    
    Lista() {
        cabecaLista = NULL;
        caudaLista = NULL;
        tamanhoLista = 0;
    }
	
	void preDestrutor() {
        for (ElementoLista<T>* i = cabecaLista; i != NULL; i = i->proximoLista) {
			delete(i->elementoLista);
			i->elementoLista = NULL;
		}
	}
    
    ~Lista() {
        ElementoLista<T>* i = cabecaLista;
        while (i != NULL) {
            ElementoLista<T>* aux1 = i->proximoLista;
            delete(i);
            i = aux1;
        }
        cabecaLista = NULL;
        caudaLista = NULL;
        tamanhoLista = 0;
    }

    T insercaoLista(ElementoLista<T>* novoElemento) {
        if (cabecaLista == NULL) {
            novoElemento->proximoLista = NULL;
            novoElemento->anteriorLista = NULL;
            cabecaLista = novoElemento;
            caudaLista = novoElemento;
        } else {
            novoElemento->proximoLista = NULL;
            novoElemento->anteriorLista = caudaLista;
            caudaLista->proximoLista = novoElemento;
            caudaLista = novoElemento;
        }
        tamanhoLista++;
        return novoElemento->elementoLista;
    }

    void remocaoLista(ElementoLista<T>* elemento) {
        if (elemento->proximoLista != NULL) {
            if (elemento->anteriorLista == NULL) {
                cabecaLista = elemento->proximoLista;
                elemento->proximoLista->anteriorLista = NULL;
                delete(elemento);
                tamanhoLista--;
            } else {
                elemento->anteriorLista->proximoLista = elemento->proximoLista;
                elemento->proximoLista->anteriorLista = elemento->anteriorLista;
                delete(elemento);
                tamanhoLista--;
            }
        } else {
            if (elemento->anteriorLista == NULL) {
                cabecaLista = NULL;
                caudaLista = NULL;
                delete(elemento);
                tamanhoLista--;
            } else {
                caudaLista = elemento->anteriorLista;
                elemento->anteriorLista->proximoLista = NULL;
                delete(elemento);
                tamanhoLista--;
            }
        }
        return;
    }

    bool buscaRemocaoLista(T elemento) {
        ElementoLista<T>* i = cabecaLista;
        while (i != NULL) {
            if (i->elementoLista == elemento) {
                remocaoLista(i);
                return true;
            }
            i = i->proximoLista;
        }
        return false;
    }

    bool buscaLista(T elemento) {
        ElementoLista<T>* i = cabecaLista;
        while (i != NULL) {
            if (i->elementoLista == elemento)
                return true;
            i = i->proximoLista;
        }
        return false;
    }

    ElementoLista<T>* buscaPosicao(int posicao) {
		int contador = 0;
		ElementoLista<T>* retorno = cabecaLista;
		while (contador != posicao) {
			++contador;
			retorno = retorno->proximoLista;
		}
		return retorno;
	}

    void exibicaoLista() {
        for (ElementoLista<T>* i = cabecaLista; i != NULL; i = i->proximoLista)
            cout << i->elementoLista << " ";
        cout << endl;
    }

};

#endif
