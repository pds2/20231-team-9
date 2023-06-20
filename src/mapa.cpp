#include "../include/mapa.h"

#include <algorithm>
#include <random>

Regiao Centro(0,0,9,9,regioes::centro);
Regiao Floresta(8,7,2,0,regioes::floresta);
Regiao Deserto(2,5,5,0,regioes::deserto);
Regiao Pantano(10,3,1,0,regioes::pantano);
Regiao Campo(6,8,2,0,regioes::campo);
Regiao Montanhas(4,3,5,0,regioes::montanhas);
Regiao Ruinas(0,2,5,4,regioes::ruinas);

Mapa::Mapa() {}

vector<string> Mapa::get_td_mundo() {
    // Criar um gerador de números aleatórios
    random_device rd;
    mt19937 g(rd());

    // Embaralhar o vetor usando a função std::shuffle
    vector<string> vetor = _td_mundo;
    shuffle(vetor.begin(), vetor.end(), g);

    return vetor;
}

vector<string> Mapa::get_participantes_centro(){

    // Criar um gerador de números aleatórios
    random_device rd;
    mt19937 g(rd());

    // Embaralhar o vetor usando a função std::shuffle
    vector<string> vetor = _centro;
    shuffle(vetor.begin(), vetor.end(), g);

    return vetor;
}

vector<string> Mapa::get_participantes_floresta(){
    // Criar um gerador de números aleatórios
    random_device rd;
    mt19937 g(rd());

    // Embaralhar o vetor usando a função std::shuffle
    vector<string> vetor = _floresta;
    shuffle(vetor.begin(), vetor.end(), g);

    return vetor;
}

vector<string> Mapa::get_participantes_deserto(){
    // Criar um gerador de números aleatórios
    random_device rd;
    mt19937 g(rd());

    // Embaralhar o vetor usando a função std::shuffle
    vector<string> vetor = _deserto;
    shuffle(vetor.begin(), vetor.end(), g);

    return vetor;
}

vector<string> Mapa::get_participantes_pantano(){
    // Criar um gerador de números aleatórios
    random_device rd;
    mt19937 g(rd());

    // Embaralhar o vetor usando a função std::shuffle
    vector<string> vetor = _pantano;
    shuffle(vetor.begin(), vetor.end(), g);

    return vetor;
}

vector<string> Mapa::get_participantes_campo(){
    // Criar um gerador de números aleatórios
    random_device rd;
    mt19937 g(rd());

    // Embaralhar o vetor usando a função std::shuffle
    vector<string> vetor = _campo;
    shuffle(vetor.begin(), vetor.end(), g);

    return vetor;
}

vector<string> Mapa::get_participantes_montanhas(){
    // Criar um gerador de números aleatórios
    random_device rd;
    mt19937 g(rd());

    // Embaralhar o vetor usando a função std::shuffle
    vector<string> vetor = _montanhas;
    shuffle(vetor.begin(), vetor.end(), g);

    return vetor;
}

vector<string> Mapa::get_participantes_ruinas(){
    // Criar um gerador de números aleatórios
    random_device rd;
    mt19937 g(rd());

    // Embaralhar o vetor usando a função std::shuffle
    vector<string> vetor = _ruinas;
    shuffle(vetor.begin(), vetor.end(), g);

    return vetor;
}

void Mapa::inicio(map<string,Participante*> vivos) {
    auto pair = vivos.begin();
    while(pair != vivos.end()) {
        _centro.push_back(pair->second->get_nome()); // coloca os jogadores no centro
        _td_mundo.push_back(pair->second->get_nome()); // coloca os jogadores no vetor td_mundo
    }
    // for(Participante p : vivos) {
    //     _centro.push_back(p.get_nome()); // coloca os jogadores no centro
    //     _td_mundo.push_back(p.get_nome()); // coloca os jogadores no vetor td_mundo
    // }
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
        fulano->muda_regiao_atual(Floresta);
        break;

        case deserto:
        _deserto.push_back(fulano->get_nome());
        fulano->muda_regiao_atual(Deserto);
        break;

        case pantano:
        _pantano.push_back(fulano->get_nome());
        fulano->muda_regiao_atual(Pantano);
        break;

        case campo:
        _campo.push_back(fulano->get_nome());
        fulano->muda_regiao_atual(Campo);
        break;

        case montanhas:
        _montanhas.push_back(fulano->get_nome());
        fulano->muda_regiao_atual(Montanhas);
        break;

        case ruinas:
        _ruinas.push_back(fulano->get_nome());
        fulano->muda_regiao_atual(Ruinas);
        break;
    }
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
        fulano->muda_regiao_atual(Centro);
        break;

        case pantano:
        _pantano.push_back(fulano->get_nome());
        fulano->muda_regiao_atual(Pantano);
        break;

        case campo:
        _campo.push_back(fulano->get_nome());
        fulano->muda_regiao_atual(Campo);
        break;
    }

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
        fulano->muda_regiao_atual(Centro);
        break;

        case ruinas:
        _ruinas.push_back(fulano->get_nome());
        fulano->muda_regiao_atual(Ruinas);
        break;

        case montanhas:
        _montanhas.push_back(fulano->get_nome());
        fulano->muda_regiao_atual(Montanhas);
        break;
    }

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
        fulano->muda_regiao_atual(Centro);
        break;

        case floresta:
        _floresta.push_back(fulano->get_nome());
        fulano->muda_regiao_atual(Floresta);
        break;

        case montanhas:
        _montanhas.push_back(fulano->get_nome());
        fulano->muda_regiao_atual(Montanhas);
        break;
    }
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
        fulano->muda_regiao_atual(Centro);
        break;

        case floresta:
        _floresta.push_back(fulano->get_nome());
        fulano->muda_regiao_atual(Floresta);
        break;

        case ruinas:
        _ruinas.push_back(fulano->get_nome());
        fulano->muda_regiao_atual(Ruinas);
        break;
    }
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
        fulano->muda_regiao_atual(Centro);
        break;

        case pantano:
        _pantano.push_back(fulano->get_nome());
        fulano->muda_regiao_atual(Pantano);
        break;

        case deserto:
        _deserto.push_back(fulano->get_nome());
        fulano->muda_regiao_atual(Deserto);
        break;
    }
    
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
        fulano->muda_regiao_atual(Centro);
        break;

        case deserto:
        _deserto.push_back(fulano->get_nome());
        fulano->muda_regiao_atual(Deserto);
        break;

        case campo:
        _campo.push_back(fulano->get_nome());
        fulano->muda_regiao_atual(Campo);
        break;
    }
    
    for(auto it = _ruinas.begin();it != _ruinas.end();++it) {
        if(*(it) == fulano->get_nome()) {
            _ruinas.erase(it);
        }
    }
}