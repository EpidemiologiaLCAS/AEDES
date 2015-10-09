#ifndef _POSICAO_
#define _POSICAO_

class Posicao {
public:

    int x;
    int y;
    
    Posicao() {}

    Posicao(int _x, int _y) {
        x = _x;
        y = _y;
    }
    
    bool operator==(Posicao P) {
        if ((x = P.x) && (y = P.y)) {
			return true;
		}
		return false;
    }

    ~Posicao() {}

};

#endif
