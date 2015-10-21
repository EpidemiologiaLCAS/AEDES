#ifndef _QUADRA_
#define _QUADRA_

using namespace std;

#include "Lote.cpp"
#include "Posicao.cpp"
#include "Lista.cpp"
#include "Parametros.cpp"
#include "CoordenadaGeo.cpp"

// Classe que representa uma quadra
class Quadra {
public:

	int quantLotes; // quantidade de lotes
	Lote** lotes; // lotes da quadra
	Parametros* parametros; // parâmetros

	Quadra(int quantLotes, Parametros* parametros) {
		this->quantLotes = quantLotes;
		this->parametros = parametros;
		this->lotes = new Lote*[quantLotes]();
		for (int i = 0; i < quantLotes; ++i) {
			this->lotes[i] = NULL;
		}
	}

	~Quadra() {
		for (int i = 0; i < quantLotes; ++i) {
			delete (lotes[i]);
		}
		delete[] (lotes);
	}

	// Adiciona um lote na quadra
	void adicionarLote(int _id, int LINHAS_LOTE, int COLUNAS_LOTE) {
		lotes[_id] = new Lote(_id, LINHAS_LOTE, COLUNAS_LOTE);
	}

	// Adiciona uma conexão entre lotes visível para os agentes mosquitos
	void adicionarConexaoInternaEntreLotesMosquitos(Posicao posicao1, int _idLoteOrigem, Posicao posicao2, int _idLoteDestino) {
		lotes[_idLoteOrigem]->lote->matriz[posicao1.x][posicao1.y].listaVizinhancaMosquitos.insercaoLista(new Conexao(posicao2, _idLoteDestino));
		lotes[_idLoteDestino]->lote->matriz[posicao2.x][posicao2.y].listaVizinhancaMosquitos.insercaoLista(new Conexao(posicao1, _idLoteOrigem));
	}

	// Adiciona uma conexão entre lotes visível para os agentes humanos
	void adicionarConexaoInternaEntreLotesHumanos(Posicao posicao1, int _idLoteOrigem, Posicao posicao2, int _idLoteDestino) {
		lotes[_idLoteOrigem]->lote->matriz[posicao1.x][posicao1.y].listaVizinhancaHumanos.insercaoLista(new Conexao(posicao2, _idLoteDestino));
		lotes[_idLoteDestino]->lote->matriz[posicao2.x][posicao2.y].listaVizinhancaHumanos.insercaoLista(new Conexao(posicao1, _idLoteOrigem));
	}

	// Adiciona uma posição no raio de percepção de agentes humanos
	void adicionarPosicaoRaioPercepcaoHumanos(Posicao posicao1, int _idLoteOrigem, Posicao posicao2, int _idLoteDestino) {
		lotes[_idLoteOrigem]->lote->matriz[posicao1.x][posicao1.y].listaAreaPercepcaoHumanos.insercaoLista(new Conexao(posicao2, _idLoteDestino));
		lotes[_idLoteDestino]->lote->matriz[posicao2.x][posicao2.y].listaAreaPercepcaoHumanos.insercaoLista(new Conexao(posicao1, _idLoteOrigem));
	}

	// Adiciona uma posição no raio de percepção de agentes mosquitos machos
	void adicionarPosicaoRaioPercepcaoMosquitosMachos(Posicao posicao1, int _idLoteOrigem, Posicao posicao2, int _idLoteDestino) {
		lotes[_idLoteOrigem]->lote->matriz[posicao1.x][posicao1.y].listaAreaPercepcaoMosquitosMachos.insercaoLista(new Conexao(posicao2, _idLoteDestino));
		lotes[_idLoteDestino]->lote->matriz[posicao2.x][posicao2.y].listaAreaPercepcaoMosquitosMachos.insercaoLista(new Conexao(posicao1, _idLoteOrigem));
	}

	// Adiciona uma posição no raio de percepção de criadouros
	void adicionarPosicaoRaioPercepcaoCriadouros(Posicao posicao1, int _idLoteOrigem, Posicao posicao2, int _idLoteDestino) {
		lotes[_idLoteOrigem]->lote->matriz[posicao1.x][posicao1.y].listaAreaPercepcaoCriadouros.insercaoLista(new Conexao(posicao2, _idLoteDestino));
		lotes[_idLoteDestino]->lote->matriz[posicao2.x][posicao2.y].listaAreaPercepcaoCriadouros.insercaoLista(new Conexao(posicao1, _idLoteOrigem));
	}

	// Lê o arquivo criando as conexões visíveis para agentes humanos
	void criacaoConexoesHumanos() {
		char caracter;
		FOR_INT(i, 0, quantLotes, 1)
		{
			ifstream arquivoQuadra;
			arquivoQuadra.open("./Entradas/ConexoesEntreLotes.csv");
			if (arquivoQuadra.is_open()) {
				stringstream streamEntrada;
				streamEntrada << string(static_cast<stringstream const&>(stringstream() << arquivoQuadra.rdbuf()).str());
				arquivoQuadra.close();
				string cabecalho;
				getline(streamEntrada, cabecalho);
				FOR_INT(k, 0, quantLotes, 1)
				{
					int idLote, quantConexoesLote, idConexao, quantConexoesInternasLoteParaHumanos;
					streamEntrada >> idLote >> caracter >> quantConexoesLote;
					FOR_INT(j, 0, quantConexoesLote, 1)
					{
						streamEntrada >> caracter >> idConexao >> caracter >> quantConexoesInternasLoteParaHumanos;
						FOR_INT(p, 0, quantConexoesInternasLoteParaHumanos, 1)
						{
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

	// Lê o arquivo criando as conexões visíveis para agentes mosquitos
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
				FOR_INT(j, 0, quantConexaos, 1)
				{
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

	// Lê o arquivo definindo os lotes que terão controle químico para não alados
	void definicaoControleQuimicoNaoAlados() {
		char caracter;
		ifstream arquivoControleQuimico;
		arquivoControleQuimico.open("./Entradas/ControleQuimicoNaoAlados.csv");
		if (arquivoControleQuimico.is_open()) {
			int quant;
			arquivoControleQuimico >> quant >> caracter;
			FOR_INT(i, 0, quant, 1)
			{
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

	// Lê o arquivo definindo os lotes que terão controle químico para alados
	void definicaoControleQuimicoAlados() {
		char caracter;
		ifstream arquivoControleQuimico;
		arquivoControleQuimico.open("./Entradas/ControleQuimicoAlados.csv");
		if (arquivoControleQuimico.is_open()) {
			int quant;
			arquivoControleQuimico >> quant >> caracter;
			FOR_INT(i, 0, quant, 1)
			{
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

	// Lê o arquivo definindo os lotes que terão controle mecânico para não alados
	void definicaoControleMecanicoNaoAlados() {
		char caracter;
		ifstream arquivoControleMecanico;
		arquivoControleMecanico.open("./Entradas/ControleMecanicoNaoAlados.csv");
		if (arquivoControleMecanico.is_open()) {
			int quant;
			arquivoControleMecanico >> quant >> caracter;
			FOR_INT(i, 0, quant, 1)
			{
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

	// Lê as coordenadas georeferenciadas do arquivo para cada posição de cada lote
	void leituraCoordenadasGeo() {
		char caracter = '-';
		double x, y;
		ifstream arquivoCoordenadas;
		arquivoCoordenadas.open("./Entradas/CoordenadasQuadra445.csv");
		if (arquivoCoordenadas.is_open()) {
			string cabecalho;
			getline(arquivoCoordenadas, cabecalho);
			FOR_INT(lote, 0, quantLotes, 1)
			{
				int LINHAS_LOTE = lotes[lote]->lote->linhasMatriz;
				int COLUNAS_LOTE = lotes[lote]->lote->colunasMatriz;
				FOR_INT(i, 0, LINHAS_LOTE, 1)
				{
					FOR_INT(j, 0, COLUNAS_LOTE, 1)
					{
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

	// Lê o arquivo criando os raios de percepção de agentes humanos
	void criacaoRaiosPercepcaoHumanos() {
		char caracter;
		ifstream arquivoRaiosHumanos;
		arquivoRaiosHumanos.open("./Entradas/RaiosPercepcaoHumanos.csv");
		if (arquivoRaiosHumanos.is_open()) {
			string cabecalho;
			getline(arquivoRaiosHumanos, cabecalho);
			while (!arquivoRaiosHumanos.eof()) {
				int idOrigem, quantConexaos, idDestino;
				Posicao origem, destino;
				arquivoRaiosHumanos >> origem.x >> caracter >> origem.y >> caracter >> idOrigem >> caracter >> quantConexaos >> caracter >> idDestino >> caracter;
				FOR_INT(j, 0, quantConexaos, 1)
				{
					arquivoRaiosHumanos >> destino.x >> caracter >> destino.y >> caracter;
					this->adicionarPosicaoRaioPercepcaoHumanos(origem, idOrigem, destino, idDestino);
				}
			}
			arquivoRaiosHumanos.close();
		} else {
			cout << "Arquivo ./Entradas/RaiosPercepcaoHumanos.csv nao foi aberto!" << endl;
			exit(1);
		}
	}

	// Lê o arquivo criando os raios de percepção de agentes mosquitos machos
	void criacaoRaiosPercepcaoMosquitosMachos() {
		char caracter;
		ifstream arquivoRaiosMosquitosMachos;
		arquivoRaiosMosquitosMachos.open("./Entradas/RaiosPercepcaoMosquitosMachos.csv");
		if (arquivoRaiosMosquitosMachos.is_open()) {
			string cabecalho;
			getline(arquivoRaiosMosquitosMachos, cabecalho);
			while (!arquivoRaiosMosquitosMachos.eof()) {
				int idOrigem, quantConexaos, idDestino;
				Posicao origem, destino;
				arquivoRaiosMosquitosMachos >> origem.x >> caracter >> origem.y >> caracter >> idOrigem >> caracter >> quantConexaos >> caracter >> idDestino >> caracter;
				FOR_INT(j, 0, quantConexaos, 1)
				{
					arquivoRaiosMosquitosMachos >> destino.x >> caracter >> destino.y >> caracter;
					this->adicionarPosicaoRaioPercepcaoMosquitosMachos(origem, idOrigem, destino, idDestino);
				}
			}
			arquivoRaiosMosquitosMachos.close();
		} else {
			cout << "Arquivo ./Entradas/RaiosPercepcaoMosquitosMachos.csv nao foi aberto!" << endl;
			exit(1);
		}
	}

	// Lê o arquivo criando os raios de percepção de criadouros
	void criacaoRaiosPercepcaoCriadouros() {
		char caracter;
		ifstream arquivoRaiosCriadouros;
		arquivoRaiosCriadouros.open("./Entradas/RaiosPercepcaoCriadouros.csv");
		if (arquivoRaiosCriadouros.is_open()) {
			string cabecalho;
			getline(arquivoRaiosCriadouros, cabecalho);
			while (!arquivoRaiosCriadouros.eof()) {
				int idOrigem, quantConexaos, idDestino;
				Posicao origem, destino;
				arquivoRaiosCriadouros >> origem.x >> caracter >> origem.y >> caracter >> idOrigem >> caracter >> quantConexaos >> caracter >> idDestino >> caracter;
				FOR_INT(j, 0, quantConexaos, 1)
				{
					arquivoRaiosCriadouros >> destino.x >> caracter >> destino.y >> caracter;
					this->adicionarPosicaoRaioPercepcaoCriadouros(origem, idOrigem, destino, idDestino);
				}
			}
			arquivoRaiosCriadouros.close();
		} else {
			cout << "Arquivo ./Entradas/RaiosPercepcaoCriadouros.csv nao foi aberto!" << endl;
			exit(1);
		}
	}

	// Define criadouros em posições aleatórias em todos os lotes
	void criacaoCriadouros() {
		FOR_INT(i, 0, quantLotes, 1)
		{
			FOR_INT(j, 0, QUANTIDADE_CRIADOUROS_POR_LOTE, 1)
			{
				int x = rand() % lotes[i]->lote->linhasMatriz;
				int y = rand() % lotes[i]->lote->colunasMatriz;
				lotes[i]->lote->matriz[x][y].criadouro = true;
			}
		}
	}

};

#endif
