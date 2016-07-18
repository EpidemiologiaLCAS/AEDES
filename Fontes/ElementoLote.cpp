#ifndef _ELEMENTOLOTE_
#define _ELEMENTOLOTE_

#include "Lista.cpp"
#include "ElementoLista.cpp"
#include "Mosquito.cpp"
#include "MosquitoFemea.cpp"
#include "Humano.cpp"
#include "Conexao.cpp"
#include "CoordenadaGeo.cpp"

// Classe que representa uma posição de um lote
class ElementoLote {
public:

	Lista<Mosquito*> listaMosquitosMachos; // agentes mosquitos machos na posição
	Lista<Mosquito*> listaMosquitosFemeas; // agentes mosquitos fêmeas na posição
	Lista<Mosquito*> listaNaoAlados; // agentes ovos na posição
	Lista<Humano*> listaHumanos; // agentes humanos na posição
	Lista<Conexao*> listaVizinhancaMosquitos; // vizinhança para agentes mosquitos da posição
	Lista<Conexao*> listaVizinhancaHumanos; // vizinhança para agentes humanos da posição
	Lista<Conexao*> listaAreaPercepcaoHumanos; // área de percepção de agentes humanos da posição
	Lista<Conexao*> listaAreaPercepcaoMosquitosMachos; // área de percepção de agentes mosquitos machos da posição
	Lista<Conexao*> listaAreaPercepcaoCriadouros; // área de percepção de criadouros da posição
	CoordenadaGeo coordenadaGeo; // coordenada georeferenciada da posição
	bool criadouro; // presença de criadouro na posição

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

	// Retorna a quantidade total de mosquitos na posição
	int quantidadeTotalMosquitosPosicao() {
		return (listaMosquitosMachos.tamanhoLista + listaMosquitosFemeas.tamanhoLista);
	}

	// Retorna verdadeiro se existe pelo menos um agente humano suscetível na posição
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
	// Retorna verdadeiro se existe pelo menos um agente humano latente na posição
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

	// Retorna verdadeiro se existe pelo menos um agente humano infectante na posição
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

	// Retorna verdadeiro se existe pelo menos um agente humano imunizado na posição
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

	// Retorna verdadeiro se existe pelo menos um agente humano recuperado na posição
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

	// Retorna verdadeiro se existe pelo menos um agente mosquito fêmea suscetível na posição
	bool femeaSuscetivel() {
		ElementoLista<Mosquito*>* i = listaMosquitosFemeas.cabecaLista;
		while (i != NULL) {
			Mosquito* mosquito = i->elementoLista;
			if (mosquito->sexo == FEMEA) {
				MosquitoFemea* mosquitoFemea = (MosquitoFemea*) i->elementoLista;
				if (mosquitoFemea->saudeDengue == SAUDAVEL) {
					return true;
				}
			}
			i = i->proximoLista;
		}
		return false;
	}

	// Retorna verdadeiro se existe pelo menos um agente mosquito fêmea latente na posição
	bool femeaLatente() {
		ElementoLista<Mosquito*>* i = listaMosquitosFemeas.cabecaLista;
		while (i != NULL) {
			Mosquito* mosquito = i->elementoLista;
			if (mosquito->sexo == FEMEA) {
				MosquitoFemea* mosquitoFemea = (MosquitoFemea*) i->elementoLista;
				if (mosquitoFemea->saudeDengue == LATENTE) {
					return true;
				}
			}
			i = i->proximoLista;
		}
		return false;
	}
	
	// Retorna verdadeiro se existe pelo menos um agente mosquito fêmea infectante na posição
	bool femeaInfectante() {
		ElementoLista<Mosquito*>* i = listaMosquitosFemeas.cabecaLista;
		while (i != NULL) {
			Mosquito* mosquito = i->elementoLista;
			if (mosquito->sexo == FEMEA) {
				MosquitoFemea* mosquitoFemea = (MosquitoFemea*) i->elementoLista;
				if (mosquitoFemea->saudeDengue == INFECTADO) {
					return true;
				}
			}
			i = i->proximoLista;
		}
		return false;
	}

	// Retorna verdadeiro se existe pelo menos um agente mosquito não alado na posição
	bool naoAlado() {
		if (listaNaoAlados.tamanhoLista > 0) {
			return true;
		}
		return false;
	}

};

#endif
