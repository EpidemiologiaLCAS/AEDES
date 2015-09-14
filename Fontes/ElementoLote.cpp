#ifndef ELEMENTOLOTE
#define ELEMENTOLOTE

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
    CoordenadaGeo coordenadaGeo;

    ElementoLote() {}

    ~ElementoLote() {
		listaVizinhancaMosquitos.preDestrutor();
		listaVizinhancaHumanos.preDestrutor();
		listaAreaPercepcaoHumanos.preDestrutor();
	}

    int quantidadeTotalMosquitosPosicao() {
        return (listaMosquitosMachos.tamanhoLista + listaMosquitosFemeas.tamanhoLista);
    }
    
    bool humanoSuscetivel() {
		ElementoLista<Humano*>* i = listaHumanos.cabecaLista;
		while (i != NULL) {
			if ((i->elementoLista->saude == 's') && (i->elementoLista->listaSorotiposContraidos.tamanhoLista == 0)) {
				return true;
			}
			i = i->proximoLista;
		}
		return false;
	}
	
	bool humanoLatente() {
		ElementoLista<Humano*>* i = listaHumanos.cabecaLista;
		while (i != NULL) {
			if (i->elementoLista->saude == 'l') {
				return true;
			}
			i = i->proximoLista;
		}
		return false;
	}
	
	bool humanoInfectante() {
		ElementoLista<Humano*>* i = listaHumanos.cabecaLista;
		while (i != NULL) {
			if (i->elementoLista->saude == 'i') {
				return true;
			}
			i = i->proximoLista;
		}
		return false;
	}
	
	bool humanoImunizado() {
		ElementoLista<Humano*>* i = listaHumanos.cabecaLista;
		while (i != NULL) {
			if (i->elementoLista->saude == 'm') {
				return true;
			}
			i = i->proximoLista;
		}
		return false;
	}
	
	bool humanoRecuperado() {
		ElementoLista<Humano*>* i = listaHumanos.cabecaLista;
		while (i != NULL) {
			if ((i->elementoLista->saude == 's') && (i->elementoLista->listaSorotiposContraidos.tamanhoLista > 0)) {
				return true;
			}
			i = i->proximoLista;
		}
		return false;
	}
	
	bool femeaSuscetivel() {
		ElementoLista<Mosquito*>* i = listaMosquitosFemeas.cabecaLista;
		while (i != NULL) {
			if (i->elementoLista->sexo == 'f') {
				MosquitoFemea* j = (MosquitoFemea*) i->elementoLista;
				if (j->saudeDengue == 's') {
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
			if (i->elementoLista->sexo == 'f') {
				MosquitoFemea* j = (MosquitoFemea*) i->elementoLista;
				if (j->saudeDengue == 'l') {
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
			if (i->elementoLista->sexo == 'f') {
				MosquitoFemea* j = (MosquitoFemea*) i->elementoLista;
				if (j->saudeDengue == 'i') {
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
