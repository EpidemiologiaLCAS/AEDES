#ifndef _MANIPULADORMOSQUITOS_
#define _MANIPULADORMOSQUITOS_

#include "Lista.cpp"
#include "ElementoLista.cpp"
#include "Mosquito.cpp"
#include "MosquitoMacho.cpp"
#include "MosquitoFemea.cpp"
#include "Parametros.cpp"
#include "Quadra.cpp"
#include "ListaMosquitos.cpp"

// Classe que contém métodos para a manipulação de agentes mosquitos
class ManipuladorMosquitos {
public:

	ListaMosquitos* listaMosquitos; // lista de mosquitos
	int contadorAcasalamentosCiclo; // contador de acasalamentos para cada ciclo
	int contadorAcasalamentosTotal; // contador de acasalamentos geral
	int contadorIDs; // contador de ids para mosquitos
	int quantLotes; // quantidade de lotes
	Parametros* parametros; // parâmetros
	Quadra* quadra; // quadra

	ManipuladorMosquitos(Parametros* parametros, Quadra* quadra, int quantLotes) {
		this->parametros = parametros;
		this->quadra = quadra;
		this->quantLotes = quantLotes;
		this->listaMosquitos = new ListaMosquitos();
		this->contadorAcasalamentosCiclo = 0;
		this->contadorAcasalamentosTotal = 0;
		this->contadorIDs = 0;
		criacao();
	}

	~ManipuladorMosquitos() {
		delete (listaMosquitos);
	}

	// Insere agentes mosquitos na simulação de acordo com os parâmetros
	void insercaoMosquitos(int id, char sexo, char saudeWolbachia, char saudeDengue, int sorotipo, char fase, int idLote, int idade) {
		int lx, ly;
		Mosquito* mosquito = NULL;
		do {
			lx = rand() % LINHAS_LOTE(idLote);
			ly = rand() % COLUNAS_LOTE(idLote);
		} while (POSICAO_LOTE(idLote, lx, ly).quantidadeTotalMosquitosPosicao() >= CAPACIDADE_MAXIMA_POSICAO_MOSQUITOS(idLote));
		if (sexo == MACHO) {
			mosquito = new MosquitoMacho(id, saudeWolbachia, fase, idade, idLote, lx, ly);
		} else {
			mosquito = new MosquitoFemea(id, saudeWolbachia, saudeDengue, sorotipo, fase, idade, idLote, lx, ly);
		}
		listaMosquitos->lista->insercaoLista(mosquito);
		switch (fase) {
		case OVO: {
			LISTA_NAO_ALADOS(idLote, lx, ly).insercaoLista(mosquito);
		}
			break;
		default: {
			switch (sexo) {
			case MACHO: {
				LISTA_MACHOS(idLote, lx, ly).insercaoLista(mosquito);
			}
				break;
			case FEMEA: {
				LISTA_FEMEAS(idLote, lx, ly).insercaoLista(mosquito);
			}
				break;
			}
		}
			break;
		}
	}

	// Insere agentes mosquitos na simulação de acordo com os parâmetros
	void criacao() {
		FOR_INT(idLote, 0, quantLotes, 1)
		{
			FOR_INT(indice1, 0, 17, 1)
			{
				switch (indice1) {
				case 0: {
					FOR_INT(i, 0, QUANTIDADE_MS1(idLote), 1)
					insercaoMosquitos(contadorIDs++, MACHO, SAUDAVEL, SAUDAVEL, 0, OVO, idLote, IDADE_OVOS(idLote));
				}
					break;
				case 1: {
					FOR_INT(i, 0, QUANTIDADE_MS2(idLote), 1)
					insercaoMosquitos(contadorIDs++, MACHO, SAUDAVEL, SAUDAVEL, 0, ATIVO, idLote, IDADE_MACHOS_ATIVOS_SAUDAVEIS(idLote));
				}
					break;
				case 2: {
					FOR_INT(i, 0, QUANTIDADE_MS3(idLote), 1)
					insercaoMosquitos(contadorIDs++, MACHO, SAUDAVEL, SAUDAVEL, 0, DECADENTE, idLote, IDADE_MACHOS_DECADENTES_SAUDAVEIS(idLote));
				}
					break;
				case 3: {
					FOR_INT(i, 0, QUANTIDADE_FS1(idLote), 1)
					insercaoMosquitos(contadorIDs++, FEMEA, SAUDAVEL, SAUDAVEL, 0, OVO, idLote, IDADE_OVOS(idLote));
				}
					break;
				case 4: {
					FOR_INT(i, 0, QUANTIDADE_FS2(idLote), 1)
					insercaoMosquitos(contadorIDs++, FEMEA, SAUDAVEL, SAUDAVEL, 0, ATIVO, idLote, IDADE_FEMEAS_ATIVAS_SAUDAVEIS(idLote));
				}
					break;
				case 5: {
					FOR_INT(i, 0, QUANTIDADE_FS3(idLote), 1)
					insercaoMosquitos(contadorIDs++, FEMEA, SAUDAVEL, SAUDAVEL, 0, DECADENTE, idLote, IDADE_FEMEAS_DECADENTES_SAUDAVEIS(idLote));
				}
					break;
				case 6: {
					FOR_INT(i, 0, QUANTIDADE_MI1(idLote), 1)
					insercaoMosquitos(contadorIDs++, MACHO, INFECTADO, SAUDAVEL, 0, OVO, idLote, IDADE_OVOS(idLote));
				}
					break;
				case 7: {
					FOR_INT(i, 0, QUANTIDADE_MI2(idLote), 1)
					insercaoMosquitos(contadorIDs++, MACHO, INFECTADO, SAUDAVEL, 0, ATIVO, idLote, IDADE_MACHOS_ATIVOS_WOLBACHIA(idLote));
				}
					break;
				case 8: {
					FOR_INT(i, 0, QUANTIDADE_MI3(idLote), 1)
					insercaoMosquitos(contadorIDs++, MACHO, INFECTADO, SAUDAVEL, 0, DECADENTE, idLote, IDADE_MACHOS_DECADENTES_WOLBACHIA(idLote));
				}
					break;
				case 9: {
					FOR_INT(i, 0, QUANTIDADE_FI1(idLote), 1)
					insercaoMosquitos(contadorIDs++, FEMEA, INFECTADO, SAUDAVEL, 0, OVO, idLote, IDADE_OVOS(idLote));
				}
					break;
				case 10: {
					FOR_INT(i, 0, QUANTIDADE_FI2(idLote), 1)
					insercaoMosquitos(contadorIDs++, FEMEA, INFECTADO, SAUDAVEL, 0, ATIVO, idLote, IDADE_FEMEAS_ATIVAS_WOLBACHIA(idLote));
				}
					break;
				case 11: {
					FOR_INT(i, 0, QUANTIDADE_FI3(idLote), 1)
					insercaoMosquitos(contadorIDs++, FEMEA, INFECTADO, SAUDAVEL, 0, DECADENTE, idLote, IDADE_FEMEAS_DECADENTES_WOLBACHIA(idLote));
				}
					break;
				case 12: {
					FOR_INT(i, 0, QUANTIDADE_FDI1(idLote), 1)
					insercaoMosquitos(contadorIDs++, FEMEA, SAUDAVEL, INFECTADO, 1, ATIVO, idLote, IDADE_FEMEAS_ATIVAS_SAUDAVEIS(idLote));
				}
					break;
				case 13: {
					FOR_INT(i, 0, QUANTIDADE_FDI2(idLote), 1)
					insercaoMosquitos(contadorIDs++, FEMEA, SAUDAVEL, INFECTADO, 2, ATIVO, idLote, IDADE_FEMEAS_ATIVAS_SAUDAVEIS(idLote));
				}
					break;
				case 14: {
					FOR_INT(i, 0, QUANTIDADE_FDI3(idLote), 1)
					insercaoMosquitos(contadorIDs++, FEMEA, SAUDAVEL, INFECTADO, 3, ATIVO, idLote, IDADE_FEMEAS_ATIVAS_SAUDAVEIS(idLote));
				}
					break;
				case 15: {
					FOR_INT(i, 0, QUANTIDADE_FDI4(idLote), 1)
					insercaoMosquitos(contadorIDs++, FEMEA, SAUDAVEL, INFECTADO, 4, ATIVO, idLote, IDADE_FEMEAS_ATIVAS_SAUDAVEIS(idLote));
				}
					break;
				case 16: {
					FOR_INT(i, 0, QUANTIDADE_FDI5(idLote), 1)
					insercaoMosquitos(contadorIDs++, FEMEA, SAUDAVEL, INFECTADO, 5, ATIVO, idLote, IDADE_FEMEAS_ATIVAS_SAUDAVEIS(idLote));
				}
					break;
				}
			}
		}
	}

	// Realiza a movimentação diurna para todos os agentes mosquitos alados
	void movimentacaoDiurna() {
		FOR_MOSQUITO(listaMosquitos->lista, i)
		{
			Mosquito* mosquito = i->elementoLista;
			if (((mosquito->fase == ATIVO) || (mosquito->fase == DECADENTE)) && (mosquito->vida)) {
				movimentacao(mosquito);
			}
		}
	}

	// Realiza a movimentação noturna para uma porcentagem dos agentes mosquitos alados
	void movimentacaoNoturna() {
		FOR_INT(idLote, 0, quantLotes, 1)
		{
			int totalMosquitos = 0;
			Lista<Mosquito*> lista;
			FOR_MOSQUITO(listaMosquitos->lista, i)
			{
				Mosquito* mosquito = i->elementoLista;
				if (((mosquito->fase == ATIVO) || (mosquito->fase == DECADENTE)) && (mosquito->idLoteAtual == idLote))
					++totalMosquitos;
			}
			int quantidadeMosquitosMovimentacao = totalMosquitos * PORCENTAGEM_MOVIMENTACAO_NOTURNA_MOSQUITOS(idLote);
			while (quantidadeMosquitosMovimentacao != 0) {
				FOR_MOSQUITO(listaMosquitos->lista, i)
				{
					Mosquito* mosquito = i->elementoLista;
					if (((mosquito->fase == ATIVO) || (mosquito->fase == DECADENTE)) && (mosquito->idLoteAtual == idLote)) {
						if (randomizarPercentual() <= 0.5) {
							lista.insercaoLista(mosquito);
							--quantidadeMosquitosMovimentacao;
						}
					}
					if (quantidadeMosquitosMovimentacao == 0)
						break;
				}
			}
			FOR2_MOSQUITO(lista, i)
			{
				Mosquito* mosquito = i->elementoLista;
				if (((mosquito->fase == ATIVO) || (mosquito->fase == DECADENTE)) && (mosquito->idLoteAtual == idLote)) {
					movimentacao(mosquito);
				}
			}
		}
	}

	// Realiza voos de levy para agentes mosquitos fêmeas acasaladas que não conseguiram alimento, de acordo com uma probabilidade
	void voosLevy() {
		FOR_MOSQUITO(listaMosquitos->lista, i)
		{
			Mosquito* mosquito = i->elementoLista;
			if (mosquito->sexo == FEMEA) {
				MosquitoFemea* mosquitoFemea = (MosquitoFemea*) (mosquito);
				if ((mosquitoFemea->tipoAcasalamento != NENHUM) && (!mosquitoFemea->alimento) && (mosquitoFemea->vida) && ((mosquitoFemea->fase == ATIVO) || (mosquitoFemea->fase == DECADENTE))) {
					if (randomizarPercentual() <= PROBABILIDADE_VOO_LEVY_ANTES_PROCURA_ALIMENTO(mosquitoFemea->idLoteAtual)) {
						vooLevy(mosquito, CURTO);
					}
				}
			}
		}
	}

	// Realiza a geração de agentes mosquitos ovos a partir de agentes mosquitos fêmeas gestantes e contagem de ciclos
	void geracao() {
		FOR_MOSQUITO(listaMosquitos->lista, i)
		{
			Mosquito* mosquito = i->elementoLista;
			if (mosquito->sexo == FEMEA) {
				MosquitoFemea* mosquitoFemea = (MosquitoFemea*) (mosquito);
				if (((mosquitoFemea->fase == ATIVO) || (mosquitoFemea->fase == DECADENTE)) && (mosquitoFemea->tipoAcasalamento != NENHUM)) {
					if (mosquitoFemea->ciclosGestacao == -1) {
						if (mosquitoFemea->contadorCiclosEntrePosturas != INTERVALO_ENTRE_POSTURAS_FEMEA(mosquitoFemea->idLoteAtual)) {
							mosquitoFemea->contadorCiclosEntrePosturas++;
						} else {
							mosquitoFemea->ciclosGestacao = 0;
						}
					} else {
						if (mosquitoFemea->ciclosGestacao < CICLOS_GESTACAO(mosquitoFemea->idLoteAtual)) {
							mosquitoFemea->ciclosGestacao++;
						} else {
							mosquitoFemea->contadorCiclosEntrePosturas = 0;
							mosquitoFemea->ciclosGestacao = -1;
							mosquitoFemea->contadorPosturas++;
							if ((mosquitoFemea->tipoProle != ESTERIL) || (mosquitoFemea->alimento)) {
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

	// Realiza a transformação de agentes mosquitos não alados e de agentes mosquitos alados
	void transformacoes() {
		FOR_INT(idLote, 0, quantLotes, 1)
		{
			transformacaoNaoAlados(OVO, LARVA, CICLOS_CONVERSAO_OVOS(idLote), BS12_OVOS(idLote), CS12_OVOS(idLote), BI12_OVOS(idLote), CI12_OVOS(idLote), idLote);
			transformacaoNaoAlados(LARVA, PUPA, CICLOS_CONVERSAO_LARVAS(idLote), BS12_LARVAS(idLote), CS12_LARVAS(idLote), BI12_LARVAS(idLote), CI12_LARVAS(idLote), idLote);
			transformacaoNaoAlados(PUPA, ATIVO, CICLOS_CONVERSAO_PUPAS(idLote), BS12_PUPAS(idLote), CS12_PUPAS(idLote), BI12_PUPAS(idLote), CI12_PUPAS(idLote), idLote);
		}
		transformacaoAlados();
	}

	// Realiza o controle natural e a remoção por idade dos agentes mosquitos
	void controleNatural(int cicloAtual) {
		remocaoMosquitosIdade();
		remocaoMosquitosControleNatural(cicloAtual);
	}

	// Realiza o controle químico para agentes mosquitos não alados e alados
	void controleQuimico(int cicloAtual) {
		remocaoMosquitosControleQuimicoNaoAlados(cicloAtual);
		remocaoMosquitosControleQuimicoAlados(cicloAtual);
	}

	// Realiza o controle mecânico para agentes mosquitos não alados
	void controleMecanico(int cicloAtual) {
		remocaoMosquitosControleMecanicoNaoAlados(cicloAtual);
	}

	// Conclui um ciclo da simulação incrementando idade, ciclos de latência e mudando saúde da fêmea
	void conclusaoCiclo() {
		FOR_MOSQUITO(listaMosquitos->lista, i)
		{
			Mosquito* mosquito = i->elementoLista;
			mosquito->idade++;
			if (mosquito->sexo == FEMEA) {
				MosquitoFemea* mosquitoFemea = (MosquitoFemea*) (mosquito);
				if (mosquitoFemea->ciclosLatencia == 0) {
					if (mosquitoFemea->saudeDengue == LATENTE) {
						mosquitoFemea->saudeDengue = INFECTADO;
					}
				} else {
					mosquitoFemea->ciclosLatencia--;
				}
			}
		}
	}

private:

	// Realiza o voo de levy curto ou longo para um agente mosquito fêmea
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
		FOR_INT(i, 0, TENTATIVAS_VOO_LEVY(mosquito->idLoteAtual), 1)
		{
			if (randomizarPercentual() <= 0.5) {
				px = -1 * px;
			}
			if (randomizarPercentual() <= 0.5) {
				py = -1 * py;
			}
			if (LIMITES_LOTE_P(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y, px, py)) {
				LISTA_FEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
				mosquito->addPosicaoAtual(px, py);
				LISTA_FEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).insercaoLista(mosquito);
				return;
			}
		}
	}

	// Efetiva o acasalamento entre dois agentes mosquitos alados de acordo com uma taxa de fecundidade da fêmea
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

	// Realiza o acasalamento entre agentes mosquitos, definindo a prole e o tipo de acasalamento de acordo com os atributos dos agentes
	void acasalamento(Mosquito* macho, Mosquito* femea) {
		MosquitoMacho* mosquitoMacho = (MosquitoMacho*) macho;
		switch (mosquitoMacho->saudeWolbachia) {
		case SAUDAVEL: {
			switch (femea->saudeWolbachia) {
			case SAUDAVEL: {
				switch (mosquitoMacho->contadorAcasalamentos) {
				case 0: {
					efetivacaoAcasalamento(macho, femea, BETASS22(femea->idLoteAtual), SAUDAVEL, SAUDAVEL);
				}
					break;
				default: {
					efetivacaoAcasalamento(macho, femea, pow(K1(femea->idLoteAtual), mosquitoMacho->contadorAcasalamentos) * (BETASS23(femea->idLoteAtual)), SAUDAVEL, SAUDAVEL);
				}
					break;
				}
			}
				break;
			case INFECTADO: {
				switch (mosquitoMacho->contadorAcasalamentos) {
				case 0: {
					efetivacaoAcasalamento(macho, femea, BETAIS22(femea->idLoteAtual), SAUDAVEL, INFECTADO);
				}
					break;
				default: {
					efetivacaoAcasalamento(macho, femea, pow(K1(femea->idLoteAtual), mosquitoMacho->contadorAcasalamentos) * (BETAIS23(femea->idLoteAtual)), SAUDAVEL, INFECTADO);
				}
					break;
				}
			}
				break;
			}
		}
			break;
		case INFECTADO: {
			switch (femea->saudeWolbachia) {
			case SAUDAVEL: {
				switch (mosquitoMacho->contadorAcasalamentos) {
				case 0: {
					efetivacaoAcasalamento(macho, femea, BETASI22(femea->idLoteAtual), INFECTADO, ESTERIL);
				}
					break;
				default: {
					efetivacaoAcasalamento(macho, femea, pow(K2(femea->idLoteAtual), mosquitoMacho->contadorAcasalamentos) * (BETASI23(femea->idLoteAtual)), INFECTADO, ESTERIL);
				}
					break;
				}
			}
				break;
			case INFECTADO: {
				switch (mosquitoMacho->contadorAcasalamentos) {
				case 0: {
					efetivacaoAcasalamento(macho, femea, BETAII22(femea->idLoteAtual), INFECTADO, INFECTADO);
				}
					break;
				default: {
					efetivacaoAcasalamento(macho, femea, pow(K2(femea->idLoteAtual), mosquitoMacho->contadorAcasalamentos) * (BETAII23(femea->idLoteAtual)), INFECTADO, INFECTADO);
				}
					break;
				}
			}
			}
		}
			break;
		}
	}

	// Procura um macho para acasalamento em uma posição escolhida anteriormente. Realiza o acasalamento com o macho com menor número de acasalamentos 
	// se o macho está na mesma posição da fêmea ou desloca a fêmea para a posição mais próxima do macho
	void procuraMachoAcasalamento(Mosquito* femea, Conexao posicaoEscolhida) {
		Mosquito* macho = NULL;
		MosquitoMacho* mosquitoMacho = NULL;
		int acasalamentos = 99;
		FOR2_MOSQUITO(LISTA_MACHOS(posicaoEscolhida.idLoteDestino, posicaoEscolhida.destino.x, posicaoEscolhida.destino.y), i)
		{
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
			CoordenadaGeo coordenadaGeoDestino = POSICAO_LOTE(femea->idLoteAtual, femea->posicaoAtual.x, femea->posicaoAtual.y).coordenadaGeo;
			double menorDistancia = POSICAO_LOTE(macho->idLoteAtual, macho->posicaoAtual.x, macho->posicaoAtual.y).coordenadaGeo.distancia(coordenadaGeoDestino);
			int xEscolhido = femea->posicaoAtual.x;
			int yEscolhido = femea->posicaoAtual.y;
			FOR_INT(i, femea->posicaoAtual.x - 1, femea->posicaoAtual.x + 1 + 1, 1)
			{
				FOR_INT(j, femea->posicaoAtual.y - 1, femea->posicaoAtual.y + 1 + 1, 1)
				{
					if (LIMITES_LOTE(femea->idLoteAtual, i, j)) {
						distanciaCalculada = POSICAO_LOTE(femea->idLoteAtual, i, j).coordenadaGeo.distancia(coordenadaGeoDestino);
						if (distanciaCalculada < menorDistancia) {
							menorDistancia = distanciaCalculada;
							xEscolhido = i;
							yEscolhido = j;
						}
					}
				}
			}
			LISTA_FEMEAS(femea->idLoteAtual, femea->posicaoAtual.x, femea->posicaoAtual.y).buscaRemocaoLista(femea);
			femea->setPosicaoAtual(xEscolhido, yEscolhido);
			LISTA_FEMEAS(femea->idLoteAtual, femea->posicaoAtual.x, femea->posicaoAtual.y).insercaoLista(femea);
		}
	}

	// Busca a posição mais próxima da fêmea que contenha um macho para acasalamento na vizinhança de Moore da fêmea e na área de percepção para machos
	void buscaMacho(Mosquito* femea) {
		Lista < Conexao > lista;
		FOR_INT(i, femea->posicaoAtual.x - RAIO_BUSCA_MACHO(femea->idLoteAtual), femea->posicaoAtual.x + RAIO_BUSCA_MACHO(femea->idLoteAtual) + 1, 1)
		{
			FOR_INT(j, femea->posicaoAtual.y - RAIO_BUSCA_MACHO(femea->idLoteAtual), femea->posicaoAtual.y + RAIO_BUSCA_MACHO(femea->idLoteAtual) + 1, 1)
			{
				if (LIMITES_LOTE(femea->idLoteAtual, i, j) && (LISTA_MACHOS(femea->idLoteAtual, i, j).tamanhoLista > 0)) {
					lista.insercaoLista(Conexao(Posicao(i, j), femea->idLoteAtual));
				}
			}
		}
		FOR_CONEXAO(LISTA_PERCEPCAO_MACHOS(femea->idLoteAtual, femea->posicaoAtual.x, femea->posicaoAtual.y), i)
		{
			Conexao* conexao = i->elementoLista;
			if (LISTA_MACHOS(conexao->idLoteDestino, conexao->destino.x, conexao->destino.y).tamanhoLista > 0) {
				lista.insercaoLista(Conexao(Posicao(conexao->destino.x, conexao->destino.y), conexao->idLoteDestino));
			}
		}
		if (lista.tamanhoLista != 0) {
			Conexao escolhido;
			double distanciaCalculada;
			escolhido = lista.cabecaLista->elementoLista;
			CoordenadaGeo coordenadaGeoDestino = POSICAO_LOTE(femea->idLoteAtual, femea->posicaoAtual.x, femea->posicaoAtual.y).coordenadaGeo;
			double menorDistancia = POSICAO_LOTE(lista.cabecaLista->elementoLista.idLoteDestino, lista.cabecaLista->elementoLista.destino.x, lista.cabecaLista->elementoLista.destino.y).coordenadaGeo.distancia(coordenadaGeoDestino);
			FOR2_CONEXAO(lista, i)
			{
				distanciaCalculada = POSICAO_LOTE(i->elementoLista.idLoteDestino, i->elementoLista.destino.x, i->elementoLista.destino.y).coordenadaGeo.distancia(coordenadaGeoDestino);
				if (distanciaCalculada < menorDistancia) {
					menorDistancia = distanciaCalculada;
					escolhido = i->elementoLista;
				}
			}
			procuraMachoAcasalamento(femea, escolhido);
		}
	}

	// Efetiva a movimentação do agente mosquito, verificando se a posição escolhida para o deslocamento é válida
	bool efetivacaoMovimentaMosquito(Mosquito* mosquito, int variacaoX, int variacaoY) {
		if (!LIMITES_LOTE_P(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y, variacaoX, variacaoY)) {
			return false;
		} else {
			switch (mosquito->sexo) {
			case MACHO: {
				LISTA_MACHOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
				LISTA_MACHOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x + variacaoX, mosquito->posicaoAtual.y + variacaoY).insercaoLista(mosquito);
			}
				break;
			case FEMEA: {
				LISTA_FEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
				LISTA_FEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x + variacaoX, mosquito->posicaoAtual.y + variacaoY).insercaoLista(mosquito);
			}
				break;
			}
			mosquito->addPosicaoAtual(variacaoX, variacaoY);
		}
		return true;
	}

	// Realiza a movimentação de uma agente mosquito entre lotes, utilizando a lista de vizinhança visível para mosquitos
	bool migrarLote(Mosquito* mosquito) {
		if (LISTA_VIZINHANCA_MOSQUITOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).tamanhoLista == 0) {
			return false;
		} else {
			int indiceEscolhido = rand() % LISTA_VIZINHANCA_MOSQUITOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).tamanhoLista;
			ElementoLista<Conexao*>* destino = LISTA_VIZINHANCA_MOSQUITOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaPosicao(indiceEscolhido);
			Posicao posicaoDestino = destino->elementoLista->destino;
			int idLoteDestino = destino->elementoLista->idLoteDestino;
			switch (mosquito->sexo) {
			case MACHO: {
				LISTA_MACHOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
				LISTA_MACHOS(idLoteDestino, posicaoDestino.x, posicaoDestino.y).insercaoLista(mosquito);
			}
				break;
			case FEMEA: {
				LISTA_FEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
				LISTA_FEMEAS(idLoteDestino, posicaoDestino.x, posicaoDestino.y).insercaoLista(mosquito);
			}
				break;
			}
			mosquito->setLoteAtualPosicaoAtual(idLoteDestino, posicaoDestino.x, posicaoDestino.y);
		}
		return true;
	}

	// Movimenta um agente mosquito macho na vizinhança de Moore e um agente mosquito fêmea na busca por um criadouro, 
	// considerando a área de percepção para criadouros, movendo-se para o criadouro mais próximo
	void movimentaMosquito(Mosquito* mosquito) {
		if (mosquito->sexo == MACHO) {
			bool moveu = false;
			int direcaoMovimentacao;
			Lista<int> direcoes;
			FOR_INT(i, 0, 9, 1)
			{
				direcoes.insercaoLista(i);
			}
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
			Lista < Conexao > lista;
			FOR_INT(i, mosquito->posicaoAtual.x - 1, mosquito->posicaoAtual.x + 1 + 1, 1)
			{
				FOR_INT(j, mosquito->posicaoAtual.y - 1, mosquito->posicaoAtual.y + 1 + 1, 1)
				{
					if (LIMITES_LOTE(mosquito->idLoteAtual, i, j)) {
						lista.insercaoLista(Conexao(Posicao(i, j), mosquito->idLoteAtual));
					}
				}
			}
			FOR_CONEXAO(LISTA_PERCEPCAO_CRIADOUROS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y), i)
			{
				Conexao* conexao = i->elementoLista;
				if (POSICAO_LOTE(conexao->idLoteDestino, conexao->destino.x, conexao->destino.y).criadouro) {
					lista.insercaoLista(Conexao(Posicao(conexao->destino.x, conexao->destino.y), conexao->idLoteDestino));
				}
			}
			if (lista.tamanhoLista != 0) {
				Conexao escolhido;
				double distanciaCalculada;
				escolhido = lista.cabecaLista->elementoLista;
				CoordenadaGeo coordenadaGeoDestino = POSICAO_LOTE(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).coordenadaGeo;
				double menorDistancia = POSICAO_LOTE(lista.cabecaLista->elementoLista.idLoteDestino, lista.cabecaLista->elementoLista.destino.x, lista.cabecaLista->elementoLista.destino.y).coordenadaGeo.distancia(coordenadaGeoDestino);
				FOR2_CONEXAO(lista, i)
				{
					Conexao conexao = i->elementoLista;
					distanciaCalculada = POSICAO_LOTE(conexao.idLoteDestino, conexao.destino.x, conexao.destino.y).coordenadaGeo.distancia(coordenadaGeoDestino);
					if (distanciaCalculada < menorDistancia) {
						menorDistancia = distanciaCalculada;
						escolhido = conexao;
					}
				}
				LISTA_FEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
				mosquito->setLoteAtualPosicaoAtual(escolhido.idLoteDestino, escolhido.destino.x, escolhido.destino.y);
				LISTA_FEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).insercaoLista(mosquito);
			}
		}
	}

	// Efetiva a movimentação de um agente mosquito fêmea alimentada, validando se a posição para deslocamento é válida, dentro do lote e
	// dentro do raio definido
	bool efetivacaoMovimentaFemeaAlimentada(Mosquito* mosquito, int variacaoX, int variacaoY) {
		MosquitoFemea* mosquitoFemea = (MosquitoFemea*) mosquito;
		if (!LIMITES_LOTE_P(mosquitoFemea->idLoteAtual, mosquitoFemea->posicaoAtual.x, mosquitoFemea->posicaoAtual.y, variacaoX, variacaoY)) {
			return false;
		} else {
			LISTA_FEMEAS(mosquito->idLoteAtual, mosquitoFemea->posicaoAtual.x, mosquitoFemea->posicaoAtual.y).buscaRemocaoLista(mosquito);
			mosquitoFemea->addPosicaoAtual(variacaoX, variacaoY);
			LISTA_FEMEAS(mosquito->idLoteAtual, mosquitoFemea->posicaoAtual.x, mosquitoFemea->posicaoAtual.y).insercaoLista(mosquito);
		}
		return true;
	}

	// Movimenta um agente fêmea alimentada na vizinhança de Moore, considerando o raio definido
	void movimentaFemeaAlimentada(Mosquito* mosquito) {
		bool moveu = false;
		int direcaoMovimentacao;
		Lista<int> direcoes;
		FOR_INT(i, 0, 9, 1)
		{
			direcoes.insercaoLista(i);
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

	// Busca o humano mais próximo considerando o raio de busca e a área de percepção para humanos
	Humano* buscaHumano(Mosquito* mosquito, int ordemVizinhancaBusca) {
		Lista<Humano*> lista;
		Humano* retorno = NULL;
		FOR_INT(i, mosquito->posicaoAtual.x - ordemVizinhancaBusca, mosquito->posicaoAtual.x + ordemVizinhancaBusca + 1, 1)
		{
			FOR_INT(j, mosquito->posicaoAtual.y - ordemVizinhancaBusca, mosquito->posicaoAtual.y + ordemVizinhancaBusca + 1, 1)
			{
				if (LIMITES_LOTE(mosquito->idLoteAtual, i, j) && (LISTA_HUMANOS(mosquito->idLoteAtual, i, j).tamanhoLista > 0)) {
					FOR2_HUMANO(LISTA_HUMANOS(mosquito->idLoteAtual, i, j), k)
					{
						Humano* humano = k->elementoLista;
						if (humano->saude != REMOVIDO) {
							lista.insercaoLista(humano);
						}
					}
				}
			}
		}
		if (ordemVizinhancaBusca == 1) {
			FOR_CONEXAO(LISTA_VIZINHANCA_MOSQUITOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y), i)
			{
				Conexao* conexao = i->elementoLista;
				if (LISTA_HUMANOS(conexao->idLoteDestino, conexao->destino.x, conexao->destino.y).tamanhoLista > 0) {
					FOR2_HUMANO(LISTA_HUMANOS(conexao->idLoteDestino, conexao->destino.x, conexao->destino.y), j)
					{
						Humano* humano = j->elementoLista;
						if (humano->saude != REMOVIDO) {
							lista.insercaoLista(humano);
						}
					}
				}
			}
		} else {
			FOR_CONEXAO(LISTA_PERCEPCAO_HUMANOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y), i)
			{
				Conexao* conexao = i->elementoLista;
				if (LISTA_HUMANOS(conexao->idLoteDestino, conexao->destino.x, conexao->destino.y).tamanhoLista > 0) {
					FOR2_HUMANO(LISTA_HUMANOS(conexao->idLoteDestino, conexao->destino.x, conexao->destino.y), j)
					{
						Humano* humano = j->elementoLista;
						if (humano->saude != REMOVIDO) {
							lista.insercaoLista(humano);
						}
					}
				}
			}
		}
		if (lista.tamanhoLista != 0) {
			double distanciaCalculada;
			retorno = lista.cabecaLista->elementoLista;
			CoordenadaGeo coordenadaGeoDestino = POSICAO_LOTE(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).coordenadaGeo;
			double menorDistancia = POSICAO_LOTE(lista.cabecaLista->elementoLista->idLoteAtual, lista.cabecaLista->elementoLista->posicaoAtual.x, lista.cabecaLista->elementoLista->posicaoAtual.y).coordenadaGeo.distancia(coordenadaGeoDestino);
			FOR2_HUMANO(lista, i)
			{
				distanciaCalculada = POSICAO_LOTE(i->elementoLista->idLoteAtual, i->elementoLista->posicaoAtual.x, i->elementoLista->posicaoAtual.y).coordenadaGeo.distancia(coordenadaGeoDestino);
				if (distanciaCalculada < menorDistancia) {
					retorno = i->elementoLista;
					menorDistancia = distanciaCalculada;
				}
			}
		}
		return retorno;
	}

	// Realiza a infecção para dengue no agente mosquito de acordo com as taxas e o sorotipo de agente humano
	void infeccaoMosquito(Mosquito* mosquito, Humano* humano) {
		MosquitoFemea* mosquitoFemea = (MosquitoFemea*) mosquito;
		if ((mosquitoFemea->saudeDengue == SAUDAVEL) && (humano->saude == INFECTADO) && (mosquitoFemea->saudeWolbachia == SAUDAVEL)) {
			double probabilidade;
			switch (humano->sorotipo) {
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
				mosquitoFemea->saudeDengue = LATENTE;
				mosquitoFemea->ciclosLatencia = CICLOS_LATENTE_MOSQUITO(mosquito->idLoteAtual);
			}
		}
	}

	// Efetiva a morte por dengue hemorrágica do agente humano
	void efetivacaoMorteDengueHemorragica(Humano* humano) {
		if (randomizarPercentual() <= PROBABILIDADE_MORTE(humano->idLoteAtual)) {
			humano->saude = REMOVIDO;
		}
	}
 
	// Efetiva a evolução para dengue hemorrágica do agente humano
	void efetivacaoEvolucaoDengueHemorragica(Humano* humano, double probabilidadeEvolucao) {
		if (randomizarPercentual() <= probabilidadeEvolucao) {
			humano->saude = HEMORRAGICO;
			efetivacaoMorteDengueHemorragica(humano);
		}
	}

	// Testa a evolução para dengue hemorrágica do humano de acordo com as taxas definidas
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

	// Efetiva a infecção para dengue no agente humano, de acordo com as taxas e o sorotipo do agente mosquito
	void efetivacaoInfeccaoHumana(Humano* humano, double probabilidadeInfeccaoHumana, int sorotipo) {
		if (randomizarPercentual() <= (probabilidadeInfeccaoHumana * TAXA_SUCESSO_INFECCAO_HUMANO(humano->idLoteAtual))) {
			humano->saude = LATENTE;
			humano->contagemCiclosPeriodos = CICLOS_LATENTE_HUMANO(humano->idLoteAtual);
			humano->listaSorotiposContraidos.insercaoLista(sorotipo);
			humano->sorotipo = sorotipo;
		}
	}

	// Testa a infecção para dengue no agente humano, de acordo com as taxas e o sorotipo do agente mosquito
	void infeccaoHumano(Mosquito* mosquito, Humano* humano) {
		MosquitoFemea* mosquitoFemea = (MosquitoFemea*) mosquito;
		if ((mosquitoFemea->saudeDengue == INFECTADO) && (humano->saude == SUSCETIVEL) && (!humano->listaSorotiposContraidos.buscaLista(mosquitoFemea->sorotipo))) {
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

	// Realiza a movimentação do agente fêmea gestante, que procurará um humano e se moverá para a posição mais próxima deste
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
						LISTA_FEMEAS(mosquitoFemea->idLoteAtual, mosquitoFemea->posicaoAtual.x, mosquitoFemea->posicaoAtual.y).buscaRemocaoLista(mosquitoFemea);
						mosquitoFemea->setLoteAtualPosicaoAtual(idLoteDestino, posicaoDestino.x, posicaoDestino.y);
						LISTA_FEMEAS(mosquitoFemea->idLoteAtual, mosquitoFemea->posicaoAtual.x, mosquitoFemea->posicaoAtual.y).insercaoLista(mosquitoFemea);
						mosquitoFemea->setPosicaoAlimento(mosquitoFemea->posicaoAtual.x, mosquitoFemea->posicaoAtual.y);
						mosquitoFemea->alimento = true;
						infeccaoMosquito(mosquito, humano);
						infeccaoHumano(mosquito, humano);
						return true;
					} else {
						double distanciaCalculada;
						CoordenadaGeo coordenadaGeoDestino = POSICAO_LOTE(humano->idLoteAtual, humano->posicaoAtual.x, humano->posicaoAtual.y).coordenadaGeo;
						double menorDistancia = POSICAO_LOTE(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).coordenadaGeo.distancia(coordenadaGeoDestino);
						int xEscolhido = mosquito->posicaoAtual.x;
						int yEscolhido = mosquito->posicaoAtual.y;
						FOR_INT(i, mosquito->posicaoAtual.x - raioVizinhancaBusca, mosquito->posicaoAtual.x + raioVizinhancaBusca + 1, 1)
						{
							FOR_INT(j, mosquito->posicaoAtual.y - raioVizinhancaBusca, mosquito->posicaoAtual.y + raioVizinhancaBusca + 1, 1)
							{
								if (LIMITES_LOTE(mosquito->idLoteAtual, i, j)) {
									distanciaCalculada = POSICAO_LOTE(mosquito->idLoteAtual, i, j).coordenadaGeo.distancia(coordenadaGeoDestino);
									if (distanciaCalculada < menorDistancia) {
										menorDistancia = distanciaCalculada;
										xEscolhido = i;
										yEscolhido = j;
									}
								}
							}
						}
						MosquitoFemea* mosquitoFemea = (MosquitoFemea*) mosquito;
						LISTA_FEMEAS(mosquitoFemea->idLoteAtual, mosquitoFemea->posicaoAtual.x, mosquitoFemea->posicaoAtual.y).buscaRemocaoLista(mosquitoFemea);
						mosquitoFemea->setPosicaoAtual(xEscolhido, yEscolhido);
						LISTA_FEMEAS(mosquitoFemea->idLoteAtual, mosquitoFemea->posicaoAtual.x, mosquitoFemea->posicaoAtual.y).insercaoLista(mosquitoFemea);
					}
				}
				raioVizinhancaBusca++;
			}
			return false;
		}
		return false;
	}

	// Testa a movimentação de um agente mosquito
	void movimentacao(Mosquito* mosquito) {
		switch (mosquito->sexo) {
		case MACHO:
			movimentaMosquito(mosquito);
			break;
		case FEMEA: {
			MosquitoFemea* mosquitoFemea = (MosquitoFemea*) mosquito;
			if (mosquitoFemea->tipoAcasalamento == NENHUM) {
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
				} else {
					movimentaFemeaAlimentada(mosquito);
				}
			}
		}
			break;
		}
	}

	// Realiza a inserção de agentes mosquitos ovos gerados por uma fêmea gestante
	void insercaoOvos(Mosquito* mosquitoMae, int quantidade, double fracaoMachos, char saudeOvo) {
		Mosquito* mosquitoNovo = NULL;
		double quantidadeFemeas = 0, quantidadeMachos = 0;
		quantidadeMachos = (int) (fracaoMachos * quantidade);
		quantidadeFemeas = (int) (quantidade - quantidadeMachos);
		FOR_INT(indice, 0, quantidadeFemeas, 1)
		{
			MosquitoFemea* mosquitoFemea = new MosquitoFemea(contadorIDs, saudeOvo, SAUDAVEL, 0, OVO, 0, mosquitoMae->idLoteAtual, mosquitoMae->posicaoAtual.x, mosquitoMae->posicaoAtual.y);
			mosquitoNovo = listaMosquitos->lista->insercaoLista(mosquitoFemea);
			LISTA_NAO_ALADOS(mosquitoMae->idLoteAtual, mosquitoMae->posicaoAtual.x, mosquitoMae->posicaoAtual.y).insercaoLista(mosquitoNovo);
			contadorIDs++;
		}
		FOR_INT(indice, 0, quantidadeMachos, 1)
		{
			MosquitoMacho* mosquitoMacho = new MosquitoMacho(contadorIDs, saudeOvo, OVO, 0, mosquitoMae->idLoteAtual, mosquitoMae->posicaoAtual.x, mosquitoMae->posicaoAtual.y);
			mosquitoNovo = listaMosquitos->lista->insercaoLista(mosquitoMacho);
			LISTA_NAO_ALADOS(mosquitoMae->idLoteAtual, mosquitoMae->posicaoAtual.x, mosquitoMae->posicaoAtual.y).insercaoLista(mosquitoNovo);
			contadorIDs++;
		}
	}

	// Testa o tipo de prole e quantidade para a geração de agentes mosquitos ovos
	void geracao6Casos(Mosquito* mosquitoMae) {
		MosquitoFemea* mosquitoFemea = (MosquitoFemea*) mosquitoMae;
		switch (mosquitoFemea->saudeWolbachia) {
		case SAUDAVEL: {
			if ((mosquitoFemea->tipoProle == SAUDAVEL) && (mosquitoFemea->tipoAcasalamento == SAUDAVEL)) {
				switch (mosquitoFemea->fase) {
				case ATIVO:
					insercaoOvos(mosquitoMae, AS21(mosquitoMae->idLoteAtual), PS21(mosquitoMae->idLoteAtual), SAUDAVEL);
					break;
				case DECADENTE:
					insercaoOvos(mosquitoMae, AS21(mosquitoMae->idLoteAtual) * H1(mosquitoMae->idLoteAtual), PS31(mosquitoMae->idLoteAtual), SAUDAVEL);
					break;
				}
			}
		}
			break;
		case INFECTADO: {
			if (mosquitoFemea->tipoProle == INFECTADO) {
				switch (mosquitoFemea->fase) {
				case ATIVO: {
					insercaoOvos(mosquitoMae, AI21(mosquitoMae->idLoteAtual), PI21(mosquitoMae->idLoteAtual), INFECTADO);
				}
					break;
				case DECADENTE: {
					insercaoOvos(mosquitoMae, AI21(mosquitoMae->idLoteAtual) * H2(mosquitoMae->idLoteAtual), PI31(mosquitoMae->idLoteAtual), INFECTADO);
				}
					break;
				}
			}
		}
			break;
		}
	}

	// Efetiva a transformação de agentes mosquitos não alados
	void efetivacaoTransformacaoNaoAlados(Lista<Mosquito*>* lista, int transforma, int naoTransforma, char sexo, char fase) {
		FOR_MOSQUITO(lista, i)
		{
			Mosquito* mosquito = i->elementoLista;
			if (randomizarPercentual() <= 0.5) {
				if (transforma > 0) {
					if (fase == ATIVO) {
						LISTA_NAO_ALADOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
						if (mosquito->sexo == MACHO) {
							LISTA_MACHOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).insercaoLista(mosquito);
						} else {
							LISTA_FEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).insercaoLista(mosquito);
						}
					}
					mosquito->fase = fase;
					transforma--;
				} else {
					if (naoTransforma > 0) {
						mosquito->vida = false;
						LISTA_NAO_ALADOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
						naoTransforma--;
					}
				}
			} else {
				if (naoTransforma > 0) {
					mosquito->vida = false;
					LISTA_NAO_ALADOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
					naoTransforma--;
				} else {
					if (transforma > 0) {
						if (fase == ATIVO) {
							LISTA_NAO_ALADOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
							if (mosquito->sexo == MACHO) {
								LISTA_MACHOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).insercaoLista(mosquito);
							} else {
								LISTA_FEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).insercaoLista(mosquito);
							}
						}
						mosquito->fase = fase;
						transforma--;
					}
				}
			}
		}
	}

	// Realiza a transformação de agentes mosquitos não alados de acordo com o sexo, fase, idade e taxas definidas
	void transformacaoNaoAlados(char faseAtual, char faseSeguinte, int maxIdade, double bs, double cs, double bi, double ci, int idLote) {
		int contadorMachosSaudaveis = 0, contadorFemeasSaudaveis = 0, contadorMachosWolbachia = 0, contadorFemeasWolbachia = 0;
		int contadorFemeasSaudaveisTransformacao = 0, contadorFemeasSaudaveisNaoTransformacao = 0, contadorMachosSaudaveisTransformacao = 0, contadorMachosSaudaveisNaoTransformacao = 0, contadorFemeasWolbachiaTransformacao = 0, contadorFemeasWolbachiaNaoTransformacao = 0, contadorMachosWolbachiaTransformacao = 0, contadorMachosWolbachiaNaoTransformacao = 0;
		double totalFemeasSaudaveis = 0, totalMachosSaudaveis = 0, totalFemeasWolbachia = 0, totalMachosWolbachia = 0;
		Lista<Mosquito*> listaMachosSaudaveis;
		Lista<Mosquito*> listaMachosWolbachia;
		Lista<Mosquito*> listaFemeasSaudaveis;
		Lista<Mosquito*> listaFemeasWolbachia;
		FOR_MOSQUITO(listaMosquitos->lista, i)
		{
			Mosquito* mosquito = i->elementoLista;
			if ((mosquito->idade > maxIdade) && (mosquito->fase == faseAtual) && (mosquito->idLoteAtual == idLote) && (mosquito->vida)) {
				if (mosquito->sexo == MACHO) {
					if (mosquito->saudeWolbachia == SAUDAVEL) {
						listaMachosSaudaveis.insercaoLista(mosquito);
						contadorMachosSaudaveis++;
					} else {
						listaMachosWolbachia.insercaoLista(mosquito);
						contadorMachosWolbachia++;
					}
				} else {
					if (mosquito->saudeWolbachia == SAUDAVEL) {
						listaFemeasSaudaveis.insercaoLista(mosquito);
						contadorFemeasSaudaveis++;
					} else {
						listaFemeasWolbachia.insercaoLista(mosquito);
						contadorFemeasWolbachia++;
					}
				}
			}
		}
		if ((contadorMachosSaudaveis + contadorFemeasSaudaveis + contadorMachosWolbachia + contadorFemeasWolbachia) != 0) {
			totalFemeasSaudaveis = contadorFemeasSaudaveis * bs;
			totalMachosSaudaveis = contadorMachosSaudaveis * cs;
			totalFemeasWolbachia = contadorFemeasWolbachia * bi;
			totalMachosWolbachia = contadorMachosWolbachia * ci;
			contadorFemeasSaudaveisNaoTransformacao = (int) totalFemeasSaudaveis;
			contadorMachosSaudaveisNaoTransformacao = (int) totalMachosSaudaveis;
			contadorFemeasWolbachiaNaoTransformacao = (int) totalFemeasWolbachia;
			contadorMachosWolbachiaNaoTransformacao = (int) totalMachosWolbachia;
			contadorFemeasSaudaveisTransformacao = contadorFemeasSaudaveis - contadorFemeasSaudaveisNaoTransformacao;
			contadorMachosSaudaveisTransformacao = contadorMachosSaudaveis - contadorMachosSaudaveisNaoTransformacao;
			contadorFemeasWolbachiaTransformacao = contadorFemeasWolbachia - contadorFemeasWolbachiaNaoTransformacao;
			contadorMachosWolbachiaTransformacao = contadorMachosWolbachia - contadorMachosWolbachiaNaoTransformacao;
			efetivacaoTransformacaoNaoAlados(&listaMachosSaudaveis, contadorMachosSaudaveisTransformacao, contadorMachosSaudaveisNaoTransformacao, MACHO, faseSeguinte);
			efetivacaoTransformacaoNaoAlados(&listaMachosWolbachia, contadorMachosWolbachiaTransformacao, contadorMachosWolbachiaNaoTransformacao, MACHO, faseSeguinte);
			efetivacaoTransformacaoNaoAlados(&listaFemeasSaudaveis, contadorFemeasSaudaveisTransformacao, contadorFemeasSaudaveisNaoTransformacao, FEMEA, faseSeguinte);
			efetivacaoTransformacaoNaoAlados(&listaFemeasWolbachia, contadorFemeasWolbachiaTransformacao, contadorFemeasWolbachiaNaoTransformacao, FEMEA, faseSeguinte);
		}
	}

	// Efetiva a transformação de agentes mosquitos alados
	int efetivacaoTransformacaoAlados(Mosquito* mosquito, int enviados, int naoEnviados, int transformados, int naoTransformados) {
		if (randomizarPercentual() <= 0.5) {
			if (transformados < enviados) {
				mosquito->fase = DECADENTE;
				return 1;
			} else {
				if (naoTransformados < naoEnviados) {
					if (mosquito->sexo == MACHO) {
						LISTA_MACHOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
					} else {
						LISTA_FEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
					}
					mosquito->vida = false;
					return 2;
				}
			}
		} else {
			if (naoTransformados < naoEnviados) {
				if (mosquito->sexo == MACHO) {
					LISTA_MACHOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
				} else {
					LISTA_FEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
				}
				mosquito->vida = false;
				return 2;
			} else {
				if (transformados < enviados) {
					mosquito->fase = DECADENTE;
					return 1;
				}
			}
		}
		return 0;
	}
	
	// Testa a transformação de agentes mosquitos alados em relação ao sexo
	void testeTransformacaoAlados(char sexo, int enviadosSaudaveis, int naoEnviadosSaudaveis, int enviadosInfectados, int naoEnviadosInfectados) {
		int transformadosSaudaveis = 0, naoTransformadosSaudaveis = 0, transformadosInfectados = 0, naoTransformadosInfectados = 0;
		switch (sexo) {
		case MACHO: {
			FOR_MOSQUITO(listaMosquitos->lista, i)
			{
				Mosquito* mosquito = i->elementoLista;
				if (mosquito->sexo == MACHO) {
					MosquitoMacho* mosquitoMacho = (MosquitoMacho*) (mosquito);
					if ((mosquitoMacho->fase == ATIVO) && (mosquitoMacho->contadorAcasalamentos > 0) && (mosquitoMacho->vida)) {
						if ((mosquitoMacho->saudeWolbachia == SAUDAVEL) && (mosquitoMacho->idade > CICLOS_CONVERSAO_MACHOS_ATIVOS_SAUDAVEIS(mosquito->idLoteAtual))) {
							if (efetivacaoTransformacaoAlados(mosquito, enviadosSaudaveis, naoEnviadosSaudaveis, transformadosSaudaveis, naoTransformadosSaudaveis) == 1) {
								transformadosSaudaveis++;
							} else {
								naoTransformadosSaudaveis++;
							}
						}
						if ((mosquitoMacho->saudeWolbachia == INFECTADO) && (mosquitoMacho->idade > CICLOS_CONVERSAO_MACHOS_ATIVOS_WOLBACHIA(mosquito->idLoteAtual))) {
							if (efetivacaoTransformacaoAlados(mosquito, enviadosInfectados, naoEnviadosInfectados, transformadosInfectados, naoTransformadosInfectados) == 1) {
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
		case FEMEA: {
			FOR_MOSQUITO(listaMosquitos->lista, i)
			{
				Mosquito* mosquito = i->elementoLista;
				if (mosquito->sexo == FEMEA) {
					MosquitoFemea* mosquitoFemea = (MosquitoFemea*) (mosquito);
					if ((mosquitoFemea->fase == ATIVO) && (mosquitoFemea->vida) && (mosquitoFemea->contadorPosturas > 0)) {
						if ((mosquitoFemea->saudeWolbachia == SAUDAVEL) && (mosquitoFemea->idade > CICLOS_CONVERSAO_FEMEAS_ATIVAS_SAUDAVEIS(mosquito->idLoteAtual))) {
							if (efetivacaoTransformacaoAlados(mosquito, enviadosSaudaveis, naoEnviadosSaudaveis, transformadosSaudaveis, naoTransformadosSaudaveis) == 1) {
								transformadosSaudaveis++;
							} else {
								naoTransformadosSaudaveis++;
							}
						}
						if ((mosquitoFemea->saudeWolbachia == INFECTADO) && (mosquitoFemea->idade > CICLOS_CONVERSAO_FEMEAS_ATIVAS_WOLBACHIA(mosquito->idLoteAtual))) {
							if (efetivacaoTransformacaoAlados(mosquito, enviadosInfectados, naoEnviadosInfectados, transformadosInfectados, naoTransformadosInfectados) == 1) {
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

	// Realiza a transformação de agentes mosquitos alados de acordo com a saúde, idade, fase e taxas definidas
	void transformacaoAlados() {
		FOR_INT(idLote, 0, quantLotes, 1)
		{
			int naoTransformaSaudaveis, transformaSaudaveis, naoTransformaWolbachia, transformaWolbachia;
			int contadorSaudaveis = 0, contadorWolbachia = 0;
			FOR_MOSQUITO(listaMosquitos->lista, i)
			{
				Mosquito* mosquito = i->elementoLista;
				if (mosquito->sexo == MACHO) {
					MosquitoMacho* mosquitoMacho = (MosquitoMacho*) (mosquito);
					if ((mosquitoMacho->fase == ATIVO) && (mosquitoMacho->contadorAcasalamentos > 0) && (mosquitoMacho->idLoteAtual == idLote) && (mosquitoMacho->vida)) {
						if ((mosquitoMacho->saudeWolbachia == SAUDAVEL) && (mosquitoMacho->idade > CICLOS_CONVERSAO_MACHOS_ATIVOS_SAUDAVEIS(idLote)))
							contadorSaudaveis++;
						if ((mosquitoMacho->saudeWolbachia == INFECTADO) && (mosquitoMacho->idade > CICLOS_CONVERSAO_MACHOS_ATIVOS_WOLBACHIA(idLote)))
							contadorWolbachia++;
					}
				}
			}
			if ((contadorSaudaveis + contadorWolbachia) != 0) {
				naoTransformaSaudaveis = (int) (contadorSaudaveis * CS23(idLote));
				transformaSaudaveis = (int) (contadorSaudaveis - naoTransformaSaudaveis);
				naoTransformaWolbachia = (int) (contadorWolbachia * CI23(idLote));
				transformaWolbachia = (int) (contadorWolbachia - naoTransformaWolbachia);
				testeTransformacaoAlados(MACHO, transformaSaudaveis, naoTransformaSaudaveis, transformaWolbachia, naoTransformaWolbachia);
				contadorSaudaveis = 0, contadorWolbachia = 0;
			}
			FOR_MOSQUITO(listaMosquitos->lista, i)
			{
				Mosquito* mosquito = i->elementoLista;
				if (mosquito->sexo == FEMEA) {
					MosquitoFemea* mosquitoFemea = (MosquitoFemea*) (mosquito);
					if ((mosquitoFemea->fase == ATIVO) && (mosquitoFemea->contadorPosturas > 0) && (mosquitoFemea->idLoteAtual == idLote) && (mosquitoFemea->vida)) {
						if ((mosquitoFemea->saudeWolbachia == SAUDAVEL) && (mosquitoFemea->idade > CICLOS_CONVERSAO_FEMEAS_ATIVAS_SAUDAVEIS(idLote)))
							contadorSaudaveis++;
						if ((mosquitoFemea->saudeWolbachia == INFECTADO) && (mosquitoFemea->idade > CICLOS_CONVERSAO_FEMEAS_ATIVAS_WOLBACHIA(idLote)))
							contadorWolbachia++;
					}
				}
			}
			if ((contadorSaudaveis + contadorWolbachia) != 0) {
				naoTransformaSaudaveis = (int) (contadorSaudaveis * BS23(idLote));
				transformaSaudaveis = (int) (contadorSaudaveis - naoTransformaSaudaveis);
				naoTransformaWolbachia = (int) (contadorWolbachia * BI23(idLote));
				transformaWolbachia = (int) (contadorWolbachia - naoTransformaWolbachia);
				testeTransformacaoAlados(FEMEA, transformaSaudaveis, naoTransformaSaudaveis, transformaWolbachia, naoTransformaWolbachia);
			}
		}
	}

	// Remove agentes mosquitos não alados e alados por controle natural, de acorde com a fase, saúde e taxas definidas
	void remocaoMosquitosControleNatural(int ciclo) {
		FOR_INT(idLote, 0, quantLotes, 1)
		{
			if ((FREQUENCIA_CONTROLE_NATURAL(idLote) > 0) && ((ciclo % FREQUENCIA_CONTROLE_NATURAL(idLote)) == 0) && (ciclo != 0)) {
				remocaoMosquitosControleNaturalNaoAlados(idLote, OVO, SAUDAVEL, PORCENTAGEM_ELIMINACAO_MACHOS_OVOS_SAUDAVEIS(idLote), PORCENTAGEM_ELIMINACAO_FEMEAS_OVOS_SAUDAVEIS(idLote));
				remocaoMosquitosControleNaturalNaoAlados(idLote, OVO, INFECTADO, PORCENTAGEM_ELIMINACAO_MACHOS_OVOS_COM_WOLBACHIA(idLote), PORCENTAGEM_ELIMINACAO_FEMEAS_OVOS_COM_WOLBACHIA(idLote));
				remocaoMosquitosControleNaturalNaoAlados(idLote, LARVA, SAUDAVEL, PORCENTAGEM_ELIMINACAO_MACHOS_LARVAS_SAUDAVEIS(idLote), PORCENTAGEM_ELIMINACAO_FEMEAS_LARVAS_SAUDAVEIS(idLote));
				remocaoMosquitosControleNaturalNaoAlados(idLote, LARVA, INFECTADO, PORCENTAGEM_ELIMINACAO_MACHOS_LARVAS_COM_WOLBACHIA(idLote), PORCENTAGEM_ELIMINACAO_FEMEAS_LARVAS_COM_WOLBACHIA(idLote));
				remocaoMosquitosControleNaturalNaoAlados(idLote, PUPA, SAUDAVEL, PORCENTAGEM_ELIMINACAO_MACHOS_PUPAS_SAUDAVEIS(idLote), PORCENTAGEM_ELIMINACAO_FEMEAS_PUPAS_SAUDAVEIS(idLote));
				remocaoMosquitosControleNaturalNaoAlados(idLote, PUPA, INFECTADO, PORCENTAGEM_ELIMINACAO_MACHOS_PUPAS_COM_WOLBACHIA(idLote), PORCENTAGEM_ELIMINACAO_FEMEAS_PUPAS_COM_WOLBACHIA(idLote));
				remocaoMosquitosControleNaturalAlados(idLote, SAUDAVEL, PORCENTAGEM_ELIMINACAO_MACHOS_ALADOS_SAUDAVEIS(idLote), PORCENTAGEM_ELIMINACAO_FEMEAS_ALADAS_SAUDAVEIS(idLote));
				remocaoMosquitosControleNaturalAlados(idLote, INFECTADO, PORCENTAGEM_ELIMINACAO_MACHOS_ALADOS_COM_WOLBACHIA(idLote), PORCENTAGEM_ELIMINACAO_FEMEAS_ALADAS_COM_WOLBACHIA(idLote));
			}
		}
	}

	// Remove agentes mosquitos não alados por controle natural, de acordo com fase, saúde e porcentagens por sexo
	void remocaoMosquitosControleNaturalNaoAlados(int idLote, char fase, char saude, double porcentagemMachos, double porcentagemFemeas) {
		Lista<ElementoLista<Mosquito*>*> listaMosquitosMortos;
		int quantidadeMachos = 0, quantidadeFemeas = 0;
		FOR_MOSQUITO(listaMosquitos->lista, i)
		{
			Mosquito* mosquito = i->elementoLista;
			if ((mosquito->fase == fase) && (mosquito->saudeWolbachia == saude) && (mosquito->idLoteAtual == idLote)) {
				if (mosquito->sexo == MACHO)
					quantidadeMachos++;
				else
					quantidadeFemeas++;
			}
		}
		quantidadeMachos = quantidadeMachos * porcentagemMachos;
		quantidadeFemeas = quantidadeFemeas * porcentagemFemeas;
		int quantidadeMachosRemovidos = 0, quantidadeFemeasRemovidas = 0;
		FOR_MOSQUITO(listaMosquitos->lista, i)
		{
			Mosquito* mosquito = i->elementoLista;
			if ((mosquito->sexo == MACHO) && (mosquito->saudeWolbachia == saude) && (mosquito->idLoteAtual == idLote) && (mosquito->fase == fase)) {
				LISTA_NAO_ALADOS(idLote, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
				mosquito->vida = false;
				listaMosquitosMortos.insercaoLista(i);
				quantidadeMachosRemovidos++;
			}
			if (quantidadeMachosRemovidos == quantidadeMachos)
				break;
		}
		FOR_MOSQUITO(listaMosquitos->lista, i)
		{
			Mosquito* mosquito = i->elementoLista;
			if ((mosquito->sexo == FEMEA) && (mosquito->saudeWolbachia == saude) && (mosquito->idLoteAtual == idLote) && (mosquito->fase == fase)) {
				LISTA_NAO_ALADOS(idLote, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
				mosquito->vida = false;
				listaMosquitosMortos.insercaoLista(i);
				quantidadeFemeasRemovidas++;
			}
			if (quantidadeFemeasRemovidas == quantidadeFemeas)
				break;
		}
		FORP2_MOSQUITO(listaMosquitosMortos, i)
		{
			delete (i->elementoLista->elementoLista);
			listaMosquitos->lista->remocaoLista(i->elementoLista);
		}
	}

	// Remove agentes mosquitos alados de acordo com saúde e porcentagem por sexo
	void remocaoMosquitosControleNaturalAlados(int idLote, char saude, double porcentagemMachos, double porcentagemFemeas) {
		Lista<ElementoLista<Mosquito*>*> listaMosquitosMortos;
		int quantidadeMachos = 0, quantidadeFemeas = 0;
		FOR_MOSQUITO(listaMosquitos->lista, i)
		{
			Mosquito* mosquito = i->elementoLista;
			if (((mosquito->fase == ATIVO) || (mosquito->fase == DECADENTE)) && (mosquito->saudeWolbachia == saude) && (mosquito->idLoteAtual == idLote)) {
				if (mosquito->sexo == MACHO)
					quantidadeMachos++;
				else
					quantidadeFemeas++;
			}
		}
		quantidadeMachos = quantidadeMachos * porcentagemMachos;
		quantidadeFemeas = quantidadeFemeas * porcentagemFemeas;
		int quantidadeMachosRemovidos = 0, quantidadeFemeasRemovidas = 0;
		FOR_MOSQUITO(listaMosquitos->lista, i)
		{
			Mosquito* mosquito = i->elementoLista;
			if ((mosquito->sexo == MACHO) && (mosquito->saudeWolbachia == saude) && (mosquito->idLoteAtual == idLote) && ((mosquito->fase == ATIVO) || (mosquito->fase == DECADENTE))) {
				LISTA_MACHOS(idLote, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
				mosquito->vida = false;
				listaMosquitosMortos.insercaoLista(i);
				quantidadeMachosRemovidos++;
			}
			if (quantidadeMachosRemovidos == quantidadeMachos)
				break;
		}
		FOR_MOSQUITO(listaMosquitos->lista, i)
		{
			Mosquito* mosquito = i->elementoLista;
			if ((mosquito->sexo == FEMEA) && (mosquito->saudeWolbachia == saude) && (mosquito->idLoteAtual == idLote) && ((mosquito->fase == ATIVO) || (mosquito->fase == DECADENTE))) {
				LISTA_FEMEAS(idLote, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
				mosquito->vida = false;
				listaMosquitosMortos.insercaoLista(i);
				quantidadeFemeasRemovidas++;
			}
			if (quantidadeFemeasRemovidas == quantidadeFemeas)
				break;
		}
		FORP2_MOSQUITO(listaMosquitosMortos, i)
		{
			delete (i->elementoLista->elementoLista);
			listaMosquitos->lista->remocaoLista(i->elementoLista);
		}
	}

	// Remove agentes mosquitos decadentes que ultrapassaram a idade máxima definida
	void remocaoMosquitosIdade() {
		Lista<ElementoLista<Mosquito*>*> listaMosquitosMortos;
		FOR_MOSQUITO(listaMosquitos->lista, i)
		{
			Mosquito* mosquito = i->elementoLista;
			if (mosquito->vida == false) {
				listaMosquitosMortos.insercaoLista(i);
				continue;
			}
			if (((mosquito->saudeWolbachia == SAUDAVEL) && (mosquito->idade > IDADE_MAXIMA_MOSQUITO_SAUDAVEL(mosquito->idLoteAtual))) || ((mosquito->saudeWolbachia == INFECTADO) && (mosquito->idade > IDADE_MAXIMA_MOSQUITO_WOLBACHIA(mosquito->idLoteAtual))) || ((mosquito->sexo == FEMEA) && (((MosquitoFemea*) (mosquito))->saudeDengue != SAUDAVEL) && (mosquito->idade > IDADE_MAXIMA_FEMEA_DENGUE(mosquito->idLoteAtual)))) {
				if (mosquito->sexo == MACHO) {
					LISTA_MACHOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
					mosquito->vida = false;
					listaMosquitosMortos.insercaoLista(i);
				} else {
					LISTA_FEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
					mosquito->vida = false;
					listaMosquitosMortos.insercaoLista(i);
				}
			}
		}
		FORP2_MOSQUITO(listaMosquitosMortos, i)
		{
			delete (i->elementoLista->elementoLista);
			listaMosquitos->lista->remocaoLista(i->elementoLista);
		}
	}

	// Remove agentes mosquitos não alados por controle químico considerando fase e taxas definidas
	void remocaoMosquitosControleQuimicoEMecanicoNaoAlados(int idLote, double percentual, char fase) {
		Lista<ElementoLista<Mosquito*>*> listaMosquitosMortos;
		int quantidade = 0;
		FOR_MOSQUITO(listaMosquitos->lista, i)
		{
			Mosquito* mosquito = i->elementoLista;
			if ((mosquito->fase == fase) && (mosquito->idLoteAtual == idLote)) {
				quantidade++;
			}
		}
		quantidade = quantidade * percentual;
		int quantidadeRemovidos = 0;
		FOR_MOSQUITO(listaMosquitos->lista, i)
		{
			Mosquito* mosquito = i->elementoLista;
			if ((mosquito->idLoteAtual == idLote) && (mosquito->fase == fase)) {
				Mosquito* mosquito = i->elementoLista;
				LISTA_NAO_ALADOS(idLote, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
				mosquito->vida = false;
				listaMosquitosMortos.insercaoLista(i);
				quantidadeRemovidos++;
			}
			if (quantidadeRemovidos == quantidade)
				break;
		}
		FORP2_MOSQUITO(listaMosquitosMortos, i)
		{
			delete (i->elementoLista->elementoLista);
			listaMosquitos->lista->remocaoLista(i->elementoLista);
		}
	}

	// Remove agentes mosquitos não alados por controle químico
	void remocaoMosquitosControleQuimicoNaoAlados(int ciclo) {
		FOR_INT(idLote, 0, quantLotes, 1)
		{
			if ((LOTE(idLote)->controleQuimicoLarvas != -1) && (LOTE(idLote)->controleQuimicoPupas != -1)) {
				if (LOTE(idLote)->controleQuimicoLarvas > 0) {
					remocaoMosquitosControleQuimicoEMecanicoNaoAlados(idLote, LOTE(idLote)->controleQuimicoLarvas, LARVA);
					LOTE(idLote)->controleQuimicoLarvas -= (1.0 / EFEITO_RESIDUAL_CONTROLE_QUIMICO_LARVAS(idLote));
				}
				if (LOTE(idLote)->controleQuimicoPupas > 0) {
					remocaoMosquitosControleQuimicoEMecanicoNaoAlados(idLote, LOTE(idLote)->controleQuimicoPupas, PUPA);
					LOTE(idLote)->controleQuimicoPupas -= (1.0 / EFEITO_RESIDUAL_CONTROLE_QUIMICO_PUPAS(idLote));
				}
				if ((FREQUENCIA_CONTROLE_QUIMICO_NAO_ALADOS(idLote) > 0) && ((ciclo % FREQUENCIA_CONTROLE_QUIMICO_NAO_ALADOS(idLote)) == 0) && (ciclo != 0)) {
					LOTE(idLote)->controleQuimicoLarvas = 1.0;
					LOTE(idLote)->controleQuimicoPupas = 1.0;
				}
			}
		}
	}

	// Remove agentes mosquitos não alados por controle mecânico
	void remocaoMosquitosControleMecanicoNaoAlados(int ciclo) {
		FOR_INT(idLote, 0, quantLotes, 1)
		{
			if ((FREQUENCIA_CONTROLE_MECANICO_NAO_ALADOS(idLote) > 0) && ((ciclo % FREQUENCIA_CONTROLE_MECANICO_NAO_ALADOS(idLote)) == 0) && (ciclo != 0) && (LOTE(idLote)->controleMecanicoNaoAlados)) {
				remocaoMosquitosControleQuimicoEMecanicoNaoAlados(idLote, TAXA_CONTROLE_MECANICO_OVOS(idLote), OVO);
				remocaoMosquitosControleQuimicoEMecanicoNaoAlados(idLote, TAXA_CONTROLE_MECANICO_LARVAS(idLote), LARVA);
				remocaoMosquitosControleQuimicoEMecanicoNaoAlados(idLote, TAXA_CONTROLE_MECANICO_PUPAS(idLote), PUPA);
			}
		}
	}

	// Remove agentes mosquitos alados por controle químíco
	void remocaoMosquitosControleQuimicoAlados(int idLote, double percentual) {
		Lista<ElementoLista<Mosquito*>*> listaMosquitosMortos;
		int quantidade = 0;
		FOR_MOSQUITO(listaMosquitos->lista, i)
		{
			Mosquito* mosquito = i->elementoLista;
			if (((mosquito->fase == ATIVO) || (mosquito->fase == DECADENTE)) && (mosquito->idLoteAtual == idLote)) {
				quantidade++;
			}
		}
		quantidade = quantidade * percentual;
		int quantidadeRemovidos = 0;
		FOR_MOSQUITO(listaMosquitos->lista, i)
		{
			Mosquito* mosquito = i->elementoLista;
			if ((mosquito->idLoteAtual == idLote) && ((mosquito->fase == ATIVO) || (mosquito->fase == DECADENTE))) {
				if (mosquito->sexo == MACHO) {
					LISTA_MACHOS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
					mosquito->vida = false;
					listaMosquitosMortos.insercaoLista(i);
				} else {
					LISTA_FEMEAS(mosquito->idLoteAtual, mosquito->posicaoAtual.x, mosquito->posicaoAtual.y).buscaRemocaoLista(mosquito);
					mosquito->vida = false;
					listaMosquitosMortos.insercaoLista(i);
				}
				quantidadeRemovidos++;
			}
			if (quantidadeRemovidos == quantidade)
				break;
		}
		FORP2_MOSQUITO(listaMosquitosMortos, i)
		{
			delete (i->elementoLista->elementoLista);
			listaMosquitos->lista->remocaoLista(i->elementoLista);
		}
	}

	// Testa controle químíco para agentes mosquitos alados
	void remocaoMosquitosControleQuimicoAlados(int ciclo) {
		FOR_INT(idLote, 0, quantLotes, 1)
		{
			if ((FREQUENCIA_CONTROLE_QUIMICO_ALADOS(idLote) > 0) && ((ciclo % FREQUENCIA_CONTROLE_QUIMICO_ALADOS(idLote)) == 0) && (ciclo != 0) && (LOTE(idLote)->controleQuimicoAlados)) {
				remocaoMosquitosControleQuimicoAlados(idLote, TAXA_CONTROLE_QUIMICO_ALADOS(idLote));
			}
		}
	}

};

#endif

