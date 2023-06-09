#include "mapa.h"

Mapa::Mapa() {}

vector<string> Mapa::get_participantes_centro(){
    return _centro;
}

vector<string> Mapa::get_participantes_floresta(){
    return _floresta;
}

vector<string> Mapa::get_participantes_deserto(){
    return _deserto;
}

vector<string> Mapa::get_participantes_pantano(){
    return _pantano;
}

vector<string> Mapa::get_participantes_campo(){
    return _campo;
}

vector<string> Mapa::get_participantes_montanhas(){
    return _montanhas;
}

vector<string> Mapa::get_participantes_ruinas(){
    return _ruinas;
}

void Mapa::morrer(Participante* fulano) {
    switch (fulano->get_regiao_atual()) {
        case centro:
        _centro.push_back(fulano->get_nome());
        break;
    
        case floresta:
        _floresta.push_back(fulano->get_nome());
        break;

        case deserto:
        _deserto.push_back(fulano->get_nome());
        break;

        case pantano:
        _pantano.push_back(fulano->get_nome());
        break;

        case campo:
        _campo.push_back(fulano->get_nome());
        break;

        case montanhas:
        _montanhas.push_back(fulano->get_nome());
        break;

        case ruinas:
        _ruinas.push_back(fulano->get_nome());
        break;
    }
}

void Mapa::mover_do_centro(regioes destino, Participante* fulano) {
    switch (destino) {
        case floresta:
        _floresta.push_back(fulano->get_nome());
        break;

        case deserto:
        _deserto.push_back(fulano->get_nome());
        break;

        case pantano:
        _pantano.push_back(fulano->get_nome());
        break;

        case campo:
        _campo.push_back(fulano->get_nome());
        break;

        case montanhas:
        _montanhas.push_back(fulano->get_nome());
        break;

        case ruinas:
        _ruinas.push_back(fulano->get_nome());
        break;
    }
    fulano->muda_regiao_atual(0,0,9,9);
    for(auto it = _centro.begin();it != _centro.end();++it) {
        if(*(it) == fulano->get_nome()) {
            _centro.erase(it);
        }
    }

}

void Mapa::mover_da_floresta(regioes destino, Participante* fulano) {
    if((destino != centro) && (destino != pantano) && (destino != campo)) {
        throw destino_invalido_e();
    }
    switch (destino) {
        case centro:
        _centro.push_back(fulano->get_nome());
        break;

        case pantano:
        _pantano.push_back(fulano->get_nome());
        break;

        case campo:
        _campo.push_back(fulano->get_nome());
        break;
    }
    fulano->muda_regiao_atual(8,7,2,0);
    for(auto it = _floresta.begin();it != _floresta.end();++it) {
        if(*(it) == fulano->get_nome()) {
            _floresta.erase(it);
        }
    }
}

void Mapa::mover_do_deserto(regioes destino, Participante* fulano) {
    if((destino != centro) && (destino != ruinas) && (destino != montanhas)) {
        throw destino_invalido_e();
    }
    switch (destino) {
        case centro:
        _centro.push_back(fulano->get_nome());
        break;

        case ruinas:
        _ruinas.push_back(fulano->get_nome());
        break;

        case montanhas:
        _montanhas.push_back(fulano->get_nome());
        break;
    }
    fulano->muda_regiao_atual(2,5,5,0);
    for(auto it = _deserto.begin();it != _deserto.end();++it) {
        if(*(it) == fulano->get_nome()) {
            _deserto.erase(it);
        }
    }
}

void Mapa::mover_do_pantano(regioes destino, Participante* fulano) {
    if((destino != centro) && (destino != floresta) && (destino != montanhas)) {
        throw destino_invalido_e();
    }
    switch (destino) {
        case centro:
        _centro.push_back(fulano->get_nome());
        break;

        case floresta:
        _floresta.push_back(fulano->get_nome());
        break;

        case montanhas:
        _montanhas.push_back(fulano->get_nome());
        break;
    }
    fulano->muda_regiao_atual(10,3,1,0);
    for(auto it = _deserto.begin();it != _deserto.end();++it) {
        if(*(it) == fulano->get_nome()) {
            _deserto.erase(it);
        }
    }
}

void Mapa::mover_do_campo(regioes destino, Participante* fulano) {
    if((destino != centro) && (destino != floresta) && (destino != ruinas)) {
        throw destino_invalido_e();
    }
    switch (destino) {
        case centro:
        _centro.push_back(fulano->get_nome());
        break;

        case floresta:
        _floresta.push_back(fulano->get_nome());
        break;

        case ruinas:
        _ruinas.push_back(fulano->get_nome());
        break;
    }
    fulano->muda_regiao_atual(6,8,2,0);
    for(auto it = _campo.begin();it != _campo.end();++it) {
        if(*(it) == fulano->get_nome()) {
            _campo.erase(it);
        }
    }
}

void Mapa::mover_das_montanhas(regioes destino, Participante* fulano) {
    if((destino != centro) && (destino != pantano) && (destino != deserto)) {
        throw destino_invalido_e();
    }
    switch (destino) {
        case centro:
        _centro.push_back(fulano->get_nome());
        break;

        case pantano:
        _pantano.push_back(fulano->get_nome());
        break;

        case deserto:
        _deserto.push_back(fulano->get_nome());
        break;
    }
    fulano->muda_regiao_atual(4,3,5,0);
    for(auto it = _montanhas.begin();it != _montanhas.end();++it) {
        if(*(it) == fulano->get_nome()) {
            _montanhas.erase(it);
        }
    }
}

void Mapa::mover_das_ruinas(regioes destino, Participante* fulano) {
    if((destino != centro) && (destino != deserto) && (destino != campo)) {
        throw destino_invalido_e();
    }
    switch (destino) {
        case centro:
        _centro.push_back(fulano->get_nome());
        break;

        case deserto:
        _deserto.push_back(fulano->get_nome());
        break;

        case campo:
        _campo.push_back(fulano->get_nome());
        break;
    }
    fulano->muda_regiao_atual(0,2,5,4);
    for(auto it = _ruinas.begin();it != _ruinas.end();++it) {
        if(*(it) == fulano->get_nome()) {
            _ruinas.erase(it);
        }
    }
}