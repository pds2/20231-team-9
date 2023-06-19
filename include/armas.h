#ifndef PDS2_ARMAS_H
#define PDS2_ARMAS_H

enum armas {
    desarmado, faca, arco, espada, machado
};
//poder de cada arma:
/*
 * desarmado: 1
 * faca: 2
 * arco: 3
 * espada: 4
 * machado: 5
 */

class Arma {
    private:
        armas _tipo;
        int _poder;
    public:

        /*
        * @brief Construtor
        */
        Arma(armas tipo);
        /*
        * @brief Retorna o tipo da arma (enum armas)
        */
        armas get_tipo() const;
        /*
        * @brief Retorna o poder da arma
        */
        int get_poder() const;
};

#endif