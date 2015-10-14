#ifndef _MATRIZ_
#define _MATRIZ_

template <class T> class Matriz {
public:

    T** matriz;
    int linhasMatriz;
    int colunasMatriz;

    Matriz(int linhasMatriz, int colunasMatriz) {
        this->linhasMatriz = linhasMatriz;
        this->colunasMatriz = colunasMatriz;
        this->matriz = new T*[linhasMatriz]();
        FOR_INT(i, 0, linhasMatriz, 1) {
            matriz[i] = new T[colunasMatriz]();
        }
    }
    
    void zero(T zero) {
		FOR_INT(i, 0, linhasMatriz, 1) {
			FOR_INT(j, 0, colunasMatriz, 1) {
				matriz[i][j] = zero;
			}
		}
	}

    ~Matriz() {
        FOR_INT(i, 0, linhasMatriz, 1) {
			delete[] (matriz[i]);
        }
        delete[] (matriz);
        linhasMatriz = 0;
        colunasMatriz = 0;
    }

};

#endif
