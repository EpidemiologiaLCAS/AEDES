#ifndef _VETOR_
#define _VETOR_

// Classe que representa um vetor genérico
template<class T> class Vetor {
public:

	T* vetor; // vetor
	int tamanhoVetor; // número máximo de elementos no vetor

	Vetor(int tamanhoVetor) {
		this->tamanhoVetor = tamanhoVetor;
		vetor = new T[tamanhoVetor]();
	}

	void zero(T _zero) {
		FOR_INT(i, 0, tamanhoVetor, 1)
		{
			vetor[i] = _zero;
		}
	}

	~Vetor() {
		delete[] (vetor);
	}

};

#endif
