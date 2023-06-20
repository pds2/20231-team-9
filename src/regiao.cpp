#include "../include/regiao.h"

Regiao::Regiao() {
    _chance_agua = 0;
    _chance_comida = 0;
    _chance_arma = 9;
    _chance_remedio = 9;
    _nome = regioes::centro;
}

Regiao::Regiao(int chance_agua, int chance_comida, int chance_arma, int chance_remedio, regioes nome) {
    _chance_agua = chance_agua;
    _chance_comida = chance_comida;
    _chance_arma = chance_arma;
    _chance_remedio = chance_remedio;
    _nome = nome;
}

int Regiao::get_chance_agua() {return _chance_agua;}

int Regiao::get_chance_comida() {return _chance_comida;}

int Regiao::get_chance_arma() {return _chance_arma;}

int Regiao::get_chance_remedio() {return _chance_remedio;}

regioes Regiao::get_nome() {return _nome;}