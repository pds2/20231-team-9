#include "../include/armas.h"

Arma::Arma(armas tipo) {
    _tipo = tipo;
    if(tipo == armas::desarmado) {
        _poder = 1;
    }
    if(tipo == armas::faca) {
        _poder = 2;
    }
    if(tipo == armas::arco) {
        _poder = 3;
    }
    if(tipo == armas::espada) {
        _poder = 4;
    }
    if(tipo == armas::machado) {
        _poder = 5;
    }
    // _poder = poder;
}

armas Arma::get_tipo() const {
    return _tipo;
}

int Arma::get_poder() const {
    return _poder;
}