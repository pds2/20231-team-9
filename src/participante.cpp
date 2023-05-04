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

void Participante::morreu() {
    _vivo = false;
}

void Participante::adicionar_arma(Arma arma) {
    for(Arma this_arma : _armas) {
        if(this_arma.get_tipo() == arma.get_tipo()) {
            std::cout << "Você já tem essa arma" << std::endl;
            return ;
        }
    }
    _armas.push_back(arma);
    // auto pair = _armas.begin();
    // while(pair != _armas.end()) {
    //     if((pair->first).get_tipo() == arma.get_tipo()) {
    //         pair->second +=1;
    //         return ;
    //     }
    // }
    // _armas[arma] = 1;
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


Arma Participante::escolher_arma() {
    for(int i = 0; i < _armas.size(); i++) {
        std::cout << i << ") " << _armas[i].get_tipo() << std::endl;
    }

    int index;
    while(1) {
        std::cin >> index;
        try {
            return _armas[index];

        } catch(std::out_of_range &e) {
            std::cout << "Digite um número válido" << std::endl;
        }
    }

}

void Participante::batalha(Participante p) {
    Arma arma_escolhida_atacante = escolher_arma();
    Arma arma_escolhida_defesa = p.escolher_arma();

    if(arma_escolhida_atacante.get_poder() > arma_escolhida_defesa.get_poder()) {
        p.morreu();
        //faltar adicionar chamadas que mudarão os campos "_energia" e "_ferido"
    }
}