#ifndef _MONTECARLO_
#define _MONTECARLO_

#include "SaidasMonteCarlo.cpp"
#include "Parametros.cpp"
#include "Simulacao.cpp"
#include "Saidas.cpp"

// Classe que representa uma simulação Monte Carlo
class MonteCarlo {
public:

	int idMonteCarlo; // id da simulação Monte Carlo
	int quantLotes; // quantidade de lotes
	string pastaEntrada; // pasta de entrada
	string pastaSaida; // pasta de saída
	SaidasMonteCarlo* saidas; // gerador de saídas Monte Carlo
	Parametros* parametros; // parâmetros
	Saidas* saidasSimulacoes; // saídas das simulações individuais

	MonteCarlo(int idMonteCarlo, string pastaSaida, int quantLotes) {
		this->quantLotes = quantLotes;
		this->idMonteCarlo = idMonteCarlo;
		this->pastaSaida = pastaSaida;
		char aux2[TAMANHO_STRINGS_AUXILIARES];
		sprintf(aux2, "%d", idMonteCarlo);
		pastaEntrada = "Entradas";
		pastaEntrada += SEPARADOR;
		pastaEntrada += "MonteCarlo_";
		string aux1 = string(aux2);
		pastaEntrada += aux1;
		pastaEntrada += SEPARADOR;
		this->parametros = new Parametros(pastaEntrada, quantLotes);
		this->saidasSimulacoes = new Saidas[QUANTIDADE_SIMULACOES]();
		FOR_INT(i, 0, QUANTIDADE_SIMULACOES, 1)
		{
			this->saidasSimulacoes[i].init(quantLotes);
		}
		this->saidas = new SaidasMonteCarlo(idMonteCarlo, aux2, pastaSaida, NUMERO_CICLOS_SIMULACAO + 1, QUANTIDADE_SIMULACOES, saidasSimulacoes, quantLotes);
	}

	~MonteCarlo() {
		delete (saidas);
		delete[] (saidasSimulacoes);
		delete (parametros);
	}

	// Inicia uma simulação Monte Carlo
	void inicioMonteCarlo() {
		Simulacao* simulacao;
		int maxSimulacao = QUANTIDADE_SIMULACOES;
		FOR_INT(indice, 0, maxSimulacao, 1)
		{
			bool simulacaoConcluida = false;
			int contadorTentativasSimulacao = 0;
			while (!simulacaoConcluida) {
				//clock_t tempoInicioSimulacao = clock();
				//cout << endl;
				char stringIdSimulacao[TAMANHO_STRINGS_AUXILIARES];
				sprintf(stringIdSimulacao, "%d", indice);
				string pasta = pastaSaida;
				pasta += "Simulacao_";
				pasta += stringIdSimulacao;
				pasta += SEPARADOR;
				simulacao = new Simulacao(idMonteCarlo, indice, parametros, pasta, &saidasSimulacoes[indice], quantLotes);
				simulacaoConcluida = simulacao->inicioSimulacao();
				delete (simulacao);
				//clock_t tempoFimSimulacao = clock();
				//double tempo = (double) (tempoFimSimulacao - tempoInicioSimulacao) / CLOCKS_PER_SEC;
				if (simulacaoConcluida == true) {
					saidasSimulacoes[indice].validade = true;
					//cout << endl << "Monte Carlo:" << setw(ESPACAMENTO_COUT) << idMonteCarlo << " Simulacao:" << setw(ESPACAMENTO_COUT) << indice << " Terminou! Tempo: " << tempo << "s" << endl;
				} else {
					//cout << endl << "\rMonte Carlo:" << setw(ESPACAMENTO_COUT) << idMonteCarlo << " Simulacao:" << setw(ESPACAMENTO_COUT) << indice << " Reiniciou! Tempo: " << tempo << "s" << endl;
					saidasSimulacoes[indice].zero();
					contadorTentativasSimulacao++;
					if (contadorTentativasSimulacao >= MAXIMO_TENTATIVAS_SIMULACAO) {
						//cout << endl << "ERRO! Impossivel Concluir Simulacao " << indice << " de Monte Carlo " << idMonteCarlo << endl;
						cout << -1 << endl;
						simulacaoConcluida = true;
					}
				}
			}
		}
	}

};

#endif
