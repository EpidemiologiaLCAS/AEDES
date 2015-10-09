#ifndef _MATRIZ_
#define _MATRIZ_

template <class T> class Matriz {
public:

    T** matriz;
    int linhasMatriz;
    int colunasMatriz;

    Matriz(int _linhasMatriz, int _colunasMatriz) {
        linhasMatriz = _linhasMatriz;
        colunasMatriz = _colunasMatriz;
        matriz = new T*[linhasMatriz]();
        FORINT(i, 0, linhasMatriz, 1) {
            matriz[i] = new T[colunasMatriz]();
        }
    }
    
    void zero(T _zero) {
		FORINT(i, 0, linhasMatriz, 1) {
			FORINT(j, 0, colunasMatriz, 1) {
				matriz[i][j] = _zero;
			}
		}
	}

    ~Matriz() {
        FORINT(i, 0, linhasMatriz, 1) {
			delete[] (matriz[i]);
        }
        delete[] (matriz);
        linhasMatriz = 0;
        colunasMatriz = 0;
    }

};

#endif
