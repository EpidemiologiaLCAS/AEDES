#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

#include "MacrosGerais.cpp"
#include "MonteCarlo.cpp"

int main(int contadorArgumentos, char* argumentos[]) {
	srand((unsigned) time(NULL));
    //clock_t tempoInicioMonteCarlo = clock();
    if (contadorArgumentos != NUMERO_ARGUMENTOS_PROGRAMA) {
        cout << endl << "Use: ./Simulacao indiceInicio indiceFim quantLotes" << endl << endl;
        return 1;
    }
    cout.precision(PRECISAO_COUT);
    cout << fixed;
    int indiceInicio = atoi(argumentos[1]);
    int indiceFim = atoi(argumentos[2]);
    int quantLotes = atoi(argumentos[3]);
    MonteCarlo* simulacaoMonteCarlo;
    FOR_INT(indice, indiceInicio, indiceFim, 1) {
        string pasta = "Saidas";
		pasta += SEPARADOR;
		pasta += "MonteCarlo_";
		char stringIdMonteCarlo[TAMANHO_STRINGS_AUXILIARES];
		sprintf(stringIdMonteCarlo, "%d", indice);
		pasta += stringIdMonteCarlo;
		pasta += SEPARADOR;
		string comando = COMANDO_CRIAR_PASTA;
        comando += pasta;
        system(comando.c_str());
        simulacaoMonteCarlo = new MonteCarlo(indice, pasta, quantLotes);
        simulacaoMonteCarlo->inicioMonteCarlo();
        delete(simulacaoMonteCarlo);
    }
    //clock_t tempoFimMonteCarlo = clock();
    //double tempoTotalExecucao = (double) (tempoFimMonteCarlo - tempoInicioMonteCarlo) / CLOCKS_PER_SEC;
    //cout << endl << "Tempo Total de Execucao: " << tempoTotalExecucao << "s" << endl << endl;
    return 0;
}
