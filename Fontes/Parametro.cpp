#ifndef _PARAMETRO_
#define _PARAMETRO_

class Parametro {
public:

    double valorMinimo;
    double valorMaximo;

    Parametro() {}

    Parametro(double _valorMinimo, double _valorMaximo) {
        valorMinimo = _valorMinimo;
        valorMaximo = _valorMaximo;
    }
    
	~Parametro() {}

    void mostrar() {
        cout << "MIN: " << valorMinimo << "\tMAX: " << valorMaximo << endl;
    }

    double random() {
		return randomizarEntreFaixa(valorMinimo, valorMaximo);
    }

};

#endif
