#include "../include/regiao.h"

#include <cmath>

Regiao::Regiao() {
    _chance_agua = 0;
    _chance_comida = 0;
    _chance_arma = 9;
    _chance_remedio = 9;
    _nome = regioes::centro;
    _x = 2;
    _y = 2;
}

Regiao::Regiao(int chance_agua, int chance_comida, int chance_arma, int chance_remedio, regioes nome, int x, int y) {
    _chance_agua = chance_agua;
    _chance_comida = chance_comida;
    _chance_arma = chance_arma;
    _chance_remedio = chance_remedio;
    _nome = nome;
    _x = x;
    _y = y;
}

int Regiao::get_chance_agua() {return _chance_agua;}

int Regiao::get_chance_comida() {return _chance_comida;}

int Regiao::get_chance_arma() {return _chance_arma;}

int Regiao::get_chance_remedio() {return _chance_remedio;}

regioes Regiao::get_nome() {return _nome;}

int Regiao::get_x() {return _x;}

int Regiao::get_y() {return _y;}

bool Regiao::pode_mudar_de_regiao(int x, int y) {
    if(( abs(_x - x) > 1 || abs(_y - y) > 1 )) {
        return false;
    } else if(_x - x == 0 && _y - y == 0) {
        return false;
    } else {
        return true;
    }
}

void Regiao::muda_regiao(regioes destino) {
    bool aux;
    switch (destino)
    {
    case centro:
        aux = pode_mudar_de_regiao(2, 2);
        if (aux == false) {
            throw nao_da_para_mudar_para_essa_regiao_e();
        }
        _x = 2;
        _y = 2;
        _chance_agua = 0;
        _chance_comida = 0;
        _chance_arma = 9;
        _chance_remedio = 9;
        _nome = centro;
        break;

    case floresta:
        _x = 2;
        _y = 1;
        _chance_agua = 8;
        _chance_comida = 7;
        _chance_arma = 2;
        _chance_remedio = 0;
        _nome = floresta;
        break;

    case pantano:
        _x = 3;
        _y = 1;
        _chance_agua = 10;
        _chance_comida = 3;
        _chance_arma = 1;
        _chance_remedio = 0;
        _nome = pantano;
        break;

    case montanhas:
        _x = 3;
        _y = 2;
        _chance_agua = 4;
        _chance_comida = 3;
        _chance_arma = 5;
        _chance_remedio = 0;
        _nome = montanhas;
        break;

    case deserto:
        _x = 3;
        _y = 3;
        _chance_agua = 2;
        _chance_comida = 5;
        _chance_arma = 5;
        _chance_remedio = 0;
        _nome = deserto;
        break;

    case ruinas:
        _x = 1;
        _y = 2;
        _chance_agua = 0;
        _chance_comida = 2;
        _chance_arma = 5;
        _chance_remedio = 4;
        _nome = ruinas;
        break;

    case campo:
        _x = 1;
        _y = 1;
        _chance_agua = 6;
        _chance_comida = 8;
        _chance_arma = 2;
        _chance_remedio = 0;
        _nome = campo;
        break;

    default:
        throw destino_nao_existe_e();
        break;
    }
}
