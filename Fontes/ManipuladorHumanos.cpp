#ifndef _MANIPULADORHUMANOS_
#define _MANIPULADORHUMANOS_

#include "Lista.cpp"
#include "Humano.cpp"
#include "Parametros.cpp"
#include "Quadra.cpp"

class ManipuladorHumanos {
public:

    Lista<Humano*>* listaHumanos;
    int contadorIDs, quantLotes;
    Parametros* parametros;
    Quadra* quadra;

    ManipuladorHumanos(Parametros* _parametros, Quadra* _quadra, int _quantLotes) {
        contadorIDs = 0;
        quantLotes = _quantLotes;
        quadra = _quadra;
        parametros = _parametros;
        listaHumanos = new Lista<Humano*>();
    }

    ~ManipuladorHumanos() {
		listaHumanos->preDestrutor();
		delete(listaHumanos);
	}

    void insercaoHumanos(int cicloAtual) {
		FORINT(idLote, 0, quantLotes, 1) {
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_1(idLote)) {
				insercao('i', 1, QUANTIDADE_HUMANOS_1(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_2(idLote)) {
				insercao('i', 2, QUANTIDADE_HUMANOS_2(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_3(idLote)) {
				insercao('i', 3, QUANTIDADE_HUMANOS_3(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_4(idLote)) {
				insercao('i', 4, QUANTIDADE_HUMANOS_4(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_5(idLote)) {
				insercao('i', 5, QUANTIDADE_HUMANOS_5(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_S(idLote)) {
				insercao('s', 0, QUANTIDADE_HUMANOS_S(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_1(idLote)) {
				insercao('r', 1, QUANTIDADE_HUMANOS_RECUPERADOS_1(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_2(idLote)) {
				insercao('r', 2, QUANTIDADE_HUMANOS_RECUPERADOS_2(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_3(idLote)) {
				insercao('r', 3, QUANTIDADE_HUMANOS_RECUPERADOS_3(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_4(idLote)) {
				insercao('r', 4, QUANTIDADE_HUMANOS_RECUPERADOS_4(idLote), idLote);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_5(idLote)) {
				insercao('r', 5, QUANTIDADE_HUMANOS_RECUPERADOS_5(idLote), idLote);
			}			
		}
    }
    
    void movimentacao(int tipoMovimentacao) {
        FORHUMANO(listaHumanos, i) {
			Humano* humano = i->elementoLista;
            switch (tipoMovimentacao) {
				case CASA: {
					LISTAHUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).buscaRemocaoLista(humano);
					humano->setLoteAtualPosicaoAtualLoteInicialPosicaoInicial();
					LISTAHUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).insercaoLista(new ElementoLista<Humano*>(humano));
				}
				break;
				case OUTRO: {
					if (randomizarPercentual() <= 0.5) {
						LISTAHUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).buscaRemocaoLista(humano);
						do {
							humano->setPosicaoAtual(rand() % LINHASLOTE(humano->idLoteAtual), rand() % COLUNASLOTE(humano->idLoteAtual));
						} while (LISTAHUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).tamanhoLista >= CAPACIDADE_MAXIMA_POSICAO_HUMANOS(humano->idLoteAtual));
						LISTAHUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).insercaoLista(new ElementoLista<Humano*>(humano));
					} else {
						if (LISTAVIZINHANCAHUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).tamanhoLista > 0) {
							int indiceVizinhanca = rand() % LISTAVIZINHANCAHUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).tamanhoLista;
							ElementoLista<Conexao*>* dest = LISTAVIZINHANCAHUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).buscaPosicao(indiceVizinhanca);
							Posicao posicaoVizinhanca = dest->elementoLista->destino;
							int idLoteVizinhanca = dest->elementoLista->idLoteDestino;
							LISTAHUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).buscaRemocaoLista(humano);
							humano->setLoteAtualPosicaoAtual(idLoteVizinhanca, posicaoVizinhanca.x, posicaoVizinhanca.y);
							LISTAHUMANOS(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).insercaoLista(new ElementoLista<Humano*>(humano));
						}
					}
				}
				break;
            }
		}
    }

    void conclusaoCiclo() {
		FORHUMANO(listaHumanos, i) {
			Humano* humano = i->elementoLista;
			if (humano->contagemCiclosPeriodos == 0) {
				switch (humano->saude) {
					case 'l': {
						humano->saude = 'i';
						humano->contagemCiclosPeriodos = CICLOS_INFECTANTE_HUMANO(humano->idLoteAtual);
					}
					break;
					case 'i': {
						humano->saude = 'm';
						humano->contagemCiclosPeriodos = CICLOS_IMUNIZADO_HUMANO(humano->idLoteAtual);
					}
					break;
					case 'm': {
						humano->saude = 's';
					}
					break;
					case 'h': {
						humano->saude = 's';
					}
					break;
				}
			} else {
				humano->contagemCiclosPeriodos--;
			}
		}
    }
    
    void controleNatural() {
		FORHUMANO(listaHumanos, i) {
			Humano* humano = i->elementoLista;
			if (humano->saude != 'r') {
				if (randomizarPercentual() <= TAXA_CONTROLE_NATURAL_HUMANOS(humano->idLoteAtual)) {
					humano->saude = 'r';
				}
			}
		}
    }

private:

    void insercao(char saude, int sorotipo, int quantidade, int idLote) {
		FORINT(indice, 0, quantidade, 1) {
			int posicaoX, posicaoY;
			do {
				posicaoX = rand() % LINHASLOTE(idLote);
				posicaoY = rand() % COLUNASLOTE(idLote);
			} while (LISTAHUMANOS(idLote, posicaoX, posicaoY).tamanhoLista >= CAPACIDADE_MAXIMA_POSICAO_HUMANOS(idLote));
			Humano* humano = new Humano(contadorIDs, (saude == 'r' ? 's' : saude), (saude == 'r' ? 0 : sorotipo), idLote, posicaoX, posicaoY);   
			listaHumanos->insercaoLista(new ElementoLista<Humano*>(humano));
			LISTAHUMANOS(idLote, posicaoX, posicaoY).insercaoLista(new ElementoLista<Humano*>(humano));
			contadorIDs++;
			if (saude == 'i') {
				humano->listaSorotiposContraidos.insercaoLista(new ElementoLista<int>(sorotipo));
				humano->contagemCiclosPeriodos = CICLOS_INFECTANTE_HUMANO(idLote);
			}
			if (saude == 'r') {
				humano->listaSorotiposContraidos.insercaoLista(new ElementoLista<int>(sorotipo));
			}
		}
    }
    
};

#endif
