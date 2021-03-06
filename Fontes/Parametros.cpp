#ifndef _PARAMETROS_
#define _PARAMETROS_

#include "Vetor.cpp"
#include "Parametro.cpp"
#include "MacrosParametros.cpp"

// Classe que armazena todos os parâmetros da simulação
class Parametros {
public:

	int quantLotes; // quantidade de lotes 
	string pastaEntrada; // pasta de entrada
	Vetor<Parametro>* pSIM; // parâmetros SIM
	Vetor<Parametro>* pSMC; // parâmetros SMC

	Vetor<Parametro>** pACA; // parâmetros ACA
	Vetor<Parametro>** pAMB; // parâmetros AMB
	Vetor<Parametro>** pCNA; // parâmetros CNA
	Vetor<Parametro>** pDEN; // parâmetros DEN
	Vetor<Parametro>** pGER; // parâmetros GER
	Vetor<Parametro>** pINS; // parâmetros INS
	Vetor<Parametro>** pMOV; // parâmetros MOV
	Vetor<Parametro>** pTRA; // parâmetros TRA

	// Realiza a alocação das estruturas de dados para os parâmetros e realiza a leitura dos arquivos de entrada
	Parametros(string pastaEntrada, int quantLotes) {
		this->pastaEntrada = pastaEntrada;
		this->quantLotes = quantLotes;
		pSIM = lerParametros(QUANTIDADE_PARAMETROS_SIM, "SIM.csv");
		pSMC = lerParametros(QUANTIDADE_PARAMETROS_SMC, "SMC.csv");
		pACA = new Vetor<Parametro>*[quantLotes];
		pAMB = new Vetor<Parametro>*[quantLotes];
		pCNA = new Vetor<Parametro>*[quantLotes];
		pDEN = new Vetor<Parametro>*[quantLotes];
		pGER = new Vetor<Parametro>*[quantLotes];
		pINS = new Vetor<Parametro>*[quantLotes];
		pMOV = new Vetor<Parametro>*[quantLotes];
		pTRA = new Vetor<Parametro>*[quantLotes];
		for (int i = 0; i < quantLotes; ++i) {
			string aux1 = "Lote_";
			char aux2[TAMANHO_STRINGS_AUXILIARES];
			sprintf(aux2, "%d", i);
			string aux3 = string(aux2);
			aux1 += aux3;
			aux1 += SEPARADOR;
			string aux4 = aux1;
			aux4 += "ACA.csv";
			pACA[i] = lerParametros(QUANTIDADE_PARAMETROS_ACA, aux4);
			aux4 = aux1;
			aux4 += "AMB.csv";
			pAMB[i] = lerParametros(QUANTIDADE_PARAMETROS_AMB, aux4);
			aux4 = aux1;
			aux4 += "CNA.csv";
			pCNA[i] = lerParametros(QUANTIDADE_PARAMETROS_CNA, aux4);
			aux4 = aux1;
			aux4 += "DEN.csv";
			pDEN[i] = lerParametros(QUANTIDADE_PARAMETROS_DEN, aux4);
			aux4 = aux1;
			aux4 += "GER.csv";
			pGER[i] = lerParametros(QUANTIDADE_PARAMETROS_GER, aux4);
			aux4 = aux1;
			aux4 += "INS.csv";
			pINS[i] = lerParametros(QUANTIDADE_PARAMETROS_INS, aux4);
			aux4 = aux1;
			aux4 += "MOV.csv";
			pMOV[i] = lerParametros(QUANTIDADE_PARAMETROS_MOV, aux4);
			aux4 = aux1;
			aux4 += "TRA.csv";
			pTRA[i] = lerParametros(QUANTIDADE_PARAMETROS_TRA, aux4);
		}
	}

	~Parametros() {
		delete (pSIM);
		delete (pSMC);
		FOR_INT(i, 0, quantLotes, 1)
		{
			delete (pACA[i]);
			delete (pAMB[i]);
			delete (pCNA[i]);
			delete (pDEN[i]);
			delete (pGER[i]);
			delete (pINS[i]);
			delete (pMOV[i]);
			delete (pTRA[i]);
		}
		delete[] (pACA);
		delete[] (pAMB);
		delete[] (pCNA);
		delete[] (pDEN);
		delete[] (pGER);
		delete[] (pINS);
		delete[] (pMOV);
		delete[] (pTRA);
	}

	// Lẽ os parâmetros dos arquivos de entrada
	Vetor<Parametro>* lerParametros(int numeroParametros, string sufixo) {
		Vetor < Parametro > *vetorParametros = new Vetor<Parametro>(numeroParametros);
		string aux1 = pastaEntrada;
		aux1 += sufixo.c_str();
		ifstream arquivoEntrada;
		arquivoEntrada.open(aux1.c_str());
		if (arquivoEntrada.is_open()) {
			stringstream streamEntrada;
			streamEntrada << string(static_cast<stringstream const&>(stringstream() << arquivoEntrada.rdbuf()).str());
			arquivoEntrada.close();
			string cabecalho;
			getline(streamEntrada, cabecalho);
			int i = 0;
			FOR_INT(j, 0, numeroParametros, 1)
			{
				string codigo;
				double valorMinimo;
				double valorMaximo;
				string comentario;
				char caracter;
				FOR_INT(j, 0, 6, 1)
				{
					streamEntrada >> caracter;
					codigo += caracter;
				}
				streamEntrada >> caracter >> valorMinimo >> caracter >> valorMaximo;
				if (valorMinimo > valorMaximo) {
					cout << "Erro: valor minimo maior que valor maximo no parametro: " << sufixo[0] << sufixo[1] << sufixo[2] << " " << i << endl;
				}
				getline(streamEntrada, comentario);
				vetorParametros->vetor[i] = Parametro(valorMinimo, valorMaximo);
				i++;
			}
		} else {
			cout << "Arquivo " << aux1 << " nao foi aberto!" << endl;
		}
		return vetorParametros;
	}

};

#endif
