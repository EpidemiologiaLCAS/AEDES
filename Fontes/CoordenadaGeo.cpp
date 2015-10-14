#ifndef _COORDENADAGEO_
#define _COORDENADAGEO_

class CoordenadaGeo {
public:

    double x;
    double y;
    
    CoordenadaGeo() {}

    CoordenadaGeo(double x, double y) {
        this->x = x;
        this->y = y;
    }
    
    double distancia(CoordenadaGeo dest) {
		return abs((this->x - dest.x) + (this->y - dest.y));
	}
    
    ~CoordenadaGeo() {}

};

#endif
