#ifndef _SIMULACAO_
#define _SIMULACAO_

#include "Quadra.cpp"
#include "ManipuladorMosquitos.cpp"
#include "ManipuladorHumanos.cpp"
#include "SaidasSimulacao.cpp"
#include "Parametros.cpp"
#include "Saidas.cpp"
#include "Vetor.cpp"
#include "Mosquito.cpp"
#include "MosquitoMacho.cpp"
#include "MosquitoFemea.cpp"

// Classe que representa uma simulação individual
class Simulacao {
public:

	int idMonteCarlo; // id da simulação Monte Carlo
	int idSimulacao; // id da simulação individual
	int quantLotes; // quantidade de lotes
	ManipuladorMosquitos* manipuladorMosquitos; // manipulador de agentes mosquitos
	ManipuladorHumanos* manipuladorHumanos; // manipulador de agentes humanos
	string pastaSaida; // pasta de saída
	SaidasSimulacao* saidas; // saídas das simulações individuais
	Parametros* parametros; // parâmetros
	Quadra* quadra; // quadra

	Simulacao(int idMonteCarlo, int idSimulacao, Parametros* parametros, string pastaSaida, Saidas* saidaSimulacao, int quantLotes) {
		this->idMonteCarlo = idMonteCarlo;
		this->idSimulacao = idSimulacao;
		this->parametros = parametros;
		this->quantLotes = quantLotes;
		this->quadra = new Quadra(quantLotes, parametros);
		FOR_INT(i, 0, quantLotes, 1)
		{
			quadra->adicionarLote(i, NUMERO_LINHAS_AMBIENTE(i), NUMERO_COLUNAS_AMBIENTE(i));
		}
		this->manipuladorMosquitos = new ManipuladorMosquitos(parametros, quadra, quantLotes);
		this->manipuladorHumanos = new ManipuladorHumanos(parametros, quadra, quantLotes);
		this->pastaSaida = pastaSaida;
		this->saidas = new SaidasSimulacao(manipuladorMosquitos, manipuladorHumanos, quadra, pastaSaida, idMonteCarlo, idSimulacao, saidaSimulacao, parametros, quantLotes);
		quadra->criacaoConexoesHumanos();
		quadra->criacaoConexoesMosquitos();
		quadra->definicaoControleQuimicoNaoAlados();
		quadra->definicaoControleQuimicoAlados();
		quadra->definicaoControleMecanicoNaoAlados();
		quadra->criacaoRaiosPercepcaoHumanos();
		quadra->criacaoRaiosPercepcaoMosquitosMachos();
		quadra->criacaoRaiosPercepcaoCriadouros();
		quadra->leituraCoordenadasGeo();
		quadra->criacaoCriadouros();
	}

	~Simulacao() {
		delete (quadra);
		delete (manipuladorHumanos);
		delete (manipuladorMosquitos);
		delete (saidas);
	}

	// Inicia uma simulação individual
	bool inicioSimulacao() {
		int maxCiclos = NUMERO_CICLOS_SIMULACAO + 1;
		saidas->gerarSaidas(0);
		FOR_INT(cicloAtual, 1, maxCiclos, 1)
		{
			if (inicioCiclo(cicloAtual) == false) {
				return false;
			}
		}
		return true;
	}

private:

	// Inicia um ciclo de uma simulação individual
	bool inicioCiclo(int cicloAtual) {
		if (!verificacaoLimiteMosquitos()) {
			return false;
		}
		manipuladorHumanos->insercaoHumanos(cicloAtual);
		inicioPeriodo(cicloAtual, 1);
		inicioPeriodo(cicloAtual, 2);
		inicioPeriodo(cicloAtual, 3);
		manipuladorMosquitos->geracao();
		manipuladorMosquitos->transformacoes();
		manipuladorMosquitos->conclusaoCiclo();
		manipuladorMosquitos->controleNatural(cicloAtual);
		manipuladorMosquitos->controleMecanico(cicloAtual);
		manipuladorMosquitos->controleQuimico(cicloAtual);
		manipuladorHumanos->conclusaoCiclo();
		manipuladorHumanos->controleNatural();
		saidas->gerarSaidas(cicloAtual);
		return true;
	}

	// Inicia um período de um ciclo de uma simulação individual
	void inicioPeriodo(int cicloAtual, int periodo) {
		manipuladorHumanos->movimentacao(OUTRO);
		switch (periodo) {
		case 1: {
			FOR_INT(subciclo, 1, NUMERO_SUBCICLOS + 1, 1)
			{
				inicioSubCiclo(cicloAtual, 1, subciclo);
			}
		}
			break;
		case 2: {
			FOR_INT(subciclo, 1, NUMERO_SUBCICLOS + 1, 1)
			{
				inicioSubCiclo(cicloAtual, 2, subciclo);
			}
		}
			break;
		case 3: {
			FOR_INT(subciclo, 1, NUMERO_SUBCICLOS + 1, 1)
			{
				inicioSubCiclo(cicloAtual, 3, subciclo);
			}
			manipuladorHumanos->movimentacao(CASA);
		}
			break;
		}
		manipuladorMosquitos->voosLevy();
	}

	// Inicia um subciclo de um período de um ciclo de uma simulação individual
	void inicioSubCiclo(int cicloAtual, int periodo, int subciclo) {
		if (periodo != 3) {
			manipuladorMosquitos->movimentacaoDiurna();
		} else {
			manipuladorMosquitos->movimentacaoNoturna();
		}
		//saidas->saidaMosquitos(cicloAtual, periodo, subciclo);
	}

	// Retorna verdadeiro se o número atual de agentes mosquitos é maior do que o máximo permitido
	bool verificacaoLimiteMosquitos() {
		if (manipuladorMosquitos->listaMosquitos->tamanhoLista > MAXIMO_MOSQUITOS) {
			string comando = COMANDO_EXCLUIR_PASTA;
			comando += pastaSaida;
			system(comando.c_str());
			return false;
		}
		return true;
	}

};

#endif
