#include "../include/participante.h"

Participante::Participante(string nome, int idade, int distrito) {
    _nome = nome;
    _idade = idade;
    _distrito = distrito;
    _vivo = true;
    _energia = 100;
    _hidratacao = 100;
    _ferido = 0;
}

string Participante::get_nome() const {
    return _nome;
}

int Participante::get_distrito() const {
    return _distrito;
}

void Participante::adicionar_arma(Arma arma) {
    auto pair = _armas.begin();
    while(pair != _armas.end()) {
        if((pair->first).get_tipo() == arma.get_tipo()) {
            pair->second +=1;
            return ;
        }
    }
    _armas[arma] = 1;
    // _armas.insert(pair<Arma, int>(arma, 1));
}

void Participante::adicionar_utensilio(Utensilio utensilio) {
    auto pair = _utensilios.begin();
    while(pair != _utensilios.end()) {
        if((pair->first).get_tipo() == utensilio.get_tipo()) {
            pair->second +=1;
            return ;
        }
    }
    _utensilios[utensilio] = 1;
    // _armas.insert(pair<Arma, int>(arma, 1));
}

