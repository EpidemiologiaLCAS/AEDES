#ifndef QUADRA
#define QUADRA

using namespace std;

#include "Lote.cpp"
#include "Posicao.cpp"
#include "Lista.cpp"
#include "Parametros.cpp"
#include "CoordenadaGeo.cpp"

class Quadra {
public:

    int quantLotes;
    Lote** lotes;
    Parametros* parametros;

    Quadra(int _quantLotes, Parametros* _parametros) {
        quantLotes = _quantLotes;
        parametros = _parametros;
        lotes = new Lote*[quantLotes]();
        for (int i = 0; i < quantLotes; ++i) {
			lotes[i] = NULL;
		}
    }

    ~Quadra() {
		for (int i = 0; i < quantLotes; ++i) {
			delete(lotes[i]);
		}
        delete[](lotes);
    }

    void adicionarLote(int _id, int linhasLote, int colunasLote) {
		lotes[_id] = new Lote(_id, linhasLote, colunasLote);
    }
    
    void adicionarConexaoInternaEntreLotesMosquitos(Posicao posicao1, int _idLoteOrigem, Posicao posicao2, int _idLoteDestino) {
		lotes[_idLoteOrigem]->lote->matriz[posicao1.x][posicao1.y].listaVizinhancaMosquitos.insercaoLista(new ElementoLista<Conexao*>(new Conexao(posicao2, _idLoteDestino)));
		lotes[_idLoteDestino]->lote->matriz[posicao2.x][posicao2.y].listaVizinhancaMosquitos.insercaoLista(new ElementoLista<Conexao*>(new Conexao(posicao1, _idLoteOrigem)));
    }

	void adicionarConexaoInternaEntreLotesHumanos(Posicao posicao1, int _idLoteOrigem, Posicao posicao2, int _idLoteDestino) {
		lotes[_idLoteOrigem]->lote->matriz[posicao1.x][posicao1.y].listaVizinhancaHumanos.insercaoLista(new ElementoLista<Conexao*>(new Conexao(posicao2, _idLoteDestino)));
		lotes[_idLoteDestino]->lote->matriz[posicao2.x][posicao2.y].listaVizinhancaHumanos.insercaoLista(new ElementoLista<Conexao*>(new Conexao(posicao1, _idLoteOrigem)));
    }
	
	void criacaoConexoesHumanos() {
		char caracter;
		FORINT(i, 0, quantLotes, 1) {
			ifstream arquivoQuadra;
			arquivoQuadra.open("./Entradas/ConexoesEntreLotes.csv");
			if (arquivoQuadra.is_open()) {
				stringstream streamEntrada;
				streamEntrada << string(static_cast<stringstream const&>(stringstream() << arquivoQuadra.rdbuf()).str());
				arquivoQuadra.close();
				string cabecalho;
				getline(streamEntrada, cabecalho);
				FORINT(k, 0, quantLotes, 1) {
					int idLote, quantConexoesLote, idConexao, quantConexoesInternasLoteParaHumanos;
					streamEntrada >> idLote >> caracter >> quantConexoesLote;
					FORINT(j, 0 , quantConexoesLote, 1) {
						streamEntrada >> caracter >> idConexao >> caracter >> quantConexoesInternasLoteParaHumanos;
						FORINT(p, 0, quantConexoesInternasLoteParaHumanos, 1) {
							this->adicionarConexaoInternaEntreLotesHumanos(Posicao(rand() % NUMERO_LINHAS_AMBIENTE(idLote), rand() % NUMERO_COLUNAS_AMBIENTE(idLote)), idLote, Posicao(rand() % NUMERO_LINHAS_AMBIENTE(idConexao), rand() % NUMERO_COLUNAS_AMBIENTE(idConexao)), idConexao);
						}
					}
				}
			} else {
				 cout << "Arquivo ./Entradas/ConexoesEntreLotes.csv nao foi aberto!" << endl;
				 exit(1);
			}
		}
	}
	
	void criacaoConexoesMosquitos() {
		char caracter;
		ifstream arquivoVizinhancas;
		arquivoVizinhancas.open("./Entradas/ConexoesIntraLotes.csv");
		if (arquivoVizinhancas.is_open()) {
			string cabecalho;
			getline(arquivoVizinhancas, cabecalho);
			while (!arquivoVizinhancas.eof()) {
				int idOrigem, quantConexaos, idDestino;
				Posicao origem, destino;
				arquivoVizinhancas >> origem.x >> caracter >> origem.y >> caracter >> idOrigem >> caracter >> quantConexaos >> caracter >> idDestino >> caracter;
				FORINT(j, 0 , quantConexaos, 1) {
					arquivoVizinhancas >> destino.x >> caracter >> destino.y >> caracter;
					this->adicionarConexaoInternaEntreLotesMosquitos(origem, idOrigem, destino, idDestino);
				}
			}
			arquivoVizinhancas.close();
		} else {
			 cout << "Arquivo ./Entradas/ConexoesIntraLotes.csv nao foi aberto!" << endl;
			 exit(1);
		}
	}
	
	void definicaoControleQuimicoNaoAlados() {
		char caracter;
		ifstream arquivoControleQuimico;
		arquivoControleQuimico.open("./Entradas/ControleQuimicoNaoAlados.csv");
		if (arquivoControleQuimico.is_open()) {
			int quant;
			arquivoControleQuimico >> quant >> caracter;
			FORINT(i, 0 , quant, 1) {
				int idLote;
				arquivoControleQuimico >> idLote >> caracter;
				lotes[idLote]->controleQuimicoLarvas = 1.0;
				lotes[idLote]->controleQuimicoPupas = 1.0;
			}
			arquivoControleQuimico.close();
		} else {
			 cout << "Arquivo ./Entradas/ControleQuimicoNaoAlados.csv nao foi aberto!" << endl;
			 exit(1);
		}
	}

	void definicaoControleQuimicoAlados() {
		char caracter;
		ifstream arquivoControleQuimico;
		arquivoControleQuimico.open("./Entradas/ControleQuimicoAlados.csv");
		if (arquivoControleQuimico.is_open()) {
			int quant;
			arquivoControleQuimico >> quant >> caracter;
			FORINT(i, 0 , quant, 1) {
				int idLote;
				arquivoControleQuimico >> idLote >> caracter;
				lotes[idLote]->controleQuimicoAlados = true;
			}
			arquivoControleQuimico.close();
		} else {
			 cout << "Arquivo ./Entradas/ControleQuimicoAlados.csv nao foi aberto!" << endl;
			 exit(1);
		}
	}
	
	void definicaoControleMecanicoNaoAlados() {
		char caracter;
		ifstream arquivoControleMecanico;
		arquivoControleMecanico.open("./Entradas/ControleMecanicoNaoAlados.csv");
		if (arquivoControleMecanico.is_open()) {
			int quant;
			arquivoControleMecanico >> quant >> caracter;
			FORINT(i, 0 , quant, 1) {
				int idLote;
				arquivoControleMecanico >> idLote >> caracter;
				lotes[idLote]->controleMecanicoNaoAlados = true;
			}
			arquivoControleMecanico.close();
		} else {
			 cout << "Arquivo ./Entradas/ControleMecanicoNaoAlados.csv nao foi aberto!" << endl;
			 exit(1);
		}
	}
	
	void leituraCoordenadasGeo() {
		char caracter = '-';
		double x, y;
		ifstream arquivoCoordenadas;
		arquivoCoordenadas.open("./Entradas/CoordenadasQuadra445.csv");
		if (arquivoCoordenadas.is_open()) {
			string cabecalho;
			getline(arquivoCoordenadas, cabecalho);
			FORINT(lote, 0, quantLotes, 1) {
				int linhasLote = lotes[lote]->lote->linhasMatriz;
				int colunasLote = lotes[lote]->lote->colunasMatriz;
				FORINT(i, 0, linhasLote, 1) {
					FORINT(j, 0, colunasLote, 1) {
						while (caracter != ';') {
							arquivoCoordenadas >> caracter;
						}
						arquivoCoordenadas >> x >> caracter >> y;
						lotes[lote]->lote->matriz[i][j].coordenadaGeo.x = x;
						lotes[lote]->lote->matriz[i][j].coordenadaGeo.y = y;
						caracter = '-';
					}
				}
			}
			arquivoCoordenadas.close();
		} else {
			 cout << "Arquivo ./Entradas/CoordenadasQuadra445.csv nao foi aberto!" << endl;
			 exit(1);
		}
	}

};

#endif
