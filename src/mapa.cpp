#include "mapa.h"

//O Construtor define os atributos de cada regiao
Mapa::Mapa() {
    _centro = Regiao(0,0,0);
    _floresta = Regiao(0,0,0);
    _deserto = Regiao(0,0,0);
    _pantano = Regiao(0,0,0);
    _campo = Regiao(0,0,0);
    _montanhas = Regiao(0,0,0);
    _ruinas = Regiao(0,0,0);
}

Regiao Mapa::get_centro() {return _centro;}

Regiao Mapa::get_floresta() {return _floresta;}

Regiao Mapa::get_deserto() {return _deserto;}

Regiao Mapa::get_pantano() {return _pantano;}

Regiao Mapa::get_campo() {return _campo;}

Regiao Mapa::get_montanhas() {return _montanhas;}

Regiao Mapa::get_ruinas() {return _ruinas;}

void Mapa::criar_participante(string nome,int idade, int destrito) {
    _vivos[nome] = Participante(nome,idade,destrito);
}

void Mapa::inicio() {
    auto pair = _vivos.begin();
    while(pair != _vivos.end()) {
        _centro.inserir_participante(&pair->second);
        pair = next(pair);
    }
}

void Mapa::mover_do_centro(regioes destino, Participante* fulano) {
    switch (destino) {
        case floresta:
        _floresta.inserir_participante(fulano);
        break;

        case deserto:
        _deserto.inserir_participante(fulano);
        break;

        case pantano:
        _pantano.inserir_participante(fulano);
        break;

        case campo:
        _campo.inserir_participante(fulano);
        break;

        case montanhas:
        _montanhas.inserir_participante(fulano);
        break;

        case ruinas:
        _ruinas.inserir_participante(fulano);
        break;
    }
    _centro.remover_participante(fulano);
}

void Mapa::mover_da_floresta(regioes destino, Participante* fulano) {
    switch (destino) {
        case centro:
        _centro.inserir_participante(fulano);
        break;

        case pantano:
        _pantano.inserir_participante(fulano);
        break;

        case campo:
        _campo.inserir_participante(fulano);
        break;
    }
    _floresta.remover_participante(fulano);
}

void Mapa::mover_do_deserto(regioes destino, Participante* fulano) {
    switch (destino) {
        case centro:
        _centro.inserir_participante(fulano);
        break;

        case ruinas:
        _ruinas.inserir_participante(fulano);
        break;

        case montanhas:
        _montanhas.inserir_participante(fulano);
        break;
    }
    _deserto.remover_participante(fulano);
}

void Mapa::mover_do_pantano(regioes destino, Participante* fulano) {
    switch (destino) {
        case centro:
        _centro.inserir_participante(fulano);
        break;

        case floresta:
        _floresta.inserir_participante(fulano);
        break;

        case montanhas:
        _montanhas.inserir_participante(fulano);
        break;
    }
    _pantano.remover_participante(fulano);
}

void Mapa::mover_do_campo(regioes destino, Participante* fulano) {
    switch (destino) {
        case centro:
        _centro.inserir_participante(fulano);
        break;

        case floresta:
        _floresta.inserir_participante(fulano);
        break;

        case ruinas:
        _ruinas.inserir_participante(fulano);
        break;
    }
    _campo.remover_participante(fulano);
}

void Mapa::mover_das_montanhas(regioes destino, Participante* fulano) {
    switch (destino) {
        case centro:
        _centro.inserir_participante(fulano);
        break;

        case pantano:
        _pantano.inserir_participante(fulano);
        break;

        case deserto:
        _deserto.inserir_participante(fulano);
        break;
    }
    _montanhas.remover_participante(fulano);
}

void Mapa::mover_das_ruinas(regioes destino, Participante* fulano) {
    switch (destino) {
        case centro:
        _centro.inserir_participante(fulano);
        break;

        case deserto:
        _deserto.inserir_participante(fulano);
        break;

        case campo:
        _campo.inserir_participante(fulano);
        break;
    }
    _ruinas.remover_participante(fulano);
}