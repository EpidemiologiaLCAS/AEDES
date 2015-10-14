#ifndef _VETOR_
#define _VETOR_

template <class T> class Vetor {
public:

    T* vetor;
	int tamanhoVetor;
	
	Vetor(int tamanhoVetor) {
        this->tamanhoVetor = tamanhoVetor;
        vetor = new T[tamanhoVetor]();
    }
    
    void zero(T _zero) {
		FOR_INT(i, 0, tamanhoVetor, 1) {
			vetor[i] = _zero;
		}
	}

    ~Vetor() {
		delete[](vetor);
    }

};

#endif
