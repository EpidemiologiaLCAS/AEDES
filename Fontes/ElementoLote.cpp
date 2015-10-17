#ifndef _ELEMENTOLOTE_
#define _ELEMENTOLOTE_

#include "Lista.cpp"
#include "ElementoLista.cpp"
#include "Mosquito.cpp"
#include "MosquitoFemea.cpp"
#include "Humano.cpp"
#include "Conexao.cpp"
#include "CoordenadaGeo.cpp"

class ElementoLote {
public:

	Lista<Mosquito*> listaMosquitosMachos;
	Lista<Mosquito*> listaMosquitosFemeas;
	Lista<Mosquito*> listaOvos;
	Lista<Humano*> listaHumanos;
	Lista<Conexao*> listaVizinhancaMosquitos;
	Lista<Conexao*> listaVizinhancaHumanos;
	Lista<Conexao*> listaAreaPercepcaoHumanos;
	Lista<Conexao*> listaAreaPercepcaoMosquitosMachos;
	Lista<Conexao*> listaAreaPercepcaoCriadouros;
	CoordenadaGeo coordenadaGeo;
	bool criadouro;

	ElementoLote() {
		this->criadouro = false;
	}

	~ElementoLote() {
		listaVizinhancaMosquitos.preDestrutor();
		listaVizinhancaHumanos.preDestrutor();
		listaAreaPercepcaoHumanos.preDestrutor();
		listaAreaPercepcaoMosquitosMachos.preDestrutor();
		listaAreaPercepcaoCriadouros.preDestrutor();
	}

	int quantidadeTotalMosquitosPosicao() {
		return (listaMosquitosMachos.tamanhoLista + listaMosquitosFemeas.tamanhoLista);
	}

	bool humanoSuscetivel() {
		ElementoLista<Humano*>* i = listaHumanos.cabecaLista;
		while (i != NULL) {
			Humano* humano = i->elementoLista;
			if ((humano->saude == SUSCETIVEL) && (humano->listaSorotiposContraidos.tamanhoLista == 0)) {
				return true;
			}
			i = i->proximoLista;
		}
		return false;
	}

	bool humanoLatente() {
		ElementoLista<Humano*>* i = listaHumanos.cabecaLista;
		while (i != NULL) {
			Humano* humano = i->elementoLista;
			if (humano->saude == LATENTE) {
				return true;
			}
			i = i->proximoLista;
		}
		return false;
	}

	bool humanoInfectante() {
		ElementoLista<Humano*>* i = listaHumanos.cabecaLista;
		while (i != NULL) {
			Humano* humano = i->elementoLista;
			if (humano->saude == INFECTADO) {
				return true;
			}
			i = i->proximoLista;
		}
		return false;
	}

	bool humanoImunizado() {
		ElementoLista<Humano*>* i = listaHumanos.cabecaLista;
		while (i != NULL) {
			Humano* humano = i->elementoLista;
			if (humano->saude == IMUNIZADO) {
				return true;
			}
			i = i->proximoLista;
		}
		return false;
	}

	bool humanoRecuperado() {
		ElementoLista<Humano*>* i = listaHumanos.cabecaLista;
		while (i != NULL) {
			Humano* humano = i->elementoLista;
			if ((humano->saude == SUSCETIVEL) && (humano->listaSorotiposContraidos.tamanhoLista > 0)) {
				return true;
			}
			i = i->proximoLista;
		}
		return false;
	}

	bool femeaSuscetivel() {
		ElementoLista<Mosquito*>* i = listaMosquitosFemeas.cabecaLista;
		while (i != NULL) {
			Mosquito* mosquito = i->elementoLista;
			if (mosquito->sexo == FEMEA) {
				MosquitoFemea* mosquitoFemea = (MosquitoFemea*) i;
				if (mosquitoFemea->saudeDengue == SAUDAVEL) {
					return true;
				}
			}
			i = i->proximoLista;
		}
		return false;
	}

	bool femeaLatente() {
		ElementoLista<Mosquito*>* i = listaMosquitosFemeas.cabecaLista;
		while (i != NULL) {
			Mosquito* mosquito = i->elementoLista;
			if (mosquito->sexo == FEMEA) {
				MosquitoFemea* mosquitoFemea = (MosquitoFemea*) i;
				if (mosquitoFemea->saudeDengue == LATENTE) {
					return true;
				}
			}
			i = i->proximoLista;
		}
		return false;
	}

	bool femeaInfectante() {
		ElementoLista<Mosquito*>* i = listaMosquitosFemeas.cabecaLista;
		while (i != NULL) {
			Mosquito* mosquito = i->elementoLista;
			if (mosquito->sexo == FEMEA) {
				MosquitoFemea* mosquitoFemea = (MosquitoFemea*) i;
				if (mosquitoFemea->saudeDengue == INFECTADO) {
					return true;
				}
			}
			i = i->proximoLista;
		}
		return false;
	}

	bool ovos() {
		if (listaOvos.tamanhoLista > 0) {
			return true;
		}
		return false;
	}

};

#endif
