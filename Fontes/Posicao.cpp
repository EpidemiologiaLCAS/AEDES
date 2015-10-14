#ifndef _POSICAO_
#define _POSICAO_

class Posicao {
public:

    int x;
    int y;
    
    Posicao() {}

    Posicao(int x, int y) {
        this->x = x;
        this->y = y;
    }
    
    bool operator==(Posicao pos) {
        if ((x = pos.x) && (y = pos.y)) {
			return true;
		}
		return false;
    }

    ~Posicao() {}

};

#endif
