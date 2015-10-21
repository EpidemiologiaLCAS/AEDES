#ifndef _COORDENADAGEO_
#define _COORDENADAGEO_

// Classe que representa as coordenadas georeferenciadas das posições dos lotes
class CoordenadaGeo {
public:

	double x; // coordenada x georeferenciada
	double y; // coordenada y georeferenciada

	CoordenadaGeo() {
	}

	CoordenadaGeo(double x, double y) {
		this->x = x;
		this->y = y;
	}

	// Retorna a distância entre dois pontos utilizando a fórmula |(x1 - x2) + (y1 - y2))|
	double distancia(CoordenadaGeo dest) {
		return abs((this->x - dest.x) + (this->y - dest.y));
	}

	~CoordenadaGeo() {
	}

};

#endif
