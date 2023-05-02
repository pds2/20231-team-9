#ifndef PDS2_ARMAS_H
#define PDS2_ARMAS_H

enum armas {
    faca, arco, espada, escudo,
};

class Arma {
    private:
        armas _tipo;
        int _poder;
    public:
        Arma(armas tipo, int poder);
        armas get_tipo() const;
};

#endif