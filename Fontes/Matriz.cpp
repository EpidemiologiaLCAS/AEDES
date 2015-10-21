#ifndef _MATRIZ_
#define _MATRIZ_

// Classe que representa uma matriz genérica
template<class T> class Matriz {
public:

	T** matriz; // matriz
	int linhasMatriz; // quantidade de linhas da matriz
	int colunasMatriz; // quantidade de colunas da matriz

	Matriz(int linhasMatriz, int colunasMatriz) {
		this->linhasMatriz = linhasMatriz;
		this->colunasMatriz = colunasMatriz;
		this->matriz = new T*[linhasMatriz]();
		FOR_INT(i, 0, linhasMatriz, 1)
		{
			matriz[i] = new T[colunasMatriz]();
		}
	}

	void zero(T zero) {
		FOR_INT(i, 0, linhasMatriz, 1)
		{
			FOR_INT(j, 0, colunasMatriz, 1)
			{
				matriz[i][j] = zero;
			}
		}
	}

	~Matriz() {
		FOR_INT(i, 0, linhasMatriz, 1)
		{
			delete[] (matriz[i]);
		}
		delete[] (matriz);
		linhasMatriz = 0;
		colunasMatriz = 0;
	}

};

#endif
