#include "mapa.h"

//O Construtor define os atributos de cada regiao
Mapa::Mapa() {
    _centro = Regiao(0,0,9,9);
    _floresta = Regiao(8,7,2,0);
    _deserto = Regiao(2,5,5,0);
    _pantano = Regiao(10,3,1,0);
    _campo = Regiao(6,8,2,0);
    _montanhas = Regiao(4,3,5,0);
    _ruinas = Regiao(0,2,5,4);
}

map<string, Participante> Mapa::get_map_vivos() {
    return _vivos;
}

Regiao Mapa::get_centro() {return _centro;}

Regiao Mapa::get_floresta() {return _floresta;}

Regiao Mapa::get_deserto() {return _deserto;}

Regiao Mapa::get_pantano() {return _pantano;}

Regiao Mapa::get_campo() {return _campo;}

Regiao Mapa::get_montanhas() {return _montanhas;}

Regiao Mapa::get_ruinas() {return _ruinas;}

vector<string> Mapa::get_vivos() {
    vector<string> v;
    auto pair = _vivos.begin();
    while(pair != _vivos.end()) {
        v.push_back(pair->first);
        pair = next(pair);
    }
    return v;
}

map<string,Participante*> Mapa::get_participantes_centro(){
    return _centro.get_participantes();
}

map<string,Participante*> Mapa::get_participantes_floresta(){
    return _floresta.get_participantes();
}

map<string,Participante*> Mapa::get_participantes_deserto(){
    return _deserto.get_participantes();
}

map<string,Participante*> Mapa::get_participantes_pantano(){
    return _pantano.get_participantes();
}

map<string,Participante*> Mapa::get_participantes_campo(){
    return _campo.get_participantes();
}

map<string,Participante*> Mapa::get_participantes_montanhas(){
    return _montanhas.get_participantes();
}

map<string,Participante*> Mapa::get_participantes_ruinas(){
    return _ruinas.get_participantes();
}

vector<string> Mapa::get_mortos() {
    return _mortos;
} 

void Mapa::criar_participante(string nome, int distrito) {
    auto pair = _vivos.begin();
    while(pair != _vivos.end()) {
        if(nome == pair->first) {
            throw participante_ja_existe_e();
        }
        pair = next(pair);
    }
    
    if(distrito > 12 || distrito < 1) {
        throw distrito_invalido_e();
    }

    _vivos[nome] = Participante(nome,distrito);
}

void Mapa::inicio() {
    auto pair = _vivos.begin();
    while(pair != _vivos.end()) {
        _centro.inserir_participante(&pair->second);
        pair = next(pair);
    }
}

void Mapa::morrer(Participante* fulano) {
    switch (fulano->get_atual()) {
        case centro:
        _centro.remover_participante(fulano);
        break;
    
        case floresta:
        _floresta.remover_participante(fulano);
        break;

        case deserto:
        _deserto.remover_participante(fulano);
        break;

        case pantano:
        _pantano.remover_participante(fulano);
        break;

        case campo:
        _campo.remover_participante(fulano);
        break;

        case montanhas:
        _montanhas.remover_participante(fulano);
        break;

        case ruinas:
        _ruinas.remover_participante(fulano);
        break;
    }
    _mortos.push_back(fulano->get_nome());
    _vivos.erase(fulano->get_nome());
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
    fulano->muda_regiao_atual(destino);
    _centro.remover_participante(fulano);
}

void Mapa::mover_da_floresta(regioes destino, Participante* fulano) {
    if((destino != centro) && (destino != pantano) && (destino != campo)) {
        throw destino_invalido_e();
    }
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
    fulano->muda_regiao_atual(destino);
    _floresta.remover_participante(fulano);
}

void Mapa::mover_do_deserto(regioes destino, Participante* fulano) {
    if((destino != centro) && (destino != ruinas) && (destino != montanhas)) {
        throw destino_invalido_e();
    }
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
    fulano->muda_regiao_atual(destino);
    _deserto.remover_participante(fulano);
}

void Mapa::mover_do_pantano(regioes destino, Participante* fulano) {
    if((destino != centro) && (destino != floresta) && (destino != montanhas)) {
        throw destino_invalido_e();
    }
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
    fulano->muda_regiao_atual(destino);
    _pantano.remover_participante(fulano);
}

void Mapa::mover_do_campo(regioes destino, Participante* fulano) {
    if((destino != centro) && (destino != floresta) && (destino != ruinas)) {
        throw destino_invalido_e();
    }
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
    fulano->muda_regiao_atual(destino);
    _campo.remover_participante(fulano);
}

void Mapa::mover_das_montanhas(regioes destino, Participante* fulano) {
    if((destino != centro) && (destino != pantano) && (destino != deserto)) {
        throw destino_invalido_e();
    }
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
    fulano->muda_regiao_atual(destino);
    _montanhas.remover_participante(fulano);
}

void Mapa::mover_das_ruinas(regioes destino, Participante* fulano) {
    if((destino != centro) && (destino != deserto) && (destino != campo)) {
        throw destino_invalido_e();
    }
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
    fulano->muda_regiao_atual(destino);
    _ruinas.remover_participante(fulano);
}