#ifndef COORDENADAGEO
#define COORDENADAGEO

class CoordenadaGeo {
public:

    double x;
    double y;
    
    CoordenadaGeo() {}

    CoordenadaGeo(double _x, double _y) {
        x = _x;
        y = _y;
    }
    
    double distancia(CoordenadaGeo d) {
		return abs((x - d.x) + (y - d.y));
	}
    
    ~CoordenadaGeo() {}

};

#endif
