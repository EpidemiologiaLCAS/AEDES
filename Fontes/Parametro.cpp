#ifndef _PARAMETRO_
#define _PARAMETRO_

// Classe que representa um parâmetro da simulação
class Parametro {
public:

	double valorMinimo; // valor mínimo do parâmetro
	double valorMaximo; // valor máximo do parâmetro

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
