#include "regiao.h"

Regiao::Regiao() {
    _chance_agua = 0;
    _chance_comida = 0;
    _chance_arma = 9;
    _chance_remedio = 9;
}

Regiao::Regiao(int chance_agua, int chance_comida, int chance_arma, int chance_remedio, regioes regiao) {
    _chance_agua = chance_agua;
    _chance_comida = chance_comida;
    _chance_arma = chance_arma;
    _chance_remedio = chance_remedio;
}

int Regiao::get_chance_agua() {return _chance_agua;}

int Regiao::get_chance_comida() {return _chance_comida;}

int Regiao::get_chance_arma() {return _chance_arma;}

regioes Regiao::get_nome() {return _nome;}