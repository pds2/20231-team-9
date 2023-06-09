#include "../include/participante.h"

#define stringify( name ) # name

Participante::Participante() {}

Participante::Participante(string nome, int distrito) {
    _nome = nome;
    _distrito = distrito;
    _vivo = true;
    _energia = 100;
    _hidratacao = 100;
    _ferido = 0;
    _atual = Regiao();
    // _regiao = centro;
}

string Participante::get_nome() const {
    return _nome;
}

int Participante::get_distrito() const {
    return _distrito;
}

Regiao Participante::get_atual() {
    return _atual;
}

float Participante::get_energia() {
    return _energia;
}
float Participante::get_hidratacao() {
    return _hidratacao;
}
float Participante::get_ferido() {
    return _ferido;
}

void Participante::muda_regiao_atual(Regiao destino) {
    _atual = destino;
}

void Participante::adicionar_arma(Arma arma) {
    for(Arma this_arma : _armas) {
        if(this_arma.get_tipo() == arma.get_tipo()) {
            std::cout << "Você já tem essa arma" << std::endl;
            return ;
        }
    }
    _armas.push_back(arma);
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
}


Arma Participante::escolher_arma() {
    for(int i = 0; i < _armas.size(); i++) {
        std::cout << i << ") " << _armas[i].get_tipo() << std::endl;
    }

    int index;
    while(1) {
        std::cout << "Qual arma você quer usar? " << std::endl;
        std::cin >> index;
        if(index < _armas.size()) {
            return _armas[index];

        } else {
            std::cout << "Digite um número válido" << std::endl;
        }
    }

}

void Participante::muda_regiao_atual(Regiao destino) {
    _atual = destino;
}

void Participante::batalha(Participante& p) {
    std::cout << "O jogador " << get_nome() << " do distrito " << get_distrito() << " atacou o jogador " << p.get_nome() << " do distrito " << p.get_distrito() << std::endl;
    Arma arma_escolhida_atacante = escolher_arma();
    Arma arma_escolhida_defesa = p.escolher_arma();

    if(arma_escolhida_atacante.get_poder() > arma_escolhida_defesa.get_poder()) {
        p._vivo = false;
        std::cout << "O jogador " << p.get_nome() << " do distrito " << p.get_distrito() << " foi morto" << std::endl;
        //faltar adicionar chamadas que mudarão os campos "_energia" e "_ferido"
        _energia *= (1 - 0.1*arma_escolhida_atacante.get_poder());
        _ferido *= (1 + 0.1*arma_escolhida_atacante.get_poder());

    } else if(arma_escolhida_atacante.get_poder() < arma_escolhida_defesa.get_poder()) {
        _vivo = false;
        std::cout << "O jogador " << get_nome() << " do distrito " << get_distrito() << " foi morto" << std::endl;
        p._energia *= (1 - 0.1*arma_escolhida_defesa.get_poder());
        p._ferido *= (1 + 0.1*arma_escolhida_defesa.get_poder());
    } 
}

 regioes Participante::get_regiao_atual() {
    return _atual.get_nome();
 }
void Participante::consumir_utensilios() {
    auto pair = _utensilios.begin();
    std::cout << "O jogador " << get_nome() << " possui os seguintes utensílios:" << std::endl;
    while(pair != _utensilios.end()) {
        std::cout << "* " << stringify(pair->first.get_tipo()) << ": " << pair->second << "unidades" << std::endl;
        pair = next(pair);
    }

    while(1) {
        std::string a_consumir;
        std::cout << "Digite o nome do utensílio que você deseja consumir nessa rodada: ";
        std::cin >> a_consumir;

        transform(a_consumir.begin(), a_consumir.end(), a_consumir.begin(), ::tolower);
        pair = _utensilios.begin();
        while(pair != _utensilios.end()) {
            if(stringify(pair->first.get_tipo()) == a_consumir) {
                _utensilios[pair->first] -= 1;
                return ;
            }
        }
    }

}
