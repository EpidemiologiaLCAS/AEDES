#ifndef SIMULACAO
#define SIMULACAO

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

class Simulacao {
public:

    int idMonteCarlo, idSimulacao, quantLotes;
    ManipuladorMosquitos* manipuladorMosquitos;
    ManipuladorHumanos* manipuladorHumanos;
    string pastaSaida;
    SaidasSimulacao* saidas;
    Parametros* parametros;
    Quadra* quadra;

    Simulacao(int _idMonteCarlo, int _idSimulacao, Parametros* _parametros, string pasta, Saidas* _saidaSimulacao, int _quantLotes) {
        idMonteCarlo = _idMonteCarlo;
        idSimulacao = _idSimulacao;
        parametros = _parametros;
        quantLotes = _quantLotes;
        quadra = new Quadra(quantLotes, parametros);
        FORINT(i, 0, quantLotes, 1) {
			quadra->adicionarLote(i, NUMERO_LINHAS_AMBIENTE(i), NUMERO_COLUNAS_AMBIENTE(i));
		}
        manipuladorMosquitos = new ManipuladorMosquitos(parametros, quadra, quantLotes);
        manipuladorHumanos = new ManipuladorHumanos(parametros, quadra, quantLotes);
        pastaSaida = pasta;
        saidas = new SaidasSimulacao(manipuladorMosquitos, manipuladorHumanos, quadra, pastaSaida, idMonteCarlo, idSimulacao, _saidaSimulacao, parametros, quantLotes);
		quadra->criacaoConexoesHumanos();
		quadra->criacaoConexoesMosquitos();
		quadra->definicaoControleQuimicoNaoAlados();
        quadra->definicaoControleQuimicoAlados();
		quadra->definicaoControleMecanicoNaoAlados();
    }    
    
    ~Simulacao() {
		delete(quadra);
		delete(manipuladorHumanos);
		delete(manipuladorMosquitos);
		delete(saidas);
    }

    bool inicioSimulacao() {
        int maxCiclos = NUMERO_CICLOS_SIMULACAO + 1;
		saidas->gerarSaidas(0);
		FORINT(cicloAtual, 1, maxCiclos, 1) {
			if (inicioCiclo(cicloAtual) == false) {
				return false;
			}
		}
		return true;
    }

private:

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

    void inicioPeriodo(int cicloAtual, int periodo) {
        manipuladorHumanos->movimentacao(1);
        switch (periodo) {
			case 1: {
				FORINT(subciclo, 1, NUMERO_SUBCICLOS + 1, 1) {
					inicioSubCiclo(cicloAtual, 1, subciclo);
				}
			}
			break;
			case 2: {
				FORINT(subciclo, 1, NUMERO_SUBCICLOS + 1, 1) {
					inicioSubCiclo(cicloAtual, 2, subciclo);
				}
			}
			break;
			case 3: {
				FORINT(subciclo, 1, NUMERO_SUBCICLOS + 1, 1) {
					inicioSubCiclo(cicloAtual, 3, subciclo);
				}
				manipuladorHumanos->movimentacao(0);
			}
			break;
        }
        manipuladorMosquitos->voosLevy();
    }

    void inicioSubCiclo(int cicloAtual, int periodo, int subciclo) {
        if (periodo != 3) {
            manipuladorMosquitos->movimentacaoDiurna();
        } else {
            manipuladorMosquitos->movimentacaoNoturna();
        }
        //saidas->saidaMosquitos(cicloAtual, periodo, subciclo);
    }

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
