#ifndef MACROSGERAIS
#define MACROSGERAIS

#ifdef linux
	#define SISTEMA "Linux"
	#define COMANDO_CRIAR_PASTA	"mkdir -p "
	#define COMANDO_EXCLUIR_PASTA "rm -rf "
	#define SEPARADOR "/"
#elif defined WIN32
	#define SISTEMA "Windows"
	#define COMANDO_CRIAR_PASTA "md "
	#define COMANDO_EXCLUIR_PASTA "rd /s /q "
	#define SEPARADOR "\\"
#endif

#define NUMERO_ARGUMENTOS_PROGRAMA 4
#define TAMANHO_STRINGS_AUXILIARES 10
#define TAMANHO_BARRA_PROGRESSO 20
#define PRECISAO_COUT 5
#define ESPACAMENTO_COUT 5
#define MAX_RAND 32000
#define VALOR_MAXIMO 1024031999
#define COLUNAS_SAIDAS_WOLBACHIA 12
#define COLUNAS_SAIDAS_HUMANOS 13
#define COLUNAS_SAIDAS_DENGUE 13
#define QUANTIDADE_CRIADOUROS_POR_LOTE 10

#define FORINT(indice, valorInicio, valorFinal, incremento) for (int indice = valorInicio; indice < valorFinal; indice += incremento)
#define FORHUMANO(lista, indice) for (ElementoLista<Humano*>* indice = lista->cabecaLista; indice != NULL; indice = indice->proximoLista)
#define FOR2HUMANO(lista, indice) for (ElementoLista<Humano*>* indice = lista.cabecaLista; indice != NULL; indice = indice->proximoLista)
#define FORPHUMANO(lista, indice) for (ElementoLista<ElementoLista<Humano*>*>* indice = lista->cabecaLista; indice != NULL; indice = indice->proximoLista)
#define FORP2HUMANO(lista, indice) for (ElementoLista<ElementoLista<Humano*>*>* indice = lista.cabecaLista; indice != NULL; indice = indice->proximoLista)
#define FORMOSQUITO(lista, indice) for (ElementoLista<Mosquito*>* indice = lista->cabecaLista; indice != NULL; indice = indice->proximoLista)
#define FOR2MOSQUITO(lista, indice) for (ElementoLista<Mosquito*>* indice = lista.cabecaLista; indice != NULL; indice = indice->proximoLista)
#define FORPMOSQUITO(lista, indice) for (ElementoLista<ElementoLista<Mosquito*>*>* indice = lista->cabecaLista; indice != NULL; indice = indice->proximoLista)
#define FORP2MOSQUITO(lista, indice) for (ElementoLista<ElementoLista<Mosquito*>*>* indice = lista.cabecaLista; indice != NULL; indice = indice->proximoLista)
#define FORCONEXAO(lista, indice) for (ElementoLista<Conexao*>* indice = lista.cabecaLista; indice != NULL; indice = indice->proximoLista)
#define FOR2CONEXAO(lista, indice) for (ElementoLista<Conexao>* indice = lista.cabecaLista; indice != NULL; indice = indice->proximoLista)

#define CASA 0
#define OUTRO 1
#define CURTO 0
#define LONGO 1
#define LISTAHUMANOS(idLote, x, y) quadra->lotes[idLote]->lote->matriz[x][y].listaHumanos
#define LISTAVIZINHANCAMOSQUITOS(idLote, x, y) quadra->lotes[idLote]->lote->matriz[x][y].listaVizinhancaMosquitos
#define LISTAVIZINHANCAHUMANOS(idLote, x, y) quadra->lotes[idLote]->lote->matriz[x][y].listaVizinhancaHumanos
#define LISTAPERCEPCAOMACHOS(idLote, x, y) quadra->lotes[idLote]->lote->matriz[x][y].listaAreaPercepcaoMosquitosMachos
#define LISTAPERCEPCAOHUMANOS(idLote, x, y) quadra->lotes[idLote]->lote->matriz[x][y].listaAreaPercepcaoHumanos
#define LISTAPERCEPCAOCRIADOUROS(idLote, x, y) quadra->lotes[idLote]->lote->matriz[x][y].listaAreaPercepcaoCriadouros
#define LINHASLOTE(idLote) quadra->lotes[idLote]->lote->linhasMatriz
#define COLUNASLOTE(idLote) quadra->lotes[idLote]->lote->colunasMatriz
#define POSICAOLOTE(idLote, x, y) quadra->lotes[idLote]->lote->matriz[x][y]
#define LISTAOVOS(idLote, x, y) quadra->lotes[idLote]->lote->matriz[x][y].listaOvos
#define LISTAMACHOS(idLote, x, y) quadra->lotes[idLote]->lote->matriz[x][y].listaMosquitosMachos
#define LISTAFEMEAS(idLote, x, y) quadra->lotes[idLote]->lote->matriz[x][y].listaMosquitosFemeas
#define LIMITESLOTE(idLote, x, y) ((x < LINHASLOTE(idLote)) && (x >= 0) && (y < COLUNASLOTE(idLote)) && (y >= 0) && (POSICAOLOTE(idLote, x, y).quantidadeTotalMosquitosPosicao() < CAPACIDADE_MAXIMA_POSICAO_MOSQUITOS(idLote)))
#define LIMITESLOTEP(idLote, x, y, px, py) (((x + px) < LINHASLOTE(idLote)) && ((x + px) >= 0) && ((y + py) < COLUNASLOTE(idLote)) && ((y + py) >= 0) && (POSICAOLOTE(idLote, x + px, y + py).quantidadeTotalMosquitosPosicao() < CAPACIDADE_MAXIMA_POSICAO_MOSQUITOS(idLote)))
#define VIZINHANCAMOORE(var1, var2, x, y, ordem) FORINT(var1, x - ordem, x + ordem + 1, 1) { \
												 FORINT(var2, y - ordem, y + ordem + 1, 1)

double randomizarPercentual() {
	double num = MAX_RAND * (rand() % (MAX_RAND + 1)) + (rand() % MAX_RAND);
	return abs(num / VALOR_MAXIMO);
}

double randomizarEntreFaixa(double min, double max) {
	double percentual = randomizarPercentual();
	return min + (max - min) * percentual;
}

#endif
