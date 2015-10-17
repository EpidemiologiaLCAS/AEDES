#ifndef _PARAMETRO_
#define _PARAMETRO_

class Parametro {
public:

	double valorMinimo;
	double valorMaximo;

	Parametro() {
	}

	Parametro(double valorMinimo, double valorMaximo) {
		this->valorMinimo = valorMinimo;
		this->valorMaximo = valorMaximo;
	}

	~Parametro() {
	}

	void mostrar() {
		cout << "MIN: " << valorMinimo << "\tMAX: " << valorMaximo << endl;
	}

	double random() {
		return randomizarEntreFaixa(valorMinimo, valorMaximo);
	}

};

#endif
