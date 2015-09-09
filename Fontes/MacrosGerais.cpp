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
#define COLUNAS_SAIDAS_WOLBACHIA 12
#define COLUNAS_SAIDAS_HUMANOS 13
#define COLUNAS_SAIDAS_DENGUE 13

double randomizarPercentual() {
	double max = pow(MAX_RAND, 2) + (MAX_RAND - 1);
	double val = MAX_RAND * (rand() % (MAX_RAND + 1)) + (rand() % MAX_RAND);
	return abs(val / max);
}

double randomizarEntreFaixa(double min, double max) {
	double percentual = randomizarPercentual();
	return min + (max - min) * percentual;
}

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

#endif
