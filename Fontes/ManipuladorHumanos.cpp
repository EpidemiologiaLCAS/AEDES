#ifndef _MANIPULADORHUMANOS_
#define _MANIPULADORHUMANOS_

#include "Lista.cpp"
#include "Humano.cpp"
#include "Parametros.cpp"
#include "Quadra.cpp"
#include "ListaHumanos.cpp"

class ManipuladorHumanos {
public:

	ListaHumanos* listaHumanos;
	int contadorIDs, quantLotes;
	Parametros* parametros;
	Quadra* quadra;

	ManipuladorHumanos(Parametros* parametros, Quadra* quadra, int quantLotes) {
		this->contadorIDs = 0;
		this->quantLotes = quantLotes;
		this->quadra = quadra;
		this->parametros = parametros;
		this->listaHumanos = new ListaHumanos();
	}

	~ManipuladorHumanos() {
		delete (listaHumanos);
	}

	void insercaoHumanos(int cicloAtual) {
		FOR_INT(idLote, 0, quantLotes, 1)
		{
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_1(idLote)) {
				insercao(INFECTADO, 1, QUANTIDADE_HUMANOS_1(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_2(idLote)) {
				insercao(INFECTADO, 2, QUANTIDADE_HUMANOS_2(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_3(idLote)) {
				insercao(INFECTADO, 3, QUANTIDADE_HUMANOS_3(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_4(idLote)) {
				insercao(INFECTADO, 4, QUANTIDADE_HUMANOS_4(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_5(idLote)) {
				insercao(INFECTADO, 5, QUANTIDADE_HUMANOS_5(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_S(idLote)) {
				insercao(SUSCETIVEL, 0, QUANTIDADE_HUMANOS_S(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_1(idLote)) {
				insercao(RECUPERADO, 1, QUANTIDADE_HUMANOS_RECUPERADOS_1(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_2(idLote)) {
				insercao(RECUPERADO, 2, QUANTIDADE_HUMANOS_RECUPERADOS_2(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_3(idLote)) {
				insercao(RECUPERADO, 3, QUANTIDADE_HUMANOS_RECUPERADOS_3(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_4(idLote)) {
				insercao(RECUPERADO, 4, QUANTIDADE_HUMANOS_RECUPERADOS_4(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_5(idLote)) {
				insercao(RECUPERADO, 5, QUANTIDADE_HUMANOS_RECUPERADOS_5(idLote), idLote);
			}
		}
	}

	void movimentacao(int tipoMovimentacao) {
		FOR_HUMANO(listaHumanos->lista, i)
		{
			Humano* humano = i->elementoLista;
			switch (tipoMovimentacao) {
			case CASA: {
				LISTA_HUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).buscaRemocaoLista(humano);
				humano->setLoteAtualPosicaoAtualLoteInicialPosicaoInicial();
				LISTA_HUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).insercaoLista(humano);
			}
				break;
			case OUTRO: {
				if (randomizarPercentual() <= 0.5) {
					LISTA_HUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).buscaRemocaoLista(humano);
					do {
						humano->setPosicaoAtual(rand() % LINHAS_LOTE(humano->idLoteAtual), rand() % COLUNAS_LOTE(humano->idLoteAtual));
					} while (LISTA_HUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).tamanhoLista >= CAPACIDADE_MAXIMA_POSICAO_HUMANOS(humano->idLoteAtual));
					LISTA_HUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).insercaoLista(humano);
				} else {
					if (LISTA_VIZINHANCA_HUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).tamanhoLista > 0) {
						int indiceVizinhanca = rand() % LISTA_VIZINHANCA_HUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).tamanhoLista;
						ElementoLista<Conexao*>* dest = LISTA_VIZINHANCA_HUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).buscaPosicao(indiceVizinhanca);
						Posicao posicaoVizinhanca = dest->elementoLista->destino;
						int idLoteVizinhanca = dest->elementoLista->idLoteDestino;
						LISTA_HUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).buscaRemocaoLista(humano);
						humano->setLoteAtualPosicaoAtual(idLoteVizinhanca, posicaoVizinhanca.x, posicaoVizinhanca.y);
						LISTA_HUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).insercaoLista(humano);
					}
				}
			}
				break;
			}
		}
	}

	void conclusaoCiclo() {
		FOR_HUMANO(listaHumanos->lista, i)
		{
			Humano* humano = i->elementoLista;
			if (humano->contagemCiclosPeriodos == 0) {
				switch (humano->saude) {
				case LATENTE: {
					humano->saude = INFECTADO;
					humano->contagemCiclosPeriodos = CICLOS_INFECTANTE_HUMANO(humano->idLoteAtual);
				}
					break;
				case INFECTADO: {
					humano->saude = IMUNIZADO;
					humano->contagemCiclosPeriodos = CICLOS_IMUNIZADO_HUMANO(humano->idLoteAtual);
				}
					break;
				case IMUNIZADO: {
					humano->saude = SUSCETIVEL;
				}
					break;
				case HEMORRAGICO: {
					humano->saude = SUSCETIVEL;
				}
					break;
				}
			} else {
				humano->contagemCiclosPeriodos--;
			}
		}
	}

	void controleNatural() {
		FOR_HUMANO(listaHumanos->lista, i)
		{
			Humano* humano = i->elementoLista;
			if (humano->saude != REMOVIDO) {
				if (randomizarPercentual() <= TAXA_CONTROLE_NATURAL_HUMANOS(humano->idLoteAtual)) {
					humano->saude = REMOVIDO;
				}
			}
		}
	}

private:

	void insercao(char saude, int sorotipo, int quantidade, int idLote) {
		FOR_INT(indice, 0, quantidade, 1)
		{
			int posicaoX, posicaoY;
			do {
				posicaoX = rand() % LINHAS_LOTE(idLote);
				posicaoY = rand() % COLUNAS_LOTE(idLote);
			} while (LISTA_HUMANOS(idLote, posicaoX, posicaoY).tamanhoLista >= CAPACIDADE_MAXIMA_POSICAO_HUMANOS(idLote));
			Humano* humano = new Humano(contadorIDs, (saude == RECUPERADO ? SUSCETIVEL : saude), (saude == RECUPERADO ? 0 : sorotipo), idLote, posicaoX, posicaoY);
			listaHumanos->lista->insercaoLista(humano);
			LISTA_HUMANOS(idLote, posicaoX, posicaoY).insercaoLista(humano);
			contadorIDs++;
			if (saude == INFECTADO) {
				humano->listaSorotiposContraidos.insercaoLista(sorotipo);
				humano->contagemCiclosPeriodos = CICLOS_INFECTANTE_HUMANO(idLote);
			}
			if (saude == RECUPERADO) {
				humano->listaSorotiposContraidos.insercaoLista(sorotipo);
			}
		}
	}

};

#endif
