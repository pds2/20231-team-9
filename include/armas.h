#ifndef PDS2_ARMAS_H
#define PDS2_ARMAS_H

enum armas {
    desarmado, faca, arco, espada, machado
};

class Arma {
    private:
        armas _tipo;
        int _poder;
    public:

        /*
        * @brief Construtor
        */
        Arma(armas tipo, int poder);
        /*
        * @brief Retorna o tipo da arma
        */
        armas get_tipo() const;
        /*
        * @brief Retorna o poder da arma
        */
        int get_poder() const;
};

#endif