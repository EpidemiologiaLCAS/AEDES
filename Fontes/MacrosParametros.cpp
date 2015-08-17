#ifndef MACROSPARAMETROS
#define MACROSPARAMETROS

#define QUANTIDADE_PARAMETROS_ACA 12
#define QUANTIDADE_PARAMETROS_AMB 4
#define QUANTIDADE_PARAMETROS_CNA 30
#define QUANTIDADE_PARAMETROS_DEN 27
#define QUANTIDADE_PARAMETROS_GER 30
#define QUANTIDADE_PARAMETROS_INS 22
#define QUANTIDADE_PARAMETROS_MOV 8
#define QUANTIDADE_PARAMETROS_SIM 3
#define QUANTIDADE_PARAMETROS_SMC 2
#define QUANTIDADE_PARAMETROS_TRA 23

#define BETASS22(idLote) (double) parametros->pACA[idLote]->vetor[0].random()
#define BETASS23(idLote) (double) parametros->pACA[idLote]->vetor[1].random()
#define BETAII22(idLote) (double) parametros->pACA[idLote]->vetor[2].random()
#define BETAII23(idLote) (double) parametros->pACA[idLote]->vetor[3].random()
#define BETAIS22(idLote) (double) parametros->pACA[idLote]->vetor[4].random()
#define BETAIS23(idLote) (double) parametros->pACA[idLote]->vetor[5].random()
#define BETASI22(idLote) (double) parametros->pACA[idLote]->vetor[6].random()
#define BETASI23(idLote) (double) parametros->pACA[idLote]->vetor[7].random()
#define K1(idLote) (double) parametros->pACA[idLote]->vetor[8].random()
#define K2(idLote) (double) parametros->pACA[idLote]->vetor[9].random()
#define RAIO_BUSCA_MACHO(idLote) (int) parametros->pACA[idLote]->vetor[10].random()
#define TAXA_FECUNDIDADE(idLote) (double) parametros->pACA[idLote]->vetor[11].random()

#define NUMERO_LINHAS_AMBIENTE(idLote) (int) parametros->pAMB[idLote]->vetor[0].random()
#define NUMERO_COLUNAS_AMBIENTE(idLote) (int) parametros->pAMB[idLote]->vetor[1].random()
#define CAPACIDADE_MAXIMA_POSICAO_MOSQUITOS(idLote) (int) parametros->pAMB[idLote]->vetor[2].random()
#define CAPACIDADE_MAXIMA_POSICAO_HUMANOS(idLote) (int) parametros->pAMB[idLote]->vetor[3].random()

#define TAXA_CONTROLE_NATURAL_HUMANOS(idLote) (double) parametros->pCNA[idLote]->vetor[0].random()
#define IDADE_MAXIMA_MOSQUITO_SAUDAVEL(idLote) (int) parametros->pCNA[idLote]->vetor[1].random()
#define IDADE_MAXIMA_MOSQUITO_WOLBACHIA(idLote) (int) parametros->pCNA[idLote]->vetor[2].random()
#define IDADE_MAXIMA_FEMEA_DENGUE(idLote) (int) parametros->pCNA[idLote]->vetor[3].random()
#define FREQUENCIA_CONTROLE_NATURAL(idLote) (int) parametros->pCNA[idLote]->vetor[4].random()
#define PORCENTAGEM_ELIMINACAO_MACHOS_OVOS_SAUDAVEIS(idLote) (double) parametros->pCNA[idLote]->vetor[5].random()
#define PORCENTAGEM_ELIMINACAO_FEMEAS_OVOS_SAUDAVEIS(idLote) (double) parametros->pCNA[idLote]->vetor[6].random()
#define PORCENTAGEM_ELIMINACAO_MACHOS_OVOS_COM_WOLBACHIA(idLote) (double) parametros->pCNA[idLote]->vetor[7].random()
#define PORCENTAGEM_ELIMINACAO_FEMEAS_OVOS_COM_WOLBACHIA(idLote) (double) parametros->pCNA[idLote]->vetor[8].random()
#define PORCENTAGEM_ELIMINACAO_MACHOS_ALADOS_SAUDAVEIS(idLote) (double) parametros->pCNA[idLote]->vetor[9].random()
#define PORCENTAGEM_ELIMINACAO_FEMEAS_ALADAS_SAUDAVEIS(idLote) (double) parametros->pCNA[idLote]->vetor[10].random()
#define PORCENTAGEM_ELIMINACAO_MACHOS_ALADOS_COM_WOLBACHIA(idLote) (double) parametros->pCNA[idLote]->vetor[11].random()
#define PORCENTAGEM_ELIMINACAO_FEMEAS_ALADAS_COM_WOLBACHIA(idLote) (double) parametros->pCNA[idLote]->vetor[12].random()
#define PORCENTAGEM_ELIMINACAO_MACHOS_LARVAS_SAUDAVEIS(idLote) (double) parametros->pCNA[idLote]->vetor[13].random()
#define PORCENTAGEM_ELIMINACAO_FEMEAS_LARVAS_SAUDAVEIS(idLote) (double) parametros->pCNA[idLote]->vetor[14].random()
#define PORCENTAGEM_ELIMINACAO_MACHOS_LARVAS_COM_WOLBACHIA(idLote) (double) parametros->pCNA[idLote]->vetor[15].random()
#define PORCENTAGEM_ELIMINACAO_FEMEAS_LARVAS_COM_WOLBACHIA(idLote) (double) parametros->pCNA[idLote]->vetor[16].random()
#define PORCENTAGEM_ELIMINACAO_MACHOS_PUPAS_SAUDAVEIS(idLote) (double) parametros->pCNA[idLote]->vetor[17].random()
#define PORCENTAGEM_ELIMINACAO_FEMEAS_PUPAS_SAUDAVEIS(idLote) (double) parametros->pCNA[idLote]->vetor[18].random()
#define PORCENTAGEM_ELIMINACAO_MACHOS_PUPAS_COM_WOLBACHIA(idLote) (double) parametros->pCNA[idLote]->vetor[19].random()
#define PORCENTAGEM_ELIMINACAO_FEMEAS_PUPAS_COM_WOLBACHIA(idLote) (double) parametros->pCNA[idLote]->vetor[20].random()
#define FREQUENCIA_CONTROLE_QUIMICO_NAO_ALADOS(idLote) (int) parametros->pCNA[idLote]->vetor[21].random()
#define EFEITO_RESIDUAL_CONTROLE_QUIMICO_LARVAS(idLote) (int) parametros->pCNA[idLote]->vetor[22].random()
#define EFEITO_RESIDUAL_CONTROLE_QUIMICO_PUPAS(idLote) (int) parametros->pCNA[idLote]->vetor[23].random()
#define FREQUENCIA_CONTROLE_MECANICO_NAO_ALADOS(idLote) (int) parametros->pCNA[idLote]->vetor[24].random()
#define TAXA_CONTROLE_MECANICO_OVOS(idLote) (double) parametros->pCNA[idLote]->vetor[25].random()
#define TAXA_CONTROLE_MECANICO_LARVAS(idLote) (double) parametros->pCNA[idLote]->vetor[26].random()
#define TAXA_CONTROLE_MECANICO_PUPAS(idLote) (double) parametros->pCNA[idLote]->vetor[27].random()
#define FREQUENCIA_CONTROLE_QUIMICO_ALADOS(idLote) (int) parametros->pCNA[idLote]->vetor[28].random()
#define TAXA_CONTROLE_QUIMICO_ALADOS(idLote) (double) parametros->pCNA[idLote]->vetor[29].random()

#define CICLOS_LATENTE_MOSQUITO(idLote) (int) parametros->pDEN[idLote]->vetor[0].random()
#define CICLOS_LATENTE_HUMANO(idLote) (int) parametros->pDEN[idLote]->vetor[1].random()
#define CICLOS_INFECTANTE_HUMANO(idLote) (int) parametros->pDEN[idLote]->vetor[2].random()
#define CICLOS_IMUNIZADO_HUMANO(idLote) (int) parametros->pDEN[idLote]->vetor[3].random()
#define PROBABILIDADE_INFECCAO_HUMANA_SOROTIPO_1(idLote) (double) parametros->pDEN[idLote]->vetor[4].random()
#define PROBABILIDADE_INFECCAO_HUMANA_SOROTIPO_2(idLote) (double) parametros->pDEN[idLote]->vetor[5].random()
#define PROBABILIDADE_INFECCAO_HUMANA_SOROTIPO_3(idLote) (double) parametros->pDEN[idLote]->vetor[6].random()
#define PROBABILIDADE_INFECCAO_HUMANA_SOROTIPO_4(idLote) (double) parametros->pDEN[idLote]->vetor[7].random()
#define PROBABILIDADE_INFECCAO_HUMANA_SOROTIPO_5(idLote) (double) parametros->pDEN[idLote]->vetor[8].random()
#define PROBABILIDADE_DENGUE_HEMORRAGICA_1_SOROTIPO_CONTRAIDO(idLote) (double) parametros->pDEN[idLote]->vetor[9].random()
#define PROBABILIDADE_DENGUE_HEMORRAGICA_2_SOROTIPOS_CONTRAIDOS(idLote) (double) parametros->pDEN[idLote]->vetor[10].random()
#define PROBABILIDADE_DENGUE_HEMORRAGICA_3_SOROTIPOS_CONTRAIDOS(idLote) (double) parametros->pDEN[idLote]->vetor[11].random()
#define PROBABILIDADE_DENGUE_HEMORRAGICA_4_SOROTIPOS_CONTRAIDOS(idLote) (double) parametros->pDEN[idLote]->vetor[12].random()
#define PROBABILIDADE_DENGUE_HEMORRAGICA_5_SOROTIPOS_CONTRAIDOS(idLote) (double) parametros->pDEN[idLote]->vetor[13].random()
#define PROBABILIDADE_MORTE(idLote) (double) parametros->pDEN[idLote]->vetor[14].random()
#define PROBABILIDADE_INFECCAO_HUMANO_RECUPERADO_SOROTIPO_1(idLote) (double) parametros->pDEN[idLote]->vetor[15].random()
#define PROBABILIDADE_INFECCAO_HUMANO_RECUPERADO_SOROTIPO_2(idLote) (double) parametros->pDEN[idLote]->vetor[16].random()
#define PROBABILIDADE_INFECCAO_HUMANO_RECUPERADO_SOROTIPO_3(idLote) (double) parametros->pDEN[idLote]->vetor[17].random()
#define PROBABILIDADE_INFECCAO_HUMANO_RECUPERADO_SOROTIPO_4(idLote) (double) parametros->pDEN[idLote]->vetor[18].random()
#define PROBABILIDADE_INFECCAO_HUMANO_RECUPERADO_SOROTIPO_5(idLote) (double) parametros->pDEN[idLote]->vetor[19].random()
#define PROBABILIDADE_INFECCAO_MOSQUITO_SOROTIPO_1(idLote) (double) parametros->pDEN[idLote]->vetor[20].random()
#define PROBABILIDADE_INFECCAO_MOSQUITO_SOROTIPO_2(idLote) (double) parametros->pDEN[idLote]->vetor[21].random()
#define PROBABILIDADE_INFECCAO_MOSQUITO_SOROTIPO_3(idLote) (double) parametros->pDEN[idLote]->vetor[22].random()
#define PROBABILIDADE_INFECCAO_MOSQUITO_SOROTIPO_4(idLote) (double) parametros->pDEN[idLote]->vetor[23].random()
#define PROBABILIDADE_INFECCAO_MOSQUITO_SOROTIPO_5(idLote) (double) parametros->pDEN[idLote]->vetor[24].random()
#define TAXA_SUCESSO_INFECCAO_HUMANO(idLote) (double) parametros->pDEN[idLote]->vetor[25].random()
#define TAXA_SUCESSO_INFECCAO_MOSQUITO(idLote) (double) parametros->pDEN[idLote]->vetor[26].random()

#define QUANTIDADE_MS1(idLote) (int) parametros->pGER[idLote]->vetor[0].random()
#define QUANTIDADE_MS2(idLote) (int) parametros->pGER[idLote]->vetor[1].random()
#define QUANTIDADE_MS3(idLote) (int) parametros->pGER[idLote]->vetor[2].random()
#define QUANTIDADE_FS1(idLote) (int) parametros->pGER[idLote]->vetor[3].random()
#define QUANTIDADE_FS2(idLote) (int) parametros->pGER[idLote]->vetor[4].random()
#define QUANTIDADE_FS3(idLote) (int) parametros->pGER[idLote]->vetor[5].random()
#define QUANTIDADE_MI1(idLote) (int) parametros->pGER[idLote]->vetor[6].random()
#define QUANTIDADE_MI2(idLote) (int) parametros->pGER[idLote]->vetor[7].random()
#define QUANTIDADE_MI3(idLote) (int) parametros->pGER[idLote]->vetor[8].random()
#define QUANTIDADE_FI1(idLote) (int) parametros->pGER[idLote]->vetor[9].random()
#define QUANTIDADE_FI2(idLote) (int) parametros->pGER[idLote]->vetor[10].random()
#define QUANTIDADE_FI3(idLote) (int) parametros->pGER[idLote]->vetor[11].random()
#define QUANTIDADE_FDI1(idLote) (int) parametros->pGER[idLote]->vetor[12].random()
#define QUANTIDADE_FDI2(idLote) (int) parametros->pGER[idLote]->vetor[13].random()
#define QUANTIDADE_FDI3(idLote) (int) parametros->pGER[idLote]->vetor[14].random()
#define QUANTIDADE_FDI4(idLote) (int) parametros->pGER[idLote]->vetor[15].random()
#define QUANTIDADE_FDI5(idLote) (int) parametros->pGER[idLote]->vetor[16].random()
#define CICLOS_GESTACAO(idLote) (int) parametros->pGER[idLote]->vetor[17].random()
#define AS21(idLote) (int) parametros->pGER[idLote]->vetor[18].random()
#define PS21(idLote) (double) parametros->pGER[idLote]->vetor[19].random()
#define H1(idLote) (double) parametros->pGER[idLote]->vetor[20].random()
#define PS31(idLote) (double) parametros->pGER[idLote]->vetor[21].random()
#define AI21(idLote) (int) parametros->pGER[idLote]->vetor[22].random()
#define PI21(idLote) (double) parametros->pGER[idLote]->vetor[23].random()
#define H2(idLote) (double) parametros->pGER[idLote]->vetor[24].random()
#define PI31(idLote) (double) parametros->pGER[idLote]->vetor[25].random()
#define INTERVALO_ENTRE_POSTURAS_FEMEA(idLote) (int) parametros->pGER[idLote]->vetor[26].random()
#define INTERVALO_ENTRE_BUSCA_ALIMENTO_FEMEA(idLote) (int) parametros->pGER[idLote]->vetor[27].random()
#define PROBABILIDADE_VOO_LEVY_ANTES_POSTURA(idLote) (double) parametros->pGER[idLote]->vetor[28].random()
#define PROBABILIDADE_VOO_LEVY_ANTES_PROCURA_ALIMENTO(idLote) (double) parametros->pGER[idLote]->vetor[29].random()

#define CICLO_DE_ENTRADA_HUMANOS_1(idLote) (int) parametros->pINS[idLote]->vetor[0].random()
#define QUANTIDADE_HUMANOS_1(idLote) (int) parametros->pINS[idLote]->vetor[1].random()
#define CICLO_DE_ENTRADA_HUMANOS_2(idLote) (int) parametros->pINS[idLote]->vetor[2].random()
#define QUANTIDADE_HUMANOS_2(idLote) (int) parametros->pINS[idLote]->vetor[3].random()
#define CICLO_DE_ENTRADA_HUMANOS_3(idLote) (int) parametros->pINS[idLote]->vetor[4].random()
#define QUANTIDADE_HUMANOS_3(idLote) (int) parametros->pINS[idLote]->vetor[5].random()
#define CICLO_DE_ENTRADA_HUMANOS_4(idLote) (int) parametros->pINS[idLote]->vetor[6].random()
#define QUANTIDADE_HUMANOS_4(idLote) (int) parametros->pINS[idLote]->vetor[7].random()
#define CICLO_DE_ENTRADA_HUMANOS_5(idLote) (int) parametros->pINS[idLote]->vetor[8].random()
#define QUANTIDADE_HUMANOS_5(idLote) (int) parametros->pINS[idLote]->vetor[9].random()
#define CICLO_DE_ENTRADA_HUMANOS_S(idLote) (int) parametros->pINS[idLote]->vetor[10].random()
#define QUANTIDADE_HUMANOS_S(idLote) (int) parametros->pINS[idLote]->vetor[11].random()
#define CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_1(idLote) (int) parametros->pINS[idLote]->vetor[12].random()
#define QUANTIDADE_HUMANOS_RECUPERADOS_1(idLote) (int) parametros->pINS[idLote]->vetor[13].random()
#define CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_2(idLote) (int) parametros->pINS[idLote]->vetor[14].random()
#define QUANTIDADE_HUMANOS_RECUPERADOS_2(idLote) (int) parametros->pINS[idLote]->vetor[15].random()
#define CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_3(idLote) (int) parametros->pINS[idLote]->vetor[16].random()
#define QUANTIDADE_HUMANOS_RECUPERADOS_3(idLote) (int) parametros->pINS[idLote]->vetor[17].random()
#define CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_4(idLote) (int) parametros->pINS[idLote]->vetor[18].random()
#define QUANTIDADE_HUMANOS_RECUPERADOS_4(idLote) (int) parametros->pINS[idLote]->vetor[19].random()
#define CICLO_DE_ENTRADA_HUMANOS_RECUPERADOS_5(idLote) (int) parametros->pINS[idLote]->vetor[20].random()
#define QUANTIDADE_HUMANOS_RECUPERADOS_5(idLote) (int) parametros->pINS[idLote]->vetor[21].random()

#define REGIAO_DE_POSTURA_X(idLote) (int) parametros->pMOV[idLote]->vetor[0].random()
#define REGIAO_DE_POSTURA_Y(idLote) (int) parametros->pMOV[idLote]->vetor[1].random()
#define AMPLITUDE_VOO_LEVY_CURTO(idLote) (int) parametros->pMOV[idLote]->vetor[2].random()
#define AMPLITUDE_VOO_LEVY_LONGO(idLote) (int) parametros->pMOV[idLote]->vetor[3].random()
#define TENTATIVAS_VOO_LEVY(idLote) (int) parametros->pMOV[idLote]->vetor[4].random()
#define AREA_PERCEPCAO_ALIMENTO(idLote) (int) parametros->pMOV[idLote]->vetor[5].random()
#define PORCENTAGEM_MOVIMENTACAO_NOTURNA_MOSQUITOS(idLote) (double) parametros->pMOV[idLote]->vetor[6].random()
#define FATOR_AMORTECIMENTO_PROCURA_HUMANO(idLote) (int) parametros->pMOV[idLote]->vetor[7].random()

#define NUMERO_CICLOS_SIMULACAO (int) parametros->pSIM->vetor[0].random()
#define NUMERO_SUBCICLOS (int) parametros->pSIM->vetor[1].random()
#define MAXIMO_MOSQUITOS (int) parametros->pSIM->vetor[2].random()

#define QUANTIDADE_SIMULACOES (int) parametros->pSMC->vetor[0].random()
#define MAXIMO_TENTATIVAS_SIMULACAO (int) parametros->pSMC->vetor[1].random()

#define CICLOS_CONVERSAO_OVOS(idLote) (int) parametros->pTRA[idLote]->vetor[0].random()
#define BS12_OVOS(idLote) (double) parametros->pTRA[idLote]->vetor[1].random()
#define CS12_OVOS(idLote) (double) parametros->pTRA[idLote]->vetor[2].random()
#define BI12_OVOS(idLote) (double) parametros->pTRA[idLote]->vetor[3].random()
#define CI12_OVOS(idLote) (double) parametros->pTRA[idLote]->vetor[4].random()
#define CICLOS_CONVERSAO_MACHOS_ATIVOS_SAUDAVEIS(idLote) (int) parametros->pTRA[idLote]->vetor[5].random()
#define CICLOS_CONVERSAO_MACHOS_ATIVOS_WOLBACHIA(idLote) (int) parametros->pTRA[idLote]->vetor[6].random()
#define CS23(idLote) (double) parametros->pTRA[idLote]->vetor[7].random()
#define CI23(idLote) (double) parametros->pTRA[idLote]->vetor[8].random()
#define CICLOS_CONVERSAO_FEMEAS_ATIVAS_SAUDAVEIS(idLote) (int) parametros->pTRA[idLote]->vetor[9].random()
#define CICLOS_CONVERSAO_FEMEAS_ATIVAS_WOLBACHIA(idLote) (int) parametros->pTRA[idLote]->vetor[10].random()
#define BS23(idLote) (double) parametros->pTRA[idLote]->vetor[11].random()
#define BI23(idLote) (double) parametros->pTRA[idLote]->vetor[12].random()
#define CICLOS_CONVERSAO_LARVAS(idLote) (int) parametros->pTRA[idLote]->vetor[13].random()
#define BS12_LARVAS(idLote) (double) parametros->pTRA[idLote]->vetor[14].random()
#define CS12_LARVAS(idLote) (double) parametros->pTRA[idLote]->vetor[15].random()
#define BI12_LARVAS(idLote) (double) parametros->pTRA[idLote]->vetor[16].random()
#define CI12_LARVAS(idLote) (double) parametros->pTRA[idLote]->vetor[17].random()
#define CICLOS_CONVERSAO_PUPAS(idLote) (int) parametros->pTRA[idLote]->vetor[18].random()
#define BS12_PUPAS(idLote) (double) parametros->pTRA[idLote]->vetor[19].random()
#define CS12_PUPAS(idLote) (double) parametros->pTRA[idLote]->vetor[20].random()
#define BI12_PUPAS(idLote) (double) parametros->pTRA[idLote]->vetor[21].random()
#define CI12_PUPAS(idLote) (double) parametros->pTRA[idLote]->vetor[22].random()

#define IDADE_OVOS(idLote) (int) rand() % CICLOS_CONVERSAO_OVOS(idLote)
#define IDADE_MACHOS_ATIVOS_SAUDAVEIS(idLote) (int) (parametros->pTRA[idLote]->vetor[0].valorMinimo + (int) rand() % (int) (CICLOS_CONVERSAO_MACHOS_ATIVOS_SAUDAVEIS(idLote) - parametros->pTRA[idLote]->vetor[0].valorMinimo))
#define IDADE_MACHOS_DECADENTES_SAUDAVEIS(idLote) (int) (parametros->pTRA[idLote]->vetor[5].valorMinimo + (rand() % (int) parametros->pTRA[idLote]->vetor[0].valorMinimo))
#define IDADE_FEMEAS_ATIVAS_SAUDAVEIS(idLote) (int) (parametros->pTRA[idLote]->vetor[0].valorMinimo + (int) rand() % (int) (CICLOS_CONVERSAO_FEMEAS_ATIVAS_SAUDAVEIS(idLote) - parametros->pTRA[idLote]->vetor[0].valorMinimo))
#define IDADE_FEMEAS_DECADENTES_SAUDAVEIS(idLote) (int) (parametros->pTRA[idLote]->vetor[9].valorMinimo + (rand() % (int) parametros->pTRA[idLote]->vetor[0].valorMinimo))
#define IDADE_MACHOS_ATIVOS_WOLBACHIA(idLote) (int) (parametros->pTRA[idLote]->vetor[0].valorMinimo + (int) rand() % (int) (CICLOS_CONVERSAO_MACHOS_ATIVOS_WOLBACHIA(idLote) - parametros->pTRA[idLote]->vetor[0].valorMinimo))
#define IDADE_MACHOS_DECADENTES_WOLBACHIA(idLote) (int) (parametros->pTRA[idLote]->vetor[6].valorMinimo + (rand() % (int) parametros->pTRA[idLote]->vetor[0].valorMinimo))
#define IDADE_FEMEAS_ATIVAS_WOLBACHIA(idLote) (int) (parametros->pTRA[idLote]->vetor[0].valorMinimo + (int) rand() % (int) (CICLOS_CONVERSAO_FEMEAS_ATIVAS_WOLBACHIA(idLote) - parametros->pTRA[idLote]->vetor[0].valorMinimo))
#define IDADE_FEMEAS_DECADENTES_WOLBACHIA(idLote) (int) (parametros->pTRA[idLote]->vetor[10].valorMinimo + (rand() % (int) parametros->pTRA[idLote]->vetor[0].valorMinimo))

#endif
