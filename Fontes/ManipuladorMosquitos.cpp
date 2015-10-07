#ifndef MANIPULADORMOSQUITOS
#define MANIPULADORMOSQUITOS

#include "Lista.cpp"
#include "ElementoLista.cpp"
#include "Mosquito.cpp"
#include "MosquitoMacho.cpp"
#include "MosquitoFemea.cpp"
#include "Parametros.cpp"
#include "Quadra.cpp"

class ManipuladorMosquitos {
public:

	Lista<Mosquito*>* listaMosquitos;
    int contadorAcasalamentosCiclo, contadorAcasalamentosTotal, contadorIDs, quantLotes;
    Parametros* parametros;
    Quadra* quadra;

    ManipuladorMosquitos(Parametros* _parametros, Quadra* _quadra, int _quantLotes) {
        parametros = _parametros;
        quadra = _quadra;
        quantLotes = _quantLotes;
        listaMosquitos = new Lista<Mosquito*>();
        contadorAcasalamentosCiclo = 0;
        contadorAcasalamentosTotal = 0;       
		contadorIDs = 0;
		criacao();
    }

    ~ManipuladorMosquitos() {
		listaMosquitos->preDestrutor();
		delete(listaMosquitos);
	}
    
    void insercaoMosquitos(int id, char sexo, char saudeWolbachia, char saudeDengue, int sorotipo, char fase, int idLote, int idade) {
        int lx, ly;
        Mosquito* mosquito = NULL;
        do {
           lx = rand() % LINHASLOTE(idLote);
           ly = rand() % COLUNASLOTE(idLote); 
        } while(POSICAOLOTE(idLote, lx, ly).quantidadeTotalMosquitosPosicao() >= CAPACIDADE_MAXIMA_POSICAO_MOSQUITOS(idLote));
        if (sexo == 'm') {
			mosquito = new MosquitoMacho(id, saudeWolbachia, fase, idade, idLote, lx, ly);		
		} else {
			mosquito = new MosquitoFemea(id, saudeWolbachia, saudeDengue, sorotipo, fase, idade, idLote, lx, ly);
		}
		listaMosquitos->insercaoLista(new ElementoLista<Mosquito*>(mosquito));
        switch (fase) {
           case 'o': {
			   LISTAOVOS(idLote, lx, ly).insercaoLista(new ElementoLista<Mosquito*>(mosquito));
           }
           break;
           default: {
                switch (sexo) {
					case 'm': {
						LISTAMACHOS(idLote, lx, ly).insercaoLista(new ElementoLista<Mosquito*>(mosquito));
					}
						break;
					case 'f': {
						LISTAFEMEAS(idLote, lx, ly).insercaoLista(new ElementoLista<Mosquito*>(mosquito));
					}
						break;
                }
            }
            break;
        }
    }

    void criacao() {
		FORINT(idLote, 0, quantLotes, 1) {
			FORINT(indice1, 0, 17, 1) {
				switch (indice1) {
					case 0: {
						FORINT(i, 0, QUANTIDADE_MS1(idLote), 1)
							insercaoMosquitos(contadorIDs++, 'm', 's', 's', 0, 'o', idLote, IDADE_OVOS(idLote));
					}
						break;
					case 1: {
						FORINT(i, 0, QUANTIDADE_MS2(idLote), 1)
							insercaoMosquitos(contadorIDs++, 'm', 's', 's', 0, 'a', idLote, IDADE_MACHOS_ATIVOS_SAUDAVEIS(idLote));
					}
						break;
					case 2: {
						FORINT(i, 0, QUANTIDADE_MS3(idLote), 1)
							insercaoMosquitos(contadorIDs++, 'm', 's', 's', 0, 'd', idLote, IDADE_MACHOS_DECADENTES_SAUDAVEIS(idLote));
					}
						break;
					case 3: {
						FORINT(i, 0, QUANTIDADE_FS1(idLote), 1)
							insercaoMosquitos(contadorIDs++, 'f', 's', 's', 0, 'o', idLote, IDADE_OVOS(idLote));
					}
						break;
					case 4: {
						FORINT(i, 0, QUANTIDADE_FS2(idLote), 1)
							insercaoMosquitos(contadorIDs++, 'f', 's', 's', 0, 'a', idLote, IDADE_FEMEAS_ATIVAS_SAUDAVEIS(idLote));
					}
						break;
					case 5: {
						FORINT(i, 0, QUANTIDADE_FS3(idLote), 1)
							insercaoMosquitos(contadorIDs++, 'f', 's', 's', 0, 'd', idLote, IDADE_FEMEAS_DECADENTES_SAUDAVEIS(idLote));
					}
						break;
					case 6: {
						FORINT(i, 0, QUANTIDADE_MI1(idLote), 1)
							insercaoMosquitos(contadorIDs++, 'm', 'i', 's', 0, 'o', idLote, IDADE_OVOS(idLote));
					}
						break;
					case 7: {
						FORINT(i, 0, QUANTIDADE_MI2(idLote), 1)
							insercaoMosquitos(contadorIDs++, 'm', 'i', 's', 0, 'a', idLote, IDADE_MACHOS_ATIVOS_WOLBACHIA(idLote));
					}
						break;
					case 8: {
						FORINT(i, 0, QUANTIDADE_MI3(idLote), 1)
							insercaoMosquitos(contadorIDs++, 'm', 'i', 's', 0, 'd', idLote, IDADE_MACHOS_DECADENTES_WOLBACHIA(idLote));
					}
						break;
					case 9: {
						FORINT(i, 0, QUANTIDADE_FI1(idLote), 1)
							insercaoMosquitos(contadorIDs++, 'f', 'i', 's', 0, 'o', idLote, IDADE_OVOS(idLote));
					}
						break;
					case 10: {
						FORINT(i, 0, QUANTIDADE_FI2(idLote), 1)
							insercaoMosquitos(contadorIDs++, 'f', 'i', 's', 0, 'a', idLote, IDADE_FEMEAS_ATIVAS_WOLBACHIA(idLote));
					}
						break;
					case 11: {
						FORINT(i, 0, QUANTIDADE_FI3(idLote), 1)
							insercaoMosquitos(contadorIDs++, 'f', 'i', 's', 0, 'd', idLote, IDADE_FEMEAS_DECADENTES_WOLBACHIA(idLote));
					}
						break;
					case 12: {
						FORINT(i, 0, QUANTIDADE_FDI1(idLote), 1)
							insercaoMosquitos(contadorIDs++, 'f', 's', 'i', 1, 'a', idLote, IDADE_FEMEAS_ATIVAS_SAUDAVEIS(idLote));
					}
						break;
					case 13: {
						FORINT(i, 0, QUANTIDADE_FDI2(idLote), 1)
							insercaoMosquitos(contadorIDs++, 'f', 's', 'i', 2, 'a', idLote, IDADE_FEMEAS_ATIVAS_SAUDAVEIS(idLote));
					}
						break;
					case 14: {
						FORINT(i, 0, QUANTIDADE_FDI3(idLote), 1)
							insercaoMosquitos(contadorIDs++, 'f', 's', 'i', 3, 'a', idLote, IDADE_FEMEAS_ATIVAS_SAUDAVEIS(idLote));
					}
						break;
					case 15: {
						FORINT(i, 0, QUANTIDADE_FDI4(idLote), 1)
							insercaoMosquitos(contadorIDs++, 'f', 's', 'i', 4, 'a', idLote, IDADE_FEMEAS_ATIVAS_SAUDAVEIS(idLote));
					}
						break;
					case 16: {
						FORINT(i, 0, QUANTIDADE_FDI5(idLote), 1)
							insercaoMosquitos(contadorIDs++, 'f', 's', 'i', 5, 'a', idLote, IDADE_FEMEAS_ATIVAS_SAUDAVEIS(idLote));
					}
						break;
				}
			}
		}
    }

    void movimentacaoDiurna() {
        FORMOSQUITO(listaMosquitos, i) {
			Mosquito* mosquito = i->elementoLista;
            if (((mosquito->fase == 'a') || (mosquito->fase == 'd')) && (mosquito->vida)) {
                movimentacao(mosquito);
            }
        }
    }

    void movimentacaoNoturna() {
		FORINT(idLote, 0, quantLotes, 1) {
			int totalMosquitos = 0;
			Lista<Mosquito*> lista;
			FORMOSQUITO(listaMosquitos, i) {
				Mosquito* mosquito = i->elementoLista;
				if (((mosquito->fase == 'a') || (mosquito->fase == 'd')) && (mosquito->idLoteAtual == idLote))
					++totalMosquitos;
			}
			int quantidadeMosquitosMovimentacao = totalMosquitos * PORCENTAGEM_MOVIMENTACAO_NOTURNA_MOSQUITOS(idLote);
			while (quantidadeMosquitosMovimentacao != 0) {
				FORMOSQUITO(listaMosquitos, i) {
					Mosquito* mosquito = i->elementoLista;
					if (((mosquito->fase == 'a') || (mosquito->fase == 'd')) && (mosquito->idLoteAtual == idLote)) {
						if (randomizarPercentual() <= 0.5) {
							lista.insercaoLista(new ElementoLista<Mosquito*>(mosquito));
							--quantidadeMosquitosMovimentacao;
						}
					}
					if (quantidadeMosquitosMovimentacao == 0)
						break;
				}
			}
			FOR2MOSQUITO(lista, i) {
				Mosquito* mosquito = i->elementoLista;
				if (((mosquito->fase == 'a') || (mosquito->fase == 'd')) && (mosquito->idLoteAtual == idLote))  {
				   movimentacao(mosquito);
				}
			}
		}
    }

    void voosLevy() {
        FORMOSQUITO(listaMosquitos, i) {
			Mosquito* mosquito = i->elementoLista;
			if (mosquito->sexo == 'f') {
				MosquitoFemea* mosquitoFemea = (MosquitoFemea*) (mosquito);
				if ((mosquitoFemea->tipoAcasalamento != 'n') && (!mosquitoFemea->alimento) && (mosquitoFemea->vida) && ((mosquitoFemea->fase == 'a') || (mosquitoFemea->fase == 'd'))) {
					if (randomizarPercentual() <= PROBABILIDADE_VOO_LEVY_ANTES_PROCURA_ALIMENTO(mosquitoFemea->idLoteAtual)) {
						vooLevy(mosquito, CURTO);
					}
				}
			}
        }
    }

    void geracao() {
        FORMOSQUITO(listaMosquitos, i) {
			Mosquito* mosquito = i->elementoLista;
            if (mosquito->sexo == 'f') {
				MosquitoFemea* mosquitoFemea = (MosquitoFemea*) (mosquito);
				if (((mosquitoFemea->fase == 'a') || (mosquitoFemea->fase == 'd')) && (mosquitoFemea->tipoAcasalamento != 'n')) {
					if (mosquitoFemea->ciclosGestacao == -1) {
						if (mosquitoFemea->contadorCiclosEntrePosturas != INTERVALO_ENTRE_POSTURAS_FEMEA(mosquitoFemea->idLoteAtual)) {
							mosquitoFemea->contadorCiclosEntrePosturas++;
						} else {
							mosquitoFemea->ciclosGestacao = 0;
						}
					}
					else {
						if (mosquitoFemea->ciclosGestacao < CICLOS_GESTACAO(mosquitoFemea->idLoteAtual)) {
							mosquitoFemea->ciclosGestacao++;
						} else {
							mosquitoFemea->contadorCiclosEntrePosturas = 0;
							mosquitoFemea->ciclosGestacao = -1;
							mosquitoFemea->contadorPosturas++;
							if ((mosquitoFemea->tipoProle != 'e') || (mosquitoFemea->alimento)) {
								if (randomizarPercentual() <= PROBABILIDADE_VOO_LEVY_ANTES_POSTURA(mosquitoFemea->idLoteAtual)) {
									vooLevy(mosquito, LONGO);
								}
								geracao6Casos(mosquito);
							}
						}
					}	
				}
			}
        }
    }

    void transformacoes() {
        transformacaoOvos();
        transformacaoLarvas();
        transformacaoPupas();
        transformacaoAlados();
    }

    void controleNatural(int cicloAtual) {
        remocaoMosquitosIdade();
        remocaoMosquitosControleNatural(cicloAtual);
    }
    
    void controleQuimico(int cicloAtual) {
        remocaoMosquitosControleQuimicoNaoAlados(cicloAtual);
        remocaoMosquitosControleQuimicoAlados(cicloAtual);
    }
    
    void controleMecanico(int cicloAtual) {
        remocaoMosquitosControleMecanicoNaoAlados(cicloAtual);
    }

    void conclusaoCiclo() {
        FORMOSQUITO(listaMosquitos, i) {
			Mosquito* mosquito = i->elementoLista;
            mosquito->idade++;
            if (mosquito->sexo == 'f') {
				MosquitoFemea* mosquitoFemea = (MosquitoFemea*) (mosquito);
				if (mosquitoFemea->ciclosLatencia == 0) {
					if (mosquitoFemea->saudeDengue == 'l') {
						mosquitoFemea->saudeDengue = 'i';
					}
				} else {
					mosquitoFemea->ciclosLatencia--;
				}
			}
        }
    }

private:

    void vooLevy(Mosquito* mosquito, int tipoVoo) {
        int px, py;
        switch (tipoVoo) {
			case CURTO: {
				px = AMPLITUDE_VOO_LEVY_CURTO(mosquito->idLoteAtual);
				py = AMPLITUDE_VOO_LEVY_CURTO(mosquito->idLoteAtual);
			}
			break;
			case LONGO: {
				px = AMPLITUDE_VOO_LEVY_LONGO(mosquito->idLoteAtual);
				py = AMPLITUDE_VOO_LEVY_LONGO(mosquito->idLoteAtual);
			}
			break;
		}
        FORINT(i, 0, TENTATIVAS_VOO_LEVY(mosquito->idLoteAtual), 1) {
            if (randomizarPercentual() <= 0.5) {
                px = -1 * px;
			}
            if (randomizarPercentual() <= 0.5) {
                py = -1 * py;
			}
			if (LIMITESLOTEP(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y, px, py)) {
				LISTAFEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
                mosquito->addPosicaoAtual(px, py);
                LISTAFEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).insercaoLista(new ElementoLista<Mosquito*>(mosquito));
                return;
            }
        }
    }

    void efetivacaoAcasalamento(Mosquito* macho, Mosquito* femea, double probabilidadeAcasalamento, char tipoAcasalamento, char prole) {
        if (randomizarPercentual() <= (TAXA_FECUNDIDADE(femea->idLoteAtual) * probabilidadeAcasalamento)) {
			MosquitoFemea* mosquitoFemea = (MosquitoFemea*) femea;
            mosquitoFemea->tipoAcasalamento = tipoAcasalamento;
            mosquitoFemea->tipoProle = prole;
            MosquitoMacho* mosquitoMacho = (MosquitoMacho*) macho;
            mosquitoMacho->contadorAcasalamentos++;
            contadorAcasalamentosCiclo++;
            contadorAcasalamentosTotal++;
        }
    }

    void acasalamento(Mosquito* macho, Mosquito* femea) {
		MosquitoMacho* mosquitoMacho = (MosquitoMacho*) macho;
        switch (mosquitoMacho->saudeWolbachia) {
			case 's': {
				switch (femea->saudeWolbachia) {
					case 's': {
						switch (mosquitoMacho->contadorAcasalamentos) {
							case 0: {
								efetivacaoAcasalamento(macho, femea, BETASS22(femea->idLoteAtual), 'a', 's');
							}
							break;
							default: {
								efetivacaoAcasalamento(macho, femea, pow(K1(femea->idLoteAtual), mosquitoMacho->contadorAcasalamentos)*(BETASS23(femea->idLoteAtual)), 'a', 's');
							}
							break;
						}
					}
					break;
					case 'i': {
						switch (mosquitoMacho->contadorAcasalamentos) {
							case 0: {
								efetivacaoAcasalamento(macho, femea, BETAIS22(femea->idLoteAtual), 'a', 'i');
							}
							break;
							default: {
								efetivacaoAcasalamento(macho, femea, pow(K1(femea->idLoteAtual), mosquitoMacho->contadorAcasalamentos)*(BETAIS23(femea->idLoteAtual)), 'a', 'i');
							}
							break;
						}
					}
					break;
				}
			}
			break;
			case 'i': {
				switch (femea->saudeWolbachia) {
					case 's': {
						switch (mosquitoMacho->contadorAcasalamentos) {
							case 0: {
								efetivacaoAcasalamento(macho, femea, BETASI22(femea->idLoteAtual), 'i', 'e');
							}
							break;
							default: {
								efetivacaoAcasalamento(macho, femea, pow(K2(femea->idLoteAtual), mosquitoMacho->contadorAcasalamentos)*(BETASI23(femea->idLoteAtual)), 'i', 'e');
							}
							break;
						}
					}
					break;
					case 'i': {
						switch (mosquitoMacho->contadorAcasalamentos) {
							case 0: {
								efetivacaoAcasalamento(macho, femea, BETAII22(femea->idLoteAtual), 'i', 'i');
							}
							break;
							default: {
								efetivacaoAcasalamento(macho, femea, pow(K2(femea->idLoteAtual), mosquitoMacho->contadorAcasalamentos)*(BETAII23(femea->idLoteAtual)), 'i', 'i');
							}
							break;
						}
					}
				}
			}
			break;
        }
    }

    void procuraMachoAcasalamento(Mosquito* femea, Conexao posicaoEscolhida) {
		Mosquito* macho = NULL;
		MosquitoMacho* mosquitoMacho = NULL;
		int acasalamentos = 99;
		FOR2MOSQUITO(LISTAMACHOS(posicaoEscolhida.idLoteDestino, posicaoEscolhida.destino.x, posicaoEscolhida.destino.y), i) {
			mosquitoMacho = (MosquitoMacho*) i->elementoLista;
			if (mosquitoMacho->contadorAcasalamentos < acasalamentos) {
				macho = i->elementoLista;
				acasalamentos = mosquitoMacho->contadorAcasalamentos;
			}
		}
		if ((macho->posicaoAtual.x == femea->posicaoAtual.x) && (macho->posicaoAtual.y == femea->posicaoAtual.y) && (macho->idLoteAtual == femea->idLoteAtual)) {
			acasalamento(macho, femea);
		} else {
			double distanciaCalculada;
			CoordenadaGeo coordenadaGeoDestino = POSICAOLOTE(femea->idLoteAtual, femea->posicaoAtual.x, femea->posicaoAtual.y).coordenadaGeo;
			double menorDistancia = POSICAOLOTE(macho->idLoteAtual, macho->posicaoAtual.x, macho->posicaoAtual.y).coordenadaGeo.distancia(coordenadaGeoDestino);
			int xEscolhido = femea->posicaoAtual.x;
			int yEscolhido = femea->posicaoAtual.y;				
			VIZINHANCAMOORE(i, j, femea->posicaoAtual.x, femea->posicaoAtual.y, 1) {
				if (LIMITESLOTE(femea->idLoteAtual, i, j)) {
					distanciaCalculada = POSICAOLOTE(femea->idLoteAtual, i, j).coordenadaGeo.distancia(coordenadaGeoDestino);	
					if (distanciaCalculada < menorDistancia) {
						menorDistancia = distanciaCalculada;
						xEscolhido = i;
						yEscolhido = j;
					}
				}
			}
			}
			LISTAFEMEAS(femea->idLoteAtual, femea->posicaoAtual.x, femea->posicaoAtual.y).buscaRemocaoLista(femea);
			femea->setPosicaoAtual(xEscolhido, yEscolhido);
			LISTAFEMEAS(femea->idLoteAtual, femea->posicaoAtual.x, femea->posicaoAtual.y).insercaoLista(new ElementoLista<Mosquito*>(femea));
		}
    }

    void buscaMacho(Mosquito* femea) {
		Lista<Conexao> lista;
		VIZINHANCAMOORE(i, j, femea->posicaoAtual.x, femea->posicaoAtual.y, RAIO_BUSCA_MACHO(femea->idLoteAtual)) {
			if (LIMITESLOTE(femea->idLoteAtual, i, j) && (LISTAMACHOS(femea->idLoteAtual, i, j).tamanhoLista > 0)) {
				lista.insercaoLista(new ElementoLista<Conexao>(Conexao(Posicao(i, j), femea->idLoteAtual)));
			}
		}
		}
		FORCONEXAO(LISTAPERCEPCAOMACHOS(femea->idLoteAtual, femea->posicaoAtual.x, femea->posicaoAtual.y), i) {
			Conexao* conexao = i->elementoLista;
			if (LISTAMACHOS(conexao->idLoteDestino, conexao->destino.x, conexao->destino.y).tamanhoLista > 0) {
				lista.insercaoLista(new ElementoLista<Conexao>(Conexao(Posicao(conexao->destino.x, conexao->destino.y), conexao->idLoteDestino)));
			}
		}
        if (lista.tamanhoLista != 0) {
			Conexao escolhido;
			double distanciaCalculada;
			escolhido = lista.cabecaLista->elementoLista;
			CoordenadaGeo coordenadaGeoDestino = POSICAOLOTE(femea->idLoteAtual, femea->posicaoAtual.x, femea->posicaoAtual.y).coordenadaGeo;
			double menorDistancia = POSICAOLOTE(lista.cabecaLista->elementoLista.idLoteDestino, lista.cabecaLista->elementoLista.destino.x, lista.cabecaLista->elementoLista.destino.y).coordenadaGeo.distancia(coordenadaGeoDestino);
			FOR2CONEXAO(lista, i) {
				distanciaCalculada = POSICAOLOTE(i->elementoLista.idLoteDestino, i->elementoLista.destino.x, i->elementoLista.destino.y).coordenadaGeo.distancia(coordenadaGeoDestino);
				if (distanciaCalculada < menorDistancia) {
					menorDistancia = distanciaCalculada;
					escolhido = i->elementoLista;
				}
			}
			procuraMachoAcasalamento(femea, escolhido);
		}
    }
   
    bool efetivacaoMovimentaMosquito(Mosquito* mosquito, int variacaoX, int variacaoY) {
		if (!LIMITESLOTEP(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y, variacaoX, variacaoY)) {
            return false;
        } else {
            switch (mosquito->sexo) {
				case 'm': {
					LISTAMACHOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
					LISTAMACHOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x + variacaoX, mosquito->posicaoAtual.y + variacaoY).insercaoLista(new ElementoLista<Mosquito*>(mosquito));
				}
				break;
				case 'f': {
					LISTAFEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
					LISTAFEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x + variacaoX, mosquito->posicaoAtual.y + variacaoY).insercaoLista(new ElementoLista<Mosquito*>(mosquito));
				}
				break;
            }
            mosquito->addPosicaoAtual(variacaoX, variacaoY);
        }
        return true;
    }

     bool migrarLote(Mosquito* mosquito) {
        if (LISTAVIZINHANCAMOSQUITOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).tamanhoLista == 0) {
            return false;
        } else {
			int indiceEscolhido = rand() % LISTAVIZINHANCAMOSQUITOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).tamanhoLista;
			ElementoLista<Conexao*>* destino = LISTAVIZINHANCAMOSQUITOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaPosicao(indiceEscolhido);
			Posicao posicaoDestino = destino->elementoLista->destino;
			int idLoteDestino = destino->elementoLista->idLoteDestino;
			switch (mosquito->sexo) {
				case 'm': {
					LISTAMACHOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
					LISTAMACHOS(idLoteDestino, posicaoDestino.x, posicaoDestino.y).insercaoLista(new ElementoLista<Mosquito*>(mosquito));
				}
				break;
				case 'f': {
					LISTAFEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
					LISTAFEMEAS(idLoteDestino, posicaoDestino.x, posicaoDestino.y).insercaoLista(new ElementoLista<Mosquito*>(mosquito));				}
				break;
            }
            mosquito->setLoteAtualPosicaoAtual(idLoteDestino, posicaoDestino.x, posicaoDestino.y);
        }
        return true;
    }
    
    void movimentaMosquito(Mosquito* mosquito) {
        bool moveu = false;
        int direcaoMovimentacao;
        Lista<int> direcoes;
        FORINT(i, 0, 9, 1) {
			direcoes.insercaoLista(new ElementoLista<int>(i));
        }
        if (mosquito->sexo == 'm') {
			while ((!moveu) && (direcoes.tamanhoLista != 0)) {
				direcaoMovimentacao = direcoes.buscaPosicao(rand() % direcoes.tamanhoLista)->elementoLista;
				switch (direcaoMovimentacao) {
					case 0: {
						moveu = efetivacaoMovimentaMosquito(mosquito, -1, 0);
					}
					break;
					case 1: {
						moveu = efetivacaoMovimentaMosquito(mosquito, 1, 0);
					}
					break;
					case 2:
						moveu = efetivacaoMovimentaMosquito(mosquito, 0, -1);
					break;
					case 3: {
						moveu = efetivacaoMovimentaMosquito(mosquito, 0, 1);
					}
					break;
					case 4: {
						moveu = efetivacaoMovimentaMosquito(mosquito, -1, -1);
					}
					break;
					case 5: {
						moveu = efetivacaoMovimentaMosquito(mosquito, -1, 1);
					}
					break;
					case 6: {
						moveu = efetivacaoMovimentaMosquito(mosquito, 1, -1);
					}
					break;
					case 7: {
						moveu = efetivacaoMovimentaMosquito(mosquito, 1, 1);
					}
					break;
					case 8: {
						moveu = migrarLote(mosquito);
					}
					break;
				}
				if (moveu == false) {
					direcoes.buscaRemocaoLista(direcaoMovimentacao);
				}
			}
		} else {
			Lista<Conexao> lista;
			VIZINHANCAMOORE(i, j, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y, 1) {
				if (LIMITESLOTE(mosquito->idLoteAtual, i, j)) {
					lista.insercaoLista(new ElementoLista<Conexao>(Conexao(Posicao(i, j), mosquito->idLoteAtual)));
				}
			}
			}
			FORCONEXAO(LISTAPERCEPCAOCRIADOUROS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y), i) {
				Conexao* conexao = i->elementoLista;
				if (POSICAOLOTE(conexao->idLoteDestino, conexao->destino.x, conexao->destino.y).criadouro) {
					lista.insercaoLista(new ElementoLista<Conexao>(Conexao(Posicao(conexao->destino.x, conexao->destino.y), conexao->idLoteDestino)));
				}
			}
			if (lista.tamanhoLista != 0) {
				Conexao escolhido;
				double distanciaCalculada;
				escolhido = lista.cabecaLista->elementoLista;
				CoordenadaGeo coordenadaGeoDestino = POSICAOLOTE(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).coordenadaGeo;
				double menorDistancia = POSICAOLOTE(lista.cabecaLista->elementoLista.idLoteDestino, lista.cabecaLista->elementoLista.destino.x, lista.cabecaLista->elementoLista.destino.y).coordenadaGeo.distancia(coordenadaGeoDestino);
				FOR2CONEXAO(lista, i) {
					Conexao conexao = i->elementoLista;
					distanciaCalculada = POSICAOLOTE(conexao.idLoteDestino, conexao.destino.x, conexao.destino.y).coordenadaGeo.distancia(coordenadaGeoDestino);
					if (distanciaCalculada < menorDistancia) {
						menorDistancia = distanciaCalculada;
						escolhido = conexao;
					}
				}
				LISTAFEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
				mosquito->setLoteAtualPosicaoAtual(escolhido.idLoteDestino, escolhido.destino.x, escolhido.destino.y);
				LISTAFEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).insercaoLista(new ElementoLista<Mosquito*>(mosquito));
			}
		}
    }

    bool efetivacaoMovimentaFemeaAlimentada(Mosquito* mosquito, int variacaoX, int variacaoY) {
		MosquitoFemea* mosquitoFemea = (MosquitoFemea*) mosquito;
		if (!LIMITESLOTEP(mosquitoFemea->idLoteAtual, mosquitoFemea->posicaoAtual.x, mosquitoFemea->posicaoAtual.y, variacaoX, variacaoY)) {
            return false;
        } else {
			LISTAFEMEAS(mosquito->idLoteAtual, mosquitoFemea->posicaoAtual.x, mosquitoFemea->posicaoAtual.y).buscaRemocaoLista(mosquito);
            mosquitoFemea->addPosicaoAtual(variacaoX, variacaoY);
            LISTAFEMEAS(mosquito->idLoteAtual, mosquitoFemea->posicaoAtual.x, mosquitoFemea->posicaoAtual.y).insercaoLista(new ElementoLista<Mosquito*>(mosquito));
        }
        return true;
    }

    void movimentaFemeaAlimentada(Mosquito* mosquito) {
        bool moveu = false;
        int direcaoMovimentacao;
        Lista<int> direcoes;
        FORINT(i, 0, 9, 1) {
			direcoes.insercaoLista(new ElementoLista<int>(i));
        }
        while ((!moveu) && (direcoes.tamanhoLista != 0)) {
			direcaoMovimentacao = direcoes.buscaPosicao(rand() % direcoes.tamanhoLista)->elementoLista;
            switch (direcaoMovimentacao) {
				case 0: {
					moveu = efetivacaoMovimentaFemeaAlimentada(mosquito, -1, 0);
				}
				break;
				case 1: {
					moveu = efetivacaoMovimentaFemeaAlimentada(mosquito, 1, 0);
				}
				break;
				case 2:
					moveu = efetivacaoMovimentaFemeaAlimentada(mosquito, 0, -1);
				break;
				case 3: {
					moveu = efetivacaoMovimentaFemeaAlimentada(mosquito, 0, 1);
				}
				break;
				case 4: {
					moveu = efetivacaoMovimentaFemeaAlimentada(mosquito, -1, -1);
				}
				break;
				case 5: {
					moveu = efetivacaoMovimentaFemeaAlimentada(mosquito, -1, 1);
				}
				break;
				case 6: {
					moveu = efetivacaoMovimentaFemeaAlimentada(mosquito, 1, -1);
				}
				break;
				case 7: {
					moveu = efetivacaoMovimentaFemeaAlimentada(mosquito, 1, 1);
				}
				break;
				case 8: {
					moveu = migrarLote(mosquito);
				}
				break;
            }
            if (moveu == false) {
                direcoes.buscaRemocaoLista(direcaoMovimentacao);
            }
        }
    }

    Humano* buscaHumano(Mosquito* mosquito, int ordemVizinhancaBusca) {
        Lista<Humano*> lista;
        Humano* retorno = NULL;
        VIZINHANCAMOORE(i, j, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y, ordemVizinhancaBusca) {
			if (LIMITESLOTE(mosquito->idLoteAtual, i, j) && (LISTAHUMANOS(mosquito->idLoteAtual, i, j).tamanhoLista > 0)) {
				FOR2HUMANO(LISTAHUMANOS(mosquito->idLoteAtual, i, j), k) {
					Humano* humano = k->elementoLista;
					if (humano->saude != 'r') {
						lista.insercaoLista(new ElementoLista<Humano*>(humano));
					}
				} 
           }
        } 
        }
        if (ordemVizinhancaBusca == 1) {
			FORCONEXAO(LISTAVIZINHANCAMOSQUITOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y), i) {
				Conexao* conexao = i->elementoLista;
				if (LISTAHUMANOS(conexao->idLoteDestino, conexao->destino.x, conexao->destino.y).tamanhoLista > 0) {
					FOR2HUMANO(LISTAHUMANOS(conexao->idLoteDestino, conexao->destino.x, conexao->destino.y), j) {
						Humano* humano = j->elementoLista;
						if (humano->saude != 'r') {
							lista.insercaoLista(new ElementoLista<Humano*>(humano));
						}
					}
				}
			}
		} else {
			FORCONEXAO(LISTAPERCEPCAOHUMANOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y), i) {
				Conexao* conexao = i->elementoLista;
				if (LISTAHUMANOS(conexao->idLoteDestino, conexao->destino.x, conexao->destino.y).tamanhoLista > 0) {
					FOR2HUMANO(LISTAHUMANOS(conexao->idLoteDestino, conexao->destino.x, conexao->destino.y), j) {
						Humano* humano = j->elementoLista;
						if (humano->saude != 'r') {
							lista.insercaoLista(new ElementoLista<Humano*>(humano));
						}
					}
				}
			}
		}
        if (lista.tamanhoLista != 0) {
			double distanciaCalculada;
			retorno = lista.cabecaLista->elementoLista;
			CoordenadaGeo coordenadaGeoDestino = POSICAOLOTE(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).coordenadaGeo;
			double menorDistancia = POSICAOLOTE(lista.cabecaLista->elementoLista->idLoteAtual, lista.cabecaLista->elementoLista->posicaoAtual.x, lista.cabecaLista->elementoLista->posicaoAtual.y).coordenadaGeo.distancia(coordenadaGeoDestino);
			FOR2HUMANO(lista, i) {
				distanciaCalculada = POSICAOLOTE(i->elementoLista->idLoteAtual, i->elementoLista->posicaoAtual.x, i->elementoLista->posicaoAtual.y).coordenadaGeo.distancia(coordenadaGeoDestino);
				if (distanciaCalculada < menorDistancia) {
					retorno = i->elementoLista;
					menorDistancia = distanciaCalculada;
				}
			}
		}
		return retorno;
    }

    void infeccaoMosquito(Mosquito* mosquito, Humano* humano) {
        MosquitoFemea* mosquitoFemea = (MosquitoFemea*) mosquito;
        if ((mosquitoFemea->saudeDengue == 's') && (humano->saude == 'i')  && (mosquitoFemea->saudeWolbachia == 's')) {
			double probabilidade;
			switch(humano->sorotipo) {
				case 1: {
					probabilidade = PROBABILIDADE_INFECCAO_MOSQUITO_SOROTIPO_1(humano->idLoteAtual);
				} 
				break;
				case 2: {
					probabilidade = PROBABILIDADE_INFECCAO_MOSQUITO_SOROTIPO_2(humano->idLoteAtual);
				} 
				break;
				case 3: {
					probabilidade = PROBABILIDADE_INFECCAO_MOSQUITO_SOROTIPO_3(humano->idLoteAtual);
				} 
				break;
				case 4: {
					probabilidade = PROBABILIDADE_INFECCAO_MOSQUITO_SOROTIPO_4(humano->idLoteAtual);
				} 
				break;
				case 5: {
					probabilidade = PROBABILIDADE_INFECCAO_MOSQUITO_SOROTIPO_5(humano->idLoteAtual);
				} 
				break;
			}
			if (randomizarPercentual() <= (probabilidade * TAXA_SUCESSO_INFECCAO_MOSQUITO(humano->idLoteAtual))) {
				mosquitoFemea->sorotipo = humano->sorotipo;
				mosquitoFemea->saudeDengue = 'l';
				mosquitoFemea->ciclosLatencia = CICLOS_LATENTE_MOSQUITO(mosquito->idLoteAtual);
			}
        }
    }

    void efetivacaoMorteDengueHemorragica(Humano* humano) {
        if (randomizarPercentual() <= PROBABILIDADE_MORTE(humano->idLoteAtual)) {
            humano->saude = 'r';
		}
    }

    void efetivacaoEvolucaoDengueHemorragica(Humano* humano, double probabilidadeEvolucao) {
        if (randomizarPercentual() <= probabilidadeEvolucao) {
            humano->saude = 'h';
            efetivacaoMorteDengueHemorragica(humano);
        }
    }

    void evolucaoDengueHemorragica(Humano* humano) {
        switch (humano->listaSorotiposContraidos.tamanhoLista) {
			case 1:
				efetivacaoEvolucaoDengueHemorragica(humano, PROBABILIDADE_DENGUE_HEMORRAGICA_1_SOROTIPO_CONTRAIDO(humano->idLoteAtual));
			break;
			case 2:
				efetivacaoEvolucaoDengueHemorragica(humano, PROBABILIDADE_DENGUE_HEMORRAGICA_2_SOROTIPOS_CONTRAIDOS(humano->idLoteAtual));
			break;
			case 3:
				efetivacaoEvolucaoDengueHemorragica(humano, PROBABILIDADE_DENGUE_HEMORRAGICA_3_SOROTIPOS_CONTRAIDOS(humano->idLoteAtual));
			break;
			case 4:
				efetivacaoEvolucaoDengueHemorragica(humano, PROBABILIDADE_DENGUE_HEMORRAGICA_4_SOROTIPOS_CONTRAIDOS(humano->idLoteAtual));
			break;
			case 5:
				efetivacaoEvolucaoDengueHemorragica(humano, PROBABILIDADE_DENGUE_HEMORRAGICA_5_SOROTIPOS_CONTRAIDOS(humano->idLoteAtual));
			break;
        }
    }

    void efetivacaoInfeccaoHumana(Humano* humano, double probabilidadeInfeccaoHumana, int sorotipo) {
        if (randomizarPercentual() <= (probabilidadeInfeccaoHumana * TAXA_SUCESSO_INFECCAO_HUMANO(humano->idLoteAtual))) {
            humano->saude = 'l';
            humano->contagemCiclosPeriodos = CICLOS_LATENTE_HUMANO(humano->idLoteAtual);
            humano->listaSorotiposContraidos.insercaoLista(new ElementoLista<int>(sorotipo));
            humano->sorotipo = sorotipo;
        }
    }

    void infeccaoHumano(Mosquito* mosquito, Humano* humano) {
        MosquitoFemea* mosquitoFemea = (MosquitoFemea*) mosquito;
        if ((mosquitoFemea->saudeDengue == 'i') && (humano->saude == 's') && (!humano->listaSorotiposContraidos.buscaLista(mosquitoFemea->sorotipo))) {
			if (humano->listaSorotiposContraidos.tamanhoLista == 0) {
				switch (mosquitoFemea->sorotipo) {
					case 1:
						efetivacaoInfeccaoHumana(humano, PROBABILIDADE_INFECCAO_HUMANA_SOROTIPO_1(mosquito->idLoteAtual), 1);
						break;
					case 2:
						efetivacaoInfeccaoHumana(humano, PROBABILIDADE_INFECCAO_HUMANA_SOROTIPO_2(mosquito->idLoteAtual), 2);
						break;
					case 3:
						efetivacaoInfeccaoHumana(humano, PROBABILIDADE_INFECCAO_HUMANA_SOROTIPO_3(mosquito->idLoteAtual), 3);
						break;
					case 4:
						efetivacaoInfeccaoHumana(humano, PROBABILIDADE_INFECCAO_HUMANA_SOROTIPO_4(mosquito->idLoteAtual), 4);
						break;
					case 5:
						efetivacaoInfeccaoHumana(humano, PROBABILIDADE_INFECCAO_HUMANA_SOROTIPO_5(mosquito->idLoteAtual), 5);
						break;
				}
			} else {
				switch (mosquitoFemea->sorotipo) {
					case 1:
						efetivacaoInfeccaoHumana(humano, PROBABILIDADE_INFECCAO_HUMANO_RECUPERADO_SOROTIPO_1(mosquito->idLoteAtual), 1);
						break;
					case 2:
						efetivacaoInfeccaoHumana(humano, PROBABILIDADE_INFECCAO_HUMANO_RECUPERADO_SOROTIPO_2(mosquito->idLoteAtual), 2);
						break;
					case 3:
						efetivacaoInfeccaoHumana(humano, PROBABILIDADE_INFECCAO_HUMANO_RECUPERADO_SOROTIPO_3(mosquito->idLoteAtual), 3);
						break;
					case 4:
						efetivacaoInfeccaoHumana(humano, PROBABILIDADE_INFECCAO_HUMANO_RECUPERADO_SOROTIPO_4(mosquito->idLoteAtual), 4);
						break;
					case 5:
						efetivacaoInfeccaoHumana(humano, PROBABILIDADE_INFECCAO_HUMANO_RECUPERADO_SOROTIPO_5(mosquito->idLoteAtual), 5);
						break;
				}
			}
            evolucaoDengueHemorragica(humano);
        }
    }

    bool movimentaFemeaGestante(Mosquito* mosquito) {
		if (randomizarPercentual() <= (1.0 / FATOR_AMORTECIMENTO_PROCURA_HUMANO(mosquito->idLoteAtual))) {
			int raioVizinhancaBusca = 1, variacaoX, variacaoY;
			while (raioVizinhancaBusca <= AREA_PERCEPCAO_ALIMENTO(mosquito->idLoteAtual)) {
				Humano* humano = buscaHumano(mosquito, raioVizinhancaBusca);
				if (humano != NULL) {
					if (raioVizinhancaBusca == 1) {
						MosquitoFemea* mosquitoFemea = (MosquitoFemea*) mosquito;
						Posicao posicaoDestino = humano->posicaoAtual;
						int idLoteDestino = humano->idLoteAtual;
						LISTAFEMEAS(mosquitoFemea->idLoteAtual, mosquitoFemea->posicaoAtual.x, mosquitoFemea->posicaoAtual.y).buscaRemocaoLista(mosquitoFemea);
						mosquitoFemea->setLoteAtualPosicaoAtual(idLoteDestino, posicaoDestino.x, posicaoDestino.y);
						LISTAFEMEAS(mosquitoFemea->idLoteAtual, mosquitoFemea->posicaoAtual.x, mosquitoFemea->posicaoAtual.y).insercaoLista(new ElementoLista<Mosquito*>(mosquitoFemea));
						mosquitoFemea->setPosicaoAlimento(mosquitoFemea->posicaoAtual.x, mosquitoFemea->posicaoAtual.y);
						mosquitoFemea->alimento = true;
						infeccaoMosquito(mosquito, humano);
						infeccaoHumano(mosquito, humano);
						return true;
					} else {
						double distanciaCalculada;
						CoordenadaGeo coordenadaGeoDestino = POSICAOLOTE(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).coordenadaGeo;
						double menorDistancia = POSICAOLOTE(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).coordenadaGeo.distancia(coordenadaGeoDestino);
						int xEscolhido = mosquito->posicaoAtual.x;
						int yEscolhido = mosquito->posicaoAtual.y;	
						VIZINHANCAMOORE(i, j, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y, raioVizinhancaBusca) {		
							if (LIMITESLOTE(mosquito->idLoteAtual, i, j)) {
								distanciaCalculada = POSICAOLOTE(mosquito->idLoteAtual, i, j).coordenadaGeo.distancia(coordenadaGeoDestino);	
								if (distanciaCalculada < menorDistancia) {
									menorDistancia = distanciaCalculada;
									xEscolhido = i;
									yEscolhido = j;
								}
							}
						}
						}
						MosquitoFemea* mosquitoFemea = (MosquitoFemea*) mosquito;
						LISTAFEMEAS(mosquitoFemea->idLoteAtual, mosquitoFemea->posicaoAtual.x, mosquitoFemea->posicaoAtual.y).buscaRemocaoLista(mosquitoFemea);
						mosquitoFemea->setPosicaoAtual(xEscolhido, yEscolhido);
						LISTAFEMEAS(mosquitoFemea->idLoteAtual, mosquitoFemea->posicaoAtual.x, mosquitoFemea->posicaoAtual.y).insercaoLista(new ElementoLista<Mosquito*>(mosquitoFemea));
					}
				}
				raioVizinhancaBusca++;
			}
			return false;
		}
		return false;
    }

    void movimentacao(Mosquito* mosquito) {
        switch (mosquito->sexo) {
			case 'm':
				movimentaMosquito(mosquito);
				break;
			case 'f': {
				MosquitoFemea* mosquitoFemea = (MosquitoFemea*) mosquito;
				if (mosquitoFemea->tipoAcasalamento == 'n') {
					movimentaMosquito(mosquito);
					buscaMacho(mosquito);
				} else {
					if ((mosquitoFemea->contadorPosturas % INTERVALO_ENTRE_BUSCA_ALIMENTO_FEMEA(mosquitoFemea->idLoteAtual)) == 0) {
						mosquitoFemea->alimento = false;
						if (movimentaFemeaGestante(mosquito)) {
							movimentaFemeaAlimentada(mosquito);
						} else {
							movimentaMosquito(mosquito);
						}
					}
					else {
						movimentaFemeaAlimentada(mosquito);
					}
				}
			}
			break;
        }
    }

    void insercaoOvos(Mosquito* mosquitoMae, int quantidade, double fracaoMachos, char saudeOvo) {
        Mosquito* mosquitoNovo = NULL;
        double quantidadeFemeas = 0, quantidadeMachos = 0;
        quantidadeMachos = (int) (fracaoMachos * quantidade);
        quantidadeFemeas = (int) (quantidade - quantidadeMachos);
        FORINT(indice, 0, quantidadeFemeas, 1) {
            MosquitoFemea* mosquitoFemea = new MosquitoFemea(contadorIDs, saudeOvo, 's', 0, 'o', 0, mosquitoMae->idLoteAtual, mosquitoMae->posicaoAtual.x, mosquitoMae->posicaoAtual.y);
            mosquitoNovo = listaMosquitos->insercaoLista(new ElementoLista<Mosquito*>(mosquitoFemea));            
            LISTAOVOS(mosquitoMae->idLoteAtual, mosquitoMae->posicaoAtual.x, mosquitoMae->posicaoAtual.y).insercaoLista(new ElementoLista<Mosquito*>(mosquitoNovo));
            contadorIDs++;
        }
        FORINT(indice, 0, quantidadeMachos, 1) {
            MosquitoMacho* mosquitoMacho = new MosquitoMacho(contadorIDs, saudeOvo, 'o', 0, mosquitoMae->idLoteAtual, mosquitoMae->posicaoAtual.x, mosquitoMae->posicaoAtual.y);
            mosquitoNovo = listaMosquitos->insercaoLista(new ElementoLista<Mosquito*>(mosquitoMacho));
            LISTAOVOS(mosquitoMae->idLoteAtual, mosquitoMae->posicaoAtual.x, mosquitoMae->posicaoAtual.y).insercaoLista(new ElementoLista<Mosquito*>(mosquitoNovo));
            contadorIDs++;
        }
    }

    void geracao6Casos(Mosquito* mosquitoMae) {
		MosquitoFemea* mosquitoFemea = (MosquitoFemea*) mosquitoMae;
        switch (mosquitoFemea->saudeWolbachia) {
			case 's': {
				if ((mosquitoFemea->tipoProle == 's') && (mosquitoFemea->tipoAcasalamento == 'a')) {
					switch (mosquitoFemea->fase) {
						case 'a':
							insercaoOvos(mosquitoMae, AS21(mosquitoMae->idLoteAtual), PS21(mosquitoMae->idLoteAtual), 's');
							break;
						case 'd':
							insercaoOvos(mosquitoMae, AS21(mosquitoMae->idLoteAtual) * H1(mosquitoMae->idLoteAtual), PS31(mosquitoMae->idLoteAtual), 's');
							break;
					}
				}
			}
			break;
			case 'i': {
				if (mosquitoFemea->tipoProle == 'i') {
					switch (mosquitoFemea->fase) {
						case 'a': {
							insercaoOvos(mosquitoMae, AI21(mosquitoMae->idLoteAtual), PI21(mosquitoMae->idLoteAtual), 'i');
						}
						break;
						case 'd': {
							insercaoOvos(mosquitoMae, AI21(mosquitoMae->idLoteAtual) * H2(mosquitoMae->idLoteAtual), PI31(mosquitoMae->idLoteAtual), 'i');
						}
						break;
					}
				}
			}
			break;
        }
    }

    void efetivacaoTransformacaoOvos(Lista<Mosquito*>* listaOvos, int transforma, int naoTransforma, char sexo) {
        FORMOSQUITO(listaOvos, i) {
            Mosquito* mosquito = i->elementoLista;
            if (randomizarPercentual() <= 0.5) {
                if (transforma > 0) {
                    mosquito->fase = 'l';
                    transforma--;
                } else {
                    if (naoTransforma > 0) {
                        mosquito->vida = false;
                        LISTAOVOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
                        naoTransforma--;
                    }
                }
            } else {
                if (naoTransforma > 0) {
                    mosquito->vida = false;
                    LISTAOVOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
                    naoTransforma--;
                } else {
                    if (transforma > 0) {
                        mosquito->fase = 'l';
                        transforma--;
                    }
                }
            }
        }
    }

    void transformacaoOvos() {
        FORINT(idLote, 0, quantLotes, 1) {
			int contadorMachosSaudaveis = 0, contadorFemeasSaudaveis = 0, contadorMachosWolbachia = 0, contadorFemeasWolbachia = 0;
			int contadorFemeasSaudaveisTransformacao = 0, contadorFemeasSaudaveisNaoTransformacao = 0, contadorMachosSaudaveisTransformacao = 0, contadorMachosSaudaveisNaoTransformacao = 0, contadorFemeasWolbachiaTransformacao = 0, contadorFemeasWolbachiaNaoTransformacao = 0, contadorMachosWolbachiaTransformacao = 0, contadorMachosWolbachiaNaoTransformacao = 0;
			double totalFemeasSaudaveis = 0, totalMachosSaudaveis = 0, totalFemeasWolbachia = 0, totalMachosWolbachia = 0;
			Lista<Mosquito*> listaMachosSaudaveis;
			Lista<Mosquito*> listaMachosWolbachia;
			Lista<Mosquito*> listaFemeasSaudaveis;
			Lista<Mosquito*> listaFemeasWolbachia;
			FORMOSQUITO(listaMosquitos, i) {
				Mosquito* mosquito = i->elementoLista;
				if ((mosquito->idade > CICLOS_CONVERSAO_OVOS(idLote)) && (mosquito->fase == 'o') && (mosquito->idLoteAtual == idLote) && (mosquito->vida)) {
					if (mosquito->sexo == 'm') {
						if (mosquito->saudeWolbachia == 's') {
							listaMachosSaudaveis.insercaoLista(new ElementoLista<Mosquito*>(mosquito));
							contadorMachosSaudaveis++;
						} else {
							listaMachosWolbachia.insercaoLista(new ElementoLista<Mosquito*>(mosquito));
							contadorMachosWolbachia++;
						}
					} else {
						if (mosquito->saudeWolbachia == 's') {
							listaFemeasSaudaveis.insercaoLista(new ElementoLista<Mosquito*>(mosquito));
							contadorFemeasSaudaveis++;
						} else {
							listaFemeasWolbachia.insercaoLista(new ElementoLista<Mosquito*>(mosquito));
							contadorFemeasWolbachia++;
						}
					}
				}
			}
			if ((contadorMachosSaudaveis + contadorFemeasSaudaveis + contadorMachosWolbachia + contadorFemeasWolbachia) != 0) {
				totalFemeasSaudaveis = contadorFemeasSaudaveis * BS12_OVOS(idLote);
				totalMachosSaudaveis = contadorMachosSaudaveis * CS12_OVOS(idLote);
				totalFemeasWolbachia = contadorFemeasWolbachia * BI12_OVOS(idLote);
				totalMachosWolbachia = contadorMachosWolbachia * CI12_OVOS(idLote);
				contadorFemeasSaudaveisNaoTransformacao = (int) totalFemeasSaudaveis;
				contadorMachosSaudaveisNaoTransformacao = (int) totalMachosSaudaveis;
				contadorFemeasWolbachiaNaoTransformacao = (int) totalFemeasWolbachia;
				contadorMachosWolbachiaNaoTransformacao = (int) totalMachosWolbachia;
				contadorFemeasSaudaveisTransformacao = contadorFemeasSaudaveis - contadorFemeasSaudaveisNaoTransformacao;
				contadorMachosSaudaveisTransformacao = contadorMachosSaudaveis - contadorMachosSaudaveisNaoTransformacao;
				contadorFemeasWolbachiaTransformacao = contadorFemeasWolbachia - contadorFemeasWolbachiaNaoTransformacao;
				contadorMachosWolbachiaTransformacao = contadorMachosWolbachia - contadorMachosWolbachiaNaoTransformacao;
				efetivacaoTransformacaoOvos(&listaMachosSaudaveis, contadorMachosSaudaveisTransformacao, contadorMachosSaudaveisNaoTransformacao, 'm');
				efetivacaoTransformacaoOvos(&listaMachosWolbachia, contadorMachosWolbachiaTransformacao, contadorMachosWolbachiaNaoTransformacao, 'm');
				efetivacaoTransformacaoOvos(&listaFemeasSaudaveis, contadorFemeasSaudaveisTransformacao, contadorFemeasSaudaveisNaoTransformacao, 'f');
				efetivacaoTransformacaoOvos(&listaFemeasWolbachia, contadorFemeasWolbachiaTransformacao, contadorFemeasWolbachiaNaoTransformacao, 'f');
			}
		}
    }
    
    void efetivacaoTransformacaoLarvas(Lista<Mosquito*>* listaMosquitosNaoAlados, int transforma, int naoTransforma, char sexo) {
        FORMOSQUITO(listaMosquitosNaoAlados, i) {
            Mosquito* mosquito = i->elementoLista;
            if (randomizarPercentual() <= 0.5) {
                if (transforma > 0) {
                    mosquito->fase = 'p';
                    transforma--;
                } else {
                    if (naoTransforma > 0) {
                        mosquito->vida = false;
                        quadra->lotes[mosquito->idLoteAtual]->lote->matriz[mosquito->posicaoAtual.x][mosquito->posicaoAtual.y].listaOvos.buscaRemocaoLista(mosquito);
						naoTransforma--;
                    }
                }
            } else {
                if (naoTransforma > 0) {
                    mosquito->vida = false;
                    quadra->lotes[mosquito->idLoteAtual]->lote->matriz[mosquito->posicaoAtual.x][mosquito->posicaoAtual.y].listaOvos.buscaRemocaoLista(mosquito);
					naoTransforma--;
                } else {
                    if (transforma > 0) {
                        mosquito->fase = 'p';
                        transforma--;
                    }
                }
            }
        }
    }

    void transformacaoLarvas() {
        FORINT(idLote, 0, quantLotes, 1) {
			int contadorMachosSaudaveis = 0, contadorFemeasSaudaveis = 0, contadorMachosWolbachia = 0, contadorFemeasWolbachia = 0;
			int contadorFemeasSaudaveisTransformacao = 0, contadorFemeasSaudaveisNaoTransformacao = 0, contadorMachosSaudaveisTransformacao = 0, contadorMachosSaudaveisNaoTransformacao = 0, contadorFemeasWolbachiaTransformacao = 0, contadorFemeasWolbachiaNaoTransformacao = 0, contadorMachosWolbachiaTransformacao = 0, contadorMachosWolbachiaNaoTransformacao = 0;
			double totalFemeasSaudaveis = 0, totalMachosSaudaveis = 0, totalFemeasWolbachia = 0, totalMachosWolbachia = 0;
			Lista<Mosquito*> listaMachosSaudaveis;
			Lista<Mosquito*> listaMachosWolbachia;
			Lista<Mosquito*> listaFemeasSaudaveis;
			Lista<Mosquito*> listaFemeasWolbachia;
			FORMOSQUITO(listaMosquitos, i) {
				Mosquito* mosquito = i->elementoLista;
				if ((mosquito->idade > CICLOS_CONVERSAO_LARVAS(idLote)) && (mosquito->fase == 'l') && (mosquito->idLoteAtual == idLote) && (mosquito->vida)) {
					if (mosquito->sexo == 'm') {
						if (mosquito->saudeWolbachia == 's') {
							listaMachosSaudaveis.insercaoLista(new ElementoLista<Mosquito*>(mosquito));
							contadorMachosSaudaveis++;
						} else {
							listaMachosWolbachia.insercaoLista(new ElementoLista<Mosquito*>(mosquito));
							contadorMachosWolbachia++;
						}
					} else {
						if (mosquito->saudeWolbachia == 's') {
							listaFemeasSaudaveis.insercaoLista(new ElementoLista<Mosquito*>(mosquito));
							contadorFemeasSaudaveis++;
						} else {
							listaFemeasWolbachia.insercaoLista(new ElementoLista<Mosquito*>(mosquito));
							contadorFemeasWolbachia++;
						}
					}
				}
			}
			if ((contadorMachosSaudaveis + contadorFemeasSaudaveis + contadorMachosWolbachia + contadorFemeasWolbachia) != 0) {
				totalFemeasSaudaveis = contadorFemeasSaudaveis * BS12_LARVAS(idLote);
				totalMachosSaudaveis = contadorMachosSaudaveis * CS12_LARVAS(idLote);
				totalFemeasWolbachia = contadorFemeasWolbachia * BI12_LARVAS(idLote);
				totalMachosWolbachia = contadorMachosWolbachia * CI12_LARVAS(idLote);
				contadorFemeasSaudaveisNaoTransformacao = (int) totalFemeasSaudaveis;
				contadorMachosSaudaveisNaoTransformacao = (int) totalMachosSaudaveis;
				contadorFemeasWolbachiaNaoTransformacao = (int) totalFemeasWolbachia;
				contadorMachosWolbachiaNaoTransformacao = (int) totalMachosWolbachia;
				contadorFemeasSaudaveisTransformacao = contadorFemeasSaudaveis - contadorFemeasSaudaveisNaoTransformacao;
				contadorMachosSaudaveisTransformacao = contadorMachosSaudaveis - contadorMachosSaudaveisNaoTransformacao;
				contadorFemeasWolbachiaTransformacao = contadorFemeasWolbachia - contadorFemeasWolbachiaNaoTransformacao;
				contadorMachosWolbachiaTransformacao = contadorMachosWolbachia - contadorMachosWolbachiaNaoTransformacao;
				efetivacaoTransformacaoLarvas(&listaMachosSaudaveis, contadorMachosSaudaveisTransformacao, contadorMachosSaudaveisNaoTransformacao, 'm');
				efetivacaoTransformacaoLarvas(&listaMachosWolbachia, contadorMachosWolbachiaTransformacao, contadorMachosWolbachiaNaoTransformacao, 'm');
				efetivacaoTransformacaoLarvas(&listaFemeasSaudaveis, contadorFemeasSaudaveisTransformacao, contadorFemeasSaudaveisNaoTransformacao, 'f');
				efetivacaoTransformacaoLarvas(&listaFemeasWolbachia, contadorFemeasWolbachiaTransformacao, contadorFemeasWolbachiaNaoTransformacao, 'f');
			}
		}
    }
    
    void efetivacaoTransformacaoPupas(Lista<Mosquito*>* listaMosquitosNaoAlados, int transforma, int naoTransforma, char sexo) {
        FORMOSQUITO(listaMosquitosNaoAlados, i) {
            Mosquito* mosquito = i->elementoLista;
            if (randomizarPercentual() <= 0.5) {
                if (transforma > 0) {
                    mosquito->fase = 'a';
                    quadra->lotes[mosquito->idLoteAtual]->lote->matriz[mosquito->posicaoAtual.x][mosquito->posicaoAtual.y].listaOvos.buscaRemocaoLista(mosquito);
                    if (sexo == 'm') {
                        quadra->lotes[mosquito->idLoteAtual]->lote->matriz[mosquito->posicaoAtual.x][mosquito->posicaoAtual.y].listaMosquitosMachos.insercaoLista(new ElementoLista<Mosquito*>(mosquito));
                    } else {
                        quadra->lotes[mosquito->idLoteAtual]->lote->matriz[mosquito->posicaoAtual.x][mosquito->posicaoAtual.y].listaMosquitosFemeas.insercaoLista(new ElementoLista<Mosquito*>(mosquito));
                    }
                     transforma--;
                } else {
                    if (naoTransforma > 0) {
                        mosquito->vida = false;
                        quadra->lotes[mosquito->idLoteAtual]->lote->matriz[mosquito->posicaoAtual.x][mosquito->posicaoAtual.y].listaOvos.buscaRemocaoLista(mosquito);
                        naoTransforma--;
                    }
                }
            } else {
                if (naoTransforma > 0) {
                    mosquito->vida = false;
                    quadra->lotes[mosquito->idLoteAtual]->lote->matriz[mosquito->posicaoAtual.x][mosquito->posicaoAtual.y].listaOvos.buscaRemocaoLista(mosquito);
					naoTransforma--;
                } else {
                    if (transforma > 0) {
                        mosquito->fase = 'a';
                        quadra->lotes[mosquito->idLoteAtual]->lote->matriz[mosquito->posicaoAtual.x][mosquito->posicaoAtual.y].listaOvos.buscaRemocaoLista(mosquito);
						if (sexo == 'm') {
							quadra->lotes[mosquito->idLoteAtual]->lote->matriz[mosquito->posicaoAtual.x][mosquito->posicaoAtual.y].listaMosquitosMachos.insercaoLista(new ElementoLista<Mosquito*>(mosquito));
						} else {
							quadra->lotes[mosquito->idLoteAtual]->lote->matriz[mosquito->posicaoAtual.x][mosquito->posicaoAtual.y].listaMosquitosFemeas.insercaoLista(new ElementoLista<Mosquito*>(mosquito));
						}
                        transforma--;
                    }
                }
            }
        }
    }

    void transformacaoPupas() {
        FORINT(idLote, 0, quantLotes, 1) {
			int contadorMachosSaudaveis = 0, contadorFemeasSaudaveis = 0, contadorMachosWolbachia = 0, contadorFemeasWolbachia = 0;
			int contadorFemeasSaudaveisTransformacao = 0, contadorFemeasSaudaveisNaoTransformacao = 0, contadorMachosSaudaveisTransformacao = 0, contadorMachosSaudaveisNaoTransformacao = 0, contadorFemeasWolbachiaTransformacao = 0, contadorFemeasWolbachiaNaoTransformacao = 0, contadorMachosWolbachiaTransformacao = 0, contadorMachosWolbachiaNaoTransformacao = 0;
			double totalFemeasSaudaveis = 0, totalMachosSaudaveis = 0, totalFemeasWolbachia = 0, totalMachosWolbachia = 0;
			Lista<Mosquito*> listaMachosSaudaveis;
			Lista<Mosquito*> listaMachosWolbachia;
			Lista<Mosquito*> listaFemeasSaudaveis;
			Lista<Mosquito*> listaFemeasWolbachia;
			FORMOSQUITO(listaMosquitos, i) {
				Mosquito* mosquito = i->elementoLista;
				if ((mosquito->idade > CICLOS_CONVERSAO_PUPAS(idLote)) && (mosquito->fase == 'p') && (mosquito->idLoteAtual == idLote) && (mosquito->vida)) {
					if (mosquito->sexo == 'm') {
						if (mosquito->saudeWolbachia == 's') {
							listaMachosSaudaveis.insercaoLista(new ElementoLista<Mosquito*>(mosquito));
							contadorMachosSaudaveis++;
						} else {
							listaMachosWolbachia.insercaoLista(new ElementoLista<Mosquito*>(mosquito));
							contadorMachosWolbachia++;
						}
					} else {
						if (mosquito->saudeWolbachia == 's') {
							listaFemeasSaudaveis.insercaoLista(new ElementoLista<Mosquito*>(mosquito));
							contadorFemeasSaudaveis++;
						} else {
							listaFemeasWolbachia.insercaoLista(new ElementoLista<Mosquito*>(mosquito));
							contadorFemeasWolbachia++;
						}
					}
				}
			}
			if ((contadorMachosSaudaveis + contadorFemeasSaudaveis + contadorMachosWolbachia + contadorFemeasWolbachia) != 0) {
				totalFemeasSaudaveis = contadorFemeasSaudaveis * BS12_PUPAS(idLote);
				totalMachosSaudaveis = contadorMachosSaudaveis * CS12_PUPAS(idLote);
				totalFemeasWolbachia = contadorFemeasWolbachia * BI12_PUPAS(idLote);
				totalMachosWolbachia = contadorMachosWolbachia * CI12_PUPAS(idLote);
				contadorFemeasSaudaveisNaoTransformacao = (int) totalFemeasSaudaveis;
				contadorMachosSaudaveisNaoTransformacao = (int) totalMachosSaudaveis;
				contadorFemeasWolbachiaNaoTransformacao = (int) totalFemeasWolbachia;
				contadorMachosWolbachiaNaoTransformacao = (int) totalMachosWolbachia;
				contadorFemeasSaudaveisTransformacao = contadorFemeasSaudaveis - contadorFemeasSaudaveisNaoTransformacao;
				contadorMachosSaudaveisTransformacao = contadorMachosSaudaveis - contadorMachosSaudaveisNaoTransformacao;
				contadorFemeasWolbachiaTransformacao = contadorFemeasWolbachia - contadorFemeasWolbachiaNaoTransformacao;
				contadorMachosWolbachiaTransformacao = contadorMachosWolbachia - contadorMachosWolbachiaNaoTransformacao;
				efetivacaoTransformacaoPupas(&listaMachosSaudaveis, contadorMachosSaudaveisTransformacao, contadorMachosSaudaveisNaoTransformacao, 'm');
				efetivacaoTransformacaoPupas(&listaMachosWolbachia, contadorMachosWolbachiaTransformacao, contadorMachosWolbachiaNaoTransformacao, 'm');
				efetivacaoTransformacaoPupas(&listaFemeasSaudaveis, contadorFemeasSaudaveisTransformacao, contadorFemeasSaudaveisNaoTransformacao, 'f');
				efetivacaoTransformacaoPupas(&listaFemeasWolbachia, contadorFemeasWolbachiaTransformacao, contadorFemeasWolbachiaNaoTransformacao, 'f');
			}
		}
    }

    int efetivacaoTransformacaoAlados(Mosquito* mosquito, int enviados, int naoEnviados, int transformados, int naoTransformados) {
        if (randomizarPercentual() <= 0.5) {
            if (transformados < enviados) {
                mosquito->fase = 'd';
                return 1;
            } else {
                if (naoTransformados < naoEnviados) {
                    if (mosquito->sexo == 'm') {
                        quadra->lotes[mosquito->idLoteAtual]->lote->matriz[mosquito->posicaoAtual.x][mosquito->posicaoAtual.y].listaMosquitosMachos.buscaRemocaoLista(mosquito);
                    } else {
                        quadra->lotes[mosquito->idLoteAtual]->lote->matriz[mosquito->posicaoAtual.x][mosquito->posicaoAtual.y].listaMosquitosFemeas.buscaRemocaoLista(mosquito);
                    }
                    mosquito->vida = false;
                    return 2;
                }
            }
        } else {
            if (naoTransformados < naoEnviados) {
                if (mosquito->sexo == 'm') {
                    quadra->lotes[mosquito->idLoteAtual]->lote->matriz[mosquito->posicaoAtual.x][mosquito->posicaoAtual.y].listaMosquitosMachos.buscaRemocaoLista(mosquito);
                } else {
                    quadra->lotes[mosquito->idLoteAtual]->lote->matriz[mosquito->posicaoAtual.x][mosquito->posicaoAtual.y].listaMosquitosFemeas.buscaRemocaoLista(mosquito);
                }
                mosquito->vida = false;
                return 2;
            } else {
                if (transformados < enviados) {
                    mosquito->fase = 'd';
                    return 1;
                }
            }
        }
        return 0;
    }

    void testeTransformacaoAlados(char sexo, int enviadosSaudaveis, int naoEnviadosSaudaveis, int enviadosInfectados, int naoEnviadosInfectados) {
        int transformadosSaudaveis = 0, naoTransformadosSaudaveis = 0, transformadosInfectados = 0, naoTransformadosInfectados = 0;
        switch (sexo) {
			case 'm': {
				FORMOSQUITO(listaMosquitos, i) {
					if (i->elementoLista->sexo == 'm') {
						MosquitoMacho* macho2 = (MosquitoMacho*) (i->elementoLista);
						if ((macho2->fase == 'a') && (macho2->contadorAcasalamentos > 0) && (macho2->vida)) {
							if ((macho2->saudeWolbachia == 's') && (macho2->idade > CICLOS_CONVERSAO_MACHOS_ATIVOS_SAUDAVEIS(i->elementoLista->idLoteAtual))) {
								if (efetivacaoTransformacaoAlados(i->elementoLista, enviadosSaudaveis, naoEnviadosSaudaveis, transformadosSaudaveis, naoTransformadosSaudaveis) == 1) {
									transformadosSaudaveis++;
								} else {
									naoTransformadosSaudaveis++;
								}
							}
							if ((macho2->saudeWolbachia == 'i') && (macho2->idade > CICLOS_CONVERSAO_MACHOS_ATIVOS_WOLBACHIA(i->elementoLista->idLoteAtual))) {
								if (efetivacaoTransformacaoAlados(i->elementoLista, enviadosInfectados, naoEnviadosInfectados, transformadosInfectados, naoTransformadosInfectados) == 1) {
									transformadosInfectados++;
								} else {
									naoTransformadosInfectados++;
								}
							}
						}
					}
				}
			}
			break;
			case 'f': {
				FORMOSQUITO(listaMosquitos, i) {
					if (i->elementoLista->sexo == 'f') {
						MosquitoFemea* femea2 = (MosquitoFemea*) (i->elementoLista);
						if ((femea2->fase == 'a') && (femea2->vida) && (femea2->contadorPosturas > 0)) {
							if ((femea2->saudeWolbachia == 's') && (femea2->idade > CICLOS_CONVERSAO_FEMEAS_ATIVAS_SAUDAVEIS(i->elementoLista->idLoteAtual))) {
								if (efetivacaoTransformacaoAlados(i->elementoLista, enviadosSaudaveis, naoEnviadosSaudaveis, transformadosSaudaveis, naoTransformadosSaudaveis) == 1) {
									transformadosSaudaveis++;
								} else {
									naoTransformadosSaudaveis++;
								}
							}
							if ((femea2->saudeWolbachia == 'i') && (femea2->idade > CICLOS_CONVERSAO_FEMEAS_ATIVAS_WOLBACHIA(i->elementoLista->idLoteAtual))) {
								if (efetivacaoTransformacaoAlados(i->elementoLista, enviadosInfectados, naoEnviadosInfectados, transformadosInfectados, naoTransformadosInfectados) == 1) {
									transformadosInfectados++;
								} else {
									naoTransformadosInfectados++;
								}
							}
						}
					}
				}
			}
			break;
        }
    }

    void transformacaoAlados() {
		FORINT(idLote, 0, quantLotes, 1) {
			int naoTransformaSaudaveis, transformaSaudaveis, naoTransformaWolbachia, transformaWolbachia;
			int contadorSaudaveis = 0, contadorWolbachia = 0;
			FORMOSQUITO(listaMosquitos, i) {
				if (i->elementoLista->sexo == 'm') {
					MosquitoMacho* macho2 = (MosquitoMacho*) (i->elementoLista);
					if ((macho2->fase == 'a') && (macho2->contadorAcasalamentos > 0) && (macho2->idLoteAtual == idLote) && (macho2->vida)) {
						if ((macho2->saudeWolbachia == 's') && (macho2->idade > CICLOS_CONVERSAO_MACHOS_ATIVOS_SAUDAVEIS(idLote)))
							contadorSaudaveis++;
						if ((macho2->saudeWolbachia == 'i') && (macho2->idade > CICLOS_CONVERSAO_MACHOS_ATIVOS_WOLBACHIA(idLote)))
							contadorWolbachia++;
					}
				}
			}
			if ((contadorSaudaveis + contadorWolbachia) != 0) {
				naoTransformaSaudaveis = (int) (contadorSaudaveis * CS23(idLote));
				transformaSaudaveis = (int) (contadorSaudaveis - naoTransformaSaudaveis);
				naoTransformaWolbachia = (int) (contadorWolbachia * CI23(idLote));
				transformaWolbachia = (int) (contadorWolbachia - naoTransformaWolbachia);
				testeTransformacaoAlados('m', transformaSaudaveis, naoTransformaSaudaveis, transformaWolbachia, naoTransformaWolbachia);
				contadorSaudaveis = 0, contadorWolbachia = 0;
			}
			FORMOSQUITO(listaMosquitos, i) {
				if (i->elementoLista->sexo == 'f') {
					MosquitoFemea* femea2 = (MosquitoFemea*) (i->elementoLista);
					if ((femea2->fase == 'a') && (femea2->contadorPosturas > 0) && (femea2->idLoteAtual == idLote) && (femea2->vida)) {
						if ((femea2->saudeWolbachia == 's') && (femea2->idade > CICLOS_CONVERSAO_FEMEAS_ATIVAS_SAUDAVEIS(idLote)))
							contadorSaudaveis++;
						if ((femea2->saudeWolbachia == 'i') && (femea2->idade > CICLOS_CONVERSAO_FEMEAS_ATIVAS_WOLBACHIA(idLote)))
							contadorWolbachia++;
					}
				}
			}
			if ((contadorSaudaveis + contadorWolbachia) != 0) {
				naoTransformaSaudaveis = (int) (contadorSaudaveis * BS23(idLote));
				transformaSaudaveis = (int) (contadorSaudaveis - naoTransformaSaudaveis);
				naoTransformaWolbachia = (int) (contadorWolbachia * BI23(idLote));
				transformaWolbachia = (int) (contadorWolbachia - naoTransformaWolbachia);
				testeTransformacaoAlados('f', transformaSaudaveis, naoTransformaSaudaveis, transformaWolbachia, naoTransformaWolbachia);
			}
		}
    }
    
    void remocaoMosquitosControleNatural(int ciclo) {
		FORINT(idLote, 0, quantLotes, 1) {
			if ((FREQUENCIA_CONTROLE_NATURAL(idLote) > 0) && ((ciclo % FREQUENCIA_CONTROLE_NATURAL(idLote)) == 0) && (ciclo != 0)) {
				remocaoMosquitosControleNaturalOvosSaudaveis(idLote);
				remocaoMosquitosControleNaturalOvosWolbachia(idLote);
				remocaoMosquitosControleNaturalLarvasSaudaveis(idLote);
				remocaoMosquitosControleNaturalLarvasWolbachia(idLote);
				remocaoMosquitosControleNaturalPupasSaudaveis(idLote);
				remocaoMosquitosControleNaturalPupasWolbachia(idLote);
				remocaoMosquitosControleNaturalAtivosSaudaveis(idLote);
				remocaoMosquitosControleNaturalAtivosWolbachia(idLote);
			}
		}
	}

    void remocaoMosquitosControleNaturalOvosSaudaveis(int idLote) {
		Lista<ElementoLista<Mosquito*>*> listaMosquitosMortos;
		int quantidadeMachos = 0, quantidadeFemeas = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->fase == 'o')  && (i->elementoLista->saudeWolbachia == 's') && (i->elementoLista->idLoteAtual == idLote)){
				if (i->elementoLista->sexo == 'm')
					quantidadeMachos++;
				else
					quantidadeFemeas++;
			}
		}
		quantidadeMachos = quantidadeMachos * PORCENTAGEM_ELIMINACAO_MACHOS_OVOS_SAUDAVEIS(idLote);
		quantidadeFemeas = quantidadeFemeas * PORCENTAGEM_ELIMINACAO_FEMEAS_OVOS_SAUDAVEIS(idLote);
		int quantidadeMachosRemovidos = 0, quantidadeFemeasRemovidas = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->sexo == 'm') && (i->elementoLista->saudeWolbachia == 's') && (i->elementoLista->idLoteAtual == idLote) && (i->elementoLista->fase == 'o')) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaOvos.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeMachosRemovidos++;
			}
			if (quantidadeMachosRemovidos == quantidadeMachos)
				break;
		}
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->sexo == 'f') && (i->elementoLista->saudeWolbachia == 's') && (i->elementoLista->idLoteAtual == idLote) && (i->elementoLista->fase == 'o')) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaOvos.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeFemeasRemovidas++;
			}
			if (quantidadeFemeasRemovidas == quantidadeFemeas)
				break;
		}
		FORP2MOSQUITO(listaMosquitosMortos, i) {
			delete(i->elementoLista->elementoLista);
			listaMosquitos->remocaoLista(i->elementoLista);
		}
    }
    
    void remocaoMosquitosControleNaturalOvosWolbachia(int idLote) {
		Lista<ElementoLista<Mosquito*>*> listaMosquitosMortos;
		int quantidadeMachos = 0, quantidadeFemeas = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->fase == 'o') && (i->elementoLista->saudeWolbachia == 'i') && (i->elementoLista->idLoteAtual == idLote)){
				if (i->elementoLista->sexo == 'm')
					quantidadeMachos++;
				else
					quantidadeFemeas++;
			}
		}
		quantidadeMachos = quantidadeMachos * PORCENTAGEM_ELIMINACAO_MACHOS_OVOS_COM_WOLBACHIA(idLote);
		quantidadeFemeas = quantidadeFemeas * PORCENTAGEM_ELIMINACAO_FEMEAS_OVOS_COM_WOLBACHIA(idLote);
		int quantidadeMachosRemovidos = 0, quantidadeFemeasRemovidas = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->sexo == 'm') && (i->elementoLista->saudeWolbachia == 'i') && (i->elementoLista->idLoteAtual == idLote) && (i->elementoLista->fase == 'o')) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaOvos.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeMachosRemovidos++;
			}
			if (quantidadeMachosRemovidos == quantidadeMachos)
				break;
		}
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->sexo == 'f') && (i->elementoLista->saudeWolbachia == 'i') && (i->elementoLista->idLoteAtual == idLote) && (i->elementoLista->fase == 'o')) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaOvos.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeFemeasRemovidas++;
			}
			if (quantidadeFemeasRemovidas == quantidadeFemeas)
				break;
		}
		FORP2MOSQUITO(listaMosquitosMortos, i) {
			delete(i->elementoLista->elementoLista);
			listaMosquitos->remocaoLista(i->elementoLista);
		}
    }
    
    void remocaoMosquitosControleNaturalLarvasSaudaveis(int idLote) {
		Lista<ElementoLista<Mosquito*>*> listaMosquitosMortos;
		int quantidadeMachos = 0, quantidadeFemeas = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->fase == 'l') && (i->elementoLista->saudeWolbachia == 's') && (i->elementoLista->idLoteAtual == idLote)){
				if (i->elementoLista->sexo == 'm')
					quantidadeMachos++;
				else
					quantidadeFemeas++;
			}
		}
		quantidadeMachos = quantidadeMachos * PORCENTAGEM_ELIMINACAO_MACHOS_LARVAS_SAUDAVEIS(idLote);
		quantidadeFemeas = quantidadeFemeas * PORCENTAGEM_ELIMINACAO_FEMEAS_LARVAS_SAUDAVEIS(idLote);
		int quantidadeMachosRemovidos = 0, quantidadeFemeasRemovidas = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->sexo == 'm') && (i->elementoLista->saudeWolbachia == 's') && (i->elementoLista->idLoteAtual == idLote) && (i->elementoLista->fase == 'l')) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaOvos.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeMachosRemovidos++;
			}
			if (quantidadeMachosRemovidos == quantidadeMachos)
				break;
		}
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->sexo == 'f') && (i->elementoLista->saudeWolbachia == 's') && (i->elementoLista->idLoteAtual == idLote) && (i->elementoLista->fase == 'l')) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaOvos.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeFemeasRemovidas++;
			}
			if (quantidadeFemeasRemovidas == quantidadeFemeas)
				break;
		}
		FORP2MOSQUITO(listaMosquitosMortos, i) {
			delete(i->elementoLista->elementoLista);
			listaMosquitos->remocaoLista(i->elementoLista);
		}
    }
    
    void remocaoMosquitosControleNaturalLarvasWolbachia(int idLote) {
		Lista<ElementoLista<Mosquito*>*> listaMosquitosMortos;
		int quantidadeMachos = 0, quantidadeFemeas = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->fase == 'l') && (i->elementoLista->saudeWolbachia == 'i') && (i->elementoLista->idLoteAtual == idLote)){
				if (i->elementoLista->sexo == 'm')
					quantidadeMachos++;
				else
					quantidadeFemeas++;
			}
		}
		quantidadeMachos = quantidadeMachos * PORCENTAGEM_ELIMINACAO_MACHOS_LARVAS_COM_WOLBACHIA(idLote);
		quantidadeFemeas = quantidadeFemeas * PORCENTAGEM_ELIMINACAO_FEMEAS_LARVAS_COM_WOLBACHIA(idLote);
		int quantidadeMachosRemovidos = 0, quantidadeFemeasRemovidas = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->sexo == 'm') && (i->elementoLista->saudeWolbachia == 'i') && (i->elementoLista->idLoteAtual == idLote) && (i->elementoLista->fase == 'l')) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaOvos.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeMachosRemovidos++;
			}
			if (quantidadeMachosRemovidos == quantidadeMachos)
				break;
		}
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->sexo == 'f') && (i->elementoLista->saudeWolbachia == 'i') && (i->elementoLista->idLoteAtual == idLote) && (i->elementoLista->fase == 'l')) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaOvos.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeFemeasRemovidas++;
			}
			if (quantidadeFemeasRemovidas == quantidadeFemeas)
				break;
		}
		FORP2MOSQUITO(listaMosquitosMortos, i) {
			delete(i->elementoLista->elementoLista);
			listaMosquitos->remocaoLista(i->elementoLista);
		}
    }
    
    void remocaoMosquitosControleNaturalPupasSaudaveis(int idLote) {
		Lista<ElementoLista<Mosquito*>*> listaMosquitosMortos;
		int quantidadeMachos = 0, quantidadeFemeas = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->fase == 'p') && (i->elementoLista->saudeWolbachia == 's') && (i->elementoLista->idLoteAtual == idLote)){
				if (i->elementoLista->sexo == 'm')
					quantidadeMachos++;
				else
					quantidadeFemeas++;
			}
		}
		quantidadeMachos = quantidadeMachos * PORCENTAGEM_ELIMINACAO_MACHOS_PUPAS_SAUDAVEIS(idLote);
		quantidadeFemeas = quantidadeFemeas * PORCENTAGEM_ELIMINACAO_FEMEAS_PUPAS_SAUDAVEIS(idLote);
		int quantidadeMachosRemovidos = 0, quantidadeFemeasRemovidas = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->sexo == 'm') && (i->elementoLista->saudeWolbachia == 's') && (i->elementoLista->idLoteAtual == idLote) && (i->elementoLista->fase == 'p')) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaOvos.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeMachosRemovidos++;
			}
			if (quantidadeMachosRemovidos == quantidadeMachos)
				break;
		}
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->sexo == 'f') && (i->elementoLista->saudeWolbachia == 's') && (i->elementoLista->idLoteAtual == idLote) && (i->elementoLista->fase == 'p')) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaOvos.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeFemeasRemovidas++;
			}
			if (quantidadeFemeasRemovidas == quantidadeFemeas)
				break;
		}
		FORP2MOSQUITO(listaMosquitosMortos, i) {
			delete(i->elementoLista->elementoLista);
			listaMosquitos->remocaoLista(i->elementoLista);
		}
    }
    
    void remocaoMosquitosControleNaturalPupasWolbachia(int idLote) {
		Lista<ElementoLista<Mosquito*>*> listaMosquitosMortos;
		int quantidadeMachos = 0, quantidadeFemeas = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->fase == 'p') && (i->elementoLista->saudeWolbachia == 'i') && (i->elementoLista->idLoteAtual == idLote)){
				if (i->elementoLista->sexo == 'm')
					quantidadeMachos++;
				else
					quantidadeFemeas++;
			}
		}
		quantidadeMachos = quantidadeMachos * PORCENTAGEM_ELIMINACAO_MACHOS_PUPAS_COM_WOLBACHIA(idLote);
		quantidadeFemeas = quantidadeFemeas * PORCENTAGEM_ELIMINACAO_FEMEAS_PUPAS_COM_WOLBACHIA(idLote);
		int quantidadeMachosRemovidos = 0, quantidadeFemeasRemovidas = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->sexo == 'm') && (i->elementoLista->saudeWolbachia == 'i') && (i->elementoLista->idLoteAtual == idLote) && (i->elementoLista->fase == 'p')) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaOvos.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeMachosRemovidos++;
			}
			if (quantidadeMachosRemovidos == quantidadeMachos)
				break;
		}
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->sexo == 'f') && (i->elementoLista->saudeWolbachia == 'i') && (i->elementoLista->idLoteAtual == idLote) && (i->elementoLista->fase == 'p')) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaOvos.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeFemeasRemovidas++;
			}
			if (quantidadeFemeasRemovidas == quantidadeFemeas)
				break;
		}
		FORP2MOSQUITO(listaMosquitosMortos, i) {
			delete(i->elementoLista->elementoLista);
			listaMosquitos->remocaoLista(i->elementoLista);
		}
    }
    
    void remocaoMosquitosControleNaturalAtivosSaudaveis(int idLote) {
		Lista<ElementoLista<Mosquito*>*> listaMosquitosMortos;
		int quantidadeMachos = 0, quantidadeFemeas = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if (((i->elementoLista->fase == 'a') || (i->elementoLista->fase == 'd')) && (i->elementoLista->saudeWolbachia == 's') && (i->elementoLista->idLoteAtual == idLote)){
				if (i->elementoLista->sexo == 'm')
					quantidadeMachos++;
				else
					quantidadeFemeas++;
			}
		}
		quantidadeMachos = quantidadeMachos * PORCENTAGEM_ELIMINACAO_MACHOS_ALADOS_SAUDAVEIS(idLote);
		quantidadeFemeas = quantidadeFemeas * PORCENTAGEM_ELIMINACAO_FEMEAS_ALADAS_SAUDAVEIS(idLote);
		int quantidadeMachosRemovidos = 0, quantidadeFemeasRemovidas = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->sexo == 'm') && (i->elementoLista->saudeWolbachia == 's') && (i->elementoLista->idLoteAtual == idLote) && ((i->elementoLista->fase == 'a') || (i->elementoLista->fase == 'd'))) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaMosquitosMachos.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeMachosRemovidos++;
			}
			if (quantidadeMachosRemovidos == quantidadeMachos)
				break;
		}
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->sexo == 'f') && (i->elementoLista->saudeWolbachia == 's') && (i->elementoLista->idLoteAtual == idLote) && ((i->elementoLista->fase == 'a') || (i->elementoLista->fase == 'd'))) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaMosquitosFemeas.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeFemeasRemovidas++;
			}
			if (quantidadeFemeasRemovidas == quantidadeFemeas)
				break;
		}
		FORP2MOSQUITO(listaMosquitosMortos, i) {
			delete(i->elementoLista->elementoLista);
			listaMosquitos->remocaoLista(i->elementoLista);
		}
    }
    
    void remocaoMosquitosControleNaturalAtivosWolbachia(int idLote) {
		Lista<ElementoLista<Mosquito*>*> listaMosquitosMortos;
		int quantidadeMachos = 0, quantidadeFemeas = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if (((i->elementoLista->fase == 'a') || (i->elementoLista->fase == 'd')) && (i->elementoLista->saudeWolbachia == 'i') && (i->elementoLista->idLoteAtual == idLote)){
				if (i->elementoLista->sexo == 'm')
					quantidadeMachos++;
				else
					quantidadeFemeas++;
			}
		}
		quantidadeMachos = quantidadeMachos * PORCENTAGEM_ELIMINACAO_MACHOS_ALADOS_COM_WOLBACHIA(idLote);
		quantidadeFemeas = quantidadeFemeas * PORCENTAGEM_ELIMINACAO_FEMEAS_ALADAS_COM_WOLBACHIA(idLote);
		int quantidadeMachosRemovidos = 0, quantidadeFemeasRemovidas = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->sexo == 'm') && (i->elementoLista->saudeWolbachia == 'i') && (i->elementoLista->idLoteAtual == idLote) && ((i->elementoLista->fase == 'a') || (i->elementoLista->fase == 'd'))) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaMosquitosMachos.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeMachosRemovidos++;
			}
			if (quantidadeMachosRemovidos == quantidadeMachos)
				break;
		}
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->sexo == 'f') && (i->elementoLista->saudeWolbachia == 'i') && (i->elementoLista->idLoteAtual == idLote) && ((i->elementoLista->fase == 'a') || (i->elementoLista->fase == 'd'))) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaMosquitosFemeas.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeFemeasRemovidas++;
			}
			if (quantidadeFemeasRemovidas == quantidadeFemeas)
				break;
		}
		FORP2MOSQUITO(listaMosquitosMortos, i) {
			delete(i->elementoLista->elementoLista);
			listaMosquitos->remocaoLista(i->elementoLista);
		}
    }

    void remocaoMosquitosIdade() {
        Lista<ElementoLista<Mosquito*>*> listaMosquitosMortos;
        FORMOSQUITO(listaMosquitos, i) {
            if (i->elementoLista->vida == false) {
                listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
                continue;
            }
            if (((i->elementoLista->saudeWolbachia == 's') && (i->elementoLista->idade > IDADE_MAXIMA_MOSQUITO_SAUDAVEL(i->elementoLista->idLoteAtual))) || ((i->elementoLista->saudeWolbachia == 'i') && (i->elementoLista->idade > IDADE_MAXIMA_MOSQUITO_WOLBACHIA(i->elementoLista->idLoteAtual))) || ((i->elementoLista->sexo == 'f') && (((MosquitoFemea*) (i->elementoLista))->saudeDengue != 's') && (i->elementoLista->idade > IDADE_MAXIMA_FEMEA_DENGUE(i->elementoLista->idLoteAtual)))) {
                if (i->elementoLista->sexo == 'm') {
                    quadra->lotes[i->elementoLista->idLoteAtual]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaMosquitosMachos.buscaRemocaoLista(i->elementoLista);
                    i->elementoLista->vida = false;
                    listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
                } else {
                    quadra->lotes[i->elementoLista->idLoteAtual]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaMosquitosFemeas.buscaRemocaoLista(i->elementoLista);
                    i->elementoLista->vida = false;
                    listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
                }
            }
        }
        FORP2MOSQUITO(listaMosquitosMortos, i) {
			delete(i->elementoLista->elementoLista);
            listaMosquitos->remocaoLista(i->elementoLista);
        }
    }

	void remocaoMosquitosControleQuimicoEMecanicoOvos(int idLote, double percentual) {
		Lista<ElementoLista<Mosquito*>*> listaMosquitosMortos;
		int quantidade = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->fase == 'o')  && (i->elementoLista->idLoteAtual == idLote)){
				quantidade++;
			}
		}
		quantidade = quantidade * percentual;
		int quantidadeRemovidos = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->idLoteAtual == idLote) && (i->elementoLista->fase == 'o')) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaOvos.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeRemovidos++;
			}
			if (quantidadeRemovidos == quantidade)
				break;
		}
		FORP2MOSQUITO(listaMosquitosMortos, i) {
			delete(i->elementoLista->elementoLista);
			listaMosquitos->remocaoLista(i->elementoLista);
		}
    }
    
    void remocaoMosquitosControleQuimicoEMecanicoLarvas(int idLote, double percentual) {
		Lista<ElementoLista<Mosquito*>*> listaMosquitosMortos;
		int quantidade = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->fase == 'l')  && (i->elementoLista->idLoteAtual == idLote)){
				quantidade++;
			}
		}
		quantidade = quantidade * percentual;
		int quantidadeRemovidos = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->idLoteAtual == idLote) && (i->elementoLista->fase == 'l')) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaOvos.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeRemovidos++;
			}
			if (quantidadeRemovidos == quantidade)
				break;
		}
		FORP2MOSQUITO(listaMosquitosMortos, i) {
			delete(i->elementoLista->elementoLista);
			listaMosquitos->remocaoLista(i->elementoLista);
		}
    }
    
    void remocaoMosquitosControleQuimicoEMecanicoPupas(int idLote, double percentual) {
		Lista<ElementoLista<Mosquito*>*> listaMosquitosMortos;
		int quantidade = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->fase == 'p')  && (i->elementoLista->idLoteAtual == idLote)){
				quantidade++;
			}
		}
		quantidade = quantidade * percentual;
		int quantidadeRemovidos = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->idLoteAtual == idLote) && (i->elementoLista->fase == 'p')) {
				quadra->lotes[idLote]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaOvos.buscaRemocaoLista(i->elementoLista);
				i->elementoLista->vida = false;
				listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
				quantidadeRemovidos++;
			}
			if (quantidadeRemovidos == quantidade)
				break;
		}
		FORP2MOSQUITO(listaMosquitosMortos, i) {
			delete(i->elementoLista->elementoLista);
			listaMosquitos->remocaoLista(i->elementoLista);
		}
    }
	
	void remocaoMosquitosControleQuimicoNaoAlados(int ciclo) {
		FORINT(idLote, 0, quantLotes, 1) {
			if ((quadra->lotes[idLote]->controleQuimicoLarvas != -1) && (quadra->lotes[idLote]->controleQuimicoPupas != -1)) {
				if  (quadra->lotes[idLote]->controleQuimicoLarvas > 0) {
					remocaoMosquitosControleQuimicoEMecanicoLarvas(idLote, quadra->lotes[idLote]->controleQuimicoLarvas);
					quadra->lotes[idLote]->controleQuimicoLarvas -= (1.0 / EFEITO_RESIDUAL_CONTROLE_QUIMICO_LARVAS(idLote));
				}
				if  (quadra->lotes[idLote]->controleQuimicoPupas > 0) {
					remocaoMosquitosControleQuimicoEMecanicoPupas(idLote, quadra->lotes[idLote]->controleQuimicoPupas);
					quadra->lotes[idLote]->controleQuimicoPupas -= (1.0 / EFEITO_RESIDUAL_CONTROLE_QUIMICO_PUPAS(idLote));
				}
				if ((FREQUENCIA_CONTROLE_QUIMICO_NAO_ALADOS(idLote) > 0) && ((ciclo % FREQUENCIA_CONTROLE_QUIMICO_NAO_ALADOS(idLote)) == 0) && (ciclo != 0)) {
					quadra->lotes[idLote]->controleQuimicoLarvas = 1.0;
					quadra->lotes[idLote]->controleQuimicoPupas = 1.0;
				}
			}
		}
	}
	
	void remocaoMosquitosControleMecanicoNaoAlados(int ciclo) {
		FORINT(idLote, 0, quantLotes, 1) {
			if ((FREQUENCIA_CONTROLE_MECANICO_NAO_ALADOS(idLote) > 0) && ((ciclo % FREQUENCIA_CONTROLE_MECANICO_NAO_ALADOS(idLote)) == 0) && (ciclo != 0) && (quadra->lotes[idLote]->controleMecanicoNaoAlados)) {
				remocaoMosquitosControleQuimicoEMecanicoOvos(idLote, TAXA_CONTROLE_MECANICO_OVOS(idLote));
				remocaoMosquitosControleQuimicoEMecanicoLarvas(idLote, TAXA_CONTROLE_MECANICO_LARVAS(idLote));
				remocaoMosquitosControleQuimicoEMecanicoPupas(idLote, TAXA_CONTROLE_MECANICO_PUPAS(idLote));
			}
		}
	}

	void remocaoMosquitosControleQuimicoAlados(int idLote, double percentual) {
		Lista<ElementoLista<Mosquito*>*> listaMosquitosMortos;
		int quantidade = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if (((i->elementoLista->fase == 'a') || (i->elementoLista->fase == 'd')) && (i->elementoLista->idLoteAtual == idLote)){
				quantidade++;
			}
		}
		quantidade = quantidade * percentual;
		int quantidadeRemovidos = 0;
		FORMOSQUITO(listaMosquitos, i) {
			if ((i->elementoLista->idLoteAtual == idLote) && ((i->elementoLista->fase == 'a') || (i->elementoLista->fase == 'd'))) {
				if (i->elementoLista->sexo == 'm') {
                    quadra->lotes[i->elementoLista->idLoteAtual]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaMosquitosMachos.buscaRemocaoLista(i->elementoLista);
                    i->elementoLista->vida = false;
                    listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
                } else {
                    quadra->lotes[i->elementoLista->idLoteAtual]->lote->matriz[i->elementoLista->posicaoAtual.x][i->elementoLista->posicaoAtual.y].listaMosquitosFemeas.buscaRemocaoLista(i->elementoLista);
                    i->elementoLista->vida = false;
                    listaMosquitosMortos.insercaoLista(new ElementoLista<ElementoLista<Mosquito*>*>(i));
                }
				quantidadeRemovidos++;
			}
			if (quantidadeRemovidos == quantidade)
				break;
		}
		FORP2MOSQUITO(listaMosquitosMortos, i) {
			delete(i->elementoLista->elementoLista);
			listaMosquitos->remocaoLista(i->elementoLista);
		}
    }

	void remocaoMosquitosControleQuimicoAlados(int ciclo) {
		FORINT(idLote, 0, quantLotes, 1) {
			if ((FREQUENCIA_CONTROLE_QUIMICO_ALADOS(idLote) > 0) && ((ciclo % FREQUENCIA_CONTROLE_QUIMICO_ALADOS(idLote)) == 0) && (ciclo != 0) && (quadra->lotes[idLote]->controleQuimicoAlados)) {
				remocaoMosquitosControleQuimicoAlados(idLote, TAXA_CONTROLE_QUIMICO_ALADOS(idLote));
			}
		}
	}

};

#endif

