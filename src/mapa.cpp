#include "../include/mapa.h"

#include <algorithm>
#include <random>

Regiao Centro(0,0,9,9,regioes::centro,2,2);
Regiao Floresta(8,7,2,0,regioes::floresta,2,1);
Regiao Deserto(2,5,5,0,regioes::deserto,3,3);
Regiao Pantano(10,3,1,0,regioes::pantano,3,1);
Regiao Campo(6,8,2,0,regioes::campo,1,1);
Regiao Montanhas(4,3,5,0,regioes::montanhas,3,2);
Regiao Ruinas(0,2,5,4,regioes::ruinas,1,2);

Mapa::Mapa() {}

// set<Participante *> Mapa::get_td_mundo() {
//     return _td_mundo;
// }
set<Participante *> Mapa::get_participantes_centro() {
    return _centro;
}
set<Participante *> Mapa::get_participantes_floresta() {
    return _floresta;
}
set<Participante *> Mapa::get_participantes_deserto() {
    return _deserto;
}
set<Participante *> Mapa::get_participantes_pantano() {
    return _pantano;
}
set<Participante *> Mapa::get_participantes_campo() {
    return _campo;
}
set<Participante *> Mapa::get_participantes_montanhas() {
    return _montanhas;
}
set<Participante *> Mapa::get_participantes_ruinas() {
    return _ruinas;
}


// vector<string> Mapa::get_td_mundo() {
//     // Criar um gerador de números aleatórios
//     random_device rd;
//     mt19937 g(rd());

//     // Embaralhar o vetor usando a função std::shuffle
//     vector<string> vetor = _td_mundo;
//     shuffle(vetor.begin(), vetor.end(), g);

//     return vetor;
// }

// vector<string> Mapa::get_participantes_centro(){

//     // Criar um gerador de números aleatórios
//     random_device rd;
//     mt19937 g(rd());

//     // Embaralhar o vetor usando a função std::shuffle
//     vector<string> vetor = _centro;
//     shuffle(vetor.begin(), vetor.end(), g);

//     return vetor;
// }

// vector<string> Mapa::get_participantes_floresta(){
//     // Criar um gerador de números aleatórios
//     random_device rd;
//     mt19937 g(rd());

//     // Embaralhar o vetor usando a função std::shuffle
//     vector<string> vetor = _floresta;
//     shuffle(vetor.begin(), vetor.end(), g);

//     return vetor;
// }

// vector<string> Mapa::get_participantes_deserto(){
//     // Criar um gerador de números aleatórios
//     random_device rd;
//     mt19937 g(rd());

//     // Embaralhar o vetor usando a função std::shuffle
//     vector<string> vetor = _deserto;
//     shuffle(vetor.begin(), vetor.end(), g);

//     return vetor;
// }

// vector<string> Mapa::get_participantes_pantano(){
//     // Criar um gerador de números aleatórios
//     random_device rd;
//     mt19937 g(rd());

//     // Embaralhar o vetor usando a função std::shuffle
//     vector<string> vetor = _pantano;
//     shuffle(vetor.begin(), vetor.end(), g);

//     return vetor;
// }

// vector<string> Mapa::get_participantes_campo(){
//     // Criar um gerador de números aleatórios
//     random_device rd;
//     mt19937 g(rd());

//     // Embaralhar o vetor usando a função std::shuffle
//     vector<string> vetor = _campo;
//     shuffle(vetor.begin(), vetor.end(), g);

//     return vetor;
// }

// vector<string> Mapa::get_participantes_montanhas(){
//     // Criar um gerador de números aleatórios
//     random_device rd;
//     mt19937 g(rd());

//     // Embaralhar o vetor usando a função std::shuffle
//     vector<string> vetor = _montanhas;
//     shuffle(vetor.begin(), vetor.end(), g);

//     return vetor;
// }

// vector<string> Mapa::get_participantes_ruinas(){
//     // Criar um gerador de números aleatórios
//     random_device rd;
//     mt19937 g(rd());

//     // Embaralhar o vetor usando a função std::shuffle
//     vector<string> vetor = _ruinas;
//     shuffle(vetor.begin(), vetor.end(), g);

//     return vetor;
// }

void Mapa::inicio(Participante *p) {
    _centro.insert(p);
    // auto pair = vivos.begin();
    // while(pair != vivos.end()) {
    //     _centro.insert(pair->second); // coloca os jogadores no centro
    //     _td_mundo.insert(pair->second); // coloca os jogadores no vetor td_mundo
    //     pair = next(pair);
    // }
    // for(Participante p : vivos) {
    //     _centro.push_back(p.get_nome()); // coloca os jogadores no centro
    //     _td_mundo.push_back(p.get_nome()); // coloca os jogadores no vetor td_mundo
    // }
}

void Mapa::morrer(Participante* fulano) {
    switch (fulano->get_Regiao_Atual().get_nome()) {
        case centro:
        _centro.erase(fulano);
        break;
    
        case floresta:
        _floresta.erase(fulano);
        break;

        case deserto:
        _deserto.erase(fulano);
        break;

        case pantano:
        _pantano.erase(fulano);
        break;

        case campo:
        _campo.erase(fulano);
        break;

        case montanhas:
        _montanhas.erase(fulano);
        break;

        case ruinas:
        _ruinas.erase(fulano);
        break;

        default:
        break;
    }
}

void Mapa::mover_do_centro(regioes destino, Participante* fulano) {
    switch (destino) {
        case floresta:
        _floresta.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        case deserto:
        _deserto.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        case pantano:
        _pantano.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        case campo:
        _campo.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        case montanhas:
        _montanhas.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        case ruinas:
        _ruinas.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        default:
        break;
    }
    _centro.erase(fulano);

}

void Mapa::mover_da_floresta(regioes destino, Participante* fulano) {
    if((destino != centro) && (destino != pantano) && (destino != campo)) {
        throw destino_invalido_e();
    }
    switch (destino) {
        case centro:
        _centro.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        case pantano:
        _pantano.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        case campo:
        _campo.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        default:
        break;
    }
    _floresta.erase(fulano);
}

void Mapa::mover_do_deserto(regioes destino, Participante* fulano) {
    if((destino != centro) && (destino != ruinas) && (destino != montanhas)) {
        throw destino_invalido_e();
    }
    switch (destino) {
        case centro:
        _centro.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        case ruinas:
        _ruinas.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        case montanhas:
        _montanhas.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        default:
        break;
    }
    _deserto.erase(fulano);
}

void Mapa::mover_do_pantano(regioes destino, Participante* fulano) {
    if((destino != centro) && (destino != floresta) && (destino != montanhas)) {
        throw destino_invalido_e();
    }
    switch (destino) {
        case centro:
        _centro.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        case floresta:
        _floresta.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        case montanhas:
        _montanhas.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        default:
        break;
    }
    _pantano.erase(fulano);
}

void Mapa::mover_do_campo(regioes destino, Participante* fulano) {
    if((destino != centro) && (destino != floresta) && (destino != ruinas)) {
        throw destino_invalido_e();
    }
    switch (destino) {
        case centro:
        _centro.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        case floresta:
        _floresta.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        case ruinas:
        _ruinas.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        default:
        break;
    }
    _campo.erase(fulano);
}

void Mapa::mover_das_montanhas(regioes destino, Participante* fulano) {
    if((destino != centro) && (destino != pantano) && (destino != deserto)) {
        throw destino_invalido_e();
    }
    switch (destino) {
        case centro:
        _centro.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        case pantano:
        _pantano.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        case deserto:
        _deserto.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        default:
        break;
    }
    _montanhas.erase(fulano);
}

void Mapa::mover_das_ruinas(regioes destino, Participante* fulano) {
    if((destino != centro) && (destino != deserto) && (destino != campo)) {
        throw destino_invalido_e();
    }
    switch (destino) {
        case centro:
        _centro.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        case deserto:
        _deserto.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        case campo:
        _campo.insert(fulano);
        fulano->muda_regiao(destino);
        break;

        default:
        break;
    }
    _ruinas.erase(fulano);

}