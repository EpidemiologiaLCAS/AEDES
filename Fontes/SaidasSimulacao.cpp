#ifndef _SAIDASSIMULACAO_
#define _SAIDASSIMULACAO_

#include "Vetor.cpp"
#include "Quadra.cpp"
#include "ManipuladorMosquitos.cpp"
#include "ManipuladorHumanos.cpp"
#include "Saidas.cpp"
#include "Parametros.cpp"

class SaidasSimulacao {
public:

	int idMonteCarlo, idSimulacao, quantLotes, contadorDeslocamentoSDLGeo, numLinhas;
    string pastaSaida;
    Saidas* saidasSimulacao;
    Quadra* quadra;
    ManipuladorMosquitos* manipuladorMosquitos;
    ManipuladorHumanos* manipuladorHumanos;
    Parametros* parametros;
    Matriz<int>* matrizSDLgeo;

    SaidasSimulacao(ManipuladorMosquitos* manipuladorMosquitos, ManipuladorHumanos* manipuladorHumanos, Quadra* quadra, string pastaSaida, int idMonteCarlo, int idSimulacao, Saidas* saidasSimulacao, Parametros* parametros, int quantLotes) {
        this->quadra = quadra;
        this->pastaSaida = pastaSaida;
        this->idMonteCarlo = idMonteCarlo;
        this->manipuladorMosquitos = manipuladorMosquitos;
        this->manipuladorHumanos = manipuladorHumanos;
        this->quantLotes = quantLotes;
        this->idSimulacao = idSimulacao;
        this->saidasSimulacao = saidasSimulacao;
        this->parametros = parametros;
        FOR_INT(i, 0, quantLotes, 1) {
			saidasSimulacao->sdl[i] << quadra->lotes[i]->lote->linhasMatriz << ";" << quadra->lotes[i]->lote->colunasMatriz << ";" << NUMERO_CICLOS_SIMULACAO << endl;
		}
		saidasSimulacao->mosquitosMachos << "Ciclo;Periodo;Subciclo;ID;Sexo;SaudeWolbachia;Fase;Idade;IDLoteAtual;x;y;Acasalamentos;Vida" << endl;
		saidasSimulacao->mosquitosFemeas << "Ciclo;Periodo;Subciclo;ID;Sexo;SaudeWolbachia;SaudeDengue;Sorotipo;Fase;Idade;IDLoteAtual;x;y;CiclosLatencia;CiclosGestacao;TipoAcasalamento;ContadorPosturas;ContadorCiclosEntrePosturas;TipoProle;alx;aly;alimento;vida" << endl;
		numLinhas = 0;
		FOR_INT(i, 0, quantLotes, 1) {
			numLinhas += (NUMERO_LINHAS_AMBIENTE(i) * NUMERO_COLUNAS_AMBIENTE(i));
		}
		matrizSDLgeo = new Matriz<int>(numLinhas, NUMERO_CICLOS_SIMULACAO + 1);
		matrizSDLgeo->zero(0);
        contadorDeslocamentoSDLGeo = 0;
    }

    ~SaidasSimulacao() {
		string comando = COMANDO_CRIAR_PASTA;
        comando += pastaSaida;
        system(comando.c_str());
		//salvar("MosquitosMachos.csv", &saidasSimulacao->mosquitosMachos);
		//salvar("MosquitosFemeas.csv", &saidasSimulacao->mosquitosFemeas);
		FOR_INT(i, 0, quantLotes, 1) {
			char aux[TAMANHO_STRINGS_AUXILIARES];
			sprintf(aux, "%d", i);
			string aux2 = string(aux);
			string aux3;
			/*aux3 = "SDL_";
			aux3 += aux2;
			aux3 += ".csv";
			salvar(aux3, &saidasSimulacao->sdl[i]);*/
			aux3 = "Lote_";
			aux3 += aux2;
			aux3 += "-Dengue.csv";
			salvar(aux3, &saidasSimulacao->quantidadesDengueLote[i]);
			aux3 = "Lote_";
			aux3 += aux2;
			aux3 += "-Wolbachia.csv";
			salvar(aux3, &saidasSimulacao->quantidadesWolbachiaLote[i]);
			aux3 = "Lote_";
			aux3 += aux2;
			aux3 += "-Humanos.csv";
			salvar(aux3, &saidasSimulacao->quantidadesHumanosLote[i]);
		}
		salvarSDLGeo();
		salvar("Quadra-Dengue.csv", &saidasSimulacao->quantidadesDengueQuadra);
		salvar("Quadra-Wolbachia.csv", &saidasSimulacao->quantidadesWolbachiaQuadra);
		salvar("Quadra-Humanos.csv", &saidasSimulacao->quantidadesHumanosQuadra);
    }
    
    void salvarSDLGeo() {
		string auxiliar = pastaSaida;
        auxiliar += "SDL_Geo.csv";
        ofstream arquivo;
        arquivo.open(auxiliar.c_str());
        if (!arquivo.is_open()) {
            cout << "SaidasSimulacao: Arquivo " << auxiliar << " nao foi aberto!" << endl;
        } else {
			FOR_INT(i, 0, numLinhas, 1) {
				FOR_INT(j, 0, NUMERO_CICLOS_SIMULACAO + 1, 1) {
					arquivo << matrizSDLgeo->matriz[i][j] << ";";
				}
				arquivo << endl;
			}
			arquivo.close();
		}
		delete(matrizSDLgeo);
	}
        
    void salvar(string nomeArquivo, stringstream* streamSaida) {
		ofstream* streamArquivo = new ofstream();
		abrirArquivo(nomeArquivo, streamArquivo);
		*streamArquivo << streamSaida->str();
		streamArquivo->close();
		delete(streamArquivo);
	}
    
    void abrirArquivo(string nomeArquivo, ofstream* streamArquivo) {
        string auxiliar = pastaSaida;
        auxiliar += nomeArquivo.c_str();
        streamArquivo->open(auxiliar.c_str());
        if (!streamArquivo->is_open()) {
            cout << "SaidasSimulacao: Arquivo " << auxiliar << " nao foi aberto!" << endl;
        }
    }
    
	void gerarSaidas(int cicloAtual) {
        FOR_INT(i, 0, quantLotes, 1) {
			//saidaSDL(i);
			saidaDengueLote(i, cicloAtual);
			saidaWolbachiaLote(i, cicloAtual);
			saidaHumanosLote(i, cicloAtual);
			saidaSDLGeo(i, cicloAtual);
		}
		contadorDeslocamentoSDLGeo = 0;
		saidaDengueQuadra(cicloAtual);
		saidaWolbachiaQuadra(cicloAtual);
		saidaHumanosQuadra(cicloAtual);
        //barraProgresso(((double) cicloAtual) / NUMERO_CICLOS_SIMULACAO);
        cout << (QUANTIDADE_SIMULACOES == 1 ? 100 : (int) (((double) idSimulacao) / (QUANTIDADE_SIMULACOES - 1) * 100)) << ";" << (int) (((double) cicloAtual) / NUMERO_CICLOS_SIMULACAO * 100) << endl;
	}

    void saidaWolbachiaQuadra(int ciclo) {
		Vetor<int>* vetorAuxiliar = new Vetor<int>(COLUNAS_SAIDAS_WOLBACHIA - 1);
        vetorAuxiliar->zero(0);
        FOR_MOSQUITO(manipuladorMosquitos->listaMosquitos, i) {
			vetorAuxiliar->vetor[0] += 1;
			Mosquito* mosquito = i->elementoLista;
			if (mosquito->fase == OVO) {
				if (mosquito->saudeWolbachia == SAUDAVEL)
					vetorAuxiliar->vetor[5] += 1;
				else
					vetorAuxiliar->vetor[6] += 1;
			} 
			if (mosquito->fase == LARVA) {
				if (mosquito->saudeWolbachia == SAUDAVEL)
					vetorAuxiliar->vetor[7] += 1;
				else
					vetorAuxiliar->vetor[8] += 1;
			} 
			if (mosquito->fase == PUPA) {
				if (mosquito->saudeWolbachia == SAUDAVEL)
					vetorAuxiliar->vetor[9] += 1;
				else
					vetorAuxiliar->vetor[10] += 1;
			}  
			if ((mosquito->fase == ATIVO) || (mosquito->fase == DECADENTE)) {
				if (mosquito->sexo == MACHO) {
					if (mosquito->saudeWolbachia == SAUDAVEL)
						vetorAuxiliar->vetor[1] += 1;
					else
						vetorAuxiliar->vetor[2] += 1;
				} else {
					if (mosquito->saudeWolbachia == SAUDAVEL)
						vetorAuxiliar->vetor[3] += 1;
					else
						vetorAuxiliar->vetor[4] += 1;
				}
			}
        }
        saidasSimulacao->quantidadesWolbachiaQuadra << ciclo << ";" << vetorAuxiliar->vetor[1] << ";" << vetorAuxiliar->vetor[2] << ";" << vetorAuxiliar->vetor[3] << ";" << vetorAuxiliar->vetor[4] << ";" << vetorAuxiliar->vetor[5] << ";" << vetorAuxiliar->vetor[6] << ";" << vetorAuxiliar->vetor[7] << ";" << vetorAuxiliar->vetor[8] << ";" << vetorAuxiliar->vetor[9] << ";" << vetorAuxiliar->vetor[10] << ";" << vetorAuxiliar->vetor[0] << ";" << endl;
        delete(vetorAuxiliar);
    }

    void saidaHumanosQuadra(int ciclo) {
		Vetor<int>* vetorAuxiliar = new Vetor<int>(COLUNAS_SAIDAS_HUMANOS - 1);
        vetorAuxiliar->zero(0);
        FOR_HUMANO(manipuladorHumanos->listaHumanos->lista, i) {
			Humano* humano = i->elementoLista;
			vetorAuxiliar->vetor[0] += 1;
			switch (humano->saude) {
				case SUSCETIVEL: {
					if (humano->listaSorotiposContraidos.tamanhoLista == 0) {
						vetorAuxiliar->vetor[1] += 1;
					} else {
						vetorAuxiliar->vetor[11] += 1;
					}
				}
					break;
				case LATENTE:
					vetorAuxiliar->vetor[2] += 1;
					break;
				case INFECTADO: {
					vetorAuxiliar->vetor[humano->sorotipo + 2] += 1;
				}
					break;
				case IMUNIZADO:
					vetorAuxiliar->vetor[8] += 1;
					break;
				case HEMORRAGICO:
					vetorAuxiliar->vetor[9] += 1;
					break;
				case REMOVIDO:
					vetorAuxiliar->vetor[10] += 1;
					break;
			}
        }
        saidasSimulacao->quantidadesHumanosQuadra << ciclo << ";" << vetorAuxiliar->vetor[1] << ";" << vetorAuxiliar->vetor[2] << ";" << vetorAuxiliar->vetor[3] << ";" << vetorAuxiliar->vetor[4] << ";" << vetorAuxiliar->vetor[5] << ";" << vetorAuxiliar->vetor[6] << ";" << vetorAuxiliar->vetor[7] << ";" << vetorAuxiliar->vetor[8] << ";" << vetorAuxiliar->vetor[9] << ";" << vetorAuxiliar->vetor[10] << ";" << vetorAuxiliar->vetor[11] << ";" << vetorAuxiliar->vetor[0] << ";" << endl;
        delete(vetorAuxiliar);
    }
    
    void saidaDengueQuadra(int ciclo) {
		Vetor<int>* vetorAuxiliar = new Vetor<int>(COLUNAS_SAIDAS_DENGUE - 1);
        vetorAuxiliar->zero(0);
        FOR_MOSQUITO(manipuladorMosquitos->listaMosquitos, i) {
			vetorAuxiliar->vetor[0] += 1;
			Mosquito* mosquito = i->elementoLista;
			if (((mosquito->fase == ATIVO) || (mosquito->fase == DECADENTE))) {
				if (mosquito->sexo == FEMEA) {
					MosquitoFemea* mosquitoFemea = (MosquitoFemea*) (i);
					if (mosquitoFemea->saudeDengue == SAUDAVEL) {
						vetorAuxiliar->vetor[2] += 1;
						continue;
					}
					if (mosquitoFemea->saudeDengue == LATENTE) {
						vetorAuxiliar->vetor[3] += 1;
						continue;
					}
					if (mosquitoFemea->saudeDengue == INFECTADO) {
						switch (mosquitoFemea->sorotipo) {
							case 1:
								vetorAuxiliar->vetor[4] += 1;
								break;
							case 2:
								vetorAuxiliar->vetor[5] += 1;
								break;
							case 3:
								vetorAuxiliar->vetor[6] += 1;
								break;
							case 4:
								vetorAuxiliar->vetor[7] += 1;
								break;
							case 5:
								vetorAuxiliar->vetor[8] += 1;
								break;
						}
					}
				}
				else {
					vetorAuxiliar->vetor[1] += 1;
				}
			} 
			if (mosquito->fase == OVO) {
				vetorAuxiliar->vetor[9] += 1;
			}
			if (mosquito->fase == LARVA) {
				vetorAuxiliar->vetor[10] += 1;
			}
			if (mosquito->fase == PUPA) {
				vetorAuxiliar->vetor[11] += 1;
			}
		}
        saidasSimulacao->quantidadesDengueQuadra << ciclo << ";" << vetorAuxiliar->vetor[1] << ";" << vetorAuxiliar->vetor[2] << ";" << vetorAuxiliar->vetor[3] << ";" << vetorAuxiliar->vetor[4] << ";" << vetorAuxiliar->vetor[5] << ";" << vetorAuxiliar->vetor[6] << ";" << vetorAuxiliar->vetor[7] << ";" << vetorAuxiliar->vetor[8] << ";" << vetorAuxiliar->vetor[9] << ";" << vetorAuxiliar->vetor[10] << ";" << vetorAuxiliar->vetor[11] << ";" << vetorAuxiliar->vetor[0] << ";" << endl;
        delete(vetorAuxiliar);
    }

    void saidaWolbachiaLote(int idLote, int ciclo) {
		Vetor<int>* vetorAuxiliar = new Vetor<int>(COLUNAS_SAIDAS_WOLBACHIA - 1);
        vetorAuxiliar->zero(0);
        FOR_MOSQUITO(manipuladorMosquitos->listaMosquitos, i) {
			Mosquito* mosquito = i->elementoLista;
			if (mosquito->idLoteAtual == idLote) {
				vetorAuxiliar->vetor[0] += 1;
				if (mosquito->fase == OVO) {
					if (mosquito->saudeWolbachia == SAUDAVEL)
						vetorAuxiliar->vetor[5] += 1;
					else
						vetorAuxiliar->vetor[6] += 1;
				} 
				if (mosquito->fase == LARVA) {
					if (mosquito->saudeWolbachia == SAUDAVEL)
						vetorAuxiliar->vetor[7] += 1;
					else
						vetorAuxiliar->vetor[8] += 1;
				} 
				if (mosquito->fase == PUPA) {
					if (mosquito->saudeWolbachia == SAUDAVEL)
						vetorAuxiliar->vetor[9] += 1;
					else
						vetorAuxiliar->vetor[10] += 1;
				}  
				if ((mosquito->fase == ATIVO) || (mosquito->fase == DECADENTE)) {
					if (mosquito->sexo == MACHO) {
						if (mosquito->saudeWolbachia == SAUDAVEL)
							vetorAuxiliar->vetor[1] += 1;
						else
							vetorAuxiliar->vetor[2] += 1;
					} else {
						if (mosquito->saudeWolbachia == SAUDAVEL)
							vetorAuxiliar->vetor[3] += 1;
						else
							vetorAuxiliar->vetor[4] += 1;
					}
				}
			}
        }
        saidasSimulacao->quantidadesWolbachiaLote[idLote] << ciclo << ";" << vetorAuxiliar->vetor[1] << ";" << vetorAuxiliar->vetor[2] << ";" << vetorAuxiliar->vetor[3] << ";" << vetorAuxiliar->vetor[4] << ";" << vetorAuxiliar->vetor[5] << ";" << vetorAuxiliar->vetor[6] << ";" << vetorAuxiliar->vetor[7] << ";" << vetorAuxiliar->vetor[8] << ";" << vetorAuxiliar->vetor[9] << ";" << vetorAuxiliar->vetor[10] << ";" << vetorAuxiliar->vetor[0] << ";" << endl;
        delete(vetorAuxiliar);
    }

    void saidaHumanosLote(int idLote, int ciclo) {
		Vetor<int>* vetorAuxiliar = new Vetor<int>(COLUNAS_SAIDAS_HUMANOS - 1);
        vetorAuxiliar->zero(0);
        FOR_HUMANO(manipuladorHumanos->listaHumanos->lista, i) {
			Humano* humano = i->elementoLista;
			if (humano->idLoteAtual == idLote) {
				vetorAuxiliar->vetor[0] += 1;
				switch (humano->saude) {
					case SUSCETIVEL: {
						if (humano->listaSorotiposContraidos.tamanhoLista == 0) {
							vetorAuxiliar->vetor[1] += 1;
						} else {
							vetorAuxiliar->vetor[11] += 1;
						}
					}	
						break;
					case LATENTE:
						vetorAuxiliar->vetor[2] += 1;
						break;
					case INFECTADO: {
						vetorAuxiliar->vetor[humano->sorotipo + 2] += 1;
					}
						break;
					case IMUNIZADO:
						vetorAuxiliar->vetor[8] += 1;
						break;
					case HEMORRAGICO:
						vetorAuxiliar->vetor[9] += 1;
						break;
					case REMOVIDO:
						vetorAuxiliar->vetor[10] += 1;
						break;
				}
			}
        }
        saidasSimulacao->quantidadesHumanosLote[idLote]<< ciclo << ";" << vetorAuxiliar->vetor[1] << ";" << vetorAuxiliar->vetor[2] << ";" << vetorAuxiliar->vetor[3] << ";" << vetorAuxiliar->vetor[4] << ";" << vetorAuxiliar->vetor[5] << ";" << vetorAuxiliar->vetor[6] << ";" << vetorAuxiliar->vetor[7] << ";" << vetorAuxiliar->vetor[8] << ";" << vetorAuxiliar->vetor[9] << ";" << vetorAuxiliar->vetor[10] << ";" << vetorAuxiliar->vetor[11] << ";" << vetorAuxiliar->vetor[0] << ";" << endl;
        delete(vetorAuxiliar);
    }
    
    void saidaDengueLote(int idLote, int ciclo) {
		Vetor<int>* vetorAuxiliar = new Vetor<int>(COLUNAS_SAIDAS_DENGUE - 1);
        vetorAuxiliar->zero(0);
        FOR_MOSQUITO(manipuladorMosquitos->listaMosquitos, i) {
			Mosquito* mosquito = i->elementoLista;
			if (mosquito->idLoteAtual == idLote) {
				vetorAuxiliar->vetor[0] += 1;
				Mosquito* mosquito = i->elementoLista;
				if (((mosquito->fase == ATIVO) || (mosquito->fase == DECADENTE))) {
					if (mosquito->sexo == FEMEA) {
						MosquitoFemea* mosquitoFemea = (MosquitoFemea*) (i);
						if (mosquitoFemea->saudeDengue == SAUDAVEL) {
							vetorAuxiliar->vetor[2] += 1;
							continue;
						}
						if (mosquitoFemea->saudeDengue == LATENTE) {
							vetorAuxiliar->vetor[3] += 1;
							continue;
						}
						if (mosquitoFemea->saudeDengue == INFECTADO) {
							switch (mosquitoFemea->sorotipo) {
								case 1:
									vetorAuxiliar->vetor[4] += 1;
									break;
								case 2:
									vetorAuxiliar->vetor[5] += 1;
									break;
								case 3:
									vetorAuxiliar->vetor[6] += 1;
									break;
								case 4:
									vetorAuxiliar->vetor[7] += 1;
									break;
								case 5:
									vetorAuxiliar->vetor[8] += 1;
									break;
							}
						}
					}
					else {
						vetorAuxiliar->vetor[1] += 1;
					}
				}
				if (mosquito->fase == OVO) {
					vetorAuxiliar->vetor[9] += 1;
				}
				if (mosquito->fase == LARVA) {
					vetorAuxiliar->vetor[10] += 1;
				}
				if (mosquito->fase == PUPA) {
					vetorAuxiliar->vetor[11] += 1;
				}
			}
		}
        saidasSimulacao->quantidadesDengueLote[idLote] << ciclo << ";" << vetorAuxiliar->vetor[1] << ";" << vetorAuxiliar->vetor[2] << ";" << vetorAuxiliar->vetor[3] << ";" << vetorAuxiliar->vetor[4] << ";" << vetorAuxiliar->vetor[5] << ";" << vetorAuxiliar->vetor[6] << ";" << vetorAuxiliar->vetor[7] << ";" << vetorAuxiliar->vetor[8] << ";" << vetorAuxiliar->vetor[9] << ";" << vetorAuxiliar->vetor[10] << ";" << vetorAuxiliar->vetor[11] << ";" << vetorAuxiliar->vetor[0] << ";" << endl;
        delete(vetorAuxiliar);
    }

    int sdlHumanos(int idLote, int i, int j) {
		if (POSICAO_LOTE(idLote, i, j).humanoInfectante()) {
			return 300;
		}
		if (POSICAO_LOTE(idLote, i, j).humanoLatente()) {
			return 200;
		}
		if (POSICAO_LOTE(idLote, i, j).humanoRecuperado()) {
			return 500;
		}   
		if (POSICAO_LOTE(idLote, i, j).humanoImunizado()) {
			return 400;
		}
		if (POSICAO_LOTE(idLote, i, j).humanoSuscetivel()) {
			return 100;
		}
		return 0;  
	}
	
	int sdlMosquitos(int idLote, int i, int j) {
		if (POSICAO_LOTE(idLote, i, j).femeaInfectante()) {
			return 30;
		}
		if (POSICAO_LOTE(idLote, i, j).femeaLatente()) {
			return 20;
		}
		if (POSICAO_LOTE(idLote, i, j).femeaSuscetivel()) {
			return 10;
		}
		return 0;
	}
	
	int sdlOvos(int idLote, int i, int j) {
		if (POSICAO_LOTE(idLote, i, j).ovos()) {
			return 1;
		}
		return 0;
	}
    
    void saidaSDL(int idLote) {
        Matriz<int>* m = new Matriz<int>(quadra->lotes[idLote]->lote->linhasMatriz, quadra->lotes[idLote]->lote->colunasMatriz);
        m->zero(0);
        FOR_INT(i, 0, LINHAS_LOTE(idLote), 1) {
            FOR_INT(j, 0, COLUNAS_LOTE(idLote), 1) {
                m->matriz[i][j] += sdlHumanos(idLote, i, j);
                m->matriz[i][j] += sdlMosquitos(idLote, i, j);
                m->matriz[i][j] += sdlOvos(idLote, i, j);
            }
        }
		FOR_INT(aux2, 0, LINHAS_LOTE(idLote), 1) {
            FOR_INT(aux3, 0, COLUNAS_LOTE(idLote), 1) {
                saidasSimulacao->sdl[idLote] << m->matriz[aux2][aux3] << ";";
            }
            saidasSimulacao->sdl[idLote] << endl;
        }
        saidasSimulacao->sdl[idLote] << endl;
        delete(m);
    }
    
    void saidaSDLGeo(int idLote, int cicloAtual) {
        FOR_INT(i, 0, LINHAS_LOTE(idLote), 1) {
            FOR_INT(j, 0, COLUNAS_LOTE(idLote), 1) {
				matrizSDLgeo->matriz[contadorDeslocamentoSDLGeo][cicloAtual] = 0;
                matrizSDLgeo->matriz[contadorDeslocamentoSDLGeo][cicloAtual] += sdlHumanos(idLote, i, j);
                matrizSDLgeo->matriz[contadorDeslocamentoSDLGeo][cicloAtual] += sdlMosquitos(idLote, i, j);
                matrizSDLgeo->matriz[contadorDeslocamentoSDLGeo][cicloAtual] += sdlOvos(idLote, i, j);
                contadorDeslocamentoSDLGeo++;
            }
        }
    }

    void saidaMosquitos(int ciclo, int periodo, int subciclo) {
        FOR_MOSQUITO(manipuladorMosquitos->listaMosquitos, i) {
			Mosquito* mosquito = i->elementoLista;
			if (((mosquito->fase == ATIVO) || (mosquito->fase == DECADENTE))) {
				if (mosquito->sexo == MACHO) {
					MosquitoMacho* macho = (MosquitoMacho*) (mosquito);
					saidasSimulacao->mosquitosMachos << ciclo << ";" << periodo << ";" << subciclo << ";" << macho->id << ";" << macho->sexo << ";" << macho->saudeWolbachia << ";" << macho->fase << ";" << macho->idade << ";" << macho->idLoteAtual << ";" << macho->posicaoAtual.x << ";" << macho->posicaoAtual.y << ";" << macho->contadorAcasalamentos << ";" << macho->vida << endl;
				} else {
					MosquitoFemea* femea = (MosquitoFemea*) (mosquito);
					saidasSimulacao->mosquitosFemeas << ciclo << ";" << periodo << ";" << subciclo << ";" << femea->id << ";" << femea->sexo << ";" << femea->saudeWolbachia << ";" << femea->saudeDengue << ";" << femea->sorotipo << ";" << femea->fase << ";" << femea->idade << ";" << femea->idLoteAtual <<";" << femea->posicaoAtual.x << ";" << femea->posicaoAtual.y << ";" << femea->ciclosLatencia << ";" << femea->ciclosGestacao << ";" << femea->tipoAcasalamento << ";" << femea->contadorPosturas << ";" << femea->contadorCiclosEntrePosturas << ";" << femea->tipoProle << ";" << femea->posicaoAlimento.x << ";" << femea->posicaoAlimento.y << ";" << femea->alimento << ";" << femea->vida << endl;
				}
			}
        }
    }
    
    void barraProgresso(double percentual) {
        int progresso = (percentual * TAMANHO_BARRA_PROGRESSO);
        cout << "Monte Carlo:" << setw(ESPACAMENTO_COUT) << idMonteCarlo << " Simulacao:" << setw(ESPACAMENTO_COUT) << idSimulacao << ": [";
        FOR_INT(i, 0, progresso, 1) {
            cout << "#";
        }
        FOR_INT(i, progresso + 1, TAMANHO_BARRA_PROGRESSO, 1) {
            cout << "-";
        }
        cout << "] " << (percentual * 100) << "%\r";
    }

};

#endif
