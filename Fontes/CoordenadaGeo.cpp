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
		return sqrt(pow(x - d.x, 2.0) + pow(y - d.y, 2.0));
	}
    
    ~CoordenadaGeo() {}

};

#endif
