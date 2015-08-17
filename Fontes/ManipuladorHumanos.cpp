#ifndef MANIPULADORHUMANOS
#define MANIPULADORHUMANOS

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
				insercao(1, QUANTIDADE_HUMANOS_1(idLote), idLote, 1);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_2(idLote)) {
				insercao(2, QUANTIDADE_HUMANOS_2(idLote), idLote, 1);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_3(idLote)) {
				insercao(3, QUANTIDADE_HUMANOS_3(idLote), idLote, 1);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_4(idLote)) {
				insercao(4, QUANTIDADE_HUMANOS_4(idLote), idLote, 1);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_5(idLote)) {
				insercao(5, QUANTIDADE_HUMANOS_5(idLote), idLote, 1);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_S(idLote)) {
				insercao(0, QUANTIDADE_HUMANOS_S(idLote), idLote, 1);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_1(idLote)) {
				insercao(1, QUANTIDADE_HUMANOS_RECUPERADOS_1(idLote), idLote, 2);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_2(idLote)) {
				insercao(2, QUANTIDADE_HUMANOS_RECUPERADOS_2(idLote), idLote, 2);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_3(idLote)) {
				insercao(3, QUANTIDADE_HUMANOS_RECUPERADOS_3(idLote), idLote, 2);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_4(idLote)) {
				insercao(4, QUANTIDADE_HUMANOS_RECUPERADOS_4(idLote), idLote, 2);
			}
			if (cicloAtual == CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_5(idLote)) {
				insercao(5, QUANTIDADE_HUMANOS_RECUPERADOS_5(idLote), idLote, 2);
			}			
		}
    }
    
    void movimentacao(int destino) {
        FORHUMANO(listaHumanos, i) {
            switch (destino) {
				case 0: {
					quadra->lotes[i->elementoLista->idLoteAtual]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaHumanos.buscaRemocaoLista(i->elementoLista);
					i->elementoLista->posicaoAtual.x = i->elementoLista->posicaoInicial.x;
					i->elementoLista->posicaoAtual.y = i->elementoLista->posicaoInicial.y;
					i->elementoLista->idLoteAtual = i->elementoLista->idLoteInicial;
					quadra->lotes[i->elementoLista->idLoteAtual]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaHumanos.insercaoLista(new ElementoLista<Humano*>(i->elementoLista));
				}
				break;
				case 1: {
					if (randomizarPercentual() <= 0.5) {
						quadra->lotes[i->elementoLista->idLoteAtual]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaHumanos.buscaRemocaoLista(i->elementoLista);
						do {
							i->elementoLista->posicaoAtual.x = rand() % quadra->lotes[i->elementoLista->idLoteAtual]->lote->linhasMatriz;
							i->elementoLista->posicaoAtual.y = rand() % quadra->lotes[i->elementoLista->idLoteAtual]->lote->colunasMatriz;
						} while (quadra->lotes[i->elementoLista->idLoteAtual]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaHumanos.tamanhoLista >= CAPACIDADE_MAXIMA_POSICAO_HUMANOS(i->elementoLista->idLoteAtual));
						quadra->lotes[i->elementoLista->idLoteAtual]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaHumanos.insercaoLista(new ElementoLista<Humano*>(i->elementoLista));
					} else {
						if (quadra->lotes[i->elementoLista->idLoteAtual]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaVizinhancaHumanos.tamanhoLista > 0) {
							int r = rand() % quadra->lotes[i->elementoLista->idLoteAtual]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaVizinhancaHumanos.tamanhoLista;
							ElementoLista<Conexao*>* dest = quadra->lotes[i->elementoLista->idLoteAtual]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaVizinhancaHumanos.buscaPosicao(r);
							Posicao pos = dest->elementoLista->destino;
							quadra->lotes[i->elementoLista->idLoteAtual]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaHumanos.buscaRemocaoLista(i->elementoLista);
							i->elementoLista->posicaoAtual.x = pos.x;
							i->elementoLista->posicaoAtual.y = pos.y;
							i->elementoLista->idLoteAtual = dest->elementoLista->idLoteDestino;
							quadra->lotes[i->elementoLista->idLoteAtual]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaHumanos.insercaoLista(new ElementoLista<Humano*>(i->elementoLista));
						}
					}
				}
				break;
            }
		}
    }

    void conclusaoCiclo() {
		FORHUMANO(listaHumanos, i) {
			if (i->elementoLista->contagemCiclosPeriodos == 0) {
				switch (i->elementoLista->saude) {
					case 'l': {
						i->elementoLista->saude = 'i';
						i->elementoLista->contagemCiclosPeriodos = CICLOS_INFECTANTE_HUMANO(i->elementoLista->idLoteAtual);
					}
					break;
					case 'i': {
						i->elementoLista->saude = 'm';
						i->elementoLista->contagemCiclosPeriodos = CICLOS_IMUNIZADO_HUMANO(i->elementoLista->idLoteAtual);
					}
					break;
					case 'm': {
						i->elementoLista->saude = 's';
					}
					break;
					case 'h': {
						i->elementoLista->saude = 's';
					}
					break;
				}
			} else {
				i->elementoLista->contagemCiclosPeriodos = (i->elementoLista->contagemCiclosPeriodos - 1);
			}
		}
    }
    
    void controleNatural() {
		FORHUMANO(listaHumanos, i) {
			if (i->elementoLista->saude != 'r') {
				if (randomizarPercentual() <= TAXA_CONTROLE_NATURAL_HUMANOS(i->elementoLista->idLoteAtual)) {
					i->elementoLista->saude = 'r';
				}
			}
		}
    }

private:

    void insercaoHumanoSaudavelOuInfectado(char saude, int sorotipo, int idLote) {
		int posicaoX, posicaoY;
		do {
			posicaoX = rand() % quadra->lotes[idLote]->lote->linhasMatriz;
			posicaoY = rand() % quadra->lotes[idLote]->lote->colunasMatriz;
		} while (quadra->lotes[idLote]->lote->matriz[posicaoX][posicaoY].listaHumanos.tamanhoLista >= CAPACIDADE_MAXIMA_POSICAO_HUMANOS(idLote));
		Humano* humano = new Humano(contadorIDs, saude, sorotipo, idLote, posicaoX, posicaoY);   
		ElementoLista<Humano*>* a1 = new ElementoLista<Humano*>(humano);
		listaHumanos->insercaoLista(a1);
		quadra->lotes[idLote]->lote->matriz[posicaoX][posicaoY].listaHumanos.insercaoLista(new ElementoLista<Humano*>(humano));
		contadorIDs++;
		if (saude == 'i') {
			humano->listaSorotiposContraidos.insercaoLista(new ElementoLista<int>(sorotipo));
			humano->contagemCiclosPeriodos = CICLOS_INFECTANTE_HUMANO(idLote);
		}
    }
    
    void insercaoHumanoRecuperado(int sorotipo, int idLote) {
		int posicaoX, posicaoY;
		do {
			posicaoX = rand() % quadra->lotes[idLote]->lote->linhasMatriz;
			posicaoY = rand() % quadra->lotes[idLote]->lote->colunasMatriz;
		} while (quadra->lotes[idLote]->lote->matriz[posicaoX][posicaoY].listaHumanos.tamanhoLista >= CAPACIDADE_MAXIMA_POSICAO_HUMANOS(idLote));
		Humano* humano = new Humano(contadorIDs, 's', 0, idLote, posicaoX, posicaoY);   
		ElementoLista<Humano*>* a1 = new ElementoLista<Humano*>(humano);
		listaHumanos->insercaoLista(a1);
		quadra->lotes[idLote]->lote->matriz[posicaoX][posicaoY].listaHumanos.insercaoLista(new ElementoLista<Humano*>(humano));
		contadorIDs++;
		humano->listaSorotiposContraidos.insercaoLista(new ElementoLista<int>(sorotipo));
    }


    void insercao(int sorotipo, int quantidade, int idLote, int tipo) {
		if (tipo == 1) {
			char saude = (sorotipo == 0 ? 's' : 'i');
			FORINT(indice, 0, quantidade, 1) {
				insercaoHumanoSaudavelOuInfectado(saude, sorotipo, idLote);
			}
		} else {
			FORINT(indice, 0, quantidade, 1) {
				insercaoHumanoRecuperado(sorotipo, idLote);
			}
		}
    }
    
};

#endif
