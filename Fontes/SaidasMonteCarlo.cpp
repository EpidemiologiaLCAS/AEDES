#ifndef _SAIDASMONTECARLO_
#define _SAIDASMONTECARLO_

#include "Matriz.cpp"
#include "Saidas.cpp"

class SaidasMonteCarlo {
public:

	string stringIdMonteCarlo, pastaSaida;
    int numeroCiclosSimulacao, numeroSimulacoes, idMonteCarlo, quantLotes;
    Saidas* saidasSimulacoes;
    
    SaidasMonteCarlo(int idMonteCarlo, string stringIdMonteCarlo, string pastaSaida, int numeroCiclosSimulacao, int numeroSimulacoes, Saidas* saidasSimulacoes, int quantLotes) {
		this->idMonteCarlo = idMonteCarlo;
		this->stringIdMonteCarlo = stringIdMonteCarlo;
		this->pastaSaida = pastaSaida;
        this->numeroCiclosSimulacao = numeroCiclosSimulacao;
        this->numeroSimulacoes = numeroSimulacoes;
		this->saidasSimulacoes = saidasSimulacoes;
		this->quantLotes = quantLotes;
    }

	~SaidasMonteCarlo() {
		int simulacoesValidas = verificacaoSimulacoesValidas();
		geracaoSaidasQuadra(simulacoesValidas);
		FOR_INT(i, 0, quantLotes, 1) {
			geracaoSaidasLotes(simulacoesValidas, i);
		}
	}

private:

	int verificacaoSimulacoesValidas() {
		int numeroSimulacoesValidas = numeroSimulacoes;
		FOR_INT(aux1, 0, numeroSimulacoes, 1) {
			if (saidasSimulacoes[aux1].validade == false) {
				numeroSimulacoesValidas--;
			}
        }
        //cout << endl << "AVISO! MonteCarlo: " << idMonteCarlo << " gerou " << numeroSimulacoesValidas << "/" << numeroSimulacoes << " simulacoes!" << endl;
        if (numeroSimulacoesValidas == 0) {
			//cout << endl << "AVISO! MonteCarlo: " << idMonteCarlo << " explodiu!" << endl;
		}
		return numeroSimulacoesValidas;
	}
	
	    void geracaoSaidasLotes(int numVal, int idLote) {
		if (numVal == 0) {
			return;
		}
		int numeroSimulacoesValidas = numVal;
        int aux6;
        char caracter;
        stringstream textoWolbachia, textoHumanos, textoDengue;
        Matriz<int>* matrizWolbachia = NULL;
        Matriz<int>* matrizHumanos = NULL;
        Matriz<int>* matrizDengue = NULL;
        matrizWolbachia = new Matriz<int>(numeroCiclosSimulacao, COLUNAS_SAIDAS_WOLBACHIA);
        matrizHumanos = new Matriz<int>(numeroCiclosSimulacao, COLUNAS_SAIDAS_HUMANOS);
        matrizDengue = new Matriz<int>(numeroCiclosSimulacao, COLUNAS_SAIDAS_DENGUE);
        matrizWolbachia->zero(0);
        matrizHumanos->zero(0);
        matrizDengue->zero(0);
        FOR_INT(aux1, 0, numeroSimulacoes, 1) {
			if (saidasSimulacoes[aux1].validade == true) {
				FOR_INT(aux2, 0, numeroCiclosSimulacao, 1) {
					FOR_INT(aux3, 0, COLUNAS_SAIDAS_WOLBACHIA, 1) {
						saidasSimulacoes[aux1].quantidadesWolbachiaLote[idLote] >> aux6 >> caracter;
						matrizWolbachia->matriz[aux2][aux3] += aux6;
					}
				}
			}
        }
        FOR_INT(aux1, 0, numeroSimulacoes, 1) {
			if (saidasSimulacoes[aux1].validade == true) {
				FOR_INT(aux2, 0, numeroCiclosSimulacao, 1) {
					FOR_INT(aux3, 0, COLUNAS_SAIDAS_HUMANOS, 1) {
						saidasSimulacoes[aux1].quantidadesHumanosLote[idLote] >> aux6 >> caracter;
						matrizHumanos->matriz[aux2][aux3] += aux6;
					}
				}
			}
        }
        FOR_INT(aux1, 0, numeroSimulacoes, 1) {
			if (saidasSimulacoes[aux1].validade == true) {
				FOR_INT(aux2, 0, numeroCiclosSimulacao, 1) {
					FOR_INT(aux3, 0, COLUNAS_SAIDAS_DENGUE, 1) {
						saidasSimulacoes[aux1].quantidadesDengueLote[idLote] >> aux6 >> caracter;
						matrizDengue->matriz[aux2][aux3] += aux6;
					}
				}
			}
        }
        FOR_INT(aux1, 0, numeroCiclosSimulacao, 1) {
            FOR_INT(aux2, 0, COLUNAS_SAIDAS_WOLBACHIA, 1) {
                matrizWolbachia->matriz[aux1][aux2] = (int) ((double) matrizWolbachia->matriz[aux1][aux2] / numeroSimulacoesValidas);
            }
        }
        FOR_INT(aux1, 0, numeroCiclosSimulacao, 1) {
            FOR_INT(aux2, 0, COLUNAS_SAIDAS_HUMANOS, 1) {
                matrizHumanos->matriz[aux1][aux2] = (int) ((double) matrizHumanos->matriz[aux1][aux2] / numeroSimulacoesValidas);
            }
        }
        FOR_INT(aux1, 0, numeroCiclosSimulacao, 1) {
            FOR_INT(aux2, 0, COLUNAS_SAIDAS_DENGUE, 1) {
                matrizDengue->matriz[aux1][aux2] = (int) ((double) matrizDengue->matriz[aux1][aux2] / numeroSimulacoesValidas);
            }
        }
        FOR_INT(i, 0, numeroCiclosSimulacao, 1) {
			matrizWolbachia->matriz[i][0] = i;
			matrizHumanos->matriz[i][0] = i;
			matrizDengue->matriz[i][0] = i;
		}
        FOR_INT(aux1, 0, numeroCiclosSimulacao, 1) {
            FOR_INT(aux2, 0, COLUNAS_SAIDAS_WOLBACHIA, 1) {
                textoWolbachia << matrizWolbachia->matriz[aux1][aux2] << ";";
            }
            textoWolbachia << endl;
        }
        FOR_INT(aux1, 0, numeroCiclosSimulacao, 1) {
            FOR_INT(aux2, 0, COLUNAS_SAIDAS_HUMANOS, 1) {
                textoHumanos << matrizHumanos->matriz[aux1][aux2] << ";";
            }
            textoHumanos << endl;
        }
        FOR_INT(aux1, 0, numeroCiclosSimulacao, 1) {
            FOR_INT(aux2, 0, COLUNAS_SAIDAS_DENGUE, 1) {
                textoDengue << matrizDengue->matriz[aux1][aux2] << ";";
            }
            textoDengue << endl;
        }
        delete(matrizWolbachia);
        delete(matrizHumanos);
        delete(matrizDengue);
        char il1[TAMANHO_STRINGS_AUXILIARES];
		sprintf(il1, "%d", idLote);
		string il2 = string(il1);
        ofstream arquivoWolbachia;
        string aux5 = "Saidas";
        aux5 += SEPARADOR;
        aux5 += "MonteCarlo_";
        aux5 += stringIdMonteCarlo;
        aux5 += SEPARADOR;
        aux5 += "Lote_";
        aux5 += il2;
        aux5 += "-Wolbachia.csv";
        arquivoWolbachia.open(aux5.c_str());
        if (arquivoWolbachia.is_open()) {
            arquivoWolbachia << textoWolbachia.str();
            arquivoWolbachia.close();
        } else {
            cout << "SaidasMonteCarlo: Arquivo " << aux5 << " nao foi aberto!" << endl;
        }
        ofstream arquivoHumanos;
        aux5 = "Saidas";
        aux5 += SEPARADOR;
        aux5 += "MonteCarlo_";
        aux5 += stringIdMonteCarlo;
        aux5 += SEPARADOR;
        aux5 += "Lote_";
        aux5 += il2;
        aux5 += "-Humanos.csv";
        arquivoHumanos.open(aux5.c_str());
        if (arquivoHumanos.is_open()) {
            arquivoHumanos << textoHumanos.str();
            arquivoHumanos.close();
        } else {
            cout << "SaidasMonteCarlo: Arquivo " << aux5 << " nao foi aberto!" << endl;
        }
        ofstream arquivoDengue;
        aux5 = "Saidas";
        aux5 += SEPARADOR;
        aux5 += "MonteCarlo_";
        aux5 += stringIdMonteCarlo;
        aux5 += SEPARADOR;
        aux5 += "Lote_";
        aux5 += il2;
        aux5 += "-Dengue.csv";
        arquivoDengue.open(aux5.c_str());
        if (arquivoDengue.is_open()) {
            arquivoDengue << textoDengue.str();
            arquivoDengue.close();
        } else {
            cout << "SaidasMonteCarlo: Arquivo " << aux5 << " nao foi aberto!" << endl;
        }
    }

    void geracaoSaidasQuadra(int numVal) {
		if (numVal == 0) {
			return;
		}
		int numeroSimulacoesValidas = numVal;
        int aux6;
        char caracter;
        stringstream textoWolbachia, textoHumanos, textoDengue;
        Matriz<int>* matrizWolbachia = NULL;
        Matriz<int>* matrizHumanos = NULL;
        Matriz<int>* matrizDengue = NULL;
        matrizWolbachia = new Matriz<int>(numeroCiclosSimulacao, COLUNAS_SAIDAS_WOLBACHIA);
        matrizHumanos = new Matriz<int>(numeroCiclosSimulacao, COLUNAS_SAIDAS_HUMANOS);
        matrizDengue = new Matriz<int>(numeroCiclosSimulacao, COLUNAS_SAIDAS_DENGUE);
        matrizWolbachia->zero(0);
        matrizHumanos->zero(0);
        matrizDengue->zero(0);
        FOR_INT(aux1, 0, numeroSimulacoes, 1) {
			if (saidasSimulacoes[aux1].validade == true) {
				FOR_INT(aux2, 0, numeroCiclosSimulacao, 1) {
					FOR_INT(aux3, 0, COLUNAS_SAIDAS_WOLBACHIA, 1) {
						saidasSimulacoes[aux1].quantidadesWolbachiaQuadra >> aux6 >> caracter;
						matrizWolbachia->matriz[aux2][aux3] += aux6;
					}
				}
			}
        }
        FOR_INT(aux1, 0, numeroSimulacoes, 1) {
			if (saidasSimulacoes[aux1].validade == true) {
				FOR_INT(aux2, 0, numeroCiclosSimulacao, 1) {
					FOR_INT(aux3, 0, COLUNAS_SAIDAS_HUMANOS, 1) {
						saidasSimulacoes[aux1].quantidadesHumanosQuadra >> aux6 >> caracter;
						matrizHumanos->matriz[aux2][aux3] += aux6;
					}
				}
			}
        }
        FOR_INT(aux1, 0, numeroSimulacoes, 1) {
			if (saidasSimulacoes[aux1].validade == true) {
				FOR_INT(aux2, 0, numeroCiclosSimulacao, 1) {
					FOR_INT(aux3, 0, COLUNAS_SAIDAS_DENGUE, 1) {
						saidasSimulacoes[aux1].quantidadesDengueQuadra >> aux6 >> caracter;
						matrizDengue->matriz[aux2][aux3] += aux6;
					}
				}
			}
        }
        FOR_INT(aux1, 0, numeroCiclosSimulacao, 1) {
            FOR_INT(aux2, 0, COLUNAS_SAIDAS_WOLBACHIA, 1) {
                matrizWolbachia->matriz[aux1][aux2] = (int) ((double) matrizWolbachia->matriz[aux1][aux2] / numeroSimulacoesValidas);
            }
        }
        FOR_INT(aux1, 0, numeroCiclosSimulacao, 1) {
            FOR_INT(aux2, 0, COLUNAS_SAIDAS_HUMANOS, 1) {
                matrizHumanos->matriz[aux1][aux2] = (int) ((double) matrizHumanos->matriz[aux1][aux2] / numeroSimulacoesValidas);
            }
        }
        FOR_INT(aux1, 0, numeroCiclosSimulacao, 1) {
            FOR_INT(aux2, 0, COLUNAS_SAIDAS_DENGUE, 1) {
                matrizDengue->matriz[aux1][aux2] = (int) ((double) matrizDengue->matriz[aux1][aux2] / numeroSimulacoesValidas);
            }
        }
        FOR_INT(i, 0, numeroCiclosSimulacao, 1) {
			matrizWolbachia->matriz[i][0] = i;
			matrizHumanos->matriz[i][0] = i;
			matrizDengue->matriz[i][0] = i;
		}
        FOR_INT(aux1, 0, numeroCiclosSimulacao, 1) {
            FOR_INT(aux2, 0, COLUNAS_SAIDAS_WOLBACHIA, 1) {
                textoWolbachia << matrizWolbachia->matriz[aux1][aux2] << ";";
            }
            textoWolbachia << endl;
        }
        FOR_INT(aux1, 0, numeroCiclosSimulacao, 1) {
            FOR_INT(aux2, 0, COLUNAS_SAIDAS_HUMANOS, 1) {
                textoHumanos << matrizHumanos->matriz[aux1][aux2] << ";";
            }
            textoHumanos << endl;
        }
        FOR_INT(aux1, 0, numeroCiclosSimulacao, 1) {
            FOR_INT(aux2, 0, COLUNAS_SAIDAS_DENGUE, 1) {
                textoDengue << matrizDengue->matriz[aux1][aux2] << ";";
            }
            textoDengue << endl;
        }
        delete(matrizWolbachia);
        delete(matrizHumanos);
        delete(matrizDengue);
        ofstream arquivoWolbachia;
        string aux5 = "Saidas";
        aux5 += SEPARADOR;
        aux5 += "MonteCarlo_";
        aux5 += stringIdMonteCarlo;
        aux5 += SEPARADOR;
        aux5 += "Quadra-Wolbachia.csv";
        arquivoWolbachia.open(aux5.c_str());
        if (arquivoWolbachia.is_open()) {
            arquivoWolbachia << textoWolbachia.str();
            arquivoWolbachia.close();
        } else {
            cout << "SaidasMonteCarlo: Arquivo " << aux5 << " nao foi aberto!" << endl;
        }
        ofstream arquivoHumanos;
        aux5 = "Saidas";
        aux5 += SEPARADOR;
        aux5 += "MonteCarlo_";
        aux5 += stringIdMonteCarlo;
        aux5 += SEPARADOR;
        aux5 += "Quadra-Humanos.csv";
        arquivoHumanos.open(aux5.c_str());
        if (arquivoHumanos.is_open()) {
            arquivoHumanos << textoHumanos.str();
            arquivoHumanos.close();
        } else {
            cout << "SaidasMonteCarlo: Arquivo " << aux5 << " nao foi aberto!" << endl;
        }
        ofstream arquivoDengue;
        aux5 = "Saidas";
        aux5 += SEPARADOR;
        aux5 += "MonteCarlo_";
        aux5 += stringIdMonteCarlo;
        aux5 += SEPARADOR;
        aux5 += "Quadra-Dengue.csv";
        arquivoDengue.open(aux5.c_str());
        if (arquivoDengue.is_open()) {
            arquivoDengue << textoDengue.str();
            arquivoDengue.close();
        } else {
            cout << "SaidasMonteCarlo: Arquivo " << aux5 << " nao foi aberto!" << endl;
        }
    }

};

#endif
