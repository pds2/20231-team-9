#include "../include/armas.h"

Arma::Arma(armas tipo) {
    _tipo = tipo;
    if(tipo == armas::desarmado) {
        _poder = 1;
        _nome = "Desarmado";
    }
    if(tipo == armas::faca) {
        _poder = 2;
        _nome = "Faca";
    }
    if(tipo == armas::arco) {
        _poder = 3;
        _nome = "Arco e flecha";
    }
    if(tipo == armas::espada) {
        _poder = 4;
        _nome = "Espada";
    }
    if(tipo == armas::machado) {
        _poder = 5;
        _nome = "Machado";
    }
}

armas Arma::get_tipo() const {
    return _tipo;
}

int Arma::get_poder() const {
    return _poder;
}

std::string Arma::get_nome() const {
    return _nome;
}