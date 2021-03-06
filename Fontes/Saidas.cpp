#ifndef _SAIDAS_
#define _SAIDAS_

// Classe que armazena as saídas das simulações
class Saidas {
public:

	bool validade; // validade da saída armazenada
	int quantLotes; // quantidade de lotes
	stringstream mosquitosMachos; // saída para agentes mosquitos machos
	stringstream mosquitosFemeas; // saída para agentes mosquitos fêmeas
	stringstream* sdl; // saída espacial
	stringstream* quantidadesDengueLote; // saída para quantidades de agentes mosquitos visão dengue por lote
	stringstream* quantidadesWolbachiaLote; // saída para quantidades de agentes mosquitos visão Wolbachia por lote
	stringstream* quantidadesHumanosLote; // saída para quantidades de agentes humanos por lote
	stringstream quantidadesDengueQuadra; // saída para quantidades de agentes mosquitos visão dengue por quadra
	stringstream quantidadesWolbachiaQuadra; // saída para quantidades de agentes mosquitos visão Wolbachia por quadra
	stringstream quantidadesHumanosQuadra; // saída para quantidades de agentes humanos por quadra

	Saidas() {
	}

	void init(int quantLotes) {
		this->quantLotes = quantLotes;
		zero();
	}

	void zero() {
		validade = false;
		mosquitosMachos.str(std::string());
		mosquitosFemeas.str(std::string());
		sdl = new stringstream[quantLotes]();
		quantidadesDengueLote = new stringstream[quantLotes]();
		quantidadesWolbachiaLote = new stringstream[quantLotes]();
		quantidadesHumanosLote = new stringstream[quantLotes]();
		FOR_INT(i, 0, quantLotes, 1)
		{
			sdl[i].str(std::string());
			quantidadesDengueLote[i].str(std::string());
			quantidadesWolbachiaLote[i].str(std::string());
			quantidadesHumanosLote[i].str(std::string());
		}
		quantidadesDengueQuadra.str(std::string());
		quantidadesWolbachiaQuadra.str(std::string());
		quantidadesHumanosQuadra.str(std::string());
	}

	~Saidas() {
		delete[] (sdl);
		delete[] (quantidadesDengueLote);
		delete[] (quantidadesWolbachiaLote);
		delete[] (quantidadesHumanosLote);
	}

};

#endif
