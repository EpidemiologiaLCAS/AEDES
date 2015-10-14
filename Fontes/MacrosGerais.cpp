#ifndef _MACROSGERAIS_
#define _MACROSGERAIS_

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

#define FOR_INT(indice, valorInicio, valorFinal, incremento) for (int indice = valorInicio; indice < valorFinal; indice += incremento)
#define FOR_HUMANO(lista, indice) for (ElementoLista<Humano*>* indice = lista->cabecaLista; indice != NULL; indice = indice->proximoLista)
#define FOR2_HUMANO(lista, indice) for (ElementoLista<Humano*>* indice = lista.cabecaLista; indice != NULL; indice = indice->proximoLista)
#define FORP_HUMANO(lista, indice) for (ElementoLista<ElementoLista<Humano*>*>* indice = lista->cabecaLista; indice != NULL; indice = indice->proximoLista)
#define FORP2_HUMANO(lista, indice) for (ElementoLista<ElementoLista<Humano*>*>* indice = lista.cabecaLista; indice != NULL; indice = indice->proximoLista)
#define FOR_MOSQUITO(lista, indice) for (ElementoLista<Mosquito*>* indice = lista->cabecaLista; indice != NULL; indice = indice->proximoLista)
#define FOR2_MOSQUITO(lista, indice) for (ElementoLista<Mosquito*>* indice = lista.cabecaLista; indice != NULL; indice = indice->proximoLista)
#define FORP_MOSQUITO(lista, indice) for (ElementoLista<ElementoLista<Mosquito*>*>* indice = lista->cabecaLista; indice != NULL; indice = indice->proximoLista)
#define FORP2_MOSQUITO(lista, indice) for (ElementoLista<ElementoLista<Mosquito*>*>* indice = lista.cabecaLista; indice != NULL; indice = indice->proximoLista)
#define FOR_CONEXAO(lista, indice) for (ElementoLista<Conexao*>* indice = lista.cabecaLista; indice != NULL; indice = indice->proximoLista)
#define FOR2_CONEXAO(lista, indice) for (ElementoLista<Conexao>* indice = lista.cabecaLista; indice != NULL; indice = indice->proximoLista)

#define CASA 0
#define OUTRO 1
#define CURTO 0
#define LONGO 1
#define MACHO 'm'
#define FEMEA 'f'
#define SAUDAVEL 's'
#define OVO 'o'
#define LARVA 'l'
#define PUPA 'p'
#define ATIVO 'a'
#define DECADENTE 'd'
#define ESTERIL 'e'
#define NENHUM 'n'
#define SUSCETIVEL 's'
#define LATENTE 'l'
#define INFECTADO 'i'
#define IMUNIZADO 'm'
#define HEMORRAGICO 'h'
#define REMOVIDO 'r'
#define RECUPERADO 'r'

#define LOTE(idLote) quadra->lotes[idLote]
#define LISTA_OVOS(idLote, x, y) LOTE(idLote)->lote->matriz[x][y].listaOvos
#define LISTA_MACHOS(idLote, x, y) LOTE(idLote)->lote->matriz[x][y].listaMosquitosMachos
#define LISTA_FEMEAS(idLote, x, y) LOTE(idLote)->lote->matriz[x][y].listaMosquitosFemeas
#define LISTA_HUMANOS(idLote, x, y) LOTE(idLote)->lote->matriz[x][y].listaHumanos
#define LISTA_VIZINHANCA_MOSQUITOS(idLote, x, y) LOTE(idLote)->lote->matriz[x][y].listaVizinhancaMosquitos
#define LISTA_VIZINHANCA_HUMANOS(idLote, x, y) LOTE(idLote)->lote->matriz[x][y].listaVizinhancaHumanos
#define LISTA_PERCEPCAO_MACHOS(idLote, x, y) LOTE(idLote)->lote->matriz[x][y].listaAreaPercepcaoMosquitosMachos
#define LISTA_PERCEPCAO_HUMANOS(idLote, x, y) LOTE(idLote)->lote->matriz[x][y].listaAreaPercepcaoHumanos
#define LISTA_PERCEPCAO_CRIADOUROS(idLote, x, y) LOTE(idLote)->lote->matriz[x][y].listaAreaPercepcaoCriadouros
#define LINHAS_LOTE(idLote) LOTE(idLote)->lote->linhasMatriz
#define COLUNAS_LOTE(idLote) LOTE(idLote)->lote->colunasMatriz
#define POSICAO_LOTE(idLote, x, y) LOTE(idLote)->lote->matriz[x][y]
#define LIMITES_LOTE(idLote, x, y) ((x < LINHAS_LOTE(idLote)) && (x >= 0) && (y < COLUNAS_LOTE(idLote)) && (y >= 0) && (POSICAO_LOTE(idLote, x, y).quantidadeTotalMosquitosPosicao() < CAPACIDADE_MAXIMA_POSICAO_MOSQUITOS(idLote)))
#define LIMITES_LOTE_P(idLote, x, y, px, py) (((x + px) < LINHAS_LOTE(idLote)) && ((x + px) >= 0) && ((y + py) < COLUNAS_LOTE(idLote)) && ((y + py) >= 0) && (POSICAO_LOTE(idLote, x + px, y + py).quantidadeTotalMosquitosPosicao() < CAPACIDADE_MAXIMA_POSICAO_MOSQUITOS(idLote)))
#define VIZINHANCA_MOORE(var1, var2, x, y, ordem) FOR_INT(var1, x - ordem, x + ordem + 1, 1) { \
												 FOR_INT(var2, y - ordem, y + ordem + 1, 1)

double randomizarPercentual() {
	double num = MAX_RAND * (rand() % (MAX_RAND + 1)) + (rand() % MAX_RAND);
	return abs(num / VALOR_MAXIMO);
}

double randomizarEntreFaixa(double min, double max) {
	double percentual = randomizarPercentual();
	return min + (max - min) * percentual;
}

#endif
