#ifndef PDS2_ARMAS_H
#define PDS2_ARMAS_H

#include <string>

enum armas {
    desarmado=1, faca=2, arco=3, espada=4, machado=5
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
        std::string _nome;
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

        std::string get_nome() const;
};

#endif