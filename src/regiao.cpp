#include "regiao.h"

Regiao::Regiao() {
    _chance_agua = 0;
    _chance_comida = 0;
    _chance_arma = 9;
    _chance_remedio = 9;
}

Regiao::Regiao(int chance_agua, int chance_comida, int chance_arma, int chance_remedio) {
    _chance_agua = chance_agua;
    _chance_comida = chance_comida;
    _chance_arma = chance_arma;
    _chance_remedio = chance_remedio;
}

int Regiao::get_chance_agua() {return _chance_agua;}

int Regiao::get_chance_comida() {return _chance_comida;}

int Regiao::get_chance_arma() {return _chance_arma;}

map<string,Participante*> Regiao::get_participantes() {
    return _regiao;
}

void Regiao::inserir_participante(Participante *fulano) {
    _regiao[fulano->get_nome()] = fulano;
}

bool Regiao::conferir_participante(string nome) {
    auto pair = _regiao.begin();
    while( pair != _regiao.end() ) {
        if(pair->first == nome) {
            return true;
        }
        pair = next(pair);
    }
    return false;
}

void Regiao::remover_participante(Participante *fulano) {
    if(conferir_participante(fulano->get_nome()) == false) {
        throw participante_nao_esta_aq_e();
    }
    string nome = fulano->get_nome();
    _regiao.erase(nome);
}