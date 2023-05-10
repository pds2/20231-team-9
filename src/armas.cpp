#include "../include/armas.h"

Arma::Arma(armas tipo, int poder) {
    _tipo = tipo;
    _poder = poder;
}

armas Arma::get_tipo() const {
    return _tipo;
}

int Arma::get_poder() const {
    return _poder;
}