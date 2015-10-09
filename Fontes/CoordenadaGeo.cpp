#ifndef _COORDENADAGEO_
#define _COORDENADAGEO_

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
