#ifndef _LISTA_
#define _LISTA_

#include "ElementoLista.cpp"

// Classe que representa uma lista de elementos genéricos
template<class T> class Lista {
public:

	ElementoLista<T>* cabecaLista; // cabeça da lista
	ElementoLista<T>* caudaLista; // cauda da lista
	int tamanhoLista; // quantidade de elementos na lista

	Lista() {
		this->cabecaLista = NULL;
		this->caudaLista = NULL;
		this->tamanhoLista = 0;
	}

	// Libera os elementos da lista caso forem ponteiros
	void preDestrutor() {
		for (ElementoLista<T>* i = cabecaLista; i != NULL; i = i->proximoLista) {
			delete (i->elementoLista);
			i->elementoLista = NULL;
		}
	}

	~Lista() {
		ElementoLista<T>* i = cabecaLista;
		while (i != NULL) {
			ElementoLista<T>* aux1 = i->proximoLista;
			delete (i);
			i = aux1;
		}
		cabecaLista = NULL;
		caudaLista = NULL;
		tamanhoLista = 0;
	}

	// Insere um novo elemento na lista
	T insercaoLista(T novo) {
		ElementoLista<T>* novoElemento = new ElementoLista<T>(novo);
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

	// Remove um elemento da lista
	void remocaoLista(ElementoLista<T>* elemento) {
		if (elemento->proximoLista != NULL) {
			if (elemento->anteriorLista == NULL) {
				cabecaLista = elemento->proximoLista;
				elemento->proximoLista->anteriorLista = NULL;
				delete (elemento);
				tamanhoLista--;
			} else {
				elemento->anteriorLista->proximoLista = elemento->proximoLista;
				elemento->proximoLista->anteriorLista = elemento->anteriorLista;
				delete (elemento);
				tamanhoLista--;
			}
		} else {
			if (elemento->anteriorLista == NULL) {
				cabecaLista = NULL;
				caudaLista = NULL;
				delete (elemento);
				tamanhoLista--;
			} else {
				caudaLista = elemento->anteriorLista;
				elemento->anteriorLista->proximoLista = NULL;
				delete (elemento);
				tamanhoLista--;
			}
		}
		return;
	}

	// Busca e remove um elemento da lista
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

	// Verifica se um elemento está na lista
	bool buscaLista(T elemento) {
		ElementoLista<T>* i = cabecaLista;
		while (i != NULL) {
			if (i->elementoLista == elemento)
				return true;
			i = i->proximoLista;
		}
		return false;
	}

	// Retorna um elemento da lista pela sua posição
	ElementoLista<T>* buscaPosicao(int posicao) {
		int contador = 0;
		ElementoLista<T>* retorno = cabecaLista;
		while (contador != posicao) {
			++contador;
			retorno = retorno->proximoLista;
		}
		return retorno;
	}

	// Mostra a lista
	void exibicaoLista() {
		for (ElementoLista<T>* i = cabecaLista; i != NULL; i = i->proximoLista)
			cout << i->elementoLista << " ";
		cout << endl;
	}

};

#endif
