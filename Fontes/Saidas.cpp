#ifndef SAIDAS
#define SAIDAS

class Saidas {
public:

	bool validade;
	int quantLotes;
    stringstream mosquitosMachos;
    stringstream mosquitosFemeas;
    stringstream* sdl;
    stringstream* quantidadesDengueLote;
    stringstream* quantidadesWolbachiaLote;
    stringstream* quantidadesHumanosLote;
    stringstream quantidadesDengueQuadra;
    stringstream quantidadesWolbachiaQuadra;
    stringstream quantidadesHumanosQuadra;

	Saidas() {}
	
	void init(int _quantLotes) {
		quantLotes = _quantLotes;
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
		FORINT(i, 0, quantLotes, 1) {
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
		delete[](sdl);
		delete[](quantidadesDengueLote);
		delete[](quantidadesWolbachiaLote);
		delete[](quantidadesHumanosLote);
	}

};

#endif
