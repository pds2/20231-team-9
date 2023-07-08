#include "../include/regiao.h"

#include <cmath>

Regiao::Regiao() {
    //Inicializa, por padrão, a regiao como Centro
    _chance_agua = 0;
    _chance_comida = 0;
    _chance_arma = 9;
    _chance_remedio = 3;
    _nome_string = "centro";
    _x = 2;
    _y = 2;
}

Regiao::Regiao(int x,int y, std::string nome_str, int chance_agua, int chance_comida, int chance_arma, int chance_remedio) {
    //Inicializa, por padrão, a regiao como Centro
    _chance_agua = chance_agua;
    _chance_comida = chance_comida;
    _chance_arma = chance_arma;
    _chance_remedio = chance_remedio;
    _nome_string = nome_str;
    _x = x;
    _y = y;
}

int Regiao::get_chance_agua() {return _chance_agua;}

int Regiao::get_chance_comida() {return _chance_comida;}

int Regiao::get_chance_arma() {return _chance_arma;}

int Regiao::get_chance_remedio() {return _chance_remedio;}

std::string Regiao::get_nome_string() {return _nome_string;}

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
