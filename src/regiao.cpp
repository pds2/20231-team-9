#include "regiao.h"

Regiao::Regiao() {
    _chance_agua = 0;
    _chance_comida = 0;
    _chance_arma = 0;
}

Regiao::Regiao(int chance_agua, int chance_comida, int chance_arma) {
    _chance_agua = chance_agua;
    _chance_comida = chance_comida;
    _chance_arma = chance_arma;
}

int Regiao::get_chance_agua() {return _chance_agua;}

int Regiao::get_chance_comida() {return _chance_comida;}

int Regiao::get_chance_arma() {return _chance_arma;}

void Regiao::inserir_participante(Participante *fulano) {
    _regiao[fulano->get_nome()] = fulano;
}

void Regiao::remover_participante(Participante *fulano) {
    string nome = fulano->get_nome();
    _regiao.erase(nome);
}